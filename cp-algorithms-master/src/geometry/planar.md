# Tìm kiếm các mặt của một đồ thị phẳng (planar graph)

---
tags:
  - Dịch
e_maxx_link: facets
---

# Tìm kiếm các mặt của một đồ thị phẳng

Xét một đồ thị $G$ với $n$ đỉnh và $m$ cạnh, có thể được vẽ trên một mặt phẳng sao cho hai cạnh chỉ giao nhau tại một đỉnh chung (nếu có).
Những đồ thị như vậy được gọi là **đồ thị phẳng** (planar graph). Bây giờ giả sử rằng chúng ta được cung cấp một đồ thị phẳng cùng với nhúng đường thẳng (straight-line embedding) của nó, nghĩa là đối với mỗi đỉnh $v$, chúng ta có một điểm tương ứng $(x, y)$ và tất cả các cạnh được vẽ dưới dạng các đoạn thẳng giữa các điểm này mà không có giao điểm (nhúng như vậy luôn tồn tại). Các đoạn thẳng này chia mặt phẳng thành một số vùng, được gọi là mặt (face). Chính xác một trong các mặt là không giới hạn. Khuôn mặt này được gọi là **bên ngoài** (outer), trong khi các khuôn mặt khác được gọi là **bên trong** (inner).

Trong bài viết này, chúng ta sẽ xử lý việc tìm kiếm cả mặt trong và mặt ngoài của đồ thị phẳng. Chúng ta sẽ giả sử rằng đồ thị được kết nối.

## Một số sự thật về đồ thị phẳng

