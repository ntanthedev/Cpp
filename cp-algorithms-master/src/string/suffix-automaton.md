# Tự động hóa hậu tố

---
tags:
  - Dịch
e_maxx_link: suffix_automata
---

# Tự động hóa hậu tố (Suffix Automaton)

**Tự động hóa hậu tố** (Suffix Automaton) là một cấu trúc dữ liệu mạnh mẽ cho phép giải quyết nhiều bài toán liên quan đến chuỗi.

Ví dụ: bạn có thể tìm kiếm tất cả các lần xuất hiện của một chuỗi trong chuỗi khác hoặc đếm số lượng chuỗi con khác nhau của một chuỗi nhất định.
Cả hai nhiệm vụ đều có thể được giải quyết trong thời gian tuyến tính với sự trợ giúp của tự động hóa hậu tố.

Theo trực giác, tự động hóa hậu tố có thể được hiểu là một dạng nén của **tất cả các chuỗi con** của một chuỗi nhất định.
Một thực tế ấn tượng là tự động hóa hậu tố chứa tất cả thông tin này ở dạng nén cao.
Đối với một chuỗi có độ dài $n$, nó chỉ yêu cầu bộ nhớ $O(n)$.
Hơn nữa, nó cũng có thể được xây dựng trong thời gian $O(n)$ (nếu chúng ta coi kích thước $k$ của bảng chữ cái là một hằng số), nếu không thì cả độ phức tạp về bộ nhớ và thời gian sẽ là $O(n \log k)$.

Tính tuyến tính của kích thước của tự động hóa hậu tố lần đầu tiên được phát hiện vào năm 1983 bởi Blumer và cộng sự, và vào năm 1985, các thuật toán tuyến tính đầu tiên để xây dựng được trình bày bởi Crochemore và Blumer.

## Định nghĩa tự động hóa hậu tố

Tự động hóa hậu tố cho một chuỗi $s$ nhất định là **DFA** (máy tự động hữu hạn xác định / máy trạng thái hữu hạn xác định) tối thiểu chấp nhận tất cả các hậu tố của chuỗi $s$.

Nói cách khác:

- Tự động hóa hậu tố là một đồ thị có hướng phi chu trình.
  Các đỉnh được gọi là **trạng thái** và các cạnh được gọi là **chuyển đổi** giữa các trạng thái.
- Một trong các trạng thái $t_0$ là **trạng thái ban đầu** và nó phải là nguồn của đồ thị (tất cả các trạng thái khác đều có thể đạt được từ $t_0$).
- Mỗi **chuyển đổi** được gắn nhãn bằng một số ký tự.
  Tất cả các chuyển đổi bắt nguồn từ một trạng thái phải có nhãn **khác nhau**.
- Một hoặc nhiều trạng thái được đánh dấu là **trạng thái kết thúc**.
  Nếu chúng ta bắt đầu từ trạng thái ban đầu $t_0$ và di chuyển dọc theo các chuyển đổi đến trạng thái kết thúc, thì nhãn của các chuyển đổi đã qua phải đánh vần một trong các hậu tố của chuỗi $s$.
  Mỗi hậu tố của $s$ phải được đánh vần bằng cách sử dụng một đường dẫn từ $t_0$ đến trạng thái kết thúc.
- Tự động hóa hậu tố chứa số lượng đỉnh tối thiểu trong số tất cả các tự động thỏa mãn các điều kiện được mô tả ở trên.

### Thuộc tính chuỗi con

Thuộc tính đơn giản và quan trọng nhất của tự động hóa hậu tố là nó chứa thông tin về tất cả các chuỗi con của chuỗi $s$.
Bất kỳ đường dẫn nào bắt đầu từ trạng thái ban đầu $t_0$, nếu chúng ta viết ra nhãn của các chuyển đổi, tạo thành một **chuỗi con** của $s$.
Và ngược lại, mọi chuỗi con của $s$ tương ứng với một đường dẫn nhất định bắt đầu từ $t_0$.

Để đơn giản hóa các giải thích, chúng ta sẽ nói rằng chuỗi con **tương ứng** với đường dẫn đó (bắt đầu từ $t_0$ và nhãn đánh vần chuỗi con).
Và ngược lại, chúng ta nói rằng bất kỳ đường dẫn nào **tương ứng** với chuỗi được đánh vần bằng nhãn của nó.

Một hoặc nhiều đường dẫn có thể dẫn đến một trạng thái.
Do đó, chúng ta sẽ nói rằng một trạng thái **tương ứng** với tập hợp các chuỗi, tương ứng với các đường dẫn này.

### Ví dụ về tự động hóa hậu tố được xây dựng

Ở đây chúng ta sẽ trình bày một số ví dụ về tự động hóa hậu tố cho một số chuỗi đơn giản.

Chúng ta sẽ biểu thị trạng thái ban đầu bằng màu xanh lam và trạng thái kết thúc bằng màu xanh lục.

Đối với chuỗi $s =~ \text{""}$:

![Tự động hóa hậu tố cho ""](SA.png)

Đối với chuỗi $s =~ \text{"a"}$:

![Tự động hóa hậu tố cho "a"](SAa.png)

Đối với chuỗi $s =~ \text{"aa"}$:

![Tự động hóa hậu tố cho "aa"](SAaa.png)

Đối với chuỗi $s =~ \text{"ab"}$:

![Tự động hóa hậu tố cho "ab"](SAab.png)

Đối với chuỗi $s =~ \text{"aba"}$:

![Tự động hóa hậu tố cho "aba"](SAaba.png)

Đối với chuỗi $s =~ \text{"abb"}$:

![Tự động hóa hậu tố cho "abb"](SAabb.png)

Đối với chuỗi $s =~ \text{"abbb"}$:

![Tự động hóa hậu tố cho "abbb"](SAabbb.png)

## Xây dựng trong thời gian tuyến tính

Trước khi chúng ta mô tả thuật toán để xây dựng tự động hóa hậu tố trong thời gian tuyến tính, chúng ta cần giới thiệu một số khái niệm mới và bằng chứng đơn giản, điều này sẽ rất quan trọng trong việc hiểu cách xây dựng.

### Vị trí kết thúc $endpos$ {data-toc-label="Vị trí kết thúc"}

Xét bất kỳ chuỗi con $t$ khác rỗng nào của chuỗi $s$.
Chúng ta sẽ biểu thị bằng $endpos(t)$ tập hợp tất cả các vị trí trong chuỗi $s$, trong đó các lần xuất hiện của $t$ kết thúc. Ví dụ: chúng ta có $endpos(\text{"bc"}) = \{2, 4\}$ cho chuỗi $\text{"abcbc"}$.

Chúng ta sẽ gọi hai chuỗi con $t_1$ và $t_2$ là tương đương $endpos$, nếu tập hợp kết thúc của chúng trùng nhau: $endpos(t_1) = endpos(t_2)$.
Do đó, tất cả các chuỗi con khác rỗng của chuỗi $s$ có thể được phân tách thành một số **lớp tương đương** theo tập hợp $endpos$ của chúng.

Hóa ra, trong máy hậu tố, các chuỗi con tương đương $endpos$ **tương ứng với cùng một trạng thái**.
Nói cách khác, số lượng trạng thái trong tự động hóa hậu tố bằng với số lượng lớp tương đương trong số tất cả các chuỗi con, cộng với trạng thái ban đầu.
Mỗi trạng thái của tự động hóa hậu tố tương ứng với một hoặc nhiều chuỗi con có cùng giá trị $endpos$.

Chúng ta sẽ mô tả thuật toán xây dựng sau bằng cách sử dụng giả định này.
Sau đó, chúng ta sẽ thấy rằng tất cả các thuộc tính cần thiết của tự động hóa hậu tố, ngoại trừ tính tối thiểu, đều được đáp ứng.
Và tính tối thiểu theo sau từ định lý Nerode (sẽ không được chứng minh trong bài viết này).

Chúng ta có thể đưa ra một số quan sát quan trọng liên quan đến các giá trị $endpos$:

**Bổ đề 1**:
Hai chuỗi con khác rỗng $u$ và $w$ (với $length(u) \le length(w)$) tương đương $endpos$, nếu và chỉ khi chuỗi $u$ xuất hiện trong $s$ chỉ ở dạng hậu tố của $w$.

