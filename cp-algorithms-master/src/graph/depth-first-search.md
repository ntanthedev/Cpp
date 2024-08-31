# Tìm kiếm theo chiều sâu (Depth First Search)

---
tags:
  - Dịch
e_maxx_link: dfs
---

# Tìm kiếm theo chiều sâu (Depth First Search)

Tìm kiếm theo chiều sâu (Depth First Search - DFS) là một trong những thuật toán đồ thị chính.

Tìm kiếm theo chiều sâu tìm đường dẫn theo thứ tự từ điển đầu tiên trong đồ thị từ đỉnh nguồn $u$ đến mỗi đỉnh.
Tìm kiếm theo chiều sâu cũng sẽ tìm thấy các đường dẫn ngắn nhất trong cây (vì chỉ tồn tại một đường dẫn đơn giản), nhưng trên các đồ thị nói chung thì điều này không đúng.

Thuật toán hoạt động trong thời gian $O(m + n)$ trong đó $n$ là số lượng đỉnh và $m$ là số lượng cạnh.

## Mô tả thuật toán

Ý tưởng đằng sau DFS là đi sâu vào đồ thị càng nhiều càng tốt và quay lui sau khi bạn ở một đỉnh mà không có đỉnh liền kề nào chưa được truy cập.

Rất dễ dàng để mô tả / triển khai thuật toán một cách đệ quy:
Chúng ta bắt đầu tìm kiếm tại một đỉnh.
Sau khi truy cập một đỉnh, chúng ta tiếp tục thực hiện DFS cho mỗi đỉnh liền kề mà chúng ta chưa truy cập trước đó.
Bằng cách này, chúng ta truy cập tất cả các đỉnh có thể truy cập được từ đỉnh bắt đầu.

Để biết thêm chi tiết, hãy xem phần triển khai.

## Ứng dụng của Tìm kiếm theo chiều sâu

  * Tìm bất kỳ đường dẫn nào trong đồ thị từ đỉnh nguồn $u$ đến tất cả các đỉnh.
  
  * Tìm đường dẫn đầu tiên theo thứ tự từ điển trong đồ thị từ nguồn $u$ đến tất cả các đỉnh.
  
  * Kiểm tra xem một đỉnh trong cây có phải là tổ tiên của một số đỉnh khác hay không:
  
    Ở đầu và cuối mỗi lệnh gọi tìm kiếm, chúng ta ghi nhớ "thời gian" vào và thoát của mỗi đỉnh.
    Bây giờ bạn có thể tìm thấy câu trả lời cho bất kỳ cặp đỉnh nào $(i, j)$ trong $O(1)$:
    đỉnh $i$ là tổ tiên của đỉnh $j$ nếu và chỉ khi $\text{entry}[i] < \text{entry}[j]$ và $\text{exit}[i] > \text{exit}[j]$.
  
  * Tìm tổ tiên chung thấp nhất (LCA - Lowest Common Ancestor) của hai đỉnh.
  
  * Sắp xếp topo (Topological sorting):
  
    Chạy một loạt tìm kiếm theo chiều sâu để truy cập mỗi đỉnh chính xác một lần trong thời gian $O(n + m)$.
    Thứ tự topo cần thiết sẽ là các đỉnh được sắp xếp theo thứ tự giảm dần của thời gian thoát.
  
  
  * Kiểm tra xem một đồ thị nhất định có phải là phi chu trình hay không và tìm các chu trình trong đồ thị. (Như đã đề cập ở trên bằng cách đếm các cạnh lùi trong mọi thành phần được kết nối).
  
  * Tìm các thành phần được kết nối mạnh (strongly connected components) trong đồ thị có hướng:
  
    Trước tiên, hãy sắp xếp topo đồ thị.
    Sau đó chuyển vị đồ thị và chạy một loạt tìm kiếm theo chiều sâu khác theo thứ tự được xác định bởi sắp xếp topo. Đối với mỗi lệnh gọi DFS, thành phần được tạo bởi nó là một thành phần được kết nối mạnh.
  
  * Tìm cầu (bridge) trong đồ thị vô hướng:
  
    Trước tiên, hãy chuyển đổi đồ thị đã cho thành đồ thị có hướng bằng cách chạy một loạt tìm kiếm theo chiều sâu và làm cho mỗi cạnh được định hướng khi chúng ta đi qua nó, theo hướng chúng ta đã đi. Thứ hai, tìm các thành phần được kết nối mạnh trong đồ thị có hướng này. Cầu là các cạnh có đầu thuộc các thành phần được kết nối mạnh khác nhau.

## Phân loại cạnh của đồ thị

Chúng ta có thể phân loại các cạnh của đồ thị, $G$, bằng cách sử dụng thời điểm vào và thời điểm thoát của các nút cuối $u$ và $v$ của các cạnh $(u,v)$.
Các phân loại này thường được sử dụng cho các bài toán như [tìm cầu](bridge-searching.md) và [tìm điểm khớp nối](cutpoints.md).

