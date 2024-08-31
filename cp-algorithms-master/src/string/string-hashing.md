# Băm chuỗi (String Hashing)

---
tags:
  - Dịch
e_maxx_link: string_hashes
---

# Băm chuỗi (String Hashing)

Các thuật toán băm rất hữu ích trong việc giải quyết rất nhiều bài toán.

Chúng ta muốn giải quyết bài toán so sánh các chuỗi một cách hiệu quả.
Cách đơn giản để làm như vậy là chỉ cần so sánh các chữ cái của cả hai chuỗi, điều này có độ phức tạp thời gian là $O(\min(n_1, n_2))$ nếu $n_1$ và $n_2$ là kích thước của hai chuỗi.
Chúng ta muốn làm tốt hơn.
Ý tưởng đằng sau việc băm chuỗi như sau: chúng ta ánh xạ mỗi chuỗi thành một số nguyên và so sánh chúng thay vì chuỗi.
Làm như vậy cho phép chúng ta giảm thời gian thực hiện của phép so sánh chuỗi xuống còn $O(1)$.

Đối với việc chuyển đổi, chúng ta cần một cái gọi là **hàm băm**.
Mục tiêu của nó là chuyển đổi một chuỗi thành một số nguyên, cái gọi là **giá trị băm** của chuỗi.
Điều kiện sau phải được giữ: nếu hai chuỗi $s$ và $t$ bằng nhau ($s = t$), thì giá trị băm của chúng cũng phải bằng nhau ($\text{hash}(s) = \text{hash}(t)$).
Nếu không, chúng ta sẽ không thể so sánh các chuỗi.

Lưu ý, hướng ngược lại không cần phải giữ.
Nếu các giá trị băm bằng nhau ($\text{hash}(s) = \text{hash}(t)$), thì các chuỗi không nhất thiết phải bằng nhau.
Ví dụ: một hàm băm hợp lệ sẽ chỉ đơn giản là $\text{hash}(s) = 0$ cho mỗi $s$.
Bây giờ, đây chỉ là một ví dụ ngớ ngẩn, bởi vì hàm này sẽ hoàn toàn vô dụng, nhưng nó là một hàm băm hợp lệ.
Lý do tại sao hướng ngược lại không cần phải giữ là vì có rất nhiều chuỗi theo cấp số nhân.
Nếu chúng ta chỉ muốn hàm băm này phân biệt giữa tất cả các chuỗi bao gồm các ký tự thường có độ dài nhỏ hơn 15, thì giá trị băm sẽ không còn phù hợp với số nguyên 64 bit (ví dụ: unsigned long long) nữa, bởi vì có rất nhiều chuỗi.
Và tất nhiên, chúng ta không muốn so sánh các số nguyên dài tùy ý, bởi vì điều này cũng sẽ có độ phức tạp $O(n)$.

Vì vậy, thông thường chúng ta muốn hàm băm ánh xạ các chuỗi lên các số trong một phạm vi cố định $[0, m)$, sau đó việc so sánh các chuỗi chỉ là so sánh hai số nguyên có độ dài cố định.
Và tất nhiên, chúng ta muốn $\text{hash}(s) \neq \text{hash}(t)$ rất có thể xảy ra nếu $s \neq t$.

Đó là phần quan trọng mà bạn phải ghi nhớ.
Sử dụng băm sẽ không chính xác 100% một cách xác định, bởi vì hai chuỗi hoàn toàn khác nhau có thể có cùng giá trị băm (giá trị băm va chạm).
Tuy nhiên, trong phần lớn các nhiệm vụ, điều này có thể được bỏ qua một cách an toàn vì xác suất va chạm giá trị băm của hai chuỗi khác nhau vẫn còn rất nhỏ.
Và chúng ta sẽ thảo luận về một số kỹ thuật trong bài viết này để giữ xác suất va chạm ở mức rất thấp.

## Tính toán giá trị băm của một chuỗi

Cách tốt và được sử dụng rộng rãi để định nghĩa giá trị băm của một chuỗi $s$ có độ dài $n$ là

$$\begin{align}
\text{hash}(s) &= s[0] + s[1] \cdot p + s[2] \cdot p^2 + ... + s[n-1] \cdot p^{n-1} \mod m \\
&= \sum_{i=0}^{n-1} s[i] \cdot p^i \mod m,
\end{align}$$

