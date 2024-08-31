# Tìm cầu trong đồ thị trong $O(N + M)$

---
tags:
  - Dịch
e_maxx_link: bridge_searching
---

# Tìm cầu trong đồ thị trong $O(N + M)$

Cho một đồ thị vô hướng. Một cầu (bridge) được định nghĩa là một cạnh, khi bị loại bỏ, sẽ làm cho đồ thị bị ngắt kết nối (hoặc chính xác hơn là làm tăng số lượng thành phần được kết nối trong đồ thị). Nhiệm vụ là tìm tất cả các cầu trong đồ thị đã cho.

Nói một cách không chính thức, bài toán được phát biểu như sau: cho một bản đồ các thành phố được kết nối với các con đường, hãy tìm tất cả các con đường "quan trọng", tức là những con đường mà khi bị loại bỏ, sẽ khiến một số cặp thành phố không còn đường đi đến nhau.

Thuật toán được mô tả ở đây dựa trên [tìm kiếm theo chiều sâu](depth-first-search.md) và có độ phức tạp $O(N + M)$, trong đó $N$ là số lượng đỉnh và $M$ là số lượng cạnh trong đồ thị.

Lưu ý rằng cũng có bài viết [Tìm cầu trực tuyến](bridge-searching-online.md) - không giống như thuật toán ngoại tuyến (offline) được mô tả ở đây, thuật toán trực tuyến (online) có thể duy trì danh sách tất cả các cầu trong một đồ thị thay đổi (giả sử rằng loại thay đổi duy nhất là bổ sung các cạnh mới).

## Thuật toán

Chọn một đỉnh tùy ý của đồ thị $root$ và chạy [tìm kiếm theo chiều sâu](depth-first-search.md) từ nó. Lưu ý thực tế sau đây (rất dễ chứng minh):

- Giả sử chúng ta đang ở trong DFS, xem xét các cạnh bắt đầu từ đỉnh $v$. Cạnh hiện tại $(v, to)$ là một cầu nếu và chỉ khi không có đỉnh nào trong số $to$ và các con cháu của nó trong cây duyệt DFS có cạnh lùi (back-edge) đến đỉnh $v$ hoặc bất kỳ tổ tiên nào của nó. Thật vậy, điều kiện này có nghĩa là không có cách nào khác từ $v$ đến $to$ ngoại trừ cạnh $(v, to)$.

Bây giờ chúng ta phải học cách kiểm tra thực tế này cho mỗi đỉnh một cách hiệu quả. Chúng ta sẽ sử dụng "thời điểm vào nút" được tính toán bởi tìm kiếm theo chiều sâu.

Vì vậy, cho $\mathtt{tin}[v]$ biểu thị thời điểm vào nút $v$. Chúng ta giới thiệu một mảng $\mathtt{low}$ sẽ cho phép chúng ta lưu trữ nút có thời điểm vào sớm nhất được tìm thấy trong tìm kiếm DFS mà nút $v$ có thể đạt tới bằng một cạnh duy nhất từ ​​chính nó hoặc con cháu của nó. $\mathtt{low}[v]$ là giá trị nhỏ nhất của $\mathtt{tin}[v]$, thời điểm vào $\mathtt{tin}[p]$ cho mỗi nút $p$ được kết nối với nút $v$ thông qua cạnh lùi $(v, p)$ và giá trị của $\mathtt{low}[to]$ cho mỗi đỉnh $to$ là con cháu trực tiếp của $v$ trong cây DFS:

$$\mathtt{low}[v] = \min \left\{ 
    \begin{array}{l}
    \mathtt{tin}[v] \\ 
    \mathtt{tin}[p]  &\text{ cho tất cả }p\text{ mà }(v, p)\text{ là cạnh lùi} \\ 
    \mathtt{low}[to] &\text{ cho tất cả }to\text{ mà }(v, to)\text{ là cạnh cây}
    \end{array}
\right\}$$

