# Độ dài của hợp các đoạn thẳng

---
tags:
  - Dịch
e_maxx_link: length_of_segments_union
---

# Độ dài của hợp các đoạn thẳng

Cho $n$ đoạn thẳng trên một đường thẳng, mỗi đoạn thẳng được mô tả bởi một cặp tọa độ $(a_{i1}, a_{i2})$.
Chúng ta phải tìm độ dài của hợp của chúng.

Thuật toán sau đây được đề xuất bởi Klee vào năm 1977.
Nó hoạt động trong $O(n\log n)$ và đã được chứng minh là tối ưu tiệm cận.

## Giải pháp

Chúng ta lưu trữ trong một mảng $x$ các điểm cuối của tất cả các đoạn thẳng được sắp xếp theo giá trị của chúng.
Và ngoài ra, chúng ta lưu trữ xem đó là điểm cuối bên trái hay điểm cuối bên phải của một đoạn thẳng.
Bây giờ chúng ta lặp qua mảng, giữ một bộ đếm $c$ của các đoạn thẳng hiện đang mở.
Bất cứ khi nào phần tử hiện tại là điểm cuối bên trái, chúng ta tăng bộ đếm này lên và ngược lại, chúng ta giảm nó xuống.
Để tính toán câu trả lời, chúng ta lấy độ dài giữa hai giá trị $x$ cuối cùng $x_i - x_{i-1}$, bất cứ khi nào chúng ta đến một tọa độ mới và hiện tại có ít nhất một đoạn thẳng đang mở.

## Triển khai

```cpp
int length_union(const vector<pair<int, int>> &a) {
    int n = a.size();
    vector<pair<int, bool>> x(n*2);
    for (int i = 0; i < n; i++) {
        x[i*2] = {a[i].first, false};
        x[i*2+1] = {a[i].second, true};
    }

    sort(x.begin(), x.end());

    int result = 0;
    int c = 0;
    for (int i = 0; i < n * 2; i++) {
        if (i > 0 && x[i].first > x[i-1].first && c > 0)
            result += x[i].first - x[i-1].first;
        if (x[i].second)
            c--;
        else
            c++;
    }
    return result;
}
```

--- 
