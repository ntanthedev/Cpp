# Hàm Z và cách tính toán

---
tags:
  - Dịch
e_maxx_link: z_function
---

# Hàm Z và cách tính toán

Giả sử chúng ta được cho một chuỗi $s$ có độ dài $n$. **Hàm Z** cho chuỗi này là một mảng có độ dài $n$ trong đó phần tử thứ $i$ bằng với số lượng ký tự lớn nhất bắt đầu từ vị trí $i$ trùng với các ký tự đầu tiên của $s$.

Nói cách khác, $z[i]$ là độ dài của chuỗi dài nhất, đồng thời là tiền tố của $s$ và là tiền tố của hậu tố của $s$ bắt đầu từ $i$.

**Lưu ý.** Trong bài viết này, để tránh nhầm lẫn, chúng ta giả sử chỉ mục dựa trên 0; đó là: ký tự đầu tiên của $s$ có chỉ mục $0$ và ký tự cuối cùng có chỉ mục $n-1$.

Phần tử đầu tiên của hàm Z, $z[0]$, thường không được xác định rõ ràng. Trong bài viết này, chúng ta sẽ giả sử nó bằng không (mặc dù nó không thay đổi bất cứ điều gì trong việc triển khai thuật toán).

Bài viết này trình bày một thuật toán để tính hàm Z trong thời gian $O(n)$, cũng như các ứng dụng khác nhau của nó.

## Ví dụ

Ví dụ: đây là các giá trị của hàm Z được tính toán cho các chuỗi khác nhau:

* "aaaaa" - $[0, 4, 3, 2, 1]$
* "aaabaab" - $[0, 2, 1, 0, 2, 1, 0]$
* "abacaba" - $[0, 0, 1, 0, 3, 0, 1]$

## Thuật toán đơn giản

Định nghĩa hình thức có thể được biểu diễn trong cách triển khai $O(n^2)$ cơ bản sau đây.

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

Chúng ta chỉ cần lặp qua mọi vị trí $i$ và cập nhật $z[i]$ cho mỗi vị trí trong số chúng, bắt đầu từ $z[i] = 0$ và tăng dần nó miễn là chúng ta không tìm thấy sự không khớp (và miễn là chúng ta không đạt đến cuối dòng).

Tất nhiên, đây không phải là một cách triển khai hiệu quả. Bây giờ chúng ta sẽ trình bày việc xây dựng một cách triển khai hiệu quả.

## Thuật toán hiệu quả để tính hàm Z

Để có được một thuật toán hiệu quả, chúng ta sẽ tính toán các giá trị của $z[i]$ lần lượt từ $i = 1$ đến $n - 1$ nhưng đồng thời, khi tính toán một giá trị mới, chúng ta sẽ cố gắng sử dụng tốt nhất có thể các giá trị đã tính toán trước đó.

Để ngắn gọn, hãy gọi **các đoạn khớp** là những chuỗi con trùng với tiền tố của $s$. Ví dụ: giá trị của hàm Z mong muốn $z[i]$ là độ dài của đoạn khớp bắt đầu từ vị trí $i$ (và kết thúc ở vị trí $i + z[i] - 1$).

Để thực hiện việc này, chúng ta sẽ giữ **chỉ số $[l, r)$ của đoạn khớp ngoài cùng bên phải**. Đó là, trong số tất cả các đoạn được phát hiện, chúng ta sẽ giữ lại đoạn kết thúc ngoài cùng bên phải. Theo một cách nào đó, chỉ số $r$ có thể được xem như "ranh giới" mà chuỗi $s$ của chúng ta đã được thuật toán quét; mọi thứ vượt quá điểm đó vẫn chưa được biết.

Sau đó, nếu chỉ số hiện tại (mà chúng ta phải tính giá trị tiếp theo của hàm Z) là $i$, chúng ta có một trong hai tùy chọn:

*   $i \geq r$ -- vị trí hiện tại nằm **ngoài** những gì chúng ta đã xử lý.

    Sau đó, chúng ta sẽ tính toán $z[i]$ bằng **thuật toán đơn giản** (tức là chỉ so sánh các giá trị từng cái một). Lưu ý rằng cuối cùng, nếu $z[i] > 0$, chúng ta sẽ phải cập nhật các chỉ số của đoạn khớp ngoài cùng bên phải, bởi vì đảm bảo rằng $r = i + z[i]$ mới tốt hơn $r$ trước đó.

