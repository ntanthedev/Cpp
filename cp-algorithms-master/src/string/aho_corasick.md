---
tags:
  - Đã dịch
e_maxx_link: aho_corasick
---

# Thuật toán Aho-Corasick

Thuật toán Aho-Corasick cho phép chúng ta tìm kiếm nhanh chóng nhiều mẫu trong một văn bản. Bộ chuỗi mẫu cũng được gọi là một _từ điển_. Chúng ta sẽ ký hiệu tổng độ dài của các chuỗi thành phần bằng $m$ và kích thước của bảng chữ cái bằng $k$. Thuật toán xây dựng một tự động hóa trạng thái hữu hạn dựa trên một trie trong thời gian $O(m k)$ và sau đó sử dụng nó để xử lý văn bản.

Thuật toán được đề xuất bởi Alfred Aho và Margaret Corasick vào năm 1975.

## Xây dựng của trie

<center>
<img src="https://upload.wikimedia.org/wikipedia/commons/e/e2/Trie.svg" width="400px">
<br>
<i>Một trie dựa trên các từ "Java", "Rad", "Rand", "Rau", "Raum" và "Rose".</i>
<br>
<i>Hình ảnh bởi [nd](https://de.wikipedia.org/wiki/Benutzer:Nd) được phân phối dưới giấy phép <a href="https://creativecommons.org/licenses/by-sa/3.0/deed.en">CC BY-SA 3.0</a>.</i>
</center>

Theo cách chính thức, một trie là một cây có gốc, trong đó mỗi cạnh của cây được gắn nhãn bằng một chữ cái nào đó và các cạnh đi ra từ một đỉnh có nhãn khác nhau.

Chúng ta sẽ xác định mỗi đỉnh trong trie với chuỗi được tạo thành từ các nhãn trên đường đi từ gốc đến đỉnh đó.

Mỗi đỉnh cũng sẽ có một cờ $\text{output}$ sẽ được thiết lập nếu đỉnh đó tương ứng với một mẫu trong từ điển.

Tương ứng, một trie cho một tập hợp các chuỗi là một trie sao cho mỗi đỉnh $\text{output}$ tương ứng với một chuỗi từ tập hợp đó, và ngược lại, mỗi chuỗi của tập hợp tương ứng với một đỉnh $\text{output}$.

Bây giờ chúng ta sẽ mô tả cách xây dựng một trie cho một tập hợp đã cho các chuỗi trong thời gian tuyến tính so với tổng độ dài của chúng.

Chúng ta giới thiệu một cấu trúc cho các đỉnh của cây:
```cpp
const int K = 26;

struct Vertex {
    int next[K];
    bool output = false;

    Vertex() {
        fill(begin(next), end(next), -1);
    }
};

vector<Vertex> trie(1);
```
Dưới đây, chúng ta lưu trie dưới dạng một mảng của $\text{Vertex}$. Mỗi $\text{Vertex}$ chứa cờ $\text{output}$ và các cạnh dưới dạng một mảng $\text{next}[]$, trong đó $\text{next}[i]$ là chỉ số của đỉnh mà chúng ta đến bằng cách đi theo ký tự $i$, hoặc $-1$ nếu không có cạnh tương ứng. Ban đầu, trie chỉ bao gồm một đỉnh duy nhất - gốc - có chỉ số $0$.

Bây giờ chúng ta triển khai một hàm để thêm một chuỗi $s$ vào trie. Triển khai là đơn giản: chúng ta bắt đầu tại nút gốc, và trong khi có cạnh tương ứng với các ký tự của $s$ chúng ta đi theo chúng. Nếu không có cạnh cho một ký tự, chúng ta tạo một đỉnh mới và kết nối nó với một cạnh. Cuối cùng của quá trình, chúng ta đánh dấu đỉnh cuối cùng với cờ $\text{output}$.

```cpp
void add_string(string const& s) {
    int v = 0;
    for (char ch : s) {
        int c = ch - 'a';
        if (trie[v].next[c] == -1) {
            trie[v].next[c] = trie.size();
            trie.emplace_back();
        }
        v = trie[v].next[c];
    }
    trie[v].output = true;
}
```
Triển khai này rõ ràng chạy trong thời gian tuyến tính, và vì mỗi đỉnh lưu trữ $k$ liên kết, nó sẽ sử dụng bộ nhớ $O(m k)$.

Có thể giảm tiêu thụ bộ nhớ xuống $O(m)$ bằng cách sử dụng một bản đồ thay vì một mảng trong mỗi đỉnh. Tuy nhiên, điều này sẽ làm tăng độ phức tạp thời gian lên $O(m \log k)$.

## Xây dựng một tự động hóa

Giả sử chúng ta đã xây dựng một trie cho tập hợp chuỗi đã cho. Bây giờ hãy xem xét nó từ một góc độ khác. Nếu chúng ta nhìn vào bất kỳ đỉnh nào, chuỗi tương ứng với nó là một tiền tố của một hoặc nhiều chuỗi trong tập hợp, do đó mỗi đỉnh của trie có thể được hiểu là một vị trí trong một hoặc nhiều chuỗi từ tập hợp.

Trong thực tế, các đỉnh của trie có thể được hiểu là các trạng thái trong một tự động hóa hữu hạn xác định. Từ bất kỳ trạng thái nào, chúng ta có thể chuyển tiếp - sử dụng một chữ cái đầu vào - đến các trạng thái khác, tức là đến một vị trí khác trong tập hợp các chuỗi. Ví dụ, nếu chỉ có một chuỗi $abc$ trong từ điển, và chúng ta đang đứng tại đỉnh $ab$, thì sử dụng chữ cái $c$ chúng ta có thể đi đến đỉnh $abc$.

Do đó, chúng ta có thể hiểu các cạnh của trie như các chuyển tiếp trong một tự động hóa theo chữ cái tương ứng. Tuy nhiên, trong một tự động hóa, chúng ta cần có các chuyển tiếp cho mọi kết hợp của một trạng thái và một chữ cái. Nếu chúng ta cố gắng thực hiện một chuyển tiếp bằng cách sử dụng một chữ cái, và không có cạnh tương ứng trong trie, thì ta vẫn phải đi vào một trạng thái nào đó.

Cụ thể hơn, giả sử chúng ta đang ở một trạng thái tương ứng với một chuỗi $t$, và chúng ta muốn chuyển tiếp đến một trạng thái khác bằng cách sử dụng ký tự $c$. Nếu có một cạnh được gán nhãn bằng ký tự này $c$, thì chúng ta có thể đi qua cạnh này một cách đơn giản và nhận được đỉnh tương ứng với $t + c$. Nếu không có cạnh như vậy, vì chúng ta muốn duy trì điều kiện rằng trạng thái hiện tại là kết quả phụ dài nhất trong chuỗi đã được xử lý, chúng ta phải tìm chuỗi dài nhất trong trie mà là tiền tố hợp lệ của chuỗi $t$, và cố gắng thực hiện một chuyển tiếp từ đó.

Ví dụ, hãy giả sử trie được xây dựng bởi các chuỗi $ab$ và $bc$, và chúng ta hiện đang ở đỉnh tương ứng với $ab$, cũng là một đỉnh $\text{output}$. Để chuyển tiếp với chữ cái $c$, chúng ta buộc phải đi đến trạng thái tương ứng với chuỗi $b$, và từ đó tiếp tục theo cạnh với chữ cái $c$.

<center>
<img src="https://upload.wikimedia.org/wikipedia/commons/9/90/A_diagram_of_the_Aho-Corasick_string_search_algorithm.svg" width="300px">
<br>
<i>Một tự động hóa Aho-Corasick dựa trên các từ "a", "ab", "bc", "bca", "c" và "caa".</i>
<br>
<i>Các mũi tên màu xanh lá cây là các liên kết tiền tố, các mũi tên màu xanh lá cây là các liên kết terminal.</i>
</center>
Một liên kết tiền tố cho một đỉnh $p$ là một cạnh trỏ vào tiền tố hợp lệ dài nhất của chuỗi tương ứng với đỉnh $p$. Trường hợp đặc biệt duy nhất là gốc của trie, mà liên kết tiền tố sẽ trỏ vào chính nó. Bây giờ chúng ta có thể phát biểu lại về các chuyển tiếp trong tự động hóa như sau: trong khi không có chuyển tiếp từ đỉnh hiện tại của trie bằng cách sử dụng chữ cái hiện tại (hoặc cho đến khi chúng ta đạt được gốc), chúng ta đi theo liên kết tiền tố.

Do đó, chúng ta đã giảm bài toán xây dựng một tự động hóa thành bài toán tìm liên kết tiền tố cho tất cả các đỉnh của trie. Tuy nhiên, chúng ta sẽ xây dựng các liên kết tiền tố này, kỳ lạ thay, bằng cách sử dụng các chuyển tiếp được xây dựng trong tự động hóa.

Các liên kết tiền tố của đỉnh gốc và tất cả các con trực tiếp của nó trỏ vào đỉnh gốc. Đối với bất kỳ đỉnh $v$ nào sâu hơn trong cây, chúng ta có thể tính toán liên kết tiền tố như sau: nếu $p$ là tổ tiên của $v$ với $c$ là ký tự gán nhãn cho cạnh từ $p$ đến $v$, đi đến $p$, sau đó theo liên kết tiền tố của nó, và thực hiện chuyển tiếp với chữ cái $c$ từ đó.

Do đó, bài toán về việc tìm các chuyển tiếp đã được giảm xuống thành bài toán về việc tìm các liên kết tiền tố, và bài toán về việc tìm các liên kết tiền tố đã được giảm xuống thành bài toán về việc tìm một liên kết tiền tố và một chuyển tiếp, ngoại trừ các đỉnh gần gốc. Vì vậy, chúng ta có một phụ thuộc đệ quy mà chúng ta có thể giải quyết trong thời gian tuyến tính.

Hãy chuyển sang việc triển khai.
Chú ý rằng bây giờ chúng ta sẽ lưu tổ tiên $p$ và ký tự $pch$ của cạnh từ $p$ đến $v$ cho mỗi đỉnh $v$.
Ngoài ra, tại mỗi đỉnh chúng ta sẽ lưu liên kết tiền tố $\text{link}$ (hoặc $-1$ nếu chưa được tính toán), và trong mảng $\text{go}[k]$ các chuyển tiếp trong máy cho mỗi ký tự (lại là $-1$ nếu chưa được tính toán).

```cpp
const int K = 26;

struct Vertex {
    int next[K];
    bool output = false;
    int p = -1;
    char pch;
    int link = -1;
    int go[K];

    Vertex(int p=-1, char ch='$') : p(p), pch(ch) {
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
    }
};

vector<Vertex> t(1);

void add_string(string const& s) {
    int v = 0;
    for (char ch : s) {
        int c = ch - 'a';
        if (t[v].next[c] == -1) {
            t[v].next[c] = t.size();
            t.emplace_back(v, ch);
        }
        v = t[v].next[c];
    }
    t[v].output = true;
}

int go(int v, char ch);

int get_link(int v) {
    if (t[v].link == -1) {
        if (v == 0 || t[v].p == 0)
            t[v].link = 0;
        else
            t[v].link = go(get_link(t[v].p), t[v].pch);
    }
    return t[v].link;
}

int go(int v, char ch) {
    int c = ch - 'a';
    if (t[v].go[c] == -1) {
        if (t[v].next[c] != -1)
            t[v].go[c] = t[v].next[c];
        else
            t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
    }
    return t[v].go[c];
} 
```

Dễ dàng nhận thấy rằng nhờ vào việc ghi nhớ liên kết tiền tố và các chuyển tiếp,
tổng thời gian để tìm tất cả các liên kết tiền tố và các chuyển tiếp sẽ là tuyến tính.

Để minh họa về khái niệm này, xem trang 103 của [Stanford slides](http://web.stanford.edu/class/archive/cs/cs166/cs166.1166/lectures/02/Slides02.pdf).

### Xây dựng dựa trên BFS

Thay vì tính toán các chuyển tiếp và liên kết tiền tố bằng các cuộc gọi đệ quy tới `go` và `get_link`, có thể tính chúng dưới cùng từ gốc.
(Trong thực tế, khi từ điển chỉ gồm một chuỗi, chúng ta thu được thuật toán Knuth-Morris-Pratt quen thuộc.)

Phương pháp này sẽ có một số ưu điểm so với phương pháp đã mô tả ở trên vì thay vì tổng độ dài $m$, thời gian chạy của nó chỉ phụ thuộc vào số lượng đỉnh $n$ trong trie. Hơn nữa, có thể điều chỉnh nó cho các bảng chữ cái lớn bằng cách sử dụng một cấu trúc dữ liệu mảng không thay đổi, từ đó làm thời gian xây dựng trở thành $O(n \log k)$ thay vì $O(mk)$, điều đó là một cải tiến đáng kể giả định rằng $m$ có thể lên đến $n^2$.

Chúng ta có thể lập luận theo phương pháp quy nạp sử dụng sự thật rằng BFS từ gốc đi qua các đỉnh theo thứ tự tăng dần chiều dài.
Chúng ta có thể giả định rằng khi chúng ta đang ở một đỉnh $v$, liên kết tiền tố của nó $u = link[v]$ đã được tính toán thành công, và cho tất cả các đỉnh có độ dài ngắn hơn, các chuyển tiếp từ chúng cũng đã được tính toán hoàn toàn.

Giả sử vào thời điểm này chúng ta đang đứng ở một đỉnh $v$ và xem xét một ký tự $c$. Thực ra chúng ta có hai trường hợp:

1. $go[v][c] = -1$. Trong trường hợp này, chúng ta có thể gán $go[v][c] = go[u][c]$, điều này đã được biết từ giả thuyết quy nạp;
2. $go[v][c] = w \neq -1$. Trong trường hợp này, chúng ta có thể gán $link[w] = go[u][c]$.

Theo cách này, chúng ta tiêu tốn $O(1)$ thời gian cho mỗi cặp một đỉnh và một ký tự, làm cho thời gian chạy trở thành $O(mk)$. Chi phí chính ở đây là chúng ta sao chép nhiều chuyển tiếp từ $u$ trong trường hợp thứ nhất, trong khi các chuyển tiếp của trường hợp thứ hai tạo thành trie và tổng cộng là $m$ trên tất cả các đỉnh. Để tránh việc sao chép $go[u][c]$, chúng ta có thể sử dụng một cấu trúc dữ liệu mảng không thay đổi, trong đó ban đầu chúng ta sao chép $go[u]$ vào $go[v]$ và sau đó chỉ cập nhật các giá trị cho các ký tự mà chuyển tiếp sẽ khác nhau. Điều này dẫn đến thuật toán $O(m \log k)$.

## Ứng dụng

### Tìm tất cả chuỗi từ một tập hợp đã cho trong một văn bản

Chúng ta được cho một tập hợp các chuỗi và một văn bản.
Chúng ta phải in tất cả các xuất hiện của tất cả các chuỗi từ tập hợp trong văn bản đã cho trong $O(\text{len} + \text{ans})$, nơi $\text{len}$ là độ dài của văn bản và $\text{ans}$ là kích thước của câu trả lời.

Chúng ta xây dựng một tự động hóa cho tập hợp các chuỗi này.
Chúng ta sẽ xử lý văn bản từng chữ cái bằng cách sử dụng tự động hóa, bắt đầu từ gốc của trie.
Nếu vào bất kỳ thời điểm nào chúng ta đang ở trạng thái $v$, và chữ cái tiếp theo là $c$, thì chúng ta chuyển tiếp đến trạng thái tiếp theo với $\text{go}(v, c)$, do đó, tăng độ dài của chuỗi khớp hiện tại lên $1$, hoặc giảm nó bằng cách theo liên kết tiền tố.

Làm thế nào để tìm ra cho một trạng thái $v$, nếu có bất kỳ sự khớp nào với các chuỗi từ tập hợp?
Trước hết, rõ ràng rằng nếu chúng ta đứng trên một đỉnh $\text{output}$, thì chuỗi tương ứng với đỉnh kết thúc tại vị trí này trong văn bản.
Tuy nhiên, điều này chưa chắc đã là trường hợp duy nhất có thể xảy ra của việc khớp:
nếu chúng ta có thể đạt được một hoặc nhiều đỉnh $\text{output}$ bằng cách di chuyển dọc theo các liên kết tiền tố, thì sẽ cũng có một sự khớp tương ứng với mỗi đỉnh $\text{output}$ được tìm thấy.
Một ví dụ đơn giản minh họa tình huống này có thể tạo bằng cách sử dụng tập hợp các chuỗi $\{dabce, abc, bc\}$ và văn bản $dabc$.

Do đó nếu chúng ta lưu trữ trong mỗi đỉnh $\text{output}$ chỉ số của chuỗi tương ứng với nó (hoặc danh sách các chỉ số nếu các chuỗi trùng lặp xuất hiện trong tập hợp), thì chúng ta có thể tìm thấy trong thời gian $O(n)$ các chỉ số của tất cả các chuỗi khớp với trạng thái hiện tại, chỉ bằng cách đi dọc theo các liên kết tiền tố từ đỉnh hiện tại đến gốc.
Đây không phải là giải pháp hiệu quả nhất, vì điều này dẫn đến tổng phức tạp $O(n ~ \text{len})$ toàn bộ. Tuy nhiên, điều này có thể được tối ưu hóa bằng cách tính toán và lưu trữ đỉnh $\text{output}$ gần nhất có thể tiếp cận được bằng các liên kết tiền tố (đôi khi được gọi là **liên kết thoát**). Giá trị này chúng ta có thể tính toán một cách lười biếng trong thời gian tuyến tính.
Do đó, đối với mỗi đỉnh chúng ta có thể tiến lên trong $O(1)$ thời gian đến đỉnh đánh dấu tiếp theo trong đường liên kết tiền tố, tức là đến khớp tiếp theo.
Do đó, đối với mỗi sự khớp chúng ta tiêu tốn $O(1)$ thời gian, và do đó chúng ta đạt được độ phức tạp $O(\text{len} + \text{ans})$.

Nếu bạn chỉ muốn đếm số lần xuất hiện và không tìm các chỉ số chính xác, bạn có thể tính toán số đỉnh được đánh dấu trong đường liên kết tiền tố cho mỗi đỉnh $v$.
Điều này có thể được tính toán trong thời gian tổng cộng $O(n)$.
Do đó, chúng ta có thể tổng hợp tất cả các sự khớp trong $O(\text{len})$.

### Tìm chuỗi nhỏ nhất theo thứ tự từ điển có độ dài đã cho mà không khớp với bất kỳ chuỗi nào đã cho

Một tập hợp các chuỗi và một độ dài $L$ được cung cấp.
Chúng ta phải tìm một chuỗi có độ dài $L$, không chứa bất kỳ chuỗi nào từ tập hợp, và tìm ra chuỗi nhỏ nhất theo thứ tự từ điển.

Chúng ta có thể xây dựng tự động hóa cho tập hợp các chuỗi.
Nhớ rằng các đỉnh $\text{output}$ là các trạng thái mà chúng ta có một sự khớp với một chuỗi từ tập hợp.
Vì trong bài tập này chúng ta phải tránh các sự khớp, nên chúng ta không được phép vào các trạng thái như vậy.
Mặt khác, chúng ta có thể vào tất cả các đỉnh khác.
Do đó chúng ta xóa tất cả các đỉnh "xấu" khỏi máy, và trong đồ thị còn lại của tự động hóa chúng ta tìm đường đi nhỏ nhất theo thứ tự từ điển có độ dài $L$.
Nhiệm vụ này có thể được giải quyết trong $O(L)$ ví dụ bằng [tìm kiếm theo chiều sâu](../graph/depth-first-search.md).

### Tìm chuỗi ngắn nhất chứa tất cả các chuỗi đã cho

Ở đây chúng ta sử dụng những ý tưởng tương tự.
Đối với mỗi đỉnh chúng ta lưu trữ một mask mà chỉ ra các chuỗi khớp tại trạng thái này.
Sau đó, vấn đề có thể được biểu diễn lại như sau:
ban đầu ở trạng thái $(v = \text{root},~ \text{mask} = 0)$, chúng ta muốn đạt được trạng thái $(v,~ \text{mask} = 2^n - 1)$, trong đó $n$ là số chuỗi trong tập hợp.
Khi chúng ta chuyển từ một trạng thái này sang một trạng thái khác bằng một ký tự, chúng ta cập nhật mask tương ứng.
Bằng cách chạy một [tìm kiếm theo chiều rộng](../graph/breadth-first-search.md) chúng ta có thể tìm một đường đi đến trạng thái $(v,~ \text{mask} = 2^n - 1)$ có độ dài nhỏ nhất.

### Tìm chuỗi nhỏ nhất theo thứ tự từ điển có độ dài $L$ chứa $k$ chuỗi {data-toc-label="Tìm chuỗi nhỏ nhất theo thứ tự từ điển có độ dài L chứa k chuỗi"}

Như trong vấn đề trước, chúng ta tính cho mỗi đỉnh số lượng sự khớp tương ứng với nó (đó là số đỉnh được đánh dấu có thể tiếp cận được bằng các liên kết tiền tố).
Chúng ta biểu diễn lại vấn đề: trạng thái hiện tại được xác định bởi một bộ ba số $(v,~ \text{len},~ \text{cnt})$, và chúng ta muốn đạt được từ trạng thái $(\text{root},~ 0,~ 0)$ đến trạng thái $(v,~ L,~ k)$, trong đó $v$ có thể là bất kỳ đỉnh nào.
Do đó, chúng ta có thể tìm được một đường đi như vậy bằng cách sử dụng tìm kiếm theo chiều sâu (và nếu tìm kiếm xem xét các cạnh theo thứ tự tự nhiên của chúng, thì đường đi được tìm thấy sẽ tự động là chuỗi nhỏ nhất theo thứ tự từ điển).

## Bài toán

- [UVA #11590 - Prefix Lookup](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2637)
- [UVA #11171 - SMS](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2112)
- [UVA #10679 - I Love Strings!!](https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1620)
- [Codeforces - x-prime Substrings](https://codeforces.com/problemset/problem/1400/F)
- [Codeforces - Frequency of String](http://codeforces.com/problemset/problem/963/D)
- [CodeChef - TWOSTRS](https://www.codechef.com/MAY20A/problems/TWOSTRS)

## Tham khảo
- [Stanford's CS166 - Aho-Corasick Automata](http://web.stanford.edu/class/archive/cs/cs166/cs166.1166/lectures/02/Slides02.pdf) ([Condensed](http://web.stanford.edu/class/archive/cs/cs166/cs166.1166/lectures/02/Small02.pdf))
