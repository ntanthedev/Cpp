# Cây Fenwick (Fenwick Tree)

---
tags:
  - Dịch
e_maxx_link: fenwick_tree
---

# Fenwick Tree

Cho $f$ là một phép toán nhóm (một hàm kết hợp nhị phân trên một tập hợp có phần tử đơn vị và phần tử nghịch đảo) và $A$ là một mảng các số nguyên có độ dài $N$.
Biểu thị ký hiệu trung tố của $f$ là $*$; nghĩa là, $f(x,y) = x*y$ cho các số nguyên $x, y$ tùy ý.
(Vì đây là phép toán kết hợp, chúng ta sẽ bỏ qua dấu ngoặc đơn cho thứ tự áp dụng của $f$ khi sử dụng ký hiệu trung tố.)

Fenwick tree là một cấu trúc dữ liệu:

* tính toán giá trị của hàm $f$ trong phạm vi $[l, r]$ nhất định (tức là $A_l * A_{l+1} * \dots * A_r$) trong thời gian $O(\log N)$
* cập nhật giá trị của một phần tử của $A$ trong thời gian $O(\log N)$
* yêu cầu bộ nhớ $O(N)$ (lượng tương tự cần thiết cho $A$)
* dễ sử dụng và viết mã, đặc biệt là trong trường hợp mảng nhiều chiều

Ứng dụng phổ biến nhất của Fenwick tree là _tính tổng của một phạm vi_.
Ví dụ: sử dụng phép cộng trên tập hợp các số nguyên làm phép toán nhóm, tức là $f(x,y) = x + y$: phép toán nhị phân, $*$, là $+$ trong trường hợp này, vì vậy $A_l * A_{l+1} * \dots * A_r = A_l + A_{l+1} + \dots + A_{r}$.

Fenwick tree còn được gọi là **Cây chỉ mục nhị phân (Binary Indexed Tree - BIT)**.
Nó được mô tả lần đầu tiên trong một bài báo có tiêu đề "A new data structure for cumulative frequency tables" (Peter M. Fenwick, 1994).

## Mô tả

### Tổng quan

Để đơn giản, chúng ta sẽ giả sử rằng hàm $f$ được định nghĩa là $f(x,y) = x + y$ trên các số nguyên.

Giả sử chúng ta được cho một mảng các số nguyên, $A[0 \dots N-1]$.
(Lưu ý rằng chúng ta đang sử dụng chỉ mục dựa trên 0.)
Fenwick tree chỉ là một mảng, $T[0 \dots N-1]$, trong đó mỗi phần tử bằng tổng các phần tử của $A$ trong một phạm vi nhất định, $[g(i), i]$:

$$T_i = \sum_{j = g(i)}^{i}{A_j}$$

trong đó $g$ là một số hàm thỏa mãn $0 \le g(i) \le i$.
Chúng ta sẽ định nghĩa $g$ trong một vài đoạn tiếp theo.

Cấu trúc dữ liệu được gọi là cây vì có một biểu diễn đẹp của nó dưới dạng cây, mặc dù chúng ta không cần phải mô hình hóa một cây thực tế với các nút và cạnh.
Chúng ta chỉ cần duy trì mảng $T$ để xử lý tất cả các truy vấn.

**Lưu ý:** Fenwick tree được trình bày ở đây sử dụng chỉ mục dựa trên 0.
Nhiều người sử dụng phiên bản của Fenwick tree sử dụng chỉ mục dựa trên 1.
Do đó, bạn cũng sẽ tìm thấy một cách triển khai thay thế sử dụng chỉ mục dựa trên 1 trong phần triển khai.
Cả hai phiên bản đều tương đương về độ phức tạp thời gian và bộ nhớ.

Bây giờ chúng ta có thể viết một số mã giả cho hai thao tác được đề cập ở trên.
Dưới đây, chúng ta lấy tổng các phần tử của $A$ trong phạm vi $[0, r]$ và cập nhật (tăng) một số phần tử $A_i$:

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

1. Đầu tiên, nó thêm tổng của phạm vi $[g(r), r]$ (tức là $T[r]$) vào `kết quả`.
2. Sau đó, nó "nhảy" đến phạm vi $[g(g(r)-1), g(r)-1]$ và thêm tổng của phạm vi này vào `kết quả`.
3. Điều này tiếp tục cho đến khi nó "nhảy" từ $[0, g(g( \dots g(r)-1 \dots -1)-1)]$ đến $[g(-1), -1]$; đây là nơi hàm `sum` dừng nhảy.

Hàm `increase` hoạt động với sự tương tự, nhưng nó "nhảy" theo hướng tăng dần các chỉ số:

1. Tổng cho mỗi phạm vi có dạng $[g(j), j]$ thỏa mãn điều kiện $g(j) \le i \le j$ được tăng thêm `delta`; nghĩa là, `t[j] += delta`.
Do đó, nó cập nhật tất cả các phần tử trong $T$ tương ứng với các phạm vi mà $A_i$ nằm trong đó.

Độ phức tạp của cả `sum` và `increase` phụ thuộc vào hàm $g$.
Có nhiều cách để chọn hàm $g$ sao cho $0 \le g(i) \le i$ cho mọi $i$.
Ví dụ: hàm $g(i) = i$ hoạt động, tạo ra $T = A$ (trong trường hợp này, các truy vấn tổng là chậm).
Chúng ta cũng có thể lấy hàm $g(i) = 0$.
Điều này sẽ tương ứng với mảng tổng tiền tố (trong trường hợp này, việc tìm tổng của phạm vi $[0, i]$ sẽ chỉ mất thời gian không đổi; tuy nhiên, việc cập nhật sẽ chậm).
Phần thông minh của thuật toán cho Fenwick tree là cách nó sử dụng định nghĩa đặc biệt của hàm $g$ có thể xử lý cả hai thao tác trong thời gian $O(\log N)$.

### Định nghĩa $g(i)$ { data-toc-label='Definition of <script type="math/tex">g(i)</script>' }

Việc tính toán $g(i)$ được định nghĩa bằng cách sử dụng phép toán đơn giản sau:
chúng ta thay thế tất cả các bit $1$ ở cuối trong biểu diễn nhị phân của $i$ bằng các bit $0$.

Nói cách khác, nếu chữ số ít quan trọng nhất của $i$ trong hệ nhị phân là $0$, thì $g(i) = i$.
Và ngược lại, chữ số ít quan trọng nhất là $1$ và chúng ta lấy $1$ này và tất cả các số $1$ ở cuối khác và lật chúng.

Ví dụ: chúng ta nhận được

$$\begin{align}
g(11) = g(1011_2) = 1000_2 &= 8 \\\\
g(12) = g(1100_2) = 1100_2 &= 12 \\\\
g(13) = g(1101_2) = 1100_2 &= 12 \\\\
g(14) = g(1110_2) = 1110_2 &= 14 \\\\
g(15) = g(1111_2) = 0000_2 &= 0 \\\\
\end{align}$$

Tồn tại một cách triển khai đơn giản sử dụng các phép toán bit cho phép toán không tầm thường được mô tả ở trên:

$$g(i) = i ~\&~ (i+1),$$

trong đó $\&$ là toán tử AND bit. Không khó để tự thuyết phục bản thân rằng giải pháp này làm điều tương tự như thao tác được mô tả ở trên.

Bây giờ, chúng ta chỉ cần tìm cách lặp lại tất cả các $j$, sao cho $g(j) \le i \le j$.

Dễ dàng nhận thấy rằng chúng ta có thể tìm thấy tất cả các $j$ như vậy bằng cách bắt đầu bằng $i$ và lật bit chưa được đặt cuối cùng.
Chúng ta sẽ gọi phép toán này là $h(j)$.
Ví dụ: đối với $i = 10$, chúng ta có:

$$\begin{align}
10 &= 0001010_2 \\\\
h(10) = 11 &= 0001011_2 \\\\
h(11) = 15 &= 0001111_2 \\\\
h(15) = 31 &= 0011111_2 \\\\
h(31) = 63 &= 0111111_2 \\\\
\vdots &
\end{align}$$

Không có gì ngạc nhiên, cũng tồn tại một cách đơn giản để thực hiện $h$ bằng cách sử dụng các phép toán bit:

$$h(j) = j ~\|~ (j+1),$$

trong đó $\|$ là toán tử OR bit.

Hình ảnh sau đây cho thấy một cách giải thích có thể có của Fenwick tree dưới dạng cây.
Các nút của cây hiển thị phạm vi mà chúng bao phủ.

<center>![Binary Indexed Tree](binary_indexed_tree.png)</center>

## Triển khai

### Tìm tổng trong mảng một chiều

Ở đây, chúng ta trình bày cách triển khai Fenwick tree cho các truy vấn tổng và cập nhật đơn lẻ.

Fenwick tree thông thường chỉ có thể trả lời các truy vấn tổng thuộc loại $[0, r]$ bằng cách sử dụng `sum(int r)`, tuy nhiên chúng ta cũng có thể trả lời các truy vấn khác thuộc loại $[l, r]$ bằng cách tính hai tổng $[0, r]$ và $[0, l-1]$ và trừ chúng.
Điều này được xử lý trong phương thức `sum(int l, int r)`.