Bằng chứng là rõ ràng.
Nếu $u$ và $w$ có cùng giá trị $endpos$, thì $u$ là hậu tố của $w$ và chỉ xuất hiện dưới dạng hậu tố của $w$ trong $s$.
Và nếu $u$ là hậu tố của $w$ và chỉ xuất hiện dưới dạng hậu tố trong $s$, thì các giá trị $endpos$ bằng nhau theo định nghĩa.

**Bổ đề 2**:
Xét hai chuỗi con khác rỗng $u$ và $w$ (với $length(u) \le length(w)$).
Sau đó, tập hợp $endpos$ của chúng hoặc không giao nhau chút nào, hoặc $endpos(w)$ là tập con của $endpos(u)$.
Và nó phụ thuộc vào việc $u$ có phải là hậu tố của $w$ hay không.

$$\begin{cases}
endpos(w) \subseteq endpos(u) & \text{nếu } u \text{ là hậu tố của } w \\\\
endpos(w) \cap endpos(u) = \emptyset & \text{ngược lại}
\end{cases}$$

Chứng minh:
Nếu tập hợp $endpos(u)$ và $endpos(w)$ có ít nhất một phần tử chung, thì cả hai chuỗi $u$ và $w$ đều kết thúc ở vị trí đó, tức là $u$ là hậu tố của $w$.
Nhưng sau đó, ở mỗi lần xuất hiện của $w$ cũng xuất hiện chuỗi con $u$, có nghĩa là $endpos(w)$ là tập con của $endpos(u)$.

**Bổ đề 3**:
Xét một lớp tương đương $endpos$.
Sắp xếp tất cả các chuỗi con trong lớp này theo chiều dài giảm dần.
Sau đó, trong chuỗi kết quả, mỗi chuỗi con sẽ ngắn hơn chuỗi con trước đó một ký tự và đồng thời sẽ là hậu tố của chuỗi con trước đó.
Nói cách khác, trong cùng một lớp tương đương, các chuỗi con ngắn hơn thực sự là hậu tố của các chuỗi con dài hơn và chúng nhận tất cả các độ dài có thể có trong một khoảng nhất định $[x; y]$.

Chứng minh:
Sửa một số lớp tương đương $endpos$.
Nếu nó chỉ chứa một chuỗi, thì bổ đề rõ ràng là đúng.
Bây giờ, giả sử rằng số lượng chuỗi trong lớp lớn hơn một.

Theo Bổ đề 1, hai chuỗi tương đương $endpos$ khác nhau luôn theo cách mà chuỗi ngắn hơn là hậu tố thực sự của chuỗi dài hơn.
Do đó, không thể có hai chuỗi có cùng độ dài trong lớp tương đương.

Hãy biểu thị bằng $w$ chuỗi dài nhất và bằng $u$ chuỗi ngắn nhất trong lớp tương đương.
Theo Bổ đề 1, chuỗi $u$ là hậu tố thực sự của chuỗi $w$.
Bây giờ hãy xem xét bất kỳ hậu tố nào của $w$ có độ dài trong khoảng $[length(u); length(w)]$.
Dễ dàng nhận thấy hậu tố này cũng nằm trong cùng một lớp tương đương.
Bởi vì hậu tố này chỉ có thể xuất hiện dưới dạng hậu tố của $w$ trong chuỗi $s$ (vì hậu tố $u$ ngắn hơn cũng chỉ xuất hiện dưới dạng hậu tố của $w$).
Do đó, theo Bổ đề 1, hậu tố này tương đương $endpos$ với chuỗi $w$.

### Liên kết hậu tố $link$ {data-toc-label="Liên kết hậu tố"}

Xét một số trạng thái $v \ne t_0$ trong tự động.
Như chúng ta đã biết, trạng thái $v$ tương ứng với lớp các chuỗi có cùng giá trị $endpos$.
Và nếu chúng ta biểu thị bằng $w$ chuỗi dài nhất trong số các chuỗi này, thì tất cả các chuỗi khác là hậu tố của $w$.

Chúng ta cũng biết một vài hậu tố đầu tiên của một chuỗi $w$ (nếu chúng ta xét các hậu tố theo thứ tự giảm dần về độ dài) đều nằm trong lớp tương đương này và tất cả các hậu tố khác (ít nhất là một hậu tố khác - hậu tố rỗng) nằm trong một số lớp khác.
Chúng ta biểu thị bằng $t$ hậu tố lớn nhất như vậy và tạo liên kết hậu tố đến nó.

Nói cách khác, **liên kết hậu tố** (suffix link) $link(v)$ dẫn đến trạng thái tương ứng với **hậu tố dài nhất** của $w$ nằm trong một lớp tương đương $endpos$ khác.

Ở đây chúng ta giả định rằng trạng thái ban đầu $t_0$ tương ứng với lớp tương đương của chính nó (chỉ chứa chuỗi rỗng), và để thuận tiện, chúng ta đặt $endpos(t_0) = \{-1, 0, \dots, length(s)-1\}$.

**Bổ đề 4**:
Các liên kết hậu tố tạo thành một **cây** có gốc là $t_0$.

Chứng minh:
Xét một trạng thái tùy ý $v \ne t_0$.
Liên kết hậu tố $link(v)$ dẫn đến trạng thái tương ứng với các chuỗi có độ dài nhỏ hơn (điều này theo sau từ định nghĩa của liên kết hậu tố và từ Bổ đề 3).
Do đó, bằng cách di chuyển dọc theo các liên kết hậu tố, sớm muộn gì chúng ta cũng sẽ đến trạng thái ban đầu $t_0$, tương ứng với chuỗi rỗng.

**Bổ đề 5**:
Nếu chúng ta xây dựng một cây bằng cách sử dụng các tập hợp $endpos$ (theo quy tắc là tập hợp của một nút cha chứa các tập hợp của tất cả các con là tập con), thì cấu trúc sẽ trùng với cây của liên kết hậu tố.

Chứng minh:
Thực tế là chúng ta có thể xây dựng một cây bằng cách sử dụng các tập hợp $endpos$ theo sau trực tiếp từ Bổ đề 2 (rằng bất kỳ hai tập hợp nào hoặc không giao nhau hoặc một tập hợp được chứa trong tập hợp kia).

Bây giờ hãy xem xét một trạng thái tùy ý $v \ne t_0$ và liên kết hậu tố $link(v)$ của nó.
Từ định nghĩa của liên kết hậu tố và từ Bổ đề 2, ta có

$$endpos(v) \subseteq endpos(link(v)),$$

điều này cùng với bổ đề trước chứng minh khẳng định:
cây của liên kết hậu tố về cơ bản là cây của tập hợp $endpos$.

Đây là **ví dụ** về cây của liên kết hậu tố trong tự động hóa hậu tố được xây dựng cho chuỗi $\text{"abcbc"}$.
Các nút được gắn nhãn với chuỗi con dài nhất từ ​​lớp tương đương tương ứng.

![Tự động hóa hậu tố cho "abcbc" với liên kết hậu tố](SA_suffix_links.png)

### Tóm tắt

Trước khi tiến hành đến bản thân thuật toán, chúng ta hãy tóm tắt kiến ​​thức tích lũy và giới thiệu một vài ký hiệu phụ trợ.

- Các chuỗi con của chuỗi $s$ có thể được phân tách thành các lớp tương đương theo vị trí kết thúc $endpos$ của chúng.
- Tự động hóa hậu tố bao gồm trạng thái ban đầu $t_0$, cũng như một trạng thái cho mỗi lớp tương đương $endpos$.
- Đối với mỗi trạng thái $v$, một hoặc nhiều chuỗi con khớp.
  Chúng ta biểu thị bằng $longest(v)$ chuỗi dài nhất như vậy và thông qua $len(v)$ là độ dài của nó.
  Chúng ta biểu thị bằng $shortest(v)$ chuỗi con ngắn nhất như vậy và độ dài của nó là $minlen(v)$.
  Sau đó, tất cả các chuỗi tương ứng với trạng thái này là các hậu tố khác nhau của chuỗi $longest(v)$ và có tất cả các độ dài có thể có trong khoảng $[minlen(v); len(v)]$.