Trong phần này, chúng ta trình bày một số sự thật về đồ thị phẳng mà không cần chứng minh. Độc giả quan tâm đến chứng minh nên tham khảo [Lý thuyết đồ thị của R. Diestel](https://sites.math.washington.edu/~billey/classes/562.winter.2018/articles/GraphTheory.pdf) hoặc một số sách khác.

### Định lý Euler
Định lý Euler phát biểu rằng bất kỳ nhúng chính xác nào của một đồ thị phẳng được kết nối với $n$ đỉnh, $m$ cạnh và $f$ mặt đều thỏa mãn:

$$n - m + f = 2$$

Và tổng quát hơn, mọi đồ thị phẳng có $k$ thành phần được kết nối đều thỏa mãn:

$$n - m + f = 1 + k$$

### Số cạnh của đồ thị phẳng.
Nếu $n \ge 3$ thì số cạnh tối đa của đồ thị phẳng có $n$ đỉnh là $3n - 6$. Số này đạt được bởi bất kỳ đồ thị phẳng được kết nối nào trong đó mỗi mặt được giới hạn bởi một tam giác. Về mặt độ phức tạp, thực tế này có nghĩa là $m = O(n)$ cho bất kỳ đồ thị phẳng nào.

### Số mặt của đồ thị phẳng.
Là hệ quả trực tiếp của thực tế trên, nếu $n \ge 3$ thì số mặt tối đa của đồ thị phẳng có $n$ đỉnh là $2n - 4$.

### Bậc đỉnh tối thiểu trong đồ thị phẳng.
Mọi đồ thị phẳng đều có một đỉnh có bậc 5 trở xuống.

## Thuật toán

Đầu tiên, sắp xếp các cạnh liền kề cho mỗi đỉnh theo góc cực.
Bây giờ hãy duyệt qua đồ thị theo cách sau. Giả sử rằng chúng ta đã vào đỉnh $u$ qua cạnh $(v, u)$ và $(u, w)$ là cạnh tiếp theo sau $(v, u)$ trong danh sách kề được sắp xếp của $u$. Sau đó, đỉnh tiếp theo sẽ là $w$. Hóa ra nếu chúng ta bắt đầu duyệt này ở một số cạnh $(v, u)$, chúng ta sẽ duyệt chính xác một trong các mặt liền kề với $(v, u)$, mặt chính xác phụ thuộc vào việc bước đầu tiên của chúng ta là từ $u$ đến $v$ hoặc từ $v$ đến $u$.

Bây giờ thuật toán khá rõ ràng. Chúng ta phải lặp lại tất cả các cạnh của đồ thị và bắt đầu duyệt cho mỗi cạnh chưa được truy cập bởi một trong các lần duyệt trước đó. Bằng cách này, chúng ta sẽ tìm thấy mỗi mặt chính xác một lần và mỗi cạnh sẽ được duyệt hai lần (một lần theo mỗi hướng).

### Tìm cạnh tiếp theo
Trong quá trình duyệt, chúng ta phải tìm cạnh tiếp theo theo thứ tự ngược chiều kim đồng hồ. Cách rõ ràng nhất để tìm cạnh tiếp theo là tìm kiếm nhị phân theo góc. Tuy nhiên, với thứ tự ngược chiều kim đồng hồ của các cạnh liền kề cho mỗi đỉnh, chúng ta có thể tính toán trước các cạnh tiếp theo và lưu trữ chúng trong một bảng băm. Nếu các cạnh đã được sắp xếp theo góc, độ phức tạp của việc tìm tất cả các mặt trong trường hợp này sẽ trở thành tuyến tính.

### Tìm mặt ngoài
Không khó để nhận thấy rằng thuật toán duyệt qua mỗi mặt trong theo thứ tự chiều kim đồng hồ và mặt ngoài theo thứ tự ngược chiều kim đồng hồ, vì vậy mặt ngoài có thể được tìm thấy bằng cách kiểm tra thứ tự của mỗi mặt.

### Độ phức tạp
Rõ ràng là độ phức tạp của thuật toán là $O(m \log m)$ do sắp xếp, và vì $m = O(n)$, nên thực tế là $O(n \log n)$. Như đã đề cập trước đó, nếu không sắp xếp thì độ phức tạp sẽ trở thành $O(n)$.

## Điều gì sẽ xảy ra nếu đồ thị không được kết nối?

Thoạt nhìn, có vẻ như việc tìm các mặt của một đồ thị không được kết nối không khó hơn nhiều bởi vì chúng ta có thể chạy cùng một thuật toán cho mỗi thành phần được kết nối. Tuy nhiên, các thành phần có thể được vẽ theo cách lồng nhau, tạo thành **lỗ** (xem hình ảnh bên dưới). Trong trường hợp này, mặt trong của một số thành phần trở thành mặt ngoài của một số thành phần khác và có đường viền ngắt kết nối phức tạp. Việc xử lý các trường hợp như vậy khá khó khăn, một cách tiếp cận khả thi là xác định các thành phần lồng nhau bằng thuật toán [định vị điểm](point-location.md).

<center>![Đồ thị phẳng có lỗ](planar_hole.png)</center>

## Triển khai
Cách triển khai sau trả về một vectơ các đỉnh cho mỗi mặt, mặt ngoài đi trước.
Các mặt trong được trả về theo thứ tự ngược chiều kim đồng hồ và mặt ngoài được trả về theo thứ tự chiều kim đồng hồ.

Để đơn giản, chúng ta tìm cạnh tiếp theo bằng cách thực hiện tìm kiếm nhị phân theo góc.
```{.cpp file=planar}
struct Point {
    int64_t x, y;

    Point(int64_t x_, int64_t y_): x(x_), y(y_) {}

    Point operator - (const Point & p) const {
        return Point(x - p.x, y - p.y);
    }

    int64_t cross (const Point & p) const {
        return x * p.y - y * p.x;
    }

    int64_t cross (const Point & p, const Point & q) const {
        return (p - *this).cross(q - *this);
    }

    int half () const {
        return int(y < 0 || (y == 0 && x < 0));
    }
};

std::vector<std::vector<size_t>> find_faces(std::vector<Point> vertices, std::vector<std::vector<size_t>> adj) {
    size_t n = vertices.size();
    std::vector<std::vector<char>> used(n);
    for (size_t i = 0; i < n; i++) {
        used[i].resize(adj[i].size());
        used[i].assign(adj[i].size(), 0);
        auto compare = [&](size_t l, size_t r) {
            Point pl = vertices[l] - vertices[i];
            Point pr = vertices[r] - vertices[i];
            if (pl.half() != pr.half())
                return pl.half() < pr.half();
            return pl.cross(pr) > 0;
        };
        std::sort(adj[i].begin(), adj[i].end(), compare);
    }
    std::vector<std::vector<size_t>> faces;
    for (size_t i = 0; i < n; i++) {
        for (size_t edge_id = 0; edge_id < adj[i].size(); edge_id++) {
            if (used[i][edge_id]) {
                continue;
            }
            std::vector<size_t> face;
            size_t v = i;
            size_t e = edge_id;
            while (!used[v][e]) {
                used[v][e] = true;
                face.push_back(v);
                size_t u = adj[v][e];
                size_t e1 = std::lower_bound(adj[u].begin(), adj[u].end(), v, [&](size_t l, size_t r) {
                    Point pl = vertices[l] - vertices[u];
                    Point pr = vertices[r] - vertices[u];
                    if (pl.half() != pr.half())
                        return pl.half() < pr.half();
                    return pl.cross(pr) > 0;
                }) - adj[u].begin() + 1;
                if (e1 == adj[u].size()) {
                    e1 = 0;
                }
                v = u;
                e = e1;
            }
            std::reverse(face.begin(), face.end());
            int sign = 0;
            for (size_t j = 0; j < face.size(); j++) {
                size_t j1 = (j + 1) % face.size();
                size_t j2 = (j + 2) % face.size();
                int64_t val = vertices[face[j]].cross(vertices[face[j1]], vertices[face[j2]]);
                if (val > 0) {
                    sign = 1;
                    break;
                } else if (val < 0) {
                    sign = -1;
                    break;
                }
            }
            if (sign <= 0) {
                faces.insert(faces.begin(), face);
            } else {
                faces.emplace_back(face);
            }
        }
    }
    return faces;
}
```

## Xây dựng đồ thị phẳng từ các đoạn thẳng

Đôi khi bạn không được cung cấp một đồ thị một cách rõ ràng, mà là một tập hợp các đoạn thẳng trên mặt phẳng và đồ thị thực tế được hình thành bằng cách giao nhau các đoạn thẳng đó, như trong hình bên dưới. Trong trường hợp này, bạn phải xây dựng đồ thị theo cách thủ công. Cách dễ nhất để làm như vậy như sau. Sửa một đoạn thẳng và giao nó với tất cả các đoạn thẳng khác. Sau đó, sắp xếp tất cả các điểm giao nhau cùng với hai điểm cuối của đoạn thẳng theo thứ tự từ điển và thêm chúng vào đồ thị dưới dạng các đỉnh. Ngoài ra, liên kết mỗi hai đỉnh liền kề theo thứ tự từ điển bằng một cạnh. Sau khi thực hiện thủ tục này cho tất cả các cạnh, chúng ta sẽ thu được đồ thị. Tất nhiên, chúng ta nên đảm bảo rằng hai điểm giao nhau bằng nhau sẽ luôn tương ứng với cùng một đỉnh. Cách dễ nhất để làm điều này là lưu trữ các điểm trong một _map_ (bản đồ) theo tọa độ của chúng, coi các điểm có tọa độ khác nhau một số nhỏ (giả sử, nhỏ hơn $10^{-9}$) là bằng nhau. Thuật toán này hoạt động trong $O(n^2 \log n)$.

<center>![Đồ thị được xác định ngầm](planar_implicit.png)</center>

## Triển khai
```{.cpp file=planar_implicit}
using dbl = long double;

const dbl eps = 1e-9;

struct Point {
    dbl x, y;

    Point(){}
    Point(dbl x_, dbl y_): x(x_), y(y_) {}

    Point operator * (dbl d) const {
        return Point(x * d, y * d);
    }

    Point operator + (const Point & p) const {
        return Point(x + p.x, y + p.y);
    }

    Point operator - (const Point & p) const {
        return Point(x - p.x, y - p.y);
    }

    dbl cross (const Point & p) const {
        return x * p.y - y * p.x;
    }

    dbl cross (const Point & p, const Point & q) const {
        return (p - *this).cross(q - *this);
    }

    dbl dot (const Point & p) const {
        return x * p.x + y * p.y;
    }

    dbl dot (const Point & p, const Point & q) const {
        return (p - *this).dot(q - *this);
    }

    bool operator < (const Point & p) const {
        if (fabs(x - p.x) < eps) {
            if (fabs(y - p.y) < eps) {
                return false;
            } else {
                return y < p.y;
            }
        } else {
            return x < p.x;
        }
    }

    bool operator == (const Point & p) const {
        return fabs(x - p.x) < eps && fabs(y - p.y) < eps;
    }

    bool operator >= (const Point & p) const {
        return !(*this < p);
    }
};

struct Line{
	Point p[2];

	Line(Point l, Point r){p[0] = l; p[1] = r;}
	Point& operator [](const int & i){return p[i];}
	const Point& operator[](const int & i)const{return p[i];}
	Line(const Line & l){
		p[0] = l.p[0]; p[1] = l.p[1];
	}
	Point getOrth()const{
		return Point(p[1].y - p[0].y, p[0].x - p[1].x);
	}
	bool hasPointLine(const Point & t)const{
		return std::fabs(p[0].cross(p[1], t)) < eps;
	}
	bool hasPointSeg(const Point & t)const{
		return hasPointLine(t) && t.dot(p[0], p[1]) < eps;
	}
};

std::vector<Point> interLineLine(Line l1, Line l2){
	if(std::fabs(l1.getOrth().cross(l2.getOrth())) < eps){
		if(l1.hasPointLine(l2[0]))return {l1[0], l1[1]};
		else return {};
	}
	Point u = l2[1] - l2[0];
	Point v = l1[1] - l1[0];
	dbl s = u.cross(l2[0] - l1[0])/u.cross(v);
	return {Point(l1[0] + v * s)};
}

std::vector<Point> interSegSeg(Line l1, Line l2){
	if (l1[0] == l1[1]) {
		if (l2[0] == l2[1]) {
			if (l1[0] == l2[0])
                return {l1[0]};
			else 
                return {};
		} else {
			if (l2.hasPointSeg(l1[0]))
                return {l1[0]};
			else
                return {};
		}
	}
	if (l2[0] == l2[1]) {
		if (l1.hasPointSeg(l2[0]))
            return {l2[0]};
		else 
            return {};
	}
	auto li = interLineLine(l1, l2);
	if (li.empty())
        return li;
	if (li.size() == 2) {
		if (l1[0] >= l1[1])
            std::swap(l1[0], l1[1]);
		if (l2[0] >= l2[1])
            std::swap(l2[0], l2[1]);
        std::vector<Point> res(2);
		if (l1[0] < l2[0])
            res[0] = l2[0];
        else
            res[0] = l1[0];
		if (l1[1] < l2[1])
            res[1] = l1[1];
        else
            res[1] = l2[1];
		if (res[0] == res[1])
            res.pop_back();
		if (res.size() == 2u && res[1] < res[0])
            return {};
		else 
            return res;
	}
	Point cand = li[0];
	if (l1.hasPointSeg(cand) && l2.hasPointSeg(cand))
        return {cand};
	else 
        return {};
}

std::pair<std::vector<Point>, std::vector<std::vector<size_t>>> build_graph(std::vector<Line> segments) {
    std::vector<Point> p;
    std::vector<std::vector<size_t>> adj;
    std::map<std::pair<int64_t, int64_t>, size_t> point_id;
    auto get_point_id = [&](Point pt) {
        auto repr = std::make_pair(
            int64_t(std::round(pt.x * 1000000000) + 1e-6),
            int64_t(std::round(pt.y * 1000000000) + 1e-6)
        );
        if (!point_id.count(repr)) {
            adj.emplace_back();
            size_t id = point_id.size();
            point_id[repr] = id;
            p.push_back(pt);
            return id;
        } else {
            return point_id[repr];
        }
    };
    for (size_t i = 0; i < segments.size(); i++) {
        std::vector<size_t> curr = {
            get_point_id(segments[i][0]),
            get_point_id(segments[i][1])
        };
        for (size_t j = 0; j < segments.size(); j++) {
            if (i == j)
                continue;
            auto inter = interSegSeg(segments[i], segments[j]);
            for (auto pt: inter) {
                curr.push_back(get_point_id(pt));
            }
        }
        std::sort(curr.begin(), curr.end(), [&](size_t l, size_t r) { return p[l] < p[r]; });
        curr.erase(std::unique(curr.begin(), curr.end()), curr.end());
        for (size_t j = 0; j + 1 < curr.size(); j++) {
            adj[curr[j]].push_back(curr[j + 1]);
            adj[curr[j + 1]].push_back(curr[j]);
        }
    }
    for (size_t i = 0; i < adj.size(); i++) {
        std::sort(adj[i].begin(), adj[i].end());
        // removing edges that were added multiple times
        adj[i].erase(std::unique(adj[i].begin(), adj[i].end()), adj[i].end());
    }
    return {p, adj};
}
```

## Bài tập
 * [TIMUS 1664 Pipeline Transportation](https://acm.timus.ru/problem.aspx?space=1&num=1664)
 * [TIMUS 1681 Brother Bear's Garden](https://acm.timus.ru/problem.aspx?space=1&num=1681)


---




