# Định lý Sprague-Grundy. Nim

## Giới thiệu

Định lý này mô tả cái gọi là trò chơi hai người chơi **công bằng** (impartial),
tức là những trò chơi mà các nước đi có sẵn và thắng/thua chỉ phụ thuộc vào trạng thái của trò chơi.
Nói cách khác, điểm khác biệt duy nhất giữa hai người chơi là một trong số họ đi trước.

Ngoài ra, chúng tôi giả định rằng trò chơi có **thông tin hoàn hảo** (perfect information), tức là không có thông tin nào bị ẩn khỏi người chơi (họ biết các quy tắc và các nước đi có thể có).

Giả sử rằng trò chơi là **hữu hạn** (finite), tức là sau một số lần di chuyển nhất định, một trong hai người chơi sẽ rơi vào thế thua — từ đó họ không thể di chuyển sang vị trí khác.
Mặt khác, người chơi thiết lập vị trí này cho đối thủ sẽ thắng.
Hiểu một cách dễ dàng, không có trận hòa trong trò chơi này.

Những trò chơi như vậy có thể được mô tả hoàn toàn bằng một *đồ thị có hướng phi chu trình (directed acyclic graph)*: các đỉnh là trạng thái trò chơi và các cạnh là các phép chuyển đổi (nước đi).
Một đỉnh không có cạnh đi ra là một đỉnh thua (một người chơi phải di chuyển từ đỉnh này sẽ thua).

Vì không có trận hòa, chúng ta có thể phân loại tất cả các trạng thái trò chơi là **thắng** (winning) hoặc **thua** (losing).
Trạng thái thắng là những trạng thái mà từ đó có một nước đi dẫn đến thất bại chắc chắn của người chơi kia, ngay cả khi họ phản ứng tốt nhất.
Trạng thái thua là những trạng thái mà từ đó tất cả các nước đi đều dẫn đến trạng thái thắng cho người chơi kia.
Tóm tắt, một trạng thái là thắng nếu có ít nhất một phép chuyển đổi sang trạng thái thua và thua nếu không có ít nhất một phép chuyển đổi sang trạng thái thua.

Nhiệm vụ của chúng ta là phân loại các trạng thái của một trò chơi nhất định.

Lý thuyết về những trò chơi như vậy được phát triển độc lập bởi Roland Sprague vào năm 1935 và Patrick Michael Grundy vào năm 1939.

## Nim

Trò chơi này tuân theo các hạn chế được mô tả ở trên.
Hơn nữa, *bất kỳ* trò chơi hai người chơi công bằng có thông tin hoàn hảo nào cũng có thể được rút gọn thành trò chơi Nim.
Nghiên cứu trò chơi này sẽ cho phép chúng ta giải quyết tất cả các trò chơi tương tự khác, nhưng điều đó sẽ được nói sau.

Trong lịch sử, trò chơi này đã phổ biến từ thời cổ đại.
Nguồn gốc của nó có lẽ là ở Trung Quốc — hoặc ít nhất là trò chơi *Jianshizi* rất giống với nó.
Ở châu Âu, những tài liệu tham khảo sớm nhất về nó là từ thế kỷ 16.
Cái tên này được đặt bởi Charles Bouton, người vào năm 1901 đã xuất bản một bài phân tích đầy đủ về trò chơi này.

### Mô tả trò chơi

Có một số đống, mỗi đống có một số viên đá.
Trong một nước đi, người chơi có thể lấy bất kỳ số viên đá dương nào từ bất kỳ đống nào và ném chúng đi.
Một người chơi thua nếu họ không thể thực hiện một nước đi nào, điều này xảy ra khi tất cả các đống đều trống.

Trạng thái trò chơi được mô tả rõ ràng bởi một tập hợp đa thức (multiset) của các số nguyên dương.
Một nước đi bao gồm việc giảm nghiêm ngặt một số nguyên được chọn (nếu nó bằng không, nó sẽ bị xóa khỏi tập hợp).

### Giải pháp

Giải pháp của Charles L. Bouton như sau:

