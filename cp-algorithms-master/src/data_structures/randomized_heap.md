# Heap ngẫu nhiên (Randomized Heap)

---
tags:
  - Dịch
e_maxx_link: randomized_heap
---

# Heap ngẫu nhiên (Randomized Heap)

Heap ngẫu nhiên là heap, thông qua việc sử dụng ngẫu nhiên, cho phép thực hiện tất cả các thao tác trong thời gian logarit dự kiến.

**Min heap** là một cây nhị phân trong đó giá trị của mỗi đỉnh nhỏ hơn hoặc bằng giá trị của các con của nó.
Do đó, giá trị nhỏ nhất của cây luôn nằm ở đỉnh gốc.

Max heap có thể được định nghĩa theo cách tương tự: bằng cách thay thế nhỏ hơn bằng lớn hơn.

Các thao tác mặc định của heap là:

- Thêm một giá trị
- Trích xuất giá trị nhỏ nhất
- Xóa giá trị nhỏ nhất
- Hợp nhất hai heap (không xóa các bản sao)
- Xóa một phần tử tùy ý (nếu vị trí của nó trong cây đã biết)

Heap ngẫu nhiên có thể thực hiện tất cả các thao tác này trong thời gian dự kiến $O(\log n)$ với cách triển khai rất đơn giản.

## Cấu trúc dữ liệu

Chúng ta có thể mô tả ngay cấu trúc của heap nhị phân:

```{.cpp file=randomized_heap_structure}
struct Tree {
    int value;
    Tree * l = nullptr;
    Tree * r = nullptr;
};
```

Trong đỉnh chúng ta lưu trữ một giá trị.
Ngoài ra, chúng ta có các con trỏ đến con trái và con phải, chúng trỏ đến null nếu con tương ứng không tồn tại.

## Các thao tác

Không khó để nhận thấy, tất cả các thao tác đều có thể được rút gọn thành một thao tác duy nhất: **hợp nhất** hai heap thành một.
Thật vậy, việc thêm một giá trị mới vào heap tương đương với việc hợp nhất heap với một heap bao gồm một đỉnh duy nhất có giá trị đó.
Việc tìm giá trị nhỏ nhất không yêu cầu bất kỳ thao tác nào cả - giá trị nhỏ nhất chỉ đơn giản là giá trị ở gốc.
Việc xóa giá trị nhỏ nhất tương đương với kết quả của việc hợp nhất các con trái và phải của đỉnh gốc.
Và việc xóa một phần tử tùy ý cũng tương tự.
Chúng ta hợp nhất các con của đỉnh và thay thế đỉnh bằng kết quả của phép hợp nhất.

Vì vậy, chúng ta thực sự chỉ cần triển khai thao tác hợp nhất hai heap.
Tất cả các hoạt động khác được rút gọn một cách tầm thường thành hoạt động này.

Cho hai heap $T_1$ và $T_2$.
Rõ ràng là gốc của mỗi heap này chứa giá trị nhỏ nhất của nó.
Vì vậy, gốc của heap kết quả sẽ là giá trị nhỏ nhất của hai giá trị này.
Vì vậy, chúng ta so sánh cả hai giá trị và sử dụng giá trị nhỏ hơn làm gốc mới.
Bây giờ chúng ta phải kết hợp các con của đỉnh được chọn với heap còn lại.
Đối với điều này, chúng ta chọn một trong các con và hợp nhất nó với heap còn lại.
Do đó, chúng ta lại có thao tác hợp nhất hai heap.
Sớm muộn gì quá trình này cũng sẽ kết thúc (số lượng các bước như vậy bị giới hạn bởi tổng chiều cao của hai heap)

Để đạt được độ phức tạp logarit trung bình, chúng ta cần chỉ định một phương pháp để chọn một trong hai con sao cho độ dài đường dẫn trung bình là logarit.
Không khó để đoán, chúng ta sẽ đưa ra quyết định này một cách **ngẫu nhiên**.
Do đó, cách triển khai thao tác hợp nhất như sau:

```{.cpp file=randomized_heap_merge}
Tree* merge(Tree* t1, Tree* t2) {
    if (!t1 || !t2)
        return t1 ? t1 : t2;
    if (t2->value < t1->value)
        swap(t1, t2);
    if (rand() & 1)
        swap(t1->l, t1->r);
    t1->l = merge(t1->l, t2);
    return t1;
}
```

