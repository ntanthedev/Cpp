---
tags:
  - Translated
e_maxx_link: strong_connected_components
---

# Tìm thành phần liên thông mạnh / Xây dựng đồ thị thu gọn

## Định nghĩa
Bạn được cho một đồ thị có hướng $G$ với các đỉnh $V$ và các cạnh $E$. Có thể có các vòng lặp và nhiều cạnh. Hãy ký hiệu $n$ là số lượng đỉnh và $m$ là số lượng cạnh trong $G$.

**Thành phần liên thông mạnh** là một tập hợp con tối đa các đỉnh $C$ sao cho bất kỳ hai đỉnh nào của tập hợp con này đều có thể đến được với nhau, tức là đối với bất kỳ $u, v \in C$:

$$u \mapsto v, v \mapsto u$$

trong đó $\mapsto$ có nghĩa là khả năng tiếp cận, tức là sự tồn tại của đường đi từ đỉnh đầu tiên đến đỉnh thứ hai.

Rõ ràng, các thành phần liên thông mạnh không giao nhau, tức là đây là một phân hoạch của tất cả các đỉnh đồ thị. Do đó, chúng ta có thể đưa ra định nghĩa về đồ thị thu gọn $G^{SCC}$ là một đồ thị chứa mọi thành phần liên thông mạnh như một đỉnh. Mỗi đỉnh của đồ thị thu gọn tương ứng với thành phần liên thông mạnh của đồ thị $G$. Có một cạnh có hướng giữa hai đỉnh $C_i$ và $C_j$ của đồ thị thu gọn nếu và chỉ khi có hai đỉnh $u \in C_i, v \in C_j$ sao cho có một cạnh trong đồ thị ban đầu, tức là $(u, v) \in E$.

Thuộc tính quan trọng nhất của đồ thị thu gọn là nó là **không chu trình**. Thật vậy, giả sử rằng có một cạnh giữa $C$ và $C'$, hãy chứng minh rằng không có cạnh từ $C'$ đến $C$. Giả sử rằng $C' \mapsto C$. Khi đó có hai đỉnh $u' \in C$ và $v' \in C'$ sao cho $v' \mapsto u'$. Nhưng vì $u$ và $u'$ nằm trong cùng một thành phần liên thông mạnh nên có một đường đi giữa chúng; tương tự cho $v$ và $v'$. Kết quả là, nếu chúng ta nối các đường dẫn này, chúng ta có $v \mapsto u$ và đồng thời $u \mapsto v$. Do đó, $u$ và $v$ phải nằm trong cùng một thành phần liên thông mạnh, vì vậy đây là mâu thuẫn. Điều này hoàn thành bằng chứng.

Thuật toán được mô tả trong phần tiếp theo sẽ trích xuất tất cả các thành phần liên thông mạnh trong một đồ thị nhất định. Sau đó, việc xây dựng một đồ thị thu gọn khá dễ dàng.

## Mô tả thuật toán
Thuật toán được mô tả đã được Kosaraju và Sharir đề xuất độc lập vào năm 1979. Đây là một thuật toán dễ triển khai dựa trên hai chuỗi [tìm kiếm theo chiều sâu](depth-first-search.md) và hoạt động trong thời gian $O(n + m)$.

**Trong bước đầu tiên** của thuật toán, chúng ta đang thực hiện chuỗi tìm kiếm theo chiều sâu, truy cập toàn bộ đồ thị. Chúng ta bắt đầu tại mỗi đỉnh của đồ thị và chạy tìm kiếm theo chiều sâu từ mọi đỉnh chưa được truy cập. Đối với mỗi đỉnh, chúng ta đang theo dõi **thời gian thoát** $tout[v]$. Những thời gian thoát này có vai trò quan trọng trong một thuật toán và vai trò này được thể hiện trong định lý tiếp theo.