**Định lý.**
Người chơi hiện tại có chiến lược chiến thắng nếu và chỉ khi tổng xor của kích thước đống là khác không.
Tổng xor của một chuỗi $a$ là $a_1 \oplus a_2 \oplus \ldots \oplus  a_n$, trong đó $\oplus$ là *phép toán XOR từng bit (bitwise exclusive or)*.

**Chứng minh.**
Chìa khóa của bằng chứng là sự hiện diện của **chiến lược đối xứng cho đối thủ** (symmetric strategy for the opponent).
Chúng ta chỉ ra rằng một khi ở vị trí có tổng xor bằng 0, người chơi sẽ không thể làm cho nó khác không về lâu dài —
nếu họ chuyển sang vị trí có tổng xor khác không, đối thủ sẽ luôn có một nước đi trả về tổng xor về 0.

Chúng ta sẽ chứng minh định lý bằng phương pháp quy nạp toán học.

Đối với Nim trống (trong đó tất cả các đống đều trống, tức là tập hợp đa thức trống), tổng xor bằng 0 và định lý là đúng.

Bây giờ giả sử chúng ta đang ở trạng thái không trống.
Sử dụng giả thiết quy nạp (và tính phi chu trình của trò chơi), chúng ta giả sử rằng định lý được chứng minh cho tất cả các trạng thái có thể đạt được từ trạng thái hiện tại.

Sau đó, bằng chứng được chia thành hai phần:
nếu đối với vị trí hiện tại, tổng xor $s = 0$, chúng ta phải chứng minh rằng trạng thái này là thua, tức là tất cả các trạng thái có thể đạt được đều có tổng xor $t \neq 0$.
Nếu $s \neq 0$, chúng ta phải chứng minh rằng có một nước đi dẫn đến trạng thái $t = 0$.

*   Cho $s = 0$ và hãy xem xét bất kỳ nước đi nào.
    Nước đi này làm giảm kích thước của đống $x$ xuống kích thước $y$.
    Sử dụng các thuộc tính cơ bản của $\oplus$, chúng ta có
    
    \[ t = s \oplus x \oplus y = 0 \oplus x \oplus y = x \oplus y \]
    
    Vì $y < x$, $y \oplus x$ không thể bằng 0, nên $t \neq 0$.
    Điều đó có nghĩa là bất kỳ trạng thái nào có thể đạt được đều là trạng thái thắng (theo giả thiết quy nạp), vì vậy chúng ta đang ở thế thua.

*   Cho $s \neq 0$.
    Xét biểu diễn nhị phân của số $s$.
    Cho $d$ là chỉ số của bit khác không hàng đầu (giá trị lớn nhất) của nó.
    Nước đi của chúng ta sẽ nằm trên một đống có bit số $d$ của kích thước được đặt (nó phải tồn tại, nếu không thì bit sẽ không được đặt trong $s$).
    Chúng ta sẽ giảm kích thước $x$ của nó xuống $y = x \oplus s$.
    Tất cả các bit ở các vị trí lớn hơn $d$ trong $x$ và $y$ đều khớp và bit $d$ được đặt trong $x$ nhưng không được đặt trong $y$.
    Do đó, $y < x$, là tất cả những gì chúng ta cần để một nước đi hợp lệ.
    Bây giờ chúng ta có:
    
    \[ t = s \oplus x \oplus y = s \oplus x \oplus (s \oplus x) = 0 \]
    
    Điều này có nghĩa là chúng ta đã tìm thấy một trạng thái thua có thể đạt được (theo giả thiết quy nạp) và trạng thái hiện tại là thắng.

**Hệ quả.**
Bất kỳ trạng thái nào của Nim đều có thể được thay thế bằng một trạng thái tương đương miễn là tổng xor không thay đổi.
Hơn nữa, khi phân tích Nim với một số đống, chúng ta có thể thay thế nó bằng một đống duy nhất có kích thước $s$.

## Sự tương đương của trò chơi công bằng và Nim (Định lý Sprague-Grundy)

Bây giờ chúng ta sẽ tìm hiểu cách tìm, cho bất kỳ trạng thái trò chơi nào của bất kỳ trò chơi công bằng nào, một trạng thái tương ứng của Nim.

### Bổ đề về Nim với sự gia tăng