trong đó $p$ và $m$ là một số số dương được chọn.
Nó được gọi là **hàm băm đa thức lăn (polynomial rolling hash function)**.

Việc làm cho $p$ là một số nguyên tố gần bằng số lượng ký tự trong bảng chữ cái đầu vào là hợp lý.
Ví dụ: nếu đầu vào chỉ bao gồm các chữ cái thường của bảng chữ cái tiếng Anh, thì $p = 31$ là một lựa chọn tốt.
Nếu đầu vào có thể chứa cả chữ cái in hoa và chữ cái thường, thì $p = 53$ là một lựa chọn khả thi.
Mã trong bài viết này sẽ sử dụng $p = 31$.

Rõ ràng $m$ phải là một số lớn vì xác suất hai chuỗi ngẫu nhiên va chạm là khoảng $\approx \frac{1}{m}$.
Đôi khi $m = 2^{64}$ được chọn, vì khi đó tràn số nguyên của số nguyên 64 bit hoạt động giống hệt như phép toán modulo.
Tuy nhiên, tồn tại một phương pháp tạo ra các chuỗi va chạm (hoạt động độc lập với sự lựa chọn của $p$).
Vì vậy, trong thực tế, $m = 2^{64}$ không được khuyến khích.
Một lựa chọn tốt cho $m$ là một số nguyên tố lớn.
Mã trong bài viết này sẽ chỉ sử dụng $m = 10^9+9$.
Đây là một số lớn, nhưng vẫn đủ nhỏ để chúng ta có thể thực hiện phép nhân hai giá trị bằng cách sử dụng số nguyên 64 bit.

Đây là một ví dụ về cách tính giá trị băm của một chuỗi $s$, chỉ chứa các chữ cái thường.
Chúng ta chuyển đổi từng ký tự của $s$ thành một số nguyên.
Ở đây chúng ta sử dụng phép chuyển đổi $a \rightarrow 1$, $b \rightarrow 2$, $\dots$, $z \rightarrow 26$.
Việc chuyển đổi $a \rightarrow 0$ không phải là một ý tưởng hay, bởi vì khi đó giá trị băm của các chuỗi $a$, $aa$, $aaa$, $\dots$ đều được đánh giá là $0$.

```{.cpp file=hashing_function}
long long compute_hash(string const& s) {
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}
```

Việc tính toán trước các lũy thừa của $p$ có thể giúp tăng hiệu suất.

## Ví dụ nhiệm vụ

### Tìm kiếm các chuỗi trùng lặp trong một mảng các chuỗi

Bài toán: Cho một danh sách $n$ chuỗi $s_i$, mỗi chuỗi không dài quá $m$ ký tự, hãy tìm tất cả các chuỗi trùng lặp và chia chúng thành các nhóm.

Từ thuật toán rõ ràng liên quan đến việc sắp xếp các chuỗi, chúng ta sẽ nhận được độ phức tạp thời gian là $O(n m \log n)$ trong đó việc sắp xếp yêu cầu $O(n \log n)$ so sánh và mỗi so sánh mất thời gian $O(m)$.
Tuy nhiên, bằng cách sử dụng giá trị băm, chúng ta giảm thời gian so sánh xuống còn $O(1)$, cho chúng ta một thuật toán chạy trong thời gian $O(n m + n \log n)$.

Chúng ta tính toán giá trị băm cho mỗi chuỗi, sắp xếp các giá trị băm cùng với các chỉ số, sau đó nhóm các chỉ số theo giá trị băm giống hệt nhau.

```{.cpp file=hashing_group_identical_strings}
vector<vector<int>> group_identical_strings(vector<string> const& s) {
    int n = s.size();
    vector<pair<long long, int>> hashes(n);
    for (int i = 0; i < n; i++)
        hashes[i] = {compute_hash(s[i]), i};

    sort(hashes.begin(), hashes.end());

    vector<vector<int>> groups;
    for (int i = 0; i < n; i++) {
        if (i == 0 || hashes[i].first != hashes[i-1].first)
            groups.emplace_back();
        groups.back().push_back(hashes[i].second);
    }
    return groups;
}
```

### Tính toán giá trị băm nhanh của các chuỗi con của chuỗi nhất định

Bài toán: Cho một chuỗi $s$ và các chỉ số $i$ và $j$, hãy tìm giá trị băm của chuỗi con $s [i \dots j]$.