Đầu tiên, hãy đặt ký hiệu: hãy định nghĩa thời gian thoát $tout[C]$ từ thành phần liên thông mạnh $C$ là giá trị lớn nhất của $tout[v]$ bởi tất cả $v \in C$. Bên cạnh đó, trong quá trình chứng minh định lý, chúng ta sẽ đề cập đến thời gian vào $tin[v]$ trong mỗi đỉnh và theo cách tương tự, hãy xem xét $tin[C]$ cho mỗi thành phần liên thông mạnh $C$ là giá trị nhỏ nhất của $tin[v]$ bởi tất cả $v \in C$.

**Định lý**. Cho $C$ và $C'$ là hai thành phần liên thông mạnh khác nhau và có một cạnh $(C, C')$ trong đồ thị thu gọn giữa hai đỉnh này. Khi đó $tout[C] > tout[C']$.

Có hai trường hợp chính khác nhau trong bằng chứng tùy thuộc vào thành phần nào sẽ được tìm kiếm theo chiều sâu truy cập trước, tức là tùy thuộc vào sự khác biệt giữa $tin[C]$ và $tin[C']$:

- Thành phần $C$ được tiếp cận trước. Điều đó có nghĩa là tìm kiếm theo chiều sâu đến một đỉnh $v$ của thành phần $C$ tại một thời điểm nào đó, nhưng tất cả các đỉnh khác của thành phần $C$ và $C'$ chưa được truy cập. Theo điều kiện, có một cạnh $(C, C')$ trong đồ thị thu gọn, vì vậy không chỉ toàn bộ thành phần $C$ có thể tiếp cận được từ $v$ mà toàn bộ thành phần $C'$ cũng có thể tiếp cận được. Điều đó có nghĩa là tìm kiếm theo chiều sâu đang chạy từ đỉnh $v$ sẽ truy cập tất cả các đỉnh của thành phần $C$ và $C'$, vì vậy chúng sẽ là con cháu của $v$ trong cây tìm kiếm theo chiều sâu, tức là đối với mỗi đỉnh $u \in C \cup C', u \ne v$ chúng ta có $tout[v] > tout[u]$, như chúng ta đã tuyên bố.

- Giả sử rằng thành phần $C'$ được truy cập trước. Tương tự, tìm kiếm theo chiều sâu đến một đỉnh $v$ của thành phần $C'$ tại một thời điểm nào đó, nhưng tất cả các đỉnh khác của thành phần $C$ và $C'$ chưa được truy cập. Nhưng theo điều kiện, có một cạnh $(C, C')$ trong đồ thị thu gọn, vì vậy, do tính chất không chu trình của đồ thị thu gọn, không có đường dẫn ngược từ $C'$ đến $C$, tức là tìm kiếm theo chiều sâu từ đỉnh $v$ sẽ không đến được các đỉnh của $C$. Điều đó có nghĩa là các đỉnh của $C$ sẽ được tìm kiếm theo chiều sâu truy cập sau, vì vậy $tout[C] > tout[C']$. Điều này hoàn thành bằng chứng.

