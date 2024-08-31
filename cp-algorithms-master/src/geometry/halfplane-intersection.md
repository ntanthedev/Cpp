# Giao điểm nửa mặt phẳng (Half-plane intersection)

---
tags:
  - Bản gốc
---

# Giao điểm nửa mặt phẳng (Half-plane intersection)

Trong bài viết này, chúng ta sẽ thảo luận về bài toán tính giao điểm của một tập hợp các nửa mặt phẳng. Giao điểm như vậy có thể được biểu diễn một cách thuận tiện dưới dạng một vùng/đa giác lồi, trong đó mọi điểm bên trong nó cũng nằm bên trong tất cả các nửa mặt phẳng và chính đa giác này là thứ mà chúng ta đang cố gắng tìm hoặc xây dựng. Chúng ta đưa ra một số trực giác ban đầu cho bài toán, mô tả cách tiếp cận $O(N \log N)$ được gọi là thuật toán Sắp xếp và Tăng dần (Sort-and-Incremental) và đưa ra một số ứng dụng mẫu của kỹ thuật này.

Người đọc nên quen thuộc với các nguyên thủy và phép toán hình học cơ bản (điểm, vectơ, giao điểm của các đường thẳng). Ngoài ra, kiến ​​thức về [Bao lồi](../geometry/convex-hull.md) hoặc [Thủ thuật bao lồi](../geometry/convex_hull_trick.md) có thể giúp hiểu rõ hơn các khái niệm trong bài viết này, nhưng chúng không phải là điều kiện tiên quyết.

## Làm rõ ban đầu và định nghĩa

Trong toàn bộ bài viết, chúng ta sẽ đưa ra một số giả định (trừ khi có quy định khác):

1. Chúng ta định nghĩa $N$ là số lượng nửa mặt phẳng trong tập hợp đã cho.
2. Chúng ta sẽ biểu diễn các đường thẳng và nửa mặt phẳng bằng một điểm và một vectơ (bất kỳ điểm nào nằm trên đường thẳng đã cho và vectơ hướng của đường thẳng). Trong trường hợp của nửa mặt phẳng, chúng ta giả định rằng mọi nửa mặt phẳng đều cho phép vùng nằm ở phía bên trái của vectơ hướng của nó. Ngoài ra, chúng ta định nghĩa góc của nửa mặt phẳng là góc cực của vectơ hướng của nó. Xem hình ảnh bên dưới để biết ví dụ.
3. Chúng ta sẽ giả sử rằng giao điểm kết quả luôn bị giới hạn hoặc trống. Nếu chúng ta cần xử lý trường hợp không giới hạn, chúng ta có thể chỉ cần thêm 4 nửa mặt phẳng xác định một hộp giới hạn đủ lớn.
4. Để đơn giản, chúng ta sẽ giả sử rằng không có nửa mặt phẳng song song nào trong tập hợp đã cho. Đến cuối bài viết, chúng ta sẽ thảo luận về cách xử lý các trường hợp như vậy.

![](halfplanes_rep.png)

Nửa mặt phẳng $y \geq 2x - 2$ có thể được biểu diễn dưới dạng điểm $P = (1, 0)$ với vectơ hướng $PQ = Q - P = (1, 2)$

## Cách tiếp cận vét cạn - $O(N^3)$ {data-toc-label="Cách tiếp cận vét cạn - O(N^3)"}

Một trong những giải pháp đơn giản và rõ ràng nhất sẽ là tính toán điểm giao nhau của các đường thẳng của tất cả các cặp nửa mặt phẳng và đối với mỗi điểm, hãy kiểm tra xem nó có nằm bên trong tất cả các nửa mặt phẳng khác hay không. Vì có $O(N^2)$ điểm giao nhau và đối với mỗi điểm giao nhau, chúng ta phải kiểm tra $O(N)$ nửa mặt phẳng, nên độ phức tạp thời gian tổng cộng là $O(N^3)$. Vùng thực tế của giao điểm sau đó có thể được xây dựng lại bằng cách sử dụng, ví dụ, thuật toán Bao lồi trên tập hợp các điểm giao nhau được bao gồm trong tất cả các nửa mặt phẳng.

