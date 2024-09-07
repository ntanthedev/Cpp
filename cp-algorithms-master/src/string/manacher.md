# Thuật toán Manacher - Tìm tất cả các chuỗi con đối xứng trong $O(N)$

---
tags:
  - Dịch
e_maxx_link: palindromes_count
---

# Thuật toán Manacher - Tìm tất cả các chuỗi con đối xứng (palindrome) trong $O(N)$

## Bài toán

Cho chuỗi $s$ có độ dài $n$. Tìm tất cả các cặp $(i, j)$ sao cho chuỗi con $s[i\dots j]$ là chuỗi đối xứng. Chuỗi $t$ là chuỗi đối xứng khi $t = t_{rev}$ ($t_{rev}$ là chuỗi đảo ngược của $t$).

## Bài toán chi tiết hơn

Trong trường hợp xấu nhất, chuỗi có thể có tới $O(n^2)$ chuỗi con đối xứng và thoạt nhìn có vẻ như không có thuật toán tuyến tính nào cho bài toán này.

Nhưng thông tin về các chuỗi đối xứng có thể được lưu giữ **theo một cách gọn nhẹ**: đối với mỗi vị trí $i$, chúng ta sẽ tìm số lượng chuỗi đối xứng không rỗng có tâm tại vị trí này.

Các chuỗi đối xứng có chung một tâm tạo thành một chuỗi liền kề, tức là nếu chúng ta có một chuỗi đối xứng có độ dài $l$ có tâm ở $i$, chúng ta cũng có các chuỗi đối xứng có độ dài $l-2$, $l-4$ và vân vân cũng có tâm ở $i$. Do đó, chúng ta sẽ thu thập thông tin về tất cả các chuỗi con đối xứng theo cách này.

Các chuỗi đối xứng có độ dài lẻ và chẵn được tính riêng biệt là $d_{odd}[i]$ và $d_{even}[i]$. Đối với các chuỗi đối xứng có độ dài chẵn, chúng ta giả sử rằng chúng có tâm ở vị trí $i$ nếu hai ký tự trung tâm của chúng là $s[i]$ và $s[i-1]$.

Ví dụ: chuỗi $s = abababc$ có ba chuỗi đối xứng có độ dài lẻ với tâm ở vị trí $s[3] = b$, tức là $d_{odd}[3] = 3$:

$$a\ \overbrace{b\ a\ \underbrace{b}_{s_3}\ a\ b}^{d_{odd}[3]=3} c$$

Và chuỗi $s = cbaabd$ có hai chuỗi đối xứng có độ dài chẵn với tâm ở vị trí $s[3] = a$, tức là $d_{even}[3] = 2$:

$$c\ \overbrace{b\ a\ \underbrace{a}_{s_3}\ b}^{d_{even}[3]=2} d$$

Thật ngạc nhiên là có một thuật toán đủ đơn giản để tính toán các "mảng đối xứng" $d_{odd}[]$ và $d_{even}[]$ này trong thời gian tuyến tính. Thuật toán được mô tả trong bài viết này.

## Giải pháp

Nhìn chung, bài toán này có nhiều giải pháp: với [Băm chuỗi](string-hashing.md), nó có thể được giải quyết trong $O(n\cdot \log n)$, và với [Cây hậu tố](suffix-tree-ukkonen.md) và LCA nhanh, bài toán này có thể được giải quyết trong $O(n)$.

Nhưng phương pháp được mô tả ở đây **đủ** đơn giản hơn và có hằng số ẩn nhỏ hơn về độ phức tạp thời gian và bộ nhớ. Thuật toán này được phát hiện bởi **Glenn K. Manacher** vào năm 1975.

Một cách hiện đại khác để giải quyết bài toán này và để xử lý các chuỗi đối xứng nói chung là thông qua cái gọi là cây đối xứng, hay eertree.

## Thuật toán đơn giản

Để tránh sự mơ hồ trong phần mô tả tiếp theo, chúng ta biểu thị thuật toán "đơn giản" là gì.

