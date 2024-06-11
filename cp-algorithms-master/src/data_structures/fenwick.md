---
tags:
  - Đã dịch
e_maxx_link: fenwick_tree
---

# Fenwick Tree

Cho $f$ là một phép toán nhóm (hàm kết hợp nhị phân trên một tập hợp có phần tử đơn vị và phần tử nghịch đảo) và $A$ là một mảng số nguyên có độ dài $N$.

Fenwick Tree là một cấu trúc dữ liệu mà:

* tính giá trị của hàm $f$ trong một đoạn cho trước $[l, r]$ (ví dụ $f(A_l, A_{l+1}, \dots, A_r)$) trong thời gian $O(\log N)$;
* cập nhật giá trị của một phần tử của $A$ trong thời gian $O(\log N)$;
* yêu cầu bộ nhớ $O(N)$, hay nói cách khác, chính xác bằng bộ nhớ cần thiết cho $A$;
* dễ sử dụng và lập trình, đặc biệt là trong trường hợp mảng nhiều chiều.

Ứng dụng phổ biến nhất của cây Fenwick là _tính tổng của một đoạn_ (ví dụ sử dụng phép cộng trên tập hợp các số nguyên $\mathbb{Z}$: $f(A_1, A_2, \dots, A_k) = A_1 + A_2 + \dots + A_k$).

Fenwick Tree còn được gọi là **Cây chỉ mục nhị phân**, hay viết tắt là **BIT**.

Fenwick Tree được mô tả lần đầu tiên trong một bài báo có tiêu đề "Cấu trúc dữ liệu mới cho bảng tần số tích lũy" (Peter M. Fenwick, 1994).

## Mô tả

### Tổng quan

Để cho đơn giản, chúng ta sẽ giả sử rằng hàm $f$ chỉ là một *hàm tính tổng*.

Cho một mảng số nguyên $A[0 \dots N-1]$.
Fenwick Tree chỉ là một mảng $T[0 \dots N-1]$, trong đó mỗi phần tử của nó bằng tổng các phần tử của $A$ trong một đoạn $[g(i), i]$:

$$T_i = \sum_{j = g(i)}^{i}{A_j},$$

trong đó $g$ là một hàm nào đó thỏa mãn $0 \le g(i) \le i$.
Chúng ta sẽ định nghĩa hàm này trong một vài đoạn tiếp theo.

Cấu trúc dữ liệu được gọi là cây, bởi vì có một biểu diễn đẹp mắt về cấu trúc dữ liệu dưới dạng cây, mặc dù chúng ta không cần phải mô hình hóa một cây thực sự với các nút và cạnh.
Chúng ta sẽ chỉ cần duy trì mảng $T$ để xử lý tất cả các truy vấn.

**Lưu ý:** Fenwick Tree được trình bày ở đây sử dụng chỉ mục dựa trên 0.
Nhiều người thực sự sẽ sử dụng phiên bản cây Fenwick sử dụng chỉ mục dựa trên 1.
Do đó, bạn cũng sẽ tìm thấy một cách triển khai thay thế sử dụng chỉ mục dựa trên 1 trong phần triển khai.
Cả hai phiên bản đều tương đương về độ phức tạp thời gian và bộ nhớ.

Bây giờ chúng ta có thể viết một số mã giả cho hai thao tác được đề cập ở trên - lấy tổng các phần tử của $A$ trong đoạn $[0, r]$ và cập nhật (tăng) một phần tử $A_i$:

```python
def sum(int r):
    res = 0
    while (r >= 0):
        res += t[r]
        r = g(r) - 1
    return res

def increase(int i, int delta):
    for all j with g(j) <= i <= j:
        t[j] += delta
```

Hàm `sum` hoạt động như sau:

1. đầu tiên, nó cộng tổng của đoạn $[g(r), r]$ (ví dụ $T[r]$) vào `result`
2. sau đó, nó "nhảy" đến đoạn $[g(g(r)-1), g(r)-1]$, và cộng tổng của đoạn này vào `result`
3. và cứ như vậy, cho đến khi nó "nhảy" từ $[0, g(g( \dots g(r)-1 \dots -1)-1)]$ đến $[g(-1), -1]$; đó là nơi hàm `sum` dừng nhảy.

