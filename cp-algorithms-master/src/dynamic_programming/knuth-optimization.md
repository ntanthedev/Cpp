# Tối ưu hóa Knuth (Knuth's Optimization)

Tối ưu hóa Knuth, còn được gọi là Tăng tốc Knuth-Yao, là một trường hợp đặc biệt của quy hoạch động (DP) trên phạm vi, có thể tối ưu hóa độ phức tạp thời gian của các giải pháp bằng một hệ số tuyến tính, từ $O(n^3)$ cho DP phạm vi tiêu chuẩn thành $O(n^2)$.

## Điều kiện

Tăng tốc được áp dụng cho các chuyển đổi có dạng

$$dp(i, j) = \min_{i \leq k < j} [ dp(i, k) + dp(k+1, j) + C(i, j) ].$$

Tương tự như [chia để trị DP](./divide-and-conquer-dp.md), cho $opt(i, j)$ là giá trị của $k$ cực tiểu hóa biểu thức trong chuyển đổi ($opt$ được gọi là "điểm chia tối ưu" trong bài viết này). Tối ưu hóa yêu cầu điều kiện sau được thỏa mãn:

$$opt(i, j-1) \leq opt(i, j) \leq opt(i+1, j).$$

Chúng ta có thể chứng minh rằng điều đó là đúng khi hàm chi phí $C$ thỏa mãn các điều kiện sau cho $a \leq b \leq c \leq d$:

1. $C(b, c) \leq C(a, d)$;

2. $C(a, c) + C(b, d) \leq C(a, d) + C(b, c)$ (bất đẳng thức tứ giác [QI]).

Kết quả này được chứng minh thêm bên dưới.

## Thuật toán

Hãy xử lý các trạng thái dp theo cách mà chúng ta tính toán $dp(i, j-1)$ và $dp(i+1, j)$ trước $dp(i, j)$ và khi làm như vậy, chúng ta cũng tính toán $opt(i, j-1)$ và $opt(i+1, j)$. Sau đó, để tính toán $opt(i, j)$, thay vì kiểm tra các giá trị của $k$ từ $i$ đến $j-1$, chúng ta chỉ cần kiểm tra từ $opt(i, j-1)$ đến $opt(i+1, j)$. Để xử lý các cặp $(i, j)$ theo thứ tự này, chúng ta chỉ cần sử dụng các vòng lặp for lồng nhau trong đó $i$ đi từ giá trị lớn nhất đến giá trị nhỏ nhất và $j$ đi từ $i+1$ đến giá trị lớn nhất.

### Triển khai chung

Mặc dù cách triển khai khác nhau, đây là một ví dụ
khá chung. Cấu trúc của mã gần như giống hệt với cấu trúc của DP phạm vi.

```{.cpp file=knuth_optimization}

int solve() {
    int N;
    ... // đọc N và đầu vào
    int dp[N][N], opt[N][N];

    auto C = [&](int i, int j) {
        ... // Triển khai hàm chi phí C.
    };

    for (int i = 0; i < N; i++) {
        opt[i][i] = i;
        ... // Khởi tạo dp[i][i] theo bài toán
    }

    for (int i = N-2; i >= 0; i--) {
        for (int j = i+1; j < N; j++) {
            int mn = INT_MAX;
            int cost = C(i, j);
            for (int k = opt[i][j-1]; k <= min(j-1, opt[i+1][j]); k++) {
                if (mn >= dp[i][k] + dp[k+1][j] + cost) {
                    opt[i][j] = k; 
                    mn = dp[i][k] + dp[k+1][j] + cost; 
                }
            }
            dp[i][j] = mn; 
        }
    }

    return dp[0][N-1];
}
```

### Độ phức tạp

Độ phức tạp của thuật toán có thể được ước tính bằng tổng sau:

$$
\sum\limits_{i=1}^N \sum\limits_{j=i+1}^N [opt(i+1,j)-opt(i,j-1)] =
\sum\limits_{i=1}^N \sum\limits_{j=i}^{N-1} [opt(i+1,j+1)-opt(i,j)].
$$