Chúng ta xem xét sửa đổi sau đối với Nim: chúng ta cũng cho phép **thêm đá vào một đống được chọn**.
Các quy tắc chính xác về cách thức và thời điểm cho phép tăng **không làm chúng ta quan tâm**, tuy nhiên các quy tắc nên giữ cho trò chơi của chúng ta **phi chu trình** (acyclic). Trong các phần sau, các trò chơi ví dụ được xem xét.

**Bổ đề.**
Việc bổ sung tăng vào Nim không thay đổi cách xác định trạng thái thắng và thua.
Nói cách khác, việc tăng là vô ích và chúng ta không phải sử dụng chúng trong chiến lược chiến thắng.

**Chứng minh.**
Giả sử một người chơi thêm đá vào một đống. Sau đó, đối thủ của anh ta có thể chỉ cần hoàn tác nước đi của mình — giảm số lượng trở lại giá trị trước đó.
Vì trò chơi là phi chu trình, sớm muộn gì người chơi hiện tại sẽ không thể sử dụng nước đi tăng và sẽ phải thực hiện nước đi Nim thông thường.

### Định lý Sprague-Grundy

Hãy xem xét một trạng thái $v$ của trò chơi công bằng hai người chơi và cho $v_i$ là các trạng thái có thể đạt được từ nó (trong đó $i \in \{ 1, 2, \dots, k \} , k \ge 0$).
Đối với trạng thái này, chúng ta có thể gán một trò chơi Nim hoàn toàn tương đương với một đống có kích thước $x$.
Số $x$ được gọi là giá trị Grundy hoặc giá trị nim của trạng thái $v$.

Hơn nữa, số này có thể được tìm thấy theo cách đệ quy sau:

$$ x = \text{mex}\ \{ x_1, \ldots, x_k \}, $$

trong đó $x_i$ là giá trị Grundy cho trạng thái $v_i$ và hàm $\text{mex}$ (*minimum excludant*) là số nguyên không âm nhỏ nhất không tìm thấy trong tập hợp đã cho.

Xem trò chơi như một đồ thị, chúng ta có thể dần dần tính toán các giá trị Grundy bắt đầu từ các đỉnh không có cạnh đi ra.
Giá trị Grundy bằng 0 có nghĩa là một trạng thái đang thua.

**Chứng minh.**
Chúng ta sẽ sử dụng bằng chứng bằng quy nạp.

Đối với các đỉnh không có nước đi, giá trị $x$ là $\text{mex}$ của một tập hợp rỗng, là 0.
Điều đó là chính xác, vì một Nim trống đang thua.

Bây giờ hãy xem xét bất kỳ đỉnh $v$ nào khác.
Theo quy nạp, chúng ta giả sử các giá trị $x_i$ tương ứng với các đỉnh có thể đạt được của nó đã được tính toán.

Cho $p = \text{mex}\ \{ x_1, \ldots, x_k \}$.
Sau đó, chúng ta biết rằng đối với bất kỳ số nguyên $i \in [0, p)$ nào, tồn tại một đỉnh có thể đạt được với giá trị Grundy $i$.
Điều này có nghĩa là $v$ **tương đương với một trạng thái của trò chơi Nim với sự gia tăng với một đống có kích thước $p$**.
Trong một trò chơi như vậy, chúng ta có các phép chuyển đổi sang các đống có mọi kích thước nhỏ hơn $p$ và có thể có các phép chuyển đổi sang các đống có kích thước lớn hơn $p$.
Do đó, $p$ thực sự là giá trị Grundy mong muốn cho trạng thái hiện đang được xem xét.

## Ứng dụng của định lý

Cuối cùng, chúng ta mô tả một thuật toán để xác định kết quả thắng/thua của một trò chơi, có thể áp dụng cho bất kỳ trò chơi công bằng hai người chơi nào.

Để tính toán giá trị Grundy của một trạng thái nhất định, bạn cần:

* Nhận tất cả các phép chuyển đổi có thể có từ trạng thái này

* Mỗi phép chuyển đổi có thể dẫn đến **tổng của các trò chơi độc lập** (một trò chơi trong trường hợp suy biến).
Tính toán giá trị Grundy cho mỗi trò chơi độc lập và XOR-sum chúng.
Tất nhiên, XOR không làm gì nếu chỉ có một trò chơi.