Hàm `increase` hoạt động với cách thức tương tự, nhưng "nhảy" theo hướng tăng dần chỉ mục:

1. tổng của các đoạn $[g(j), j]$ thỏa mãn điều kiện $g(j) \le i \le j$ được tăng lên `delta` , tức là `t[j] += delta`. Do đó, chúng ta đã cập nhật tất cả các phần tử trong $T$ tương ứng với các đoạn mà $A_i$ nằm trong đó.

Rõ ràng là độ phức tạp của cả `sum` và `increase` phụ thuộc vào hàm $g$.
Có rất nhiều cách để chọn hàm $g$, miễn là $0 \le g(i) \le i$ với mọi $i$.
Ví dụ, hàm $g(i) = i$ hoạt động, dẫn đến $T = A$, và do đó các truy vấn tính tổng sẽ chậm.
Chúng ta cũng có thể lấy hàm $g(i) = 0$.
Điều này sẽ tương ứng với mảng tổng tiền tố, có nghĩa là việc tìm tổng của đoạn $[0, i]$ sẽ chỉ mất thời gian không đổi, nhưng việc cập nhật sẽ chậm.
Phần thông minh của thuật toán Fenwick là, nó sử dụng một định nghĩa đặc biệt của hàm $g$ có thể xử lý cả hai thao tác trong thời gian $O(\log N)$.

### Định nghĩa của $g(i)$ { data-toc-label='Định nghĩa của <script type="math/tex">g(i)</script>' }

Việc tính toán $g(i)$ được định nghĩa bằng cách sử dụng thao tác đơn giản sau:
chúng ta thay thế tất cả các bit $1$ ở cuối trong biểu diễn nhị phân của $i$ bằng các bit $0$.

Nói cách khác, nếu chữ số có nghĩa nhỏ nhất của $i$ ở dạng nhị phân là $0$, thì $g(i) = i$.
Và ngược lại, chữ số có nghĩa nhỏ nhất là $1$, và chúng ta lấy số $1$ này và tất cả các số $1$ ở cuối khác và lật chúng.

Ví dụ: chúng ta nhận được

$$\begin{align}
g(11) = g(1011_2) = 1000_2 &= 8 \\\\
g(12) = g(1100_2) = 1100_2 &= 12 \\\\
g(13) = g(1101_2) = 1100_2 &= 12 \\\\
g(14) = g(1110_2) = 1110_2 &= 14 \\\\
g(15) = g(1111_2) = 0000_2 &= 0 \\\\
\end{align}$$

Có một cách triển khai đơn giản sử dụng các phép toán bit cho thao tác không tầm thường được mô tả ở trên:

$$g(i) = i ~\&~ (i+1),$$

trong đó $\&$ là toán tử AND bit. Không khó để tự mình tin rằng giải pháp này cũng thực hiện điều tương tự như thao tác được mô tả ở trên.

Bây giờ, chúng ta chỉ cần tìm cách lặp qua tất cả các $j$, sao cho $g(j) \le i \le j$.

Dễ dàng nhận thấy rằng chúng ta có thể tìm thấy tất cả các $j$ như vậy bằng cách bắt đầu bằng $i$ và lật bit không được đặt cuối cùng.
Chúng ta sẽ gọi thao tác này là $h(j)$.
Ví dụ: đối với $i = 10$, chúng ta có:

$$\begin{align}
10 &= 0001010_2 \\\\
h(10) = 11 &= 0001011_2 \\\\
h(11) = 15 &= 0001111_2 \\\\
h(15) = 31 &= 0011111_2 \\\\
h(31) = 63 &= 0111111_2 \\\\
\vdots &
\end{align}$$

Không có gì ngạc nhiên, cũng có một cách đơn giản để thực hiện $h$ bằng cách sử dụng các phép toán bit:

$$h(j) = j ~\|~ (j+1),$$

trong đó $\|$ là toán tử OR bit.

Hình ảnh sau đây cho thấy cách giải thích khả dĩ về cây Fenwick dưới dạng cây.
Các nút của cây cho thấy phạm vi mà chúng bao phủ.

