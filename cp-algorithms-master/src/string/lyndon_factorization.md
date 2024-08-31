# Phân tích Lyndon

## Phân tích Lyndon

Trước tiên, hãy định nghĩa khái niệm về phân tích Lyndon.

Một chuỗi được gọi là **đơn giản** (hoặc một từ Lyndon) nếu nó **nhỏ hơn** bất kỳ **hậu tố** (suffix) **không tầm thường** (nontrivial) nào của chính nó.
Ví dụ về chuỗi đơn giản là: $a$, $b$, $ab$, $aab$, $abb$, $ababb$, $abcd$.
Có thể chứng minh rằng một chuỗi là đơn giản, nếu và chỉ khi nó **nhỏ hơn** tất cả các **dịch chuyển vòng** (cyclic shifts) **không tầm thường** (nontrivial) của nó.

Tiếp theo, giả sử có một chuỗi $s$ nhất định.
**Phân tích Lyndon** của chuỗi $s$ là một phân tích $s = w_1 w_2 \dots w_k$, trong đó tất cả các chuỗi $w_i$ đều đơn giản và chúng theo thứ tự không tăng $w_1 \ge w_2 \ge \dots \ge w_k$.

Có thể chứng minh rằng, đối với bất kỳ chuỗi nào, sự phân tích như vậy tồn tại và là duy nhất.

## Thuật toán Duval

Thuật toán Duval xây dựng phân tích Lyndon trong thời gian $O(n)$ bằng cách sử dụng $O(1)$ bộ nhớ bổ sung.

Trước tiên, hãy giới thiệu một khái niệm khác:
một chuỗi $t$ được gọi là **tiền đơn giản** (pre-simple), nếu nó có dạng $t = w w \dots w \overline{w}$, trong đó $w$ là chuỗi đơn giản và $\overline{w}$ là tiền tố (prefix) của $w$ (có thể trống).
Một chuỗi đơn giản cũng là tiền đơn giản.

Thuật toán Duval là tham lam.
Tại bất kỳ thời điểm nào trong quá trình thực thi, chuỗi $s$ sẽ thực sự được chia thành ba chuỗi $s = s_1 s_2 s_3$, trong đó phân tích Lyndon cho $s_1$ đã được tìm thấy và hoàn thành, chuỗi $s_2$ là tiền đơn giản (và chúng ta biết độ dài của chuỗi đơn giản trong đó), và $s_3$ hoàn toàn không được xử lý.
Trong mỗi lần lặp, thuật toán Duval lấy ký tự đầu tiên của chuỗi $s_3$ và cố gắng nối nó vào chuỗi $s_2$.
Nếu $s_2$ không còn là tiền đơn giản, thì phân tích Lyndon cho một số phần của $s_2$ sẽ được biết và phần này sẽ chuyển sang $s_1$.

Hãy mô tả thuật toán chi tiết hơn.
Con trỏ $i$ sẽ luôn trỏ đến đầu của chuỗi $s_2$.
Vòng lặp bên ngoài sẽ được thực hiện miễn là $i < n$.
Bên trong vòng lặp, chúng ta sử dụng hai con trỏ bổ sung, $j$ trỏ đến đầu của $s_3$ và $k$ trỏ đến ký tự hiện tại mà chúng ta đang so sánh.
Chúng ta muốn thêm ký tự $s[j]$ vào chuỗi $s_2$, điều này yêu cầu so sánh với ký tự $s[k]$.
Có thể có ba trường hợp khác nhau:

- $s[j] = s[k]$: nếu đúng như vậy, thì việc thêm ký hiệu $s[j]$ vào $s_2$ không vi phạm tính tiền đơn giản của nó.
  Vì vậy, chúng ta chỉ cần tăng các con trỏ $j$ và $k$.
- $s[j] > s[k]$: ở đây, chuỗi $s_2 + s[j]$ trở nên đơn giản.
  Chúng ta có thể tăng $j$ và đặt lại $k$ về đầu của $s_2$, sao cho ký tự tiếp theo có thể được so sánh với đầu của từ đơn giản.
