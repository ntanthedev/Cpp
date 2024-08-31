# Chia căn (Sqrt Decomposition)

---
tags:
  - Dịch
e_maxx_link: sqrt_decomposition
---

# Chia căn (Sqrt Decomposition)

Chia căn (Sqrt Decomposition) là một phương pháp (hoặc một cấu trúc dữ liệu) cho phép bạn thực hiện một số thao tác phổ biến (tìm tổng các phần tử của mảng con, tìm phần tử nhỏ nhất/lớn nhất, v.v.) trong $O(\sqrt{n})$ thao tác, nhanh hơn nhiều so với $O(n)$ cho thuật toán đơn giản.

Đầu tiên, chúng ta mô tả cấu trúc dữ liệu cho một trong những ứng dụng đơn giản nhất của ý tưởng này, sau đó chỉ ra cách khái quát hóa nó để giải quyết một số bài toán khác và cuối cùng xem xét một cách sử dụng ý tưởng này hơi khác một chút: chia các yêu cầu đầu vào thành các khối căn bậc hai.

## Cấu trúc dữ liệu dựa trên chia căn

Cho một mảng $a[0 \dots n-1]$, hãy triển khai một cấu trúc dữ liệu cho phép tìm tổng các phần tử $a[l \dots r]$ cho $l$ và $r$ tùy ý trong $O(\sqrt{n})$ thao tác.

### Mô tả

Ý tưởng cơ bản của chia căn là tiền xử lý. Chúng ta sẽ chia mảng $a$ thành các khối có độ dài xấp xỉ $\sqrt{n}$, và đối với mỗi khối $i$, chúng ta sẽ tính toán trước tổng các phần tử trong đó $b[i]$.

Chúng ta có thể giả sử rằng cả kích thước khối và số khối đều bằng $\sqrt{n}$ được làm tròn lên:

$$ s = \lceil \sqrt n \rceil $$

Sau đó, mảng $a$ được chia thành các khối theo cách sau:

$$ \underbrace{a[0], a[1], \dots, a[s-1]}_{\text{b[0]}}, \underbrace{a[s], \dots, a[2s-1]}_{\text{b[1]}}, \dots, \underbrace{a[(s-1) \cdot s], \dots, a[n-1]}_{\text{b[s-1]}} $$

Khối cuối cùng có thể có ít phần tử hơn các khối khác (nếu $n$ không phải là bội số của $s$), điều này không quan trọng đối với cuộc thảo luận (vì nó có thể được xử lý dễ dàng).
Do đó, đối với mỗi khối $k$, chúng ta biết tổng các phần tử trên đó $b[k]$:

$$ b[k] = \sum\limits_{i=k\cdot s}^{\min {(n-1,(k+1)\cdot s - 1})} a[i] $$

Vì vậy, chúng ta đã tính toán các giá trị của $b[k]$ (điều này yêu cầu $O(n)$ thao tác). Làm thế nào chúng có thể giúp chúng ta trả lời từng truy vấn $[l, r]$?
Lưu ý rằng nếu khoảng $[l, r]$ đủ dài, nó sẽ chứa một số khối nguyên và đối với những khối đó, chúng ta có thể tìm tổng các phần tử trong chúng trong một thao tác duy nhất. Kết quả là, khoảng $[l, r]$ sẽ chỉ chứa các phần của hai khối và chúng ta sẽ phải tính toán tổng các phần tử trong các phần này một cách tầm thường.

Do đó, để tính tổng các phần tử trên khoảng $[l, r]$, chúng ta chỉ cần cộng các phần tử của hai "đuôi":
$[l\dots (k + 1)\cdot s-1]$ và $[p\cdot s\dots r]$, và cộng các giá trị $b[i]$ trong tất cả các khối từ $k + 1$ đến $p-1$:

$$ \sum\limits_{i=l}^r a[i] = \sum\limits_{i=l}^{(k+1) \cdot s-1} a[i] + \sum\limits_{i=k+1}^{p-1} b[i] + \sum\limits_{i=p\cdot s}^r a[i] $$

