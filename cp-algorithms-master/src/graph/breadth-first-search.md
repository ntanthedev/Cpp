# Tìm kiếm theo chiều rộng (Breadth-first search)

---
tags:
  - Dịch
e_maxx_link: bfs
---

# Tìm kiếm theo chiều rộng (Breadth-first search)

Tìm kiếm theo chiều rộng (Breadth First Search - BFS) là một trong những thuật toán tìm kiếm cơ bản và thiết yếu trên đồ thị.

Do cách thuật toán hoạt động, đường dẫn được tìm thấy bằng tìm kiếm theo chiều rộng đến bất kỳ nút nào là đường dẫn ngắn nhất đến nút đó, tức là đường dẫn chứa số lượng cạnh nhỏ nhất trong đồ thị không trọng số (unweighted graph).

Thuật toán hoạt động trong thời gian $O(n + m)$, trong đó $n$ là số lượng đỉnh và $m$ là số lượng cạnh.

## Mô tả thuật toán

Thuật toán nhận đầu vào là một đồ thị không trọng số và id của đỉnh nguồn $s$. Đồ thị đầu vào có thể là có hướng (directed) hoặc vô hướng (undirected),
điều đó không quan trọng đối với thuật toán.

Thuật toán có thể được hiểu như một ngọn lửa lan truyền trên đồ thị: ở bước thứ 0, chỉ có nguồn $s$ bốc cháy. Ở mỗi bước, ngọn lửa cháy ở mỗi đỉnh sẽ lan sang tất cả các lân cận của nó. Trong một lần lặp của thuật toán, "vòng lửa"
được mở rộng theo chiều rộng thêm một đơn vị (do đó có tên của thuật toán).

Chính xác hơn, thuật toán có thể được phát biểu như sau: Tạo một hàng đợi (queue) $q$ sẽ chứa các đỉnh sẽ được xử lý và một
mảng Boolean $used[]$ cho biết đối với mỗi đỉnh, liệu nó đã được thắp sáng (hoặc đã truy cập) hay chưa.

Ban đầu, đẩy nguồn $s$ vào hàng đợi và đặt $used[s] = true$, và đối với tất cả các đỉnh $v$ khác, đặt $used[v] = false$.
Sau đó, lặp cho đến khi hàng đợi trống và trong mỗi lần lặp, hãy lấy ra một đỉnh từ đầu hàng đợi. Lặp qua tất cả các cạnh đi ra
khỏi đỉnh này và nếu một số cạnh trong số này đi đến các đỉnh chưa được thắp sáng, hãy đốt cháy chúng và đặt chúng vào hàng đợi.

Kết quả là, khi hàng đợi trống, "vòng lửa" chứa tất cả các đỉnh có thể truy cập được từ nguồn $s$, với mỗi đỉnh được truy cập theo cách ngắn nhất có thể.
Bạn cũng có thể tính toán độ dài của các đường dẫn ngắn nhất (chỉ yêu cầu duy trì một mảng độ dài đường dẫn $d[]$) cũng như lưu thông tin để khôi phục tất cả các đường dẫn ngắn nhất này (đối với điều này, cần phải duy trì một mảng "cha mẹ" $p[]$, lưu trữ cho mỗi đỉnh đỉnh mà từ đó chúng ta đã đến được nó).

## Triển khai

Chúng tôi viết mã cho thuật toán được mô tả bằng C++ và Java.

=== "C++"
    ```cpp
    vector<vector<int>> adj;  // biểu diễn danh sách kề
    int n; // số lượng nút
    int s; // đỉnh nguồn

    queue<int> q;
    vector<bool> used(n);
    vector<int> d(n), p(n);

    q.push(s);
    used[s] = true;
    p[s] = -1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : adj[v]) {
            if (!used[u]) {
                used[u] = true;
                q.push(u);
                d[u] = d[v] + 1;
                p[u] = v;
            }
        }
    }
    ```
=== "Java"
    ```java
    ArrayList<ArrayList<Integer>> adj = new ArrayList<>(); // biểu diễn danh sách kề
        
    int n; // số lượng nút
    int s; // đỉnh nguồn


    LinkedList<Integer> q = new LinkedList<Integer>();
    boolean used[] = new boolean[n];
    int d[] = new int[n];
    int p[] = new int[n];

    q.push(s);
    used[s] = true;
    p[s] = -1;
    while (!q.isEmpty()) {
        int v = q.pop();
        for (int u : adj.get(v)) {
            if (!used[u]) {
                used[u] = true;
                q.push(u);
                d[u] = d[v] + 1;
                p[u] = v;
            }
        }
    }
    ```

