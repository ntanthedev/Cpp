# Treap (Cây Descartes)

---
tags:
  - Dịch
e_maxx_link: treap
---

# Treap (Cây Descartes - Cartesian tree)

Treap là một cấu trúc dữ liệu kết hợp cây nhị phân tìm kiếm (BST - Binary Search Tree) và heap nhị phân (do đó có tên: tree + heap $\Rightarrow$ Treap).

Cụ thể hơn, Treap là một cấu trúc dữ liệu lưu trữ các cặp $(X, Y)$ trong một cây nhị phân theo cách sao cho nó là một cây nhị phân tìm kiếm theo $X$ và một heap nhị phân theo $Y$.
Nếu một số nút của cây chứa các giá trị $(X_0, Y_0)$, tất cả các nút trong cây con bên trái có $X \leq X_0$, tất cả các nút trong cây con bên phải có $X_0 \leq X$ và tất cả các nút trong cả cây con bên trái và bên phải đều có $Y \leq Y_0$.

Treap cũng thường được gọi là "cây Descartes" (Cartesian tree), vì nó dễ dàng được nhúng vào mặt phẳng Descartes:

<center>
<img src="https://upload.wikimedia.org/wikipedia/commons/e/e4/Treap.svg" width="350px"/>
</center>

Treap đã được đề xuất bởi Raimund Siedel và Cecilia Aragon vào năm 1989.

## Ưu điểm của cách tổ chức dữ liệu như vậy

Trong cách triển khai như vậy, các giá trị $X$ là các khóa (và đồng thời là các giá trị được lưu trữ trong Treap) và các giá trị $Y$ được gọi là **ưu tiên** (priorities). Nếu không có các ưu tiên, Treap sẽ là một cây nhị phân tìm kiếm thông thường theo $X$ và một tập hợp các giá trị $X$ có thể tương ứng với rất nhiều cây khác nhau, một số trong số đó bị thoái hóa (ví dụ: ở dạng danh sách liên kết) và do đó cực kỳ chậm (các thao tác chính sẽ có độ phức tạp $O(N)$).

Đồng thời, **các ưu tiên** (khi chúng là duy nhất) cho phép chỉ định **duy nhất** cây sẽ được xây dựng (tất nhiên, nó không phụ thuộc vào thứ tự mà các giá trị được thêm vào), điều này có thể được chứng minh bằng cách sử dụng định lý tương ứng. Rõ ràng, nếu bạn **chọn các ưu tiên một cách ngẫu nhiên**, bạn sẽ nhận được các cây không thoái hóa trung bình, điều này sẽ đảm bảo độ phức tạp $O(\log N)$ cho các thao tác chính. Do đó, một tên khác của cấu trúc dữ liệu này - **cây tìm kiếm nhị phân ngẫu nhiên**.

## Các thao tác

Treap cung cấp các thao tác sau:

- **Chèn (X, Y)** trong $O(\log N)$.
  Thêm một nút mới vào cây. Một biến thể khả thi là chỉ truyền $X$ và tạo $Y$ ngẫu nhiên bên trong thao tác.
- **Tìm kiếm (X)** trong $O(\log N)$.
  Tìm kiếm một nút có giá trị khóa được chỉ định là $X$. Việc triển khai giống như đối với cây tìm kiếm nhị phân thông thường.
- **Xóa (X)** trong $O(\log N)$.
  Tìm kiếm một nút có giá trị khóa được chỉ định là $X$ và xóa nó khỏi cây.
- **Xây dựng ($X_1$, ..., $X_N$)** trong $O(N)$.
  Xây dựng một cây từ một danh sách các giá trị. Điều này có thể được thực hiện trong thời gian tuyến tính (giả sử rằng $X_1, ..., X_N$ được sắp xếp).
- **Hợp nhất ($T_1$, $T_2$)** trong $O(M \log (N/M))$.
  Hợp nhất hai cây, giả sử rằng tất cả các phần tử đều khác nhau. Có thể đạt được cùng một độ phức tạp nếu các phần tử trùng lặp bị xóa trong quá trình hợp nhất.
