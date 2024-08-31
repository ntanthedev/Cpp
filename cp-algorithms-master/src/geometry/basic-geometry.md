# Hình học cơ bản

Trong bài viết này, chúng ta sẽ xem xét các phép toán cơ bản trên các điểm trong không gian Euclid, là nền tảng của toàn bộ hình học giải tích.
Chúng ta sẽ xem xét cho mỗi điểm $\mathbf r$ là vectơ $\vec{\mathbf r}$ hướng từ $\mathbf 0$ đến $\mathbf r$.
Sau đó, chúng ta sẽ không phân biệt giữa $\mathbf r$ và $\vec{\mathbf r}$ và sử dụng thuật ngữ **điểm** như một từ đồng nghĩa với **vectơ**.

## Phép toán tuyến tính

Cả điểm 2D và 3D đều duy trì không gian tuyến tính, có nghĩa là tổng các điểm và phép nhân điểm với một số nào đó được xác định. Dưới đây là những triển khai cơ bản cho 2D:

```{.cpp file=point2d}
struct point2d {
    ftype x, y;
    point2d() {}
    point2d(ftype x, ftype y): x(x), y(y) {}
    point2d& operator+=(const point2d &t) {
        x += t.x;
        y += t.y;
        return *this;
    }
    point2d& operator-=(const point2d &t) {
        x -= t.x;
        y -= t.y;
        return *this;
    }
    point2d& operator*=(ftype t) {
        x *= t;
        y *= t;
        return *this;
    }
    point2d& operator/=(ftype t) {
        x /= t;
        y /= t;
        return *this;
    }
    point2d operator+(const point2d &t) const {
        return point2d(*this) += t;
    }
    point2d operator-(const point2d &t) const {
        return point2d(*this) -= t;
    }
    point2d operator*(ftype t) const {
        return point2d(*this) *= t;
    }
    point2d operator/(ftype t) const {
        return point2d(*this) /= t;
    }
};
point2d operator*(ftype a, point2d b) {
    return b * a;
}
```
Và điểm 3D:
```{.cpp file=point3d}
struct point3d {
    ftype x, y, z;
    point3d() {}
    point3d(ftype x, ftype y, ftype z): x(x), y(y), z(z) {}
    point3d& operator+=(const point3d &t) {
        x += t.x;
        y += t.y;
        z += t.z;
        return *this;
    }
    point3d& operator-=(const point3d &t) {
        x -= t.x;
        y -= t.y;
        z -= t.z;
        return *this;
    }
    point3d& operator*=(ftype t) {
        x *= t;
        y *= t;
        z *= t;
        return *this;
    }
    point3d& operator/=(ftype t) {
        x /= t;
        y /= t;
        z /= t;
        return *this;
    }
    point3d operator+(const point3d &t) const {
        return point3d(*this) += t;
    }
    point3d operator-(const point3d &t) const {
        return point3d(*this) -= t;
    }
    point3d operator*(ftype t) const {
        return point3d(*this) *= t;
    }
    point3d operator/(ftype t) const {
        return point3d(*this) /= t;
    }
};
point3d operator*(ftype a, point3d b) {
    return b * a;
}
```

Ở đây, `ftype` là một số loại được sử dụng cho tọa độ, thường là `int`, `double` hoặc `long long`.

## Tích vô hướng (Dot product)

### Định nghĩa
Tích vô hướng (hoặc tích scalar) $\mathbf a \cdot \mathbf b$ cho các vectơ $\mathbf a$ và $\mathbf b$ có thể được định nghĩa theo hai cách giống hệt nhau.
Về mặt hình học, nó là tích của độ dài của vectơ thứ nhất với độ dài hình chiếu của vectơ thứ hai lên vectơ thứ nhất.
Như bạn có thể thấy từ hình ảnh bên dưới, hình chiếu này không gì khác ngoài $|\mathbf a| \cos \theta$ trong đó $\theta$ là góc giữa $\mathbf a$ và $\mathbf b$. Do đó, $\mathbf a\cdot  \mathbf b = |\mathbf a| \cos \theta \cdot |\mathbf b|$.

