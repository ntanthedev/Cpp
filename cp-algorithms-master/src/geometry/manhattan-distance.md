# Khoảng cách Manhattan (Manhattan Distance)

## Định nghĩa

Đối với các điểm $p$ và $q$ trên mặt phẳng, chúng ta có thể định nghĩa khoảng cách giữa chúng là tổng của hiệu số giữa tọa độ $x$ và $y$ của chúng:

$$d(p,q) = |p.x - q.x| + |p.y - q.y|$$

Được định nghĩa theo cách này, khoảng cách tương ứng với cái gọi là [hình học Manhattan (taxi)](https://en.wikipedia.org/wiki/Taxicab_geometry), trong đó các điểm được coi là giao điểm trong một thành phố được thiết kế tốt, như Manhattan, nơi bạn chỉ có thể di chuyển trên đường phố theo chiều ngang hoặc chiều dọc, như trong hình ảnh bên dưới:

<center>![Khoảng cách Manhattan](https://upload.wikimedia.org/wikipedia/commons/thumb/0/08/Manhattan_distance.svg/220px-Manhattan_distance.svg.png)</center>

Những hình ảnh này hiển thị một số đường dẫn ngắn nhất từ ​​điểm đen này sang điểm đen kia, tất cả đều có độ dài $12$.

Có một số thủ thuật và thuật toán thú vị có thể được thực hiện với khoảng cách này và chúng tôi sẽ trình bày một số trong số chúng ở đây.

## Cặp điểm xa nhất theo khoảng cách Manhattan

Cho $n$ điểm $P$, chúng ta muốn tìm cặp điểm $p,q$ xa nhau nhất, tức là tối đa hóa $|p.x - q.x| + |p.y - q.y|$.

Trước tiên hãy nghĩ trong một chiều, vì vậy $y=0$. Quan sát chính là chúng ta có thể vét cạn (bruteforce) nếu $|p.x - q.x|$ bằng $p.x - q.x$ hoặc $-p.x + q.x$, bởi vì nếu chúng ta "bỏ lỡ dấu" của giá trị tuyệt đối, chúng ta sẽ chỉ nhận được một giá trị nhỏ hơn, vì vậy nó không thể ảnh hưởng đến câu trả lời. Chính thức hơn, nó được giữ:

$$|p.x - q.x| = \max(p.x - q.x, -p.x + q.x)$$

Vì vậy, ví dụ, chúng ta có thể thử có $p$ sao cho $p.x$ có dấu cộng, và sau đó $q$ phải có dấu trừ. Bằng cách này, chúng ta muốn tìm:

$$\max\limits_{p, q \in P}(p.x + (-q.x)) = \max\limits_{p \in P}(p.x) + \max\limits_{q \in P}( - q.x ).$$

Lưu ý rằng chúng ta có thể mở rộng ý tưởng này thêm cho 2 (hoặc nhiều hơn!) chiều. Đối với $d$ chiều, chúng ta phải vét cạn $2^d$ giá trị có thể có của các dấu. Ví dụ: nếu chúng ta đang ở trong $2$ chiều và vét cạn rằng $p$ có cả hai dấu cộng mà chúng ta muốn tìm:

$$\max\limits_{p, q \in P} [(p.x + (-q.x)) + (p.y + (-q.y))] = \max\limits_{p \in P}(p.x + p.y) + \max\limits_{q \in P}(-q.x - q.y).$$

Vì chúng ta đã làm cho $p$ và $q$ độc lập, nên bây giờ rất dễ dàng để tìm $p$ và $q$ tối đa hóa biểu thức.

Mã bên dưới khái quát hóa điều này thành $d$ chiều và chạy trong $O(n \cdot 2^d \cdot d)$.

```cpp
long long ans = 0;
for (int msk = 0; msk < (1 << d); msk++) {
    long long mx = LLONG_MIN, mn = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        long long cur = 0;
        for (int j = 0; j < d; j++) {
            if (msk & (1 << j)) cur += p[i][j];
            else cur -= p[i][j];
        }
        mx = max(mx, cur);
        mn = min(mn, cur);
    }
    ans = max(ans, mx - mn);
}
```

## Xoay các điểm và khoảng cách Chebyshev

Ai cũng biết rằng, với mọi $m, n \in \mathbb{R}$,

$$|m| + |n| = \text{max}(|m + n|, |m - n|).$$

Để chứng minh điều này, chúng ta chỉ cần phân tích dấu của $m$ và $n$. Và nó được để lại như một bài tập.

Chúng ta có thể áp dụng phương trình này cho công thức khoảng cách Manhattan để tìm ra rằng

$$d((x_1, y_1), (x_2, y_2)) = |x_1 - x_2| + |y_1 - y_2| = \text{max}(|(x_1 + y_1) - (x_2 + y_2)|, |(x_1 - y_1) - (x_2 - y_2)|).$$

Biểu thức cuối cùng trong phương trình trước là [khoảng cách Chebyshev](https://en.wikipedia.org/wiki/Chebyshev_distance) của các điểm $(x_1 + y_1, x_1 - y_1)$ và $(x_2 + y_2, x_2 - y_2)$. Điều này có nghĩa là, sau khi áp dụng phép biến đổi

$$\alpha : (x, y) \to (x + y, x - y),$$

khoảng cách Manhattan giữa các điểm $p$ và $q$ biến thành khoảng cách Chebyshev giữa $\alpha(p)$ và $\alpha(q)$.

Ngoài ra, chúng ta có thể nhận ra rằng $\alpha$ là [phép đồng dạng xoắn ốc](https://en.wikipedia.org/wiki/Spiral_similarity) (quay mặt phẳng theo sau là giãn nở tâm $O$) với tâm $(0, 0)$, góc quay là $45^{\circ}$ theo chiều kim đồng hồ và giãn nở bằng $\sqrt{2}$.

Đây là hình ảnh để giúp hình dung phép biến đổi:

<center>![Biến đổi Chebyshev](chebyshev-transformation.png)</center>

## Cây khung nhỏ nhất Manhattan (Manhattan Minimum Spanning Tree)

Bài toán Cây khung nhỏ nhất Manhattan (Manhattan MST) bao gồm, cho một số điểm trên mặt phẳng, tìm các cạnh nối tất cả các điểm và có tổng trọng số nhỏ nhất. Trọng số của một cạnh nối hai điểm là khoảng cách Manhattan của chúng. Để đơn giản, chúng tôi giả sử rằng tất cả các điểm đều có vị trí khác nhau.
Ở đây, chúng tôi chỉ ra một cách tìm MST trong $O(n \log{n})$ bằng cách tìm cho mỗi điểm láng giềng gần nhất của nó trong mỗi góc phần tám, như được biểu diễn trong hình ảnh bên dưới. Điều này sẽ cung cấp cho chúng ta $O(n)$ cạnh ứng viên, như chúng ta sẽ chỉ ra bên dưới, sẽ đảm bảo rằng chúng chứa MST. Bước cuối cùng sau đó là sử dụng một số MST tiêu chuẩn, ví dụ: [thuật toán Kruskal sử dụng hợp nhất tập hợp rời rạc](https://cp-algorithms.com/graph/mst_kruskal_with_dsu.html).

<center>![hình ảnh 8 góc phần tám](manhattan-mst-octants.png)

*8 góc phần tám so với điểm S*</center>

Thuật toán được hiển thị ở đây lần đầu tiên được trình bày trong một bài báo từ [H. Zhou, N. Shenoy, and W. Nichollos (2002)](https://ieeexplore.ieee.org/document/913303). Ngoài ra còn có một thuật toán đã biết khác sử dụng cách tiếp cận Chia để trị của [J. Stolfi](https://www.academia.edu/15667173/On_computing_all_north_east_nearest_neighbors_in_the_L1_metric), cũng rất thú vị và chỉ khác nhau ở cách chúng tìm láng giềng gần nhất trong mỗi góc phần tám. Cả hai đều có cùng độ phức tạp, nhưng cái được trình bày ở đây dễ triển khai hơn và có hệ số hằng số thấp hơn.

Đầu tiên, hãy hiểu tại sao chỉ cần xem xét láng giềng gần nhất trong mỗi góc phần tám. Ý tưởng là chứng minh rằng đối với một điểm $s$ và bất kỳ hai điểm $p$ và $q$ nào khác trong cùng một góc phần tám, $d(p, q) < \max(d(s, p), d(s, q))$. Điều này rất quan trọng, bởi vì nó cho thấy rằng nếu có MST trong đó $s$ được kết nối với cả $p$ và $q$, chúng ta có thể xóa một trong những cạnh này và thêm cạnh $(p, q)$, điều này sẽ làm giảm tổng chi phí. Để chứng minh điều này, chúng ta giả sử không mất tính tổng quát rằng $p$ và $q$ nằm trong góc phần tám $R_1$, được xác định bởi: $x_s \leq x$ và $x_s - y_s > x - y$, và sau đó thực hiện một số trường hợp. Hình ảnh bên dưới cung cấp một số trực giác về lý do tại sao điều này là đúng.

<center>![láng giềng gần nhất duy nhất](manhattan-mst-uniqueness.png)

*Theo trực giác, giới hạn của góc phần tám khiến cho $p$ và $q$ không thể cùng lúc gần $s$ hơn là gần nhau*</center>


Do đó, câu hỏi chính là làm thế nào để tìm láng giềng gần nhất trong mỗi góc phần tám cho mỗi một trong $n$ điểm.

## Láng giềng gần nhất trong mỗi góc phần tám trong O(n log n)

Để đơn giản, chúng ta tập trung vào góc phần tám NNE ($R_1$ trong hình trên). Tất cả các hướng khác có thể được tìm thấy bằng cùng một thuật toán bằng cách xoay đầu vào.

Chúng ta sẽ sử dụng phương pháp quét đường (sweep-line). Chúng ta xử lý các điểm từ tây nam đến đông bắc, tức là theo thứ tự không giảm của $x + y$. Chúng ta cũng giữ một tập hợp các điểm chưa có láng giềng gần nhất, mà chúng ta gọi là "tập hợp hoạt động". Chúng tôi thêm hình ảnh bên dưới để giúp hình dung thuật toán.

<center>![quét manhattan-mst](manhattan-mst-sweep-line-1.png)

*Màu đen với mũi tên, bạn có thể thấy hướng của quét đường. Tất cả các điểm bên dưới các dòng này đều nằm trong tập hợp hoạt động và các điểm ở trên vẫn chưa được xử lý. Màu xanh lá cây, chúng ta thấy các điểm nằm trong góc phần tám của điểm đã xử lý. Màu đỏ là các điểm không nằm trong góc phần tám đang tìm kiếm.*</center>

<center>![quét manhattan-mst](manhattan-mst-sweep-line-2.png)

*Trong hình ảnh này, chúng ta thấy tập hợp hoạt động sau khi xử lý điểm $p$. Lưu ý rằng $2$ điểm màu xanh lá cây của hình ảnh trước đó có $p$ trong góc phần tám bắc-bắc-đông của nó và không còn nằm trong tập hợp hoạt động nữa, bởi vì chúng đã tìm thấy láng giềng gần nhất của chúng.*</center>

Khi chúng ta thêm một điểm mới $p$, đối với mọi điểm $s$ có nó trong góc phần tám của nó, chúng ta có thể gán $p$ một cách an toàn làm láng giềng gần nhất. Điều này đúng bởi vì khoảng cách của chúng là $d(p,s) = |x_p - x_s| + |y_p - y_s| = (x_p + y_p) - (x_s + y_s)$, bởi vì $p$ nằm trong góc phần tám bắc-bắc-đông. Vì tất cả các điểm tiếp theo sẽ không có giá trị $x + y$ nhỏ hơn do bước sắp xếp, nên $p$ được đảm bảo có khoảng cách nhỏ hơn. Sau đó, chúng ta có thể loại bỏ tất cả các điểm như vậy khỏi tập hợp hoạt động và cuối cùng thêm $p$ vào tập hợp hoạt động.

Câu hỏi tiếp theo là làm thế nào để tìm ra hiệu quả những điểm $s$ nào có $p$ trong góc phần tám bắc-bắc-đông. Tức là những điểm $s$ nào thỏa mãn:

- $x_s \leq x_p$
- $x_p - y_p < x_s - y_s$

Vì không có điểm nào trong tập hợp hoạt động nằm trong vùng $R_1$ của một điểm khác, nên chúng ta cũng có điều đó đối với hai điểm $q_1$ và $q_2$ trong tập hợp hoạt động, $x_{q_1} \neq x_{q_2}$ và thứ tự của chúng ngụ ý $x_{q_1} < x_{q_2} \implies x_{q_1} - y_{q_1} \leq x_{q_2} - y_{q_2}$.

Bạn có thể thử hình dung điều này trên các hình ảnh ở trên bằng cách coi thứ tự của $x - y$ là "đường quét" đi từ tây bắc đến đông nam, vì vậy vuông góc với đường đã vẽ.

Điều này có nghĩa là nếu chúng ta giữ tập hợp hoạt động được sắp xếp theo $x$ thì các ứng cử viên $s$ được đặt liên tiếp. Sau đó, chúng ta có thể tìm $x_s \leq x_p$ lớn nhất và xử lý các điểm theo thứ tự giảm dần của $x$ cho đến khi điều kiện thứ hai $x_p - y_p < x_s - y_s$ bị phá vỡ (chúng ta thực sự có thể cho phép $x_p - y_p = x_s - y_s$ và điều đó xử lý trường hợp các điểm có tọa độ bằng nhau). Lưu ý rằng bởi vì chúng ta xóa khỏi tập hợp ngay sau khi xử lý, điều này sẽ có độ phức tạp khấu hao (amortized complexity) là $O(n \log(n))$.
	Bây giờ chúng ta đã có điểm gần nhất theo hướng đông bắc, chúng ta xoay các điểm và lặp lại. Có thể chỉ ra rằng thực tế chúng ta cũng tìm thấy theo cách này điểm gần nhất theo hướng tây nam, vì vậy chúng ta chỉ có thể lặp lại 4 lần thay vì 8 lần.

Tóm tắt, chúng ta:

- Sắp xếp các điểm theo $x + y$ theo thứ tự không giảm;
- Đối với mỗi điểm, chúng ta lặp lại tập hợp hoạt động bắt đầu với điểm có $x$ lớn nhất sao cho $x \leq x_p$ và chúng ta phá vỡ vòng lặp nếu $x_p - y_p \geq x_s - y_s$. Đối với mỗi điểm $s$ hợp lệ, chúng ta thêm cạnh $(s,p, d(s,p))$ vào danh sách của chúng ta;
- Chúng ta thêm điểm $p$ vào tập hợp hoạt động;
- Xoay các điểm và lặp lại cho đến khi chúng ta lặp qua tất cả các góc phần tám.
- Áp dụng thuật toán Kruskal vào danh sách các cạnh để nhận MST.

Dưới đây, bạn có thể tìm thấy một triển khai, dựa trên triển khai từ [KACTL](https://github.com/kth-competitive-programming/kactl/blob/main/content/geometry/ManhattanMST.h).

```{.cpp file=manhattan_mst}
struct point {
    long long x, y;
};

// Trả về danh sách các cạnh ở định dạng (trọng số, u, v).
// Việc truyền danh sách này cho thuật toán Kruskal sẽ cung cấp MST Manhattan.
vector<tuple<long long, int, int>> manhattan_mst_edges(vector<point> ps) {
    vector<int> ids(ps.size());
    iota(ids.begin(), ids.end(), 0);
    vector<tuple<long long, int, int>> edges;
    for (int rot = 0; rot < 4; rot++) { // đối với mỗi vòng quay
        sort(ids.begin(), ids.end(), [&](int i, int j){
            return (ps[i].x + ps[i].y) < (ps[j].x + ps[j].y);
        });
        map<int, int, greater<int>> active; // (xs, id)
        for (auto i : ids) {
            for (auto it = active.lower_bound(ps[i].x); it != active.end();
            active.erase(it++)) {
                int j = it->second;
                if (ps[i].x - ps[i].y > ps[j].x - ps[j].y) break;
                assert(ps[i].x >= ps[j].x && ps[i].y >= ps[j].y);
                edges.push_back({(ps[i].x - ps[j].x) + (ps[i].y - ps[j].y), i, j});
            }
            active[ps[i].x] = i;
        }
        for (auto &p : ps) { // xoay
            if (rot & 1) p.x *= -1;
            else swap(p.x, p.y);
        }
    }
    return edges;
}
```

## Bài tập
 * [AtCoder Beginner Contest 178E - Dist Max](https://atcoder.jp/contests/abc178/tasks/abc178_e)
 * [CodeForces 1093G - Multidimensional Queries](https://codeforces.com/contest/1093/problem/G)
 * [CodeForces 944F - Game with Tokens](https://codeforces.com/contest/944/problem/F)
 * [AtCoder Code Festival 2017D - Four Coloring](https://atcoder.jp/contests/code-festival-2017-quala/tasks/code_festival_2017_quala_d)
 * [The 2023 ICPC Asia EC Regionals Online Contest (I) - J. Minimum Manhattan Distance](https://codeforces.com/gym/104639/problem/J)
 * [Petrozavodsk Winter Training Camp 2016 Contest 4 - B. Airports](https://codeforces.com/group/eqgxxTNwgd/contest/100959/attachments)

--- 