- **Giao ($T_1$, $T_2$)** trong $O(M \log (N/M))$.
  Tìm giao điểm của hai cây (tức là các phần tử chung của chúng). Chúng ta sẽ không xem xét việc triển khai thao tác này ở đây.

Ngoài ra, do Treap là một cây tìm kiếm nhị phân, nên nó có thể thực hiện các thao tác khác, chẳng hạn như tìm phần tử lớn thứ $K$ hoặc tìm chỉ mục của một phần tử.

## Mô tả triển khai

Về mặt triển khai, mỗi nút chứa $X$, $Y$ và các con trỏ đến các con trái ($L$) và phải ($R$).

Chúng ta sẽ triển khai tất cả các thao tác cần thiết chỉ bằng hai thao tác phụ trợ: Chia (Split) và Hợp nhất (Merge).

### Chia (Split)

<center>
<img src="https://upload.wikimedia.org/wikipedia/commons/6/69/Treap_split.svg" width="450px"/>
</center>

**Chia ($T$, $X$)** tách cây $T$ thành 2 cây con $L$ và $R$ (là giá trị trả về của chia) sao cho $L$ chứa tất cả các phần tử có khóa $X_L \le X$ và $R$ chứa tất cả các phần tử có khóa $X_R > X$. Thao tác này có độ phức tạp $O(\log N)$ và được triển khai bằng cách sử dụng đệ quy thuần túy:

1. Nếu giá trị của nút gốc (R) là $\le X$, thì `L` sẽ ít nhất bao gồm `R->L` và `R`. Sau đó, chúng ta gọi chia trên `R->R`, và lưu ý kết quả chia của nó là `L'` và `R'`. Cuối cùng, `L` cũng sẽ chứa `L'`, trong khi `R = R'`.
2. Nếu giá trị của nút gốc (R) là $> X$, thì `R` sẽ ít nhất bao gồm `R` và `R->R`. Sau đó, chúng ta gọi chia trên `R->L`, và lưu ý kết quả chia của nó là `L'` và `R'`. Cuối cùng, `L=L'`, trong khi `R` cũng sẽ chứa `R'`.

Do đó, thuật toán chia là:

1. quyết định nút gốc sẽ thuộc về cây con nào (trái hoặc phải)
2. gọi đệ quy chia trên một trong các con của nó
3. tạo kết quả cuối cùng bằng cách sử dụng lại lệnh gọi chia đệ quy.

### Hợp nhất (Merge)

<center>
<img src="https://upload.wikimedia.org/wikipedia/commons/a/a8/Treap_merge.svg" width="500px"/>
</center>

**Hợp nhất ($T_1$, $T_2$)** kết hợp hai cây con $T_1$ và $T_2$ và trả về cây mới. Thao tác này cũng có độ phức tạp $O(\log N)$. Nó hoạt động với giả định rằng $T_1$ và $T_2$ được sắp xếp (tất cả các khóa $X$ trong $T_1$ đều nhỏ hơn các khóa trong $T_2$). Do đó, chúng ta cần kết hợp các cây này mà không vi phạm thứ tự ưu tiên $Y$. Để thực hiện việc này, chúng ta chọn làm gốc cây có mức ưu tiên $Y$ cao hơn trong nút gốc và gọi đệ quy Hợp nhất cho cây còn lại và cây con tương ứng của nút gốc đã chọn.

### Chèn (Insert)

<center>
<img src="https://upload.wikimedia.org/wikipedia/commons/3/35/Treap_insert.svg" width="500px"/>
</center>

Bây giờ việc triển khai **Chèn ($X$, $Y$)** trở nên rõ ràng. Đầu tiên, chúng ta đi xuống cây (như trong cây tìm kiếm nhị phân thông thường theo X) và dừng lại ở nút đầu tiên mà giá trị ưu tiên nhỏ hơn $Y$. Chúng ta đã tìm thấy vị trí mà chúng ta sẽ chèn phần tử mới. Tiếp theo, chúng ta gọi **Chia (T, X)** trên cây con bắt đầu từ nút đã tìm và sử dụng các cây con đã trả về $L$ và $R$ làm con trái và phải của nút mới.

