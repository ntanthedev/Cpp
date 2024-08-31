# Giới thiệu về Quy hoạch động (Dynamic Programming)

---
tags:
  - Bản gốc
---

# Giới thiệu về Quy hoạch động (Dynamic Programming)

Bản chất của quy hoạch động (Dynamic Programming) là tránh tính toán lặp lại. Thông thường, các bài toán quy hoạch động có thể được giải quyết một cách tự nhiên bằng đệ quy. Trong những trường hợp như vậy, cách dễ nhất là viết giải pháp đệ quy, sau đó lưu các trạng thái lặp lại trong một bảng tra cứu. Quá trình này được gọi là quy hoạch động từ trên xuống với ghi nhớ (memoization). Đó là cách đọc "memoization" (giống như chúng ta đang viết vào một cuốn sổ ghi nhớ) chứ không phải memorization (ghi nhớ).

Một trong những ví dụ cổ điển, cơ bản nhất về quá trình này là dãy Fibonacci. Công thức đệ quy của nó là $f(n) = f(n-1) + f(n-2)$ trong đó $n \ge 2$ và $f(0)=0$ và $f(1)=1$. Trong C++, điều này sẽ được biểu thị là:

```cpp
int f(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return f(n - 1) + f(n - 2);
}
```

Thời gian chạy của hàm đệ quy này là theo cấp số nhân - xấp xỉ $O(2^n)$ vì một lệnh gọi hàm ( $f(n)$ ) dẫn đến 2 lệnh gọi hàm có kích thước tương tự ($f(n-1)$ và $f(n-2)$ ).

## Tăng tốc Fibonacci với Quy hoạch động (Ghi nhớ - Memoization)

Hàm đệ quy của chúng ta hiện đang giải quyết fibonacci trong thời gian theo cấp số nhân. Điều này có nghĩa là chúng ta chỉ có thể xử lý các giá trị đầu vào nhỏ trước khi bài toán trở nên quá khó. Ví dụ: $f(29)$ dẫn đến *hơn 1 triệu* lệnh gọi hàm!

Để tăng tốc độ, chúng ta nhận ra rằng số lượng bài toán con chỉ là $O(n)$. Tức là, để tính toán $f(n)$ chúng ta chỉ cần biết $f(n-1),f(n-2), \dots ,f(0)$. Do đó, thay vì tính toán lại các bài toán con này, chúng ta giải chúng một lần rồi lưu kết quả vào bảng tra cứu. Các lệnh gọi tiếp theo sẽ sử dụng bảng tra cứu này và trả về kết quả ngay lập tức, do đó loại bỏ công việc theo cấp số nhân!

Mỗi lệnh gọi đệ quy sẽ kiểm tra dựa trên bảng tra cứu để xem giá trị đã được tính toán hay chưa. Điều này được thực hiện trong thời gian $O(1)$. Nếu chúng ta đã tính toán nó trước đó, hãy trả về kết quả, nếu không, chúng ta tính toán hàm bình thường. Tổng thời gian chạy là $O(n)$! Đây là một cải tiến to lớn so với thuật toán thời gian theo cấp số nhân trước đó của chúng ta!

```cpp
const int MAXN = 100;
bool found[MAXN];
int memo[MAXN];

int f(int n) {
    if (found[n]) return memo[n];
    if (n == 0) return 0;
    if (n == 1) return 1;

    found[n] = true;
    return memo[n] = f(n - 1) + f(n - 2);
}
```

Với hàm đệ quy có ghi nhớ mới của chúng ta, $f(29)$, vốn dẫn đến *hơn 1 triệu lệnh gọi*, giờ chỉ dẫn đến *57* lệnh gọi, gần *20.000 lần* ít hơn số lệnh gọi hàm! Trớ trêu thay, bây giờ chúng ta bị giới hạn bởi kiểu dữ liệu của mình. $f(46)$ là số fibonacci cuối cùng có thể phù hợp với số nguyên 32 bit có dấu.

Thông thường, chúng ta cố gắng lưu các trạng thái trong mảng, nếu có thể, vì thời gian tra cứu là $O(1)$ với chi phí tối thiểu. Tuy nhiên, nói chung hơn, chúng ta có thể lưu các trạng thái theo bất kỳ cách nào chúng ta muốn. Các ví dụ khác bao gồm map (cây tìm kiếm nhị phân) hoặc unordered_map (bảng băm).

