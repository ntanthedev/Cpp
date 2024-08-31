# Bài toán Cái túi (Knapsack Problem)

Kiến thức cần có: [Giới thiệu về Quy hoạch động](https://cp-algorithms.com/dynamic_programming/intro-to-dp.html)

## Giới thiệu
Xét ví dụ sau:

### [[USACO07 Dec] Charm Bracelet](https://www.acmicpc.net/problem/6144)
Có $n$ vật phẩm khác nhau và một cái túi có sức chứa $W$. Mỗi vật phẩm có 2 thuộc tính, trọng lượng ($w_{i}$) và giá trị ($v_{i}$).
Bạn phải chọn một tập hợp con các vật phẩm để cho vào túi sao cho tổng trọng lượng không vượt quá sức chứa $W$ và tổng giá trị được tối đa hóa.

Trong ví dụ trên, mỗi vật phẩm chỉ có hai trạng thái có thể (lấy hoặc không lấy),
tương ứng với nhị phân 0 và 1. Do đó, loại bài toán này được gọi là "bài toán cái túi 0-1".

## Cái túi 0-1 (0-1 Knapsack)

### Giải thích

Trong ví dụ trên, đầu vào của bài toán là: trọng lượng của vật phẩm thứ $i$ $w_{i}$, giá trị của vật phẩm thứ $i$ $v_{i}$ và tổng sức chứa của túi $W$.

Gọi $f_{i, j}$ là trạng thái quy hoạch động chứa tổng giá trị tối đa mà túi có thể mang theo với sức chứa $j$, khi chỉ xem xét $i$ vật phẩm đầu tiên.

Giả sử tất cả các trạng thái của $i-1$ vật phẩm đầu tiên đã được xử lý, các tùy chọn cho vật phẩm thứ $i$ là gì?

- Khi nó không được cho vào túi, sức chứa còn lại không thay đổi và tổng giá trị không thay đổi. Do đó, giá trị tối đa trong trường hợp này là $f_{i-1, j}$
- Khi nó được cho vào túi, sức chứa còn lại giảm đi $w_{i}$ và tổng giá trị tăng lên $v_{i}$,
vì vậy giá trị tối đa trong trường hợp này là $f_{i-1, j-w_i} + v_i$

Từ đây chúng ta có thể suy ra phương trình chuyển đổi dp:

$$f_{i, j} = \max(f_{i-1, j}, f_{i-1, j-w_i} + v_i)$$

Hơn nữa, vì $f_{i}$ chỉ phụ thuộc vào $f_{i-1}$, chúng ta có thể loại bỏ chiều đầu tiên. Chúng ta thu được quy tắc chuyển đổi

$$f_j \gets \max(f_j, f_{j-w_i}+v_i)$$

phải được thực thi theo thứ tự **giảm dần** của $j$ (sao cho $f_{j-w_i}$ ngầm tương ứng với $f_{i-1,j-w_i}$ chứ không phải $f_{i,j-w_i}$).

**Điều quan trọng là phải hiểu quy tắc chuyển đổi này, bởi vì hầu hết các chuyển đổi cho bài toán cái túi đều được suy ra theo cách tương tự.**

### Triển khai

Thuật toán được mô tả có thể được triển khai trong $O(nW)$ như sau:

```.c++
for (int i = 1; i <= n; i++)
  for (int j = W; j >= w[i]; j--)
    f[j] = max(f[j], f[j - w[i]] + v[i]);
```

Một lần nữa, lưu ý thứ tự thực hiện. Cần phải tuân thủ nghiêm ngặt điều này để đảm bảo bất biến sau: Ngay trước khi cặp $(i, j)$ được xử lý, $f_k$ tương ứng với $f_{i,k}$ cho $k > j$, nhưng với $f_{i-1,k}$ cho $k < j$. Điều này đảm bảo rằng $f_{j-w_i}$ được lấy từ bước $(i-1)$ chứ không phải từ bước $i$.

## Cái túi hoàn chỉnh (Complete Knapsack)

Mô hình cái túi hoàn chỉnh tương tự như cái túi 0-1, điểm khác biệt duy nhất so với cái túi 0-1 là một vật phẩm có thể được chọn vô số lần thay vì chỉ một lần.

Chúng ta có thể tham khảo ý tưởng về cái túi 0-1 để định nghĩa trạng thái: $f_{i, j}$, giá trị tối đa mà túi có thể nhận được bằng cách sử dụng $i$ vật phẩm đầu tiên với sức chứa tối đa $j$.

Cần lưu ý rằng mặc dù định nghĩa trạng thái tương tự như định nghĩa của cái túi 0-1, nhưng quy tắc chuyển đổi của nó khác với quy tắc của cái túi 0-1.

### Giải thích

Cách tiếp cận tầm thường là, đối với $i$ vật phẩm đầu tiên, liệt kê số lần mỗi vật phẩm được lấy. Độ phức tạp thời gian của việc này là $O(n^2W)$.

Điều này mang lại phương trình chuyển đổi sau:

$$f_{i, j} = \max\limits_{k=0}^{\infty}(f_{i-1, j-k\cdot w_i} + k\cdot v_i)$$

Đồng thời, nó được đơn giản hóa thành một phương trình "phẳng":

$$f_{i, j} = \max(f_{i-1, j},f_{i, j-w_i} + v_i)$$

Lý do điều này hoạt động là vì $f_{i, j-w_i}$ đã được cập nhật bởi $f_{i, j-2\cdot w_i}$, v.v.

Tương tự như cái túi 0-1, chúng ta có thể loại bỏ chiều đầu tiên để tối ưu hóa độ phức tạp không gian. Điều này cho chúng ta cùng một quy tắc chuyển đổi như cái túi 0-1.

$$f_j \gets \max(f_j, f_{j-w_i}+v_i)$$

### Triển khai

Thuật toán được mô tả có thể được triển khai trong $O(nW)$ như sau:

```.c++
for (int i = 1; i <= n; i++)
  for (int j = w[i]; j <= W; j++)
    f[j] = max(f[j], f[j - w[i]] + v[i]);
```

Mặc dù có cùng quy tắc chuyển đổi, nhưng mã ở trên không chính xác đối với cái túi 0-1.

Quan sát mã một cách cẩn thận, chúng ta thấy rằng đối với vật phẩm $i$ đang được xử lý hiện tại và trạng thái hiện tại $f_{i,j}$,
khi $j\geqslant w_{i}$, $f_{i,j}$ sẽ bị ảnh hưởng bởi $f_{i,j-w_{i}}$.
Điều này tương đương với việc có thể đặt vật phẩm $i$ vào ba lô nhiều lần, điều này phù hợp với bài toán cái túi hoàn chỉnh chứ không phải bài toán cái túi 0-1.

## Cái túi nhiều lần (Multiple Knapsack)

Cái túi nhiều lần cũng là một biến thể của cái túi 0-1. Sự khác biệt chính là có $k_i$ của mỗi vật phẩm thay vì chỉ $1$.

### Giải thích

Một ý tưởng rất đơn giản là: "chọn mỗi vật phẩm $k_i$ lần" tương đương với "$k_i$ của cùng một vật phẩm được chọn từng cái một". Do đó chuyển đổi nó thành mô hình cái túi 0-1, có thể được mô tả bằng hàm chuyển đổi:

$$f_{i, j} = \max_{k=0}^{k_i}(f_{i-1,j-k\cdot w_i} + k\cdot v_i)$$

Độ phức tạp thời gian của quá trình này là $O(W\sum\limits_{i=1}^{n}k_i)$

### Tối ưu hóa nhóm nhị phân (Binary Grouping)

Chúng ta vẫn xem xét việc chuyển đổi mô hình cái túi nhiều lần thành mô hình cái túi 0-1 để tối ưu hóa. Độ phức tạp thời gian $O(Wn)$ không thể được tối ưu hóa hơn nữa với cách tiếp cận ở trên, vì vậy chúng ta tập trung vào thành phần $O(\sum k_i)$.

Cho $A_{i, j}$ biểu thị vật phẩm thứ $j$ được tách ra từ vật phẩm thứ $i$. Trong cách tiếp cận tầm thường được thảo luận ở trên, $A_{i, j}$ đại diện cho cùng một vật phẩm cho tất cả $j \leq k_i$. Lý do chính khiến hiệu quả của chúng ta thấp là chúng ta đang làm rất nhiều công việc lặp đi lặp lại. Ví dụ: hãy xem xét việc chọn $\{A_{i, 1},A_{i, 2}\}$ và chọn $\{A_{i, 2}, A_{i, 3}\}$. Hai tình huống này hoàn toàn tương đương. Do đó, việc tối ưu hóa phương pháp chia tách sẽ giảm đáng kể độ phức tạp thời gian.

Việc nhóm được thực hiện hiệu quả hơn bằng cách sử dụng nhóm nhị phân.

Cụ thể, $A_{i, j}$ chứa $2^j$ vật phẩm riêng lẻ ($j\in[0,\lfloor \log_2(k_i+1)\rfloor-1]$).Nếu $k_i + 1$ không phải là lũy thừa nguyên của $2$, thì một bó khác có kích thước $k_i-2^{\lfloor \log_2(k_i+1)\rfloor-1}$ được sử dụng để bù vào.

Thông qua phương pháp chia tách ở trên, có thể thu được bất kỳ tổng nào của $\leq k_i$ vật phẩm bằng cách chọn một vài $A_{i, j}$. Sau khi chia tách mỗi vật phẩm theo cách được mô tả, chúng ta chỉ cần sử dụng phương pháp cái túi 0-1 để giải quyết công thức mới của bài toán.

Tối ưu hóa này mang lại cho chúng ta độ phức tạp thời gian là $O(W\sum\limits_{i=1}^{n}\log k_i)$.

### Triển khai

```c++
index = 0;
for (int i = 1; i <= n; i++) {
  int c = 1, p, h, k;
  cin >> p >> h >> k;
  while (k > c) {
    k -= c;
    list[++index].w = c * p;
    list[index].v = c * h;
    c *= 2;
  }
  list[++index].w = p * k;
  list[index].v = h * k;
}
```

### Tối ưu hóa hàng đợi đơn điệu (Monotone Queue Optimization)

Trong tối ưu hóa này, chúng ta hướng tới việc chuyển đổi bài toán cái túi thành bài toán [hàng đợi tối đa](https://cp-algorithms.com/data_structures/stack_queue_modification.html).

Để thuận tiện cho việc mô tả, cho $g_{x, y} = f_{i, x \cdot w_i + y} ,\space g'_{x, y} = f_{i-1, x \cdot w_i + y}$. Khi đó quy tắc chuyển đổi có thể được viết là:

$$g_{x, y} = \max_{k=0}^{k_i}(g'_{x-k, y} + v_i \cdot k)$$

Hơn nữa, cho $G_{x, y} = g'_{x, y} - v_i \cdot x$. Khi đó quy tắc chuyển đổi có thể được biểu thị là:

$$g_{x, y} \gets \max_{k=0}^{k_i}(G_{x-k, y}) + v_i \cdot x$$

Điều này biến đổi thành dạng tối ưu hóa hàng đợi đơn điệu cổ điển. $G_{x, y}$ có thể được tính toán trong $O(1)$, vì vậy đối với một $y$ cố định, chúng ta có thể tính toán $g_{x, y}$ trong thời gian $O(\lfloor \frac{W}{w_i} \rfloor)$.
Do đó, độ phức tạp của việc tìm tất cả $g_{x, y}$ là $O(\lfloor \frac{W}{w_i} \rfloor) \times O(w_i) = O(W)$.
Bằng cách này, tổng độ phức tạp của thuật toán được giảm xuống còn $O(nW)$.

## Cái túi hỗn hợp (Mixed Knapsack)

Bài toán cái túi hỗn hợp liên quan đến sự kết hợp của ba bài toán được mô tả ở trên. Tức là, một số vật phẩm chỉ có thể được lấy một lần, một số có thể được lấy vô hạn lần và một số có thể được lấy nhiều nhất $k$ lần.

Bài toán có vẻ khó khăn, nhưng miễn là bạn hiểu những ý tưởng cốt lõi của các bài toán cái túi trước đó và kết hợp chúng lại với nhau, bạn có thể làm được. Mã giả cho giải pháp như sau:

```c++
for (mỗi vật phẩm) {
  if (cái túi 0-1)
    Áp dụng mã cái túi 0-1;
  else if (cái túi hoàn chỉnh)
    Áp dụng mã cái túi hoàn chỉnh;
  else if (cái túi nhiều lần)
    Áp dụng mã cái túi nhiều lần;
}
```

## Bài tập thực hành

- [Atcoder: Knapsack-1](https://atcoder.jp/contests/dp/tasks/dp_d)
- [Atcoder: Knapsack-2](https://atcoder.jp/contests/dp/tasks/dp_e)
- [CSES: Book Shop II](https://cses.fi/problemset/task/1159)
- [DMOJ: Knapsack-3](https://dmoj.ca/problem/knapsack)
- [DMOJ: Knapsack-4](https://dmoj.ca/problem/knapsack4)

--- 


