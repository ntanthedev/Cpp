# Tìm kiếm ma trận con 0 lớn nhất (Finding the largest zero submatrix)

---
tags:
  - Dịch
e_maxx_link: maximum_zero_submatrix
---

# Tìm kiếm ma trận con 0 lớn nhất

Cho một ma trận có `n` hàng và `m` cột. Tìm ma trận con lớn nhất chỉ bao gồm số 0 (ma trận con là một vùng hình chữ nhật của ma trận).

## Thuật toán

Các phần tử của ma trận sẽ là `a[i][j]`, trong đó `i = 0...n - 1`, `j = 0... m - 1`. Để đơn giản, chúng ta sẽ coi tất cả các phần tử khác không bằng 1.

### Bước 1: Quy hoạch động phụ trợ

Đầu tiên, chúng ta tính toán ma trận phụ trợ sau: `d[i][j]`, hàng gần nhất có 1 phía trên `a[i][j]`. Nói một cách chính thức, `d[i][j]` là số hàng lớn nhất (từ `0` đến `i - 1`), trong đó có một phần tử bằng `1` trong cột thứ `j`.
Trong khi lặp từ trên cùng bên trái xuống dưới cùng bên phải, khi chúng ta đứng ở hàng `i`, chúng ta biết các giá trị từ hàng trước đó, vì vậy, chỉ cần cập nhật các phần tử có giá trị `1`. Chúng ta có thể lưu các giá trị trong một mảng đơn giản `d[i]`, `i = 1...m - 1`, bởi vì trong thuật toán tiếp theo, chúng ta sẽ xử lý ma trận theo từng hàng một và chỉ cần các giá trị của hàng hiện tại.

```cpp
vector<int> d(m, -1);
for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
        if (a[i][j] == 1) {
            d[j] = i;
        }
    }
}
```

### Bước 2: Giải quyết vấn đề

Chúng ta có thể giải quyết bài toán trong $O(n m^2)$ bằng cách lặp qua các hàng, xem xét mọi cột trái và phải có thể có cho một ma trận con. Phần dưới cùng của hình chữ nhật sẽ là hàng hiện tại và sử dụng `d[i][j]`, chúng ta có thể tìm thấy hàng trên cùng. Tuy nhiên, có thể đi xa hơn và cải thiện đáng kể độ phức tạp của giải pháp.

Rõ ràng là ma trận con 0 mong muốn bị giới hạn ở cả bốn phía bởi một số số 1, điều này ngăn nó tăng kích thước và cải thiện câu trả lời. Do đó, chúng ta sẽ không bỏ lỡ câu trả lời nếu chúng ta hành động như sau: đối với mọi ô `j` trong hàng `i` (hàng dưới cùng của ma trận con 0 tiềm năng), chúng ta sẽ có `d[i][j]` là hàng trên cùng của ma trận con 0 hiện tại. Bây giờ, điều còn lại là xác định ranh giới trái và phải tối ưu của ma trận con 0, tức là đẩy tối đa ma trận con này sang trái và phải của cột thứ `j`.

Đẩy tối đa sang trái có nghĩa là gì? Nó có nghĩa là tìm một chỉ số `k1` mà `d[i][k1] > d[i][j]` và đồng thời `k1` - chỉ số gần nhất ở bên trái của chỉ số `j`. Rõ ràng là khi đó `k1 + 1` cho số của cột bên trái của ma trận con 0 cần thiết. Nếu hoàn toàn không có chỉ số như vậy, thì hãy đặt `k1` = `-1` (điều này có nghĩa là chúng ta đã có thể mở rộng ma trận con 0 hiện tại sang trái đến hết đường viền của ma trận `a`).

Đối xứng, bạn có thể định nghĩa chỉ số `k2` cho đường viền bên phải: đây là chỉ số gần nhất ở bên phải của `j` sao cho `d[i][k2] > d[i][j]` (hoặc `m`, nếu không có chỉ số như vậy).

Vì vậy, các chỉ số `k1` và `k2`, nếu chúng ta học cách tìm kiếm chúng một cách hiệu quả, sẽ cung cấp cho chúng ta tất cả thông tin cần thiết về ma trận con 0 hiện tại. Đặc biệt, diện tích của nó sẽ bằng `(i - d[i][j]) * (k2 - k1 - 1)`.

Làm thế nào để tìm kiếm các chỉ số `k1` và `k2` này một cách hiệu quả với `i` và `j` cố định? Chúng ta có thể làm điều đó trong $O(1)$ trung bình.

Để đạt được độ phức tạp như vậy, bạn có thể sử dụng _stack_ (ngăn xếp) như sau. Trước tiên, hãy tìm hiểu cách tìm kiếm chỉ số `k1` và lưu giá trị của nó cho mỗi chỉ số `j` trong hàng `i` hiện tại trong ma trận `d1[i][j]`. Để làm điều này, chúng ta sẽ xem xét tất cả các cột `j` từ trái sang phải và chúng ta sẽ chỉ lưu trữ trong _stack_ những cột có `d[][]` lớn hơn `d[i][j]`. Rõ ràng là khi di chuyển từ cột `j` sang cột tiếp theo, cần phải cập nhật nội dung của _stack_. Khi có một phần tử không phù hợp ở đầu _stack_ (tức là `d[][] <= d[i][j]`) hãy bật nó ra. Dễ hiểu rằng chỉ cần xóa khỏi _stack_ từ đầu của nó và không xóa khỏi bất kỳ vị trí nào khác của nó (vì _stack_ sẽ chứa chuỗi `d` tăng dần của các cột).

Giá trị `d1[i][j]` cho mỗi `j` sẽ bằng với giá trị nằm ở thời điểm đó trên đầu _stack_.

Động lực học `d2[i][j]` để tìm các chỉ số `k2` được coi là tương tự, chỉ là bạn cần xem các cột từ phải sang trái.

Rõ ràng là vì có chính xác `m` phần được thêm vào _stack_ trên mỗi dòng, nên cũng không thể có nhiều lần xóa hơn, tổng độ phức tạp sẽ là tuyến tính, vì vậy độ phức tạp cuối cùng của thuật toán là $O(nm)$.

Cũng cần lưu ý rằng thuật toán này tiêu thụ $O(m)$ bộ nhớ (không tính dữ liệu đầu vào - ma trận `a[][]`).

### Triển khai

```cpp
int zero_matrix(vector<vector<int>> a) {
    int n = a.size();
    int m = a[0].size();

    int ans = 0;
    vector<int> d(m, -1), d1(m), d2(m);
    stack<int> st;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 1)
                d[j] = i;
        }

        for (int j = 0; j < m; ++j) {
            while (!st.empty() && d[st.top()] <= d[j])
                st.pop();
            d1[j] = st.empty() ? -1 : st.top();
            st.push(j);
        }
        while (!st.empty())
            st.pop();

        for (int j = m - 1; j >= 0; --j) {
            while (!st.empty() && d[st.top()] <= d[j])
                st.pop();
            d2[j] = st.empty() ? m : st.top();
            st.push(j);
        }
        while (!st.empty())
            st.pop();

        for (int j = 0; j < m; ++j)
            ans = max(ans, (i - d[j]) * (d2[j] - d1[j] - 1));
    }
    return ans;
}
```

---