Chúng ta thực hiện DFS và phân loại các cạnh gặp phải bằng cách sử dụng các quy tắc sau:

Nếu $v$ chưa được truy cập:

* Cạnh cây (Tree Edge) - Nếu $v$ được truy cập sau $u$ thì cạnh $(u,v)$ được gọi là cạnh cây. Nói cách khác, nếu $v$ được truy cập lần đầu tiên và $u$ hiện đang được truy cập thì $(u,v)$ được gọi là cạnh cây.
Những cạnh này tạo thành cây DFS và do đó có tên là cạnh cây.

Nếu $v$ được truy cập trước $u$:

* Cạnh lùi (Back Edge) - Nếu $v$ là tổ tiên của $u$, thì cạnh $(u,v)$ là một cạnh lùi. $v$ là tổ tiên chính xác nếu chúng ta đã vào $v$, nhưng chưa thoát ra. Các cạnh lùi hoàn thành một chu trình vì có một đường dẫn từ tổ tiên $v$ đến con cháu $u$ (trong đệ quy của DFS) và một cạnh từ con cháu $u$ đến tổ tiên $v$ (cạnh lùi), do đó một chu trình được hình thành. Các chu trình có thể được phát hiện bằng cách sử dụng các cạnh lùi.

* Cạnh tiến (Forward Edge) - Nếu $v$ là con cháu của $u$, thì cạnh $(u, v)$ là cạnh tiến. Nói cách khác, nếu chúng ta đã truy cập và thoát khỏi $v$ và $\text{entry}[u] < \text{entry}[v]$ thì cạnh $(u,v)$ tạo thành cạnh tiến.
* Cạnh chéo (Cross Edge): nếu $v$ không phải là tổ tiên hay con cháu của $u$, thì cạnh $(u, v)$ là cạnh chéo. Nói cách khác, nếu chúng ta đã truy cập và thoát khỏi $v$ và $\text{entry}[u] > \text{entry}[v]$ thì $(u,v)$ là cạnh chéo.

**Định lý**. Cho $G$ là một đồ thị vô hướng. Sau đó, việc thực hiện DFS trên $G$ sẽ phân loại mọi cạnh gặp phải là cạnh cây hoặc cạnh lùi, tức là cạnh tiến và cạnh chéo chỉ tồn tại trong đồ thị có hướng.

Giả sử $(u,v)$ là một cạnh tùy ý của $G$ và không mất tính tổng quát, $u$ được truy cập trước $v$, tức là $\text{entry}[u] < \text{entry}[v]$. Vì DFS chỉ xử lý các cạnh một lần, nên chỉ có hai cách để chúng ta xử lý cạnh $(u,v)$ và do đó phân loại nó:

* Lần đầu tiên chúng ta khám phá cạnh $(u,v)$ là theo hướng từ $u$ đến $v$. Vì $\text{entry}[u] < \text{entry}[v]$, tính chất đệ quy của DFS có nghĩa là nút $v$ sẽ được khám phá đầy đủ và do đó thoát ra trước khi chúng ta có thể "di chuyển ngược lên ngăn xếp cuộc gọi" để thoát khỏi nút $u$. Do đó, nút $v$ phải chưa được truy cập khi DFS lần đầu tiên khám phá cạnh $(u,v)$ từ $u$ đến $v$ vì nếu không thì tìm kiếm sẽ đã khám phá $(u,v)$ từ $v$ đến $u$ trước khi thoát khỏi nút $v$, vì các nút $u$ và $v$ là láng giềng. Do đó, cạnh $(u,v)$ là một cạnh cây.

* Lần đầu tiên chúng ta khám phá cạnh $(u,v)$ là theo hướng từ $v$ đến $u$. Vì chúng ta đã khám phá nút $u$ trước khi khám phá nút $v$ và chúng ta chỉ xử lý các cạnh một lần, nên cách duy nhất để chúng ta có thể khám phá cạnh $(u,v)$ theo hướng từ $v$ đến $u$ là nếu có một đường dẫn khác từ $u$ đến $v$ không liên quan đến cạnh $(u,v)$, do đó làm cho $u$ trở thành tổ tiên của $v$. Cạnh $(u,v)$ do đó hoàn thành một chu trình vì nó đi từ con cháu, $v$, đến tổ tiên, $u$, mà chúng ta chưa thoát ra. Do đó, cạnh $(u,v)$ là một cạnh lùi.

Vì chỉ có hai cách để xử lý cạnh $(u,v)$, với hai trường hợp và phân loại kết quả của chúng được nêu ở trên, việc thực hiện DFS trên $G$ do đó sẽ phân loại mọi cạnh gặp phải là cạnh cây hoặc cạnh lùi, tức là cạnh tiến và cạnh chéo chỉ tồn tại trong đồ thị có hướng. Điều này hoàn thành bằng chứng.

## Triển khai