Ngoài ra, việc chèn có thể được thực hiện bằng cách chia Treap ban đầu trên $X$ và thực hiện $2$ phép hợp nhất với nút mới (xem hình).


### Xóa (Erase)

<center>
<img src="https://upload.wikimedia.org/wikipedia/commons/6/62/Treap_erase.svg" width="500px"/>
</center>

Việc triển khai **Xóa ($X$)** cũng rõ ràng. Đầu tiên, chúng ta đi xuống cây (như trong cây tìm kiếm nhị phân thông thường theo $X$), tìm kiếm phần tử mà chúng ta muốn xóa. Khi tìm thấy nút, chúng ta gọi **Hợp nhất** trên các con của nó và đặt giá trị trả về của thao tác vào vị trí của phần tử mà chúng ta đang xóa.

Ngoài ra, chúng ta có thể tách cây con chứa $X$ bằng 2 phép toán chia và hợp nhất các Treap còn lại (xem hình).

### Xây dựng (Build)

Chúng ta triển khai thao tác **Xây dựng** với độ phức tạp $O(N \log N)$ bằng cách sử dụng $N$ lệnh gọi **Chèn**.

### Hợp nhất (Union)

**Hợp nhất ($T_1$, $T_2$)** có độ phức tạp lý thuyết $O(M \log (N / M))$, nhưng trong thực tế, nó hoạt động rất tốt, có thể với hằng số ẩn rất nhỏ. Giả sử không mất tính tổng quát rằng $T_1 \rightarrow Y > T_2 \rightarrow Y$, tức là gốc của $T_1$ sẽ là gốc của kết quả. Để có được kết quả, chúng ta cần hợp nhất các cây $T_1 \rightarrow L$, $T_1 \rightarrow R$ và $T_2$ thành hai cây có thể là con của gốc $T_1$. Để thực hiện việc này, chúng ta gọi Chia ($T_2$, $T_1\rightarrow X$), do đó chia $T_2$ thành hai phần L và R, sau đó chúng ta kết hợp đệ quy với các con của $T_1$: Hợp nhất ($T_1 \rightarrow L$, $L$) và Hợp nhất ($T_1 \rightarrow R$, $R$), do đó nhận được các cây con trái và phải của kết quả.

## Triển khai

```cpp
struct item {
	int key, prior;
	item *l, *r;
	item () { }
	item (int key) : key(key), prior(rand()), l(NULL), r(NULL) { }
	item (int key, int prior) : key(key), prior(prior), l(NULL), r(NULL) { }
};
typedef item* pitem;
```

Đây là định nghĩa mục của chúng ta. Lưu ý có hai con trỏ con và một khóa số nguyên (cho BST) và một mức ưu tiên số nguyên (cho heap). Mức ưu tiên được gán bằng cách sử dụng trình tạo số ngẫu nhiên.

```cpp
void split (pitem t, int key, pitem & l, pitem & r) {
	if (!t)
		l = r = NULL;
	else if (t->key <= key)
        split (t->r, key, t->r, r),  l = t;
	else
        split (t->l, key, l, t->l),  r = t;
}
```

`t` là Treap để chia và `key` là giá trị BST để chia theo. Lưu ý rằng chúng ta không `trả về` các giá trị kết quả ở bất kỳ đâu, thay vào đó, chúng ta chỉ sử dụng chúng như sau:

```cpp
pitem l = nullptr, r = nullptr;
split(t, 5, l, r);
if (l) cout << "Kích thước cây con bên trái: " << (l->size) << endl;
if (r) cout << "Kích thước cây con bên phải: " << (r->size) << endl;
```