*   $i < r$ -- vị trí hiện tại nằm trong đoạn khớp hiện tại $[l, r)$.

    Sau đó, chúng ta có thể sử dụng các giá trị Z đã được tính toán để "khởi tạo" giá trị của $z[i]$ thành một cái gì đó (chắc chắn là tốt hơn "bắt đầu từ 0"), thậm chí có thể là một số lớn.

    Đối với điều này, chúng ta quan sát thấy các chuỗi con $s[l \dots r)$ và $s[0 \dots r-l)$ **khớp nhau**. Điều này có nghĩa là như một xấp xỉ ban đầu cho $z[i]$, chúng ta có thể lấy giá trị đã được tính toán cho đoạn tương ứng $s[0 \dots r-l)$, và đó là $z[i-l]$.

    Tuy nhiên, giá trị $z[i-l]$ có thể quá lớn: khi được áp dụng cho vị trí $i$, nó có thể vượt quá chỉ số $r$. Điều này là không được phép vì chúng ta không biết gì về các ký tự ở bên phải của $r$: chúng có thể khác với những ký tự được yêu cầu.

    Đây là **ví dụ** về một kịch bản tương tự:

    $$ s = "aaaabaa" $$

    Khi chúng ta đến vị trí cuối cùng ($i = 6$), đoạn khớp hiện tại sẽ là $[5, 7)$. Vị trí $6$ sau đó sẽ khớp với vị trí $6 - 5 = 1$, mà giá trị của hàm Z là $z[1] = 3$. Rõ ràng, chúng ta không thể khởi tạo $z[6]$ thành $3$, điều đó sẽ hoàn toàn không chính xác. Giá trị tối đa mà chúng ta có thể khởi tạo nó là $1$ — bởi vì đó là giá trị lớn nhất mà không đưa chúng ta vượt quá chỉ số $r$ của đoạn khớp $[l, r)$.

    Như vậy, như một **xấp xỉ ban đầu** cho $z[i]$, chúng ta có thể an toàn lấy:

    $$ z_0[i] = \min(r - i,\; z[i-l]) $$

    Sau khi đã khởi tạo $z[i]$ thành $z_0[i]$, chúng ta cố gắng tăng $z[i]$ bằng cách chạy **thuật toán đơn giản** — bởi vì nói chung, sau ranh giới $r$, chúng ta không thể biết liệu đoạn có tiếp tục khớp hay không.

Như vậy, toàn bộ thuật toán được chia thành hai trường hợp, chỉ khác nhau ở **giá trị ban đầu** của $z[i]$: trong trường hợp thứ nhất, nó được giả sử là 0, trong trường hợp thứ hai, nó được xác định bởi các giá trị đã được tính toán trước đó (sử dụng công thức trên). Sau đó, cả hai nhánh của thuật toán này đều có thể được rút gọn thành việc triển khai **thuật toán đơn giản**, bắt đầu ngay sau khi chúng ta chỉ định giá trị ban đầu.

Thuật toán hóa ra rất đơn giản. Mặc dù thực tế là trên mỗi lần lặp, thuật toán đơn giản được chạy, chúng ta đã đạt được tiến bộ đáng kể, có một thuật toán chạy trong thời gian tuyến tính. Sau này chúng ta sẽ chứng minh rằng thời gian chạy là tuyến tính.

## Triển khai

Việc triển khai hóa ra khá ngắn gọn:

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

### Nhận xét về cách triển khai này

Toàn bộ giải pháp được đưa ra dưới dạng một hàm trả về một mảng có độ dài $n$ — hàm Z của $s$.

Mảng $z$ ban đầu được điền bằng 0. Đoạn khớp ngoài cùng bên phải hiện tại được giả định là $[0; 0)$ (tức là một đoạn nhỏ cố ý không chứa bất kỳ $i$ nào).

Bên trong vòng lặp cho $i = 1 \dots n - 1$, trước tiên chúng ta xác định giá trị ban đầu $z[i]$ — nó sẽ giữ nguyên bằng không hoặc được tính toán bằng cách sử dụng công thức trên.

Sau đó, thuật toán đơn giản cố gắng tăng giá trị của $z[i]$ càng nhiều càng tốt.

Cuối cùng, nếu cần (tức là nếu $i + z[i] > r$), chúng ta cập nhật đoạn khớp ngoài cùng bên phải $[l, r)$.

## Hành vi tiệm cận của thuật toán

