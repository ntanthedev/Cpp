# Thuật toán Bellman-Ford

---
tags:
  - Dịch
e_maxx_link: ford_bellman
---

# Thuật toán Bellman-Ford

**Đường đi ngắn nhất nguồn đơn với các cạnh có trọng số âm**

Giả sử rằng chúng ta được cho một đồ thị có hướng có trọng số $G$ với $n$ đỉnh và $m$ cạnh, và một số đỉnh được chỉ định $v$. Bạn muốn tìm độ dài của đường đi ngắn nhất từ ​​đỉnh $v$ đến mọi đỉnh khác.

Không giống như thuật toán Dijkstra, thuật toán này cũng có thể được áp dụng cho các đồ thị có chứa các cạnh có trọng số âm. Tuy nhiên, nếu đồ thị chứa một chu trình âm, thì rõ ràng là đường đi ngắn nhất đến một số đỉnh có thể không tồn tại (do thực tế là trọng số của đường đi ngắn nhất phải bằng âm vô cùng); tuy nhiên, thuật toán này có thể được sửa đổi để báo hiệu sự hiện diện của một chu trình có trọng số âm, hoặc thậm chí suy ra chu trình này.

Thuật toán mang tên của hai nhà khoa học Mỹ: Richard Bellman và Lester Ford. Ford thực sự đã phát minh ra thuật toán này vào năm 1956 trong quá trình nghiên cứu một bài toán toán học khác, cuối cùng được rút gọn thành một bài toán con để tìm các đường đi ngắn nhất trong đồ thị, và Ford đã đưa ra dàn ý về thuật toán để giải quyết bài toán này. Bellman vào năm 1958 đã xuất bản một bài báo dành riêng cho bài toán tìm đường đi ngắn nhất, và trong bài báo này, ông đã nêu rõ thuật toán ở dạng mà chúng ta biết bây giờ.

## Mô tả thuật toán

Hãy giả sử rằng đồ thị không chứa chu trình trọng số âm. Trường hợp có chu trình trọng số âm sẽ được thảo luận bên dưới trong một phần riêng biệt.

Chúng ta sẽ tạo một mảng khoảng cách $d[0 \ldots n-1]$, sau khi thực hiện thuật toán sẽ chứa câu trả lời cho bài toán. Ban đầu, chúng ta điền nó như sau: $d[v] = 0$ và tất cả các phần tử $d[ ]$ khác bằng vô cùng $\infty$.

Thuật toán bao gồm một số giai đoạn. Mỗi giai đoạn quét qua tất cả các cạnh của đồ thị và thuật toán cố gắng tạo ra **sự giãn** (relaxation) dọc theo mỗi cạnh $(a,b)$ có trọng số $c$. Sự giãn dọc theo các cạnh là một nỗ lực để cải thiện giá trị $d[b]$ bằng cách sử dụng giá trị $d[a] + c$. Trên thực tế, điều đó có nghĩa là chúng ta đang cố gắng cải thiện câu trả lời cho đỉnh này bằng cách sử dụng cạnh $(a,b)$ và câu trả lời hiện tại cho đỉnh $a$.

Người ta cho rằng $n-1$ giai đoạn của thuật toán là đủ để tính toán chính xác độ dài của tất cả các đường đi ngắn nhất trong đồ thị (một lần nữa, chúng ta tin rằng không tồn tại các chu trình có trọng số âm). Đối với các đỉnh không thể truy cập được, khoảng cách $d[ ]$ sẽ vẫn bằng vô cùng $\infty$.

## Triển khai

Không giống như nhiều thuật toán đồ thị khác, đối với thuật toán Bellman-Ford, sẽ thuận tiện hơn khi biểu diễn đồ thị bằng cách sử dụng một danh sách duy nhất của tất cả các cạnh (thay vì $n$ danh sách các cạnh - các cạnh từ mỗi đỉnh). Chúng ta bắt đầu triển khai bằng một cấu trúc $\rm edge$ để biểu diễn các cạnh. Đầu vào của thuật toán là các số $n$, $m$, danh sách $e$ của các cạnh và đỉnh bắt đầu $v$. Tất cả các đỉnh được đánh số từ $0$ đến $n - 1$.

