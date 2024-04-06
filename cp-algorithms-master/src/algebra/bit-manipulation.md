---
tags:
  - translated
---
# Bit manipulation

## Số nhị phân

Một **số nhị phân** là một số được biểu diễn trong hệ thống đếm nhị phân hoặc hệ thống số nhị phân, đây là một phương pháp biểu diễn toán học chỉ sử dụng hai ký hiệu: thường là "0" (zero) và "1" (one).

Chúng ta nói rằng một bit cụ thể được **đặt**, nếu nó là một, và **xóa** nếu nó là không.

Số nhị phân $(a_k a_{k-1} \dots a_1 a_0)_2$ biểu diễn số:

$$(a_k a_{k-1} \dots a_1 a_0)_2 = a_k \cdot 2^k + a_{k-1} \cdot 2^{k-1} + \dots + a_1 \cdot 2^1 + a_0 \cdot 2^0.$$

Ví dụ, số nhị phân $1101_2$ biểu diễn số $13$:

$$\begin{align}
1101_2 &= 1 \cdot 2^3 + 1 \cdot 2^2 + 0 \cdot 2^1 + 1 \cdot 2^0 \\
       &= 1\cdot 8 + 1 \cdot 4 + 0 \cdot 2 + 1 \cdot 1 = 13
\end{align}$$

