# Xây dựng bao lồi (Convex Hull Construction)

---
tags:
  - Dịch
e_maxx_link: convex_hull_graham
---

# Xây dựng bao lồi

Trong bài viết này, chúng ta sẽ thảo luận về bài toán xây dựng bao lồi từ một tập hợp các điểm.

Xét $N$ điểm cho trước trên một mặt phẳng, mục tiêu là tạo ra một bao lồi, tức là đa giác lồi nhỏ nhất chứa tất cả các điểm đã cho.

Chúng ta sẽ xem xét thuật toán **quét Graham** (Graham's scan) được xuất bản vào năm 1972 bởi Graham, và
cũng là thuật toán **chuỗi đơn điệu** (Monotone chain) được xuất bản vào năm 1979 bởi Andrew. Cả hai
đều có độ phức tạp $\mathcal{O}(N \log N)$, và là tối ưu tiệm cận (vì đã được chứng minh là không có thuật toán nào tốt hơn về mặt tiệm cận), ngoại trừ một số bài toán liên quan đến xử lý song song hoặc trực tuyến.

## Thuật toán quét Graham

Thuật toán đầu tiên tìm điểm thấp nhất $P_0$. Nếu có nhiều điểm
có cùng tọa độ Y, điểm có tọa độ X nhỏ hơn được xem xét. Bước
này mất thời gian $\mathcal{O}(N)$.

Tiếp theo, tất cả các điểm khác được sắp xếp theo góc cực theo chiều kim đồng hồ.
Nếu góc cực giữa hai hoặc nhiều điểm là như nhau, thì nên phá vỡ ràng buộc bằng khoảng cách từ $P_0$, theo thứ tự tăng dần.

Sau đó, chúng ta lặp qua từng điểm một và đảm bảo rằng điểm hiện tại
và hai điểm trước nó tạo thành một lượt theo chiều kim đồng hồ, nếu không điểm trước đó
sẽ bị loại bỏ, vì nó sẽ tạo thành hình dạng không lồi. Việc kiểm tra tính chất theo chiều kim đồng hồ hoặc ngược chiều kim đồng hồ
có thể được thực hiện bằng cách kiểm tra [hướng](oriented-triangle-area.md).

Chúng ta sử dụng một _stack_ (ngăn xếp) để lưu trữ các điểm và sau khi chúng ta đến điểm gốc $P_0$,
thuật toán được thực hiện và chúng ta trả về _stack_ chứa tất cả các điểm của
bao lồi theo chiều kim đồng hồ.

Nếu bạn cần bao gồm các điểm thẳng hàng trong khi thực hiện quét Graham, bạn cần
thêm một bước sau khi sắp xếp. Bạn cần lấy các điểm có
khoảng cách cực lớn nhất từ ​​$P_0$ (những điểm này phải ở cuối vectơ đã sắp xếp) và thẳng hàng.
Các điểm trong dòng này phải được đảo ngược để chúng ta có thể xuất ra tất cả
các điểm thẳng hàng, nếu không, thuật toán sẽ lấy điểm gần nhất trong dòng này
và thoát. Bước này không nên được bao gồm trong phiên bản không thẳng hàng
của thuật toán, nếu không, bạn sẽ không nhận được bao lồi nhỏ nhất.

### Triển khai

```{.cpp file=graham_scan}
struct pt {
    double x, y;
    bool operator == (pt const& t) const {
        return x == t.x && y == t.y;
    }
};

int orientation(pt a, pt b, pt c) {
    double v = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
    if (v < 0) return -1; // theo chiều kim đồng hồ
    if (v > 0) return +1; // ngược chiều kim đồng hồ
    return 0;
}

bool cw(pt a, pt b, pt c, bool include_collinear) {
    int o = orientation(a, b, c);
    return o < 0 || (include_collinear && o == 0);
}
bool collinear(pt a, pt b, pt c) { return orientation(a, b, c) == 0; }

void convex_hull(vector<pt>& a, bool include_collinear = false) {
    pt p0 = *min_element(a.begin(), a.end(), [](pt a, pt b) {
        return make_pair(a.y, a.x) < make_pair(b.y, b.x);
    });
    sort(a.begin(), a.end(), [&p0](const pt& a, const pt& b) {
        int o = orientation(p0, a, b);
        if (o == 0)
            return (p0.x-a.x)*(p0.x-a.x) + (p0.y-a.y)*(p0.y-a.y)
                < (p0.x-b.x)*(p0.x-b.x) + (p0.y-b.y)*(p0.y-b.y);
        return o < 0;
    });
    if (include_collinear) {
        int i = (int)a.size()-1;
        while (i >= 0 && collinear(p0, a[i], a.back())) i--;
        reverse(a.begin()+i+1, a.end());
    }

    vector<pt> st;
    for (int i = 0; i < (int)a.size(); i++) {
        while (st.size() > 1 && !cw(st[st.size()-2], st.back(), a[i], include_collinear))
            st.pop_back();
        st.push_back(a[i]);
    }

    if (include_collinear == false && st.size() == 2 && st[0] == st[1])
        st.pop_back();

    a = st;
}
```

## Thuật toán chuỗi đơn điệu

Thuật toán đầu tiên tìm điểm ngoài cùng bên trái và ngoài cùng bên phải A và B. Trong trường hợp tồn tại nhiều điểm như vậy,
điểm thấp nhất trong số các điểm bên trái (tọa độ Y thấp nhất) được lấy là A và điểm cao nhất trong số các điểm bên phải (tọa độ Y cao nhất)
được lấy là B. Rõ ràng là cả A và B đều phải thuộc bao lồi vì chúng ở xa nhất và chúng không thể được chứa
bởi bất kỳ đường thẳng nào được tạo bởi một cặp trong số các điểm đã cho.

Bây giờ, vẽ một đường thẳng đi qua AB. Điều này chia tất cả các điểm khác thành hai tập hợp, S1 và S2, trong đó S1 chứa tất cả các điểm
phía trên đường thẳng nối A và B, và S2 chứa tất cả các điểm phía dưới đường thẳng nối A và B. Các điểm nằm trên
đường thẳng nối A và B có thể thuộc về một trong hai tập hợp. Các điểm A và B thuộc về cả hai tập hợp. Bây giờ thuật toán
xây dựng tập hợp trên S1 và tập hợp dưới S2 và sau đó kết hợp chúng để thu được câu trả lời.

Để lấy tập hợp trên, chúng ta sắp xếp tất cả các điểm theo tọa độ x. Đối với mỗi điểm, chúng ta kiểm tra xem liệu - điểm hiện tại có phải là điểm cuối cùng hay không,
(mà chúng ta đã định nghĩa là B), hoặc nếu hướng giữa đường thẳng giữa A và điểm hiện tại và đường thẳng giữa điểm hiện tại và B là theo chiều kim đồng hồ. Trong những trường hợp đó, điểm hiện tại
thuộc về tập hợp trên S1. Việc kiểm tra tính chất theo chiều kim đồng hồ hoặc ngược chiều kim đồng hồ
có thể được thực hiện bằng cách kiểm tra [hướng](oriented-triangle-area.md).

Nếu điểm đã cho thuộc về tập hợp trên, chúng ta kiểm tra góc được tạo bởi đường thẳng nối điểm gần cuối thứ hai và điểm cuối cùng trong bao lồi trên,
với đường thẳng nối điểm cuối cùng trong bao lồi trên và điểm hiện tại. Nếu góc không theo chiều kim đồng hồ, chúng ta xóa điểm gần đây nhất được thêm vào
bao lồi trên vì điểm hiện tại sẽ có thể chứa điểm trước đó sau khi nó được thêm vào bao lồi.

Logic tương tự áp dụng cho tập hợp dưới S2. Nếu một trong hai - điểm hiện tại là B hoặc hướng của các đường thẳng, được tạo bởi A và
điểm hiện tại và điểm hiện tại và B, là ngược chiều kim đồng hồ - thì nó thuộc về S2.

Nếu điểm đã cho thuộc về tập hợp dưới, chúng ta hành động tương tự như đối với điểm trên tập hợp trên, ngoại trừ chúng ta kiểm tra hướng ngược chiều kim đồng hồ
thay vì hướng theo chiều kim đồng hồ. Do đó, nếu góc được tạo bởi đường thẳng nối điểm gần cuối thứ hai và điểm cuối cùng trong bao lồi dưới,
với đường thẳng nối điểm cuối cùng trong bao lồi dưới và điểm hiện tại không ngược chiều kim đồng hồ, chúng ta xóa điểm gần đây nhất được thêm vào bao lồi dưới vì điểm hiện tại sẽ có thể chứa
điểm trước đó sau khi được thêm vào bao lồi.

Bao lồi cuối cùng thu được từ hợp của bao lồi trên và bao lồi dưới, tạo thành bao lồi theo chiều kim đồng hồ, và việc triển khai như sau.

Nếu bạn cần các điểm thẳng hàng, bạn chỉ cần kiểm tra chúng trong các quy trình theo chiều kim đồng hồ/ngược chiều kim đồng hồ.
Tuy nhiên, điều này cho phép một trường hợp suy biến trong đó tất cả các điểm đầu vào thẳng hàng trong một đường thẳng duy nhất và thuật toán sẽ xuất ra các điểm lặp lại.
Để giải quyết điều này, chúng ta kiểm tra xem bao lồi trên có chứa tất cả các điểm hay không và nếu có, chúng ta chỉ cần trả về các điểm theo thứ tự ngược lại, vì đó
là những gì cách triển khai của Graham sẽ trả về trong trường hợp này.

### Triển khai

```{.cpp file=monotone_chain}
struct pt {
    double x, y;
};

int orientation(pt a, pt b, pt c) {
    double v = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
    if (v < 0) return -1; // theo chiều kim đồng hồ
    if (v > 0) return +1; // ngược chiều kim đồng hồ
    return 0;
}

bool cw(pt a, pt b, pt c, bool include_collinear) {
    int o = orientation(a, b, c);
    return o < 0 || (include_collinear && o == 0);
}
bool ccw(pt a, pt b, pt c, bool include_collinear) {
    int o = orientation(a, b, c);
    return o > 0 || (include_collinear && o == 0);
}

void convex_hull(vector<pt>& a, bool include_collinear = false) {
    if (a.size() == 1)
        return;

    sort(a.begin(), a.end(), [](pt a, pt b) {
        return make_pair(a.x, a.y) < make_pair(b.x, b.y);
    });
    pt p1 = a[0], p2 = a.back();
    vector<pt> up, down;
    up.push_back(p1);
    down.push_back(p1);
    for (int i = 1; i < (int)a.size(); i++) {
        if (i == a.size() - 1 || cw(p1, a[i], p2, include_collinear)) {
            while (up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], a[i], include_collinear))
                up.pop_back();
            up.push_back(a[i]);
        }
        if (i == a.size() - 1 || ccw(p1, a[i], p2, include_collinear)) {
            while (down.size() >= 2 && !ccw(down[down.size()-2], down[down.size()-1], a[i], include_collinear))
                down.pop_back();
            down.push_back(a[i]);
        }
    }

    if (include_collinear && up.size() == a.size()) {
        reverse(a.begin(), a.end());
        return;
    }
    a.clear();
    for (int i = 0; i < (int)up.size(); i++)
        a.push_back(up[i]);
    for (int i = down.size() - 2; i > 0; i--)
        a.push_back(down[i]);
}
```

## Bài tập thực hành

* [Kattis - Convex Hull](https://open.kattis.com/problems/convexhull)
* [Kattis - Keep the Parade Safe](https://open.kattis.com/problems/parade)
* [URI 1464 - Onion Layers](https://www.urionlinejudge.com.br/judge/en/problems/view/1464)
* [Timus 1185: Wall](http://acm.timus.ru/problem.aspx?space=1&num=1185)
* [Usaco 2014 January Contest, Gold - Cow Curling](http://usaco.org/index.php?page=viewproblem2&cpid=382)

---