Như bạn thấy, hầu hết các số hạng trong biểu thức này triệt tiêu lẫn nhau, ngoại trừ các số hạng dương với $j=N$ và các số hạng âm với $i=1$. Do đó, toàn bộ tổng có thể được ước tính là

$$
\sum\limits_{k=1}^N[opt(k,N)-opt(1,k)] = O(n^2),
$$

thay vì $O(n^3)$ như sẽ là nếu chúng ta đang sử dụng DP phạm vi thông thường.

### Trên thực tế

Ứng dụng phổ biến nhất của tối ưu hóa Knuth là trong DP phạm vi, với chuyển đổi nhất định. Khó khăn duy nhất là chứng minh rằng hàm chi phí thỏa mãn các điều kiện nhất định. Trường hợp đơn giản nhất là khi hàm chi phí $C(i, j)$ chỉ đơn giản là tổng các phần tử của mảng con $S[i, i+1, ..., j]$ cho một số mảng (tùy thuộc vào câu hỏi). Tuy nhiên, đôi khi chúng có thể phức tạp hơn.

Lưu ý rằng hơn cả các điều kiện trên chuyển đổi dp và hàm chi phí, chìa khóa cho tối ưu hóa này là bất đẳng thức trên điểm chia tối ưu. Trong một số bài toán, chẳng hạn như bài toán cây tìm kiếm nhị phân tối ưu (ngẫu nhiên, là bài toán ban đầu mà tối ưu hóa này được phát triển), các chuyển đổi và hàm chi phí sẽ ít rõ ràng hơn, tuy nhiên, người ta vẫn có thể chứng minh rằng $opt(i, j-1) \leq opt(i, j) \leq opt(i+1, j)$ và do đó, hãy sử dụng tối ưu hóa này.


### Chứng minh tính đúng đắn

Để chứng minh tính đúng đắn của thuật toán này về các điều kiện $C(i, j)$, chúng ta chỉ cần chứng minh rằng

$$
opt(i, j-1) \leq opt(i, j) \leq opt(i+1, j)
$$

giả sử các điều kiện nhất định được thỏa mãn.

!!! lemma "Bổ đề"
    $dp(i, j)$ cũng thỏa mãn bất đẳng thức tứ giác, với điều kiện các điều kiện của bài toán được thỏa mãn.

??? hint "Chứng minh"
    Bằng chứng cho bổ đề này sử dụng quy nạp mạnh. Nó được lấy từ bài báo <a href="https://dl.acm.org/doi/pdf/10.1145/800141.804691">Efficient Dynamic Programming Using Quadrangle Inequalities</a>, do F. Frances Yao viết, đã giới thiệu Knuth-Yao Speedup (câu lệnh cụ thể này là Bổ đề 2.1 trong bài báo). Ý tưởng là quy nạp theo độ dài $l = d - a$. Trường hợp $l = 1$ là tầm thường. Đối với $l > 1$, hãy xem xét 2 trường hợp:

 1. $b = c$
 Bất đẳng thức rút gọn thành $dp(a, b) + dp(b, d) \leq dp(a, d)$ (Điều này giả định rằng $dp(i, i) = 0$ với mọi $i$, là trường hợp của tất cả các bài toán sử dụng tối ưu hóa này). Cho $opt(a,d) = z$.

     - Nếu $z < j$,
     Lưu ý rằng

         $$
         dp(a, b) \leq dp_{z}(a, b) = dp(a, z) + dp(z+1, b) + C(a, b).
         $$

         Do đó,

         $$
         dp(a, b) + dp(b, d) \leq dp(a, z) + dp(z+1, b) + dp(b, d) + C(a, b)
         $$

         Từ giả thuyết quy nạp, $dp(z+1, b) + dp(b, d) \leq dp(z+1, d)$. Ngoài ra, được cho là $C(a, b) \leq C(a, d)$. Kết hợp 2 sự kiện này với bất đẳng thức trên mang lại kết quả mong muốn.

     - Nếu $z \geq j$, chứng minh của trường hợp này đối xứng với trường hợp trước đó.

 1. $b < c$
 Cho $opt(b, c) = z$ và $opt(a, d) = y$.

     - Nếu $z \leq y$,

         $$
         dp(a, c) + dp(b, d) \leq dp_{z}(a, c) + dp_{y}(b, d)
         $$

         trong đó

         $$
         dp_{z}(a, c) + dp_{y}(b, d) = C(a, c) + C(b, d) + dp(a, z) + dp(z+1, c) + dp(b, y) + dp(y+1, d).
         $$

         Sử dụng QI trên $C$ và trên trạng thái dp cho các chỉ số $z+1 \leq y+1 \leq c \leq d$ (từ giả thuyết quy nạp) mang lại kết quả mong muốn.

     - Nếu $z > y$, chứng minh của trường hợp này đối xứng với trường hợp trước đó.

 Điều này hoàn thành chứng minh của bổ đề.

