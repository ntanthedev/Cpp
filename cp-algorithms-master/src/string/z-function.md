---
tags:
  - Translated
e_maxx_link: z_function
---

# Hàm Z và cách tính toán của nó

Giả sử chúng ta được cung cấp một chuỗi $s$ có độ dài $n$. **Hàm Z** cho chuỗi này là một mảng có độ dài $n$ trong đó phần tử thứ $i$ bằng với số lượng lớn nhất các ký tự bắt đầu từ vị trí $i$ mà trùng khớp với các ký tự đầu tiên của $s$.

Nói cách khác, $z[i]$ là độ dài của chuỗi dài nhất mà đồng thời là một tiền tố của $s$ và là một tiền tố của hậu tố của $s$ bắt đầu từ $i$.

**Chú ý.** Trong bài viết này, để tránh sự mơ hồ, chúng ta giả định sử dụng chỉ số bắt đầu từ $0$; tức là: ký tự đầu tiên của $s$ có chỉ số là $0$ và ký tự cuối cùng có chỉ số là $n-1$.

Phần tử đầu tiên của Hàm Z, $z[0]$, thường không được xác định rõ ràng. Trong bài viết này, chúng ta sẽ giả định nó là zero (mặc dù điều này không làm thay đổi bất kỳ điều gì trong cài đặt thuật toán).

Bài viết này trình bày một thuật toán để tính toán Hàm Z trong thời gian $O(n)$, cũng như các ứng dụng khác nhau của nó.

## Ví dụ

Ví dụ, dưới đây là các giá trị của Hàm Z được tính toán cho các chuỗi khác nhau:

* "aaaaa" - $[0, 4, 3, 2, 1]$
* "aaabaab" - $[0, 2, 1, 0, 2, 1, 0]$
* "abacaba" - $[0, 0, 1, 0, 3, 0, 1]$

## Thuật toán trắc nghiệm

Định nghĩa chính thức có thể được biểu diễn trong cài đặt cơ bản $O(n^2)$ sau đây.

```cpp
vector<int> z_function_trivial(string s) {
	int n = s.size();
	vector<int> z(n);
	for (int i = 1; i < n; i++) {
		while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
			z[i]++;
		}
	}
	return z;
}
```

Chúng ta chỉ cần lặp qua mỗi vị trí $i$ và cập nhật $z[i]$ cho mỗi một trong số chúng, bắt đầu từ $z[i] = 0$ và tăng nó cho đến khi chúng ta không tìm thấy một sự không phù hợp (và cho đến khi chúng ta không đạt được cuối của dòng).

Tất nhiên, đây không phải là một cài đặt hiệu quả. Bây giờ chúng ta sẽ chỉ ra cách xây dựng một cài đặt hiệu quả.

## Thuật toán hiệu quả để tính toán Hàm Z

Để có được một thuật toán hiệu quả, chúng ta sẽ tính toán các giá trị của $z[i]$ lần lượt từ $i = 1$ đến $n - 1$ nhưng đồng thời, khi tính toán một giá trị mới, chúng ta sẽ cố gắng sử dụng tốt nhất có thể các giá trị đã tính toán trước đó.

Vì sự ngắn gọn, hãy gọi các **tương đương phân đoạn** là các phụ chuỗi trùng khớp với một tiền tố của $s$. Ví dụ, giá trị của Hàm Z mong muốn $z[i]$ là độ dài của tương đương phân đoạn bắt đầu từ vị trí $i$ (và kết thúc tại vị trí $i + z[i] - 1$).

Để làm điều này, chúng ta sẽ giữ **các chỉ số $[l, r)$ của tương đương phân đoạn phải nhất**. Nghĩa là, trong số tất cả các phân đoạn phát hiện chúng ta sẽ giữ lại phân đoạn kết thúc cuối cùng. Một cách, chỉ số $r$ có thể được xem như "ranh giới" mà chuỗi $s$ của chúng ta đã được quét bởi thuật toán; mọi thứ vượt ra ngoài điểm đó vẫn chưa biết.

Sau đó, nếu chỉ số hiện tại (cho đó chúng ta phải tính toán giá trị tiếp theo của Hàm Z) là $i$, chúng ta có hai lựa chọn:

*   $i \geq r$ -- vị trí hiện tại **nằm bên ngoài** những gì chúng ta đã xử lý trước đó.

    Chúng ta sẽ tính toán $z[i]$ với **thuật toán trắc nghiệm** (nghĩa là chỉ so sánh giá trị một c

ách tuần tự). Lưu ý rằng cuối cùng, nếu $z[i] > 0$, chúng ta sẽ phải cập nhật các chỉ số của phân đoạn phải nhất, bởi vì ta đảm bảo rằng giá trị mới $r = i + z[i]$ tốt hơn so với $r$ trước đó.

