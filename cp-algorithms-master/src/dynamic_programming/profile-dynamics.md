# Quy hoạch động trên Profile gãy. Bài toán "Parquet"

---
tags:
  - Dịch
e_maxx_link: profile_dynamics
---

# Quy hoạch động trên Profile gãy (Broken Profile). Bài toán "Parquet"

Các bài toán phổ biến được giải quyết bằng quy hoạch động (DP) trên profile gãy bao gồm:

- tìm số cách lấp đầy hoàn toàn một khu vực (ví dụ: bàn cờ/lưới) bằng một số hình (ví dụ: domino)
- tìm cách lấp đầy một khu vực với số lượng hình tối thiểu
- tìm một cách lấp đầy một phần với số lượng không gian (hoặc ô, trong trường hợp lưới) chưa được lấp đầy tối thiểu
- tìm một cách lấp đầy một phần với số lượng hình tối thiểu, sao cho không thể thêm hình nào nữa

## Bài toán "Parquet"

**Mô tả bài toán.** Cho một lưới có kích thước $N \times M$. Tìm số cách lấp đầy lưới bằng các hình có kích thước $2 \times 1$ (không được để trống ô nào và các hình không được chồng lên nhau).

Gọi trạng thái DP là: $dp[i, mask]$, trong đó $i = 1, \ldots N$ và $mask = 0, \ldots 2^M - 1$.

$i$ biểu thị số hàng trong lưới hiện tại và $mask$ là trạng thái của hàng cuối cùng của lưới hiện tại. Nếu bit thứ $j$ của $mask$ là $0$ thì ô tương ứng được lấp đầy, ngược lại thì nó không được lấp đầy.

Rõ ràng, câu trả lời cho bài toán sẽ là $dp[N, 0]$.

Chúng ta sẽ xây dựng trạng thái DP bằng cách lặp qua mỗi $i = 1, \cdots N$ và mỗi $mask = 0, \ldots 2^M - 1$, và đối với mỗi $mask$, chúng ta sẽ chỉ chuyển tiếp, nghĩa là chúng ta sẽ _thêm_ các hình vào lưới hiện tại.

### Triển khai

```cpp
int n, m;
vector < vector<long long> > dp;


void calc (int x = 0, int y = 0, int mask = 0, int next_mask = 0)
{
	if (x == n)
		return;
	if (y >= m)
		dp[x+1][next_mask] += dp[x][mask];
	else
	{
		int my_mask = 1 << y;
		if (mask & my_mask)
			calc (x, y+1, mask, next_mask);
		else
		{
			calc (x, y+1, mask, next_mask | my_mask);
			if (y+1 < m && ! (mask & my_mask) && ! (mask & (my_mask << 1)))
				calc (x, y+2, mask, next_mask);
		}
	}
}


int main()
{
	cin >> n >> m;

	dp.resize (n+1, vector<long long> (1<<m));
	dp[0][0] = 1;
	for (int x=0; x<n; ++x)
		for (int mask=0; mask<(1<<m); ++mask)
			calc (x, 0, mask, 0);

	cout << dp[n][0];

}
```

## Bài tập thực hành

- [UVA 10359 - Tiling](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1300)
- [UVA 10918 - Tri Tiling](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1859)
- [SPOJ GNY07H (Four Tiling)](https://www.spoj.com/problems/GNY07H/)
- [SPOJ M5TILE (Five Tiling)](https://www.spoj.com/problems/M5TILE/)
- [SPOJ MNTILE (MxN Tiling)](https://www.spoj.com/problems/MNTILE/)
- [SPOJ DOJ1](https://www.spoj.com/problems/DOJ1/)
- [SPOJ DOJ2](https://www.spoj.com/problems/DOJ2/)
- [SPOJ BTCODE_J](https://www.spoj.com/problems/BTCODE_J/)
- [SPOJ PBOARD](https://www.spoj.com/problems/PBOARD/)
- [ACM HDU 4285 - Circuits](http://acm.hdu.edu.cn/showproblem.php?pid=4285)
- [LiveArchive 4608 - Mosaic](https://vjudge.net/problem/UVALive-4608)
- [Timus 1519 - Formula 1](https://acm.timus.ru/problem.aspx?space=1&num=1519)
- [Codeforces Parquet](https://codeforces.com/problemset/problem/26/C)

## Tài liệu tham khảo

- [Blog của EvilBunny](https://web.archive.org/web/20180712171735/https://blog.evilbuggy.com/2018/05/broken-profile-dynamic-programming.html)
- [Công thức TopCoder của "syg96"](https://apps.topcoder.com/forums/?module=Thread&start=0&threadID=697369)
- [Bài đăng trên blog của sk765](http://sk765.blogspot.com/2012/02/dynamic-programming-with-profile.html)

---