Ở đây, trước tiên, chúng ta kiểm tra xem một trong các heap có trống hay không, sau đó chúng ta không cần thực hiện bất kỳ hành động hợp nhất nào cả.
Nếu không, chúng ta tạo heap `t1` là heap có giá trị nhỏ hơn (bằng cách hoán đổi `t1` và `t2` nếu cần).
Chúng ta muốn hợp nhất con trái của `t1` với `t2`, do đó chúng ta hoán đổi ngẫu nhiên các con của `t1`, sau đó thực hiện hợp nhất.

## Độ phức tạp

Chúng ta giới thiệu biến ngẫu nhiên $h(T)$ sẽ biểu thị **độ dài của đường dẫn ngẫu nhiên** từ gốc đến lá (độ dài tính bằng số cạnh).
Rõ ràng là thuật toán `merge` thực hiện $O(h(T_1) + h(T_2))$ bước.
Do đó, để hiểu độ phức tạp của các thao tác, chúng ta phải xem xét biến ngẫu nhiên $h(T)$.

### Giá trị kỳ vọng

Chúng ta giả định rằng kỳ vọng $h(T)$ có thể được ước tính từ trên bởi logarit của số lượng đỉnh trong heap:

$$\mathbf{E} h(T) \le \log(n+1)$$

Điều này có thể dễ dàng được chứng minh bằng quy nạp.
Cho $L$ và $R$ là các cây con trái và phải của gốc $T$, và $n_L$ và $n_R$ là số lượng đỉnh trong chúng ($n = n_L + n_R + 1$).

Sau đây cho thấy bước quy nạp:

$$\begin{align}
\mathbf{E} h(T) &= 1 + \frac{\mathbf{E} h(L) + \mathbf{E} h(R)}{2} 
\le 1 + \frac{\log(n_L + 1) \log(n_R + 1)}{2} \\\\
&= 1 + \log\sqrt{(n_L + 1)(n_R + 1)} = \log 2\sqrt{(n_L + 1)(n_R + 1)} \\\\
&\le \log \frac{2\left((n_L + 1) + (n_R + 1)\right)}{2} = \log(n_L + n_R + 2) = \log(n+1)
\end{align}$$

### Vượt quá giá trị kỳ vọng

Tất nhiên chúng ta vẫn chưa hài lòng.
Giá trị kỳ vọng của $h(T)$ không nói lên điều gì về trường hợp xấu nhất.
Vẫn có khả năng các đường dẫn từ gốc đến các đỉnh trung bình lớn hơn nhiều so với $\log(n + 1)$ đối với một cây cụ thể.

Chúng ta hãy chứng minh rằng việc vượt quá giá trị kỳ vọng thực sự rất nhỏ:

$$P\{h(T) > (c+1) \log n\} < \frac{1}{n^c}$$

cho bất kỳ hằng số dương $c$ nào.

Ở đây chúng ta biểu thị bằng $P$ tập hợp các đường dẫn từ gốc của heap đến các lá, trong đó độ dài vượt quá $(c+1) \log n$.
Lưu ý rằng đối với bất kỳ đường dẫn $p$ nào có độ dài $|p|$, xác suất nó được chọn làm đường dẫn ngẫu nhiên là $2^{-|p|}$.
Do đó chúng ta nhận được:

$$P\{h(T) > (c+1) \log n\} = \sum_{p \in P} 2^{-|p|} < \sum_{p \in P} 2^{-(c+1) \log n} = |P| n^{-(c+1)} \le n^{-c}$$

### Độ phức tạp của thuật toán

Do đó, thuật toán `merge`, và do đó tất cả các thao tác khác được thể hiện bằng nó, có thể được thực hiện trong $O(\log n)$ trung bình.

Hơn nữa, đối với bất kỳ hằng số dương $\epsilon$ nào, tồn tại một hằng số dương $c$ sao cho xác suất thao tác yêu cầu nhiều hơn $c \log n$ bước nhỏ hơn $n^{-\epsilon}$ (theo một nghĩa nào đó, điều này mô tả hành vi trường hợp xấu nhất của thuật toán).



---