![Cây chỉ mục nhị phân](https://hackmd.io/_uploads/SyibUP0X0.png)

## Triển khai

### Tìm tổng trong mảng một chiều

Ở đây, chúng tôi trình bày cách triển khai cây Fenwick cho các truy vấn tổng và cập nhật đơn lẻ.

Fenwick Tree thông thường chỉ có thể trả lời các truy vấn tổng của loại $[0, r]$ bằng cách sử dụng `sum(int r)`, tuy nhiên chúng ta cũng có thể trả lời các truy vấn khác của loại $[l, r]$ bằng cách tính toán hai tổng $[0, r]$ và $[0, l-1]$ và trừ chúng cho nhau.
Điều này được xử lý trong phương thức `sum(int l, int r)`.

Ngoài ra, triển khai này hỗ trợ hai hàm tạo.
Bạn có thể tạo một cây Fenwick được khởi tạo bằng số không hoặc bạn có thể chuyển đổi một mảng hiện có thành dạng Fenwick.


```{.cpp file=fenwick_sum}
struct FenwickTree {
    vector<int> bit;  // cây chỉ mục nhị phân
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> const &a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};
```

### Xây dựng tuyến tính

Việc triển khai ở trên yêu cầu thời gian $O(N \log N)$.
Có thể cải thiện điều đó thành thời gian $O(N)$.

Ý tưởng là, số $a[i]$ tại chỉ mục $i$ sẽ đóng góp vào phạm vi được lưu trữ trong $bit[i]$ và cho tất cả các phạm vi mà chỉ mục $i | (i + 1)$ đóng góp vào.
Vì vậy, bằng cách thêm các số theo thứ tự, bạn chỉ cần đẩy tổng hiện tại đến phạm vi tiếp theo, sau đó nó sẽ được đẩy đến phạm vi tiếp theo, v.v.

```cpp
FenwickTree(vector<int> const &a) : FenwickTree(a.size()){
    for (int i = 0; i < n; i++) {
        bit[i] += a[i];
        int r = i | (i + 1);
        if (r < n) bit[r] += bit[i];
    }
}
```

### Tìm giá trị nhỏ nhất của $[0, r]$ trong mảng một chiều { data-toc-label='Tìm giá trị nhỏ nhất của <script type="math/tex">[0, r]</script> trong mảng một chiều' }

Rõ ràng là không có cách nào dễ dàng để tìm giá trị nhỏ nhất của đoạn $[l, r]$ bằng cách sử dụng cây Fenwick, vì cây Fenwick chỉ có thể trả lời các truy vấn thuộc loại $[0, r]$.
Ngoài ra, mỗi khi một giá trị được `cập nhật`, giá trị mới phải nhỏ hơn giá trị hiện tại.
Cả hai hạn chế đáng kể là do phép toán $min$ cùng với tập hợp các số nguyên không tạo thành một nhóm, vì không có phần tử nghịch đảo.

```{.cpp file=fenwick_min}
struct FenwickTreeMin {
    vector<int> bit;
    int n;
    const int INF = (int)1e9;

    FenwickTreeMin(int n) {
        this->n = n;
        bit.assign(n, INF);
    }

    FenwickTreeMin(vector<int> a) : FenwickTreeMin(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            update(i, a[i]);
    }

    int getmin(int r) {
        int ret = INF;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret = min(ret, bit[r]);
        return ret;
    }

    void update(int idx, int val) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] = min(bit[idx], val);
    }
};
```

Lưu ý: có thể triển khai một cây Fenwick có thể xử lý các truy vấn đoạn nhỏ nhất tùy ý và các cập nhật tùy ý.
Bài báo [Các truy vấn đoạn nhỏ nhất hiệu quả bằng cách sử dụng cây chỉ mục nhị phân](http://ioinformatics.org/oi/pdf/v9_2015_39_44.pdf) mô tả một cách tiếp cận như vậy.
Tuy nhiên, với cách tiếp cận đó, bạn cần duy trì một cây chỉ mục nhị phân thứ hai trên dữ liệu, với cấu trúc hơi khác một chút, vì một cây là không đủ để lưu trữ giá trị của tất cả các phần tử trong mảng.
Việc triển khai cũng khó hơn rất nhiều so với triển khai thông thường cho tổng.

### Tìm tổng trong mảng hai chiều

Như đã khẳng định trước đó, rất dễ dàng để triển khai Fenwick Tree cho mảng nhiều chiều.

```cpp
struct FenwickTree2D {
    vector<vector<int>> bit;
    int n, m;

    // init(...) { ... }

    int sum(int x, int y) {
        int ret = 0;
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
            for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
                ret += bit[i][j];
        return ret;
    }

    void add(int x, int y, int delta) {
        for (int i = x; i < n; i = i | (i + 1))
            for (int j = y; j < m; j = j | (j + 1))
                bit[i][j] += delta;
    }
};
```

### Cách tiếp cận chỉ mục dựa trên một

Đối với cách tiếp cận này, chúng tôi thay đổi các yêu cầu và định nghĩa cho $T[]$ và $g()$ một chút.
Chúng tôi muốn $T[i]$ lưu trữ tổng của $[g(i)+1; i]$.
Điều này thay đổi việc triển khai một chút và cho phép định nghĩa đẹp mắt tương tự cho $g(i)$:

```python
def sum(int r):
    res = 0
    while (r > 0):
        res += t[r]
        r = g(r)
    return res

def increase(int i, int delta):
    for all j with g(j) < i <= j:
        t[j] += delta
```

Việc tính toán $g(i)$ được định nghĩa là:
chuyển đổi bit $1$ cuối cùng được đặt trong biểu diễn nhị phân của $i$.

$$\begin{align}
g(7) = g(111_2) = 110_2 &= 6 \\\\
g(6) = g(110_2) = 100_2 &= 4 \\\\
g(4) = g(100_2) = 000_2 &= 0 \\\\
\end{align}$$

Bit được đặt cuối cùng có thể được trích xuất bằng $i ~\&~ (-i)$, vì vậy phép toán có thể được biểu thị là:

$$g(i) = i - (i ~\&~ (-i)).$$

Và không khó để nhận thấy, bạn cần thay đổi tất cả các giá trị $T[j]$ trong chuỗi $i,~ h(i),~ h(h(i)),~ \dots$ khi bạn muốn cập nhật $A[j]$, trong đó $h(i)$ được định nghĩa là:

$$h(i) = i + (i ~\&~ (-i)).$$

Như bạn có thể thấy, lợi ích chính của cách tiếp cận này là các phép toán nhị phân bổ sung cho nhau rất đẹp mắt.

Việc triển khai sau đây có thể được sử dụng giống như các triển khai khác, tuy nhiên, nó sử dụng chỉ mục dựa trên một trong nội bộ.

```{.cpp file=fenwick_sum_onebased}
struct FenwickTreeOneBasedIndexing {
    vector<int> bit;  // cây chỉ mục nhị phân
    int n;

    FenwickTreeOneBasedIndexing(int n) {
        this->n = n + 1;
        bit.assign(n + 1, 0);
    }

    FenwickTreeOneBasedIndexing(vector<int> a)
        : FenwickTreeOneBasedIndexing(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int idx) {
        int ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (++idx; idx < n; idx += idx & -idx)
            bit[idx] += delta;
    }
};
```

## Thao tác trên đoạn

Fenwick Tree có thể hỗ trợ các thao tác trên đoạn sau:

1. Cập nhật điểm và Truy vấn đoạn
2. Cập nhật đoạn và Truy vấn điểm
3. Cập nhật đoạn và Truy vấn đoạn

### 1. Cập nhật điểm và Truy vấn đoạn

Đây chỉ là cây Fenwick thông thường như đã giải thích ở trên.

### 2. Cập nhật đoạn và Truy vấn điểm

Sử dụng các thủ thuật đơn giản, chúng ta cũng có thể thực hiện các thao tác ngược lại: tăng các đoạn và truy vấn cho các giá trị đơn lẻ.

Cho cây Fenwick được khởi tạo bằng số không.
Giả sử rằng chúng ta muốn tăng đoạn $[l, r]$ lên $x$.
Chúng ta thực hiện hai thao tác cập nhật điểm trên cây Fenwick là `add(l, x)` và `add(r+1, -x)`.

Nếu chúng ta muốn lấy giá trị của $A[i]$, chúng ta chỉ cần lấy tổng tiền tố bằng phương pháp tính tổng đoạn thông thường.
Để xem tại sao điều này đúng, chúng ta có thể chỉ cần tập trung vào thao tác tăng trước đó một lần nữa.
Nếu $i < l$, thì hai thao tác cập nhật không ảnh hưởng đến truy vấn và chúng ta nhận được tổng $0$.
Nếu $i \in [l, r]$, thì chúng ta nhận được câu trả lời $x$ do thao tác cập nhật đầu tiên.
Và nếu $i > r$, thì thao tác cập nhật thứ hai sẽ hủy bỏ tác động của thao tác đầu tiên.

Việc triển khai sau đây sử dụng chỉ mục dựa trên một.

```cpp
void add(int idx, int val) {
    for (++idx; idx < n; idx += idx & -idx)
        bit[idx] += val;
}

void range_add(int l, int r, int val) {
    add(l, val);
    add(r + 1, -val);
}

int point_query(int idx) {
    int ret = 0;
    for (++idx; idx > 0; idx -= idx & -idx)
        ret += bit[idx];
    return ret;
}
```

Lưu ý: tất nhiên cũng có thể tăng một điểm $A[i]$ với `range_add(i, i, val)`.

### 3. Cập nhật đoạn và Truy vấn đoạn

Để hỗ trợ cả cập nhật đoạn và truy vấn đoạn, chúng ta sẽ sử dụng hai BIT là $B_1[]$ và $B_2[]$, được khởi tạo bằng số không.

Giả sử rằng chúng ta muốn tăng đoạn $[l, r]$ lên giá trị $x$.
Tương tự như phương pháp trước, chúng ta thực hiện hai thao tác cập nhật điểm trên $B_1$: `add(B1, l, x)` và `add(B1, r+1, -x)`.
Và chúng ta cũng cập nhật $B_2$. Chi tiết sẽ được giải thích sau.

```python
def range_add(l, r, x):
    add(B1, l, x)
    add(B1, r+1, -x)
    add(B2, l, x*(l-1))
    add(B2, r+1, -x*r))
```
Sau khi cập nhật đoạn $(l, r, x)$, truy vấn tổng đoạn sẽ trả về các giá trị sau:

$$
sum[0, i]=
\begin{cases}
0 & i < l \\\\
x \cdot (i-(l-1)) & l \le i \le r \\\\
x \cdot (r-l+1) & i > r \\\\
\end{cases}
$$

Chúng ta có thể viết tổng đoạn dưới dạng hiệu của hai số hạng, trong đó chúng ta sử dụng $B_1$ cho số hạng thứ nhất và $B_2$ cho số hạng thứ hai.
Hiệu của các truy vấn sẽ cho chúng ta tổng tiền tố trên $[0, i]$.

$$\begin{align}
sum[0, i] &= sum(B_1, i) \cdot i - sum(B_2, i) \\\\
&= \begin{cases}
0 \cdot i - 0 & i < l\\\\
x \cdot i - x \cdot (l-1) & l \le i \le r \\\\
0 \cdot i - (x \cdot (l-1) - x \cdot r) & i > r \\\\
\end{cases}
\end{align}
$$

Biểu thức cuối cùng chính xác bằng các số hạng cần thiết.
Do đó, chúng ta có thể sử dụng $B_2$ để loại bỏ các số hạng thừa khi chúng ta nhân $B_1[i]\times i$.

Chúng ta có thể tìm tổng đoạn tùy ý bằng cách tính tổng tiền tố cho $l-1$ và $r$ và lấy hiệu của chúng một lần nữa.

```python
def add(b, idx, x):
    while idx <= N:
        b[idx] += x
        idx += idx & -idx

def range_add(l,r,x):
    add(B1, l, x)
    add(B1, r+1, -x)
    add(B2, l, x*(l-1))
    add(B2, r+1, -x*r)

def sum(b, idx):
    total = 0
    while idx > 0:
        total += b[idx]
        idx -= idx & -idx
    return total

def prefix_sum(idx):
    return sum(B1, idx)*idx -  sum(B2, idx)

def range_sum(l, r):
    return prefix_sum(r) - prefix_sum(l-1)
```

## Bài tập thực hành

* [UVA 12086 - Potentiometers](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3238)
* [LOJ 1112 - Curious Robin Hood](http://www.lightoj.com/volume_showproblem.php?problem=1112)
* [LOJ 1266 - Points in Rectangle](http://www.lightoj.com/volume_showproblem.php?problem=1266 "Fenwick Tree 2D")
* [Codechef - SPREAD](http://www.codechef.com/problems/SPREAD)
* [SPOJ - CTRICK](http://www.spoj.com/problems/CTRICK/)
* [SPOJ - MATSUM](http://www.spoj.com/problems/MATSUM/)
* [SPOJ - DQUERY](http://www.spoj.com/problems/DQUERY/)
* [SPOJ - NKTEAM](http://www.spoj.com/problems/NKTEAM/)
* [SPOJ - YODANESS](http://www.spoj.com/problems/YODANESS/)
* [SRM 310 - FloatingMedian](https://community.topcoder.com/stat?c=problem_statement&pm=6551&rd=9990)
* [SPOJ - Ada and Behives](http://www.spoj.com/problems/ADABEHIVE/)
* [Hackerearth - Counting in Byteland](https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/counting-in-byteland/)
* [DevSkill - Shan and String (lưu trữ)](http://web.archive.org/web/20210322010617/https://devskill.com/CodingProblems/ViewProblem/300)
* [Codeforces - Little Artem and Time Machine](http://codeforces.com/contest/669/problem/E)
* [Codeforces - Hanoi Factory](http://codeforces.com/contest/777/problem/E)
* [SPOJ - Tulip and Numbers](http://www.spoj.com/problems/TULIPNUM/)
* [SPOJ - SUMSUM](http://www.spoj.com/problems/SUMSUM/)
* [SPOJ - Sabir and Gifts](http://www.spoj.com/problems/SGIFT/)
* [SPOJ - The Permutation Game Again](http://www.spoj.com/problems/TPGA/)
* [SPOJ - Zig when you Zag](http://www.spoj.com/problems/ZIGZAG2/)
* [SPOJ - Cryon](http://www.spoj.com/problems/CRAYON/)
* [SPOJ - Weird Points](http://www.spoj.com/problems/DCEPC705/)
* [SPOJ - Its a Murder](http://www.spoj.com/problems/DCEPC206/)
* [SPOJ - Bored of Suffixes and Prefixes](http://www.spoj.com/problems/KOPC12G/)
* [SPOJ - Mega Inversions](http://www.spoj.com/problems/TRIPINV/)
* [Codeforces - Subsequences](http://codeforces.com/contest/597/problem/C)
* [Codeforces - Ball](http://codeforces.com/contest/12/problem/D)
* [GYM - The Kamphaeng Phet's Chedis](http://codeforces.com/gym/101047/problem/J)
* [Codeforces - Garlands](http://codeforces.com/contest/707/problem/E)
* [Codeforces - Inversions after Shuffle](http://codeforces.com/contest/749/problem/E)
* [GYM - Cairo Market](http://codeforces.com/problemset/gymProblem/101055/D)
* [Codeforces - Goodbye Souvenir](http://codeforces.com/contest/849/problem/E)
* [SPOJ - Ada and Species](http://www.spoj.com/problems/ADACABAA/)
* [Codeforces - Thor](https://codeforces.com/problemset/problem/704/A)
* [CSES - Forest Queries II](https://cses.fi/problemset/task/1739/)
* [Latin American Regionals 2017 - Fundraising](http://matcomgrader.com/problem/9346/fundraising/)

## Nguồn khác

* [Fenwick Tree trên Wikipedia](http://en.wikipedia.org/wiki/Fenwick_tree)
* [Hướng dẫn về cây chỉ mục nhị phân trên TopCoder](https://www.topcoder.com/community/data-science/data-science-tutorials/binary-indexed-trees/)
* [Cập nhật và truy vấn đoạn](https://programmingcontests.quora.com/Tutorial-Range-Updates-in-Fenwick-Tree)
