# Tìm cầu trực tuyến (Finding Bridges Online)

---
tags:
  - Dịch
e_maxx_link: bridge_searching_online
---

# Tìm cầu trực tuyến

Chúng ta được cho một đồ thị vô hướng.
Cầu (bridge) là một cạnh mà việc loại bỏ nó sẽ làm cho đồ thị bị ngắt kết nối (hoặc chính xác hơn là làm tăng số lượng thành phần được kết nối).
Nhiệm vụ của chúng ta là tìm tất cả các cầu trong đồ thị đã cho.

Nói một cách không chính thức, nhiệm vụ này có thể được đặt như sau:
chúng ta phải tìm tất cả những con đường "quan trọng" trên bản đồ đường đã cho, tức là những con đường mà việc loại bỏ bất kỳ con đường nào trong số chúng sẽ dẫn đến một số thành phố không thể đến được từ những thành phố khác.

Đã có bài viết [Tìm cầu trong $O(N+M)$](bridge-searching.md) giải quyết nhiệm vụ này bằng cách duyệt [Tìm kiếm theo chiều sâu](depth-first-search.md).
Thuật toán này sẽ phức tạp hơn nhiều, nhưng nó có một ưu điểm lớn:
thuật toán được mô tả trong bài viết này hoạt động trực tuyến (online), nghĩa là không cần phải biết trước đồ thị đầu vào.
Các cạnh được thêm vào từng cái một và sau mỗi lần thêm, thuật toán sẽ tính toán lại tất cả các cầu trong đồ thị hiện tại.
Nói cách khác, thuật toán được thiết kế để hoạt động hiệu quả trên một đồ thị động, thay đổi.

Phát biểu của bài toán một cách chặt chẽ hơn như sau:
Ban đầu, đồ thị trống rỗng và bao gồm $n$ đỉnh.
Sau đó, chúng ta nhận được các cặp đỉnh $(a, b)$, biểu thị một cạnh được thêm vào đồ thị.
Sau mỗi cạnh nhận được, tức là sau khi thêm mỗi cạnh, hãy xuất ra số lượng cầu hiện tại trong đồ thị.

Cũng có thể duy trì một danh sách tất cả các cầu cũng như hỗ trợ rõ ràng các thành phần được kết nối 2 cạnh.

Thuật toán được mô tả bên dưới hoạt động trong thời gian $O(n \log n + m)$, trong đó $m$ là số cạnh.
Thuật toán dựa trên cấu trúc dữ liệu [Hợp nhất tập hợp rời rạc](../data_structures/disjoint_set_union.md).
Tuy nhiên, việc triển khai trong bài viết này mất thời gian $O(n \log n + m \log n)$, bởi vì nó sử dụng phiên bản đơn giản hóa của DSU mà không có Union by Rank.

## Thuật toán

Trước tiên, hãy định nghĩa một thành phần được kết nối $k$ cạnh:
đó là một thành phần được kết nối vẫn được kết nối bất cứ khi nào bạn xóa ít hơn $k$ cạnh.

Rất dễ dàng để nhận thấy rằng các cầu phân chia đồ thị thành các thành phần được kết nối 2 cạnh.
Nếu chúng ta nén mỗi thành phần được kết nối 2 cạnh đó thành các đỉnh và chỉ để lại các cầu làm cạnh trong đồ thị được nén, thì chúng ta sẽ thu được một đồ thị phi chu trình, tức là một rừng.

Thuật toán được mô tả bên dưới duy trì rừng cây này một cách rõ ràng cũng như các thành phần được kết nối 2 cạnh.

Rõ ràng là ban đầu, khi đồ thị trống, nó chứa $n$ thành phần được kết nối 2 cạnh, bản thân chúng không được kết nối.

Khi thêm cạnh tiếp theo $(a, b)$, có thể xảy ra ba trường hợp:

* Cả hai đỉnh $a$ và $b$ đều nằm trong cùng một thành phần được kết nối 2 cạnh - thì cạnh này không phải là cầu và không thay đổi bất cứ điều gì trong cấu trúc rừng, vì vậy chúng ta có thể chỉ cần bỏ qua cạnh này.

    Như vậy, trong trường hợp này, số lượng cầu không thay đổi.