_Lưu ý: Khi $k = p$, tức là $l$ và $r$ thuộc cùng một khối, công thức không thể được áp dụng và tổng phải được tính một cách tầm thường._

Cách tiếp cận này cho phép chúng ta giảm đáng kể số lượng thao tác. Thật vậy, kích thước của mỗi "đuôi" không vượt quá độ dài khối $s$ và số khối trong tổng không vượt quá $s$. Vì chúng ta đã chọn $s \approx \sqrt{n}$, nên tổng số thao tác cần thiết để tìm tổng các phần tử trên khoảng $[l, r]$ là $O(\sqrt{n})$.

### Triển khai

Hãy bắt đầu với cách triển khai đơn giản nhất:

```cpp
// dữ liệu đầu vào
int n;
vector<int> a (n);

// tiền xử lý
int len = (int) sqrt (n + .0) + 1; // kích thước của khối và số khối
vector<int> b (len);
for (int i=0; i<n; ++i)
    b[i / len] += a[i];

// trả lời các truy vấn
for (;;) {
    int l, r;
  // đọc dữ liệu đầu vào cho truy vấn tiếp theo
    int sum = 0;
    for (int i=l; i<=r; )
        if (i % len == 0 && i + len - 1 <= r) {
            // nếu toàn bộ khối bắt đầu từ i thuộc về [l, r]
            sum += b[i / len];
            i += len;
        }
        else {
            sum += a[i];
            ++i;
        }
}
```

Cách triển khai này có quá nhiều phép toán chia (chậm hơn nhiều so với các phép toán số học khác). Thay vào đó, chúng ta có thể tính toán các chỉ số của các khối $c_l$ và $c_r$ chứa các chỉ số $l$ và $r$ và lặp qua các khối $c_l+1 \dots c_r-1$ với xử lý riêng biệt các "đuôi" trong các khối $c_l$ và $c_r$. Cách tiếp cận này tương ứng với công thức cuối cùng trong phần mô tả và làm cho trường hợp $c_l = c_r$ trở thành một trường hợp đặc biệt.

```cpp
int sum = 0;
int c_l = l / len,   c_r = r / len;
if (c_l == c_r)
    for (int i=l; i<=r; ++i)
        sum += a[i];
else {
    for (int i=l, end=(c_l+1)*len-1; i<=end; ++i)
        sum += a[i];
    for (int i=c_l+1; i<=c_r-1; ++i)
        sum += b[i];
    for (int i=c_r*len; i<=r; ++i)
        sum += a[i];
}
```

## Các bài toán khác

Cho đến nay, chúng ta đã thảo luận về bài toán tìm tổng các phần tử của một mảng con liên tục. Bài toán này có thể được mở rộng để cho phép **cập nhật các phần tử mảng riêng lẻ**. Nếu một phần tử $a[i]$ thay đổi, thì chỉ cần cập nhật giá trị của $b[k]$ cho khối mà phần tử này thuộc về ($k = i / s$) trong một thao tác:

$$ b[k] += a_{new}[i] - a_{old}[i] $$

Mặt khác, nhiệm vụ tìm tổng các phần tử có thể được thay thế bằng nhiệm vụ tìm phần tử nhỏ nhất/lớn nhất của mảng con. Nếu bài toán này cũng phải giải quyết các cập nhật của các phần tử riêng lẻ, thì việc cập nhật giá trị của $b[k]$ cũng có thể thực hiện được, nhưng nó sẽ yêu cầu lặp lại tất cả các giá trị của khối $k$ trong $O(s) = O(\sqrt{n})$ thao tác.

Chia căn có thể được áp dụng theo cách tương tự cho cả một lớp các bài toán khác: tìm số lượng phần tử bằng không, tìm phần tử khác không đầu tiên, đếm các phần tử thỏa mãn một thuộc tính nhất định, v.v.