Hàm `split` này có thể khó hiểu, vì nó có cả con trỏ (`pitem`) cũng như tham chiếu đến các con trỏ đó (`pitem &l`). Chúng ta hãy hiểu bằng lời những gì ý định của hàm gọi `split(t, k, l, r)`: "chia Treap `t` theo giá trị `k` thành hai Treap và lưu trữ Treap bên trái trong `l` và Treap bên phải trong `r`". Tuyệt vời! Bây giờ, chúng ta hãy áp dụng định nghĩa này cho hai lệnh gọi đệ quy, sử dụng trường hợp công việc mà chúng ta đã phân tích trong phần trước: (Điều kiện if đầu tiên là trường hợp cơ bản tầm thường cho Treap rỗng)

1. Khi giá trị nút gốc là $\le$ key, chúng ta gọi `split (t->r, key, t->r, r)`, có nghĩa là: "chia Treap `t->r` (cây con bên phải của `t`) theo giá trị `key` và lưu trữ cây con bên trái trong `t->r` và cây con bên phải trong `r`". Sau đó, chúng ta đặt `l = t`. Lưu ý bây giờ rằng giá trị kết quả `l` chứa `t->l`, `t` cũng như `t->r` (là kết quả của lệnh gọi đệ quy mà chúng ta đã thực hiện) tất cả đã được hợp nhất theo đúng thứ tự! Bạn nên tạm dừng để đảm bảo rằng kết quả của `l` và `r` này tương ứng chính xác với những gì chúng ta đã thảo luận trước đó trong Mô tả triển khai.
2. Khi giá trị nút gốc lớn hơn key, chúng ta gọi `split (t->l, key, l, t->l)`, có nghĩa là: "chia Treap `t->l` (cây con bên trái của `t`) theo giá trị `key` và lưu trữ cây con bên trái trong `l` và cây con bên phải trong `t->l`". Sau đó, chúng ta đặt `r = t`. Lưu ý bây giờ rằng giá trị kết quả `r` chứa `t->l` (là kết quả của lệnh gọi đệ quy mà chúng ta đã thực hiện), `t` cũng như `t->r`, tất cả đã được hợp nhất theo đúng thứ tự! Bạn nên tạm dừng để đảm bảo rằng kết quả của `l` và `r` này tương ứng chính xác với những gì chúng ta đã thảo luận trước đó trong Mô tả triển khai.

Nếu bạn vẫn gặp khó khăn trong việc hiểu cách triển khai, bạn nên xem xét nó một cách _quy nạp_, tức là: *không* cố gắng chia nhỏ các lệnh gọi đệ quy hết lần này đến lần khác. Giả sử cách triển khai chia hoạt động chính xác trên Treap rỗng, sau đó thử chạy nó cho Treap nút đơn, sau đó là Treap hai nút, v.v., mỗi lần sử dụng lại kiến ​​thức của bạn rằng chia trên Treap nhỏ hơn hoạt động.

```cpp
void insert (pitem & t, pitem it) {
	if (!t)
		t = it;
	else if (it->prior > t->prior)
		split (t, it->key, it->l, it->r),  t = it;
	else
		insert (t->key <= it->key ? t->r : t->l, it);
}

void merge (pitem & t, pitem l, pitem r) {
	if (!l || !r)
		t = l ? l : r;
	else if (l->prior > r->prior)
		merge (l->r, l->r, r),  t = l;
	else
		merge (r->l, l, r->l),  t = r;
}

void erase (pitem & t, int key) {
	if (t->key == key) {
		pitem th = t;
		merge (t, t->l, t->r);
		delete th;
	}
	else
		erase (key < t->key ? t->l : t->r, key);
}

pitem unite (pitem l, pitem r) {
	if (!l || !r)  return l ? l : r;
	if (l->prior < r->prior)  swap (l, r);
	pitem lt, rt;
	split (r, l->key, lt, rt);
	l->l = unite (l->l, lt);
	l->r = unite (l->r, rt);
	return l;
}
```

## Duy trì kích thước của cây con