Ngoài ra, cách triển khai này hỗ trợ hai hàm tạo.
Bạn có thể tạo Fenwick tree được khởi tạo bằng 0 hoặc bạn có thể chuyển đổi một mảng hiện có sang dạng Fenwick tree.


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

Cách triển khai ở trên yêu cầu thời gian $O(N \log N)$.
Có thể cải thiện điều đó thành thời gian $O(N)$.

Ý tưởng là, số $a[i]$ ở chỉ số $i$ sẽ đóng góp vào phạm vi được lưu trữ trong $bit[i]$ và cho tất cả các phạm vi mà chỉ số $i | (i + 1)$ đóng góp vào.
Vì vậy, bằng cách thêm các số theo thứ tự, bạn chỉ cần đẩy tổng hiện tại đi xa hơn đến phạm vi tiếp theo, sau đó nó sẽ được đẩy đi xa hơn đến phạm vi tiếp theo, v.v.

```cpp
FenwickTree(vector<int> const &a) : FenwickTree(a.size()){
    for (int i = 0; i < n; i++) {
        bit[i] += a[i];
        int r = i | (i + 1);
        if (r < n) bit[r] += bit[i];
    }
}
```

### Tìm giá trị nhỏ nhất của $[0, r]$ trong mảng một chiều { data-toc-label='Finding minimum of <script type="math/tex">[0, r]</script> in one-dimensional array' }

Rõ ràng là không có cách nào dễ dàng để tìm giá trị nhỏ nhất của phạm vi $[l, r]$ bằng cách sử dụng Fenwick tree, vì Fenwick tree chỉ có thể trả lời các truy vấn thuộc loại $[0, r]$.
Ngoài ra, mỗi khi một giá trị được `cập nhật`, giá trị mới phải nhỏ hơn giá trị hiện tại.
Cả hai hạn chế đáng kể này là do phép toán $min$ cùng với tập hợp các số nguyên không tạo thành một nhóm, vì không có phần tử nghịch đảo.

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