Bây giờ, có một cạnh lùi từ đỉnh $v$ hoặc một trong các con cháu của nó đến một trong các tổ tiên của nó nếu và chỉ khi đỉnh $v$ có một con $to$ mà $\mathtt{low}[to] \leq \mathtt{tin}[v]$. Nếu $\mathtt{low}[to] = \mathtt{tin}[v]$, cạnh lùi đi thẳng đến $v$, nếu không thì nó đi đến một trong các tổ tiên của $v$.

Do đó, cạnh hiện tại $(v, to)$ trong cây DFS là một cầu nếu và chỉ khi $\mathtt{low}[to] > \mathtt{tin}[v]$.

## Triển khai

Việc triển khai cần phân biệt ba trường hợp: khi chúng ta đi xuống cạnh trong cây DFS, khi chúng ta tìm thấy một cạnh lùi đến tổ tiên của đỉnh và khi chúng ta quay trở lại cha của đỉnh. Đây là những trường hợp:

- $\mathtt{visited}[to] = false$ - cạnh là một phần của cây DFS;
- $\mathtt{visited}[to] = true$ && $to \neq parent$ - cạnh là cạnh lùi đến một trong các tổ tiên;
- $to = parent$ - cạnh dẫn trở lại cha trong cây DFS.

Để triển khai điều này, chúng ta cần một hàm tìm kiếm theo chiều sâu chấp nhận đỉnh cha của nút hiện tại.

Đối với trường hợp nhiều cạnh, chúng ta cần cẩn thận khi bỏ qua cạnh từ cha. Để giải quyết vấn đề này, chúng ta có thể thêm một cờ `parent_skipped` để đảm bảo rằng chúng ta chỉ bỏ qua cha một lần.

```{.cpp file=bridge_searching_offline}
void IS_BRIDGE(int v,int to); // một số hàm để xử lý cầu được tìm thấy
int n; // số lượng nút
vector<vector<int>> adj; // danh sách kề của đồ thị

vector<bool> visited;
vector<int> tin, low;
int timer;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    bool parent_skipped = false;
    for (int to : adj[v]) {
        if (to == p && !parent_skipped) {
            parent_skipped = true;
            continue;
        }
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

Hàm chính là `find_bridges`; nó thực hiện khởi tạo cần thiết và bắt đầu tìm kiếm theo chiều sâu trong mỗi thành phần được kết nối của đồ thị.

Hàm `IS_BRIDGE(a, b)` là một số hàm sẽ xử lý thực tế là cạnh $(a, b)$ là một cầu, ví dụ: in nó ra.

Lưu ý rằng việc triển khai này sẽ bị lỗi nếu đồ thị có nhiều cạnh, vì nó bỏ qua chúng. Tất nhiên, nhiều cạnh sẽ không bao giờ là một phần của câu trả lời, vì vậy `IS_BRIDGE` có thể kiểm tra thêm rằng cầu được báo cáo không phải là nhiều cạnh. Ngoài ra, có thể truyền cho `dfs` chỉ số của cạnh được sử dụng để vào đỉnh thay vì đỉnh cha (và lưu trữ các chỉ số của tất cả các đỉnh).

## Bài tập thực hành

- [UVA #796 "Critical Links"](http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=737) [độ khó: thấp]
- [UVA #610 "Street Directions"](http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=551) [độ khó: trung bình]
- [Case of the Computer Network (Codeforces Round #310 Div. 1 E)](http://codeforces.com/problemset/problem/555/E) [độ khó: cao]
* [UVA 12363 - Hedge Mazes](https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=3785)
* [UVA 315 - Network](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=251)
* [GYM - Computer Network (J)](http://codeforces.com/gym/100114)
* [SPOJ - King Graffs Defense](http://www.spoj.com/problems/GRAFFDEF/)
* [SPOJ - Critical Edges](http://www.spoj.com/problems/EC_P/)