Chúng ta sẽ chứng minh rằng thuật toán trên có thời gian chạy tuyến tính theo độ dài của chuỗi — do đó, nó là $O(n)$.

Bằng chứng rất đơn giản.

Chúng ta quan tâm đến vòng lặp `while` lồng nhau, vì mọi thứ khác chỉ là một loạt các phép toán hằng số có tổng là $O(n)$.

Chúng ta sẽ chỉ ra rằng **mỗi lần lặp** của vòng lặp `while` sẽ tăng ranh giới bên phải $r$ của đoạn khớp.

Để làm được điều đó, chúng ta sẽ xem xét cả hai nhánh của thuật toán:

*   $i \geq r$

    Trong trường hợp này, hoặc vòng lặp `while` sẽ không thực hiện bất kỳ lần lặp nào (nếu $s[0] \ne s[i]$), hoặc nó sẽ thực hiện một vài lần lặp, bắt đầu từ vị trí $i$, mỗi lần di chuyển một ký tự sang phải. Sau đó, ranh giới bên phải $r$ nhất thiết sẽ được cập nhật.

    Vì vậy, chúng ta đã thấy rằng, khi $i \geq r$, mỗi lần lặp của vòng lặp `while` sẽ làm tăng giá trị của chỉ số $r$ mới.

*   $i < r$

    Trong trường hợp này, chúng ta khởi tạo $z[i]$ thành một giá trị nhất định $z_0$ được cho bởi công thức trên. Hãy so sánh giá trị ban đầu $z_0$ này với giá trị $r - i$. Chúng ta sẽ có ba trường hợp:

      *   $z_0 < r - i$

          Chúng ta chứng minh rằng trong trường hợp này, không có lần lặp nào của vòng lặp `while` sẽ diễn ra.

          Nó rất dễ chứng minh, ví dụ, bằng phản chứng: nếu vòng lặp `while` thực hiện ít nhất một lần lặp, điều đó có nghĩa là xấp xỉ ban đầu $z[i] = z_0$ là không chính xác (nhỏ hơn độ dài thực tế của khớp). Nhưng vì $s[l \dots r)$ và $s[0 \dots r-l)$ là giống nhau, điều này ngụ ý rằng $z[i-l]$ giữ giá trị sai (nhỏ hơn giá trị nên có).

          Do đó, vì $z[i-l]$ là chính xác và nó nhỏ hơn $r - i$, nên giá trị này trùng với giá trị $z[i]$ cần thiết.

      *   $z_0 = r - i$

          Trong trường hợp này, vòng lặp `while` có thể thực hiện một vài lần lặp, nhưng mỗi lần lặp sẽ dẫn đến tăng giá trị của chỉ số $r$ vì chúng ta sẽ bắt đầu so sánh từ $s[r]$, sẽ leo ra ngoài khoảng $[l, r)$.

      *   $z_0 > r - i$

          Tùy chọn này là không thể, theo định nghĩa của $z_0$.

Vì vậy, chúng ta đã chứng minh rằng mỗi lần lặp của vòng lặp bên trong đều làm cho con trỏ $r$ tiến sang phải. Vì $r$ không thể lớn hơn $n-1$, điều này có nghĩa là vòng lặp bên trong sẽ không thực hiện quá $n-1$ lần lặp.

Vì phần còn lại của thuật toán rõ ràng hoạt động trong $O(n)$, chúng ta đã chứng minh rằng toàn bộ thuật toán để tính toán hàm Z chạy trong thời gian tuyến tính.

## Ứng dụng

Bây giờ chúng ta sẽ xem xét một số cách sử dụng hàm Z cho các nhiệm vụ cụ thể.

Các ứng dụng này sẽ phần lớn tương tự như các ứng dụng của [hàm tiền tố](prefix-function.md).

### Tìm kiếm chuỗi con

Để tránh nhầm lẫn, chúng ta gọi $t$ là **chuỗi văn bản** và $p$ là **mẫu**. Bài toán là: tìm tất cả các lần xuất hiện của mẫu $p$ bên trong văn bản $t$.

Để giải quyết bài toán này, chúng ta tạo một chuỗi mới $s = p + \diamond + t$, tức là chúng ta áp dụng phép nối chuỗi cho $p$ và $t$ nhưng chúng ta cũng đặt một ký tự phân tách $\diamond$ ở giữa (chúng ta sẽ chọn $\diamond$ để nó chắc chắn sẽ không xuất hiện ở bất kỳ đâu trong chuỗi $p$ hoặc $t$).