Theo định nghĩa, chúng ta có:

$$\text{hash}(s[i \dots j]) = \sum_{k = i}^j s[k] \cdot p^{k-i} \mod m$$

Nhân với $p^i$ cho:

$$\begin{align}
\text{hash}(s[i \dots j]) \cdot p^i &= \sum_{k = i}^j s[k] \cdot p^k \mod m \\
&= \text{hash}(s[0 \dots j]) - \text{hash}(s[0 \dots i-1]) \mod m
\end{align}$$

Vì vậy, bằng cách biết giá trị băm của mỗi tiền tố của chuỗi $s$, chúng ta có thể tính toán giá trị băm của bất kỳ chuỗi con nào trực tiếp bằng cách sử dụng công thức này.
Vấn đề duy nhất mà chúng ta gặp phải trong việc tính toán nó là chúng ta phải có thể chia $\text{hash}(s[0 \dots j]) - \text{hash}(s[0 \dots i-1])$ cho $p^i$.
Do đó, chúng ta cần tìm [nghịch đảo nhân modulo](../algebra/module-inverse.md) của $p^i$ và sau đó thực hiện phép nhân với nghịch đảo này.
Chúng ta có thể tính toán trước nghịch đảo của mọi $p^i$, cho phép tính toán giá trị băm của bất kỳ chuỗi con nào của $s$ trong thời gian $O(1)$.

Tuy nhiên, có tồn tại một cách dễ dàng hơn.
Trong hầu hết các trường hợp, thay vì tính toán chính xác giá trị băm của chuỗi con, nó đủ để tính toán giá trị băm nhân với một số lũy thừa của $p$.
Giả sử chúng ta có hai giá trị băm của hai chuỗi con, một giá trị băm được nhân với $p^i$ và giá trị băm còn lại được nhân với $p^j$.
Nếu $i < j$ thì chúng ta nhân giá trị băm đầu tiên với $p^{j-i}$, nếu không, chúng ta nhân giá trị băm thứ hai với $p^{i-j}$.
Bằng cách làm như vậy, chúng ta nhận được cả hai giá trị băm được nhân với cùng một lũy thừa của $p$ (là giá trị lớn nhất của $i$ và $j$) và bây giờ các giá trị băm này có thể được so sánh dễ dàng mà không cần bất kỳ phép chia nào.

## Ứng dụng của băm

Dưới đây là một số ứng dụng điển hình của băm:

* [Thuật toán Rabin-Karp](rabin-karp.md) để so khớp mẫu trong chuỗi trong thời gian $O(n)$
* Tính toán số lượng chuỗi con khác nhau của một chuỗi trong $O(n^2)$ (xem bên dưới)
* Tính toán số lượng chuỗi con đối xứng trong một chuỗi.

### Xác định số lượng chuỗi con khác nhau trong một chuỗi

Bài toán: Cho một chuỗi $s$ có độ dài $n$, chỉ bao gồm các chữ cái tiếng Anh thường, hãy tìm số lượng chuỗi con khác nhau trong chuỗi này.

Để giải quyết bài toán này, chúng ta lặp qua tất cả các độ dài chuỗi con $l = 1 \dots n$.
Đối với mọi độ dài chuỗi con $l$, chúng ta xây dựng một mảng các giá trị băm của tất cả các chuỗi con có độ dài $l$ được nhân với cùng một lũy thừa của $p$.
Số lượng phần tử khác nhau trong mảng bằng với số lượng chuỗi con phân biệt có độ dài $l$ trong chuỗi.
Số này được cộng vào câu trả lời cuối cùng.

Để thuận tiện, chúng ta sẽ sử dụng $h[i]$ làm giá trị băm của tiền tố có $i$ ký tự và định nghĩa $h[0] = 0$.

```{.cpp file=hashing_count_unique_substrings}
int count_unique_substrings(string const& s) {
    int n = s.size();
    
    const int p = 31;
    const int m = 1e9 + 9;
    vector<long long> p_pow(n);
    p_pow[0] = 1;
    for (int i = 1; i < n; i++)
        p_pow[i] = (p_pow[i-1] * p) % m;

    vector<long long> h(n + 1, 0);
    for (int i = 0; i < n; i++)
        h[i+1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;

    int cnt = 0;
    for (int l = 1; l <= n; l++) {
        unordered_set<long long> hs;
        for (int i = 0; i <= n - l; i++) {
            long long cur_h = (h[i + l] + m - h[i]) % m;
            cur_h = (cur_h * p_pow[n-i-1]) % m;
            hs.insert(cur_h);
        }
        cnt += hs.size();
    }
    return cnt;
}
```