* Sau khi chúng ta đã tính toán các giá trị Grundy cho mỗi phép chuyển đổi, chúng ta tìm giá trị của trạng thái là $\text{mex}$ của những số này.

* Nếu giá trị bằng 0, thì trạng thái hiện tại đang thua, ngược lại thì nó đang thắng.

So với phần trước, chúng ta tính đến thực tế là có thể có các phép chuyển đổi sang các trò chơi kết hợp.
Chúng ta coi chúng là Nim với kích thước đống bằng với các giá trị Grundy của các trò chơi độc lập.
Chúng ta có thể XOR-sum chúng giống như Nim thông thường theo định lý của Bouton.

## Các mẫu trong giá trị Grundy

Rất thường xuyên khi giải quyết các nhiệm vụ cụ thể bằng cách sử dụng giá trị Grundy, có thể có lợi khi **nghiên cứu bảng giá trị** để tìm kiếm các mẫu.

Trong nhiều trò chơi, có vẻ khá khó để phân tích lý thuyết,
các giá trị Grundy hóa ra là tuần hoàn hoặc có dạng dễ hiểu.
Trong đại đa số các trường hợp, mẫu quan sát được hóa ra là đúng và có thể được chứng minh bằng quy nạp nếu muốn.

Tuy nhiên, giá trị Grundy không phải *luôn* chứa các tính đều đặn như vậy và ngay cả đối với một số trò chơi rất đơn giản, bài toán hỏi liệu những tính đều đặn đó có tồn tại hay không vẫn còn bỏ ngỏ (ví dụ: "trò chơi của Grundy").

## Trò chơi ví dụ

### Xếp chéo (Crosses-crosses)

**Luật chơi.**
Xét một dải ô vuông có kích thước $1 \times n$. Trong một nước đi, người chơi phải đặt một dấu chéo, nhưng cấm đặt hai dấu chéo cạnh nhau (trong các ô liền kề). Như thường lệ, người chơi không có nước đi hợp lệ sẽ thua.

**Giải pháp.**
Khi người chơi đặt dấu chéo vào bất kỳ ô nào, chúng ta có thể coi dải được chia thành hai phần độc lập:
bên trái dấu chéo và bên phải dấu chéo.
Trong trường hợp này, ô có dấu chéo, cũng như các ô bên trái và bên phải của nó bị phá hủy — không thể đặt thêm bất cứ thứ gì vào chúng.
Do đó, nếu chúng ta đánh số các ô từ $1$ đến $n$ thì việc đặt dấu chéo ở vị trí $1 < i < n$ sẽ chia dải thành
hai dải có độ dài $i-2$ và $n-i-1$, tức là chúng ta chuyển sang tổng của các trò chơi $i-2$ và $n-i-1$.
Đối với trường hợp biên của dấu chéo được đánh dấu ở vị trí $1$ hoặc $n$, chúng ta chuyển sang trò chơi $n-2$.

Do đó, giá trị Grundy $g(n)$ có dạng:

$$g(n) = \text{mex} \Bigl( \{ g(n-2) \} \cup \{g(i-2) \oplus g(n-i-1) \mid 2 \leq i \leq n-1\} \Bigr) .$$

Vì vậy, chúng ta có một giải pháp $O(n^2)$.

Trên thực tế, $g(n)$ có chu kỳ dài 34 bắt đầu từ $n=52$.


## Bài tập thực hành

- [KATTIS S-Nim](https://open.kattis.com/problems/snim)
- [CodeForces - Marbles (2018-2019 ACM-ICPC Brazil Subregional)](https://codeforces.com/gym/101908/problem/B)
- [KATTIS - Cuboid Slicing Game](https://open.kattis.com/problems/cuboidslicinggame)
- [HackerRank - Tower Breakers, Revisited!](https://www.hackerrank.com/contests/5-days-of-game-theory/challenges/tower-breakers-2)
- [HackerRank - Tower Breakers, Again!](https://www.hackerrank.com/contests/5-days-of-game-theory/challenges/tower-breakers-3/problem)
- [HackerRank - Chessboard Game, Again!](https://www.hackerrank.com/contests/5-days-of-game-theory/challenges/a-chessboard-game)


