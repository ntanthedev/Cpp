# Điểm giao nhau của các đường thẳng

---
tags:
  - Dịch
e_maxx_link: lines_intersection
---

# Điểm giao nhau của các đường thẳng

Bạn được cho hai đường thẳng, được mô tả thông qua các phương trình $a_1 x + b_1 y + c_1 = 0$ và  $a_2 x + b_2 y + c_2 = 0$.
Chúng ta phải tìm điểm giao nhau của các đường thẳng hoặc xác định rằng các đường thẳng song song.

## Giải pháp

Nếu hai đường thẳng không song song, chúng sẽ giao nhau.
Để tìm điểm giao nhau của chúng, chúng ta cần giải hệ phương trình tuyến tính sau:

$$\begin{cases} a_1 x + b_1 y + c_1 = 0 \\
a_2 x + b_2 y + c_2 = 0
\end{cases}$$

Sử dụng quy tắc Cramer, chúng ta có thể viết ngay giải pháp cho hệ thống, điều này sẽ cung cấp cho chúng ta điểm giao nhau cần thiết của các đường thẳng:

$$x = - \frac{\begin{vmatrix}c_1 & b_1 \cr c_2 & b_2\end{vmatrix}}{\begin{vmatrix}a_1 & b_1 \cr a_2 & b_2\end{vmatrix} } = - \frac{c_1 b_2 - c_2 b_1}{a_1 b_2 - a_2 b_1},$$

$$y = - \frac{\begin{vmatrix}a_1 & c_1 \cr a_2 & c_2\end{vmatrix}}{\begin{vmatrix}a_1 & b_1 \cr a_2 & b_2\end{vmatrix}} = - \frac{a_1 c_2 - a_2 c_1}{a_1 b_2 - a_2 b_1}.$$

Nếu mẫu số bằng $0$, tức là

$$\begin{vmatrix}a_1 & b_1 \cr a_2 & b_2\end{vmatrix} = a_1 b_2 - a_2 b_1 = 0 $$

thì hệ phương trình hoặc không có nghiệm (các đường thẳng song song và khác biệt) hoặc có vô số nghiệm (các đường thẳng trùng nhau).
Nếu chúng ta cần phân biệt hai trường hợp này, chúng ta phải kiểm tra xem các hệ số $c$ có tỷ lệ với cùng tỷ lệ với các hệ số $a$ và $b$ hay không.
Để làm điều đó, chúng ta chỉ cần tính toán các định thức sau và nếu cả hai đều bằng $0$, thì các đường thẳng trùng nhau:

$$\begin{vmatrix}a_1 & c_1 \cr a_2 & c_2\end{vmatrix}, \begin{vmatrix}b_1 & c_1 \cr b_2 & c_2\end{vmatrix} $$

Lưu ý, một cách tiếp cận khác để tính toán điểm giao nhau được giải thích trong bài viết [Hình học cơ bản](basic-geometry.md).

## Triển khai

```{.cpp file=line_intersection}
struct pt {
    double x, y;
};

struct line {
    double a, b, c;
};

const double EPS = 1e-9;

double det(double a, double b, double c, double d) {
    return a*d - b*c;
}

bool intersect(line m, line n, pt & res) {
    double zn = det(m.a, m.b, n.a, n.b);
    if (abs(zn) < EPS)
        return false;
    res.x = -det(m.c, m.b, n.c, n.b) / zn;
    res.y = -det(m.a, m.c, n.a, n.c) / zn;
    return true;
}

bool parallel(line m, line n) {
    return abs(det(m.a, m.b, n.a, n.b)) < EPS;
}

bool equivalent(line m, line n) {
    return abs(det(m.a, m.b, n.a, n.b)) < EPS
        && abs(det(m.a, m.c, n.a, n.c)) < EPS
        && abs(det(m.b, m.c, n.b, n.c)) < EPS;
}
```


--- 