- Đối với mỗi trạng thái $v \ne t_0$, một liên kết hậu tố được định nghĩa là một liên kết, dẫn đến một trạng thái tương ứng với hậu tố của chuỗi $longest(v)$ có độ dài $minlen(v) - 1$.
  Các liên kết hậu tố tạo thành một cây có gốc là $t_0$ và đồng thời cây này tạo thành mối quan hệ bao hàm giữa các tập hợp $endpos$.
- Chúng ta có thể biểu thị $minlen(v)$ cho $v \ne t_0$ bằng cách sử dụng liên kết hậu tố $link(v)$ như sau:
  
$$minlen(v) = len(link(v)) + 1$$

- Nếu chúng ta bắt đầu từ một trạng thái tùy ý $v_0$ và theo các liên kết hậu tố, thì sớm muộn gì chúng ta cũng sẽ đến trạng thái ban đầu $t_0$.
  Trong trường hợp này, chúng ta thu được một chuỗi các khoảng rời rạc $[minlen(v_i); len(v_i)]$, chúng hợp nhất tạo thành khoảng liên tục $[0; len(v_0)]$.

### Thuật toán

Bây giờ chúng ta có thể tiến hành đến bản thân thuật toán.
Thuật toán sẽ là **trực tuyến**, tức là chúng ta sẽ thêm các ký tự của chuỗi từng cái một và sửa đổi tự động cho phù hợp trong mỗi bước.

Để đạt được mức tiêu thụ bộ nhớ tuyến tính, chúng ta sẽ chỉ lưu trữ các giá trị $len$, $link$ và danh sách các chuyển đổi trong mỗi trạng thái.
Chúng ta sẽ không gắn nhãn các trạng thái kết thúc (nhưng sau đó chúng ta sẽ chỉ ra cách sắp xếp các nhãn này sau khi xây dựng tự động hóa hậu tố).

Ban đầu, tự động bao gồm một trạng thái duy nhất $t_0$, sẽ là chỉ số $0$ (các trạng thái còn lại sẽ nhận các chỉ số $1, 2, \dots$).
Chúng ta gán cho nó $len = 0$ và $link = -1$ để thuận tiện ($-1$ sẽ là một trạng thái hư cấu, không tồn tại).

Bây giờ, toàn bộ nhiệm vụ được rút gọn thành việc triển khai quá trình **thêm một ký tự** $c$ vào cuối chuỗi hiện tại.
Chúng ta hãy mô tả quá trình này:

  - Cho $last$ là trạng thái tương ứng với toàn bộ chuỗi trước khi thêm ký tự $c$.
    (Ban đầu chúng ta đặt $last = 0$ và chúng ta sẽ thay đổi $last$ trong bước cuối cùng của thuật toán cho phù hợp.)
  - Tạo một trạng thái mới $cur$ và gán cho nó $len(cur) = len(last) + 1$.
    Giá trị $link(cur)$ chưa được biết vào thời điểm đó.
  - Bây giờ chúng ta thực hiện quy trình sau:
    Chúng ta bắt đầu ở trạng thái $last$.
    Trong khi không có chuyển đổi nào qua chữ cái $c$, chúng ta sẽ thêm một chuyển đổi đến trạng thái $cur$ và theo liên kết hậu tố.
    Nếu tại một số điểm đã tồn tại một chuyển đổi qua chữ cái $c$, thì chúng ta sẽ dừng lại và biểu thị trạng thái này bằng $p$.
  - Nếu nó chưa tìm thấy trạng thái $p$ như vậy, thì chúng ta đã đạt đến trạng thái hư cấu $-1$, thì chúng ta có thể chỉ cần gán $link(cur) = 0$ và rời đi.
  - Bây giờ giả sử rằng chúng ta đã tìm thấy một trạng thái $p$, từ đó tồn tại một chuyển đổi qua chữ cái $c$.
    Chúng ta sẽ biểu thị trạng thái mà chuyển đổi dẫn đến bằng $q$.
  - Bây giờ chúng ta có hai trường hợp. Hoặc $len(p) + 1 = len(q)$, hoặc không.
  - Nếu $len(p) + 1 = len(q)$, thì chúng ta có thể chỉ cần gán $link(cur) = q$ và rời đi.
  - Nếu không thì nó phức tạp hơn một chút.
    Cần phải **nhân bản** trạng thái $q$:
    chúng ta tạo một trạng thái mới $clone$, sao chép tất cả dữ liệu từ $q$ (liên kết hậu tố và chuyển đổi) ngoại trừ giá trị $len$.
    Chúng ta sẽ gán $len(clone) = len(p) + 1$.

    Sau khi nhân bản, chúng ta hướng liên kết hậu tố từ $cur$ đến $clone$, và cũng từ $q$ đến $clone$.

    Cuối cùng, chúng ta cần đi từ trạng thái $p$ trở lại bằng cách sử dụng liên kết hậu tố miễn là có chuyển đổi qua $c$ đến trạng thái $q$ và chuyển hướng tất cả những liên kết đó đến trạng thái $clone$.

  - Trong bất kỳ trường hợp nào trong ba trường hợp, sau khi hoàn thành quy trình, chúng ta cập nhật giá trị $last$ bằng trạng thái $cur$.

Nếu chúng ta cũng muốn biết trạng thái nào là **kết thúc** và trạng thái nào không, thì chúng ta có thể tìm thấy tất cả các trạng thái kết thúc sau khi xây dựng tự động hóa hậu tố hoàn chỉnh cho toàn bộ chuỗi $s$.
Để thực hiện việc này, chúng ta lấy trạng thái tương ứng với toàn bộ chuỗi (được lưu trữ trong biến $last$) và theo các liên kết hậu tố của nó cho đến khi chúng ta đến trạng thái ban đầu.
Chúng ta sẽ đánh dấu tất cả các trạng thái đã truy cập là kết thúc.
Dễ hiểu rằng bằng cách làm như vậy, chúng ta sẽ đánh dấu chính xác các trạng thái tương ứng với tất cả các hậu tố của chuỗi $s$, chính là các trạng thái kết thúc.

Trong phần tiếp theo, chúng ta sẽ xem xét chi tiết từng bước và chỉ ra **tính đúng đắn** của nó.

Ở đây, chúng ta chỉ lưu ý rằng, vì chúng ta chỉ tạo một hoặc hai trạng thái mới cho mỗi ký tự của $s$, nên tự động hóa hậu tố chứa **số lượng trạng thái tuyến tính**.

Tính tuyến tính của số lượng chuyển đổi, và nói chung là tính tuyến tính của thời gian chạy của thuật toán là ít rõ ràng hơn và chúng sẽ được chứng minh sau khi chúng ta chứng minh tính đúng đắn.