* Các đỉnh $a$ và $b$ nằm trong các thành phần được kết nối hoàn toàn khác nhau, tức là mỗi đỉnh là một phần của một cây khác nhau.
    Trong trường hợp này, cạnh $(a, b)$ trở thành một cầu mới và hai cây này được kết hợp thành một (và tất cả các cầu cũ vẫn còn).

    Như vậy, trong trường hợp này, số lượng cầu tăng thêm một.

* Các đỉnh $a$ và $b$ nằm trong một thành phần được kết nối, nhưng trong các thành phần được kết nối 2 cạnh khác nhau.
    Trong trường hợp này, cạnh này tạo thành một chu trình cùng với một số cầu cũ.
    Tất cả những cây cầu này đều không còn là cầu nữa, và chu trình kết quả phải được nén thành một thành phần được kết nối 2 cạnh mới.

    Như vậy, trong trường hợp này, số lượng cầu giảm đi hai hoặc nhiều hơn.

Do đó, toàn bộ nhiệm vụ được rút gọn thành việc triển khai hiệu quả tất cả các thao tác này trên rừng của các thành phần được kết nối 2 cạnh.

## Cấu trúc dữ liệu để lưu trữ rừng

Cấu trúc dữ liệu duy nhất mà chúng ta cần là [Hợp nhất tập hợp rời rạc](../data_structures/disjoint_set_union.md).
Trên thực tế, chúng ta sẽ tạo hai bản sao của cấu trúc này:
một bản sẽ là để duy trì các thành phần được kết nối, bản còn lại để duy trì các thành phần được kết nối 2 cạnh.
Và ngoài ra, chúng ta lưu trữ cấu trúc của cây trong rừng của các thành phần được kết nối 2 cạnh thông qua các con trỏ:
Mỗi thành phần được kết nối 2 cạnh sẽ lưu trữ chỉ số `par[]` của tổ tiên của nó trong cây.

