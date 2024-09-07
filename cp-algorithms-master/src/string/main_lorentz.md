# Tìm kiếm sự lặp lại

Cho một chuỗi $s$ có độ dài $n$.

**Sự lặp lại** (repetition) là hai lần xuất hiện của một chuỗi liên tiếp.
Nói cách khác, một sự lặp lại có thể được mô tả bằng một cặp chỉ số $i < j$ sao cho chuỗi con $s[i \dots j]$ bao gồm hai chuỗi giống hệt nhau được viết sau nhau.

Thách thức là **tìm tất cả các lần lặp lại** trong một chuỗi $s$ nhất định.
Hoặc một nhiệm vụ đơn giản hơn: tìm **bất kỳ** lần lặp lại nào hoặc tìm lần lặp lại **dài nhất**.

Thuật toán được mô tả ở đây được xuất bản vào năm 1982 bởi Main và Lorentz.

## Ví dụ

Hãy xem xét các lần lặp lại trong chuỗi ví dụ sau:

$$acababaee$$

Chuỗi chứa ba lần lặp lại sau:

- $s[2 \dots 5] = abab$
- $s[3 \dots 6] = baba$
- $s[7 \dots 8] = ee$

Một ví dụ khác:

$$abaaba$$

Ở đây chỉ có hai lần lặp lại

- $s[0 \dots 5] = abaaba$
- $s[2 \dots 3] = aa$

## Số lần lặp lại

Nói chung, có thể có tới $O(n^2)$ lần lặp lại trong một chuỗi có độ dài $n$.
Một ví dụ rõ ràng là một chuỗi bao gồm $n$ lần cùng một chữ cái, trong trường hợp này, bất kỳ chuỗi con nào có độ dài chẵn đều là một lần lặp lại.
Nói chung, bất kỳ chuỗi tuần hoàn nào có chu kỳ ngắn sẽ chứa rất nhiều lần lặp lại.

Mặt khác, thực tế này không ngăn cản việc tính toán số lần lặp lại trong thời gian $O(n \log n)$, bởi vì thuật toán có thể cung cấp các lần lặp lại ở dạng nén, theo nhóm gồm nhiều phần cùng một lúc.

Thậm chí còn có một khái niệm mô tả các nhóm chuỗi con tuần hoàn với các bộ có kích thước là bốn.
Người ta đã chứng minh rằng chúng ta có số lượng các nhóm như vậy nhiều nhất là tuyến tính so với độ dài chuỗi.

Ngoài ra, đây là một số kết quả thú vị hơn liên quan đến số lần lặp lại:

  - Số lần lặp lại nguyên thủy (những lần lặp lại mà một nửa của chúng không phải là lần lặp lại) nhiều nhất là $O(n \log n)$.
  - Nếu chúng ta mã hóa các lần lặp lại bằng các bộ số (được gọi là bộ ba Crochemore) $(i,~ p,~ r)$ (trong đó $i$ là vị trí bắt đầu, $p$ là độ dài của chuỗi con lặp lại và $r$ là số lần lặp lại), thì tất cả các lần lặp lại có thể được mô tả với $O(n \log n)$ bộ ba như vậy.
  - Chuỗi Fibonacci, được định nghĩa là
    
    \[\begin{align}
    t_0 &= a, \\\\
    t_1 &= b, \\\\
    t_i &= t_{i-1} + t_{i-2},
    \end{align}\]
    
    là tuần hoàn "mạnh".
    Số lần lặp lại trong chuỗi Fibonacci $f_i$, ngay cả trong dạng nén với bộ ba Crochemore, là $O(f_n \log f_n)$.
    Số lần lặp lại nguyên thủy cũng là $O(f_n \log f_n)$.

## Thuật toán Main-Lorentz

Ý tưởng đằng sau thuật toán Main-Lorentz là **chia để trị**.