Đó là thuật toán thực hiện như sau. Đối với mỗi vị trí trung tâm $i$, nó cố gắng tăng câu trả lời thêm một miễn là có thể, so sánh một cặp ký tự tương ứng mỗi lần.

Một thuật toán như vậy rất chậm, nó chỉ có thể tính toán câu trả lời trong $O(n^2)$.

Cách triển khai thuật toán đơn giản là:

```cpp
vector<int> manacher_odd(string s) {
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    for(int i = 1; i <= n; i++) {
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}
```

Các ký tự kết thúc `$` và `^` được sử dụng để tránh phải xử lý riêng các đầu của chuỗi.

## Thuật toán Manacher

Chúng ta mô tả thuật toán để tìm tất cả các chuỗi con đối xứng có độ dài lẻ, tức là để tính toán $d_{odd}[]$.

Để tính toán nhanh, chúng ta sẽ duy trì **ranh giới $(l, r)$** của chuỗi con đối xứng (hoặc chuỗi con) ngoài cùng bên phải được tìm thấy (tức là chuỗi con đối xứng (hoặc chuỗi con) ngoài cùng bên phải hiện tại là $s[l+1] s[l+2] \dots s[r-1]$). Ban đầu, chúng ta đặt $l = 0, r = 1$, tương ứng với chuỗi rỗng.

Vì vậy, chúng ta muốn tính toán $d_{odd}[i]$ cho $i$ tiếp theo và tất cả các giá trị trước đó trong $d_{odd}[]$ đã được tính toán. Chúng ta làm như sau:

* Nếu $i$ nằm ngoài chuỗi con đối xứng hiện tại, tức là $i \geq r$, chúng ta sẽ chỉ khởi chạy thuật toán đơn giản.
    
    Vì vậy, chúng ta sẽ tăng $d_{odd}[i]$ liên tiếp và kiểm tra mỗi lần xem chuỗi con ngoài cùng bên phải hiện tại $[i - d_{odd}[i]\dots i + d_{odd}[i]]$ có phải là chuỗi đối xứng hay không. Khi chúng ta tìm thấy sự không khớp đầu tiên hoặc gặp ranh giới của $s$, chúng ta sẽ dừng lại. Trong trường hợp này, chúng ta cuối cùng đã tính toán được $d_{odd}[i]$. Sau đó, chúng ta không được quên cập nhật $(l, r)$. $r$ nên được cập nhật theo cách mà nó đại diện cho chỉ số cuối cùng của chuỗi con đối xứng ngoài cùng bên phải hiện tại.

