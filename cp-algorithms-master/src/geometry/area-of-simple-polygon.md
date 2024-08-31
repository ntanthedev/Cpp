# Tìm diện tích của đa giác đơn trong $O(N)$

---
tags:
  - Dịch
e_maxx_link: polygon_area
---

# Tìm diện tích của đa giác đơn (simple polygon) trong $O(N)$

Cho một đa giác đơn (tức là không có tự giao nhau, không nhất thiết phải lồi). Yêu cầu tính diện tích của nó với các đỉnh đã cho.

## Phương pháp 1

Điều này rất dễ thực hiện nếu chúng ta đi qua tất cả các cạnh và cộng diện tích hình thang giới hạn bởi mỗi cạnh và trục x. Diện tích cần được lấy có dấu để diện tích thừa sẽ bị giảm. Do đó, công thức như sau:

$$A = \sum_{(p,q)\in \text{edges}} \frac{(p_x - q_x) \cdot (p_y + q_y)}{2}$$

Mã:

```cpp
double area(const vector<point>& fig) {
    double res = 0;
    for (unsigned i = 0; i < fig.size(); i++) {
        point p = i ? fig[i - 1] : fig.back();
        point q = fig[i];
        res += (p.x - q.x) * (p.y + q.y);
    }
    return fabs(res) / 2;
}
```

## Phương pháp 2
Chúng ta có thể chọn một điểm $O$ tùy ý, lặp qua tất cả các cạnh cộng diện tích có hướng của tam giác được tạo bởi cạnh và điểm $O$. Một lần nữa, do dấu của diện tích, diện tích thừa sẽ bị giảm.

Phương pháp này tốt hơn vì nó có thể được khái quát hóa cho các trường hợp phức tạp hơn (chẳng hạn như khi một số cạnh là cung thay vì đường thẳng)

---