Khá dễ dàng để hiểu tại sao điều này hoạt động: các đỉnh của đa giác lồi kết quả đều là điểm giao nhau của các đường thẳng nửa mặt phẳng và mỗi đỉnh trong số đó rõ ràng là một phần của tất cả các nửa mặt phẳng. Ưu điểm chính của phương pháp này là dễ hiểu, dễ nhớ và viết mã một cách nhanh chóng nếu bạn chỉ cần kiểm tra xem giao điểm có trống hay không. Tuy nhiên, nó cực kỳ chậm và không phù hợp với hầu hết các bài toán, vì vậy chúng ta cần một thứ gì đó nhanh hơn.

## Cách tiếp cận tăng dần - $O(N^2)$ {data-toc-label="Cách tiếp cận tăng dần - O(N^2)"}

Một cách tiếp cận khá đơn giản khác là xây dựng dần dần giao điểm của các nửa mặt phẳng, từng cái một. Phương pháp này về cơ bản tương đương với việc cắt một đa giác lồi bởi một đường thẳng $N$ lần và loại bỏ các nửa mặt phẳng dư thừa ở mỗi bước. Để làm điều này, chúng ta có thể biểu diễn đa giác lồi dưới dạng danh sách các đoạn thẳng và để cắt nó bằng nửa mặt phẳng, chúng ta chỉ cần tìm các điểm giao nhau của các đoạn thẳng với đường thẳng nửa mặt phẳng (sẽ chỉ có hai điểm giao nhau nếu đường thẳng giao nhau đúng với đa giác), và thay thế tất cả các đoạn thẳng ở giữa bằng đoạn thẳng mới tương ứng với nửa mặt phẳng. Vì quy trình như vậy có thể được triển khai trong thời gian tuyến tính, chúng ta có thể chỉ cần bắt đầu với một hộp giới hạn lớn và cắt giảm nó bằng mỗi nửa mặt phẳng, thu được độ phức tạp thời gian tổng cộng là $O(N^2)$.

Phương pháp này là một bước tiến lớn theo đúng hướng, nhưng nó có vẻ lãng phí khi phải lặp lại $O(N)$ nửa mặt phẳng ở mỗi bước. Tiếp theo, chúng ta sẽ thấy rằng, bằng cách thực hiện một số quan sát thông minh, các ý tưởng đằng sau cách tiếp cận tăng dần này có thể được tái chế để tạo ra một thuật toán $O(N \log N)$.

## Thuật toán Sắp xếp và Tăng dần - $O(N \log N)$ {data-toc-label="Thuật toán Sắp xếp và Tăng dần - O(N log N)"}

