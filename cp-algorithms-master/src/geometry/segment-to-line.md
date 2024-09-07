# Tìm phương trình của đường thẳng cho một đoạn thẳng

---
tags:
  - Dịch
e_maxx_link: segment_to_line
---

# Tìm phương trình của đường thẳng cho một đoạn thẳng

Nhiệm vụ là: cho tọa độ của hai đầu của một đoạn thẳng, hãy xây dựng một đường thẳng đi qua nó.

Chúng ta giả sử rằng đoạn thẳng là không suy biến, tức là có độ dài lớn hơn 0 (nếu không, tất nhiên, vô số đường thẳng khác nhau đi qua nó).

### Trường hợp hai chiều

Cho đoạn thẳng đã cho là $PQ$, tức là các tọa độ đã biết của hai đầu của nó là $P_x , P_y , Q_x , Q_y$.

Cần phải xây dựng **phương trình của một đường thẳng trên mặt phẳng** đi qua đoạn thẳng này, tức là tìm các hệ số $A , B , C$ trong phương trình của một đường thẳng:

$$A x + B y + C = 0.$$

Lưu ý rằng đối với bộ ba $(A, B, C)$ cần thiết, có **vô số** giải pháp mô tả đoạn thẳng đã cho:
bạn có thể nhân cả ba hệ số với một số khác không tùy ý và nhận được cùng một đường thẳng.
Do đó, nhiệm vụ của chúng ta là tìm một trong những bộ ba này.

Rất dễ dàng để xác minh (bằng cách thay thế các biểu thức này và tọa độ của các điểm $P$ và $Q$ vào phương trình của một đường thẳng) rằng tập hợp các hệ số sau phù hợp:

$$\begin{align}
A &= P_y - Q_y, \\
B &= Q_x - P_x, \\
C &= - A P_x - B P_y.
\end{align}$$

### Trường hợp số nguyên

Một ưu điểm quan trọng của phương pháp xây dựng đường thẳng này là nếu tọa độ của hai đầu là số nguyên thì các hệ số thu được cũng sẽ là **số nguyên**. Trong một số trường hợp, điều này cho phép người ta thực hiện các phép toán hình học mà hoàn toàn không cần dùng đến số thực.

Tuy nhiên, có một nhược điểm nhỏ: đối với cùng một đường thẳng, có thể thu được các bộ ba hệ số khác nhau.
Để tránh điều này, nhưng không đi xa khỏi các hệ số nguyên, bạn có thể áp dụng kỹ thuật sau, thường được gọi là **hợp lý hóa** (rationing). Tìm [ước chung lớn nhất](../algebra/euclid-algorithm.md) của các số $| A | , | B | , | C |$, chúng ta chia cả ba hệ số cho nó, và sau đó chúng ta thực hiện chuẩn hóa dấu: nếu $A <0$ hoặc $A = 0, B <0$ thì nhân cả ba hệ số với $-1$.
Kết quả là, chúng ta sẽ đi đến kết luận rằng đối với các đường thẳng giống hệt nhau, các bộ ba hệ số giống hệt nhau sẽ thu được, điều này giúp dễ dàng kiểm tra xem các đường thẳng có bằng nhau hay không.

### Trường hợp số thực

Khi làm việc với số thực, bạn nên luôn lưu ý đến các lỗi.

Các hệ số $A$ và $B$ sẽ có thứ tự của tọa độ ban đầu, hệ số $C$ có thứ tự là bình phương của chúng. Đây có thể đã là những con số khá lớn, và ví dụ, khi chúng ta [giao nhau các đường thẳng](lines-intersection.md), chúng sẽ trở nên lớn hơn nữa, điều này có thể dẫn đến sai số làm tròn lớn ngay cả khi tọa độ của các điểm cuối là theo thứ tự $10^3$.

Do đó, khi làm việc với số thực, người ta mong muốn tạo ra cái gọi là **chuẩn hóa** (normalization), điều này rất đơn giản: cụ thể là, để tạo các hệ số sao cho $A ^ 2 + B ^ 2 = 1$. Để làm điều này, hãy tính số $Z$:

$$Z = \sqrt{A ^ 2 + B ^ 2},$$

và chia cả ba hệ số $A , B , C$ cho nó.

Do đó, thứ tự của các hệ số $A$ và $B$ sẽ không phụ thuộc vào thứ tự của các tọa độ đầu vào, và hệ số $C$ sẽ có cùng thứ tự với các tọa độ đầu vào. Trong thực tế, điều này dẫn đến cải thiện đáng kể về độ chính xác của các phép tính.

Cuối cùng, chúng ta đề cập đến **so sánh** các đường thẳng - trên thực tế, sau khi chuẩn hóa như vậy, đối với cùng một đường thẳng, chỉ có thể thu được hai bộ ba hệ số: cho đến khi nhân với $-1$.
Theo đó, nếu chúng ta thực hiện chuẩn hóa bổ sung có tính đến dấu (nếu $A < -\varepsilon$ hoặc $| A | < \varepsilon$, $B <- \varepsilon$ thì nhân với $-1$), các hệ số kết quả sẽ là duy nhất.

### Trường hợp ba chiều và nhiều chiều

Ngay cả trong trường hợp ba chiều, **không có phương trình đơn giản** nào mô tả một đường thẳng (nó có thể được định nghĩa là giao điểm của hai mặt phẳng, tức là một hệ hai phương trình, nhưng đây là một phương pháp bất tiện).

Do đó, trong trường hợp ba chiều và nhiều chiều, chúng ta phải sử dụng **phương pháp tham số để xác định một đường thẳng**, tức là một điểm $p$ và một vectơ $v$:

$$p + v t, ~~~ t \in \mathbb{R}.$$

Tức là. một đường thẳng là tất cả các điểm có thể thu được từ một điểm $p$ cộng với một vectơ $v$ với một hệ số tùy ý.

**Xây dựng** một đường thẳng ở dạng tham số dọc theo tọa độ của hai đầu của một đoạn thẳng là điều tầm thường, chúng ta chỉ cần lấy một đầu của đoạn thẳng cho điểm $p$ và vectơ từ đầu thứ nhất đến đầu thứ hai - cho vectơ $v$.

---