### Cách triển khai đơn giản nhất

Hằng số $\rm INF$ biểu thị số "vô cực" — nó phải được chọn sao cho nó lớn hơn tất cả các độ dài đường dẫn có thể có.

```cpp
struct Edge {
    int a, b, cost;
};

int n, m, v;
vector<Edge> edges;
const int INF = 1000000000;

void solve()
{
    vector<int> d(n, INF);
    d[v] = 0;
    for (int i = 0; i < n - 1; ++i)
        for (Edge e : edges)
            if (d[e.a] < INF)
                d[e.b] = min(d[e.b], d[e.a] + e.cost);
    // hiển thị d, ví dụ, trên màn hình
}
```

Việc kiểm tra `if (d[e.a] < INF)` chỉ cần thiết nếu đồ thị chứa các cạnh có trọng số âm: không có xác minh nào như vậy sẽ dẫn đến sự giãn từ các đỉnh mà đường dẫn chưa được tìm thấy và khoảng cách không chính xác, thuộc loại $\infty - 1$, $\infty - 2$, v.v. sẽ xuất hiện.

### Cách triển khai tốt hơn

Thuật toán này có thể được tăng tốc phần nào: thông thường chúng ta đã nhận được câu trả lời trong một vài giai đoạn và không có công việc hữu ích nào được thực hiện trong các giai đoạn còn lại, chỉ lãng phí việc truy cập tất cả các cạnh. Vì vậy, hãy giữ cờ, để cho biết liệu có điều gì đã thay đổi trong giai đoạn hiện tại hay không và nếu có bất kỳ giai đoạn nào, không có gì thay đổi, thuật toán có thể được dừng lại. (Tối ưu hóa này không cải thiện hành vi tiệm cận, tức là một số đồ thị sẽ vẫn cần tất cả $n-1$ giai đoạn, nhưng tăng tốc đáng kể hành vi của thuật toán "trung bình", tức là trên các đồ thị ngẫu nhiên.)

Với tối ưu hóa này, nói chung không cần thiết phải giới hạn thủ công số giai đoạn của thuật toán thành $n-1$ — thuật toán sẽ dừng sau số giai đoạn mong muốn.

```cpp
void solve()
{
    vector<int> d(n, INF);
    d[v] = 0;
    for (;;) {
        bool any = false;

        for (Edge e : edges)
            if (d[e.a] < INF)
                if (d[e.b] > d[e.a] + e.cost) {
                    d[e.b] = d[e.a] + e.cost;
                    any = true;
                }

        if (!any)
            break;
    }
    // hiển thị d, ví dụ, trên màn hình
}
```

### Truy xuất đường dẫn

Bây giờ chúng ta hãy xem xét cách sửa đổi thuật toán để nó không chỉ tìm độ dài của đường đi ngắn nhất mà còn cho phép xây dựng lại đường đi ngắn nhất.

Vì vậy, hãy tạo một mảng khác $p[0 \ldots n-1]$, trong đó đối với mỗi đỉnh, chúng ta lưu trữ "đỉnh đứng trước" của nó, tức là đỉnh áp chót trong đường đi ngắn nhất dẫn đến nó. Trên thực tế, đường đi ngắn nhất đến bất kỳ đỉnh $a$ nào là đường đi ngắn nhất đến một số đỉnh $p[a]$, mà chúng ta đã thêm $a$ vào cuối đường dẫn.

Lưu ý rằng thuật toán hoạt động theo cùng một logic: nó giả định rằng khoảng cách ngắn nhất đến một đỉnh đã được tính toán và cố gắng cải thiện khoảng cách ngắn nhất đến các đỉnh khác từ đỉnh đó. Do đó, tại thời điểm cải thiện, chúng ta chỉ cần nhớ $p[ ]$, tức là đỉnh mà từ đó sự cải thiện này đã xảy ra.

Sau đây là cách triển khai Bellman-Ford với việc truy xuất đường đi ngắn nhất đến một nút nhất định $t$:

```cpp
void solve()
{
    vector<int> d(n, INF);
    d[v] = 0;
    vector<int> p(n, -1);

    for (;;) {
        bool any = false;
        for (Edge e : edges)
            if (d[e.a] < INF)
                if (d[e.b] > d[e.a] + e.cost) {
                    d[e.b] = d[e.a] + e.cost;
                    p[e.b] = e.a;
                    any = true;
                }
        if (!any)
            break;
    }

    if (d[t] == INF)
        cout << "Không có đường đi từ " << v << " đến " << t << ".";
    else {
        vector<int> path;
        for (int cur = t; cur != -1; cur = p[cur])
            path.push_back(cur);
        reverse(path.begin(), path.end());

        cout << "Đường đi từ " << v << " đến " << t << ": ";
        for (int u : path)
            cout << u << ' ';
    }
}
```

Ở đây, bắt đầu từ đỉnh $t$, chúng ta đi qua các đỉnh đứng trước cho đến khi chúng ta đến đỉnh bắt đầu không có đỉnh đứng trước và lưu trữ tất cả các đỉnh trong đường dẫn vào danh sách $\rm path$. Danh sách này là đường đi ngắn nhất từ ​​$v$ đến $t$, nhưng theo thứ tự ngược lại, vì vậy chúng ta gọi hàm $\rm reverse()$ trên $\rm path$ và sau đó xuất ra đường dẫn.

## Chứng minh thuật toán

Đầu tiên, lưu ý rằng đối với tất cả các đỉnh không thể truy cập được $u$, thuật toán sẽ hoạt động chính xác, nhãn $d[u]$ sẽ vẫn bằng vô cùng (vì thuật toán Bellman-Ford sẽ tìm thấy một số cách đến tất cả các đỉnh có thể truy cập được từ đỉnh bắt đầu $v$, và sự giãn cho tất cả các đỉnh còn lại sẽ không bao giờ xảy ra).

Bây giờ chúng ta hãy chứng minh khẳng định sau: Sau khi thực hiện giai đoạn thứ $i$, thuật toán Bellman-Ford sẽ tìm ra chính xác tất cả các đường đi ngắn nhất có số cạnh không vượt quá $i$.

Nói cách khác, đối với bất kỳ đỉnh $a$ nào, hãy để chúng ta biểu thị $k$ số cạnh trong đường đi ngắn nhất đến nó (nếu có nhiều đường dẫn như vậy, bạn có thể lấy bất kỳ đường dẫn nào). Theo câu lệnh này, thuật toán đảm bảo rằng sau giai đoạn thứ $k$, đường đi ngắn nhất cho đỉnh $a$ sẽ được tìm thấy.

**Chứng minh**:
Xét một đỉnh $a$ tùy ý có đường dẫn từ đỉnh bắt đầu $v$ và xem xét đường đi ngắn nhất đến nó $(p_0=v, p_1, \ldots, p_k=a)$. Trước giai đoạn đầu tiên, đường đi ngắn nhất đến đỉnh $p_0 = v$ đã được tìm thấy chính xác. Trong giai đoạn đầu tiên, cạnh $(p_0,p_1)$ đã được thuật toán kiểm tra và do đó, khoảng cách đến đỉnh $p_1$ đã được tính toán chính xác sau giai đoạn đầu tiên. Lặp lại câu lệnh này $k$ lần, chúng ta thấy rằng sau giai đoạn thứ $k$, khoảng cách đến đỉnh $p_k = a$ được tính toán chính xác, điều mà chúng ta muốn chứng minh.

Điều cuối cùng cần lưu ý là bất kỳ đường dẫn ngắn nhất nào cũng không thể có nhiều hơn $n - 1$ cạnh. Do đó, thuật toán đủ để đi đến giai đoạn thứ $(n-1)$. Sau đó, đảm bảo rằng không có sự giãn nào sẽ cải thiện khoảng cách đến một số đỉnh.

## Trường hợp của chu trình âm