Ví dụ về điều này có thể là:

```cpp
unordered_map<int, int> memo;
int f(int n) {
    if (memo.count(n)) return memo[n];
    if (n == 0) return 0;
    if (n == 1) return 1;

    return memo[n] = f(n - 1) + f(n - 2);
}
```

Hoặc tương tự:

```cpp
map<int, int> memo;
int f(int n) {
    if (memo.count(n)) return memo[n];
    if (n == 0) return 0;
    if (n == 1) return 1;

    return memo[n] = f(n - 1) + f(n - 2);
}
```

Cả hai điều này hầu như luôn chậm hơn so với phiên bản dựa trên mảng cho một hàm đệ quy có ghi nhớ chung.
Những cách thay thế này để lưu trạng thái chủ yếu hữu ích khi lưu vector hoặc chuỗi như một phần của không gian trạng thái.

Cách phân tích thời gian chạy của hàm đệ quy có ghi nhớ của người không chuyên là:

$$\text{công việc cho mỗi bài toán con} * \text{số lượng bài toán con}$$

Sử dụng cây tìm kiếm nhị phân (map trong C++) để lưu các trạng thái về mặt kỹ thuật sẽ dẫn đến $O(n \log n)$ vì mỗi lần tra cứu và chèn sẽ mất công việc $O(\log n)$ và với $O(n)$ bài toán con duy nhất, chúng ta có $O(n \log n)$ thời gian.

Cách tiếp cận này được gọi là từ trên xuống, vì chúng ta có thể gọi hàm với một giá trị truy vấn và phép tính bắt đầu đi từ trên cùng (giá trị được truy vấn) xuống dưới cùng (trường hợp cơ sở của đệ quy) và tạo các lối tắt thông qua ghi nhớ trên đường đi.

## Quy hoạch động từ dưới lên (Bottom-up Dynamic Programming)

Cho đến bây giờ bạn mới chỉ thấy quy hoạch động từ trên xuống với ghi nhớ. Tuy nhiên, chúng ta cũng có thể giải quyết các bài toán bằng quy hoạch động từ dưới lên.
Từ dưới lên hoàn toàn ngược lại với từ trên xuống, bạn bắt đầu từ dưới cùng (trường hợp cơ sở của đệ quy) và mở rộng nó thành ngày càng nhiều giá trị hơn.

Để tạo cách tiếp cận từ dưới lên cho các số fibonacci, chúng ta khởi tạo các trường hợp cơ sở trong một mảng. Sau đó, chúng ta chỉ cần sử dụng định nghĩa đệ quy trên mảng:

```cpp
const int MAXN = 100;
int fib[MAXN];

int f(int n) {
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; i++) fib[i] = fib[i - 1] + fib[i - 2];

    return fib[n];
}
```

Tất nhiên, như đã viết, điều này hơi ngớ ngẩn vì hai lý do:
Thứ nhất, chúng ta làm công việc lặp đi lặp lại nếu chúng ta gọi hàm nhiều hơn một lần.
Thứ hai, chúng ta chỉ cần sử dụng hai giá trị trước đó để tính toán phần tử hiện tại. Do đó, chúng ta có thể giảm bộ nhớ của mình từ $O(n)$ xuống $O(1)$.

Một ví dụ về giải pháp quy hoạch động từ dưới lên cho fibonacci sử dụng $O(1)$ có thể là:

```cpp
const int MAX_SAVE = 3;
int fib[MAX_SAVE];

int f(int n) {
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; i++)
        fib[i % MAX_SAVE] = fib[(i - 1) % MAX_SAVE] + fib[(i - 2) % MAX_SAVE];

    return fib[n % MAX_SAVE];
}
```

Lưu ý rằng chúng ta đã thay đổi hằng số từ `MAXN` thành `MAX_SAVE`. Điều này là do tổng số phần tử chúng ta cần truy cập chỉ là 3. Nó không còn tỷ lệ với kích thước đầu vào và theo định nghĩa là bộ nhớ $O(1)$. Ngoài ra, chúng ta sử dụng một mẹo phổ biến (sử dụng toán tử modulo) chỉ duy trì các giá trị chúng ta cần.