Nó chia chuỗi ban đầu thành hai nửa và tính toán số lần lặp lại nằm hoàn toàn trong mỗi nửa bằng hai lệnh gọi đệ quy.
Sau đó đến phần khó khăn.
Thuật toán tìm tất cả các lần lặp lại bắt đầu trong nửa đầu và kết thúc trong nửa sau (mà chúng ta sẽ gọi là **lần lặp lại chéo** (crossing repetitions)).
Đây là phần thiết yếu của thuật toán Main-Lorentz và chúng ta sẽ thảo luận chi tiết về nó ở đây.

Độ phức tạp của thuật toán chia để trị đã được nghiên cứu kỹ lưỡng.
[Định lý chính](https://en.wikipedia.org/wiki/Master_theorem_(analysis_of_algorithms)) nói rằng chúng ta sẽ kết thúc với một thuật toán $O(n \log n)$, nếu chúng ta có thể tính toán các lần lặp lại chéo trong thời gian $O(n)$.

### Tìm kiếm các lần lặp lại chéo

Vì vậy, chúng ta muốn tìm tất cả các lần lặp lại bắt đầu trong nửa đầu của chuỗi, hãy gọi nó là $u$ và kết thúc trong nửa sau, hãy gọi nó là $v$:

$$s = u + v$$

Độ dài của chúng xấp xỉ bằng độ dài của $s$ chia cho hai.

Hãy xem xét một lần lặp lại tùy ý và nhìn vào ký tự ở giữa (chính xác hơn là ký tự đầu tiên của nửa sau của lần lặp lại).
Tức là nếu lần lặp lại là chuỗi con $s[i \dots j]$, thì ký tự ở giữa là $(i + j + 1) / 2$.

Chúng ta gọi một lần lặp lại là **trái** hoặc **phải** tùy thuộc vào chuỗi mà ký tự này nằm - trong chuỗi $u$ hoặc trong chuỗi $v$.
Nói cách khác, một chuỗi được gọi là trái, nếu phần lớn của nó nằm trong $u$, nếu không chúng ta gọi nó là phải.

Bây giờ chúng ta sẽ thảo luận về cách tìm **tất cả các lần lặp lại bên trái**.
Việc tìm tất cả các lần lặp lại bên phải có thể được thực hiện theo cách tương tự.

Hãy biểu thị độ dài của lần lặp lại bên trái bằng $2l$ (tức là mỗi nửa của lần lặp lại có độ dài $l$).
Hãy xem xét ký tự đầu tiên của lần lặp lại rơi vào chuỗi $v$ (nó ở vị trí $|u|$ trong chuỗi $s$).
Nó trùng với ký tự ở vị trí $l$ trước nó, hãy ký hiệu vị trí này là $cntr$.

Chúng ta sẽ cố định vị trí $cntr$ này và **tìm kiếm tất cả các lần lặp lại ở vị trí** $cntr$ này.

Ví dụ:

$$c ~ \underset{cntr}{a} ~ c ~ | ~ a ~ d ~ a$$

Các đường thẳng đứng chia hai nửa.
Ở đây chúng ta cố định vị trí $cntr = 1$, và ở vị trí này, chúng ta tìm thấy lần lặp lại $caca$.

Rõ ràng là nếu chúng ta cố định vị trí $cntr$, chúng ta đồng thời cố định độ dài của các lần lặp lại có thể có: $l = |u| - cntr$.
Khi chúng ta biết cách tìm các lần lặp lại này, chúng ta sẽ lặp qua tất cả các giá trị có thể có của $cntr$ từ $0$ đến $|u|-1$ và tìm tất cả các lần lặp lại chéo bên trái có độ dài $l = |u|,~ |u|-1,~ \dots, 1$.

### Tiêu chí cho các lần lặp lại chéo bên trái

Bây giờ, làm cách nào chúng ta có thể tìm thấy tất cả các lần lặp lại như vậy cho một $cntr$ cố định?
Hãy nhớ rằng vẫn có thể có nhiều lần lặp lại như vậy.

Hãy xem xét một hình ảnh trực quan một lần nữa, lần này cho lần lặp lại $abcabc$:

$$\overbrace{a}^{l_1} ~ \overbrace{\underset{cntr}{b} ~ c}^{l_2} ~ \overbrace{a}^{l_1} ~ | ~ \overbrace{b ~ c}^{l_2}$$

Ở đây chúng ta biểu thị độ dài của hai phần của lần lặp lại bằng $l_1$ và $l_2$:
$l_1$ là độ dài của lần lặp lại cho đến vị trí $cntr-1$ và $l_2$ là độ dài của lần lặp lại từ $cntr$ đến hết nửa của lần lặp lại.
Chúng ta có $2l = l_1 + l_2 + l_1 + l_2$ là tổng độ dài của lần lặp lại.

Hãy để chúng ta tạo các điều kiện **cần và đủ** cho một lần lặp lại như vậy ở vị trí $cntr$ có độ dài $2l = 2(l_1 + l_2) = 2(|u| - cntr)$:

- Cho $k_1$ là số lớn nhất sao cho $k_1$ ký tự đầu tiên trước vị trí $cntr$ trùng với $k_1$ ký tự cuối cùng trong chuỗi $u$:
  
$$
u[cntr - k_1 \dots cntr - 1] = u[|u| - k_1 \dots |u| - 1]
$$
  
- Cho $k_2$ là số lớn nhất sao cho $k_2$ ký tự bắt đầu từ vị trí $cntr$ trùng với $k_2$ ký tự đầu tiên trong chuỗi $v$:

$$  
  u[cntr \dots cntr + k_2 - 1] = v[0 \dots k_2 - 1]
$$
  
- Sau đó, chúng ta có một lần lặp lại chính xác cho bất kỳ cặp $(l_1,~ l_2)$ nào với

$$
  \begin{align}
  l_1 &\le k_1, \\\\
  l_2 &\le k_2. \\\\
  \end{align}
$$

Để tóm tắt:

- Chúng ta cố định một vị trí cụ thể $cntr$.
- Tất cả các lần lặp lại mà chúng ta sẽ tìm thấy bây giờ đều có độ dài $2l = 2(|u| - cntr)$.
  Có thể có nhiều lần lặp lại như vậy, chúng phụ thuộc vào độ dài $l_1$ và $l_2 = l - l_1$.
- Chúng ta tìm $k_1$ và $k_2$ như mô tả ở trên.
- Sau đó, tất cả các lần lặp lại phù hợp là những lần lặp lại mà độ dài của các phần $l_1$ và $l_2$ thỏa mãn các điều kiện:

$$
  \begin{align}
  l_1 + l_2 &= l = |u| - cntr \\\\
  l_1 &\le k_1, \\\\
  l_2 &\le k_2. \\\\
  \end{align}
$$

Do đó, phần duy nhất còn lại là làm thế nào chúng ta có thể tính toán các giá trị $k_1$ và $k_2$ một cách nhanh chóng cho mọi vị trí $cntr$.
May mắn thay, chúng ta có thể tính toán chúng trong $O(1)$ bằng cách sử dụng [hàm Z](../string/z-function.md):

- Để có thể tìm giá trị $k_1$ cho mỗi vị trí bằng cách tính hàm Z cho chuỗi $\overline{u}$ (tức là chuỗi đảo ngược $u$).
  Sau đó, giá trị $k_1$ cho một $cntr$ cụ thể sẽ bằng với giá trị tương ứng của mảng của hàm Z.
- Để tính toán trước tất cả các giá trị $k_2$, chúng ta tính toán hàm Z cho chuỗi $v + \# + u$ (tức là chuỗi $u$ được nối với ký tự phân tách $\#$ và chuỗi $v$).
  Một lần nữa, chúng ta chỉ cần tra cứu giá trị tương ứng trong hàm Z để nhận giá trị $k_2$.

Vì vậy, điều này là đủ để tìm tất cả các lần lặp lại chéo bên trái.

### Lần lặp lại chéo bên phải

Để tính toán các lần lặp lại chéo bên phải, chúng ta hành động tương tự:
chúng ta định nghĩa tâm $cntr$ là ký tự tương ứng với ký tự cuối cùng trong chuỗi $u$.

Sau đó, độ dài $k_1$ sẽ được định nghĩa là số lượng ký tự lớn nhất trước vị trí $cntr$ (bao gồm cả) trùng với các ký tự cuối cùng của chuỗi $u$.
Và độ dài $k_2$ sẽ được định nghĩa là số lượng ký tự lớn nhất bắt đầu từ $cntr + 1$ trùng với các ký tự của chuỗi $v$.

Do đó, chúng ta có thể tìm các giá trị $k_1$ và $k_2$ bằng cách tính hàm Z cho các chuỗi $\overline{u} + \# + \overline{v}$ và $v$.

Sau đó, chúng ta có thể tìm thấy các lần lặp lại bằng cách xem xét tất cả các vị trí $cntr$ và sử dụng cùng một tiêu chí như chúng ta đã có cho các lần lặp lại chéo bên trái.

### Triển khai

Việc triển khai thuật toán Main-Lorentz tìm thấy tất cả các lần lặp lại ở dạng bộ bốn đặc biệt: $(cntr,~ l,~ k_1,~ k_2)$ trong thời gian $O(n \log n)$.
Nếu bạn chỉ muốn tìm số lần lặp lại trong một chuỗi hoặc chỉ muốn tìm lần lặp lại dài nhất trong một chuỗi, thông tin này là đủ và thời gian chạy vẫn sẽ là $O(n \log n)$.

Lưu ý rằng nếu bạn muốn mở rộng các bộ này để nhận được vị trí bắt đầu và kết thúc của mỗi lần lặp lại, thì thời gian chạy sẽ là $O(n^2)$ (hãy nhớ rằng có thể có $O(n^2)$ lần lặp lại).
Trong cách triển khai này, chúng ta sẽ làm như vậy và lưu trữ tất cả các lần lặp lại được tìm thấy trong một vector các cặp chỉ số bắt đầu và kết thúc.

```{.cpp file=main_lorentz}
vector<int> z_function(string const& s) {
    int n = s.size();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r)
            z[i] = min(r-i+1, z[i-l]);
        while (i + z[i] < n && s[z[i]] == s[i+z[i]])
            z[i]++;
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

int get_z(vector<int> const& z, int i) {
    if (0 <= i && i < (int)z.size())
        return z[i];
    else
        return 0;
}

vector<pair<int, int>> repetitions;

void convert_to_repetitions(int shift, bool left, int cntr, int l, int k1, int k2) {
    for (int l1 = max(1, l - k2); l1 <= min(l, k1); l1++) {
        if (left && l1 == l) break;
        int l2 = l - l1;
        int pos = shift + (left ? cntr - l1 : cntr - l - l1 + 1);
        repetitions.emplace_back(pos, pos + 2*l - 1);
    }
}

void find_repetitions(string s, int shift = 0) {
    int n = s.size();
    if (n == 1)
        return;

    int nu = n / 2;
    int nv = n - nu;
    string u = s.substr(0, nu);
    string v = s.substr(nu);
    string ru(u.rbegin(), u.rend());
    string rv(v.rbegin(), v.rend());

    find_repetitions(u, shift);
    find_repetitions(v, shift + nu);

    vector<int> z1 = z_function(ru);
    vector<int> z2 = z_function(v + '#' + u);
    vector<int> z3 = z_function(ru + '#' + rv);
    vector<int> z4 = z_function(v);

    for (int cntr = 0; cntr < n; cntr++) {
        int l, k1, k2;
        if (cntr < nu) {
            l = nu - cntr;
            k1 = get_z(z1, nu - cntr);
            k2 = get_z(z2, nv + 1 + cntr);
        } else {
            l = cntr - nu + 1;
            k1 = get_z(z3, nu + 1 + nv - 1 - (cntr - nu));
            k2 = get_z(z4, (cntr - nu) + 1);
        }
        if (k1 + k2 >= l)
            convert_to_repetitions(shift, cntr < nu, cntr, l, k1, k2);
    }
}
```

--- 