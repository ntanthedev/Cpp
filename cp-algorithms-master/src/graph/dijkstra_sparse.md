# Dijkstra trên đồ thị thưa (Dijkstra on sparse graphs)

---
tags:
  - Dịch
e_maxx_link: dijkstra_sparse
---

# Dijkstra trên đồ thị thưa

Đối với phát biểu của bài toán, thuật toán với triển khai và chứng minh có thể được tìm thấy trên bài viết [Thuật toán Dijkstra](dijkstra.md).

## Thuật toán

Chúng ta nhớ lại trong quá trình suy ra độ phức tạp của thuật toán Dijkstra, chúng ta đã sử dụng hai yếu tố:
thời gian tìm đỉnh chưa được đánh dấu có khoảng cách $d[v]$ nhỏ nhất và thời gian giãn, tức là thời gian thay đổi giá trị $d[\text{to}]$.

Trong cách triển khai đơn giản nhất, các thao tác này yêu cầu thời gian $O(n)$ và $O(1)$.
Do đó, vì chúng ta thực hiện thao tác đầu tiên $O(n)$ lần và thao tác thứ hai $O(m)$ lần, nên chúng ta thu được độ phức tạp $O(n^2 + m)$.

Rõ ràng, độ phức tạp này là tối ưu đối với đồ thị dày đặc, tức là khi $m \approx n^2$.
Tuy nhiên, trong đồ thị thưa, khi $m$ nhỏ hơn nhiều so với số lượng cạnh tối đa $n^2$, độ phức tạp trở nên kém tối ưu hơn do số hạng đầu tiên.
Do đó, cần phải cải thiện thời gian thực hiện của thao tác đầu tiên (và tất nhiên là không ảnh hưởng nhiều đến thao tác thứ hai).

Để thực hiện điều đó, chúng ta có thể sử dụng một biến thể của nhiều cấu trúc dữ liệu phụ trợ.
Hiệu quả nhất là **heap Fibonacci**, cho phép thao tác đầu tiên chạy trong $O(\log n)$ và thao tác thứ hai trong $O(1)$.
Do đó, chúng ta sẽ có độ phức tạp $O(n \log n + m)$ cho thuật toán Dijkstra, đây cũng là mức tối thiểu về mặt lý thuyết cho bài toán tìm kiếm đường đi ngắn nhất.
Do đó, thuật toán này hoạt động tối ưu và heap Fibonacci là cấu trúc dữ liệu tối ưu.
Không tồn tại bất kỳ cấu trúc dữ liệu nào có thể thực hiện cả hai thao tác trong $O(1)$, bởi vì điều này cũng sẽ cho phép sắp xếp một danh sách các số ngẫu nhiên trong thời gian tuyến tính, điều này là không thể.
Điều thú vị là tồn tại một thuật toán của Thorup tìm đường đi ngắn nhất trong thời gian $O(m)$, tuy nhiên chỉ hoạt động đối với trọng số nguyên và sử dụng một ý tưởng hoàn toàn khác.
Vì vậy, điều này không dẫn đến bất kỳ mâu thuẫn nào.
Heap Fibonacci cung cấp độ phức tạp tối ưu cho nhiệm vụ này.
Tuy nhiên, chúng khá phức tạp để triển khai và cũng có hằng số ẩn khá lớn.

Để thỏa hiệp, bạn có thể sử dụng các cấu trúc dữ liệu, thực hiện cả hai loại thao tác (trích xuất giá trị nhỏ nhất và cập nhật một mục) trong $O(\log n)$.
Khi đó độ phức tạp của thuật toán Dijkstra là $O(n \log n + m \log n) = O(m \log n)$.

C++ cung cấp hai cấu trúc dữ liệu như vậy: `set` và `priority_queue`.
Cái đầu tiên dựa trên cây đỏ-đen (red-black tree) và cái thứ hai dựa trên heap.
Do đó, `priority_queue` có hằng số ẩn nhỏ hơn, nhưng cũng có một nhược điểm:
nó không hỗ trợ thao tác xóa một phần tử.
Bởi vì điều này, chúng ta cần phải thực hiện một "giải pháp thay thế", thực sự dẫn đến hệ số $\log m$ hơi tệ hơn thay vì $\log n$ (mặc dù về mặt độ phức tạp, chúng giống hệt nhau).

## Triển khai

### set

Chúng ta hãy bắt đầu với _container_ `set`.
Vì chúng ta cần lưu trữ các đỉnh được sắp xếp theo giá trị $d[]$ của chúng, nên sẽ thuận tiện hơn khi lưu trữ các cặp thực tế: khoảng cách và chỉ số của đỉnh.
Kết quả là trong `set`, các cặp được tự động sắp xếp theo khoảng cách của chúng.