* Bây giờ hãy xem xét trường hợp khi $i \le r$. Chúng ta sẽ cố gắng trích xuất một số thông tin từ các giá trị đã được tính toán trong $d_{odd}[]$. Vì vậy, hãy tìm vị trí "gương" của $i$ trong chuỗi con đối xứng $(l, r)$, tức là chúng ta sẽ nhận được vị trí $j = l + (r - i)$, và chúng ta kiểm tra giá trị của $d_{odd}[j]$. Bởi vì $j$ là vị trí đối xứng với $i$ đối với $(l+r)/2$, chúng ta có thể **gần như luôn luôn** gán $d_{odd}[i] = d_{odd}[j]$. Minh họa cho điều này (chuỗi đối xứng xung quanh $j$ thực sự được "sao chép" vào chuỗi đối xứng xung quanh $i$):
    
    $$
    \ldots\ 
    \overbrace{
        s_{l+1}\ \ldots\ 
        \underbrace{
            s_{j-d_{odd}[j]+1}\ \ldots\ s_j\ \ldots\ s_{j+d_{odd}[j]-1}\ 
        }_\text{palindrome}\ 
        \ldots\ 
        \underbrace{
            s_{i-d_{odd}[j]+1}\ \ldots\ s_i\ \ldots\ s_{i+d_{odd}[j]-1}\ 
        }_\text{palindrome}\ 
        \ldots\ s_{r-1}\ 
    }^\text{palindrome}\ 
    \ldots
    $$
    
    Nhưng có một **trường hợp khó** cần được xử lý chính xác: khi chuỗi đối xứng "bên trong" chạm đến ranh giới của chuỗi đối xứng "bên ngoài", tức là $j - d_{odd}[j] \le l$ (hoặc, giống như vậy, $i + d_{odd}[j] \ge r$). Bởi vì tính đối xứng bên ngoài chuỗi đối xứng "bên ngoài" không được đảm bảo, việc chỉ gán $d_{odd}[i] = d_{odd}[j]$ sẽ không chính xác: chúng ta không có đủ dữ liệu để khẳng định rằng chuỗi đối xứng ở vị trí $i$ có cùng độ dài.
    
    Trên thực tế, chúng ta nên giới hạn độ dài của chuỗi đối xứng của mình cho đến bây giờ, tức là gán $d_{odd}[i] = r - i$, để xử lý các tình huống như vậy một cách chính xác. Sau đó, chúng ta sẽ chạy thuật toán đơn giản sẽ cố gắng tăng $d_{odd}[i]$ trong khi có thể.
    
    Minh họa cho trường hợp này (chuỗi đối xứng có tâm $j$ bị hạn chế để phù hợp với chuỗi đối xứng "bên ngoài"):
    
    $$
    \ldots\ 
    \overbrace{
        \underbrace{
            s_{l+1}\ \ldots\ s_j\ \ldots\ s_{j+(j-l)-1}\ 
        }_\text{palindrome}\ 
        \ldots\ 
        \underbrace{
            s_{i-(r-i)+1}\ \ldots\ s_i\ \ldots\ s_{r-1}
        }_\text{palindrome}\ 
    }^\text{palindrome}\ 
    \underbrace{
        \ldots \ldots \ldots \ldots \ldots
    }_\text{thử di chuyển đến đây}
    $$
    
    Hình minh họa cho thấy mặc dù chuỗi đối xứng có tâm $j$ có thể lớn hơn và đi ra ngoài chuỗi đối xứng "bên ngoài", nhưng với $i$ là tâm, chúng ta chỉ có thể sử dụng phần hoàn toàn nằm gọn trong chuỗi đối xứng "bên ngoài". Nhưng câu trả lời cho vị trí $i$ ($d_{odd}[i]$) có thể lớn hơn nhiều so với phần này, vì vậy tiếp theo chúng ta sẽ chạy thuật toán đơn giản của chúng ta, thuật toán này sẽ cố gắng phát triển nó ra bên ngoài chuỗi đối xứng "bên ngoài" của chúng ta, tức là đến vùng "thử di chuyển đến đây".

Một lần nữa, chúng ta không nên quên cập nhật các giá trị $(l, r)$ sau khi tính toán mỗi $d_{odd}[i]$.

## Độ phức tạp của thuật toán Manacher

Thoạt nhìn, không rõ ràng rằng thuật toán này có độ phức tạp thời gian tuyến tính, bởi vì chúng ta thường chạy thuật toán ngây thơ trong khi tìm kiếm câu trả lời cho một vị trí cụ thể.

Tuy nhiên, phân tích kỹ hơn cho thấy thuật toán là tuyến tính. Trên thực tế, [thuật toán xây dựng hàm Z](z-function.md), trông giống như thuật toán này, cũng hoạt động trong thời gian tuyến tính.

Chúng ta có thể nhận thấy rằng mọi lần lặp của thuật toán đơn giản đều làm tăng $r$ thêm một. Ngoài ra $r$ không thể giảm trong quá trình thuật toán. Vì vậy, thuật toán đơn giản sẽ thực hiện tổng cộng $O(n)$ lần lặp.

Các phần khác của thuật toán Manacher rõ ràng hoạt động trong thời gian tuyến tính. Do đó, chúng ta nhận được độ phức tạp thời gian $O(n)$.

## Triển khai thuật toán Manacher

Để tính toán $d_{odd}[]$, chúng ta nhận được mã sau. Những điều cần lưu ý:

- $i$ là chỉ số của ký tự trung tâm của chuỗi đối xứng hiện tại.
- Nếu $i$ vượt quá $r$, $d_{odd}[i]$ được khởi tạo thành 0.
- Nếu $i$ không vượt quá $r$, $d_{odd}[i]$ được khởi tạo thành $d_{odd}[j]$, trong đó $j$ là vị trí gương của $i$ trong $(l,r)$, hoặc $d_{odd}[i]$ bị hạn chế bởi kích thước của chuỗi đối xứng "bên ngoài".
- Vòng lặp while biểu thị thuật toán đơn giản. Chúng ta khởi chạy nó bất kể giá trị của $k$ là bao nhiêu.
- Nếu kích thước của chuỗi đối xứng có tâm ở $i$ là $x$, thì $d_{odd}[i]$ lưu trữ $\frac{x+1}{2}$.

```cpp
vector<int> manacher_odd(string s) {
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 1, r = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = max(0, min(r - i, p[l + (r - i)]));
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if(i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}
```

## Làm việc với chẵn lẻ

Mặc dù có thể triển khai thuật toán Manacher cho độ dài lẻ và chẵn riêng biệt, nhưng việc triển khai phiên bản cho độ dài chẵn thường được coi là khó hơn, vì nó kém tự nhiên hơn và dễ dẫn đến lỗi lệch một.

Để giảm thiểu điều này, có thể rút gọn toàn bộ bài toán thành trường hợp chúng ta chỉ xử lý các chuỗi đối xứng có độ dài lẻ. Để thực hiện việc này, chúng ta có thể đặt thêm ký tự `#` giữa mỗi chữ cái trong chuỗi và cả ở đầu và cuối chuỗi:

$$abcbcba \to \#a\#b\#c\#b\#c\#b\#a\#,$$

$$d = [1,2,1,2,1,4,1,8,1,4,1,2,1,2,1].$$

Như bạn có thể thấy, $d[2i]=2 d_{even}[i]+1$ và $d[2i+1]=2 d_{odd}[i]$ trong đó $d$ biểu thị mảng Manacher cho các chuỗi đối xứng có độ dài lẻ trong chuỗi được nối bằng `#`, trong khi $d_{odd}$ và $d_{even}$ tương ứng với các mảng được xác định ở trên trong chuỗi ban đầu.

Thật vậy, các ký tự `#` không ảnh hưởng đến các chuỗi đối xứng có độ dài lẻ, chúng vẫn tập trung vào các ký tự của chuỗi ban đầu, nhưng bây giờ các chuỗi đối xứng có độ dài chẵn của chuỗi ban đầu là các chuỗi đối xứng có độ dài lẻ của chuỗi mới tập trung vào các ký tự `#`.

Lưu ý rằng $d[2i]$ và $d[2i+1]$ về cơ bản là độ dài tăng thêm $1$ của các chuỗi đối xứng có độ dài lẻ và chẵn lớn nhất tập trung vào $i$ tương ứng.

Việc rút gọn được thực hiện theo cách sau:

```cpp
vector<int> manacher(string s) {
    string t;
    for(auto c: s) {
        t += string("#") + c;
    }
    auto res = manacher_odd(t + "#");
    return vector<int>(begin(res) + 1, end(res) - 1);
}
```

Để đơn giản, việc chia mảng thành $d_{odd}$ và $d_{even}$ cũng như tính toán rõ ràng của chúng bị bỏ qua.

## Bài tập

- [Library Checker - Enumerate Palindromes](https://judge.yosupo.jp/problem/enumerate_palindromes)
- [Longest Palindrome](https://cses.fi/problemset/task/1111)
- [UVA 11475 - Extend to Palindrome](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=26&page=show_problem&problem=2470)
- [GYM - (Q) QueryreuQ](https://codeforces.com/gym/101806/problem/Q)
- [CF - Prefix-Suffix Palindrome](https://codeforces.com/contest/1326/problem/D2)
- [SPOJ - Number of Palindromes](https://www.spoj.com/problems/NUMOFPAL/)
- [Kattis - Palindromes](https://open.kattis.com/problems/palindromes)




