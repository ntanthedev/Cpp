# Định lý Pick (Pick's Theorem)

---
tags:
  - Dịch
e_maxx_link: pick_grid_theorem
---

# Định lý Pick

Một đa giác không có tự giao nhau được gọi là đa giác nguyên (lattice polygon) nếu tất cả các đỉnh của nó có tọa độ nguyên trong một số lưới 2D. Định lý Pick cung cấp một cách để tính diện tích của đa giác này thông qua số lượng đỉnh nằm trên ranh giới và số lượng đỉnh nằm hoàn toàn bên trong đa giác.

## Công thức

Cho một đa giác nguyên nhất định với diện tích khác không.

Chúng ta ký hiệu diện tích của nó là $S$, số điểm có tọa độ nguyên nằm hoàn toàn bên trong đa giác là $I$ và số điểm nằm trên các cạnh của đa giác là $B$.

Sau đó, **công thức Pick** phát biểu:

$$S=I+\frac{B}{2}-1$$

Đặc biệt, nếu các giá trị của $I$ và $B$ cho một đa giác được cho, diện tích có thể được tính trong $O(1)$ mà không cần biết các đỉnh.

Công thức này được phát hiện và chứng minh bởi nhà toán học người Áo Georg Alexander Pick vào năm 1899.

## Chứng minh

Bằng chứng được thực hiện theo nhiều giai đoạn: từ đa giác đơn giản đến đa giác tùy ý:

- Một hình vuông đơn: $S=1, I=0, B=4$, thỏa mãn công thức.

- Một hình chữ nhật không suy biến tùy ý có các cạnh song song với trục tọa độ: Giả sử $a$ và $b$ là độ dài các cạnh của hình chữ nhật. Sau đó, $S=ab, I=(a-1)(b-1), B=2(a+b)$. Khi thay thế, chúng ta thấy rằng công thức là đúng.

- Một tam giác vuông có các cạnh góc vuông song song với các trục: Để chứng minh điều này, lưu ý rằng bất kỳ tam giác nào như vậy đều có thể được tạo bằng cách cắt một hình chữ nhật bằng một đường chéo. Ký hiệu số điểm nguyên nằm trên đường chéo là $c$, có thể chứng minh rằng công thức Pick đúng với tam giác này bất kể $c$.

- Một tam giác tùy ý: Lưu ý rằng bất kỳ tam giác nào như vậy đều có thể được biến thành một hình chữ nhật bằng cách gắn nó vào các cạnh của tam giác vuông có các cạnh góc vuông song song với các trục (bạn sẽ không cần nhiều hơn 3 tam giác như vậy). Từ đây, chúng ta có thể nhận được công thức chính xác cho bất kỳ tam giác nào.

- Một đa giác tùy ý: Để chứng minh điều này, hãy tam giác hóa nó, tức là chia thành các tam giác có tọa độ nguyên. Hơn nữa, có thể chứng minh rằng định lý Pick vẫn giữ nguyên giá trị khi một đa giác được thêm vào một tam giác. Như vậy, chúng ta đã chứng minh công thức Pick cho đa giác tùy ý.

## Khái quát hóa lên các chiều cao hơn

Thật không may, công thức đơn giản và đẹp mắt này không thể được khái quát hóa lên các chiều cao hơn.

John Reeve đã chứng minh điều này bằng cách đề xuất một tứ diện (**tứ diện Reeve**) với các đỉnh sau vào năm 1957:

$$A=(0,0,0),
B=(1,0,0),
C=(0,1,0),
D=(1,1,k),$$

trong đó $k$ có thể là bất kỳ số tự nhiên nào. Khi đó, với mọi $k$, tứ diện $ABCD$ không chứa điểm nguyên bên trong nó và chỉ có $4$ điểm trên đường biên của nó, $A, B, C, D$. Do đó, thể tích và diện tích bề mặt có thể thay đổi mặc dù số lượng điểm bên trong và trên ranh giới không thay đổi. Do đó, định lý Pick không cho phép khái quát hóa.

Tuy nhiên, các chiều cao hơn vẫn có sự khái quát hóa bằng cách sử dụng **đa thức Ehrhart** nhưng chúng khá phức tạp và không chỉ phụ thuộc vào các điểm bên trong mà còn phụ thuộc vào ranh giới của hình học.

## Tài nguyên bổ sung
Một vài ví dụ đơn giản và một cách chứng minh đơn giản cho định lý Pick có thể được tìm thấy [tại đây](http://www.geometer.org/mathcircles/pick.pdf).

--- 



