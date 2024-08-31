# Ngăn xếp/Hàng đợi tìm giá trị nhỏ nhất (Minimum stack / Minimum queue)

---
tags:
  - Dịch
e_maxx_link: stacks_for_minima
---

# Ngăn xếp/Hàng đợi tìm giá trị nhỏ nhất (Minimum stack / Minimum queue)

Trong bài viết này, chúng ta sẽ xem xét ba bài toán:
đầu tiên chúng ta sẽ sửa đổi một _stack_ (ngăn xếp) theo cách cho phép chúng ta tìm phần tử nhỏ nhất của _stack_ trong $O(1)$, sau đó chúng ta sẽ làm điều tương tự với _queue_ (hàng đợi), và cuối cùng chúng ta sẽ sử dụng những cấu trúc dữ liệu này để tìm giá trị nhỏ nhất trong tất cả các mảng con có độ dài cố định trong một mảng trong $O(n)$

## Sửa đổi Stack

Chúng ta muốn sửa đổi cấu trúc dữ liệu _stack_ theo cách sao cho có thể tìm thấy phần tử nhỏ nhất trong _stack_ trong thời gian $O(1)$, đồng thời duy trì hành vi tiệm cận giống nhau để thêm và xóa các phần tử khỏi _stack_.
Nhắc nhở nhanh, trên _stack_, chúng ta chỉ thêm và xóa các phần tử ở một đầu.

Để thực hiện việc này, chúng ta sẽ không chỉ lưu trữ các phần tử trong _stack_ mà chúng ta sẽ lưu trữ chúng theo cặp: chính phần tử đó và giá trị nhỏ nhất trong _stack_ bắt đầu từ phần tử này trở xuống.

```cpp
stack<pair<int, int>> st;
```

Rõ ràng là việc tìm giá trị nhỏ nhất trong toàn bộ _stack_ chỉ bao gồm việc xem xét giá trị `stack.top().second`.

Rõ ràng là việc thêm hoặc xóa một phần tử mới vào _stack_ có thể được thực hiện trong thời gian không đổi.

Triển khai:

* Thêm một phần tử:
```cpp
int new_min = st.empty() ? new_elem : min(new_elem, st.top().second);
st.push({new_elem, new_min});
```

* Xóa một phần tử:
```cpp
int removed_element = st.top().first;
st.pop();
```

* Tìm giá trị nhỏ nhất:
```cpp
int minimum = st.top().second;
```

## Sửa đổi Queue (phương pháp 1)

Bây giờ chúng ta muốn đạt được các hoạt động tương tự với _queue_, tức là chúng ta muốn thêm các phần tử vào cuối và xóa chúng khỏi đầu.

Ở đây, chúng ta xem xét một phương pháp đơn giản để sửa đổi _queue_.
Tuy nhiên, nó có một nhược điểm lớn, bởi vì _queue_ đã sửa đổi sẽ thực sự không lưu trữ tất cả các phần tử.

Ý tưởng chính là chỉ lưu trữ các mục trong _queue_ cần thiết để xác định giá trị nhỏ nhất.
Cụ thể, chúng ta sẽ giữ _queue_ theo thứ tự không giảm (tức là giá trị nhỏ nhất sẽ được lưu trữ ở đầu) và tất nhiên không theo bất kỳ cách tùy ý nào, giá trị nhỏ nhất thực tế phải luôn được chứa trong _queue_.
Bằng cách này, phần tử nhỏ nhất sẽ luôn ở đầu _queue_.
Trước khi thêm một phần tử mới vào _queue_, nó đủ để thực hiện "cắt":
chúng ta sẽ xóa tất cả các phần tử ở cuối _queue_ lớn hơn phần tử mới, sau đó thêm phần tử mới vào _queue_.
Bằng cách này, chúng ta không phá vỡ thứ tự của _queue_ và chúng ta cũng sẽ không mất phần tử hiện tại nếu ở bất kỳ bước tiếp theo nào, nó là giá trị nhỏ nhất.
Tất cả các phần tử mà chúng ta đã xóa không bao giờ có thể là giá trị nhỏ nhất, vì vậy thao tác này được phép.
Khi chúng ta muốn trích xuất một phần tử từ đầu, nó thực sự có thể không có ở đó (vì chúng ta đã xóa nó trước đó trong khi thêm một phần tử nhỏ hơn).
Do đó, khi xóa một phần tử khỏi _queue_, chúng ta cần biết giá trị của phần tử.
Nếu đầu _queue_ có cùng giá trị, chúng ta có thể xóa nó một cách an toàn, nếu không chúng ta không làm gì cả.

Hãy xem xét các cách triển khai các hoạt động trên:

```cpp
deque<int> q;
```

* Tìm giá trị nhỏ nhất:
```cpp
int minimum = q.front();
```

* Thêm một phần tử:
```cpp
while (!q.empty() && q.back() > new_element)
    q.pop_back();
q.push_back(new_element);
```

* Xóa một phần tử:
```cpp
if (!q.empty() && q.front() == remove_element)
    q.pop_front();
```

Rõ ràng là trung bình tất cả các thao tác này chỉ mất thời gian $O(1)$ (vì mọi phần tử chỉ có thể được đẩy và bật một lần).