Lưu ý: có thể triển khai Fenwick tree có thể xử lý các truy vấn phạm vi nhỏ nhất tùy ý và cập nhật tùy ý.
Bài báo [Efficient Range Minimum Queries using Binary Indexed Trees](http://ioinformatics.org/oi/pdf/v9_2015_39_44.pdf) mô tả một cách tiếp cận như vậy.
Tuy nhiên, với cách tiếp cận đó, bạn cần duy trì cây chỉ mục nhị phân thứ hai trên dữ liệu, với cấu trúc hơi khác một chút, vì một cây là không đủ để lưu trữ giá trị của tất cả các phần tử trong mảng.
Việc triển khai cũng khó hơn rất nhiều so với việc triển khai thông thường cho tổng.

### Tìm tổng trong mảng hai chiều

Như đã khẳng định trước đó, việc triển khai Fenwick tree cho mảng nhiều chiều rất dễ dàng.

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

Đối với cách tiếp cận này, chúng ta thay đổi các yêu cầu và định nghĩa cho $T[]$ và $g()$ một chút.
Chúng ta muốn $T[i]$ lưu trữ tổng của $[g(i)+1; i]$.
Điều này thay đổi cách triển khai một chút và cho phép định nghĩa đẹp tương tự cho $g(i)$:

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

Bit cuối cùng được đặt có thể được trích xuất bằng cách sử dụng $i ~\&~ (-i)$, vì vậy phép toán có thể được biểu thị là:

$$g(i) = i - (i ~\&~ (-i)).$$

Và không khó để nhận thấy, bạn cần thay đổi tất cả các giá trị $T[j]$ trong chuỗi $i,~ h(i),~ h(h(i)),~ \dots$ khi bạn muốn cập nhật $A[j]$, trong đó $h(i)$ được định nghĩa là:

$$h(i) = i + (i ~\&~ (-i)).$$

Như bạn có thể thấy, lợi ích chính của cách tiếp cận này là các phép toán nhị phân bổ sung cho nhau rất độc đáo.

Cách triển khai sau đây có thể được sử dụng giống như các cách triển khai khác, tuy nhiên, nó sử dụng chỉ mục dựa trên một trong nội bộ.

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

## Các phép toán trên phạm vi

Fenwick tree có thể hỗ trợ các phép toán trên phạm vi sau:

1. Cập nhật điểm (Point Update) và Truy vấn phạm vi (Range Query)
2. Cập nhật phạm vi (Range Update) và Truy vấn điểm (Point Query)
3. Cập nhật phạm vi (Range Update) và Truy vấn phạm vi (Range Query)

### 1. Cập nhật điểm và Truy vấn phạm vi

Đây chỉ là Fenwick tree thông thường như đã giải thích ở trên.

### 2. Cập nhật phạm vi và Truy vấn điểm

Sử dụng các thủ thuật đơn giản, chúng ta cũng có thể thực hiện các phép toán ngược lại: tăng phạm vi và truy vấn cho các giá trị đơn lẻ.

Cho Fenwick tree được khởi tạo bằng 0.
Giả sử rằng chúng ta muốn tăng khoảng $[l, r]$ thêm $x$.
Chúng ta thực hiện hai thao tác cập nhật điểm trên Fenwick tree là `add(l, x)` và `add(r+1, -x)`.

Nếu chúng ta muốn nhận giá trị của $A[i]$, chúng ta chỉ cần lấy tổng tiền tố bằng cách sử dụng phương thức tổng phạm vi thông thường.
Để xem tại sao điều này là đúng, chúng ta có thể chỉ cần tập trung vào thao tác tăng trước đó một lần nữa.
Nếu $i < l$, thì hai thao tác cập nhật không ảnh hưởng đến truy vấn và chúng ta nhận được tổng $0$.
Nếu $i \in [l, r]$, thì chúng ta nhận được câu trả lời $x$ do thao tác cập nhật đầu tiên.
Và nếu $i > r$, thì thao tác cập nhật thứ hai sẽ hủy bỏ hiệu ứng của thao tác cập nhật thứ nhất.

Cách triển khai sau đây sử dụng chỉ mục dựa trên một.

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

Lưu ý: tất nhiên cũng có thể tăng một điểm duy nhất $A[i]$ bằng `range_add(i, i, val)`.

### 3. Cập nhật phạm vi và Truy vấn phạm vi

Để hỗ trợ cả cập nhật phạm vi và truy vấn phạm vi, chúng ta sẽ sử dụng hai BIT, đó là $B_1[]$ và $B_2[]$, được khởi tạo bằng 0.

Giả sử rằng chúng ta muốn tăng khoảng $[l, r]$ thêm giá trị $x$.
Tương tự như phương pháp trước đó, chúng ta thực hiện hai cập nhật điểm trên $B_1$: `add(B1, l, x)` và `add(B1, r+1, -x)`.
Và chúng ta cũng cập nhật $B_2$. Chi tiết sẽ được giải thích sau.

```python
def range_add(l, r, x):
    add(B1, l, x)
    add(B1, r+1, -x)
    add(B2, l, x*(l-1))
    add(B2, r+1, -x*r))
```
Sau khi cập nhật phạm vi $(l, r, x)$, truy vấn tổng phạm vi sẽ trả về các giá trị sau:

$$
sum[0, i]=
\begin{cases}
0 & i < l \\\\
x \cdot (i-(l-1)) & l \le i \le r \\\\
x \cdot (r-l+1) & i > r \\\\
\end{cases}
$$

Chúng ta có thể viết tổng phạm vi là hiệu của hai số hạng, trong đó chúng ta sử dụng $B_1$ cho số hạng đầu tiên và $B_2$ cho số hạng thứ hai.
Hiệu số của các truy vấn sẽ cho chúng ta tổng tiền tố trên $[0, i]$.

$$\begin{align}
sum[0, i] &= sum(B_1, i) \cdot i - sum(B_2, i) \\\\
&= \begin{cases}
0 \cdot i - 0 & i < l\\\\
x \cdot i - x \cdot (l-1) & l \le i \le r \\\\
0 \cdot i - (x \cdot (l-1) - x \cdot r) & i > r \\\\
\end{cases}
\end{align}
$$

Biểu thức cuối cùng chính xác bằng với các số hạng cần thiết.
Do đó, chúng ta có thể sử dụng $B_2$ để loại bỏ các số hạng thừa khi chúng ta nhân $B_1[i]\times i$.

Chúng ta có thể tìm thấy tổng phạm vi tùy ý bằng cách tính tổng tiền tố cho $l-1$ và $r$ và lấy hiệu của chúng một lần nữa.

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

* [Fenwick tree trên Wikipedia](http://en.wikipedia.org/wiki/Fenwick_tree)
* [Hướng dẫn về cây chỉ mục nhị phân trên TopCoder](https://www.topcoder.com/community/data-science/data-science-tutorials/binary-indexed-trees/)
* [Cập nhật và truy vấn phạm vi](https://programmingcontests.quora.com/Tutorial-Range-Updates-in-Fenwick-Tree)


--- 