<center>![](https://upload.wikimedia.org/wikipedia/commons/thumb/3/3e/Dot_Product.svg/300px-Dot_Product.svg.png)</center>

Tích vô hướng có một số thuộc tính đáng chú ý:

1. $\mathbf a \cdot \mathbf b = \mathbf b \cdot \mathbf a$
2. $(\alpha \cdot \mathbf a)\cdot \mathbf b = \alpha \cdot (\mathbf a \cdot \mathbf b)$
3. $(\mathbf a + \mathbf b)\cdot \mathbf c = \mathbf a \cdot \mathbf c + \mathbf b \cdot \mathbf c$

Tức là nó là một hàm giao hoán tuyến tính đối với cả hai đối số.
Hãy ký hiệu các vectơ đơn vị là

$$\mathbf e_x = \begin{pmatrix} 1 \\ 0 \\ 0 \end{pmatrix}, \mathbf e_y = \begin{pmatrix} 0 \\ 1 \\ 0 \end{pmatrix}, \mathbf e_z = \begin{pmatrix} 0 \\ 0 \\ 1 \end{pmatrix}.$$

Với ký hiệu này, chúng ta có thể viết vectơ $\mathbf r = (x;y;z)$ là $r = x \cdot \mathbf e_x + y \cdot \mathbf e_y + z \cdot \mathbf e_z$.
Và kể từ khi đối với các vectơ đơn vị

$$\mathbf e_x\cdot \mathbf e_x = \mathbf e_y\cdot \mathbf e_y = \mathbf e_z\cdot \mathbf e_z = 1,\\
\mathbf e_x\cdot \mathbf e_y = \mathbf e_y\cdot \mathbf e_z = \mathbf e_z\cdot \mathbf e_x = 0$$

chúng ta có thể thấy rằng về mặt tọa độ cho $\mathbf a = (x_1;y_1;z_1)$ và $\mathbf b = (x_2;y_2;z_2)$ thì

$$\mathbf a\cdot \mathbf b = (x_1 \cdot \mathbf e_x + y_1 \cdot\mathbf e_y + z_1 \cdot\mathbf e_z)\cdot( x_2 \cdot\mathbf e_x + y_2 \cdot\mathbf e_y + z_2 \cdot\mathbf e_z) = x_1 x_2 + y_1 y_2 + z_1 z_2$$

Đó cũng là định nghĩa đại số của tích vô hướng.
Từ đây chúng ta có thể viết các hàm tính toán nó.

```{.cpp file=dotproduct}
ftype dot(point2d a, point2d b) {
    return a.x * b.x + a.y * b.y;
}
ftype dot(point3d a, point3d b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}
```

Khi giải quyết các bài toán, người ta nên sử dụng định nghĩa đại số để tính tích vô hướng, nhưng hãy nhớ định nghĩa và thuộc tính hình học để sử dụng nó.

### Thuộc tính

Chúng ta có thể định nghĩa nhiều thuộc tính hình học thông qua tích vô hướng.
Ví dụ

1. Chuẩn của $\mathbf a$ (độ dài bình phương): $|\mathbf a|^2 = \mathbf a\cdot \mathbf a$
2. Độ dài của $\mathbf a$: $|\mathbf a| = \sqrt{\mathbf a\cdot \mathbf a}$
3. Hình chiếu của $\mathbf a$ lên $\mathbf b$: $\dfrac{\mathbf a\cdot\mathbf b}{|\mathbf b|}$
4. Góc giữa các vectơ: $\arccos \left(\dfrac{\mathbf a\cdot \mathbf b}{|\mathbf a| \cdot |\mathbf b|}\right)$
5. Từ điểm trước đó, chúng ta có thể thấy rằng tích vô hướng là dương nếu góc giữa chúng là góc nhọn, âm nếu nó là góc tù và nó bằng 0 nếu chúng là trực giao, tức là chúng tạo thành một góc vuông.

Lưu ý rằng tất cả các hàm này không phụ thuộc vào số chiều, do đó chúng sẽ giống nhau cho trường hợp 2D và 3D:

```{.cpp file=dotproperties}
ftype norm(point2d a) {
    return dot(a, a);
}
double abs(point2d a) {
    return sqrt(norm(a));
}
double proj(point2d a, point2d b) {
    return dot(a, b) / abs(b);
}
double angle(point2d a, point2d b) {
    return acos(dot(a, b) / abs(a) / abs(b));
}
```

Để xem thuộc tính quan trọng tiếp theo, chúng ta nên xem xét tập hợp các điểm $\mathbf r$ mà $\mathbf r\cdot \mathbf a = C$ cho một số hằng số cố định $C$.
Bạn có thể thấy rằng tập hợp các điểm này chính xác là tập hợp các điểm mà hình chiếu lên $\mathbf a$ là điểm $C \cdot \dfrac{\mathbf a}{|\mathbf a|}$ và chúng tạo thành siêu phẳng trực giao với $\mathbf a$.
Bạn có thể thấy vectơ $\mathbf a$ cùng với một số vectơ như vậy có cùng tích vô hướng với nó trong 2D trên hình bên dưới:

<center>![Các vectơ có cùng tích vô hướng với a](https://i.imgur.com/eyO7St4.png)</center>

Trong 2D, các vectơ này sẽ tạo thành một đường thẳng, trong 3D, chúng sẽ tạo thành một mặt phẳng.
Lưu ý rằng kết quả này cho phép chúng ta định nghĩa một đường thẳng trong 2D là $\mathbf r\cdot \mathbf n=C$ hoặc $(\mathbf r - \mathbf r_0)\cdot \mathbf n=0$ trong đó $\mathbf n$ là vectơ trực giao với đường thẳng và $\mathbf r_0$ là bất kỳ vectơ nào đã có trên đường thẳng và $C = \mathbf r_0\cdot \mathbf n$.
Theo cách tương tự, một mặt phẳng có thể được định nghĩa trong 3D.

## Tích có hướng (Cross product)

### Định nghĩa

Giả sử bạn có ba vectơ $\mathbf a$, $\mathbf b$ và $\mathbf c$ trong không gian 3D được nối trong một hình hộp như trong hình bên dưới:
<center>![Ba vectơ](https://upload.wikimedia.org/wikipedia/commons/thumb/3/3e/Parallelepiped_volume.svg/240px-Parallelepiped_volume.svg.png)</center>

Bạn sẽ tính thể tích của nó như thế nào?
Từ trường học, chúng ta biết rằng chúng ta nên nhân diện tích của đáy với chiều cao, đó là hình chiếu của $\mathbf a$ lên hướng trực giao với đáy.
Điều đó có nghĩa là nếu chúng ta định nghĩa $\mathbf b \times \mathbf c$ là vectơ trực giao với cả $\mathbf b$ và $\mathbf c$ và độ dài của nó bằng với diện tích của hình bình hành được tạo bởi $\mathbf b$ và $\mathbf c$ thì $|\mathbf a\cdot (\mathbf b\times\mathbf c)|$ sẽ bằng thể tích của hình hộp.
Để toàn vẹn, chúng ta sẽ nói rằng $\mathbf b\times \mathbf c$ sẽ luôn được hướng theo cách sao cho phép quay từ vectơ $\mathbf b$ đến vectơ $\mathbf c$ từ điểm của $\mathbf b\times \mathbf c$ luôn ngược chiều kim đồng hồ (xem hình bên dưới).

<center>![tích có hướng](https://upload.wikimedia.org/wikipedia/commons/thumb/b/b0/Cross_product_vector.svg/250px-Cross_product_vector.svg.png)</center>

Điều này định nghĩa tích có hướng (hoặc tích vectơ) $\mathbf b\times \mathbf c$ của các vectơ $\mathbf b$ và $\mathbf c$ và tích hỗn hợp (triple product) $\mathbf a\cdot(\mathbf b\times \mathbf c)$ của các vectơ $\mathbf a$, $\mathbf b$ và $\mathbf c$.

Một số thuộc tính đáng chú ý của tích có hướng và tích hỗn hợp:

1.  $\mathbf a\times \mathbf b = -\mathbf b\times \mathbf a$
2.  $(\alpha \cdot \mathbf a)\times \mathbf b = \alpha \cdot (\mathbf a\times \mathbf b)$
3.  Đối với bất kỳ $\mathbf b$ và $\mathbf c$ nào, tồn tại chính xác một vectơ $\mathbf r$ sao cho $\mathbf a\cdot (\mathbf b\times \mathbf c) = \mathbf a\cdot\mathbf r$ cho bất kỳ vectơ $\mathbf a$ nào. <br> Thật vậy, nếu có hai vectơ như vậy $\mathbf r_1$ và $\mathbf r_2$ thì $\mathbf a\cdot (\mathbf r_1 - \mathbf r_2)=0$ cho tất cả các vectơ $\mathbf a$ mà điều này chỉ có thể xảy ra khi $\mathbf r_1 = \mathbf r_2$.
4.  $\mathbf a\cdot (\mathbf b\times \mathbf c) = \mathbf b\cdot (\mathbf c\times \mathbf a) = -\mathbf a\cdot( \mathbf c\times \mathbf b)$
5.  $(\mathbf a + \mathbf b)\times \mathbf c = \mathbf a\times \mathbf c + \mathbf b\times \mathbf c$.
    Thật vậy đối với mọi vectơ $\mathbf r$ chuỗi phương trình đều đúng:

    \[\mathbf r\cdot( (\mathbf a + \mathbf b)\times \mathbf c) = (\mathbf a + \mathbf b) \cdot (\mathbf c\times \mathbf r) =  \mathbf a \cdot(\mathbf c\times \mathbf r) + \mathbf b\cdot(\mathbf c\times \mathbf r) = \mathbf r\cdot (\mathbf a\times \mathbf c) + \mathbf r\cdot(\mathbf b\times \mathbf c) = \mathbf r\cdot(\mathbf a\times \mathbf c + \mathbf b\times \mathbf c)\]

    Điều này chứng minh $(\mathbf a + \mathbf b)\times \mathbf c = \mathbf a\times \mathbf c + \mathbf b\times \mathbf c$ do điểm 3.

6.  $|\mathbf a\times \mathbf b|=|\mathbf a| \cdot |\mathbf b| \sin \theta$ trong đó $\theta$ là góc giữa $\mathbf a$ và $\mathbf b$, vì $|\mathbf a\times \mathbf b|$ bằng với diện tích của hình bình hành được tạo bởi $\mathbf a$ và $\mathbf b$.

Với tất cả những điều này và phương trình sau đúng với các vectơ đơn vị

$$\mathbf e_x\times \mathbf e_x = \mathbf e_y\times \mathbf e_y = \mathbf e_z\times \mathbf e_z = \mathbf 0,\\
\mathbf e_x\times \mathbf e_y = \mathbf e_z,~\mathbf e_y\times \mathbf e_z = \mathbf e_x,~\mathbf e_z\times \mathbf e_x = \mathbf e_y$$

chúng ta có thể tính tích có hướng của $\mathbf a = (x_1;y_1;z_1)$ và $\mathbf b = (x_2;y_2;z_2)$ ở dạng tọa độ:

$$\mathbf a\times \mathbf b = (x_1 \cdot \mathbf e_x + y_1 \cdot \mathbf e_y + z_1 \cdot \mathbf e_z)\times (x_2 \cdot \mathbf e_x + y_2 \cdot \mathbf e_y + z_2 \cdot \mathbf e_z) =$$

$$(y_1 z_2 - z_1 y_2)\mathbf e_x  + (z_1 x_2 - x_1 z_2)\mathbf e_y + (x_1 y_2 - y_1 x_2)$$

Cũng có thể được viết ở dạng gọn hơn:

$$\mathbf a\times \mathbf b = \begin{vmatrix}\mathbf e_x & \mathbf e_y & \mathbf e_z \\ x_1 & y_1 & z_1 \\ x_2 & y_2 & z_2 \end{vmatrix},~a\cdot(b\times c) = \begin{vmatrix} x_1 & y_1 & z_1 \\ x_2 & y_2 & z_2 \\ x_3 & y_3 & z_3 \end{vmatrix}$$

Ở đây, $| \cdot |$ là viết tắt của định thức của ma trận.

Một số loại tích có hướng (cụ thể là tích giả vô hướng) cũng có thể được triển khai trong trường hợp 2D.
Nếu chúng ta muốn tính diện tích hình bình hành được tạo bởi các vectơ $\mathbf a$ và $\mathbf b$, chúng ta sẽ tính $|\mathbf e_z\cdot(\mathbf a\times \mathbf b)| = |x_1 y_2 - y_1 x_2|$.
Một cách khác để thu được kết quả tương tự là nhân $|\mathbf a|$ (đáy của hình bình hành) với chiều cao, là hình chiếu của vectơ $\mathbf b$ lên vectơ $\mathbf a$ được quay $90^\circ$ lần lượt là $\widehat{\mathbf a}=(-y_1;x_1)$.
Tức là để tính $|\widehat{\mathbf a}\cdot\mathbf b|=|x_1y_2 - y_1 x_2|$.

Nếu chúng ta xem xét dấu thì diện tích sẽ dương nếu phép quay từ $\mathbf a$ sang $\mathbf b$ (tức là từ góc nhìn của điểm $\mathbf e_z$) được thực hiện ngược chiều kim đồng hồ và âm ngược lại.
Điều đó định nghĩa tích giả vô hướng.
Lưu ý rằng nó cũng bằng $|\mathbf a| \cdot |\mathbf b| \sin \theta$ trong đó $\theta$ là góc từ $\mathbf a$ đến $\mathbf b$ tính ngược chiều kim đồng hồ (và âm nếu phép quay là theo chiều kim đồng hồ).

Hãy triển khai tất cả những thứ này!

```{.cpp file=crossproduct}
point3d cross(point3d a, point3d b) {
    return point3d(a.y * b.z - a.z * b.y,
                   a.z * b.x - a.x * b.z,
                   a.x * b.y - a.y * b.x);
}
ftype triple(point3d a, point3d b, point3d c) {
    return dot(a, cross(b, c));
}
ftype cross(point2d a, point2d b) {
    return a.x * b.y - a.y * b.x;
}
```

### Thuộc tính

Đối với tích có hướng, nó bằng với vectơ 0 nếu và chỉ khi các vectơ $\mathbf a$ và $\mathbf b$ là đồng tuyến (chúng tạo thành một đường thẳng chung, tức là chúng song song).
Điều tương tự cũng xảy ra đối với tích hỗn hợp, nó bằng 0 nếu và chỉ khi các vectơ $\mathbf a$, $\mathbf b$ và $\mathbf c$ là đồng phẳng (chúng tạo thành một mặt phẳng chung).

Từ đây, chúng ta có thể thu được các phương trình phổ quát xác định đường thẳng và mặt phẳng.
Một đường thẳng có thể được định nghĩa thông qua vectơ hướng $\mathbf d$ của nó và một điểm ban đầu $\mathbf r_0$ hoặc bằng hai điểm $\mathbf a$ và $\mathbf b$.
Nó được định nghĩa là $(\mathbf r - \mathbf r_0)\times\mathbf d=0$ hoặc là $(\mathbf r - \mathbf a)\times (\mathbf b - \mathbf a) = 0$.
Đối với mặt phẳng, nó có thể được định nghĩa bởi ba điểm $\mathbf a$, $\mathbf b$ và $\mathbf c$ là $(\mathbf r - \mathbf a)\cdot((\mathbf b - \mathbf a)\times (\mathbf c - \mathbf a))=0$ hoặc bởi điểm ban đầu $\mathbf r_0$ và hai vectơ hướng nằm trong mặt phẳng này $\mathbf d_1$ và $\mathbf d_2$: $(\mathbf r - \mathbf r_0)\cdot(\mathbf d_1\times \mathbf d_2)=0$.

Trong 2D, tích giả vô hướng cũng có thể được sử dụng để kiểm tra hướng giữa hai vectơ vì nó là dương nếu phép quay từ vectơ thứ nhất sang vectơ thứ hai là theo chiều kim đồng hồ và âm ngược lại.
Và tất nhiên, nó có thể được sử dụng để tính diện tích của đa giác, được mô tả trong một bài viết khác.
Tích hỗn hợp có thể được sử dụng cho cùng một mục đích trong không gian 3D.

## Bài tập

### Giao điểm của đường thẳng

Có nhiều cách có thể để xác định một đường thẳng trong 2D và bạn không nên ngần ngại kết hợp chúng.
Ví dụ: chúng ta có hai đường thẳng và chúng ta muốn tìm điểm giao nhau của chúng.
Chúng ta có thể nói rằng tất cả các điểm từ đường thẳng thứ nhất có thể được tham số hóa là $\mathbf r = \mathbf a_1 + t \cdot \mathbf d_1$ trong đó $\mathbf a_1$ là điểm ban đầu, $\mathbf d_1$ là hướng và $t$ là một số tham số thực.
Đối với đường thẳng thứ hai, tất cả các điểm của nó phải thỏa mãn $(\mathbf r - \mathbf a_2)\times \mathbf d_2=0$. Từ đây, chúng ta có thể dễ dàng tìm tham số $t$:

$$(\mathbf a_1 + t \cdot \mathbf d_1 - \mathbf a_2)\times \mathbf d_2=0 \quad\Rightarrow\quad t = \dfrac{(\mathbf a_2 - \mathbf a_1)\times\mathbf d_2}{\mathbf d_1\times \mathbf d_2}$$

Hãy triển khai hàm để giao nhau hai đường thẳng.

```{.cpp file=basic_line_intersection}
point2d intersect(point2d a1, point2d d1, point2d a2, point2d d2) {
    return a1 + cross(a2 - a1, d2) / cross(d1, d2) * d1;
}
```

### Giao điểm của mặt phẳng

Tuy nhiên, đôi khi có thể khó sử dụng một số hiểu biết hình học.
Ví dụ: bạn được cung cấp ba mặt phẳng được xác định bởi các điểm ban đầu $\mathbf a_i$ và các hướng $\mathbf d_i$ và bạn muốn tìm điểm giao nhau của chúng.
Bạn có thể lưu ý rằng bạn chỉ cần giải hệ phương trình:

$$\begin{cases}\mathbf r\cdot \mathbf n_1 = \mathbf a_1\cdot \mathbf n_1, \\ \mathbf r\cdot \mathbf n_2 = \mathbf a_2\cdot \mathbf n_2, \\ \mathbf r\cdot \mathbf n_3 = \mathbf a_3\cdot \mathbf n_3\end{cases}$$

Thay vì suy nghĩ về cách tiếp cận hình học, bạn có thể tìm ra cách tiếp cận đại số có thể thu được ngay lập tức.
Ví dụ: cho rằng bạn đã triển khai lớp điểm, bạn sẽ dễ dàng giải hệ thống này bằng cách sử dụng quy tắc Cramer vì tích hỗn hợp chỉ đơn giản là định thức của ma trận thu được từ các vectơ là cột của nó:

```{.cpp file=plane_intersection}
point3d intersect(point3d a1, point3d n1, point3d a2, point3d n2, point3d a3, point3d n3) {
    point3d x(n1.x, n2.x, n3.x);
    point3d y(n1.y, n2.y, n3.y);
    point3d z(n1.z, n2.z, n3.z); 
    point3d d(dot(a1, n1), dot(a2, n2), dot(a3, n3));
    return point3d(triple(d, y, z),
                   triple(x, d, z),
                   triple(x, y, d)) / triple(n1, n2, n3);
}
```

Bây giờ bạn có thể tự mình thử tìm ra các cách tiếp cận cho các phép toán hình học phổ biến để làm quen với tất cả những thứ này.