Ở mọi nơi ở trên, chúng ta đã xem xét rằng không có chu trình âm trong đồ thị (chính xác là chúng ta quan tâm đến một chu trình âm có thể truy cập được từ đỉnh bắt đầu $v$ và đối với các chu trình không thể truy cập được, không có gì trong thuật toán ở trên thay đổi). Trong trường hợp có chu trình âm, có những phức tạp hơn nữa liên quan đến thực tế là khoảng cách đến tất cả các đỉnh trong chu trình này, cũng như khoảng cách đến các đỉnh có thể truy cập được từ chu trình này, không được xác định - chúng phải bằng âm vô cùng $(- \infty)$.

Dễ dàng nhận thấy rằng thuật toán Bellman-Ford có thể thực hiện giãn vô hạn giữa tất cả các đỉnh của chu trình này và các đỉnh có thể truy cập được từ nó. Do đó, nếu bạn không giới hạn số giai đoạn thành $n - 1$, thuật toán sẽ chạy vô thời hạn, liên tục cải thiện khoảng cách từ các đỉnh này.

Do đó, chúng ta thu được **tiêu chí cho sự hiện diện của một chu trình có trọng số âm có thể truy cập được đối với đỉnh nguồn $v$**: sau giai đoạn thứ $(n-1)$, nếu chúng ta chạy thuật toán cho một giai đoạn nữa và nó thực hiện ít nhất một lần giãn nữa, thì đồ thị chứa một chu trình có trọng số âm có thể truy cập được từ $v$; nếu không, chu kỳ như vậy không tồn tại.

Hơn nữa, nếu tìm thấy một chu trình như vậy, thuật toán Bellman-Ford có thể được sửa đổi để nó truy xuất chu trình này dưới dạng chuỗi các đỉnh chứa trong đó. Đối với điều này, chỉ cần nhớ đỉnh cuối cùng $x$ mà đã có sự giãn trong giai đoạn thứ $n$. Đỉnh này sẽ nằm trong một chu trình có trọng số âm hoặc có thể truy cập được từ nó. Để có được các đỉnh được đảm bảo nằm trong một chu trình âm, bắt đầu từ đỉnh $x$, hãy đi qua các đỉnh đứng trước $n$ lần. Do đó, chúng ta sẽ nhận được đỉnh $y$, cụ thể là đỉnh trong chu trình sớm nhất có thể truy cập được từ nguồn. Chúng ta phải đi từ đỉnh này, qua các đỉnh đứng trước, cho đến khi chúng ta quay trở lại cùng một đỉnh $y$ (và nó sẽ xảy ra, bởi vì sự giãn trong một chu trình có trọng số âm xảy ra theo cách tròn).

### Triển khai:

```cpp
void solve()
{
    vector<int> d(n, INF);
    d[v] = 0;
    vector<int> p(n, -1);
    int x;
    for (int i = 0; i < n; ++i) {
        x = -1;
        for (Edge e : edges)
            if (d[e.a] < INF)
                if (d[e.b] > d[e.a] + e.cost) {
                    d[e.b] = max(-INF, d[e.a] + e.cost);
                    p[e.b] = e.a;
                    x = e.b;
                }
    }

    if (x == -1)
        cout << "Không có chu trình âm từ " << v;
    else {
        int y = x;
        for (int i = 0; i < n; ++i)
            y = p[y];

        vector<int> path;
        for (int cur = y;; cur = p[cur]) {
            path.push_back(cur);
            if (cur == y && path.size() > 1)
                break;
        }
        reverse(path.begin(), path.end());

        cout << "Chu trình âm: ";
        for (int u : path)
            cout << u << ' ';
    }
}
```

Do sự hiện diện của một chu trình âm, đối với $n$ lần lặp của thuật toán, khoảng cách có thể đi xa trong phạm vi âm (đến các số âm theo thứ tự $-n m W$, trong đó $W$ là giá trị tuyệt đối tối đa của bất kỳ trọng số nào trong đồ thị). Do đó trong mã, chúng tôi đã áp dụng các biện pháp bổ sung để chống lại tràn số nguyên như sau:

```cpp
d[e.b] = max(-INF, d[e.a] + e.cost);
```