Một lớp bài toán khác xuất hiện khi chúng ta cần **cập nhật các phần tử mảng trên các khoảng**: tăng các phần tử hiện có hoặc thay thế chúng bằng một giá trị nhất định.

Ví dụ: giả sử chúng ta có thể thực hiện hai loại thao tác trên một mảng: thêm một giá trị nhất định $\delta$ vào tất cả các phần tử mảng trên khoảng $[l, r]$ hoặc truy vấn giá trị của phần tử $a[i]$. Hãy lưu trữ giá trị phải được thêm vào tất cả các phần tử của khối $k$ trong $b[k]$ (ban đầu tất cả $b[k] = 0$). Trong mỗi thao tác "thêm", chúng ta cần thêm $\delta$ vào $b[k]$ cho tất cả các khối thuộc khoảng $[l, r]$ và thêm $\delta$ vào $a[i]$ cho tất cả các phần tử thuộc "đuôi" của khoảng. Câu trả lời cho truy vấn $i$ chỉ đơn giản là $a[i] + b[i/s]$. Bằng cách này, thao tác "thêm" có độ phức tạp $O(\sqrt{n})$ và việc trả lời truy vấn có độ phức tạp $O(1)$.

Cuối cùng, hai lớp bài toán đó có thể được kết hợp nếu nhiệm vụ yêu cầu thực hiện **cả** cập nhật phần tử trên một khoảng và truy vấn trên một khoảng. Cả hai thao tác đều có thể được thực hiện với độ phức tạp $O(\sqrt{n})$. Điều này sẽ yêu cầu hai mảng khối $b$ và $c$: một để theo dõi các cập nhật phần tử và một để theo dõi câu trả lời cho truy vấn.

Có những bài toán khác có thể được giải quyết bằng cách sử dụng chia căn, ví dụ, một bài toán về việc duy trì một tập hợp các số cho phép thêm/xóa số, kiểm tra xem một số có thuộc tập hợp hay không và tìm số lớn thứ $k$. Để giải quyết nó, người ta phải lưu trữ các số theo thứ tự tăng dần, chia thành một số khối với $\sqrt{n}$ số trong mỗi khối. Mỗi khi một số được thêm/xóa, các khối phải được cân bằng lại bằng cách di chuyển các số giữa đầu và cuối của các khối liền kề.

## Thuật toán Mo

Một ý tưởng tương tự, dựa trên chia căn, có thể được sử dụng để trả lời các truy vấn phạm vi ($Q$) ngoại tuyến (offline) trong $O((N+Q)\sqrt{N})$.
Điều này nghe có vẻ tệ hơn nhiều so với các phương pháp trong phần trước, vì đây là độ phức tạp hơi kém hơn so với trước đây và không thể cập nhật giá trị giữa hai truy vấn.
Nhưng trong rất nhiều trường hợp, phương pháp này có những ưu điểm.
Trong chia căn thông thường, chúng ta phải tính toán trước các câu trả lời cho mỗi khối và hợp nhất chúng trong khi trả lời các truy vấn.
Trong một số bài toán, bước hợp nhất này có thể khá khó khăn.
Ví dụ: khi mỗi truy vấn yêu cầu tìm **yếu vị** (mode) của phạm vi của nó (số xuất hiện thường xuyên nhất).
Đối với điều này, mỗi khối sẽ phải lưu trữ số lượng của mỗi số trong đó trong một số loại cấu trúc dữ liệu và chúng ta không còn có thể thực hiện bước hợp nhất đủ nhanh nữa.
**Thuật toán Mo** sử dụng một cách tiếp cận hoàn toàn khác, có thể trả lời các loại truy vấn này một cách nhanh chóng, bởi vì nó chỉ theo dõi một cấu trúc dữ liệu và các thao tác duy nhất với nó rất dễ dàng và nhanh chóng.

