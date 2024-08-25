---
tags:
  - Translated
e_maxx_link: dfs
---

# Tìm kiếm theo chiều sâu (Depth First Search)

Tìm kiếm theo chiều sâu (DFS) là một trong những thuật toán đồ thị chính.

DFS tìm đường đi đầu tiên theo thứ tự từ điển trong đồ thị từ một đỉnh nguồn $u$ đến mỗi đỉnh.
DFS cũng sẽ tìm đường đi ngắn nhất trong một cây (vì chỉ tồn tại một đường đi đơn giản), nhưng trên các đồ thị tổng quát thì điều này không đúng.

Thuật toán hoạt động trong thời gian $O(m + n)$ trong đó $n$ là số đỉnh và $m$ là số cạnh.

## Mô tả thuật toán

Ý tưởng đằng sau DFS là đi sâu vào đồ thị càng nhiều càng tốt và quay lui khi bạn ở một đỉnh mà không có bất kỳ đỉnh kề chưa được truy cập nào.

Rất dễ dàng để mô tả / triển khai thuật toán một cách đệ quy:
Chúng ta bắt đầu tìm kiếm tại một đỉnh.
Sau khi truy cập một đỉnh, chúng ta tiếp tục thực hiện DFS cho mỗi đỉnh kề mà chúng ta chưa truy cập trước đó.
Bằng cách này, chúng ta truy cập tất cả các đỉnh có thể truy cập được từ đỉnh bắt đầu.

Để biết thêm chi tiết, hãy xem phần triển khai.

## Ứng dụng của Tìm kiếm theo chiều sâu

  * Tìm bất kỳ đường đi nào trong đồ thị từ đỉnh nguồn $u$ đến tất cả các đỉnh.
  
  * Tìm đường đi đầu tiên theo thứ tự từ điển trong đồ thị từ nguồn $u$ đến tất cả các đỉnh.
  
  * Kiểm tra xem một đỉnh trong cây có phải là tổ tiên của một đỉnh khác hay không:
  
    Ở đầu và cuối mỗi lệnh gọi tìm kiếm, chúng ta ghi nhớ "thời gian" vào và ra của mỗi đỉnh.
    Bây giờ bạn có thể tìm thấy câu trả lời cho bất kỳ cặp đỉnh $(i, j)$ nào trong $O(1)$:
    đỉnh $i$ là tổ tiên của đỉnh $j$ nếu và chỉ khi $\text{entry}[i] < \text{entry}[j]$ và $\text{exit}[i] > \text{exit}[j]$.
  
  * Tìm tổ tiên chung thấp nhất (LCA) của hai đỉnh.
  
  * Sắp xếp topo:
  
    Chạy một loạt tìm kiếm theo chiều sâu để truy cập mỗi đỉnh chính xác một lần trong thời gian $O(n + m)$.
    Thứ tự topo cần thiết sẽ là các đỉnh được sắp xếp theo thứ tự giảm dần của thời gian thoát.
  
  
  * Kiểm tra xem một đồ thị nhất định có phải là không chu trình hay không và tìm chu trình trong đồ thị. (Như đã đề cập ở trên bằng cách đếm các cạnh lùi trong mọi thành phần liên thông).
  
  * Tìm các thành phần liên thông mạnh trong một đồ thị có hướng:
  
    Đầu tiên thực hiện sắp xếp topo của đồ thị.
    Sau đó chuyển vị đồ thị và chạy một loạt tìm kiếm theo chiều sâu khác theo thứ tự được xác định bởi sắp xếp topo. Đối với mỗi lệnh gọi DFS, thành phần được tạo bởi nó là một thành phần liên thông mạnh.
  
  * Tìm cầu nối trong một đồ thị vô hướng:
  
    Trước tiên, hãy chuyển đổi đồ thị đã cho thành một đồ thị có hướng bằng cách chạy một loạt tìm kiếm theo chiều sâu và làm cho mỗi cạnh được hướng khi chúng ta đi qua nó, theo hướng mà chúng ta đã đi. Thứ hai, tìm các thành phần liên thông mạnh trong đồ thị có hướng này. Cầu nối là các cạnh mà các đầu thuộc về các thành phần liên thông mạnh khác nhau.