Bây giờ chúng ta sẽ lần lượt tháo rời mọi thao tác mà chúng ta cần học để triển khai:

  * Kiểm tra xem hai đỉnh có nằm trong cùng một thành phần được kết nối / 2 cạnh được kết nối hay không.
    Nó được thực hiện bằng thuật toán DSU thông thường, chúng ta chỉ cần tìm và so sánh các đại diện của DSU.
  
  * Nối hai cây cho một số cạnh $(a, b)$.
    Vì có thể hóa ra cả đỉnh $a$ và đỉnh $b$ đều không phải là gốc của cây của chúng, nên cách duy nhất để kết nối hai cây này là tạo lại gốc cho một trong số chúng.
    Ví dụ: bạn có thể tạo lại gốc cho cây của đỉnh $a$, sau đó gắn nó vào cây khác bằng cách đặt tổ tiên của $a$ thành $b$.
  
    Tuy nhiên, câu hỏi về hiệu quả của thao tác tạo lại gốc phát sinh:
    để tạo lại gốc cho cây có gốc $r$ thành đỉnh $v$, cần phải truy cập tất cả các đỉnh trên đường dẫn giữa $v$ và $r$ và chuyển hướng các con trỏ `par[]` theo hướng ngược lại, đồng thời thay đổi các tham chiếu đến tổ tiên trong DSU chịu trách nhiệm cho các thành phần được kết nối.
  
    Do đó, chi phí tạo lại gốc là $O(h)$, trong đó $h$ là chiều cao của cây.
    Bạn có thể đưa ra một ước tính thậm chí còn tệ hơn bằng cách nói rằng chi phí là $O(\text{size})$ trong đó $\text{size}$ là số lượng đỉnh trong cây.
    Độ phức tạp cuối cùng sẽ không khác nhau.
  
    Bây giờ chúng ta áp dụng một kỹ thuật tiêu chuẩn: chúng ta tạo lại gốc cho cây chứa ít đỉnh hơn.
    Khi đó, theo trực giác, rõ ràng là trường hợp xấu nhất là khi hai cây có kích thước xấp xỉ bằng nhau được kết hợp, nhưng sau đó kết quả là một cây có kích thước gấp đôi.
    Điều này không cho phép tình huống này xảy ra nhiều lần.
  
    Nói chung, tổng chi phí có thể được viết dưới dạng đệ quy:
    
    \[ T(n) = \max_{k = 1 \ldots n-1} \left\{ T(k) + T(n - k) + O(\min(k, n - k))\right\} \]
    
    $T(n)$ là số thao tác cần thiết để thu được một cây có $n$ đỉnh bằng cách tạo lại gốc và hợp nhất các cây.
    Một cây có kích thước $n$ có thể được tạo bằng cách kết hợp hai cây nhỏ hơn có kích thước $k$ và $n - k$.
    Công thức đệ quy này có nghiệm là $T(n) = O (n \log n)$.
  
    Như vậy, tổng thời gian dành cho tất cả các thao tác tạo lại gốc sẽ là $O(n \log n)$ nếu chúng ta luôn tạo lại gốc cho cây nhỏ hơn trong hai cây.
  
    Chúng ta sẽ phải duy trì kích thước của mỗi thành phần được kết nối, nhưng cấu trúc dữ liệu DSU giúp điều này có thể thực hiện được mà không gặp khó khăn.
  
  * Tìm kiếm chu trình được tạo bằng cách thêm một cạnh mới $(a, b)$.
    Vì $a$ và $b$ đã được kết nối trong cây nên chúng ta cần tìm [Tổ tiên chung thấp nhất (LCA - Lowest Common Ancestor)](lca.md) của các đỉnh $a$ và $b$.
    Chu trình sẽ bao gồm các đường dẫn từ $b$ đến LCA, từ LCA đến $a$ và cạnh $a$ đến $b$.
  
    Sau khi tìm thấy chu trình, chúng ta nén tất cả các đỉnh của chu trình đã phát hiện thành một đỉnh.
    Điều này có nghĩa là chúng ta đã có độ phức tạp tỷ lệ thuận với độ dài chu trình, có nghĩa là chúng ta cũng có thể sử dụng bất kỳ thuật toán LCA nào tỷ lệ thuận với độ dài và không phải sử dụng bất kỳ thuật toán nhanh nào.
  
    Vì tất cả thông tin về cấu trúc của cây đều có sẵn trong mảng tổ tiên `par[]`, nên thuật toán LCA hợp lý duy nhất là như sau:
    đánh dấu các đỉnh $a$ và $b$ là đã truy cập, sau đó chúng ta đi đến tổ tiên của chúng `par[a]` và `par[b]` và đánh dấu chúng, sau đó tiến đến tổ tiên của chúng, v.v., cho đến khi chúng ta đến một đỉnh đã được đánh dấu.
    Đỉnh này là LCA mà chúng ta đang tìm kiếm và chúng ta có thể tìm thấy các đỉnh trên chu trình bằng cách duyệt lại đường dẫn từ $a$ và $b$ đến LCA.
  
    Rõ ràng là độ phức tạp của thuật toán này tỷ lệ thuận với độ dài của chu trình mong muốn.
  
  * Nén chu trình bằng cách thêm một cạnh mới $(a, b)$ vào cây.
  
    Chúng ta cần tạo một thành phần được kết nối 2 cạnh mới, bao gồm tất cả các đỉnh của chu trình đã phát hiện (bản thân chu trình đã phát hiện cũng có thể bao gồm một số thành phần được kết nối 2 cạnh, nhưng điều này không thay đổi bất cứ điều gì).
    Ngoài ra, cần phải nén chúng sao cho cấu trúc của cây không bị xáo trộn và tất cả các con trỏ `par[]` và hai DSU vẫn chính xác.
  
    Cách dễ nhất để đạt được điều này là nén tất cả các đỉnh của chu trình thành LCA của chúng.
    Trên thực tế, LCA là đỉnh cao nhất, tức là con trỏ tổ tiên `par[]` của nó vẫn không thay đổi.
    Đối với tất cả các đỉnh khác của vòng lặp, không cần cập nhật tổ tiên, vì những đỉnh này đơn giản là ngừng tồn tại.
    Nhưng trong DSU của các thành phần được kết nối 2 cạnh, tất cả các đỉnh này sẽ chỉ trỏ đến LCA.
  
    Chúng ta sẽ triển khai DSU của các thành phần được kết nối 2 cạnh mà không cần tối ưu hóa Union by rank, do đó chúng ta sẽ nhận được độ phức tạp $O(\log n)$ trung bình cho mỗi truy vấn.
    Để đạt được độ phức tạp $O(1)$ trung bình cho mỗi truy vấn, chúng ta cần kết hợp các đỉnh của chu trình theo Union by rank, sau đó gán `par[]` cho phù hợp.