*   $i < r$ -- vị trí hiện tại nằm bên trong phân đoạn phù hợp hiện tại $[l, r)$.

    Sau đó, chúng ta có thể sử dụng các giá trị Hàm Z đã tính trước đó để "khởi tạo" giá trị của $z[i]$ thành cái gì đó (chắc chắn là tốt hơn "bắt đầu từ không"), có thể thậm chí là một số lớn.

    Đối với điều này, chúng ta quan sát rằng các chuỗi con $s[l \dots r)$ và $s[0 \dots r-l)$ **trùng khớp**. Điều này có nghĩa là như một ước lượng ban đầu cho $z[i]$ chúng ta có thể lấy giá trị đã tính toán trước đó cho phân đoạn tương ứng $s[0 \dots r-l)$, và đó là $z[i-l]$.

    Tuy nhiên, giá trị $z[i-l]$ có thể quá lớn: khi áp dụng vào vị trí $i$ nó có thể vượt qua chỉ số $r$. Điều này không được phép vì chúng ta không biết gì về các ký tự bên phải của $r$: chúng có thể khác với những gì yêu cầu.

    Dưới đây là **một ví dụ** về một kịch bản tương tự:

    $$ s = "aaaabaa" $$

    Khi chúng ta đến vị trí cuối cùng ($i = 6$), phân đoạn phù hợp hiện tại sẽ là $[5, 7)$. Vị trí $6$ sau đó sẽ phù hợp với vị trí $6 - 5 = 1$, cho đó giá trị của Hàm Z là $z[1] = 3$. Rõ ràng, chúng ta không thể khởi tạo $z[6]$ thành $3$, điều đó hoàn toàn không chính xác. Giá trị lớn nhất mà chúng ta có thể khởi tạo là $1$ -- bởi vì nó là giá trị lớn nhất không đưa chúng ta vượt qua chỉ số $r$ của phân đoạn phù hợp $[l, r)$.

    Do đó, như một **ước lượng ban đầu** cho $z[i]$ chúng ta có thể an toàn lấy:

    $$ z_0[i] = \min(r - i,\; z[i-l]) $$

    Sau khi đã khởi tạo $z[i]$ thành $z_0[i]$, chúng ta cố gắng tăng $z[i]$ bằng cách chạy **thuật toán trắc nghiệm** -- vì nói chung, sau ranh giới $r$, chúng ta không thể biết liệu phân đoạn sẽ tiếp tục phù hợp hay không.

Do đó, toàn bộ thuật toán được chia thành hai trường hợp, khác nhau chỉ trong **giá trị ban đầu** của $z[i]$: trong trường hợp đầu tiên nó được giả định là không, trong trường hợp thứ hai nó được xác định bởi các giá trị đã tính toán trước đó (sử dụng công thức trên). Sau đó, cả hai nhánh của thuật toán này có thể được giảm xuống cài đặt của **thuật toán trắc nghiệm**, bắt đầu ngay sau khi chúng ta chỉ định giá trị ban đầu.

Thuật toán hoàn toàn đơn giản. Mặc dù trong mỗi lần lặp lại, thuật toán trắc nghiệm được thực hiện, chúng ta đã thực hiện được tiến triển đáng kể, có được một thuật toán chạy trong thời gian tuyến tính. Sau đó, chúng ta sẽ chứng minh rằng thời gian chạy là tuyến tính.

## Cài đặt

Cài đặt cuối cùng khá ngắn gọn:

```cpp
vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}
```

### Nhận xét về cách thực hiện này

Toàn bộ giải pháp được thể hiện dưới dạng một hàm trả về một mảng có độ dài $n$ -- Z-function của chuỗi $s$.

Mảng $z$ được khởi tạo ban đầu với các giá trị không. Đoạn phân đoạn khớp phù hợp hiện tại được giả định là $[0; 0)$ (tức là, một đoạn nhỏ một cách cố ý mà không chứa bất kỳ $i$ nào).

Trong vòng lặp cho $i = 1 \dots n - 1$ chúng ta đầu tiên xác định giá trị ban đầu $z[i]$ -- nó sẽ hoặc giữ nguyên là không hoặc được tính toán bằng cách sử dụng công thức ở trên.

Sau đó, thuật toán tùy ý cố gắng tăng giá trị của $z[i]$ càng nhiều càng tốt.

