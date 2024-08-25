---
tags:
  - Original
---

# Định hướng mạnh

**Định hướng mạnh** của một đồ thị vô hướng là việc gán một hướng cho mỗi cạnh để biến nó thành một [đồ thị liên thông mạnh](strongly-connected-components.md).
Tức là, sau khi *định hướng*, chúng ta sẽ có thể truy cập bất kỳ đỉnh nào từ bất kỳ đỉnh nào bằng cách đi theo các cạnh có hướng.

## Giải pháp

Tất nhiên, điều này không thể được thực hiện với *mọi* đồ thị.
Hãy xem xét một [cầu nối](bridge-searching.md) trong một đồ thị.
Chúng ta phải gán một hướng cho nó và bằng cách làm như vậy, chúng ta làm cho cầu nối này "có thể đi qua" theo chỉ một hướng. Điều đó có nghĩa là chúng ta không thể đi từ một trong hai đầu của cầu nối đến đầu kia, vì vậy chúng ta không thể làm cho đồ thị liên thông mạnh.

Bây giờ hãy xem xét một [DFS](depth-first-search.md) thông qua một đồ thị liên thông không có cầu nối.
Rõ ràng, chúng ta sẽ truy cập từng đỉnh.
Và vì không có cầu nối, chúng ta có thể xóa bất kỳ cạnh cây DFS nào và vẫn có thể đi
từ bên dưới cạnh lên trên cạnh bằng cách sử dụng một đường dẫn chứa ít nhất một cạnh lùi.
Từ đó suy ra rằng từ bất kỳ đỉnh nào, chúng ta có thể đi đến gốc của cây DFS.
Ngoài ra, từ gốc của cây DFS, chúng ta có thể truy cập bất kỳ đỉnh nào chúng ta chọn.
Chúng ta đã tìm thấy một định hướng mạnh!

Nói cách khác, để định hướng mạnh một đồ thị liên thông không có cầu nối,
hãy chạy DFS trên nó và để các cạnh cây DFS hướng ra xa khỏi gốc DFS và
tất cả các cạnh khác từ con cháu đến tổ tiên trong cây DFS.

Kết quả cho thấy đồ thị liên thông không có cầu nối chính xác là các đồ thị có định hướng mạnh được gọi là **định lý Robbins**.

## Mở rộng bài toán

Hãy xem xét bài toán tìm định hướng đồ thị sao cho số lượng SCC là nhỏ nhất.

Tất nhiên, mỗi thành phần đồ thị có thể được xem xét riêng biệt.
Bây giờ, vì chỉ các đồ thị không có cầu nối mới có thể định hướng mạnh, hãy tạm thời loại bỏ tất cả các cầu nối.
Chúng ta kết thúc với một số thành phần không có cầu nối
(chính xác là *bao nhiêu thành phần có ở đầu* + *bao nhiêu cầu nối có*)
và chúng ta biết rằng chúng ta có thể định hướng mạnh từng thành phần trong số chúng.

Chúng ta chỉ được phép định hướng các cạnh, không được phép xóa chúng, nhưng hóa ra chúng ta có thể định hướng các cầu nối một cách tùy ý.
Tất nhiên, cách dễ nhất để định hướng chúng là chạy thuật toán được mô tả ở trên mà không cần sửa đổi trên mỗi thành phần liên thông ban đầu.

### Triển khai

Ở đây, đầu vào là *n* — số lượng đỉnh, *m* — số lượng cạnh, sau đó là *m* dòng mô tả các cạnh.

Đầu ra là số lượng SCC tối thiểu trên dòng đầu tiên và trên dòng thứ hai
là một chuỗi gồm *m* ký tự,
hoặc là `>` — cho chúng ta biết rằng cạnh tương ứng từ đầu vào
được định hướng từ đỉnh trái sang đỉnh phải (như trong đầu vào),
hoặc `<` — ngược lại.

Đây là một thuật toán tìm kiếm cầu nối được sửa đổi để cũng định hướng các cạnh,
bạn cũng có thể định hướng các cạnh như một bước đầu tiên và đếm các SCC trên đồ thị đã được định hướng như một bước thứ hai.

```cpp
vector<vector<pair<int, int>>> adj; // danh sách kề - các cặp đỉnh và cạnh
vector<pair<int, int>> edges;

vector<int> tin, low;
int bridge_cnt;
string orient;
vector<bool> edge_used;
void find_bridges(int v) {
	static int time = 0;
	low[v] = tin[v] = time++;
	for (auto p : adj[v]) {
		if (edge_used[p.second]) continue;
		edge_used[p.second] = true;
		orient[p.second] = v == edges[p.second].first ? '>' : '<';
		int nv = p.first;
		if (tin[nv] == -1) { // nếu nv chưa được truy cập
			find_bridges(nv);
			low[v] = min(low[v], low[nv]);
			if (low[nv] > tin[v]) {
				// một cầu nối giữa v và nv
				bridge_cnt++;
			}
		} else {
			low[v] = min(low[v], low[nv]);
		}
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	adj.resize(n);
	tin.resize(n, -1);
	low.resize(n, -1);
	orient.resize(m);
	edges.resize(m);
	edge_used.resize(m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--; b--;
		adj[a].push_back({b, i});
		adj[b].push_back({a, i});
		edges[i] = {a, b};
	}
	int comp_cnt = 0;
	for (int v = 0; v < n; v++) {
		if (tin[v] == -1) {
			comp_cnt++;
			find_bridges(v);
		}
	}
	printf("%d\n%s\n", comp_cnt + bridge_cnt, orient.c_str());
}
```

## Bài tập thực hành

* [26th Polish OI - Osiedla](https://szkopul.edu.pl/problemset/problem/nldsb4EW1YuZykBlf4lcZL1Y/site/)