Ý tưởng là trả lời các truy vấn theo một thứ tự đặc biệt dựa trên các chỉ số.
Đầu tiên, chúng ta sẽ trả lời tất cả các truy vấn có chỉ số bên trái trong khối 0, sau đó trả lời tất cả các truy vấn có chỉ số bên trái trong khối 1, v.v.
Và chúng ta cũng sẽ phải trả lời các truy vấn của một khối theo một thứ tự đặc biệt, cụ thể là được sắp xếp theo chỉ số bên phải của các truy vấn.

Như đã nói, chúng ta sẽ sử dụng một cấu trúc dữ liệu duy nhất.
Cấu trúc dữ liệu này sẽ lưu trữ thông tin về phạm vi.
Ban đầu phạm vi này sẽ trống.
Khi chúng ta muốn trả lời truy vấn tiếp theo (theo thứ tự đặc biệt), chúng ta chỉ cần mở rộng hoặc thu hẹp phạm vi, bằng cách thêm/xóa các phần tử ở cả hai phía của phạm vi hiện tại, cho đến khi chúng ta biến đổi nó thành phạm vi truy vấn.
Bằng cách này, chúng ta chỉ cần thêm hoặc xóa một phần tử duy nhất mỗi lần, đây là những thao tác khá dễ dàng trong cấu trúc dữ liệu của chúng ta.

Vì chúng ta thay đổi thứ tự trả lời các truy vấn, điều này chỉ có thể thực hiện được khi chúng ta được phép trả lời các truy vấn ở chế độ ngoại tuyến.

### Triển khai

Trong thuật toán Mo, chúng ta sử dụng hai hàm để thêm chỉ mục và xóa chỉ mục khỏi phạm vi mà chúng ta hiện đang duy trì.

```cpp
void remove(idx);  // TODO: xóa giá trị tại idx khỏi cấu trúc dữ liệu
void add(idx);     // TODO: thêm giá trị tại idx khỏi cấu trúc dữ liệu
int get_answer();  // TODO: trích xuất câu trả lời hiện tại của cấu trúc dữ liệu

int block_size;

struct Query {
    int l, r, idx;
    bool operator<(Query other) const
    {
        return make_pair(l / block_size, r) <
               make_pair(other.l / block_size, other.r);
    }
};

vector<int> mo_s_algorithm(vector<Query> queries) {
    vector<int> answers(queries.size());
    sort(queries.begin(), queries.end());

    // TODO: khởi tạo cấu trúc dữ liệu

    int cur_l = 0;
    int cur_r = -1;
    // bất biến: cấu trúc dữ liệu sẽ luôn phản ánh phạm vi [cur_l, cur_r]
    for (Query q : queries) {
        while (cur_l > q.l) {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < q.r) {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < q.l) {
            remove(cur_l);
            cur_l++;
        }
        while (cur_r > q.r) {
            remove(cur_r);
            cur_r--;
        }
        answers[q.idx] = get_answer();
    }
    return answers;
}
```

Dựa trên bài toán, chúng ta có thể sử dụng một cấu trúc dữ liệu khác nhau và sửa đổi các hàm `add`/`remove`/`get_answer` cho phù hợp.
Ví dụ: nếu chúng ta được yêu cầu tìm các truy vấn tổng phạm vi, thì chúng ta sử dụng một số nguyên đơn giản làm cấu trúc dữ liệu, là $0$ lúc đầu.
Hàm `add` sẽ chỉ đơn giản là thêm giá trị của vị trí và sau đó cập nhật biến câu trả lời.
Mặt khác, hàm `remove` sẽ trừ giá trị tại vị trí và sau đó cập nhật biến câu trả lời.
Và `get_answer` chỉ trả về số nguyên.

Để trả lời các truy vấn yếu vị, chúng ta có thể sử dụng cây tìm kiếm nhị phân (ví dụ: `map<int, int>`) để lưu trữ tần suất xuất hiện của mỗi số trong phạm vi hiện tại và cây tìm kiếm nhị phân thứ hai (ví dụ: `set<pair<int, int>>`) để giữ số lượng của các số (ví dụ: dưới dạng cặp số lượng-số) theo thứ tự.
Phương thức `add` xóa số hiện tại khỏi BST thứ hai, tăng số lượng trong BST thứ nhất và chèn số trở lại BST thứ hai.
`remove` làm điều tương tự, nó chỉ giảm số lượng.
Và `get_answer` chỉ nhìn vào cây thứ hai và trả về giá trị tốt nhất trong $O(1)$.