## Sửa đổi Queue (phương pháp 2)

Đây là sửa đổi của phương pháp 1.
Chúng ta muốn có thể xóa các phần tử mà không cần biết phần tử nào chúng ta phải xóa.
Chúng ta có thể thực hiện điều đó bằng cách lưu trữ chỉ mục cho mỗi phần tử trong _queue_.
Và chúng ta cũng nhớ có bao nhiêu phần tử chúng ta đã thêm và xóa.

```cpp
deque<pair<int, int>> q;
int cnt_added = 0;
int cnt_removed = 0;
```

* Tìm giá trị nhỏ nhất:
```cpp
int minimum = q.front().first;
```

* Thêm một phần tử:
```cpp
while (!q.empty() && q.back().first > new_element)
    q.pop_back();
q.push_back({new_element, cnt_added});
cnt_added++;
```

* Xóa một phần tử:
```cpp
if (!q.empty() && q.front().second == cnt_removed) 
    q.pop_front();
cnt_removed++;
```

## Sửa đổi Queue (phương pháp 3)

Ở đây, chúng ta xem xét một cách khác để sửa đổi _queue_ để tìm giá trị nhỏ nhất trong $O(1)$.
Cách này hơi phức tạp hơn một chút để triển khai, nhưng lần này chúng ta thực sự lưu trữ tất cả các phần tử.
Và chúng ta cũng có thể xóa một phần tử khỏi đầu mà không cần biết giá trị của nó.

Ý tưởng là rút gọn bài toán thành bài toán về _stack_, bài toán mà chúng ta đã giải quyết.
Vì vậy, chúng ta chỉ cần học cách mô phỏng _queue_ bằng cách sử dụng hai _stack_.

Chúng ta tạo hai _stack_, `s1` và `s2`.
Tất nhiên, các _stack_ này sẽ ở dạng đã sửa đổi, để chúng ta có thể tìm thấy giá trị nhỏ nhất trong $O(1)$.
Chúng ta sẽ thêm các phần tử mới vào _stack_ `s1` và xóa các phần tử khỏi _stack_ `s2`.
Nếu tại bất kỳ thời điểm nào _stack_ `s2` trống, chúng ta di chuyển tất cả các phần tử từ `s1` sang `s2` (về cơ bản đảo ngược thứ tự của các phần tử đó).
Cuối cùng, việc tìm giá trị nhỏ nhất trong _queue_ chỉ liên quan đến việc tìm giá trị nhỏ nhất của cả hai _stack_.

Do đó, chúng ta thực hiện tất cả các thao tác trong $O(1)$ trung bình (mỗi phần tử sẽ được thêm một lần vào _stack_ `s1`, một lần được chuyển sang `s2` và một lần được bật ra khỏi `s2`)

Triển khai:

```cpp
stack<pair<int, int>> s1, s2;
```

* Tìm giá trị nhỏ nhất:
```cpp
if (s1.empty() || s2.empty()) 
    minimum = s1.empty() ? s2.top().second : s1.top().second;
else
    minimum = min(s1.top().second, s2.top().second);
```

* Thêm phần tử:
```cpp
int minimum = s1.empty() ? new_element : min(new_element, s1.top().second);
s1.push({new_element, minimum});
```

* Xóa một phần tử:
```cpp
if (s2.empty()) {
    while (!s1.empty()) {
        int element = s1.top().first;
        s1.pop();
        int minimum = s2.empty() ? element : min(element, s2.top().second);
        s2.push({element, minimum});
    }
}
int remove_element = s2.top().first;
s2.pop();
```

## Tìm giá trị nhỏ nhất cho tất cả các mảng con có độ dài cố định

Giả sử chúng ta được cho một mảng $A$ có độ dài $N$ và một $M \le N$ cho trước.
Chúng ta phải tìm giá trị nhỏ nhất của mỗi mảng con có độ dài $M$ trong mảng này, tức là chúng ta phải tìm:

$$\min_{0 \le i \le M-1} A[i], \min_{1 \le i \le M} A[i], \min_{2 \le i \le M+1} A[i],~\dots~, \min_{N-M \le i \le N-1} A[i]$$

Chúng ta phải giải quyết bài toán này trong thời gian tuyến tính, tức là $O(n)$.

Chúng ta có thể sử dụng bất kỳ _queue_ nào trong ba _queue_ đã sửa đổi để giải quyết bài toán.
Các giải pháp nên rõ ràng:
chúng ta thêm $M$ phần tử đầu tiên của mảng, tìm và xuất ra giá trị nhỏ nhất của nó, sau đó thêm phần tử tiếp theo vào _queue_ và xóa phần tử đầu tiên của mảng, tìm và xuất ra giá trị nhỏ nhất của nó, v.v.
Vì tất cả các thao tác với _queue_ được thực hiện trong thời gian không đổi trung bình, nên độ phức tạp của toàn bộ thuật toán sẽ là $O(n)$.

## Bài tập thực hành
* [Queries with Fixed Length](https://www.hackerrank.com/challenges/queries-with-fixed-length/problem)
* [Binary Land](https://www.codechef.com/MAY20A/problems/BINLAND)



--- 