```{.cpp file=dijkstra_sparse_set}
const int INF = 1000000000;
vector<vector<pair<int, int>>> adj;

void dijkstra(int s, vector<int> & d, vector<int> & p) {
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);

    d[s] = 0;
    set<pair<int, int>> q;
    q.insert({0, s});
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;
            
            if (d[v] + len < d[to]) {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                p[to] = v;
                q.insert({d[to], to});
            }
        }
    }
}
```

Chúng ta không cần mảng $u[]$ từ việc triển khai thuật toán Dijkstra thông thường nữa.
Chúng ta sẽ sử dụng `set` để lưu trữ thông tin đó và cũng tìm đỉnh có khoảng cách ngắn nhất với nó.
Nó hoạt động giống như một hàng đợi.
Các vòng lặp chính thực thi cho đến khi không còn đỉnh nào trong tập hợp/hàng đợi.
Một đỉnh có khoảng cách nhỏ nhất được trích xuất và đối với mỗi lần giãn thành công, trước tiên chúng ta xóa cặp cũ, sau đó sau khi giãn, hãy thêm cặp mới vào hàng đợi.

### priority_queue

Sự khác biệt chính so với việc triển khai với `set` là trong nhiều ngôn ngữ, bao gồm cả C++, chúng ta không thể xóa các phần tử khỏi `priority_queue` (mặc dù heap có thể hỗ trợ thao tác đó về mặt lý thuyết).
Do đó, chúng ta phải sử dụng giải pháp thay thế:
Chúng ta chỉ đơn giản là không xóa cặp cũ khỏi hàng đợi.
Kết quả là một đỉnh có thể xuất hiện nhiều lần với khoảng cách khác nhau trong hàng đợi cùng một lúc.
Trong số các cặp này, chúng ta chỉ quan tâm đến các cặp có phần tử đầu tiên bằng với giá trị tương ứng trong $d[]$, tất cả các cặp khác đều là cũ.
Do đó, chúng ta cần thực hiện một sửa đổi nhỏ:
ở đầu mỗi lần lặp, sau khi trích xuất cặp tiếp theo, chúng ta kiểm tra xem đó có phải là cặp quan trọng hay đó đã là cặp cũ và đã được xử lý.
Kiểm tra này rất quan trọng, nếu không độ phức tạp có thể tăng lên đến $O(n m)$.

Theo mặc định, `priority_queue` sắp xếp các phần tử theo thứ tự giảm dần.
Để làm cho nó sắp xếp các phần tử theo thứ tự tăng dần, chúng ta có thể lưu trữ các khoảng cách bị phủ định trong đó hoặc truyền cho nó một hàm sắp xếp khác.
Chúng ta sẽ làm tùy chọn thứ hai.

```{.cpp file=dijkstra_sparse_pq}
const int INF = 1000000000;
vector<vector<pair<int, int>>> adj;

void dijkstra(int s, vector<int> & d, vector<int> & p) {
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);

    d[s] = 0;
    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});
    while (!q.empty()) {
        int v = q.top().second;
        int d_v = q.top().first;
        q.pop();
        if (d_v != d[v])
            continue;

        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;
            
            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
                q.push({d[to], to});
            }
        }
    }
}
```

Trong thực tế, phiên bản `priority_queue` nhanh hơn một chút so với phiên bản có `set`.

Điều thú vị là một [báo cáo kỹ thuật năm 2007](https://www3.cs.stonybrook.edu/~rezaul/papers/TR-07-54.pdf) đã kết luận rằng biến thể của thuật toán không sử dụng thao tác giảm khóa chạy nhanh hơn so với biến thể giảm khóa, với khoảng cách hiệu suất lớn hơn đối với đồ thị thưa.

### Loại bỏ các cặp

Bạn có thể cải thiện hiệu suất thêm một chút nếu bạn không lưu trữ các cặp trong các _container_, mà chỉ lưu trữ các chỉ số đỉnh.
Trong trường hợp này, chúng ta phải overload toán tử so sánh:
nó phải so sánh hai đỉnh bằng cách sử dụng khoảng cách được lưu trữ trong $d[]$.

Do kết quả của việc giãn, khoảng cách của một số đỉnh sẽ thay đổi.
Tuy nhiên, cấu trúc dữ liệu sẽ không tự động sắp xếp lại chính nó.
Trên thực tế, việc thay đổi khoảng cách của các đỉnh trong hàng đợi có thể phá hủy cấu trúc dữ liệu.
Như trước đây, chúng ta cần xóa đỉnh trước khi chúng ta giãn nó, sau đó chèn lại nó sau đó.

Vì chúng ta chỉ có thể xóa khỏi `set`, nên tối ưu hóa này chỉ áp dụng cho phương thức `set` và không hoạt động với triển khai `priority_queue`.
Trong thực tế, điều này làm tăng đáng kể hiệu suất, đặc biệt là khi các kiểu dữ liệu lớn hơn được sử dụng để lưu trữ khoảng cách, như `long long` hoặc `double`.