### Độ phức tạp

Việc sắp xếp tất cả các truy vấn sẽ mất $O(Q \log Q)$.

Còn các hoạt động khác thì sao?
Hàm `add` và `remove` sẽ được gọi bao nhiêu lần?

Giả sử kích thước khối là $S$.

Nếu chúng ta chỉ xem xét tất cả các truy vấn có chỉ số bên trái trong cùng một khối, thì các truy vấn được sắp xếp theo chỉ số bên phải.
Do đó, chúng ta sẽ chỉ gọi `add(cur_r)` và `remove(cur_r)` $O(N)$ lần cho tất cả các truy vấn này được kết hợp.
Điều này cho $O(\frac{N}{S} N)$ lệnh gọi cho tất cả các khối.

Giá trị của `cur_l` có thể thay đổi nhiều nhất $O(S)$ giữa hai truy vấn.
Do đó, chúng ta có thêm $O(S Q)$ lệnh gọi `add(cur_l)` và `remove(cur_l)`.

Đối với $S \approx \sqrt{N}$, điều này cho tổng cộng $O((N + Q) \sqrt{N})$ thao tác.
Do đó, độ phức tạp là $O((N+Q)F\sqrt{N})$ trong đó $O(F)$ là độ phức tạp của hàm `add` và `remove`.

### Mẹo để cải thiện thời gian chạy

* Kích thước khối chính xác là $\sqrt{N}$ không phải lúc nào cũng mang lại thời gian chạy tốt nhất. Ví dụ: nếu $\sqrt{N}=750$ thì có thể xảy ra trường hợp kích thước khối là $700$ hoặc $800$ có thể chạy tốt hơn.
Quan trọng hơn, đừng tính kích thước khối khi chạy - hãy làm cho nó `const`. Phép chia cho hằng số được tối ưu hóa tốt bởi trình biên dịch.
* Trong các khối lẻ, hãy sắp xếp chỉ số bên phải theo thứ tự tăng dần và trong các khối chẵn, hãy sắp xếp nó theo thứ tự giảm dần. Điều này sẽ giảm thiểu sự di chuyển của con trỏ bên phải, vì sắp xếp thông thường sẽ di chuyển con trỏ bên phải từ cuối trở lại đầu ở đầu mỗi khối. Với phiên bản cải tiến, việc đặt lại này không còn cần thiết nữa.

```cpp
bool cmp(pair<int, int> p, pair<int, int> q) {
    if (p.first / BLOCK_SIZE != q.first / BLOCK_SIZE)
        return p < q;
    return (p.first / BLOCK_SIZE & 1) ? (p.second < q.second) : (p.second > q.second);
}
```

Bạn có thể đọc về cách tiếp cận sắp xếp thậm chí nhanh hơn [tại đây](https://codeforces.com/blog/entry/61203).

## Bài tập thực hành

* [Codeforces - Kuriyama Mirai's Stones](https://codeforces.com/problemset/problem/433/B)
* [UVA - 12003 - Array Transformer](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3154)
* [UVA - 11990 Dynamic Inversion](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3141)
* [SPOJ - Give Away](http://www.spoj.com/problems/GIVEAWAY/)
* [Codeforces - Till I Collapse](http://codeforces.com/contest/786/problem/C)
* [Codeforces - Destiny](http://codeforces.com/contest/840/problem/D)
* [Codeforces - Holes](http://codeforces.com/contest/13/problem/E)
* [Codeforces - XOR and Favorite Number](https://codeforces.com/problemset/problem/617/E)
* [Codeforces - Powerful array](http://codeforces.com/problemset/problem/86/D)
* [SPOJ - DQUERY](https://www.spoj.com/problems/DQUERY)


---


