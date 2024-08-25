---
title: Tìm cầu nối trong đồ thị trong O(N+M)
tags:
  - Translated
e_maxx_link: bridge_searching
---
# Tìm cầu nối trong đồ thị trong $O(N+M)$

Cho một đồ thị vô hướng. Một cầu nối được định nghĩa là một cạnh mà khi loại bỏ, sẽ làm cho đồ thị bị ngắt kết nối (hoặc chính xác hơn là làm tăng số lượng thành phần liên thông trong đồ thị). Nhiệm vụ là tìm tất cả các cầu nối trong đồ thị đã cho.

Nói một cách không chính thức, bài toán được phát biểu như sau: cho một bản đồ các thành phố được kết nối với nhau bằng đường, hãy tìm tất cả các con đường "quan trọng", tức là các con đường mà khi bị loại bỏ, sẽ làm mất đường đi giữa một số cặp thành phố.

Thuật toán được mô tả ở đây dựa trên [tìm kiếm theo chiều sâu](depth-first-search.md) và có độ phức tạp $O(N+M)$, trong đó $N$ là số lượng đỉnh và $M$ là số lượng cạnh trong đồ thị.

Lưu ý rằng cũng có bài viết [Tìm cầu nối trực tuyến](bridge-searching-online.md) - không giống như thuật toán ngoại tuyến được mô tả ở đây, thuật toán trực tuyến có thể duy trì danh sách tất cả các cầu nối trong một đồ thị thay đổi (giả sử rằng loại thay đổi duy nhất là thêm các cạnh mới).

## Thuật toán

Chọn một đỉnh bất kỳ của đồ thị $root$ và chạy [tìm kiếm theo chiều sâu](depth-first-search.md) từ nó. Lưu ý thực tế sau đây (điều này dễ dàng chứng minh):

- Giả sử chúng ta đang ở trong DFS, xem xét các cạnh bắt đầu từ đỉnh $v$. Cạnh hiện tại $(v, to)$ là một cầu nối nếu và chỉ khi không có đỉnh $to$ và các con cháu của nó trong cây duyệt DFS có cạnh lùi đến đỉnh $v$ hoặc bất kỳ tổ tiên nào của nó. Thật vậy, điều kiện này có nghĩa là không có cách nào khác từ $v$ đến $to$ ngoại trừ cạnh $(v, to)$.

Bây giờ chúng ta phải học cách kiểm tra thực tế này cho mỗi đỉnh một cách hiệu quả. Chúng ta sẽ sử dụng "thời gian vào nút" được tính toán bởi tìm kiếm theo chiều sâu.

Vì vậy, hãy để $tin[v]$ biểu thị thời gian vào cho nút $v$. Chúng ta giới thiệu một mảng $low$ sẽ cho phép chúng ta kiểm tra thực tế cho mỗi đỉnh $v$. $low[v]$ là giá trị nhỏ nhất của $tin[v]$, thời gian vào $tin[p]$ cho mỗi nút $p$ được kết nối với nút $v$ thông qua một cạnh lùi $(v, p)$ và các giá trị của $low[to]$ cho mỗi đỉnh $to$ là con cháu trực tiếp của $v$ trong cây DFS:

$$low[v] = \min \begin{cases} tin[v] \\ tin[p]& \text{ cho tất cả }p\text{ mà }(v, p)\text{ là cạnh lùi} \\ low[to]& \text{ cho tất cả }to\text{ mà }(v, to)\text{ là cạnh cây} \end{cases}$$

Bây giờ, có một cạnh lùi từ đỉnh $v$ hoặc một trong các con cháu của nó đến một trong các tổ tiên của nó nếu và chỉ khi đỉnh $v$ có một con $to$ mà $low[to] \leq tin[v]$. Nếu $low[to] = tin[v]$, cạnh lùi đến trực tiếp $v$, nếu không thì nó đến một trong các tổ tiên của $v$.

Do đó, cạnh hiện tại $(v, to)$ trong cây DFS là một cầu nối nếu và chỉ khi $low[to] > tin[v]$.

## Triển khai

Việc triển khai cần phân biệt ba trường hợp: khi chúng ta đi xuống cạnh trong cây DFS, khi chúng ta tìm thấy một cạnh lùi đến một tổ tiên của đỉnh và khi chúng ta quay lại cha của đỉnh. Đây là các trường hợp:

- $visited[to] = false$ - cạnh là một phần của cây DFS;
- $visited[to] = true$ && $to \neq parent$ - cạnh là cạnh lùi đến một trong các tổ tiên;
- $to = parent$ - cạnh dẫn trở lại cha trong cây DFS.

Để triển khai điều này, chúng ta cần một hàm tìm kiếm theo chiều sâu chấp nhận đỉnh cha của nút hiện tại.

```cpp
int n; // số lượng nút
vector<vector<int>> adj; // danh sách kề của đồ thị

vector<bool> visited;
vector<int> tin, low;
int timer;
 
void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                IS_BRIDGE(v, to);
        }
    }
}
 
void find_bridges() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}
```

Hàm chính là `find_bridges`; nó thực hiện khởi tạo cần thiết và bắt đầu tìm kiếm theo chiều sâu trong mỗi thành phần liên thông của đồ thị.

Hàm `IS_BRIDGE(a, b)` là một hàm nào đó sẽ xử lý thực tế rằng cạnh $(a, b)$ là một cầu nối, ví dụ, in nó ra.

Lưu ý rằng việc triển khai này sẽ gặp sự cố nếu đồ thị có nhiều cạnh, vì nó bỏ qua chúng. Tất nhiên, nhiều cạnh sẽ không bao giờ là một phần của câu trả lời, vì vậy `IS_BRIDGE` có thể kiểm tra thêm rằng cầu nối được báo cáo không phải là một cạnh đa. Ngoài ra, có thể chuyển đến `dfs` chỉ mục của cạnh được sử dụng để vào đỉnh thay vì đỉnh cha (và lưu trữ các chỉ mục của tất cả các đỉnh).

## Bài tập thực hành

- [UVA #796 "Critical Links"](http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=737) [độ khó: thấp]
- [UVA #610 "Street Directions"](http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=551) [độ khó: trung bình]
- [Case of the Computer Network (Codeforces Round #310 Div. 1 E)](http://codeforces.com/problemset/problem/555/E) [độ khó: cao]
* [UVA 12363 - Hedge Mazes](https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=3785)
* [UVA 315 - Network](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=251)
* [GYM - Computer Network (J)](http://codeforces.com/gym/100114)
* [SPOJ - King Graffs Defense](http://www.spoj.com/problems/GRAFFDEF/)
* [SPOJ - Critical Edges](http://www.spoj.com/problems/EC_P/)
* [Codeforces - Break Up](http://codeforces.com/contest/700/problem/C)
* [Codeforces - Tourist Reform](http://codeforces.com/contest/732/problem/F)