## Phân loại các cạnh của đồ thị

Chúng ta có thể phân loại các cạnh bằng cách sử dụng thời gian vào và ra của các nút cuối $u$ và $v$ của các cạnh $(u,v)$.
Các phân loại này thường được sử dụng cho các bài toán như [tìm cầu nối](bridge-searching.md) và [tìm điểm khớp nối](cutpoints.md).

Chúng ta thực hiện DFS và phân loại các cạnh gặp phải bằng cách sử dụng các quy tắc sau:

Nếu $v$ chưa được truy cập:

* Cạnh cây - Nếu $v$ được truy cập sau $u$ thì cạnh $(u,v)$ được gọi là cạnh cây. Nói cách khác, nếu $v$ được truy cập lần đầu tiên và $u$ hiện đang được truy cập thì $(u,v)$ được gọi là cạnh cây.
Các cạnh này tạo thành một cây DFS và do đó có tên là cạnh cây.

Nếu $v$ được truy cập trước $u$:

* Cạnh lùi - Nếu $v$ là tổ tiên của $u$, thì cạnh $(u,v)$ là cạnh lùi. $v$ là tổ tiên chính xác nếu chúng ta đã vào $v$, nhưng chưa thoát ra. Các cạnh lùi hoàn thành một chu trình vì có một đường dẫn từ tổ tiên $v$ đến con cháu $u$ (trong đệ quy của DFS) và một cạnh từ con cháu $u$ đến tổ tiên $v$ (cạnh lùi), do đó một chu trình được hình thành. Chu trình có thể được phát hiện bằng cách sử dụng các cạnh lùi.

* Cạnh tiến - Nếu $v$ là con cháu của $u$, thì cạnh $(u, v)$ là cạnh tiến. Nói cách khác, nếu chúng ta đã truy cập và thoát $v$ và $\text{entry}[u] < \text{entry}[v]$ thì cạnh $(u,v)$ tạo thành cạnh tiến.
* Cạnh chéo: nếu $v$ không phải là tổ tiên hay con cháu của $u$, thì cạnh $(u, v)$ là cạnh chéo. Nói cách khác, nếu chúng ta đã truy cập và thoát $v$ và $\text{entry}[u] > \text{entry}[v]$ thì $(u,v)$ là cạnh chéo.

Lưu ý: Cạnh tiến và cạnh chéo chỉ tồn tại trong đồ thị có hướng.

## Triển khai

```cpp
vector<vector<int>> adj; // đồ thị được biểu diễn dưới dạng danh sách kề
int n; // số đỉnh

vector<bool> visited;

void dfs(int v) {
	visited[v] = true;
	for (int u : adj[v]) {
		if (!visited[u])
			dfs(u);
    }
}
```
Đây là triển khai đơn giản nhất của Tìm kiếm theo chiều sâu.
Như được mô tả trong các ứng dụng, cũng có thể hữu ích khi tính toán thời gian vào và ra và màu đỉnh.
Chúng ta sẽ tô màu tất cả các đỉnh với màu 0 nếu chúng ta chưa truy cập chúng, với màu 1 nếu chúng ta đã truy cập chúng và với màu 2 nếu chúng ta đã thoát khỏi đỉnh.

Đây là một triển khai chung bổ sung tính toán những điều đó:

```cpp
vector<vector<int>> adj; // đồ thị được biểu diễn dưới dạng danh sách kề
int n; // số đỉnh

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
* [DevSkill - Maze Tester (archived)](http://web.archive.org/web/20200319103915/https://www.devskill.com/CodingProblems/ViewProblem/3)
* [DevSkill - Tourist (archived)](http://web.archive.org/web/20190426175135/https://devskill.com/CodingProblems/ViewProblem/17)
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