Để mở rộng chức năng của Treap, thường cần phải lưu trữ số lượng nút trong cây con của mỗi nút - trường `int cnt` trong cấu trúc `item`. Ví dụ: nó có thể được sử dụng để tìm phần tử lớn thứ K của cây trong $O(\log N)$, hoặc để tìm chỉ mục của phần tử trong danh sách đã sắp xếp với cùng một độ phức tạp. Việc triển khai các thao tác này sẽ giống như đối với cây tìm kiếm nhị phân thông thường.

Khi một cây thay đổi (các nút được thêm hoặc xóa, v.v.), `cnt` của một số nút sẽ được cập nhật cho phù hợp. Chúng ta sẽ tạo hai hàm: `cnt()` sẽ trả về giá trị hiện tại của `cnt` hoặc 0 nếu nút không tồn tại và `upd_cnt()` sẽ cập nhật giá trị của `cnt` cho nút này giả sử rằng đối với các con L và R của nó, các giá trị của `cnt` đã được cập nhật. Rõ ràng, việc thêm các lệnh gọi của `upd_cnt()` vào cuối `insert`, `erase`, `split` và `merge` là đủ để giữ cho các giá trị `cnt` được cập nhật.

```cpp
int cnt (pitem t) {
	return t ? t->cnt : 0;
}

void upd_cnt (pitem t) {
	if (t)
		t->cnt = 1 + cnt(t->l) + cnt (t->r);
}
```

## Xây dựng Treap trong $O(N)$ ở chế độ ngoại tuyến {data-toc-label="Xây dựng Treap trong O(N) ở chế độ ngoại tuyến"}