Tính hàm Z cho $s$. Sau đó, đối với bất kỳ $i$ nào trong khoảng $[0; \; \operatorname{length}(t) - 1]$, chúng ta sẽ xem xét giá trị tương ứng $k = z[i + \operatorname{length}(p) + 1]$. Nếu $k$ bằng $\operatorname{length}(p)$ thì chúng ta biết có một lần xuất hiện của $p$ ở vị trí thứ $i$ của $t$, ngược lại không có lần xuất hiện nào của $p$ ở vị trí thứ $i$ của $t$.

Thời gian chạy (và mức tiêu thụ bộ nhớ) là $O(\operatorname{length}(t) + \operatorname{length}(p))$.

### Số lượng chuỗi con phân biệt trong một chuỗi

Cho một chuỗi $s$ có độ dài $n$, hãy đếm số lượng chuỗi con phân biệt của $s$.

Chúng ta sẽ giải quyết bài toán này theo cách lặp. Đó là: biết số lượng chuỗi con khác nhau hiện tại, hãy tính toán lại số lượng này sau khi thêm vào cuối $s$ một ký tự.

Vì vậy, cho $k$ là số lượng chuỗi con phân biệt hiện tại của $s$. Chúng ta nối một ký tự mới $c$ vào $s$. Rõ ràng, có thể có một số chuỗi con mới kết thúc bằng ký tự mới $c$ này (cụ thể là tất cả những chuỗi kết thúc bằng ký hiệu này mà chúng ta chưa gặp phải).

Lấy một chuỗi $t = s + c$ và đảo ngược nó (viết các ký tự của nó theo thứ tự ngược lại). Nhiệm vụ của chúng ta bây giờ là đếm xem có bao nhiêu tiền tố của $t$ không được tìm thấy ở bất kỳ đâu khác trong $t$. Hãy tính hàm Z của $t$ và tìm giá trị lớn nhất $z_{max}$ của nó. Rõ ràng, tiền tố có độ dài $z_{max}$ của $t$ cũng xuất hiện ở đâu đó ở giữa $t$. Rõ ràng, các tiền tố ngắn hơn cũng xuất hiện.

Vì vậy, chúng ta đã thấy rằng số lượng chuỗi con mới xuất hiện khi ký hiệu $c$ được nối vào $s$ bằng $\operatorname{length}(t) - z_{max}$.

Do đó, thời gian chạy của giải pháp này là $O(n^2)$ cho một chuỗi có độ dài $n$.

Điều đáng chú ý là chúng ta có thể tính toán lại theo cách chính xác tương tự, vẫn trong thời gian $O(n)$, số lượng chuỗi con phân biệt khi nối thêm một ký tự vào đầu chuỗi, cũng như khi xóa nó (từ cuối hoặc đầu).

### Nén chuỗi

Cho một chuỗi $s$ có độ dài $n$. Tìm biểu diễn "nén" ngắn nhất của nó, tức là: tìm một chuỗi $t$ có độ dài ngắn nhất sao cho $s$ có thể được biểu diễn dưới dạng chuỗi nối của một hoặc nhiều bản sao của $t$.

Giải pháp là: tính hàm Z của $s$, lặp qua tất cả $i$ sao cho $i$ chia hết cho $n$. Dừng lại ở $i$ đầu tiên sao cho $i + z[i] = n$. Sau đó, chuỗi $s$ có thể được nén thành độ dài $i$.

Bằng chứng cho thực tế này giống như giải pháp sử dụng [hàm tiền tố](prefix-function.md).

## Bài tập thực hành

* [eolymp - Blocks of string](https://www.eolymp.com/en/problems/1309)
* [Codeforces - Password [Độ khó: Dễ]](http://codeforces.com/problemset/problem/126/B)
* [UVA # 455 "Periodic Strings" [Độ khó: Trung bình]](http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=396)
* [UVA # 11022 "String Factoring" [Độ khó: Trung bình]](http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1963)
* [UVa 11475 - Extend to Palindrome](http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2470)
* [LA 6439 - Pasti Pas!](https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=588&page=show_problem&problem=4450)
* [Codechef - Chef and Strings](https://www.codechef.com/problems/CHSTR)
* [Codeforces - Prefixes and Suffixes](http://codeforces.com/problemset/problem/432/D)

--- 