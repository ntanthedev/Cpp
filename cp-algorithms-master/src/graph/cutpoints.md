# Tìm điểm khớp nối trong đồ thị trong $O(N+M)$

---
tags:
  - Dịch
e_maxx_link: cutpoints
---

# Tìm điểm khớp nối trong đồ thị trong $O(N+M)$

Cho một đồ thị vô hướng. Một điểm khớp nối (articulation point) (hoặc đỉnh cắt - cut vertex) được định nghĩa là một đỉnh mà khi loại bỏ cùng với các cạnh liên quan, sẽ làm cho đồ thị bị ngắt kết nối (hoặc chính xác hơn là làm tăng số lượng thành phần được kết nối trong đồ thị). Nhiệm vụ là tìm tất cả các điểm khớp nối trong đồ thị đã cho.

Thuật toán được mô tả ở đây dựa trên [tìm kiếm theo chiều sâu](depth-first-search.md) và có độ phức tạp $O(N+M)$, trong đó $N$ là số lượng đỉnh và $M$ là số lượng cạnh trong đồ thị.

## Thuật toán

Chọn một đỉnh tùy ý của đồ thị $root$ và chạy [tìm kiếm theo chiều sâu](depth-first-search.md) từ nó. Lưu ý thực tế sau đây (rất dễ chứng minh):

- Giả sử chúng ta đang ở trong DFS, xem xét các cạnh bắt đầu từ đỉnh $v\ne root$.
Nếu cạnh hiện tại $(v, to)$ sao cho không có đỉnh $to$ nào hoặc con cháu của nó trong cây duyệt DFS có cạnh lùi (back-edge) đến bất kỳ tổ tiên nào của $v$, thì $v$ là một điểm khớp nối. Nếu không, $v$ không phải là điểm khớp nối.

- Hãy xem xét trường hợp còn lại của $v=root$.
Đỉnh này sẽ là điểm khớp nối nếu và chỉ khi đỉnh này có nhiều hơn một con trong cây DFS.

Bây giờ chúng ta phải học cách kiểm tra thực tế này cho mỗi đỉnh một cách hiệu quả. Chúng ta sẽ sử dụng "thời điểm vào nút" được tính toán bởi tìm kiếm theo chiều sâu.

Vì vậy, cho $tin[v]$ biểu thị thời điểm vào nút $v$. Chúng ta giới thiệu một mảng $low[v]$ cho phép chúng ta kiểm tra thực tế cho mỗi đỉnh $v$. $low[v]$ là giá trị nhỏ nhất của $tin[v]$, thời điểm vào $tin[p]$ cho mỗi nút $p$ được kết nối với nút $v$ thông qua một cạnh lùi $(v, p)$ và giá trị của $low[to]$ cho mỗi đỉnh $to$ là con cháu trực tiếp của $v$ trong cây DFS:

$$low[v] = \min \begin{cases} tin[v] \\ tin[p] &\text{ cho tất cả }p\text{ mà }(v, p)\text{ là cạnh lùi} \\ low[to]& \text{ cho tất cả }to\text{ mà }(v, to)\text{ là cạnh cây} \end{cases}$$

Bây giờ, có một cạnh lùi từ đỉnh $v$ hoặc một trong các con cháu của nó đến một trong các tổ tiên của nó nếu và chỉ khi đỉnh $v$ có một con $to$ mà $low[to] < tin[v]$. Nếu $low[to] = tin[v]$, cạnh lùi đi thẳng đến $v$, nếu không thì nó đi đến một trong các tổ tiên của $v$.

Do đó, đỉnh $v$ trong cây DFS là một điểm khớp nối nếu và chỉ khi $low[to] \geq tin[v]$.

## Triển khai

Việc triển khai cần phân biệt ba trường hợp: khi chúng ta đi xuống cạnh trong cây DFS, khi chúng ta tìm thấy một cạnh lùi đến tổ tiên của đỉnh và khi chúng ta quay trở lại cha của đỉnh. Đây là những trường hợp:

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
    int children=0;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] >= tin[v] && p!=-1)
                IS_CUTPOINT(v);
            ++children;
        }
    }
    if(p == -1 && children > 1)
        IS_CUTPOINT(v);
}
 
void find_cutpoints() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs (i);
    }
}
```

Hàm chính là `find_cutpoints`; nó thực hiện khởi tạo cần thiết và bắt đầu tìm kiếm theo chiều sâu trong mỗi thành phần được kết nối (connected component) của đồ thị.

Hàm `IS_CUTPOINT(a)` là một số hàm sẽ xử lý thực tế là đỉnh $a$ là một điểm khớp nối, ví dụ, in nó ra (Hãy cẩn thận rằng điều này có thể được gọi nhiều lần cho một đỉnh).

## Bài tập thực hành

- [UVA #10199 "Tourist Guide"](http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=13&page=show_problem&problem=1140) [độ khó: thấp]
- [UVA #315 "Network"](http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=5&page=show_problem&problem=251) [độ khó: thấp]
- [SPOJ - Submerging Islands](http://www.spoj.com/problems/SUBMERGE/)
- [Codeforces - Cutting Figure](https://codeforces.com/problemset/problem/193/A)

--- 