Cuối cùng, nếu cần (tức là, nếu $i + z[i] > r$), chúng ta cập nhật đoạn phân đoạn khớp phù hợp nhất $[l, r)$.

## Hành vi lượng tử của thuật toán

Chúng ta sẽ chứng minh rằng thuật toán trên có thời gian chạy tuyến tính theo độ dài của chuỗi -- do đó, đó là $O(n)$.

Bằng chứng rất đơn giản.

Chúng ta quan tâm đến vòng lặp lồng nhau `while`, vì mọi thứ khác đều chỉ là một loạt các phép toán hằng số mà tổng cộng là $O(n)$.

Chúng ta sẽ chứng minh rằng **mỗi lần lặp** của vòng lặp `while` sẽ tăng giá trị của biên phải $r$ của đoạn phân đoạn khớp phù hợp.

Để làm điều đó, chúng ta sẽ xem xét cả hai nhánh của thuật toán:

*   $i \geq r$

    Trong trường hợp này, hoặc vòng lặp `while` sẽ không thực hiện bất kỳ lần lặp nào (nếu $s[0] \ne s[i]$), hoặc nó sẽ thực hiện một vài lần lặp, bắt đầu từ vị trí $i$, mỗi lần di chuyển một ký tự sang phải. Sau đó, biên phải $r$ sẽ chắc chắn được cập nhật.

    Vì vậy, chúng ta đã tìm ra rằng, khi $i \geq r$, mỗi lần lặp của vòng lặp `while` tăng giá trị của chỉ số mới $r$.

*   $i < r$

    Trong trường hợp này, chúng ta khởi tạo $z[i]$ thành một giá trị ban đầu $z_0$ được cho bởi công thức ở trên. Hãy so sánh giá trị ban đầu $z_0$ này với giá trị $r - i$. Chúng ta sẽ có ba trường hợp:

      *   $z_0 < r - i$

          Chúng ta chứng minh rằng trong trường hợp này không có lần lặp nào của vòng lặp `while` được thực hiện.

          Dễ dàng chứng minh, ví dụ, bằng phản chứng: nếu vòng lặp `while` thực hiện ít nhất một lần, điều đó sẽ có nghĩa là ước lượng ban đầu $z[i] = z_0$ là không chính xác (nhỏ hơn độ dài thực tế của khớp). Nhưng vì $s[l \dots r)$ và $s[0 \dots r-l)$ giống nhau, điều này sẽ ngụ ý rằng $z[i-l]$ giữ giá trị sai (ít hơn so với nên có).

          Do đó, vì $z[i-l]$ là chính xác và nó nhỏ hơn $r - i$, nó suy ra rằng giá trị này trùng khớp với giá trị yêu cầu $z[i]$.

      *   $z_0 = r - i$

          Trong trường hợp này, vòng lặp `while` có thể thực hiện một vài lần, nhưng mỗi lần sẽ dẫn đến việc tăng giá trị của chỉ số $r$ vì chúng ta sẽ bắt đầu so sánh từ $s[r]$, điều này sẽ vượt qua khoảng $[l, r)$.

      *   $z_0 > r - i$

          Tùy chọn này là không thể, theo định nghĩa của $z_0$.

Vậy, chúng ta đã chứng minh rằng mỗi lần lặp của vòng lặp trong cùng tạo sự tiến bộ cho con trỏ $r$ sang phải. Vì $r$ không thể lớn hơn $n-1$, điều này có nghĩa là vòng lặp trong cùng không thực hiện nhiều hơn $n-1$ lần lặp.

Vì phần còn lại của thuật toán rõ ràng hoạt động trong $O(n)$, chúng ta đã chứng minh rằng toàn bộ thuật toán để tính Z

-functions chạy trong thời gian tuyến tính.

## Ứng dụng

Chúng ta sẽ xem xét một số ứng dụng của Z-functions cho các nhiệm vụ cụ thể.

Các ứng dụng này sẽ phần lớn tương tự như các ứng dụng của [hàm tiền tố](prefix-function.md).

### Tìm chuỗi con

Để tránh nhầm lẫn, chúng ta gọi $t$ là **chuỗi văn bản**, và $p$ là **mẫu**. Vấn đề là: tìm tất cả các lần xuất hiện của mẫu $p$ trong văn bản $t$.