Đó là nó. Đó là những điều cơ bản của quy hoạch động: Đừng lặp lại công việc bạn đã làm trước đây.

Một trong những mẹo để làm tốt hơn trong quy hoạch động là nghiên cứu một số ví dụ cổ điển.

## Các bài toán quy hoạch động cổ điển
| Tên                                               | Mô tả/Ví dụ                                                                                                                                                                                                                    |
| --------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Bài toán cái túi 0-1 (0-1 knapsack)               | Cho $W$, $N$ và $N$ vật phẩm có trọng lượng $w_i$ và giá trị $v_i$, giá trị $\sum_{i=1}^{k} v_i$ tối đa cho mỗi tập hợp con của các vật phẩm có kích thước $k$ ($1 \le k \le N$) trong khi đảm bảo $\sum_{i=1}^{k} w_i \le W$ là bao nhiêu? |
| Tổng tập con (Subset Sum)                          | Cho $N$ số nguyên và $T$, hãy xác định xem có tồn tại một tập hợp con của tập hợp đã cho mà các phần tử của nó có tổng bằng $T$ hay không.                                                                                           |
| Dãy con tăng dài nhất (Longest Increasing Subsequence) | Cho một mảng chứa $N$ số nguyên. Nhiệm vụ của bạn là xác định dãy con tăng dài nhất (LCS) trong mảng, tức là LCS trong đó mọi phần tử đều lớn hơn phần tử trước đó.                                                                         |
| Đếm tất cả các đường đi có thể có trong ma trận.  | Cho $N$ và $M$, hãy đếm tất cả các đường dẫn phân biệt có thể có từ $(1,1)$ đến $(N, M)$, trong đó mỗi bước là từ $(i,j)$ đến $(i+1,j)$ hoặc $(i,j+1)$.                                                                               |
| Dãy con chung dài nhất (Longest Common Subsequence) | Cho hai chuỗi $s$ và $t$. Tìm độ dài của chuỗi dài nhất là dãy con của cả $s$ và $t$.                                                                                                                                                |
| Đường dẫn dài nhất trong đồ thị có hướng phi chu trình (DAG) | Tìm đường dẫn dài nhất trong đồ thị có hướng phi chu trình (DAG - Directed Acyclic Graph).                                                                                                                                                                 |
| Dãy con đối xứng dài nhất (Longest Palindromic Subsequence) | Tìm dãy con đối xứng dài nhất (LPS - Longest Palindromic Subsequence) của một chuỗi nhất định.                                                                                                                                           |
| Cắt thanh (Rod Cutting)                            | Cho một thanh có độ dài $n$ đơn vị, Cho một mảng số nguyên `cuts` trong đó `cuts[i]` biểu thị một vị trí bạn nên thực hiện cắt. Chi phí của một lần cắt là chiều dài của thanh cần cắt. Tổng chi phí tối thiểu của các lần cắt là bao nhiêu. |
| Khoảng cách chỉnh sửa (Edit Distance)             | Khoảng cách chỉnh sửa giữa hai chuỗi là số lượng thao tác tối thiểu cần thiết để biến đổi một chuỗi thành chuỗi kia. Các thao tác là ["Thêm", "Xóa", "Thay thế"]                                                                    |

## Chủ đề liên quan
* Quy hoạch động Bitmask
* Quy hoạch động chữ số
* Quy hoạch động trên cây

Tất nhiên, mẹo quan trọng nhất là luyện tập.

## Bài tập thực hành
* [LeetCode - 1137. N-th Tribonacci Number](https://leetcode.com/problems/n-th-tribonacci-number/description/)
* [LeetCode - 118. Pascal's Triangle](https://leetcode.com/problems/pascals-triangle/description/)
* [LeetCode - 1025. Divisor Game](https://leetcode.com/problems/divisor-game/description/)
* [Codeforces - Zuma](https://codeforces.com/problemset/problem/607/b)
* [LeetCode - 221. Maximal Square](https://leetcode.com/problems/maximal-square/description/)
* [LeetCode - 1039. Minimum Score Triangulation of Polygon](https://leetcode.com/problems/minimum-score-triangulation-of-polygon/description/)

## Cuộc thi Dp
* [Atcoder - Educational DP Contest](https://atcoder.jp/contests/dp/tasks)
* [CSES - Dynamic Programming](https://cses.fi/problemset/list/)