## Triển khai

Đây là triển khai cuối cùng của toàn bộ thuật toán.

Như đã đề cập trước đó, để đơn giản, DSU của các thành phần được kết nối 2 cạnh được viết mà không có Union by rank, do đó độ phức tạp kết quả sẽ là $O(\log n)$ trung bình.

Ngoài ra, trong cách triển khai này, bản thân các cầu không được lưu trữ, chỉ có số lượng của chúng là `bridges`.
Tuy nhiên, sẽ không khó để tạo một `set` của tất cả các cầu.

Ban đầu, bạn gọi hàm `init()`, khởi tạo hai DSU (tạo một tập hợp riêng biệt cho mỗi đỉnh và đặt kích thước bằng một) và đặt tổ tiên `par`.

Hàm chính là `add_edge(a, b)`, xử lý và thêm một cạnh mới.

```cpp
vector<int> par, dsu_2ecc, dsu_cc, dsu_cc_size;
int bridges;
int lca_iteration;
vector<int> last_visit;
 
void init(int n) {
    par.resize(n);
    dsu_2ecc.resize(n);
    dsu_cc.resize(n);
    dsu_cc_size.resize(n);
    lca_iteration = 0;
    last_visit.assign(n, 0);
    for (int i=0; i<n; ++i) {
        dsu_2ecc[i] = i;
        dsu_cc[i] = i;
        dsu_cc_size[i] = 1;
        par[i] = -1;
    }
    bridges = 0;
}
 
int find_2ecc(int v) {
    if (v == -1)
        return -1;
    return dsu_2ecc[v] == v ? v : dsu_2ecc[v] = find_2ecc(dsu_2ecc[v]);
}
 
int find_cc(int v) {
    v = find_2ecc(v);
    return dsu_cc[v] == v ? v : dsu_cc[v] = find_cc(dsu_cc[v]);
}
 
void make_root(int v) {
    int root = v;
    int child = -1;
    while (v != -1) {
        int p = find_2ecc(par[v]);
        par[v] = child;
        dsu_cc[v] = root;
        child = v;
        v = p;
    }
    dsu_cc_size[root] = dsu_cc_size[child];
}

void merge_path (int a, int b) {
    ++lca_iteration;
    vector<int> path_a, path_b;
    int lca = -1;
    while (lca == -1) {
        if (a != -1) {
            a = find_2ecc(a);
            path_a.push_back(a);
            if (last_visit[a] == lca_iteration){
                lca = a;
                break;
                }
            last_visit[a] = lca_iteration;
            a = par[a];
        }
        if (b != -1) {
            b = find_2ecc(b);
            path_b.push_back(b);
            if (last_visit[b] == lca_iteration){
                lca = b;
                break;
                }
            last_visit[b] = lca_iteration;
            b = par[b];
        }
        
    }

    for (int v : path_a) {
        dsu_2ecc[v] = lca;
        if (v == lca)
            break;
        --bridges;
    }
    for (int v : path_b) {
        dsu_2ecc[v] = lca;
        if (v == lca)
            break;
        --bridges;
    }
}
 
void add_edge(int a, int b) {
    a = find_2ecc(a);
    b = find_2ecc(b);
    if (a == b)
        return;
 
    int ca = find_cc(a);
    int cb = find_cc(b);

    if (ca != cb) {
        ++bridges;
        if (dsu_cc_size[ca] > dsu_cc_size[cb]) {
            swap(a, b);
            swap(ca, cb);
        }
        make_root(a);
        par[a] = dsu_cc[a] = b;
        dsu_cc_size[cb] += dsu_cc_size[a];
    } else {
        merge_path(a, b);
    }
}
```