### Tính đúng đắn

  - Chúng ta sẽ gọi một chuyển đổi $(p, q)$ là **liên tục** nếu $len(p) + 1 = len(q)$.
    Ngược lại, tức là khi $len(p) + 1 < len(q)$, chuyển đổi sẽ được gọi là **không liên tục**.

    Như chúng ta có thể thấy từ mô tả của thuật toán, các chuyển đổi liên tục và không liên tục sẽ dẫn đến các trường hợp khác nhau của thuật toán.
    Các chuyển đổi liên tục được cố định và sẽ không bao giờ thay đổi nữa.
    Ngược lại, chuyển đổi không liên tục có thể thay đổi khi các chữ cái mới được thêm vào chuỗi (điểm cuối của cạnh chuyển đổi có thể thay đổi).

  - Để tránh nhầm lẫn, chúng ta sẽ biểu thị chuỗi mà tự động hóa hậu tố được xây dựng trước khi thêm ký tự hiện tại $c$ bằng $s$.

  - Thuật toán bắt đầu bằng cách tạo một trạng thái mới $cur$, trạng thái này sẽ tương ứng với toàn bộ chuỗi $s + c$.
    Rõ ràng tại sao chúng ta phải tạo một trạng thái mới.
    Cùng với ký tự mới, một lớp tương đương mới được tạo.

  - Sau khi tạo một trạng thái mới, chúng ta duyệt qua các liên kết hậu tố bắt đầu từ trạng thái tương ứng với toàn bộ chuỗi $s$.
    Đối với mỗi trạng thái, chúng ta cố gắng thêm một chuyển đổi với ký tự $c$ vào trạng thái mới $cur$.
    Do đó, chúng ta nối thêm ký tự $c$ vào mỗi hậu tố của $s$.
    Tuy nhiên, chúng ta chỉ có thể thêm các chuyển đổi mới này, nếu chúng không xung đột với một chuyển đổi đã tồn tại.
    Do đó, ngay sau khi chúng ta tìm thấy một chuyển đổi đã tồn tại với $c$, chúng ta phải dừng lại.

  - Trong trường hợp đơn giản nhất, chúng ta đạt đến trạng thái hư cấu $-1$.
    Điều này có nghĩa là chúng ta đã thêm chuyển đổi với $c$ vào tất cả các hậu tố của $s$.
    Điều này cũng có nghĩa là ký tự $c$ chưa từng là một phần của chuỗi $s$ trước đây.
    Do đó, liên kết hậu tố của $cur$ phải dẫn đến trạng thái $0$.

  - Trong trường hợp thứ hai, chúng ta bắt gặp một chuyển đổi hiện có $(p, q)$.
    Điều này có nghĩa là chúng ta đã cố gắng thêm một chuỗi $x + c$ (trong đó $x$ là hậu tố của $s$) vào máy mà **đã tồn tại** trong máy (chuỗi $x + c$ đã xuất hiện dưới dạng chuỗi con của $s$).
    Vì chúng ta giả định rằng tự động cho chuỗi $s$ được xây dựng chính xác, chúng ta không nên thêm chuyển đổi mới ở đây.

    Tuy nhiên, có một khó khăn.
    Liên kết hậu tố từ trạng thái $cur$ nên dẫn đến trạng thái nào?
    Chúng ta phải tạo một liên kết hậu tố đến một trạng thái, trong đó chuỗi dài nhất chính xác là $x + c$, tức là $len$ của trạng thái này phải là $len(p) + 1$.
    Tuy nhiên, có thể là một trạng thái như vậy chưa tồn tại, tức là $len(q) > len(p) + 1$.
    Trong trường hợp này, chúng ta phải tạo một trạng thái như vậy, bằng cách **chia** trạng thái $q$.

  - Nếu chuyển đổi $(p, q)$ hóa ra là liên tục, thì $len(q) = len(p) + 1$.
    Trong trường hợp này, mọi thứ đều đơn giản.
    Chúng ta hướng liên kết hậu tố từ $cur$ đến trạng thái $q$.

  - Nếu không thì chuyển đổi là không liên tục, tức là $len(q) > len(p) + 1$.
    Điều này có nghĩa là trạng thái $q$ không chỉ tương ứng với hậu tố của $s + c$ có độ dài $len(p) + 1$, mà còn tương ứng với các chuỗi con dài hơn của $s$.
    Chúng ta không thể làm gì khác ngoài việc **chia** trạng thái $q$ thành hai trạng thái con, sao cho trạng thái con đầu tiên có độ dài $len(p) + 1$.

    Làm cách nào chúng ta có thể chia một trạng thái?
    Chúng ta **nhân bản** trạng thái $q$, điều này cho chúng ta trạng thái $clone$, và chúng ta đặt $len(clone) = len(p) + 1$.
    Chúng ta sao chép tất cả các chuyển đổi từ $q$ sang $clone$, bởi vì chúng ta không muốn thay đổi các đường dẫn đi qua $q$.
    Ngoài ra, chúng ta đặt liên kết hậu tố từ $clone$ đến mục tiêu của liên kết hậu tố của $q$ và đặt liên kết hậu tố của $q$ thành $clone$.

    Và sau khi chia trạng thái, chúng ta đặt liên kết hậu tố từ $cur$ đến $clone$.

    Trong bước cuối cùng, chúng ta thay đổi một số chuyển đổi thành $q$, chúng ta chuyển hướng chúng đến $clone$.
    Chúng ta phải thay đổi những chuyển đổi nào?
    Chỉ cần chuyển hướng các chuyển đổi tương ứng với tất cả các hậu tố của chuỗi $w + c$ (trong đó $w$ là chuỗi dài nhất của $p$), tức là chúng ta cần tiếp tục di chuyển dọc theo các liên kết hậu tố, bắt đầu từ đỉnh $p$ cho đến khi chúng ta đạt đến trạng thái hư cấu $-1$ hoặc chuyển đổi dẫn đến một trạng thái khác với $q$.

### Số lượng hoạt động tuyến tính

Đầu tiên, chúng ta ngay lập tức đưa ra giả định rằng kích thước của bảng chữ cái là **không đổi**.
Nếu không phải như vậy, thì sẽ không thể nói về độ phức tạp thời gian tuyến tính.
Danh sách các chuyển đổi từ một đỉnh sẽ được lưu trữ trong một cây cân bằng, cho phép bạn nhanh chóng thực hiện các thao tác tìm kiếm khóa và thêm khóa.
Do đó, nếu chúng ta biểu thị bằng $k$ kích thước của bảng chữ cái, thì hành vi tiệm cận của thuật toán sẽ là $O(n \log k)$ với bộ nhớ $O(n)$.
Tuy nhiên, nếu bảng chữ cái đủ nhỏ, thì bạn có thể hy sinh bộ nhớ bằng cách tránh các cây cân bằng và lưu trữ các chuyển đổi tại mỗi đỉnh dưới dạng một mảng có độ dài $k$ (để tìm kiếm nhanh bằng khóa) và một danh sách động (để nhanh chóng duyệt qua tất cả các khóa có sẵn).
Do đó, chúng ta đạt được độ phức tạp thời gian $O(n)$ cho thuật toán, nhưng với chi phí độ phức tạp bộ nhớ $O(n k)$.

Vì vậy, chúng ta sẽ coi kích thước của bảng chữ cái là hằng số, tức là mỗi thao tác tìm kiếm chuyển đổi trên một ký tự, thêm chuyển đổi, tìm kiếm chuyển đổi tiếp theo - tất cả các thao tác này đều có thể được thực hiện trong $O(1)$.

Nếu chúng ta xem xét tất cả các phần của thuật toán, thì nó chứa ba vị trí trong thuật toán mà độ phức tạp tuyến tính không rõ ràng:

  - Vị trí đầu tiên là lần duyệt qua các liên kết hậu tố từ trạng thái $last$, thêm các chuyển đổi với ký tự $c$.
  - Vị trí thứ hai là việc sao chép các chuyển đổi khi trạng thái $q$ được nhân bản thành trạng thái mới $clone$.
  - Vị trí thứ ba là thay đổi chuyển đổi dẫn đến $q$, chuyển hướng chúng đến $clone$.

Chúng ta sử dụng thực tế là kích thước của tự động hóa hậu tố (cả về số lượng trạng thái và số lượng chuyển đổi) là **tuyến tính**.
(Bằng chứng về tính tuyến tính của số lượng trạng thái là bản thân thuật toán, và bằng chứng về tính tuyến tính của số lượng trạng thái được đưa ra bên dưới, sau khi triển khai thuật toán).

Do đó, tổng độ phức tạp của **vị trí thứ nhất và thứ hai** là rõ ràng, sau tất cả, mỗi thao tác chỉ thêm một chuyển đổi mới được khấu hao vào tự động.

Điều còn lại là ước tính tổng độ phức tạp của **vị trí thứ ba**, trong đó chúng ta chuyển hướng các chuyển đổi, ban đầu trỏ đến $q$, đến $clone$.
Chúng ta biểu thị $v = longest(p)$.
Đây là hậu tố của chuỗi $s$, và với mỗi lần lặp, độ dài của nó giảm - và do đó vị trí $v$ là hậu tố của chuỗi $s$ tăng đơn điệu theo mỗi lần lặp.
Trong trường hợp này, nếu trước lần lặp đầu tiên của vòng lặp, chuỗi tương ứng $v$ ở độ sâu $k$ ($k \ge 2$) từ $last$ (bằng cách đếm độ sâu là số lượng liên kết hậu tố), thì sau lần lặp cuối cùng, chuỗi $v + c$ sẽ là liên kết hậu tố thứ $2$ trên đường dẫn từ $cur$ (sẽ trở thành giá trị $last$ mới).

