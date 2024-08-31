# Tìm kiếm cặp điểm gần nhất

---
tags:
  - Dịch
e_maxx_link: nearest_points
---

# Tìm kiếm cặp điểm gần nhất

## Bài toán

Cho $n$ điểm trên mặt phẳng. Mỗi điểm $p_i$ được xác định bởi tọa độ của nó $(x_i,y_i)$. Yêu cầu tìm trong số chúng hai điểm sao cho khoảng cách giữa chúng là nhỏ nhất:

$$ \min_{\scriptstyle i, j=0 \ldots n-1,\atop \scriptstyle i \neq j } \rho (p_i, p_j). $$

Chúng ta lấy khoảng cách Euclide thông thường:

$$ \rho (p_i,p_j) = \sqrt{(x_i-x_j)^2 + (y_i-y_j)^2} .$$

Thuật toán tầm thường - lặp qua tất cả các cặp và tính toán khoảng cách cho mỗi cặp - hoạt động trong $O(n^2)$.

Thuật toán chạy trong thời gian $O(n \log n)$ được mô tả bên dưới. Thuật toán này được đề xuất bởi Shamos và Hoey vào năm 1975. (Nguồn: Chương 5 Ghi chú của _Thiết kế Thuật toán_ của Kleinberg & Tardos, cũng xem [tại đây](https://ieeexplore.ieee.org/abstract/document/4567872)) Preparata và Shamos cũng chỉ ra rằng thuật toán này là tối ưu trong mô hình cây quyết định.

## Thuật toán

Chúng ta xây dựng một thuật toán theo sơ đồ chung của thuật toán **chia để trị**: thuật toán được thiết kế như một hàm đệ quy, mà chúng ta truyền một tập hợp các điểm; hàm đệ quy này chia tập hợp này thành hai nửa, tự gọi đệ quy trên mỗi nửa và sau đó thực hiện một số thao tác để kết hợp các câu trả lời. Thao tác kết hợp bao gồm việc phát hiện các trường hợp khi một điểm của giải pháp tối ưu rơi vào một nửa và điểm kia rơi vào nửa kia (trong trường hợp này, các lệnh gọi đệ quy từ mỗi nửa không thể phát hiện riêng cặp này). Khó khăn chính, như mọi khi trong trường hợp thuật toán chia để trị, nằm ở việc triển khai hiệu quả giai đoạn hợp nhất. Nếu một tập hợp $n$ điểm được truyền cho hàm đệ quy, thì giai đoạn hợp nhất sẽ hoạt động không quá $O(n)$, thì tiệm cận của toàn bộ thuật toán $T(n)$ sẽ được tìm thấy từ phương trình:

$$T(n) = 2T(n/2) + O(n).$$

Giải pháp cho phương trình này, như đã biết, là $T(n) = O(n \log n).$

Vì vậy, chúng ta tiến hành xây dựng thuật toán. Để đi đến một cách triển khai hiệu quả của giai đoạn hợp nhất trong tương lai, chúng ta sẽ chia tập hợp các điểm thành hai tập hợp con, theo tọa độ $x$ của chúng: Trên thực tế, chúng ta vẽ một số đường thẳng đứng chia tập hợp các điểm thành hai tập hợp con có kích thước xấp xỉ bằng nhau. Thật tiện lợi khi thực hiện phân vùng như sau: Chúng ta sắp xếp các điểm theo cách tiêu chuẩn dưới dạng cặp số, ví dụ:

$$p_i < p_j \Longleftrightarrow (x_i < x_j) \lor \Big(\left(x_i = x_j\right) \wedge \left(y_i < y_j \right) \Big) $$

Sau đó lấy điểm giữa sau khi sắp xếp $p_m (m = \lfloor n/2 \rfloor)$, và tất cả các điểm trước nó và chính $p_m$ được gán cho nửa đầu tiên, và tất cả các điểm sau nó - cho nửa thứ hai:

$$A_1 = \{p_i \ | \ i = 0 \ldots m \}$$

$$A_2 = \{p_i \ | \ i = m + 1 \ldots n-1 \}.$$

Bây giờ, gọi đệ quy trên mỗi tập hợp $A_1$ và $A_2$, chúng ta sẽ tìm thấy câu trả lời $h_1$ và $h_2$ cho mỗi nửa. Và lấy cái tốt nhất trong số chúng: $h = \min(h_1, h_2)$.

Bây giờ chúng ta cần thực hiện **giai đoạn hợp nhất**, tức là chúng ta cố gắng tìm các cặp điểm như vậy, mà khoảng cách giữa chúng nhỏ hơn $h$ và một điểm nằm trong $A_1$ và điểm kia nằm trong $A_2$.
Rõ ràng là chỉ cần xem xét những điểm cách đường thẳng đứng một khoảng cách nhỏ hơn $h$, tức là tập $B$ của các điểm được xét ở giai đoạn này bằng:

$$B = \{ p_i\ | \ | x_i - x_m\ | < h \}.$$

Đối với mỗi điểm trong tập hợp $B$, chúng ta cố gắng tìm các điểm gần nó hơn $h$. Ví dụ: chỉ cần xem xét những điểm có tọa độ $y$ khác nhau không quá $h$. Hơn nữa, việc xem xét những điểm có tọa độ $y$ lớn hơn tọa độ $y$ của điểm hiện tại là vô nghĩa. Như vậy, đối với mỗi điểm $p_i$, chúng ta xác định tập hợp các điểm được xét $C(p_i)$ như sau:

$$C(p_i) = \{ p_j\ |\ p_j \in B,\ \ y_i - h < y_j \le y_i \}.$$

Nếu chúng ta sắp xếp các điểm của tập hợp $B$ theo tọa độ $y$, thì việc tìm $C(p_i)$ sẽ rất dễ dàng: đây là một số điểm liên tiếp trước điểm $p_i$.

Vì vậy, trong ký hiệu mới, **giai đoạn hợp nhất** trông như thế này: xây dựng một tập hợp $B$, sắp xếp các điểm trong đó theo tọa độ $y$, sau đó đối với mỗi điểm $p_i \in B$, hãy xem xét tất cả các điểm $p_j \in C(p_i)$ và đối với mỗi cặp $(p_i,p_j)$, hãy tính toán khoảng cách và so sánh với khoảng cách tốt nhất hiện tại.

Thoạt nhìn, đây vẫn là một thuật toán không tối ưu: có vẻ như kích thước của tập hợp $C(p_i)$ sẽ theo thứ tự $n$, và tiệm cận cần thiết sẽ không hoạt động. Tuy nhiên, thật ngạc nhiên, có thể chứng minh rằng kích thước của mỗi tập hợp $C(p_i)$ là một đại lượng $O(1)$, tức là nó không vượt quá một số hằng số nhỏ bất kể bản thân các điểm. Bằng chứng về thực tế này được đưa ra trong phần tiếp theo.

Cuối cùng, chúng ta chú ý đến việc sắp xếp mà thuật toán trên chứa: thứ nhất, sắp xếp theo cặp $(x, y)$, và thứ hai, sắp xếp các phần tử của tập hợp $B$ theo $y$. Trên thực tế, cả hai loại sắp xếp này bên trong hàm đệ quy đều có thể bị loại bỏ (nếu không, chúng ta sẽ không đạt được ước tính $O(n)$ cho **giai đoạn hợp nhất** và tiệm cận chung của thuật toán sẽ là $O(n \log^2 n)$). Việc loại bỏ kiểu sắp xếp đầu tiên rất dễ dàng - chỉ cần thực hiện kiểu sắp xếp này trước khi bắt đầu đệ quy: sau tất cả, bản thân các phần tử không thay đổi bên trong đệ quy, vì vậy không cần phải sắp xếp lại. Với kiểu sắp xếp thứ hai, khó thực hiện hơn một chút, việc thực hiện nó trước đó sẽ không hiệu quả. Nhưng, nhớ lại sắp xếp trộn (merge sort), cũng hoạt động theo nguyên tắc chia để trị, chúng ta có thể chỉ cần nhúng kiểu sắp xếp này vào đệ quy của mình. Cho phép đệ quy, lấy một số tập hợp điểm (như chúng ta nhớ, được sắp xếp theo cặp $(x, y)$), trả về cùng một tập hợp, nhưng được sắp xếp theo tọa độ $y$. Để làm điều này, chỉ cần hợp nhất (trong $O(n)$) hai kết quả được trả về bởi các lệnh gọi đệ quy. Điều này sẽ dẫn đến một tập hợp được sắp xếp theo tọa độ $y$.

## Đánh giá tiệm cận

Để chứng minh rằng thuật toán trên thực sự được thực thi trong $O(n \log n)$, chúng ta cần chứng minh sự kiện sau: $|C(p_i)| = O(1)$.

Vì vậy, chúng ta hãy xem xét một số điểm $p_i$; nhớ lại rằng tập hợp $C(p_i)$ là tập hợp các điểm có tọa độ $y$ nằm trong đoạn $[y_i-h; y_i]$, và hơn nữa, dọc theo tọa độ $x$, chính điểm $p_i$ và tất cả các điểm của tập hợp $C(p_i)$ nằm trong dải có độ rộng $2h$. Nói cách khác, các điểm chúng ta đang xem xét $p_i$ và $C(p_i)$ nằm trong một hình chữ nhật có kích thước $2h \times h$.

Nhiệm vụ của chúng ta là ước tính số lượng điểm tối đa có thể nằm trong hình chữ nhật $2h \times h$ này; do đó, chúng ta ước tính kích thước tối đa của tập hợp $C(p_i)$. Đồng thời, khi đánh giá, chúng ta không được quên rằng có thể có các điểm lặp lại.

Hãy nhớ rằng $h$ được lấy từ kết quả của hai lệnh gọi đệ quy - trên các tập hợp $A_1$ và $A_2$, và $A_1$ chứa các điểm ở bên trái đường phân vùng và một phần trên đó, $A_2$ chứa các điểm còn lại của đường phân vùng và điểm ở bên phải của nó. Đối với bất kỳ cặp điểm nào từ $A_1$, cũng như từ $A_2$, khoảng cách không thể nhỏ hơn $h$ — nếu không, điều đó có nghĩa là thao tác không chính xác của hàm đệ quy.

Để ước tính số lượng điểm tối đa trong hình chữ nhật $2h \times h$, chúng ta chia nó thành hai hình vuông $h \times h$, hình vuông thứ nhất bao gồm tất cả các điểm $C(p_i) \cap A_1$ và hình vuông thứ hai chứa tất cả các điểm còn lại, tức là $C(p_i) \cap A_2$. Từ những cân nhắc ở trên, suy ra rằng trong mỗi hình vuông này, khoảng cách giữa hai điểm bất kỳ là ít nhất $h$.

Chúng tôi chỉ ra rằng có nhiều nhất bốn điểm trong mỗi hình vuông. Ví dụ, điều này có thể được thực hiện như sau: chia hình vuông thành $4$ hình vuông con với các cạnh $h/2$. Sau đó, không thể có nhiều hơn một điểm trong mỗi hình vuông con này (vì ngay cả đường chéo cũng bằng $h / \sqrt{2}$, nhỏ hơn $h$). Do đó, không thể có nhiều hơn $4$ điểm trong toàn bộ hình vuông.

Vì vậy, chúng ta đã chứng minh rằng trong một hình chữ nhật $2h \times h$ không thể có nhiều hơn $4 \cdot 2 = 8$ điểm, và do đó, kích thước của tập hợp $C(p_i)$ không thể vượt quá $7$, theo yêu cầu.

## Triển khai

Chúng ta giới thiệu một cấu trúc dữ liệu để lưu trữ một điểm (tọa độ của nó và một số) và các toán tử so sánh cần thiết cho hai loại sắp xếp:

```{.cpp file=nearest_pair_def}
struct pt {
    int x, y, id;
};

struct cmp_x {
    bool operator()(const pt & a, const pt & b) const {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    }
};

struct cmp_y {
    bool operator()(const pt & a, const pt & b) const {
        return a.y < b.y;
    }
};

int n;
vector<pt> a;
```

Để thuận tiện cho việc triển khai đệ quy, chúng ta giới thiệu một hàm phụ trợ upd_ans(), hàm này sẽ tính toán khoảng cách giữa hai điểm và kiểm tra xem nó có tốt hơn câu trả lời hiện tại hay không:

```{.cpp file=nearest_pair_update}
double mindist;
pair<int, int> best_pair;

void upd_ans(const pt & a, const pt & b) {
    double dist = sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
    if (dist < mindist) {
        mindist = dist;
        best_pair = {a.id, b.id};
    }
}
```

Cuối cùng, việc triển khai chính đệ quy. Giả sử rằng trước khi gọi nó, mảng $a[]$ đã được sắp xếp theo tọa độ $x$. Trong đệ quy, chúng ta chỉ truyền hai con trỏ $l, r$, cho biết rằng nó nên tìm câu trả lời cho $a[l \ldots r)$. Nếu khoảng cách giữa $r$ và $l$ quá nhỏ, đệ quy phải được dừng lại và thực hiện thuật toán tầm thường để tìm cặp gần nhất, sau đó sắp xếp mảng con theo tọa độ $y$.

Để hợp nhất hai tập hợp điểm nhận được từ các lệnh gọi đệ quy thành một (được sắp xếp theo tọa độ $y$), chúng ta sử dụng hàm $merge()$ tiêu chuẩn của STL và tạo bộ đệm phụ trợ $t[]$ (một cho tất cả các lệnh gọi đệ quy). (Sử dụng inplace_merge () là không thực tế vì nó thường không hoạt động trong thời gian tuyến tính.)

Cuối cùng, tập hợp $B$ được lưu trữ trong cùng một mảng $t$.

```{.cpp file=nearest_pair_rec}
vector<pt> t;

void rec(int l, int r) {
    if (r - l <= 3) {
        for (int i = l; i < r; ++i) {
            for (int j = i + 1; j < r; ++j) {
                upd_ans(a[i], a[j]);
            }
        }
        sort(a.begin() + l, a.begin() + r, cmp_y());
        return;
    }

    int m = (l + r) >> 1;
    int midx = a[m].x;
    rec(l, m);
    rec(m, r);

    merge(a.begin() + l, a.begin() + m, a.begin() + m, a.begin() + r, t.begin(), cmp_y());
    copy(t.begin(), t.begin() + r - l, a.begin() + l);

    int tsz = 0;
    for (int i = l; i < r; ++i) {
        if (abs(a[i].x - midx) < mindist) {
            for (int j = tsz - 1; j >= 0 && a[i].y - t[j].y < mindist; --j)
                upd_ans(a[i], t[j]);
            t[tsz++] = a[i];
        }
    }
}
```

Nhân tiện, nếu tất cả các tọa độ là số nguyên, thì tại thời điểm đệ quy, bạn không thể chuyển sang giá trị phân số và lưu trữ trong $mindist$ bình phương của khoảng cách tối thiểu.

Trong chương trình chính, đệ quy nên được gọi như sau:

```{.cpp file=nearest_pair_main}
t.resize(n);
sort(a.begin(), a.end(), cmp_x());
mindist = 1E20;
rec(0, n);
```

## Khái quát hóa: tìm tam giác có chu vi nhỏ nhất

Thuật toán được mô tả ở trên được khái quát một cách thú vị cho bài toán này: trong một tập hợp điểm nhất định, hãy chọn ba điểm khác nhau sao cho tổng khoảng cách theo cặp giữa chúng là nhỏ nhất.

Trên thực tế, để giải quyết bài toán này, thuật toán vẫn giữ nguyên: chúng ta chia trường thành hai nửa của đường thẳng đứng, gọi giải pháp đệ quy trên cả hai nửa, chọn $minper$ tối thiểu từ chu vi đã tìm, xây dựng một dải có độ dày là $minper / 2$ và lặp lại tất cả các tam giác có thể cải thiện câu trả lời. (Lưu ý rằng tam giác có chu vi $\le minper$ có cạnh dài nhất $\le minper / 2$.)

## Bài tập thực hành

* [UVA 10245 "The Closest Pair Problem" [độ khó: thấp]](https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1186)
* [SPOJ #8725 CLOPPAIR "Closest Point Pair" [độ khó: thấp]](https://www.spoj.com/problems/CLOPPAIR/)
* [CODEFORCES Team Olympiad Saratov - 2011 "Số tiền tối thiểu" [độ khó: trung bình]](http://codeforces.com/contest/120/problem/J)
* [Google CodeJam 2009 Final " Min Perimeter "[độ khó: trung bình]](https://code.google.com/codejam/contest/311101/dashboard#s=a&a=1)
* [SPOJ #7029 CLOSEST "Closest Triple" [độ khó: trung bình]](https://www.spoj.com/problems/CLOSEST/)
* [TIMUS 1514 Công viên quốc gia [độ khó: trung bình]](https://acm.timus.ru/problem.aspx?space=1&num=1514)

--- 


