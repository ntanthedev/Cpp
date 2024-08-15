---
tags:
  - Translated
e_maxx_link: mst_kruskal_with_dsu
---

# Cây khung nhỏ nhất - Kruskal với Disjoint Set Union

Để giải thích bài toán Cây khung nhỏ nhất (MST) và thuật toán Kruskal, trước tiên hãy xem [bài viết chính về thuật toán Kruskal](mst_kruskal.md).

Trong bài viết này, chúng ta sẽ xem xét cấu trúc dữ liệu ["Disjoint Set Union"](../data_structures/disjoint_set_union.md) để triển khai thuật toán Kruskal, điều này sẽ cho phép thuật toán đạt được độ phức tạp thời gian là $O(M \log N)$.

## Mô tả

Giống như trong phiên bản đơn giản của thuật toán Kruskal, chúng ta sắp xếp tất cả các cạnh của đồ thị theo thứ tự không giảm của trọng số.
Sau đó, đặt mỗi đỉnh vào cây riêng của nó (tức là tập hợp của nó) thông qua các lệnh gọi đến hàm `make_set` - nó sẽ mất tổng cộng $O(N)$.
Chúng ta lặp qua tất cả các cạnh (theo thứ tự đã sắp xếp) và đối với mỗi cạnh, xác định xem các đầu có thuộc về các cây khác nhau hay không (với hai lệnh gọi `find_set` trong $O(1)$ mỗi lần).
Cuối cùng, chúng ta cần thực hiện hợp nhất hai cây (tập hợp), mà hàm DSU `union_sets` sẽ được gọi - cũng trong $O(1)$.
Vì vậy, chúng ta có được độ phức tạp thời gian tổng cộng là $O(M \log N + N + M)$ = $O(M \log N)$.

## Triển khai

Đây là một triển khai của thuật toán Kruskal với Union by Rank.

```cpp
vector<int> parent, rank;

void make_set(int v) {
    parent[v] = v;
    rank[v] = 0;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }
}

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

int n;
vector<Edge> edges;

int cost = 0;
vector<Edge> result;
parent.resize(n);
rank.resize(n);
for (int i = 0; i < n; i++)
    make_set(i);

sort(edges.begin(), edges.end());

for (Edge e : edges) {
    if (find_set(e.u) != find_set(e.v)) {
        cost += e.weight;
        result.push_back(e);
        union_sets(e.u, e.v);
    }
}
```

Lưu ý: vì MST sẽ chứa chính xác $N-1$ cạnh, chúng ta có thể dừng vòng lặp for một khi chúng ta tìm thấy nhiều cạnh đó.

## Bài tập thực hành

Xem [bài viết chính về thuật toán Kruskal](mst_kruskal.md) để biết danh sách các bài tập thực hành về chủ đề này.