Cho một danh sách các khóa đã được sắp xếp, có thể xây dựng Treap nhanh hơn so với việc chèn các khóa từng cái một, mất $O(N \log N)$. Vì các khóa đã được sắp xếp, nên cây tìm kiếm nhị phân cân bằng có thể dễ dàng được xây dựng trong thời gian tuyến tính. Các giá trị heap $Y$ được khởi tạo ngẫu nhiên và sau đó có thể được heap hóa độc lập với các khóa $X$ để [xây dựng heap](https://en.wikipedia.org/wiki/Binary_heap#Building_a_heap) trong $O(N)$.

```cpp
void heapify (pitem t) {
	if (!t) return;
	pitem max = t;
	if (t->l != NULL && t->l->prior > max->prior)
		max = t->l;
	if (t->r != NULL && t->r->prior > max->prior)
		max = t->r;
	if (max != t) {
		swap (t->prior, max->prior);
		heapify (max);
	}
}

pitem build (int * a, int n) {
	// Xây dựng Treap trên các giá trị {a[0], a[1], ..., a[n - 1]}
	if (n == 0) return NULL;
	int mid = n / 2;
	pitem t = new item (a[mid], rand ());
	t->l = build (a, mid);
	t->r = build (a + mid + 1, n - mid - 1);
	heapify (t);
	upd_cnt(t)
	return t;
}
```

Lưu ý: chỉ cần gọi `upd_cnt(t)` nếu bạn cần kích thước cây con.

Cách tiếp cận ở trên luôn cung cấp một cây được cân bằng hoàn hảo, nói chung là tốt cho các mục đích thực tế, nhưng với cái giá là không bảo toàn các mức ưu tiên ban đầu được gán cho mỗi nút. Do đó, cách tiếp cận này không khả thi để giải quyết bài toán sau:

!!! example "[acmsguru - Cartesian Tree](https://codeforces.com/problemsets/acmsguru/problem/99999/155)"
    Cho một chuỗi các cặp $(x_i, y_i)$, hãy xây dựng một cây Descartes trên chúng. Tất cả $x_i$ và tất cả $y_i$ đều là duy nhất.

Lưu ý rằng trong bài toán này, các ưu tiên không phải là ngẫu nhiên, do đó, việc chỉ chèn các đỉnh một cách tuần tự có thể cung cấp một giải pháp bậc hai.

Một trong những giải pháp khả thi ở đây là tìm cho mỗi phần tử các phần tử gần nhất ở bên trái và bên phải có mức ưu tiên nhỏ hơn phần tử này. Trong số hai phần tử này, phần tử có mức ưu tiên lớn hơn phải là cha của phần tử hiện tại.

Bài toán này có thể giải được bằng cách sửa đổi [ngăn xếp tối thiểu](./stack_queue_modification.md) trong thời gian tuyến tính:

```cpp
void connect(auto from, auto to) {
    vector<pitem> st;
    for(auto it: ranges::subrange(from, to)) {
        while(!st.empty() && st.back()->prior > it->prior) {
            st.pop_back();
        }
        if(!st.empty()) {
            if(!it->p || it->p->prior < st.back()->prior) {
                it->p = st.back();
            }
        }
        st.push_back(it);
    }
}

pitem build(int *x, int *y, int n) {
    vector<pitem> nodes(n);
    for(int i = 0; i < n; i++) {
        nodes[i] = new item(x[i], y[i]);
    }
    connect(nodes.begin(), nodes.end());
    connect(nodes.rbegin(), nodes.rend());
    for(int i = 0; i < n; i++) {
        if(nodes[i]->p) {
            if(nodes[i]->p->key < nodes[i]->key) {
                nodes[i]->p->r = nodes[i];
            } else {
                nodes[i]->p->l = nodes[i];
            }
        }
    }
    return nodes[min_element(y, y + n) - y];
}
```

## Treap ngầm định (Implicit Treaps)

Treap ngầm định là một sửa đổi đơn giản của Treap thông thường, là một cấu trúc dữ liệu rất mạnh mẽ. Trên thực tế, Treap ngầm định có thể được coi là một mảng với các thủ tục sau được triển khai (tất cả đều trong $O(\log N)$ ở chế độ trực tuyến):

- Chèn một phần tử vào mảng ở bất kỳ vị trí nào
- Xóa một phần tử tùy ý
- Tìm tổng, phần tử nhỏ nhất / lớn nhất, v.v. trên một khoảng tùy ý
- Phép cộng, tô màu trên một khoảng tùy ý
- Đảo ngược các phần tử trên một khoảng tùy ý

Ý tưởng là các khóa phải là **chỉ số** (indices) dựa trên 0 của các phần tử trong mảng. Nhưng chúng ta sẽ không lưu trữ các giá trị này một cách rõ ràng (nếu không, ví dụ, việc chèn một phần tử sẽ gây ra thay đổi của khóa trong $O(N)$ nút của cây).

Lưu ý rằng khóa của một nút là số lượng nút nhỏ hơn nó (các nút như vậy có thể có mặt không chỉ trong cây con bên trái của nó mà còn trong các cây con bên trái của tổ tiên của nó).
Cụ thể hơn, **khóa ngầm định** (implicit key) cho một số nút T là số lượng đỉnh $cnt (T \rightarrow L)$ trong cây con bên trái của nút này cộng với các giá trị tương tự $cnt (P \rightarrow L) + 1$ cho mỗi tổ tiên P của nút T, nếu T nằm trong cây con bên phải của P.

Bây giờ, rõ ràng là cách tính khóa ngầm định của nút hiện tại một cách nhanh chóng. Vì trong tất cả các thao tác, chúng ta đến bất kỳ nút nào bằng cách đi xuống cây, nên chúng ta có thể chỉ cần tích lũy tổng này và chuyển nó cho hàm. Nếu chúng ta đi đến cây con bên trái, tổng tích lũy không thay đổi, nếu chúng ta đi đến cây con bên phải thì nó tăng thêm $cnt (T \rightarrow L) +1$.

Dưới đây là các cách triển khai mới của **Chia** và **Hợp nhất**:

```cpp
void merge (pitem & t, pitem l, pitem r) {
	if (!l || !r)
		t = l ? l : r;
	else if (l->prior > r->prior)
		merge (l->r, l->r, r),  t = l;
	else
		merge (r->l, l, r->l),  t = r;
	upd_cnt (t);
}

void split (pitem t, pitem & l, pitem & r, int key, int add = 0) {
	if (!t)
		return void( l = r = 0 );
	push (t);
	int cur_key = add + cnt(t->l); // khóa ngầm định
	if (key <= cur_key)
		split (t->l, l, t->l, key, add),  r = t;
	else
		split (t->r, t->r, r, key, add + 1 + cnt(t->l)),  l = t;
	upd_cnt (t);
}
```

Trong cách triển khai ở trên, sau lệnh gọi $split(T, T_1, T_2, k)$, cây $T_1$ sẽ bao gồm $k$ phần tử đầu tiên của $T$ (tức là các phần tử có khóa ngầm định nhỏ hơn $k$) và $T_2$ sẽ bao gồm tất cả phần còn lại.

Bây giờ hãy xem xét việc triển khai các thao tác khác nhau trên Treap ngầm định:

- **Chèn phần tử**.
  Giả sử chúng ta cần chèn một phần tử vào vị trí $pos$. Chúng ta chia Treap thành hai phần, tương ứng với mảng $[0..pos-1]$ và $[pos..sz]$; để làm điều này, chúng ta gọi $split(T, T_1, T_2, pos)$. Sau đó, chúng ta có thể kết hợp cây $T_1$ với đỉnh mới bằng cách gọi $merge(T_1, T_1, \text{mục mới})$ (dễ dàng nhận thấy rằng tất cả các điều kiện tiên quyết đều được đáp ứng). Cuối cùng, chúng ta kết hợp các cây $T_1$ và $T_2$ trở lại thành $T$ bằng cách gọi $merge(T, T_1, T_2)$.
- **Xóa phần tử**.
  Thao tác này thậm chí còn dễ dàng hơn: tìm phần tử cần xóa $T$, thực hiện hợp nhất các con $L$ và $R$ của nó và thay thế phần tử $T$ bằng kết quả của phép hợp nhất. Trên thực tế, việc xóa phần tử trong Treap ngầm định hoàn toàn giống như trong Treap thông thường.
- Tìm **tổng / giá trị nhỏ nhất**, v.v. trên khoảng.
  Đầu tiên, tạo một trường bổ sung $F$ trong cấu trúc `item` để lưu trữ giá trị của hàm mục tiêu cho cây con của nút này. Trường này rất dễ duy trì tương tự như duy trì kích thước của cây con: tạo một hàm tính toán giá trị này cho một nút dựa trên các giá trị cho các con của nó và thêm các lệnh gọi của hàm này vào cuối tất cả các hàm sửa đổi cây.
  Thứ hai, chúng ta cần biết cách xử lý truy vấn cho một khoảng tùy ý $[A; B]$.
  Để có được một phần của cây tương ứng với khoảng $[A; B]$, chúng ta cần gọi $split(T, T_2, T_3, B+1)$, và sau đó là $split(T_2, T_1, T_2, A)$: sau đó $T_2$ sẽ bao gồm tất cả các phần tử trong khoảng $[A; B]$, và chỉ những phần tử đó. Do đó, phản hồi cho truy vấn sẽ được lưu trữ trong trường $F$ của gốc của $T_2$. Sau khi truy vấn được trả lời, cây phải được khôi phục bằng cách gọi $merge(T, T_1, T_2)$ và $merge(T, T, T_3)$.
- **Phép cộng / tô màu** trên khoảng.
  Chúng ta hành động tương tự như đoạn trước, nhưng thay vì trường F, chúng ta sẽ lưu trữ một trường `add` sẽ chứa giá trị được thêm vào cho cây con (hoặc giá trị mà cây con được tô màu). Trước khi thực hiện bất kỳ thao tác nào, chúng ta phải "đẩy" giá trị này một cách chính xác - tức là thay đổi $T \rightarrow L \rightarrow add$ và $T \rightarrow R \rightarrow add$, và dọn dẹp `add` trong nút cha. Bằng cách này, sau khi có bất kỳ thay đổi nào đối với cây, thông tin sẽ không bị mất.
- **Đảo ngược** trên khoảng.
  Điều này một lần nữa tương tự như thao tác trước đó: chúng ta phải thêm cờ boolean `rev` và đặt nó thành true khi cây con của nút hiện tại phải được đảo ngược. "Đẩy" giá trị này hơi phức tạp - chúng ta hoán đổi các con của nút này và đặt cờ này thành true cho chúng.

Dưới đây là ví dụ triển khai Treap ngầm định với đảo ngược trên khoảng. Đối với mỗi nút, chúng ta lưu trữ trường được gọi là `value` là giá trị thực tế của phần tử mảng ở vị trí hiện tại. Chúng ta cũng cung cấp cách triển khai của hàm `output()`, xuất ra một mảng tương ứng với trạng thái hiện tại của Treap ngầm định.

```cpp
typedef struct item * pitem;
struct item {
	int prior, value, cnt;
	bool rev;
	pitem l, r;
};

int cnt (pitem it) {
	return it ? it->cnt : 0;
}

void upd_cnt (pitem it) {
	if (it)
		it->cnt = cnt(it->l) + cnt(it->r) + 1;
}

void push (pitem it) {
	if (it && it->rev) {
		it->rev = false;
		swap (it->l, it->r);
		if (it->l)  it->l->rev ^= true;
		if (it->r)  it->r->rev ^= true;
	}
}

void merge (pitem & t, pitem l, pitem r) {
	push (l);
	push (r);
	if (!l || !r)
		t = l ? l : r;
	else if (l->prior > r->prior)
		merge (l->r, l->r, r),  t = l;
	else
		merge (r->l, l, r->l),  t = r;
	upd_cnt (t);
}

void split (pitem t, pitem & l, pitem & r, int key, int add = 0) {
	if (!t)
		return void( l = r = 0 );
	push (t);
	int cur_key = add + cnt(t->l);
	if (key <= cur_key)
		split (t->l, l, t->l, key, add),  r = t;
	else
		split (t->r, t->r, r, key, add + 1 + cnt(t->l)),  l = t;
	upd_cnt (t);
}

void reverse (pitem t, int l, int r) {
	pitem t1, t2, t3;
	split (t, t1, t2, l);
	split (t2, t2, t3, r-l+1);
	t2->rev ^= true;
	merge (t, t1, t2);
	merge (t, t, t3);
}

void output (pitem t) {
	if (!t)  return;
	push (t);
	output (t->l);
	printf ("%d ", t->value);
	output (t->r);
}
```

## Tài liệu

* [Blelloch, Reid-Miller "Fast Set Operations Using Treaps"](https://www.cs.cmu.edu/~scandal/papers/treaps-spaa98.pdf)

## Bài tập thực hành

* [SPOJ - Ada and Aphids](http://www.spoj.com/problems/ADAAPHID/)
* [SPOJ - Ada and Harvest](http://www.spoj.com/problems/ADACROP/)
* [Codeforces - Radio Stations](http://codeforces.com/contest/762/problem/E)
* [SPOJ - Ghost Town](http://www.spoj.com/problems/COUNT1IT/)
* [SPOJ - Arrangement Validity](http://www.spoj.com/problems/IITWPC4D/)
* [SPOJ - All in One](http://www.spoj.com/problems/ALLIN1/)
* [Codeforces - Dog Show](http://codeforces.com/contest/847/problem/D)
* [Codeforces - Yet Another Array Queries Problem](http://codeforces.com/contest/863/problem/D)
* [SPOJ - Mean of Array](http://www.spoj.com/problems/MEANARR/)
* [SPOJ - TWIST](http://www.spoj.com/problems/TWIST/)
* [SPOJ - KOILINE](http://www.spoj.com/problems/KOILINE/)
* [CodeChef - The Prestige](https://www.codechef.com/problems/PRESTIGE)
* [Codeforces - T-Shirts](https://codeforces.com/contest/702/problem/F)
* [Codeforces - Wizards and Roads](https://codeforces.com/problemset/problem/167/D)
* [Codeforces - Yaroslav and Points](https://codeforces.com/contest/295/problem/E)