Do đó, mỗi lần lặp của vòng lặp này dẫn đến thực tế là vị trí của chuỗi $longest(link(link(last))$ là hậu tố của chuỗi hiện tại sẽ tăng đơn điệu.
Do đó, chu kỳ này không thể được thực thi quá $n$ lần lặp, điều này là cần thiết để chứng minh.

### Triển khai

Đầu tiên, chúng ta mô tả một cấu trúc dữ liệu sẽ lưu trữ tất cả thông tin về một chuyển đổi cụ thể ($len$, $link$ và danh sách các chuyển đổi).
Nếu cần, bạn có thể thêm cờ kết thúc ở đây, cũng như các thông tin khác.
Chúng ta sẽ lưu trữ danh sách các chuyển đổi dưới dạng $map$, cho phép chúng ta đạt được tổng bộ nhớ $O(n)$ và thời gian $O(n \log k)$ để xử lý toàn bộ chuỗi.

```{.cpp file=suffix_automaton_struct}
struct state {
    int len, link;
    map<char, int> next;
};
```

Bản thân tự động hóa hậu tố sẽ được lưu trữ trong một mảng của các cấu trúc $state$ này.
Chúng ta lưu trữ kích thước hiện tại $sz$ và cả biến $last$, trạng thái tương ứng với toàn bộ chuỗi tại thời điểm đó.

```{.cpp file=suffix_automaton_def}
const int MAXLEN = 100000;
state st[MAXLEN * 2];
int sz, last;
```

Chúng ta đưa ra một hàm khởi tạo tự động hóa hậu tố (tạo tự động hóa hậu tố với một trạng thái duy nhất).

```{.cpp file=suffix_automaton_init}
void sa_init() {
    st[0].len = 0;
    st[0].link = -1;
    sz++;
    last = 0;
}
```

Và cuối cùng, chúng ta đưa ra cách triển khai của hàm chính - hàm thêm ký tự tiếp theo vào cuối dòng hiện tại, xây dựng lại máy cho phù hợp.

```{.cpp file=suffix_automaton_extend}
void sa_extend(char c) {
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    int p = last;
    while (p != -1 && !st[p].next.count(c)) {
        st[p].next[c] = cur;
        p = st[p].link;
    }
    if (p == -1) {
        st[cur].link = 0;
    } else {
        int q = st[p].next[c];
        if (st[p].len + 1 == st[q].len) {
            st[cur].link = q;
        } else {
            int clone = sz++;
            st[clone].len = st[p].len + 1;
            st[clone].next = st[q].next;
            st[clone].link = st[q].link;
            while (p != -1 && st[p].next[c] == q) {
                st[p].next[c] = clone;
                p = st[p].link;
            }
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}
```

Như đã đề cập ở trên, nếu bạn hy sinh bộ nhớ ($O(n k)$, trong đó $k$ là kích thước của bảng chữ cái), thì bạn có thể đạt được thời gian xây dựng máy trong $O(n)$, ngay cả đối với bất kỳ kích thước bảng chữ cái $k$ nào.
Nhưng đối với điều này, bạn sẽ phải lưu trữ một mảng có kích thước $k$ trong mỗi trạng thái (để nhảy nhanh đến chuyển đổi của chữ cái) và thêm một danh sách tất cả các chuyển đổi (để nhanh chóng lặp lại các chuyển đổi).

## Thuộc tính bổ sung

### Số lượng trạng thái

Số lượng trạng thái trong tự động hóa hậu tố của chuỗi $s$ có độ dài $n$ **không vượt quá** $2n - 1$ (đối với $n \ge 2$).

Bằng chứng là bản thân thuật toán xây dựng, vì ban đầu tự động bao gồm một trạng thái, và trong lần lặp thứ nhất và thứ hai, chỉ một trạng thái duy nhất sẽ được tạo, và trong $n-2$ bước còn lại, mỗi bước sẽ tạo ra tối đa $2$ trạng thái.

Tuy nhiên, chúng ta cũng có thể **chỉ ra** ước tính này **mà không cần biết thuật toán**.
Chúng ta hãy nhớ lại rằng số lượng trạng thái bằng với số lượng tập hợp $endpos$ khác nhau.
Ngoài ra, các tập hợp $endpos$ này tạo thành một cây (một đỉnh cha chứa tất cả các tập hợp con trong tập hợp của nó).
Hãy xem xét cây này và biến đổi nó một chút:
miễn là nó có một đỉnh bên trong chỉ có một con (có nghĩa là tập hợp của con thiếu ít nhất một vị trí từ tập hợp cha), chúng ta tạo một con mới với tập hợp các vị trí bị thiếu.
Cuối cùng, chúng ta có một cây trong đó mỗi đỉnh bên trong có bậc lớn hơn một và số lượng lá không vượt quá $n$.
Do đó, có không quá $2n - 1$ đỉnh trong một cây như vậy.

Giới hạn này của số lượng trạng thái thực sự có thể đạt được cho mỗi $n$.
Một chuỗi có thể là:

$$\text{"abbb}\dots \text{bbb"}$$

Trong mỗi lần lặp, bắt đầu từ lần lặp thứ ba, thuật toán sẽ chia một trạng thái, kết quả là chính xác $2n - 1$ trạng thái.

### Số lượng chuyển đổi

Số lượng chuyển đổi trong tự động hóa hậu tố của chuỗi $s$ có độ dài $n$ **không vượt quá** $3n - 4$ (đối với $n \ge 3$).

Chúng ta hãy chứng minh điều này:

Trước tiên, hãy ước tính số lượng chuyển đổi liên tục.
Xét một spanning tree của các đường dẫn dài nhất trong tự động bắt đầu từ trạng thái $t_0$.
Bộ khung này sẽ chỉ bao gồm các cạnh liên tục, và do đó, số lượng của chúng nhỏ hơn số lượng trạng thái, tức là nó không vượt quá $2n - 2$.

Bây giờ chúng ta hãy ước tính số lượng chuyển đổi không liên tục.
Cho chuyển đổi không liên tục hiện tại là $(p, q)$ với ký tự $c$.
Chúng ta lấy chuỗi tương ứng $u + c + w$, trong đó chuỗi $u$ tương ứng với đường dẫn dài nhất từ ​​trạng thái ban đầu đến $p$ và $w$ đến đường dẫn dài nhất từ ​​$q$ đến bất kỳ trạng thái kết thúc nào.
Một mặt, mỗi chuỗi $u + c + w$ như vậy cho mỗi chuỗi không đầy đủ sẽ khác nhau (vì chuỗi $u$ và $w$ chỉ được hình thành bởi các chuyển đổi hoàn chỉnh).
Mặt khác, mỗi chuỗi $u + c + w$ như vậy, theo định nghĩa của các trạng thái kết thúc, sẽ là hậu tố của toàn bộ chuỗi $s$.
Vì chỉ có $n$ hậu tố khác rỗng của $s$ và không có chuỗi $u + c + w$ nào có thể chứa $s$ (vì toàn bộ chuỗi chỉ chứa các chuyển đổi hoàn chỉnh), nên tổng số chuyển đổi không đầy đủ không vượt quá $n - 1$.

Kết hợp hai ước tính này, chúng ta nhận được giới hạn $3n - 3$.
Tuy nhiên, vì số lượng trạng thái tối đa chỉ có thể đạt được với trường hợp thử nghiệm $\text{"abbb\dots bbb"}$ và trường hợp này rõ ràng có ít hơn $3n - 3$ chuyển đổi, chúng ta nhận được giới hạn chặt chẽ hơn là $3n - 4$ cho số lượng chuyển đổi trong tự động hóa hậu tố.

Giới hạn này cũng có thể đạt được với chuỗi:

$$\text{"abbb}\dots \text{bbbc"}$$

## Ứng dụng

Ở đây, chúng ta xem xét một số nhiệm vụ có thể được giải quyết bằng cách sử dụng tự động hóa hậu tố.
Để đơn giản, chúng ta giả sử rằng kích thước bảng chữ cái $k$ là hằng số, điều này cho phép chúng ta coi độ phức tạp của việc nối thêm một ký tự và phép duyệt là hằng số.

### Kiểm tra sự xuất hiện

Cho một văn bản $T$ và nhiều mẫu $P$.
Chúng ta phải kiểm tra xem các chuỗi $P$ có xuất hiện dưới dạng chuỗi con của $T$ hay không.

Chúng ta xây dựng tự động hóa hậu tố của văn bản $T$ trong thời gian $O(length(T))$.
Để kiểm tra xem một mẫu $P$ có xuất hiện trong $T$ hay không, chúng ta theo các chuyển đổi, bắt đầu từ $t_0$, theo các ký tự của $P$.
Nếu tại một số điểm không tồn tại chuyển đổi, thì mẫu $P$ không xuất hiện dưới dạng chuỗi con của $T$.
Nếu chúng ta có thể xử lý toàn bộ chuỗi $P$ theo cách này, thì chuỗi sẽ xuất hiện trong $T$.

Rõ ràng là điều này sẽ mất thời gian $O(length(P))$ cho mỗi chuỗi $P$.
Hơn nữa, thuật toán thực sự tìm thấy độ dài của tiền tố dài nhất của $P$ xuất hiện trong văn bản.

### Số lượng chuỗi con khác nhau

Cho một chuỗi $S$.
Bạn muốn tính số lượng chuỗi con khác nhau.

Chúng ta hãy xây dựng tự động hóa hậu tố cho chuỗi $S$.

Mỗi chuỗi con của $S$ tương ứng với một số đường dẫn trong tự động.
Do đó, số lượng chuỗi con khác nhau bằng với số lượng đường dẫn khác nhau trong tự động bắt đầu từ $t_0$.

Cho rằng tự động hóa hậu tố là một đồ thị có hướng phi chu trình, số lượng cách khác nhau có thể được tính toán bằng quy hoạch động.

Cụ thể, cho $d[v]$ là số cách, bắt đầu từ trạng thái $v$ (bao gồm cả đường dẫn có độ dài bằng không).
Sau đó, chúng ta có đệ quy:

$$d[v] = 1 + \sum_{w : (v, w, c) \in DAWG} d[w]$$

Tức là $d[v]$ có thể được biểu thị là tổng các câu trả lời cho tất cả các đầu của các chuyển đổi của $v$.

Số lượng chuỗi con khác nhau là giá trị $d[t_0] - 1$ (vì chúng ta không tính chuỗi con rỗng).

Tổng độ phức tạp thời gian: $O(length(S))$


Ngoài ra, chúng ta có thể tận dụng thực tế là mỗi trạng thái $v$ khớp với các chuỗi con có độ dài $[minlen(v),len(v)]$.
Do đó, với $minlen(v) = 1 + len(link(v))$, chúng ta có tổng số chuỗi con phân biệt tại trạng thái $v$ là $len(v) - minlen(v) + 1 = len(v) - (1 + len(link(v))) + 1 = len(v) - len(link(v))$.

Điều này được thể hiện ngắn gọn bên dưới:

```cpp
long long get_diff_strings(){
    long long tot = 0;
    for(int i = 1; i < sz; i++) {
        tot += st[i].len - st[st[i].link].len;
    }
    return tot;
}
```

Mặc dù đây cũng là $O(length(S))$, nhưng nó không yêu cầu thêm dung lượng và không có cuộc gọi đệ quy, do đó chạy nhanh hơn trong thực tế.

### Tổng độ dài của tất cả các chuỗi con khác nhau

Cho một chuỗi $S$.
Chúng ta muốn tính tổng độ dài của tất cả các chuỗi con khác nhau của nó.

Giải pháp tương tự như giải pháp trước đó, chỉ là bây giờ cần phải xem xét hai đại lượng cho phần quy hoạch động:
số lượng chuỗi con khác nhau $d[v]$ và tổng độ dài $ans[v]$ của chúng.

Chúng ta đã mô tả cách tính toán $d[v]$ trong nhiệm vụ trước đó.
Giá trị $ans[v]$ có thể được tính toán bằng cách sử dụng đệ quy:

$$ans[v] = \sum_{w : (v, w, c) \in DAWG} d[w] + ans[w]$$

Chúng ta lấy câu trả lời của mỗi đỉnh liền kề $w$ và cộng thêm $d[w]$ vào đó (vì mọi chuỗi con đều dài hơn một ký tự khi bắt đầu từ trạng thái $v$).

Một lần nữa nhiệm vụ này có thể được tính toán trong thời gian $O(length(S))$.

Ngoài ra, chúng ta có thể, một lần nữa, tận dụng thực tế là mỗi trạng thái $v$ khớp với các chuỗi con có độ dài $[minlen(v),len(v)]$.
Vì $minlen(v) = 1 + len(link(v))$ và công thức cấp số cộng $S_n = n \cdot \frac{a_1+a_n}{2}$ (trong đó $S_n$ biểu thị tổng của $n$ số hạng, $a_1$ biểu thị số hạng đầu tiên và $a_n$ biểu thị số hạng cuối cùng), chúng ta có thể tính độ dài của các chuỗi con tại một trạng thái trong thời gian không đổi. Sau đó, chúng ta cộng tổng số này cho mỗi trạng thái $v \neq t_0$ trong tự động. Điều này được hiển thị bằng đoạn mã bên dưới:

```cpp
long long get_tot_len_diff_substings() {
    long long tot = 0;
    for(int i = 1; i < sz; i++) {
        long long shortest = st[st[i].link].len + 1;
        long long longest = st[i].len;
        
        long long num_strings = longest - shortest + 1;
        long long cur = num_strings * (longest + shortest) / 2;
        tot += cur;
    }
    return tot;
}
```

Cách tiếp cận này chạy trong thời gian $O(length(S))$, nhưng theo thực nghiệm, nó chạy nhanh hơn 20 lần so với phiên bản quy hoạch động có ghi nhớ trên các chuỗi được tạo ngẫu nhiên. Nó không yêu cầu thêm dung lượng và không có đệ quy.

### Chuỗi con thứ $k$ theo thứ tự từ điển {data-toc-label="Chuỗi con thứ k theo thứ tự từ điển"}

Cho một chuỗi $S$.
Chúng ta phải trả lời nhiều truy vấn.
Đối với mỗi số $K_i$ đã cho, chúng ta phải tìm chuỗi thứ $K_i$ trong danh sách theo thứ tự từ điển của tất cả các chuỗi con.

Giải pháp của bài toán này dựa trên ý tưởng của hai bài toán trước.
Chuỗi con thứ $k$ theo thứ tự từ điển tương ứng với đường dẫn thứ $k$ theo thứ tự từ điển trong tự động hóa hậu tố.
Do đó, sau khi đếm số lượng đường dẫn từ mỗi trạng thái, chúng ta có thể dễ dàng tìm kiếm đường dẫn thứ $k$ bắt đầu từ gốc của tự động.

Điều này mất thời gian $O(length(S))$ để tiền xử lý và sau đó là $O(length(ans) \cdot k)$ cho mỗi truy vấn (trong đó $ans$ là câu trả lời cho truy vấn và $k$ là kích thước của bảng chữ cái).

### Dịch chuyển vòng nhỏ nhất

Cho một chuỗi $S$.
Chúng ta muốn tìm dịch chuyển vòng nhỏ nhất theo thứ tự từ điển.

Chúng ta xây dựng tự động hóa hậu tố cho chuỗi $S + S$.
Sau đó, tự động sẽ chứa trong chính nó dưới dạng các đường dẫn tất cả các dịch chuyển vòng của chuỗi $S$.

Do đó, bài toán được rút gọn thành việc tìm đường dẫn nhỏ nhất theo thứ tự từ điển có độ dài $length(S)$, điều này có thể được thực hiện theo cách tầm thường: chúng ta bắt đầu ở trạng thái ban đầu và một cách tham lam đi qua các chuyển đổi với ký tự tối thiểu.

Tổng độ phức tạp thời gian là $O(length(S))$.

### Số lần xuất hiện

Đối với một văn bản $T$ nhất định.
Chúng ta phải trả lời nhiều truy vấn.
Đối với mỗi mẫu $P$ đã cho, chúng ta phải tìm ra chuỗi $P$ xuất hiện bao nhiêu lần trong chuỗi $T$ dưới dạng chuỗi con.

Chúng ta xây dựng tự động hóa hậu tố cho văn bản $T$.

Tiếp theo, chúng ta thực hiện tiền xử lý sau:
đối với mỗi trạng thái $v$ trong tự động, chúng ta tính toán số $cnt[v]$ bằng với kích thước của tập hợp $endpos(v)$.
Trên thực tế, tất cả các chuỗi tương ứng với cùng một trạng thái $v$ xuất hiện trong văn bản $T$ với số lần bằng nhau, bằng với số lượng vị trí trong tập hợp $endpos$.

Tuy nhiên, chúng ta không thể xây dựng rõ ràng các tập hợp $endpos$, do đó, chúng ta chỉ xem xét kích thước $cnt$ của chúng.

Để tính toán chúng, chúng ta tiến hành như sau.
Đối với mỗi trạng thái, nếu nó không được tạo bằng cách nhân bản (và nếu nó không phải là trạng thái ban đầu $t_0$), chúng ta khởi tạo nó bằng $cnt = 1$.
Sau đó, chúng ta sẽ đi qua tất cả các trạng thái theo thứ tự giảm dần về độ dài $len$ của chúng và thêm giá trị $cnt[v]$ hiện tại vào các liên kết hậu tố:

$$cnt[link(v)] \text{ += } cnt[v]$$

Điều này cho giá trị chính xác cho mỗi trạng thái.

Tại sao điều này lại đúng?
Tổng số trạng thái thu được _không_ thông qua nhân bản chính xác là $length(T)$ và $i$ trạng thái đầu tiên trong số chúng xuất hiện khi chúng ta thêm $i$ ký tự đầu tiên.
Do đó, đối với mỗi trạng thái này, chúng ta đếm vị trí tương ứng mà nó đã được xử lý.
Do đó, ban đầu chúng ta có $cnt = 1$ cho mỗi trạng thái như vậy và $cnt = 0$ cho tất cả các trạng thái khác.

Sau đó, chúng ta áp dụng thao tác sau cho mỗi $v$: $cnt[link(v)] \text{ += } cnt[v]$.
Ý nghĩa đằng sau điều này là, nếu một chuỗi $v$ xuất hiện $cnt[v]$ lần, thì tất cả các hậu tố của nó cũng xuất hiện ở chính các vị trí kết thúc đó, do đó cũng là $cnt[v]$ lần.

Tại sao chúng ta không đếm quá nhiều trong quy trình này (tức là không đếm một số vị trí hai lần)?
Bởi vì chúng ta chỉ thêm các vị trí của một trạng thái vào một trạng thái khác, nên không thể xảy ra trường hợp một trạng thái chuyển hướng các vị trí của nó đến một trạng thái khác hai lần theo hai cách khác nhau.

Do đó, chúng ta có thể tính toán các đại lượng $cnt$ cho tất cả các trạng thái trong tự động trong thời gian $O(length(T))$.

Sau đó, trả lời một truy vấn bằng cách chỉ cần tra cứu giá trị $cnt[t]$, trong đó $t$ là trạng thái tương ứng với mẫu, nếu trạng thái như vậy tồn tại.
Ngược lại, trả lời bằng $0$.
Việc trả lời một truy vấn mất thời gian $O(length(P))$.

### Vị trí xuất hiện đầu tiên

Cho một văn bản $T$ và nhiều truy vấn.
Đối với mỗi chuỗi truy vấn $P$, chúng ta muốn tìm vị trí xuất hiện đầu tiên của $P$ trong chuỗi $T$ (vị trí bắt đầu của $P$).

Chúng ta lại xây dựng tự động hóa hậu tố.
Ngoài ra, chúng ta tính toán trước vị trí $firstpos$ cho tất cả các trạng thái trong tự động, tức là đối với mỗi trạng thái $v$, chúng ta muốn tìm vị trí $firstpos[v]$ của điểm cuối của lần xuất hiện đầu tiên.
Nói cách khác, chúng ta muốn tìm trước phần tử tối thiểu của mỗi tập hợp $endpos$ (vì rõ ràng không thể duy trì rõ ràng tất cả các tập hợp $endpos$).

Để duy trì các vị trí $firstpos$ này, chúng ta mở rộng hàm `sa_extend()`.
Khi chúng ta tạo một trạng thái mới $cur$, chúng ta đặt:

$$firstpos(cur) = len(cur) - 1$$

Và khi chúng ta nhân bản một đỉnh $q$ thành $clone$, chúng ta đặt:

$$firstpos(clone) = firstpos(q)$$

(vì tùy chọn duy nhất khác cho một giá trị sẽ là $firstpos(cur)$ chắc chắn là quá lớn)

Do đó, câu trả lời cho một truy vấn chỉ đơn giản là $firstpos(t) - length(P) + 1$, trong đó $t$ là trạng thái tương ứng với chuỗi $P$.
Việc trả lời một truy vấn một lần nữa chỉ mất thời gian $O(length(P))$.

### Tất cả các vị trí xuất hiện

Lần này chúng ta phải hiển thị tất cả các vị trí của các lần xuất hiện trong chuỗi $T$.

Một lần nữa, chúng ta xây dựng tự động hóa hậu tố cho văn bản $T$.
Tương tự như trong nhiệm vụ trước, chúng ta tính toán vị trí $firstpos$ cho tất cả các trạng thái.

Rõ ràng $firstpos(t)$ là một phần của câu trả lời, nếu $t$ là trạng thái tương ứng với chuỗi truy vấn $P$.
Vì vậy, chúng ta đã tính đến trạng thái của tự động chứa $P$.
Chúng ta cần tính đến những trạng thái nào khác?
Tất cả các trạng thái tương ứng với các chuỗi mà $P$ là hậu tố.
Nói cách khác, chúng ta cần tìm tất cả các trạng thái có thể đạt đến trạng thái $t$ thông qua liên kết hậu tố.

Do đó, để giải quyết bài toán, chúng ta cần lưu cho mỗi trạng thái một danh sách các tham chiếu hậu tố dẫn đến nó.
Câu trả lời cho truy vấn sau đó sẽ chứa tất cả $firstpos$ cho mỗi trạng thái mà chúng ta có thể tìm thấy trên DFS / BFS bắt đầu từ trạng thái $t$ chỉ sử dụng các tham chiếu hậu tố.

Nhìn chung, điều này yêu cầu $O(length (T))$ để tiền xử lý và $O(length(P) + answer(P))$ cho mỗi yêu cầu, trong đó $answer(P)$ — đây là kích thước của câu trả lời.

Đầu tiên, chúng ta đi xuống tự động cho mỗi ký tự trong mẫu để tìm nút bắt đầu của chúng ta yêu cầu $O(length(P))$. Sau đó, chúng ta sử dụng cách giải quyết của mình, cách này sẽ hoạt động trong thời gian $O(answer(P))$, bởi vì chúng ta sẽ không truy cập một trạng thái hai lần (bởi vì chỉ có một liên kết hậu tố rời khỏi mỗi trạng thái, vì vậy không thể có hai đường dẫn khác nhau dẫn đến cùng một trạng thái).

Chúng ta chỉ phải lưu ý rằng hai trạng thái khác nhau có thể có cùng giá trị $firstpos$.
Điều này xảy ra nếu một trạng thái được lấy bằng cách nhân bản trạng thái khác.
Tuy nhiên, điều này không làm hỏng độ phức tạp, vì mỗi trạng thái chỉ có thể có nhiều nhất một bản sao.

Hơn nữa, chúng ta cũng có thể loại bỏ các vị trí trùng lặp, nếu chúng ta không xuất ra các vị trí từ các trạng thái được nhân bản.
Trên thực tế, một trạng thái mà trạng thái được nhân bản có thể đạt tới cũng có thể đạt được từ trạng thái ban đầu.
Do đó, nếu chúng ta nhớ cờ `is_cloned` cho mỗi trạng thái, chúng ta có thể chỉ cần bỏ qua các trạng thái được nhân bản và chỉ xuất $firstpos$ cho tất cả các trạng thái khác.

Dưới đây là một số phác thảo triển khai:

```cpp
struct state {
    ...
    bool is_clone;
    int first_pos;
    vector<int> inv_link;
};

// sau khi xây dựng tự động
for (int v = 1; v < sz; v++) {
    st[st[v].link].inv_link.push_back(v);
}

// xuất ra tất cả các vị trí xuất hiện
void output_all_occurrences(int v, int P_length) {
    if (!st[v].is_clone)
        cout << st[v].first_pos - P_length + 1 << endl;
    for (int u : st[v].inv_link)
        output_all_occurrences(u, P_length);
}
```

### Chuỗi không xuất hiện ngắn nhất

Cho một chuỗi $S$ và một bảng chữ cái nhất định.
Chúng ta phải tìm một chuỗi có độ dài nhỏ nhất, không xuất hiện trong $S$.

Chúng ta sẽ áp dụng quy hoạch động trên tự động hóa hậu tố được xây dựng cho chuỗi $S$.

Cho $d[v]$ là câu trả lời cho nút $v$, tức là chúng ta đã xử lý một phần của chuỗi con, hiện đang ở trạng thái $v$ và muốn tìm số lượng ký tự nhỏ nhất phải được thêm vào để tìm một chuyển đổi không tồn tại.
Việc tính toán $d[v]$ rất đơn giản.
Nếu không có chuyển đổi nào sử dụng ít nhất một ký tự của bảng chữ cái, thì $d[v] = 1$.
Ngược lại, một ký tự là không đủ, và do đó, chúng ta cần lấy giá trị nhỏ nhất của tất cả các câu trả lời của tất cả các chuyển đổi:

$$d[v] = 1 + \min_{w:(v,w,c) \in SA} d[w].$$

Câu trả lời cho bài toán sẽ là $d[t_0]$ và chuỗi thực tế có thể được khôi phục bằng cách sử dụng mảng $d[]$ đã tính toán.

### Chuỗi con chung dài nhất của hai chuỗi

Cho hai chuỗi $S$ và $T$.
Chúng ta phải tìm chuỗi con chung dài nhất, tức là một chuỗi $X$ như vậy xuất hiện dưới dạng chuỗi con trong $S$ và cả trong $T$.

Chúng ta xây dựng tự động hóa hậu tố cho chuỗi $S$.

Bây giờ, chúng ta sẽ lấy chuỗi $T$ và đối với mỗi tiền tố, hãy tìm hậu tố dài nhất của tiền tố này trong $S$.
Nói cách khác, đối với mỗi vị trí trong chuỗi $T$, chúng ta muốn tìm chuỗi con chung dài nhất của $S$ và $T$ kết thúc ở vị trí đó.

Đối với điều này, chúng ta sẽ sử dụng hai biến, **trạng thái hiện tại** $v$ và **độ dài hiện tại** $l$.
Hai biến này sẽ mô tả phần khớp hiện tại: độ dài của nó và trạng thái tương ứng với nó.

Ban đầu $v = t_0$ và $l = 0$, tức là khớp trống.

Bây giờ chúng ta hãy mô tả cách chúng ta có thể thêm một ký tự $T[i]$ và tính toán lại câu trả lời cho nó.

  - Nếu có một chuyển đổi từ $v$ với ký tự $T[i]$, thì chúng ta chỉ cần theo chuyển đổi và tăng $l$ thêm một.
  - Nếu không có chuyển đổi như vậy, chúng ta phải rút ngắn phần khớp hiện tại, có nghĩa là chúng ta cần theo liên kết hậu tố: $v = link(v)$.
    Đồng thời, độ dài hiện tại phải được rút ngắn.
    Rõ ràng, chúng ta cần gán $l = len(v)$, vì sau khi đi qua liên kết hậu tố, chúng ta kết thúc ở trạng thái mà chuỗi dài nhất tương ứng là một chuỗi con.
  - Nếu vẫn không có chuyển đổi nào sử dụng ký tự bắt buộc, chúng ta lặp lại và một lần nữa đi qua liên kết hậu tố và giảm $l$, cho đến khi chúng ta tìm thấy chuyển đổi hoặc chúng ta đến trạng thái hư cấu $-1$ (có nghĩa là ký hiệu $T[i]$ hoàn toàn không xuất hiện trong $S$, vì vậy chúng ta gán $v = l = 0$).

Câu trả lời cho nhiệm vụ sẽ là giá trị lớn nhất của tất cả các giá trị $l$.

Độ phức tạp của phần này là $O(length(T))$, vì trong một lần di chuyển, chúng ta có thể tăng $l$ thêm một, hoặc thực hiện một số lần đi qua các liên kết hậu tố, mỗi lần kết thúc bằng cách giảm giá trị $l$.

Triển khai:

```cpp
string lcs (string S, string T) {
    sa_init();
    for (int i = 0; i < S.size(); i++)
        sa_extend(S[i]);
 
    int v = 0, l = 0, best = 0, bestpos = 0;
    for (int i = 0; i < T.size(); i++) {
        while (v && !st[v].next.count(T[i])) {
            v = st[v].link ;
            l = st[v].len;
        }
        if (st[v].next.count(T[i])) {
            v = st [v].next[T[i]];
            l++;
        }
        if (l > best) {
            best = l;
            bestpos = i;
        }
    }
    return T.substr(bestpos - best + 1, best);
} 
```

### Chuỗi con chung lớn nhất của nhiều chuỗi

Có $k$ chuỗi $S_i$ đã cho.
Chúng ta phải tìm chuỗi con chung dài nhất, tức là một chuỗi $X$ như vậy xuất hiện dưới dạng chuỗi con trong mỗi chuỗi $S_i$.

Chúng ta nối tất cả các chuỗi thành một chuỗi lớn $T$, phân tách các chuỗi bằng các ký tự đặc biệt $D_i$ (một cho mỗi chuỗi):

$$T = S_1 + D_1 + S_2 + D_2 + \dots + S_k + D_k.$$

Sau đó, chúng ta xây dựng tự động hóa hậu tố cho chuỗi $T$.

Bây giờ chúng ta cần tìm một chuỗi trong máy, chuỗi này được chứa trong tất cả các chuỗi $S_i$ và điều này có thể được thực hiện bằng cách sử dụng các ký tự đặc biệt được thêm vào.
Lưu ý rằng nếu một chuỗi con được bao gồm trong một số chuỗi $S_j$, thì trong tự động hóa hậu tố tồn tại một đường dẫn bắt đầu từ chuỗi con này chứa ký tự $D_j$ và không chứa các ký tự khác $D_1, \dots, D_{j-1}, D_{j+1}, \dots, D_k$.

Do đó, chúng ta cần tính toán khả năng đạt được, điều này cho chúng ta biết cho mỗi trạng thái của máy và mỗi ký hiệu $D_i$ nếu có tồn tại một đường dẫn như vậy.
Điều này có thể dễ dàng được tính toán bằng DFS hoặc BFS và quy hoạch động.
Sau đó, câu trả lời cho bài toán sẽ là chuỗi $longest(v)$ cho trạng thái $v$, từ đó các đường dẫn tồn tại cho tất cả các ký tự đặc biệt.

## Bài tập thực hành

- [CSES - Finding Patterns](https://cses.fi/problemset/task/2102)
- [CSES - Counting Patterns](https://cses.fi/problemset/task/2103)
- [CSES - String Matching](https://cses.fi/problemset/task/1753)
- [CSES - Patterns Positions](https://cses.fi/problemset/task/2104)
- [CSES - Distinct Substrings](https://cses.fi/problemset/task/2105)
- [CSES - Word Combinations](https://cses.fi/problemset/task/1731)
- [CSES - String Distribution](https://cses.fi/problemset/task/2110)
- [AtCoder - K-th Substring](https://atcoder.jp/contests/abc097/tasks/arc097_a)
- [SPOJ - SUBLEX](https://www.spoj.com/problems/SUBLEX/)
- [Codeforces - Cyclical Quest](https://codeforces.com/problemset/problem/235/C)
- [Codeforces - String](https://codeforces.com/contest/128/problem/B)

--- 