Định lý đã được chứng minh là **cơ sở của thuật toán** để tìm các thành phần liên thông mạnh. Theo đó, bất kỳ cạnh $(C, C')$ nào trong đồ thị thu gọn đều xuất phát từ một thành phần có giá trị $tout$ lớn hơn đến thành phần có giá trị nhỏ hơn.

Nếu chúng ta sắp xếp tất cả các đỉnh $v \in V$ theo thứ tự giảm dần của thời gian thoát $tout[v]$ thì đỉnh đầu tiên $u$ sẽ là đỉnh thuộc thành phần liên thông mạnh "gốc", tức là đỉnh không có cạnh đi vào trong đồ thị thu gọn. Bây giờ chúng ta muốn chạy tìm kiếm như vậy từ đỉnh $u$ này sao cho nó sẽ truy cập tất cả các đỉnh trong thành phần liên thông mạnh này, nhưng không phải các đỉnh khác; làm như vậy, chúng ta có thể dần dần chọn tất cả các thành phần liên thông mạnh: hãy xóa tất cả các đỉnh tương ứng với thành phần được chọn đầu tiên, và sau đó hãy tìm đỉnh có giá trị lớn nhất của $tout$, và chạy tìm kiếm này từ nó, v.v.

Hãy xem xét đồ thị chuyển vị $G^T$, tức là đồ thị nhận được từ $G$ bằng cách đảo ngược hướng của mỗi cạnh.
Rõ ràng, đồ thị này sẽ có các thành phần liên thông mạnh giống như đồ thị ban đầu.
Hơn nữa, đồ thị thu gọn $G^{SCC}$ cũng sẽ được chuyển vị.
Điều đó có nghĩa là sẽ không có cạnh nào từ thành phần "gốc" của chúng ta đến các thành phần khác.

Do đó, để truy cập toàn bộ thành phần liên thông mạnh "gốc" chứa đỉnh $v$, đủ để chạy tìm kiếm từ đỉnh $v$ trong đồ thị $G^T$. Tìm kiếm này sẽ truy cập tất cả các đỉnh của thành phần liên thông mạnh này và chỉ chúng. Như đã đề cập trước đó, chúng ta có thể xóa các đỉnh này khỏi đồ thị sau đó, và tìm đỉnh tiếp theo có giá trị lớn nhất của $tout[v]$ và chạy tìm kiếm trong đồ thị chuyển vị từ nó, v.v.

Vì vậy, chúng ta đã xây dựng **thuật toán** tiếp theo để chọn các thành phần liên thông mạnh:

Bước 1. Chạy chuỗi tìm kiếm theo chiều sâu của đồ thị $G$ sẽ trả về các đỉnh với thời gian thoát $tout$ tăng dần, tức là một số danh sách $order$.

Bước 2. Xây dựng đồ thị chuyển vị $G^T$. Chạy một loạt tìm kiếm theo chiều sâu (hoặc chiều rộng) theo thứ tự được xác định bởi danh sách $order$ (chính xác là theo thứ tự ngược lại, tức là theo thứ tự giảm dần của thời gian thoát). Mỗi tập hợp các đỉnh, đạt được sau khi tìm kiếm tiếp theo, sẽ là thành phần liên thông mạnh tiếp theo.

Độ phức tạp tiệm cận của thuật toán là $O(n + m)$, bởi vì nó chỉ là hai lần tìm kiếm theo chiều sâu (hoặc chiều rộng).

Cuối cùng, cần phải đề cập đến [sắp xếp topo](topological-sort.md) ở đây. Trước hết, bước 1 của thuật toán biểu diễn sắp xếp topo ngược của đồ thị $G$ (thực tế đây chính xác là ý nghĩa của việc sắp xếp các đỉnh theo thời gian thoát). Thứ hai, sơ đồ của thuật toán tạo ra các thành phần liên thông mạnh theo thứ tự giảm dần của thời gian thoát của chúng, do đó nó tạo ra các thành phần - các đỉnh của đồ thị thu gọn - theo thứ tự sắp xếp topo.

## Triển khai
```cpp
vector<vector<int>> adj, adj_rev;
vector<bool> used;
vector<int> order, component;
 
void dfs1(int v) {
    used[v] = true;

    for (auto u : adj[v])
        if (!used[u])
            dfs1(u);

    order.push_back(v);
}
 
void dfs2(int v) {
    used[v] = true;
    component.push_back(v);

    for (auto u : adj_rev[v])
        if (!used[u])
            dfs2(u);
}
 
int main() {
    int n;
    // ... đọc n ...

    for (;;) {
        int a, b;
        // ... đọc cạnh có hướng tiếp theo (a,b) ...
        adj[a].push_back(b);
        adj_rev[b].push_back(a);
    }
 
    used.assign(n, false);

    for (int i = 0; i < n; i++)
        if (!used[i])
            dfs1(i);

    used.assign(n, false);
    reverse(order.begin(), order.end());

    for (auto v : order)
        if (!used[v]) {
            dfs2 (v);

            // ... xử lý thành phần tiếp theo ...

            component.clear();
        }
}
```

Ở đây, $g$ là đồ thị, $gr$ là đồ thị chuyển vị. Hàm $dfs1$ triển khai tìm kiếm theo chiều sâu trên đồ thị $G$, hàm $dfs2$ - trên đồ thị chuyển vị $G^T$. Hàm $dfs1$ điền vào danh sách $order$ với các đỉnh theo thứ tự tăng dần của thời gian thoát của chúng (trên thực tế, nó đang thực hiện sắp xếp topo). Hàm $dfs2$ lưu trữ tất cả các đỉnh đã đạt được trong danh sách $component$, danh sách này sẽ lưu trữ thành phần liên thông mạnh tiếp theo sau mỗi lần chạy.

### Triển khai Đồ thị Thu gọn

```cpp
// tiếp tục từ mã trước

vector<int> roots(n, 0);
vector<int> root_nodes;
vector<vector<int>> adj_scc(n);

for (auto v : order)
    if (!used[v]) {
        dfs2(v);

        int root = component.front();
        for (auto u : component) roots[u] = root;
        root_nodes.push_back(root);

        component.clear();
    }


for (int v = 0; v < n; v++)
    for (auto u : adj[v]) {
        int root_v = roots[v],
            root_u = roots[u];

        if (root_u != root_v)
            adj_scc[root_v].push_back(root_u);
    }
```

Ở đây, chúng ta đã chọn nút gốc của mỗi thành phần là nút đầu tiên trong danh sách của nó. Nút này sẽ đại diện cho toàn bộ SCC của nó trong đồ thị thu gọn. `roots[v]` cho biết nút gốc cho SCC mà nút `v` thuộc về. `root_nodes` là danh sách tất cả các nút gốc (một nút cho mỗi thành phần) trong đồ thị thu gọn.

`adj_scc` là danh sách kề của `root_nodes`. Bây giờ chúng ta có thể duyệt trên `adj_scc` như đồ thị thu gọn của chúng ta, chỉ sử dụng những nút thuộc về `root_nodes`.

## Tài liệu tham khảo

* Thomas Cormen, Charles Leiserson, Ronald Rivest, Clifford Stein. Giới thiệu về Thuật toán [2005].
* M. Sharir. Một thuật toán liên thông mạnh và ứng dụng của nó trong phân tích luồng dữ liệu [1979].

## Bài tập thực hành

* [SPOJ - Good Travels](http://www.spoj.com/problems/GOODA/)
* [SPOJ - Lego](http://www.spoj.com/problems/LEGO/)
* [Codechef - Chef and Round Run](https://www.codechef.com/AUG16/problems/CHEFRRUN)
* [Dev Skills - A Song of Fire and Ice](https://devskill.com/CodingProblems/ViewProblem/79)
* [UVA - 11838 - Come and Go](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2938)
* [UVA 247 - Calling Circles](https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=183)
* [UVA 13057 - Prove Them All](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4955)
* [UVA 12645 - Water Supply](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4393)
* [UVA 11770 - Lighting Away](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2870)
* [UVA 12926 - Trouble in Terrorist Town](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=862&page=show_problem&problem=4805)
* [UVA 11324 - The Largest Clique](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2299)
* [UVA 11709 - Trust groups](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2756)
* [UVA 12745 - Wishmaster](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4598)
* [SPOJ - True Friends](http://www.spoj.com/problems/TFRIENDS/)
* [SPOJ - Capital City](http://www.spoj.com/problems/CAPCITY/)
* [Codeforces - Scheme](http://codeforces.com/contest/22/problem/E)
* [SPOJ - Ada and Panels](http://www.spoj.com/problems/ADAPANEL/)
* [CSES - Flight Routes Check](https://cses.fi/problemset/task/1682)
* [CSES - Planets and Kingdoms](https://cses.fi/problemset/task/1683)
* [CSES -Coin Collector](https://cses.fi/problemset/task/1686)
* [Codeforces - Checkposts](https://codeforces.com/problemset/problem/427/C)