Bây giờ, hãy xem xét thiết lập sau. Chúng ta có 2 chỉ số $i \leq p \leq q < j$. Đặt $dp_{k} = C(i, j) + dp(i, k) + dp(k+1, j)$.

Giả sử chúng ta chứng minh rằng

$$
dp_{p}(i, j-1) \geq dp_{q}(i, j-1) \implies dp_{p}(i, j) \geq dp_{q}(i, j).
$$

Đặt $q = opt(i, j-1)$, theo định nghĩa, $dp_{p}(i, j-1) \geq dp_{q}(i, j-1)$. Do đó, áp dụng bất đẳng thức cho tất cả $i \leq p \leq q$, chúng ta có thể suy ra rằng $opt(i, j)$ ít nhất bằng $opt(i, j-1)$, chứng minh nửa đầu của bất đẳng thức.

Bây giờ, sử dụng QI trên một số chỉ số $p+1 \leq q+1 \leq j-1 \leq j$, chúng ta nhận được

$$\begin{align}
&dp(p+1, j-1) + dp(q+1, j) ≤ dp(q+1, j-1) + dp(p+1, j) \\
\implies& (dp(i, p) + dp(p+1, j-1) + C(i, j-1)) + (dp(i, q) + dp(q+1, j) + C(i, j)) \\  
\leq& (dp(i, q) + dp(q+1, j-1) + C(i, j-1)) + (dp(i, p) + dp(p+1, j) + C(i, j)) \\  
\implies& dp_{p}(i, j-1) + dp_{q}(i, j) ≤ dp_{p}(i, j) + dp_{q}(i, j-1) \\
\implies& dp_{p}(i, j-1) - dp_{q}(i, j-1) ≤ dp_{p}(i, j) - dp_{q}(i, j) \\
\end{align}$$

Cuối cùng,

$$\begin{align}
&dp_{p}(i, j-1) \geq dp_{q}(i, j-1) \\
&\implies 0 \leq dp_{p}(i, j-1) - dp_{q}(i, j-1) \leq dp_{p}(i, j) - dp_{q}(i, j) \\
&\implies dp_{p}(i, j) \geq dp_{q}(i, j)
\end{align}$$  

Điều này chứng minh phần đầu tiên của bất đẳng thức, tức là $opt(i, j-1) \leq opt(i, j)$. Phần thứ hai $opt(i, j) \leq opt(i+1, j)$ có thể được hiển thị với cùng một ý tưởng, bắt đầu bằng bất đẳng thức
$dp(i, p) + dp(i+1, q) ≤ dp(i+1, p) + dp(i, q)$.

Điều này hoàn thành chứng minh.

## Bài tập thực hành
- [UVA - Cutting Sticks](https://onlinejudge.org/external/100/10003.pdf)
- [UVA - Prefix Codes](https://onlinejudge.org/external/120/12057.pdf)
- [SPOJ - Breaking String](https://www.spoj.com/problems/BRKSTRNG/)
- [UVA - Optimal Binary Search Tree](https://onlinejudge.org/external/103/10304.pdf)


## Tài liệu tham khảo
- [Bài viết trên Geeksforgeeks](https://www.geeksforgeeks.org/knuths-optimization-in-dynamic-programming/)
- [Tài liệu về Tăng tốc DP](https://home.cse.ust.hk/~golin/COMP572/Notes/DP_speedup.pdf)
- [Efficient Dynamic Programming Using Quadrangle Inequalities](https://dl.acm.org/doi/pdf/10.1145/800141.804691)

---