```cpp
vector<vector<int>> adj; // đồ thị được biểu diễn dưới dạng danh sách kề
int n; // số lượng đỉnh

vector<bool> visited;

void dfs(int v) {
	visited[v] = true;
	for (int u : adj[v]) {
		if (!visited[u])
			dfs(u);
    }
}
```
Đây là cách triển khai đơn giản nhất của Tìm kiếm theo chiều sâu.
Như được mô tả trong các ứng dụng, cũng có thể hữu ích khi tính toán thời điểm vào và thời điểm thoát và màu đỉnh.
Chúng tôi sẽ tô màu tất cả các đỉnh bằng màu 0, nếu chúng ta chưa truy cập chúng, bằng màu 1 nếu chúng ta đã truy cập chúng và bằng màu 2, nếu chúng ta đã thoát khỏi đỉnh.

Dưới đây là một triển khai chung bổ sung tính toán những điều đó:

```cpp
vector<vector<int>> adj; // đồ thị được biểu diễn dưới dạng danh sách kề
int n; // số lượng đỉnh

vector<int> color;

vector<int> time_in, time_out;
int dfs_timer = 0;

void dfs(int v) {
	time_in[v] = dfs_timer++;
	color[v] = 1;
	for (int u : adj[v])
		if (color[u] == 0)
			dfs(u);
	color[v] = 2;
	time_out[v] = dfs_timer++;
}
```

## Bài tập thực hành

* [SPOJ: ABCPATH](http://www.spoj.com/problems/ABCPATH/)
* [SPOJ: EAGLE1](http://www.spoj.com/problems/EAGLE1/)
* [Codeforces: Kefa and Park](http://codeforces.com/problemset/problem/580/C)
* [Timus:Werewolf](http://acm.timus.ru/problem.aspx?space=1&num=1242)
* [Timus:Penguin Avia](http://acm.timus.ru/problem.aspx?space=1&num=1709)
* [Timus:Two Teams](http://acm.timus.ru/problem.aspx?space=1&num=1106)
* [SPOJ - Ada and Island](http://www.spoj.com/problems/ADASEA/)
* [UVA 657 - The die is cast](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=598)
* [SPOJ - Sheep](http://www.spoj.com/problems/KOZE/)
* [SPOJ - Path of the Rightenous Man](http://www.spoj.com/problems/RIOI_2_3/)
* [SPOJ - Validate the Maze](http://www.spoj.com/problems/MAKEMAZE/)
* [SPOJ - Ghosts having Fun](http://www.spoj.com/problems/GHOSTS/)
* [Codeforces - Underground Lab](http://codeforces.com/contest/781/problem/C)
* [DevSkill - Maze Tester (lưu trữ)](http://web.archive.org/web/20200319103915/https://www.devskill.com/CodingProblems/ViewProblem/3)
* [DevSkill - Tourist (lưu trữ)](http://web.archive.org/web/20190426175135/https://devskill.com/CodingProblems/ViewProblem/17)
* [Codeforces - Anton and Tree](http://codeforces.com/contest/734/problem/E)
* [Codeforces - Transformation: From A to B](http://codeforces.com/contest/727/problem/A)
* [Codeforces - One Way Reform](http://codeforces.com/contest/723/problem/E)
* [Codeforces - Centroids](http://codeforces.com/contest/709/problem/E)
* [Codeforces - Generate a String](http://codeforces.com/contest/710/problem/E)
* [Codeforces - Broken Tree](http://codeforces.com/contest/758/problem/E)
* [Codeforces - Dasha and Puzzle](http://codeforces.com/contest/761/problem/E)
* [Codeforces - Making genome In Berland](http://codeforces.com/contest/638/problem/B)
* [Codeforces - Road Improvement](http://codeforces.com/contest/638/problem/C)
* [Codeforces - Garland](http://codeforces.com/contest/767/problem/C)
* [Codeforces - Labeling Cities](http://codeforces.com/contest/794/problem/D)
* [Codeforces - Send the Fool Futher!](http://codeforces.com/contest/802/problem/K)
* [Codeforces - The tag Game](http://codeforces.com/contest/813/problem/C)
* [Codeforces - Leha and Another game about graphs](http://codeforces.com/contest/841/problem/D)
* [Codeforces - Shortest path problem](http://codeforces.com/contest/845/problem/G)
* [Codeforces - Upgrading Tree](http://codeforces.com/contest/844/problem/E)
* [Codeforces - From Y to Y](http://codeforces.com/contest/849/problem/C)
* [Codeforces - Chemistry in Berland](http://codeforces.com/contest/846/problem/E)
* [Codeforces - Wizards Tour](http://codeforces.com/contest/861/problem/F)
* [Codeforces - Ring Road](http://codeforces.com/contest/24/problem/A)
* [Codeforces - Mail Stamps](http://codeforces.com/contest/29/problem/C)
* [Codeforces - Ant on the Tree](http://codeforces.com/contest/29/problem/D)
* [SPOJ - Cactus](http://www.spoj.com/problems/CAC/)
* [SPOJ - Mixing Chemicals](http://www.spoj.com/problems/AMR10J/)

--- 