DSU cho các thành phần được kết nối 2 cạnh được lưu trữ trong vectơ `dsu_2ecc` và hàm trả về đại diện là `find_2ecc(v)`.
Hàm này được sử dụng nhiều lần trong phần còn lại của mã, vì sau khi nén một số đỉnh thành một, tất cả các đỉnh này ngừng tồn tại và thay vào đó, chỉ có phần tử dẫn đầu mới có tổ tiên `par` chính xác trong rừng của các thành phần được kết nối 2 cạnh.

DSU cho các thành phần được kết nối được lưu trữ trong vectơ `dsu_cc` và cũng có một vectơ bổ sung `dsu_cc_size` để lưu trữ kích thước thành phần.
Hàm `find_cc(v)` trả về phần tử dẫn đầu của thành phần kết nối (thực chất là gốc của cây).

Việc tạo lại gốc cho một cây `make_root(v)` hoạt động như được mô tả ở trên:
nếu duyệt từ đỉnh $v$ qua các tổ tiên đến đỉnh gốc, mỗi lần chuyển hướng tổ tiên `par` theo hướng ngược lại.
Liên kết đến đại diện của thành phần được kết nối `dsu_cc` cũng được cập nhật, sao cho nó trỏ đến đỉnh gốc mới.
Sau khi tạo lại gốc, chúng ta phải gán cho gốc mới kích thước chính xác của thành phần được kết nối.
Ngoài ra, chúng ta phải cẩn thận rằng chúng ta gọi `find_2ecc()` để lấy các đại diện của thành phần được kết nối 2 cạnh, thay vì một số đỉnh khác đã được nén.

Hàm tìm và nén chu trình `merge_path(a, b)` cũng được triển khai như được mô tả ở trên.
Nó tìm kiếm LCA của $a$ và $b$ bằng cách tăng các nút này song song, cho đến khi chúng ta gặp một đỉnh lần thứ hai.
Để đạt hiệu quả, chúng ta chọn một mã định danh duy nhất cho mỗi lệnh gọi tìm kiếm LCA và đánh dấu các đỉnh đã duyệt bằng nó.
Điều này hoạt động trong $O(1)$, trong khi các cách tiếp cận khác như sử dụng `set` hoạt động kém hơn.
Các đường dẫn đã qua được lưu trữ trong các vectơ `path_a` và `path_b` và chúng ta sử dụng chúng để đi qua chúng lần thứ hai cho đến LCA, do đó thu được tất cả các đỉnh của chu trình.
Tất cả các đỉnh của chu trình được nén bằng cách gắn chúng vào LCA, do đó độ phức tạp trung bình là $O(\log n)$ (vì chúng ta không sử dụng Union by rank).
Tất cả các cạnh chúng ta đi qua đều là cầu, vì vậy chúng ta trừ 1 cho mỗi cạnh trong chu trình.

Cuối cùng, hàm truy vấn `add_edge(a, b)` xác định các thành phần được kết nối mà các đỉnh $a$ và $b$ nằm trong đó.
Nếu chúng nằm trong các thành phần kết nối khác nhau, thì một cây nhỏ hơn được tạo lại gốc và sau đó được gắn vào cây lớn hơn.
Nếu không, nếu các đỉnh $a$ và $b$ nằm trong một cây, nhưng trong các thành phần được kết nối 2 cạnh khác nhau, thì hàm `merge_path(a, b)` sẽ được gọi, hàm này sẽ phát hiện chu trình và nén nó thành một thành phần được kết nối 2 cạnh.