Nguồn được ghi chép đầy đủ đầu tiên của thuật toán này mà chúng ta có thể tìm thấy là luận án của Zeyuan Zhu cho Cuộc thi Lựa chọn Đội tuyển Trung Quốc có tiêu đề [Thuật toán mới cho Giao điểm nửa mặt phẳng và Giá trị thực tế của nó](http://people.csail.mit.edu/zeyuan/publications.htm), từ năm 2006. Cách tiếp cận mà chúng ta sẽ mô tả tiếp theo dựa trên cùng một thuật toán này, nhưng thay vì tính toán hai giao điểm riêng biệt cho nửa dưới và nửa trên của giao điểm, chúng ta sẽ xây dựng tất cả cùng một lúc trong một lần duyệt bằng deque (hàng đợi hai đầu).

Bản thân thuật toán, như tên gọi có thể tiết lộ, tận dụng thực tế là vùng kết quả từ giao điểm của các nửa mặt phẳng là lồi, và do đó nó sẽ bao gồm một số đoạn của các nửa mặt phẳng theo thứ tự được sắp xếp theo góc của chúng. Điều này dẫn đến một quan sát quan trọng: nếu chúng ta giao nhau dần dần các nửa mặt phẳng theo thứ tự được sắp xếp theo góc (như chúng sẽ xuất hiện trong hình dạng cuối cùng, kết quả của giao điểm) và lưu trữ chúng trong một hàng đợi hai đầu, thì chúng ta sẽ chỉ cần loại bỏ các nửa mặt phẳng từ đầu và cuối của deque.

Để hình dung rõ hơn về thực tế này, giả sử chúng ta đang thực hiện cách tiếp cận tăng dần được mô tả trước đó trên một tập hợp các nửa mặt phẳng được sắp xếp theo góc (trong trường hợp này, chúng ta sẽ giả sử chúng được sắp xếp từ $-\pi$ đến $\pi$) và giả sử chúng ta sắp bắt đầu bước thứ $k$ tùy ý. Điều này có nghĩa là chúng ta đã xây dựng giao điểm của $k-1$ nửa mặt phẳng đầu tiên. Bây giờ, bởi vì các nửa mặt phẳng được sắp xếp theo góc, bất kể nửa mặt phẳng thứ $k$ là gì, chúng ta có thể chắc chắn rằng nó sẽ tạo thành một lượt lồi với nửa mặt phẳng thứ $(K-1)$. Vì lý do đó, một số điều có thể xảy ra:

1. Một số (có thể không có) nửa mặt phẳng ở phía sau giao điểm có thể trở nên *dư thừa*. Trong trường hợp này, chúng ta cần bật các nửa mặt phẳng hiện không còn sử dụng này ra khỏi mặt sau của deque.
2. Một số (có thể không có) nửa mặt phẳng ở phía trước có thể trở nên *dư thừa*. Tương tự như trường hợp 1, chúng ta chỉ cần bật chúng ra khỏi mặt trước của deque.
3. Giao điểm có thể trở nên trống (sau khi xử lý trường hợp 1 và/hoặc 2). Trong trường hợp này, chúng ta chỉ cần báo cáo giao điểm là trống và kết thúc thuật toán.

*Chúng ta nói rằng một nửa mặt phẳng là "dư thừa" nếu nó không đóng góp gì vào giao điểm. Một nửa mặt phẳng như vậy có thể được loại bỏ và giao điểm kết quả sẽ không thay đổi chút nào.*

Đây là một ví dụ nhỏ với minh họa:

Cho $H = \{ A, B, C, D, E \}$ là tập hợp các nửa mặt phẳng hiện có trong giao điểm. Ngoài ra, cho $P = \{ p, q, r, s \}$ là tập hợp các điểm giao nhau của các nửa mặt phẳng liền kề trong H. Bây giờ, giả sử chúng ta muốn giao nó với nửa mặt phẳng $F$, như trong hình minh họa bên dưới:

![](halfplanes_hp1.png)

Lưu ý nửa mặt phẳng $F$ làm cho $A$ và $E$ dư thừa trong giao điểm. Vì vậy, chúng ta loại bỏ cả $A$ và $E$ lần lượt từ mặt trước và mặt sau của giao điểm và thêm $F$ vào cuối. Và cuối cùng chúng ta thu được giao điểm mới $H = \{ B, C, D, F\}$ với $P = \{ q, r, t, u \}$.

![](halfplanes_hp2.png)

Với tất cả những điều này trong tâm trí, chúng ta đã có gần như mọi thứ chúng ta cần để thực sự triển khai thuật toán, nhưng chúng ta vẫn cần nói về một số trường hợp đặc biệt. Ở đầu bài viết, chúng tôi đã nói rằng chúng ta sẽ thêm một hộp giới hạn để xử lý các trường hợp mà giao điểm có thể không bị giới hạn, vì vậy trường hợp khó khăn duy nhất mà chúng ta thực sự cần xử lý là các nửa mặt phẳng song song. Chúng ta có thể có hai trường hợp con: hai nửa mặt phẳng có thể song song cùng hướng hoặc ngược hướng. Lý do trường hợp này cần được xử lý riêng biệt là vì chúng ta sẽ cần tính toán các điểm giao nhau của các đường thẳng nửa mặt phẳng để có thể kiểm tra xem một nửa mặt phẳng có dư thừa hay không, và hai đường thẳng song song không có điểm giao nhau, vì vậy chúng ta cần một cách đặc biệt để xử lý chúng.

Đối với trường hợp các nửa mặt phẳng song song có hướng ngược nhau: Lưu ý rằng, bởi vì chúng ta đang thêm hộp giới hạn để xử lý trường hợp không giới hạn, điều này cũng xử lý trường hợp chúng ta có hai nửa mặt phẳng song song liền kề với hướng ngược nhau sau khi sắp xếp, vì sẽ phải có ít nhất một trong các nửa mặt phẳng của hộp giới hạn nằm giữa hai nửa mặt phẳng này (hãy nhớ rằng chúng được sắp xếp theo góc).

* Tuy nhiên, có thể xảy ra trường hợp sau khi loại bỏ một số nửa mặt phẳng khỏi mặt sau của deque, hai nửa mặt phẳng song song có hướng ngược nhau kết thúc cùng nhau. Trường hợp này chỉ xảy ra, cụ thể là khi hai nửa mặt phẳng này tạo thành một giao điểm trống, vì nửa mặt phẳng cuối cùng này sẽ khiến mọi thứ bị xóa khỏi deque. Để tránh sự cố này, chúng ta phải kiểm tra thủ công các nửa mặt phẳng song song và nếu chúng có hướng ngược nhau, chúng ta chỉ cần dừng thuật toán ngay lập tức và trả về giao điểm trống.


Như vậy, trường hợp duy nhất mà chúng ta thực sự cần xử lý là có nhiều nửa mặt phẳng có cùng góc, và hóa ra trường hợp này khá dễ xử lý: chúng ta chỉ cần giữ nửa mặt phẳng ngoài cùng bên trái và xóa phần còn lại, vì dù sao chúng cũng sẽ hoàn toàn dư thừa.
Tóm lại, thuật toán đầy đủ sẽ gần giống như sau:

1. Chúng ta bắt đầu bằng cách sắp xếp tập hợp các nửa mặt phẳng theo góc, mất thời gian $O(N \log N)$.
2. Chúng ta sẽ lặp qua tập hợp các nửa mặt phẳng và đối với mỗi nửa mặt phẳng, chúng ta sẽ thực hiện quy trình tăng dần, bật ra khỏi đầu và cuối của hàng đợi hai đầu khi cần thiết. Điều này sẽ mất thời gian tuyến tính, vì mỗi nửa mặt phẳng chỉ có thể được thêm hoặc xóa một lần.
3. Cuối cùng, đa giác lồi thu được từ giao điểm có thể được lấy đơn giản bằng cách tính toán các điểm giao nhau của các nửa mặt phẳng liền kề trong deque ở cuối quy trình. Điều này cũng sẽ mất thời gian tuyến tính. Cũng có thể lưu trữ các điểm như vậy trong bước 2 và bỏ qua bước này hoàn toàn, nhưng chúng tôi tin rằng việc tính toán chúng một cách nhanh chóng sẽ dễ dàng hơn một chút (về mặt triển khai).

Nhìn chung, chúng ta đã đạt được độ phức tạp thời gian là $O(N \log N)$. Vì sắp xếp rõ ràng là nút thắt cổ chai, nên thuật toán có thể được thực hiện để chạy trong thời gian tuyến tính trong trường hợp đặc biệt khi chúng ta được cung cấp các nửa mặt phẳng được sắp xếp trước theo góc của chúng (ví dụ về trường hợp như vậy sẽ là thu được các nửa mặt phẳng xác định một đa giác lồi).

### Triển khai trực tiếp

Dưới đây là một ví dụ triển khai trực tiếp thuật toán, với các nhận xét giải thích hầu hết các phần:

Các struct điểm/vectơ và nửa mặt phẳng đơn giản:

```cpp
// Xác định lại epsilon và vô cực khi cần thiết. Hãy chú ý đến các lỗi chính xác.
const long double eps = 1e-9, inf = 1e9; 

// Struct điểm/vectơ cơ bản.
struct Point { 

    long double x, y;
    explicit Point(long double x = 0, long double y = 0) : x(x), y(y) {}

    // Phép cộng, phép trừ, nhân với hằng số, tích vô hướng, tích có hướng.

    friend Point operator + (const Point& p, const Point& q) {
        return Point(p.x + q.x, p.y + q.y); 
    }

    friend Point operator - (const Point& p, const Point& q) { 
        return Point(p.x - q.x, p.y - q.y); 
    }

    friend Point operator * (const Point& p, const long double& k) { 
        return Point(p.x * k, p.y * k); 
    } 
    
    friend long double dot(const Point& p, const Point& q) {
    	return p.x * q.x + p.y * q.y;
    }

    friend long double cross(const Point& p, const Point& q) { 
        return p.x * q.y - p.y * q.x; 
    }
};

// Struct nửa mặt phẳng cơ bản.
struct Halfplane { 

    // 'p' là một điểm đi qua của đường thẳng và 'pq' là vectơ hướng của đường thẳng.
    Point p, pq; 
    long double angle;

    Halfplane() {}
    Halfplane(const Point& a, const Point& b) : p(a), pq(b - a) {
        angle = atan2l(pq.y, pq.x);    
    }

    // Kiểm tra xem điểm 'r' có nằm ngoài nửa mặt phẳng này hay không.
    // Mọi nửa mặt phẳng đều cho phép vùng nằm ở BÊN TRÁI đường thẳng của nó.
    bool out(const Point& r) { 
        return cross(pq, r - p) < -eps; 
    }

    // Bộ so sánh để sắp xếp.
    bool operator < (const Halfplane& e) const { 
        return angle < e.angle;
    } 

    // Điểm giao nhau của các đường thẳng của hai nửa mặt phẳng. Giả sử chúng không bao giờ song song.
    friend Point inter(const Halfplane& s, const Halfplane& t) {
        long double alpha = cross((t.p - s.p), t.pq) / cross(s.pq, t.pq);
        return s.p + (s.pq * alpha);
    }
};
```

Thuật toán:

```cpp
// Thuật toán thực tế
vector<Point> hp_intersect(vector<Halfplane>& H) { 

    Point box[4] = {  // Hộp giới hạn theo thứ tự CCW
        Point(inf, inf), 
        Point(-inf, inf), 
        Point(-inf, -inf), 
        Point(inf, -inf) 
    };

    for(int i = 0; i<4; i++) { // Thêm các nửa mặt phẳng hộp giới hạn.
        Halfplane aux(box[i], box[(i+1) % 4]);
        H.push_back(aux);
    }

    // Sắp xếp theo góc và bắt đầu thuật toán
    sort(H.begin(), H.end());
    deque<Halfplane> dq;
    int len = 0;
    for(int i = 0; i < int(H.size()); i++) {

        // Loại bỏ khỏi mặt sau của deque trong khi nửa mặt phẳng cuối cùng là dư thừa
        while (len > 1 && H[i].out(inter(dq[len-1], dq[len-2]))) {
            dq.pop_back();
            --len;
        }

        // Loại bỏ khỏi mặt trước của deque trong khi nửa mặt phẳng đầu tiên là dư thừa
        while (len > 1 && H[i].out(inter(dq[0], dq[1]))) {
            dq.pop_front();
            --len;
        }
        
        // Kiểm tra trường hợp đặc biệt: Nửa mặt phẳng song song
        if (len > 0 && fabsl(cross(H[i].pq, dq[len-1].pq)) < eps) {
        	// Các nửa mặt phẳng song song đối diện kết thúc được kiểm tra với nhau.
        	if (dot(H[i].pq, dq[len-1].pq) < 0.0)
        		return vector<Point>();
        	
        	// Nửa mặt phẳng cùng hướng: chỉ giữ lại nửa mặt phẳng ngoài cùng bên trái.
        	if (H[i].out(dq[len-1].p)) {
        		dq.pop_back();
        		--len;
        	}
        	else continue;
        }
        
        // Thêm nửa mặt phẳng mới
        dq.push_back(H[i]);
        ++len;
    }

    // Dọn dẹp cuối cùng: Kiểm tra các nửa mặt phẳng ở mặt trước so với mặt sau và ngược lại
    while (len > 2 && dq[0].out(inter(dq[len-1], dq[len-2]))) {
        dq.pop_back();
        --len;
    }

    while (len > 2 && dq[len-1].out(inter(dq[0], dq[1]))) {
        dq.pop_front();
        --len;
    }

    // Báo cáo giao điểm trống nếu cần
    if (len < 3) return vector<Point>();

    // Xây dựng lại đa giác lồi từ các nửa mặt phẳng còn lại.
    vector<Point> ret(len);
    for(int i = 0; i+1 < len; i++) {
        ret[i] = inter(dq[i], dq[i+1]);
    }
    ret.back() = inter(dq[len-1], dq[0]);
    return ret;
}
```


### Thảo luận về triển khai

Một điều đặc biệt cần lưu ý là, trong trường hợp có nhiều nửa mặt phẳng giao nhau tại cùng một điểm, thì thuật toán này có thể trả về các điểm liền kề lặp lại trong đa giác cuối cùng. Tuy nhiên, điều này sẽ không ảnh hưởng đến việc đánh giá chính xác xem giao điểm có trống hay không và nó cũng không ảnh hưởng đến diện tích đa giác. Bạn có thể muốn xóa các bản sao này tùy thuộc vào những nhiệm vụ bạn cần làm sau đó. Bạn có thể làm điều này rất dễ dàng với std::unique. Chúng tôi muốn giữ các điểm lặp lại trong quá trình thực hiện thuật toán để có thể tính toán chính xác các giao điểm có diện tích bằng không (ví dụ: các giao điểm bao gồm một điểm, đường thẳng hoặc đoạn thẳng). Tôi khuyến khích người đọc kiểm tra một số trường hợp do chính tay tạo ra nhỏ trong đó giao điểm dẫn đến một điểm hoặc đường thẳng duy nhất.

Một điều nữa cần nói đến là phải làm gì nếu chúng ta được cung cấp các nửa mặt phẳng ở dạng ràng buộc tuyến tính (ví dụ: $ax + by + c \leq 0$). Trong trường hợp như vậy, có hai lựa chọn. Bạn có thể triển khai thuật toán với các sửa đổi tương ứng để hoạt động với biểu diễn như vậy (về cơ bản tạo struct nửa mặt phẳng của riêng bạn, sẽ khá đơn giản nếu bạn quen thuộc với thủ thuật bao lồi) hoặc bạn có thể biến đổi các đường thẳng thành biểu diễn mà chúng ta đã sử dụng trong bài viết này bằng cách lấy bất kỳ 2 điểm nào của mỗi đường thẳng. Nói chung, bạn nên làm việc với biểu diễn được cung cấp trong bài toán để tránh các vấn đề chính xác bổ sung.

## Bài toán, nhiệm vụ và ứng dụng

Nhiều bài toán có thể được giải quyết bằng giao điểm nửa mặt phẳng cũng có thể được giải quyết mà không cần nó, nhưng (thường) với các cách tiếp cận phức tạp hơn hoặc không phổ biến. Nói chung, giao điểm nửa mặt phẳng có thể xuất hiện khi xử lý các bài toán liên quan đến đa giác (chủ yếu là lồi), khả năng hiển thị trên mặt phẳng và quy hoạch tuyến tính hai chiều. Dưới đây là một số ví dụ nhiệm vụ có thể được giải quyết bằng kỹ thuật này:

### Giao điểm đa giác lồi

Một trong những ứng dụng cổ điển của giao điểm nửa mặt phẳng: Cho $N$ đa giác, tính toán vùng được bao gồm bên trong tất cả các đa giác.

Vì giao điểm của một tập hợp các nửa mặt phẳng là một đa giác lồi, nên chúng ta cũng có thể biểu diễn một đa giác lồi như một tập hợp các nửa mặt phẳng (mọi cạnh của đa giác là một đoạn của một nửa mặt phẳng). Tạo các nửa mặt phẳng này cho mọi đa giác và tính toán giao điểm của toàn bộ tập hợp. Tổng độ phức tạp thời gian là $O(S \log S)$, trong đó S là tổng số cạnh của tất cả các đa giác. Về mặt lý thuyết, bài toán cũng có thể được giải quyết trong $O(S \log N)$ bằng cách hợp nhất $N$ tập hợp các nửa mặt phẳng bằng cách sử dụng heap và sau đó chạy thuật toán mà không cần bước sắp xếp, nhưng giải pháp như vậy có hệ số hằng số tồi tệ hơn nhiều so với sắp xếp đơn giản và chỉ mang lại tốc độ nhỏ. tăng cho $N$ rất nhỏ.

### Khả năng hiển thị trên mặt phẳng

Các bài toán yêu cầu một cái gì đó trong số các dòng "xác định xem một số đoạn thẳng có thể nhìn thấy từ một số điểm nào đó trên mặt phẳng hay không" thường có thể được hình thành như các bài toán giao điểm nửa mặt phẳng. Ví dụ, hãy thực hiện nhiệm vụ sau: Cho một số đa giác đơn (không nhất thiết phải lồi), hãy xác định xem có điểm nào bên trong đa giác sao cho toàn bộ ranh giới của đa giác có thể được quan sát từ điểm đó hay không. Điều này còn được gọi là tìm [nhân của đa giác](https://en.wikipedia.org/wiki/Star-shaped_polygon) và có thể được giải quyết bằng giao điểm nửa mặt phẳng đơn giản, lấy mỗi cạnh của đa giác làm nửa mặt phẳng và sau đó tính toán giao điểm của nó.

Đây là một bài toán liên quan, thú vị hơn được trình bày bởi Artem Vasilyev trong một trong các [bài giảng của Trường hè ICPC Brazil](https://youtu.be/WKyZSitpm6M?t=6463) của ông:
Cho một tập hợp $p$ các điểm $p_1, p_2\ \dots \ p_n$ trên mặt phẳng, hãy xác định xem có điểm $q$ nào bạn có thể đứng sao cho bạn có thể nhìn thấy tất cả các điểm của $p$ từ trái sang phải theo thứ tự tăng dần của chỉ mục của chúng.

Bài toán như vậy có thể được giải quyết bằng cách nhận thấy rằng việc có thể nhìn thấy một số điểm $p_i$ ở bên trái $p_j$ cũng giống như việc có thể nhìn thấy phía bên phải của đoạn thẳng từ $p_i$ đến $p_j$ (hoặc tương đương, có thể nhìn thấy phía bên trái của đoạn thẳng từ $p_j$ đến $p_i$). Với suy nghĩ đó, chúng ta có thể chỉ cần tạo một nửa mặt phẳng cho mỗi đoạn thẳng $p_i p_{i+1}$ (hoặc $p_{i+1} p_i$ tùy thuộc vào hướng bạn chọn) và kiểm tra xem giao điểm của toàn bộ tập hợp có trống hay không.

### Giao điểm nửa mặt phẳng với tìm kiếm nhị phân

Một ứng dụng phổ biến khác là sử dụng giao điểm nửa mặt phẳng như một công cụ để xác thực vị ngữ của quy trình tìm kiếm nhị phân. Dưới đây là ví dụ về một bài toán như vậy, cũng được Artem Vasilyev trình bày trong bài giảng đã đề cập trước đó: Cho một đa giác **lồi** $P$, hãy tìm chu vi lớn nhất có thể được nội tiếp bên trong nó.

Thay vì tìm kiếm một số loại giải pháp dạng đóng, công thức khó chịu hoặc giải pháp thuật toán tối nghĩa, hãy thử tìm kiếm nhị phân trên câu trả lời. Lưu ý rằng, đối với một số $r$ cố định, một đường tròn có bán kính $r$ có thể được nội tiếp bên trong $P$ chỉ khi tồn tại một số điểm bên trong $P$ có khoảng cách lớn hơn hoặc bằng $r$ đến tất cả các điểm của ranh giới của $P$. Điều kiện này có thể được xác thực bằng cách "thu nhỏ" đa giác vào trong một khoảng cách $r$ và kiểm tra xem đa giác có còn không suy biến hay không (hoặc bản thân nó là một điểm/đoạn thẳng). Quy trình như vậy có thể được mô phỏng bằng cách lấy các nửa mặt phẳng của các cạnh của đa giác theo thứ tự ngược chiều kim đồng hồ, dịch từng nửa mặt phẳng theo khoảng cách $r$ theo hướng của vùng mà chúng cho phép (nghĩa là trực giao với vectơ hướng của nửa mặt phẳng), và kiểm tra xem giao điểm có trống hay không.

Rõ ràng là nếu chúng ta có thể nội tiếp một đường tròn có bán kính $r$, chúng ta cũng có thể nội tiếp bất kỳ đường tròn nào khác có bán kính nhỏ hơn $r$. Vì vậy, chúng ta có thể thực hiện tìm kiếm nhị phân trên bán kính $r$ và xác thực mọi bước bằng cách sử dụng giao điểm nửa mặt phẳng. Ngoài ra, lưu ý rằng các nửa mặt phẳng của một đa giác lồi đã được sắp xếp theo góc, vì vậy có thể bỏ qua bước sắp xếp trong thuật toán. Do đó, chúng ta thu được độ phức tạp thời gian tổng cộng là $O(NK)$, trong đó $N$ là số đỉnh của đa giác và $K$ là số lần lặp của tìm kiếm nhị phân (giá trị thực tế sẽ phụ thuộc vào phạm vi của các câu trả lời có thể có và độ chính xác mong muốn).

### Quy hoạch tuyến tính hai chiều

Một ứng dụng nữa của giao điểm nửa mặt phẳng là quy hoạch tuyến tính theo hai biến. Tất cả các ràng buộc tuyến tính cho hai biến có thể được biểu thị ở dạng $Ax + By + C \leq 0$ (bộ so sánh bất đẳng thức có thể thay đổi). Rõ ràng, đây chỉ là các nửa mặt phẳng, vì vậy việc kiểm tra xem một giải pháp khả thi có tồn tại cho một tập hợp các ràng buộc tuyến tính hay không có thể được thực hiện bằng giao điểm nửa mặt phẳng. Ngoài ra, đối với một tập hợp các ràng buộc tuyến tính nhất định, có thể tính toán vùng của các giải pháp khả thi (tức là giao điểm của các nửa mặt phẳng) và sau đó trả lời nhiều truy vấn tối đa hóa/cực tiểu hóa một số hàm tuyến tính $f(x, y)$ theo các ràng buộc trong $O(\log N)$ cho mỗi truy vấn bằng cách sử dụng tìm kiếm nhị phân (rất giống với thủ thuật bao lồi).

Điều đáng nói là cũng tồn tại một thuật toán ngẫu nhiên khá đơn giản có thể kiểm tra xem một tập hợp các ràng buộc tuyến tính có giải pháp khả thi hay không và tối đa hóa/cực tiểu hóa một số hàm tuyến tính theo các ràng buộc nhất định. Thuật toán ngẫu nhiên này cũng được Artem Vasilyev giải thích độc đáo trong bài giảng được đề cập trước đó. Dưới đây là một số tài nguyên bổ sung về nó, nếu người đọc quan tâm: [CG - Bài giảng 4, phần 4 và 5](https://youtu.be/5dfc355t2y4) và [Blog của Petr Mitrichev (bao gồm giải pháp cho bài toán khó nhất trong danh sách bài tập thực hành bên dưới)](https://petr-mitrichev.blogspot.com/2016/07/a-half-plane-week.html).

## Bài tập thực hành

### Bài toán cổ điển, ứng dụng trực tiếp

* [Codechef - Animesh decides to settle down](https://www.codechef.com/problems/CHN02)
* [POJ - How I mathematician Wonder What You Are!](http://poj.org/problem?id=3130)
* [POJ - Rotating Scoreboard](http://poj.org/problem?id=3335)
* [POJ - Video Surveillance](http://poj.org/problem?id=1474)
* [POJ - Art Gallery](http://poj.org/problem?id=1279)
* [POJ - Uyuw's Concert](http://poj.org/problem?id=2451)

### Bài toán khó hơn

* [POJ - Most Distant Point from the Sea - Trung bình](http://poj.org/problem?id=3525)
* [Baekjoon - Jeju's Island - Giống như trên nhưng có vẻ như các trường hợp thử nghiệm mạnh hơn](https://www.acmicpc.net/problem/3903)
* [POJ - Feng Shui - Trung bình](http://poj.org/problem?id=3384)
* [POJ - Triathlon - Trung bình/khó](http://poj.org/problem?id=1755)
* [DMOJ - Arrow - Trung bình/khó](https://dmoj.ca/problem/ccoprep3p3)
* [POJ - Jungle Outpost - Khó](http://poj.org/problem?id=3968)
* [Codeforces - Jungle Outpost (liên kết thay thế, bài toán J) - Khó](https://codeforces.com/gym/101309/attachments?mobile=false) 
* [Yandex - Asymmetry Value (cần cuộc thi ảo để xem, bài toán F) - Rất khó](https://contest.yandex.com/contest/2540/enter/)

### Bài toán bổ sung

* Trại lập trình Petrozavodsk lần thứ 40, Mùa đông 2021 - Ngày 1: Cuộc thi của Đại học Jagiellonian, Giải thưởng lớn của Krakow - Bài toán B: Cắt bánh (gần như) công bằng. Tại thời điểm viết bài báo, bài toán này là riêng tư và chỉ có thể truy cập bởi những người tham gia Trại lập trình.

## Tài liệu tham khảo, thư mục và các nguồn khác

### Nguồn chính

* [Thuật toán mới cho Giao điểm nửa mặt phẳng và Giá trị thực tế của nó.](http://people.csail.mit.edu/zeyuan/publications.htm) Bài báo gốc của thuật toán.
* [Bài giảng Trường hè ICPC Brazil 2020 của Artem Vasilyev.](https://youtu.be/WKyZSitpm6M?t=6463) Bài giảng tuyệt vời về giao điểm nửa mặt phẳng. Cũng bao gồm các chủ đề hình học khác.

### Blog hay (tiếng Trung)

* [Cơ bản về Hình học tính toán - Giao điểm của các nửa mặt phẳng.](https://zhuanlan.zhihu.com/p/83499723)
* [Giới thiệu chi tiết về thuật toán giao điểm nửa mặt phẳng.](https://blog.csdn.net/qq_40861916/article/details/83541403)
* [Tóm tắt các bài toán giao điểm nửa mặt phẳng.](https://blog.csdn.net/qq_40482358/article/details/87921815)
* [Phương pháp tăng dần sắp xếp của giao điểm nửa mặt phẳng.](https://blog.csdn.net/u012061345/article/details/23872929)

### Thuật toán ngẫu nhiên

* [Quy hoạch tuyến tính và giao điểm nửa mặt phẳng - Phần 4 và 5.](https://youtu.be/5dfc355t2y4)
* [Blog của Petr Mitrichev: Một tuần nửa mặt phẳng.](https://petr-mitrichev.blogspot.com/2016/07/a-half-plane-week.html)