Lưu ý rằng $O(n^2)$ không phải là độ phức tạp thời gian tốt nhất có thể cho bài toán này.
Một giải pháp với $O(n \log n)$ được mô tả trong bài viết về [Mảng hậu tố](suffix-array.md) và thậm chí có thể tính toán nó trong $O(n)$ bằng cách sử dụng [Cây hậu tố](./suffix-tree-ukkonen.md) hoặc [Tự động hóa hậu tố](./suffix-automaton.md).

## Cải thiện xác suất không va chạm

Khá thường xuyên, hàm băm đa thức được đề cập ở trên là đủ tốt và sẽ không xảy ra va chạm trong quá trình kiểm tra.
Hãy nhớ rằng, xác suất xảy ra va chạm chỉ là $\approx \frac{1}{m}$.
Đối với $m = 10^9 + 9$ xác suất là $\approx 10^{-9}$ khá thấp.
Nhưng lưu ý, chúng ta chỉ thực hiện một so sánh.
Điều gì sẽ xảy ra nếu chúng ta so sánh một chuỗi $s$ với $10^6$ chuỗi khác nhau.
Xác suất xảy ra ít nhất một va chạm bây giờ là $\approx 10^{-3}$.
Và nếu chúng ta muốn so sánh $10^6$ chuỗi khác nhau với nhau (ví dụ: bằng cách đếm có bao nhiêu chuỗi duy nhất tồn tại), thì xác suất xảy ra ít nhất một va chạm đã là $\approx 1$.
Khá chắc chắn rằng nhiệm vụ này sẽ kết thúc bằng một vụ va chạm và trả về kết quả sai.

Có một mẹo thực sự dễ dàng để có được xác suất tốt hơn.
Chúng ta có thể chỉ cần tính toán hai giá trị băm khác nhau cho mỗi chuỗi (bằng cách sử dụng hai $p$ khác nhau và/hoặc $m$ khác nhau và so sánh các cặp này thay thế.
Nếu $m$ là khoảng $10^9$ cho mỗi hàm băm thì điều này ít nhiều tương đương với việc có một hàm băm với $m \approx 10^{18}$.
Khi so sánh $10^6$ chuỗi với nhau, xác suất xảy ra ít nhất một va chạm bây giờ giảm xuống còn $\approx 10^{-6}$.

## Bài tập thực hành
* [Good Substrings - Codeforces](https://codeforces.com/contest/271/problem/D)
* [A Needle in the Haystack - SPOJ](http://www.spoj.com/problems/NHAY/)
* [String Hashing - Kattis](https://open.kattis.com/problems/hashing)
* [Double Profiles - Codeforces](http://codeforces.com/problemset/problem/154/C)
* [Password - Codeforces](http://codeforces.com/problemset/problem/126/B)
* [SUB_PROB - SPOJ](http://www.spoj.com/problems/SUB_PROB/)
* [INSQ15_A](https://www.codechef.com/problems/INSQ15_A)
* [SPOJ - Ada and Spring Cleaning](http://www.spoj.com/problems/ADACLEAN/)
* [GYM - Text Editor](http://codeforces.com/gym/101466/problem/E)
* [12012 - Detection of Extraterrestrial](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3163)
* [Codeforces - Games on a CD](http://codeforces.com/contest/727/problem/E)
* [UVA 11855 - Buzzwords](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2955)
* [Codeforces - Santa Claus and a Palindrome](http://codeforces.com/contest/752/problem/D)
* [Codeforces - String Compression](http://codeforces.com/contest/825/problem/F)
* [Codeforces - Palindromic Characteristics](http://codeforces.com/contest/835/problem/D)
* [SPOJ - Test](http://www.spoj.com/problems/CF25E/)
* [Codeforces - Palindrome Degree](http://codeforces.com/contest/7/problem/D)
* [Codeforces - Deletion of Repeats](http://codeforces.com/contest/19/problem/C)
* [HackerRank - Gift Boxes](https://www.hackerrank.com/contests/womens-codesprint-5/challenges/gift-boxes)



---