- $s[j] < s[k]$: chuỗi $s_2 + s[j]$ không còn là tiền đơn giản.
  Do đó, chúng ta sẽ chia chuỗi tiền đơn giản $s_2$ thành các chuỗi đơn giản của nó và phần còn lại, có thể trống.
  Chuỗi đơn giản sẽ có độ dài $j - k$.
  Trong lần lặp tiếp theo, chúng ta bắt đầu lại với $s_2$ còn lại.

### Triển khai

Ở đây chúng ta trình bày cách triển khai thuật toán Duval, nó sẽ trả về phân tích Lyndon mong muốn của một chuỗi $s$ nhất định.

```{.cpp file=duval_algorithm}
vector<string> duval(string const& s) {
    int n = s.size();
    int i = 0;
    vector<string> factorization;
    while (i < n) {
        int j = i + 1, k = i;
        while (j < n && s[k] <= s[j]) {
            if (s[k] < s[j])
                k = i;
            else
                k++;
            j++;
        }
        while (i <= k) {
            factorization.push_back(s.substr(i, j - k));
            i += j - k;
        }
    }
    return factorization;
}
```

### Độ phức tạp

Chúng ta hãy ước tính thời gian chạy của thuật toán này.

**Vòng lặp while bên ngoài** không vượt quá $n$ lần lặp, vì ở cuối mỗi lần lặp, $i$ tăng lên.
Ngoài ra, vòng lặp while bên trong thứ hai chạy trong $O(n)$, vì nó chỉ xuất ra phân tích cuối cùng.

Vì vậy, chúng ta chỉ quan tâm đến **vòng lặp while bên trong đầu tiên**.
Nó thực hiện bao nhiêu lần lặp trong trường hợp xấu nhất?
Dễ dàng nhận thấy rằng các từ đơn giản mà chúng ta xác định trong mỗi lần lặp của vòng lặp bên ngoài dài hơn phần còn lại mà chúng ta đã so sánh thêm.
Do đó, tổng của các phần dư cũng sẽ nhỏ hơn $n$, có nghĩa là chúng ta chỉ thực hiện nhiều nhất $O(n)$ lần lặp của vòng lặp while bên trong đầu tiên.
Trên thực tế, tổng số lần so sánh ký tự sẽ không vượt quá $4n - 3$.

## Tìm dịch chuyển vòng nhỏ nhất

Giả sử có một chuỗi $s$.
Chúng ta xây dựng phân tích Lyndon cho chuỗi $s + s$ (trong thời gian $O(n)$).
Chúng ta sẽ tìm kiếm một chuỗi đơn giản trong phân tích, chuỗi này bắt đầu ở vị trí nhỏ hơn $n$ (tức là nó bắt đầu trong lần xuất hiện đầu tiên của $s$) và kết thúc ở vị trí lớn hơn hoặc bằng $n$ (tức là trong lần xuất hiện thứ hai) của $s$).
Người ta khẳng định rằng, vị trí bắt đầu của khối đơn giản này sẽ là điểm bắt đầu của dịch chuyển vòng nhỏ nhất mong muốn.
Điều này có thể dễ dàng được xác minh bằng cách sử dụng định nghĩa của phân tích Lyndon.

Điểm bắt đầu của khối đơn giản có thể dễ dàng tìm thấy - chỉ cần nhớ con trỏ $i$ ở đầu mỗi lần lặp của vòng lặp bên ngoài, nó cho biết điểm bắt đầu của chuỗi tiền đơn giản hiện tại.

Vì vậy, chúng ta có cách triển khai sau:

```{.cpp file=smallest_cyclic_string}
string min_cyclic_string(string s) {
    s += s;
    int n = s.size();
    int i = 0, ans = 0;
    while (i < n / 2) {
        ans = i;
        int j = i + 1, k = i;
        while (j < n && s[k] <= s[j]) {
            if (s[k] < s[j])
                k = i;
            else
                k++;
            j++;
        }
        while (i <= k)
            i += j - k;
    }
    return s.substr(ans, n / 2);
}
```

## Bài tập

- [UVA #719 - Glass Beads](https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=660)

---