Máy tính biểu diễn số nguyên dưới dạng số nhị phân.
Số nguyên dương (cả có dấu và không dấu) chỉ đơn giản là được biểu diễn bằng các chữ số nhị phân của chúng, và các số âm (có thể là dương và âm) thường được biểu diễn bằng [Bù hai](https://vi.wikipedia.org/wiki/B%C3%B9_hai).

```cpp
unsigned int unsigned_number = 13;
assert(unsigned_number == 0b1101);

int positive_signed_number = 13;
assert(positive_signed_number == 0b1101);

int negative_signed_number = -13;
assert(negative_signed_number == 0b1111'1111'1111'1111'1111'1111'1111'0011);
```

CPU rất nhanh chóng thao tác các bit đó với các hoạt động cụ thể.
Đối với một số vấn đề, chúng ta có thể sử dụng biểu diễn số nhị phân này để tận dụng, và tăng tốc thời gian thực thi.
Và đối với một số vấn đề (thường là trong tổ hợp hoặc lập trình động) nơi chúng ta muốn theo dõi các đối tượng đã chọn từ một tập hợp đã cho, chúng ta chỉ cần sử dụng một số nguyên đủ lớn trong đó mỗi chữ số đại diện cho một đối tượng và tùy thuộc vào việc chúng ta chọn hoặc bỏ đối tượng chúng ta đặt hoặc xóa chữ số đó.

## Toán tử bit

Tất cả các toán tử được giới thiệu ở đây đều là ngay lập tức (cùng tốc độ với một phép cộng) trên một CPU cho các số nguyên có độ dài cố định.

### Toán tử bit

-   $\&$ : Toán tử AND bit so sánh từng bit của toán hạng đầu tiên của nó với bit tương ứng của toán hạng thứ hai của nó.
    Nếu cả hai bit đều là 1, bit kết quả tương ứng được đặt thành 1. Ngược lại, bit kết quả tương ứng được đặt thành 0.
 	
-   $|$ : Toán tử OR bit bao gồm so sánh từng bit của toán hạng đầu tiên của nó với bit tương ứng của toán hạng thứ hai của nó.
    Nếu một trong hai bit là 1, bit kết quả tương ứng được đặt thành 1. Ngược lại, bit kết quả tương ứng được đặt thành 0.

-   $\wedge$ : Toán tử XOR bit so sánh từng bit của toán hạng đầu tiên của nó với bit tương ứng của toán hạng thứ hai của nó.
    Nếu một bit là 0 và bit khác là 1, bit kết quả tương ứng được đặt thành 1. Ngược lại, bit kết quả tương ứng được đặt thành 0.

-   $\sim$ : Toán tử NOT bit đảo ngược mỗi bit của một số, nếu một bit được đặt thì toán tử sẽ xóa nó, nếu nó bị xóa thì toán tử sẽ đặt nó.

Ví dụ:

```
n         = 01011000
n-1       = 01010111
--------------------
n & (n-1) = 01010000
```

```
n         = 01011000
n-1       = 01010111
--------------------
n | (n-1) = 01011111
```

```
n         = 01011000
n-1       = 01010111
--------------------
n ^ (n-1) = 00001111
```

```
n         = 01011000
--------------------
~n        = 10100111
```

### Toán tử dịch

Có hai toán tử để dịch các bit.

-   $\gg$ Dịch một số sang phải bằng cách loại bỏ các chữ số nhị phân cuối cùng của số.
    M

ỗi lần dịch qua một đơn vị tương ứng với một phép chia nguyên cho 2, vì vậy một phép dịch sang phải bởi $k$ đơn vị đại diện cho một phép chia nguyên cho $2^k$.

    Ví dụ: $5 \gg 2 = 101_2 \gg 2 = 1_2 = 1$ tương đương với $\frac{5}{2^2} = \frac{5}{4} = 1$.
    Đối với máy tính, việc dịch một số bit nhanh hơn rất nhiều so với việc thực hiện các phép chia.

-   $\ll$ Dịch một số sang trái bằng cách thêm các chữ số 0.
    Tương tự như việc dịch sang phải bởi $k$, một phép dịch sang trái bởi $k$ đại diện cho một phép nhân với $2^k$.

    Ví dụ: $5 \ll 3 = 101_2 \ll 3 = 101000_2 = 40$ tương đương với $5 \cdot 2^3 = 5 \cdot 8 = 40$.

    Tuy nhiên, lưu ý rằng đối với một số nguyên có độ dài cố định, điều đó có nghĩa là loại bỏ các chữ số ở bên trái nhất, và nếu bạn dịch quá nhiều bạn sẽ kết thúc với số $0$.

## Các thủ thuật hữu ích

### Đặt/chuyển bit/clear bit

Sử dụng dịch bit và một số hoạt động bit cơ bản, chúng ta có thể dễ dàng đặt, chuyển hoặc xóa một bit.
$1 \ll x$ là một số chỉ có bit thứ $x$ được đặt, trong khi $\sim(1 \ll x)$ là một số có tất cả các bit được đặt trừ bit thứ $x$.

- $n ~|~ (1 \ll x)$ đặt bit thứ $x$ trong số $n$
- $n ~\wedge~ (1 \ll x)$ chuyển đổi bit thứ $x$ trong số $n$
- $n ~\&~ \sim(1 \ll x)$ xóa bit thứ $x$ trong số $n$

### Kiểm tra một bit có được đặt không

Giá trị của bit thứ $x$ có thể được kiểm tra bằng cách dịch số $x$ vị trí sang phải, để bit thứ $x$ nằm ở vị trí đơn vị, sau đó chúng ta có thể trích xuất nó bằng cách thực hiện một phép & bit với 1.

``` cpp
bool is_set(unsigned int number, int x) {
    return (number >> x) & 1;
}
```

### Kiểm tra xem số có chia hết cho một lũy thừa của 2 không

Sử dụng phép AND, chúng ta có thể kiểm tra xem một số $n$ có chẵn không vì $n ~\&~ 1 = 0$ nếu $n$ là số chẵn, và $n ~\&~ 1 = 1$ nếu $n$ là số lẻ.
Nói chung hơn, $n$ chia hết cho $2^{k}$ chính xác khi $n ~\&~ (2^{k} − 1) = 0$.

``` cpp
bool isDivisibleByPowerOf2(int n, int k) {
    int powerOf2 = 1 << k;
    return (n & (powerOf2 - 1)) == 0;
}
```

Chúng ta có thể tính $2^{k}$ bằng cách dịch trái 1 sang phải $k$ vị trí.
Thủ thuật này hoạt động vì $2^k - 1$ là một số có chính xác $k$ chữ số 1.
Và một số chia hết cho $2^k$ phải có các chữ số không trong những vị trí đó.

### Kiểm tra xem một số nguyên có phải là một lũy thừa của 2 không

Một lũy thừa của hai là một số chỉ có một bit duy nhất trong đó (ví dụ: $32 = 0010~0000_2$), trong khi số tiền đề của số đó không được đặt và tất cả các chữ số sau nó được đặt ($31 = 0001~1111_2$).
Vì vậy phép AND bit của một số với số tiền đề của nó luôn luôn là 0, vì họ không có bất kỳ chữ số nào chung được đặt.
Bạn có thể dễ dàng kiểm tra rằng điều này chỉ xảy ra cho lũy thừa của hai và cho số $0$ có sẵn mà không có chữ số nào được đặt.

``` cpp
bool isPowerOfTwo(unsigned int n) {
    return n && !(n & (n - 1));
}
```

### Xóa bit được đặt ở bên phải nhất

Biểu thức $n ~\&~ (n-1)$ có thể được sử dụng để tắt bit được đặt ở bên phải nhất của một số $n$.
Điều này hoạt động bởi vì biểu thức $n-1$ đảo ngược tất cả các bit sau bit được đặt bên phải nhất của $n$, bao gồm cả bit được đặt bên phải nhất.
Vì vậy, tất cả các chữ số đó đều khác với số gốc, và bằng cách thực hiện một phép AND bit chúng đều được đặt thành 0, đưa ra số gốc $n$ với bit được đặt bên phải nhất bị đảo.

Ví dụ, xem xét số $52 = 0011~0100_2$:

```
n         = 00110100
n-1       = 00110011
--------------------
n & (n-1) = 00110000
```

### Thuật toán của Brian Kernighan

Chúng ta có thể đếm số bit được đặt bằng biểu thức trên.

Ý tưởng là chỉ xem xét các bit được đặt của một số bằng cách tắt bit được đặt bên phải nhất của nó (sau khi đếm nó), vì vậy lần lặp tiếp theo của vòng lặp xem xét Bit Bên phải Kế tiếp.

``` cpp
int countSetBits(int n)
{
    int count = 0;
    while (n)
    {
        n = n & (n - 1);
        count++;
    }
    return count;
}
```

### Các thủ thuật bổ sung

- $n ~\&~ (n + 1)$ xóa tất cả các bit cuối: $0011~0111_2 \rightarrow 0011~0000_2$.
- $n ~|~ (n + 1)$ đặt bit cuối cùng đã bị xóa: $0011~0101_2 \rightarrow 0011~0111_2$.
- $n ~\&~ -n$ trí

ch xuất bit được đặt cuối cùng: $0011~0100_2 \rightarrow 0000~0100_2$.

Có thể tìm thấy nhiều hơn trong cuốn sách [Hacker's Delight](https://en.wikipedia.org/wiki/Hacker%27s_Delight).

### Ngôn ngữ và hỗ trợ trình biên dịch

C++ hỗ trợ một số trong những hoạt động đó kể từ C++20 thông qua thư viện chuẩn [bit](https://en.cppreference.com/w/cpp/header/bit):

- `has_single_bit`: kiểm tra xem số có phải là lũy thừa của hai không
- `bit_ceil` / `bit_floor`: làm tròn lên/xuống đến lũy thừa của hai tiếp theo
- `rotl` / `rotr`: xoay các bit trong số
- `countl_zero` / `countr_zero` / `countl_one` / `countr_one`: đếm số lượng bit không/được đặt ở đầu/cuối
- `popcount`: đếm số lượng bit được đặt

Ngoài ra, cũng có các hàm được xác định trước trong một số trình biên dịch giúp làm việc với các bit.
Ví dụ: GCC xác định một danh sách tại [Các Hàm Tích Hợp Sẵn của GCC](https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html) cũng hoạt động trong các phiên bản cũ hơn của C++:

- `__builtin_popcount(unsigned int)` trả về số lượng bit được đặt (`__builtin_popcount(0b0001'0010'1100) == 4`)
- `__builtin_ffs(int)` tìm chỉ số của bit đầu tiên (bên phải nhất) được đặt (`__builtin_ffs(0b0001'0010'1100) == 3`)
- `__builtin_clz(unsigned int)` số lượng số không đứng đầu (`__builtin_clz(0b0001'0010'1100) == 23`)
- `__builtin_ctz(unsigned int)` số lượng số không cuối cùng (`__builtin_ctz(0b0001'0010'1100) == 2`)
- ` __builtin_parity(x)` chẵn hay lẻ của số lượng bit một trong biểu diễn bit

_Lưu ý rằng một số trong các hoạt động (cả hai hàm C++20 và hàm Trình biên dịch tích hợp) có thể khá chậm trong GCC nếu bạn không kích hoạt một mục tiêu trình biên dịch cụ thể với `#pragma GCC target("popcnt")`._