Để giải quyết vấn đề này, chúng ta tạo một chuỗi mới $s = p + \diamond + t$, tức là, chúng ta áp dụng phép nối chuỗi vào $p$ và $t$ nhưng chúng ta cũng đặt một ký tự phân tách $\diamond$ ở giữa (chúng ta sẽ chọn $\diamond$ sao cho nó chắc chắn không xuất hiện ở bất kỳ nơi nào trong các chuỗi $p$ hoặc $t$).

Tính Z-function cho $s$. Sau đó, đối với mọi $i$ trong khoảng $[0; \; \operatorname{length}(t) - 1]$, chúng ta sẽ xem xét giá trị tương ứng $k = z[i + \operatorname{length}(p) + 1]$. Nếu $k$ bằng $\operatorname{length}(p)$ thì chúng ta biết có một lần xuất hiện của $p$ ở vị trí thứ $i$ của $t$, ngược lại không có lần xuất hiện nào của $p$ ở vị trí thứ $i$ của $t$.

Thời gian chạy (và lượng bộ nhớ tiêu tốn) là $O(\operatorname{length}(t) + \operatorname{length}(p))$.

### Số lượng chuỗi con phân biệt trong một chuỗi

Cho một chuỗi $s$ có độ dài $n$, hãy đếm số lượng chuỗi con phân biệt của $s$.

Chúng ta sẽ giải quyết vấn đề này theo cách lặp lại. Đó là: biết số lượng chuỗi con khác nhau hiện tại, tính lại lượng này sau khi thêm một ký tự vào cuối của $s$.

Vì vậy, hãy để $k$ là số lượng chuỗi con phân biệt hiện tại của $s$. Chúng ta thêm một ký tự mới $c$ vào $s$. Rõ ràng, có thể có một số chuỗi con mới kết thúc ở ký tự mới này $c$ (nghĩa là, tất cả các chuỗi đó kết thúc bằng ký tự này và chúng ta chưa gặp trước đó).

Lấy một chuỗi $t = s + c$ và đảo ngược nó (viết các ký tự của nó theo thứ tự ngược lại). Bài toán của chúng ta bây giờ là đếm có bao nhiêu tiền tố của $t$ không xuất hiện ở bất kỳ nơi nào khác trong $t$. Hãy tính Z-function của $t$ và tìm giá trị lớn nhất của nó $z_{max}$. Rõ ràng, tiền tố của $t$ có độ dài $z_{max}$ cũng xuất hiện ở một nơi nào đó giữa $t$. Rõ ràng, các tiền tố ngắn hơn cũng xuất hiện.

Vì vậy, chúng ta đã tìm ra rằng số lượng chuỗi con mới xuất hiện khi ký tự $c$ được thêm vào $s$ bằng $\operatorname{length}(t) - z_{max}$.

Do đó, thời gian chạy của giải pháp này là $O(n^2)$ cho một chuỗi có độ dài $n$.

Cần lưu ý rằng cách tính lại số lượng chuỗi con phân biệt khi thêm một ký tự vào đầu chuỗi hoặc khi loại bỏ nó (từ cuối hoặc từ đầu) cũng có thể được thực hiện trong thời gian $O(n)$.

### Nén chuỗi

Cho một chuỗi $s$ có độ dài $n$. Tìm biểu diễn "nén" ngắn nhất của nó, nghĩa là: tìm một chuỗi $t$ có độ dài ngắn nhất sao cho $s$ có thể được biểu diễn dưới dạng một sự kết hợp của một hoặc nhiều bản sao của $t$.

Một giải pháp là: tính Z-function của $s$, lặp qua tất cả các $i$ sao cho $i$ chia hết cho $n$. Dừng lại ở $i$ đầu tiên sao cho $i + z[i] = n$. Sau đó, chuỗi $s$ có thể được nén xuống độ dài $i$.

Bằng chứng cho sự thật này giống như giải pháp sử dụng [hàm tiền tố](prefix-function.md).

## Bài tập thực hành

* [eolymp - Blocks of string](https://www.eolymp.com/en/problems/1309)
* [Codeforces - Password [Độ khó: Dễ]](http://codeforces.com/problem

set/problem/126/B)
* [UVA # 455 "Periodic Strings" [Độ khó: Trung bình]](http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=396)
* [UVA # 11022 "String Factoring" [Độ khó: Trung bình]](http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1963)
* [UVa 11475 - Extend to Palindrome](http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2470)
* [LA 6439 - Pasti Pas!](https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=588&page=show_problem&problem=4450)
* [Codechef - Chef and Strings](https://www.codechef.com/problems/CHSTR)
* [Codeforces - Prefixes and Suffixes](http://codeforces.com/problemset/problem/432/D)