Cách triển khai ở trên tìm kiếm một chu trình âm có thể truy cập được từ một số đỉnh bắt đầu $v$; tuy nhiên, thuật toán có thể được sửa đổi để chỉ tìm kiếm bất kỳ chu trình âm nào trong đồ thị. Đối với điều này, chúng ta cần đặt tất cả khoảng cách $d[i]$ thành 0 chứ không phải vô cùng - như thể chúng ta đang tìm kiếm đường đi ngắn nhất từ ​​tất cả các đỉnh đồng thời; tính hợp lệ của việc phát hiện chu trình âm không bị ảnh hưởng.

Để biết thêm về chủ đề này - hãy xem bài viết riêng, [Tìm chu trình âm trong đồ thị](finding-negative-cycle-in-graph.md).

## Thuật toán đường dẫn ngắn hơn nhanh hơn (SPFA - Shortest Path Faster Algorithm)

SPFA là một cải tiến của thuật toán Bellman-Ford, tận dụng thực tế là không phải mọi nỗ lực giãn đều sẽ hiệu quả.
Ý tưởng chính là tạo một hàng đợi chỉ chứa các đỉnh đã được giãn nhưng vẫn có thể tiếp tục giãn các lân cận của chúng.
Và bất cứ khi nào bạn có thể thư giãn một số hàng xóm, bạn nên đặt nó vào hàng đợi. Thuật toán này cũng có thể được sử dụng để phát hiện chu trình âm như Bellman-Ford.

Trường hợp xấu nhất của thuật toán này bằng $O(n m)$ của Bellman-Ford, nhưng trong thực tế, nó hoạt động nhanh hơn nhiều và một số [người cho rằng nó thậm chí còn hoạt động trong $O(m)$ trung bình](https://en.wikipedia.org/wiki/Shortest_Path_Faster_Algorithm#Average-case_performance). Tuy nhiên, hãy cẩn thận, bởi vì thuật toán này là xác định và rất dễ tạo ra các ví dụ phản bác làm cho thuật toán chạy trong $O(n m)$.

Có một số điều cần lưu ý trong cách triển khai, chẳng hạn như thực tế là thuật toán sẽ tiếp tục mãi mãi nếu có một chu trình âm.
Để tránh điều này, có thể tạo một bộ đếm lưu trữ số lần một đỉnh đã được giãn và dừng thuật toán ngay khi một số đỉnh được giãn lần thứ $n$.
Lưu ý, cũng không có lý do gì để đặt một đỉnh vào hàng đợi nếu nó đã có trong đó.

```{.cpp file=spfa}
const int INF = 1000000000;
vector<vector<pair<int, int>>> adj;

bool spfa(int s, vector<int>& d) {
    int n = adj.size();
    d.assign(n, INF);
    vector<int> cnt(n, 0);
    vector<bool> inqueue(n, false);
    queue<int> q;

    d[s] = 0;
    q.push(s);
    inqueue[s] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        inqueue[v] = false;

        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                if (!inqueue[to]) {
                    q.push(to);
                    inqueue[to] = true;
                    cnt[to]++;
                    if (cnt[to] > n)
                        return false;  // chu trình âm
                }
            }
        }
    }
    return true;
}
```


## Bài toán liên quan trong các online judge

Danh sách các bài tập có thể được giải quyết bằng thuật toán Bellman-Ford:

* [E-OLYMP #1453 "Ford-Bellman" [độ khó: thấp]](https://www.e-olymp.com/en/problems/1453)
* [UVA #423 "MPI Maelstrom" [độ khó: thấp]](http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=364)
* [UVA #534 "Frogger" [độ khó: trung bình]](http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=7&page=show_problem&problem=475)
* [UVA #10099 "The Tourist Guide" [độ khó: trung bình]](http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=12&page=show_problem&problem=1040)
* [UVA #515 "King" [độ khó: trung bình]](http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=456)
* [UVA 12519 - The Farnsworth Parabox](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3964)

Xem thêm danh sách bài toán trong bài viết [Tìm chu trình âm trong đồ thị](finding-negative-cycle-in-graph.md).
* [CSES - High Score](https://cses.fi/problemset/task/1673)
* [CSES - Cycle Finding](https://cses.fi/problemset/task/1197)

--- 