Nếu chúng ta phải khôi phục và hiển thị đường đi ngắn nhất từ ​​nguồn đến một số đỉnh $u$, nó có thể được thực hiện theo cách sau:

=== "C++"
    ```cpp
    if (!used[u]) {
        cout << "Không có đường đi!";
    } else {
        vector<int> path;
        for (int v = u; v != -1; v = p[v])
            path.push_back(v);
        reverse(path.begin(), path.end());
        cout << "Đường dẫn: ";
        for (int v : path)
            cout << v << " ";
    }
    ```
=== "Java"
    ```java
    if (!used[u]) {
        System.out.println("No path!");
    } else {
        ArrayList<Integer> path = new ArrayList<Integer>();
        for (int v = u; v != -1; v = p[v])
            path.add(v);
        Collections.reverse(path);
        for(int v : path)
            System.out.println(v);
    }
    ```

## Ứng dụng của BFS

* Tìm đường đi ngắn nhất từ ​​nguồn đến các đỉnh khác trong đồ thị không trọng số.

* Tìm tất cả các thành phần liên thông (connected components) trong đồ thị vô hướng trong thời gian $O(n + m)$:
Để làm điều này, chúng ta chỉ cần chạy BFS bắt đầu từ mỗi đỉnh, ngoại trừ các đỉnh đã được truy cập từ các lần chạy trước đó.
Do đó, chúng ta thực hiện BFS bình thường từ mỗi đỉnh, nhưng không đặt lại mảng $used[]$ mỗi khi chúng ta nhận được một thành phần được kết nối mới và tổng thời gian chạy vẫn sẽ là $O(n + m)$ (thực hiện nhiều BFS trên đồ thị mà không đặt lại mảng $used []$ được gọi là một loạt các tìm kiếm theo chiều rộng).

* Tìm giải pháp cho một bài toán hoặc trò chơi với số lần di chuyển ít nhất, nếu mỗi trạng thái của trò chơi có thể được biểu diễn bằng một đỉnh của đồ thị và các phép chuyển đổi từ trạng thái này sang trạng thái khác là các cạnh của đồ thị.

* Tìm đường đi ngắn nhất trong đồ thị có trọng số 0 hoặc 1:
Điều này chỉ yêu cầu một chút sửa đổi đối với tìm kiếm theo chiều rộng thông thường: Thay vì duy trì mảng $used[]$, bây giờ chúng ta sẽ kiểm tra xem khoảng cách đến đỉnh có ngắn hơn khoảng cách hiện tại đã tìm thấy hay không, sau đó nếu cạnh hiện tại có trọng số bằng không, chúng ta thêm nó vào đầu hàng đợi, nếu không, chúng ta thêm nó vào cuối hàng đợi. Sửa đổi này được giải thích chi tiết hơn trong bài viết [BFS 0-1](01_bfs.md).

* Tìm chu trình ngắn nhất trong đồ thị có hướng không trọng số:
Bắt đầu tìm kiếm theo chiều rộng từ mỗi đỉnh.
Ngay sau khi chúng ta cố gắng đi từ đỉnh hiện tại trở lại đỉnh nguồn, chúng ta đã tìm thấy chu trình ngắn nhất chứa đỉnh nguồn.
Tại thời điểm này, chúng ta có thể dừng BFS và bắt đầu BFS mới từ đỉnh tiếp theo.
Từ tất cả các chu trình như vậy (tối đa một chu trình từ mỗi BFS), hãy chọn chu trình ngắn nhất.

* Tìm tất cả các cạnh nằm trên bất kỳ đường đi ngắn nhất nào giữa một cặp đỉnh nhất định $(a, b)$.
Để làm điều này, hãy chạy hai lần tìm kiếm theo chiều rộng:
một từ $a$ và một từ $b$.
Cho $d_a []$ là mảng chứa các khoảng cách ngắn nhất thu được từ BFS đầu tiên (từ $a$) và $d_b []$ là mảng chứa các khoảng cách ngắn nhất thu được từ BFS thứ hai từ $b$.
Bây giờ, đối với mỗi cạnh $(u, v)$, rất dễ dàng để kiểm tra xem cạnh đó có nằm trên bất kỳ đường đi ngắn nhất nào giữa $a$ và $b$ hay không:
tiêu chí là điều kiện $d_a [u] + 1 + d_b [v] = d_a [b]$.

* Tìm tất cả các đỉnh trên bất kỳ đường đi ngắn nhất nào giữa một cặp đỉnh nhất định $(a, b)$.
Để thực hiện điều đó, hãy chạy hai lần tìm kiếm theo chiều rộng:
một từ $a$ và một từ $b$.
Cho $d_a []$ là mảng chứa các khoảng cách ngắn nhất thu được từ BFS đầu tiên (từ $a$) và $d_b []$ là mảng chứa các khoảng cách ngắn nhất thu được từ BFS thứ hai (từ $b$).
Bây giờ, đối với mỗi đỉnh, rất dễ dàng để kiểm tra xem nó có nằm trên bất kỳ đường đi ngắn nhất nào giữa $a$ và $b$ hay không:
tiêu chí là điều kiện $d_a [v] + d_b [v] = d_a [b]$.

* Tìm đường đi ngắn nhất có độ dài chẵn từ đỉnh nguồn $s$ đến đỉnh đích $t$ trong đồ thị không trọng số:
Đối với điều này, chúng ta phải xây dựng một đồ thị phụ trợ, có các đỉnh là trạng thái $(v, c)$, trong đó $v$ - nút hiện tại, $c = 0$ hoặc $c = 1$ - tính chẵn lẻ hiện tại.
Bất kỳ cạnh $(u, v)$ nào của đồ thị ban đầu trong cột mới này sẽ biến thành hai cạnh $((u, 0), (v, 1))$ và $((u, 1), (v, 0))$.
Sau đó, chúng ta chạy BFS để tìm đường đi ngắn nhất từ ​​đỉnh bắt đầu $(s, 0)$ đến đỉnh kết thúc $(t, 0)$.

## Bài tập thực hành

* [SPOJ: AKBAR](http://spoj.com/problems/AKBAR)
* [SPOJ: NAKANJ](http://www.spoj.com/problems/NAKANJ/)
* [SPOJ: WATER](http://www.spoj.com/problems/WATER)
* [SPOJ: MICE AND MAZE](http://www.spoj.com/problems/MICEMAZE/)
* [Timus: Caravans](http://acm.timus.ru/problem.aspx?space=1&num=2034)
* [DevSkill - Holloween Party (lưu trữ)](http://web.archive.org/web/20200930162803/http://www.devskill.com/CodingProblems/ViewProblem/60)
* [DevSkill - Ohani And The Link Cut Tree (lưu trữ)](http://web.archive.org/web/20170216192002/http://devskill.com:80/CodingProblems/ViewProblem/150)
* [SPOJ - Spiky Mazes](http://www.spoj.com/problems/SPIKES/)
* [SPOJ - Four Chips (khó)](http://www.spoj.com/problems/ADV04F1/)
* [SPOJ - Inversion Sort](http://www.spoj.com/problems/INVESORT/)
* [Codeforces - Shortest Path](http://codeforces.com/contest/59/problem/E)
* [SPOJ - Yet Another Multiple Problem](http://www.spoj.com/problems/MULTII/)
* [UVA 11392 - Binary 3xType Multiple](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2387)
* [UVA 10968 - KuPellaKeS](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1909)
* [Codeforces - Police Stations](http://codeforces.com/contest/796/problem/D)
* [Codeforces - Okabe and City](http://codeforces.com/contest/821/problem/D)
* [SPOJ - Find the Treasure](http://www.spoj.com/problems/DIGOKEYS/)
* [Codeforces - Bear and Forgotten Tree 2](http://codeforces.com/contest/653/problem/E)
* [Codeforces - Cycle in Maze](http://codeforces.com/contest/769/problem/C)
* [UVA - 11312 - Flipping Frustration](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2287)
* [SPOJ - Ada and Cycle](http://www.spoj.com/problems/ADACYCLE/)
* [CSES - Labyrinth](https://cses.fi/problemset/task/1193)
* [CSES - Message Route](https://cses.fi/problemset/task/1667/)
* [CSES - Monsters](https://cses.fi/problemset/task/1194)

--- 




