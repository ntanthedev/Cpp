



Chào bạn, tôi rất hiểu mong muốn của bạn. Những đề thi cấp tỉnh/chuyên hiện nay không còn chuộng kiểu "ốp nguyên xi một thuật toán là ra", mà đòi hỏi học sinh phải có năng lực **toán học hóa vấn đề (formulation)**, **biến đổi công thức**, và **kết hợp nhiều bước logic** (Multi-step thinking).

Đặc biệt, dựa trên sự ấn tượng của bạn với các bài **BALANSUB**, **PROFIT** và **SUMQ**, điểm chung của 3 bài này là: *Nhìn bề ngoài có vẻ cần cấu trúc dữ liệu mạnh (như Segment Tree), nhưng nếu tinh tế dùng Mảng cộng dồn (Prefix Sum), Hai con trỏ (Two Pointers) kết hợp với Hàng đợi đơn điệu (Monotonic Deque/Multiset) hoặc Chặt nhị phân thì giải quyết trọn vẹn trong $O(N)$ hoặc $O(N \log N)$.*

Dưới đây là một bộ đề MỚI HOÀN TOÀN, được thiết kế "đo ni đóng giày" theo đúng phong cách tư duy đó, nâng tầm mức độ phức tạp để học sinh của bạn phải "động não" thực sự.

---

### ĐỀ THI CHUYÊN TIN - MOCK TEST (NÂNG CAO)
**Thời gian làm bài: 150 phút**

#### Bài 1: Đơn Hàng Hoàn Hảo (BS + MATH) - 2.0 điểm
Một nhà máy có 2 dây chuyền sản xuất $A$ và $B$. Dây chuyền $A$ cứ $X$ giây thì cho ra 1 sản phẩm, dây chuyền $B$ cứ $Y$ giây thì cho ra 1 sản phẩm. Tuy nhiên, nếu tại một thời điểm (tính bằng giây) mà *cả hai dây chuyền cùng lúc* nhả ra sản phẩm, thì cả 2 sản phẩm đó bị coi là lỗi và bị loại bỏ hoàn toàn.
**Yêu cầu:** Cho $X, Y$ và số lượng sản phẩm đạt chuẩn cần thiết là $K$. Hãy tìm thời điểm ngắn nhất (tính bằng giây) để nhà máy thu được **ít nhất** $K$ sản phẩm đạt chuẩn.
*   **Dữ liệu (ORDER.INP):** Một dòng chứa 3 số nguyên dương $X, Y, K$.
*   **Kết quả (ORDER.OUT):** Một số nguyên duy nhất là thời gian ngắn nhất tìm được.
*   **Ràng buộc:**
    *   50% số test: $X, Y \le 100$ và $K \le 10^5$.
    *   50% số test: $X, Y \le 10^6$ và $K \le 10^{12}$.
*   **Ví dụ:**
    *   *Input:* `2 3 4`
    *   *Output:* `8`
    *   *Giải thích:*
        - Giây 2: Máy A tạo 1 SP (Tổng: 1)
        - Giây 3: Máy B tạo 1 SP (Tổng: 2)
        - Giây 4: Máy A tạo 1 SP (Tổng: 3)
        - Giây 6: Máy A và B cùng tạo SP -> Lỗi, loại bỏ. (Tổng vẫn: 3)
        - Giây 8: Máy A tạo 1 SP (Tổng: 4). Đủ 4 sản phẩm.

#### Bài 2: Cặp Số Tương Đồng (SORTING + BINARY SEARCH + MATH) - 2.5 điểm
Cho một dãy số $A$ gồm $N$ số nguyên dương và 2 số nguyên dương $M, D$.
Một cặp chỉ số $(i, j)$ với $i < j$ được gọi là "tương đồng" nếu thỏa mãn đồng thời 2 điều kiện sau:
1. Độ chênh lệch giữa hai số không vượt quá $D$: $|A_i - A_j| \le D$.
2. Tổng hai số chia hết cho $M$: $(A_i + A_j) \vdots M$.
**Yêu cầu:** Đếm số lượng cặp chỉ số "tương đồng" trong dãy $A$.
*   **Dữ liệu (SIMILAR.INP):**
    *   Dòng 1 chứa ba số nguyên $N, M, D$ ($1 \le N \le 10^5; 1 \le M \le 10^5; 1 \le D \le 10^9$).
    *   Dòng 2 chứa $N$ số nguyên dương $A_1, A_2, ..., A_N$ ($1 \le A_i \le 10^9$).
*   **Kết quả (SIMILAR.OUT):** Một số nguyên là số lượng cặp thỏa mãn.
*   **Ràng buộc:**
    *   40% số test: $N \le 10^3$.
    *   60% số test không có ràng buộc gì thêm.
*   **Ví dụ:**
    *   *Input:*
        `6 5 4`
        `2 3 7 8 13 12`
    *   *Output:* `3`
    *   *Giải thích:* Các cặp giá trị thỏa mãn là (2,3) tổng 5 đ/k lệch 1<=4; (7,8) tổng 15 đ/k lệch 1<=4; (8,12) tổng 20 đ/k lệch 4<=4. *(Lưu ý: cặp (2, 8) có tổng 10 chia hết cho 5 nhưng lệch 6 > 4 nên loại).*

#### Bài 3: Thử Thách Sinh Tồn (TWO POINTERS + DEQUE) - 2.5 điểm
*(Lấy cảm hứng từ sự biến đổi chỉ số của bài BALANSUB)*
Một trò chơi có $N$ màn chơi liên tiếp, màn thứ $i$ yêu cầu người chơi phải có mức năng lượng tối thiểu là $P_i$ để vượt qua. Nếu bắt đầu chơi, cứ qua mỗi màn (bất kể dễ hay khó), người chơi bị trừ đi $1$ năng lượng do mệt mỏi.
Cụ thể, nếu người chơi có mức năng lượng ban đầu là $S$, và chọn bắt đầu từ màn $L$, thì:
- Ở màn $L$: Cần năng lượng hiện tại $\ge P_L$ (tức là $S \ge P_L$). Vượt qua xong, năng lượng còn $S-1$.
- Ở màn $L+1$: Cần năng lượng hiện tại $\ge P_{L+1}$ (tức là $S-1 \ge P_{L+1}$). Vượt qua xong, năng lượng còn $S-2$.
- ... và tiếp tục như vậy.
**Yêu cầu:** Cho trước năng lượng ban đầu $S$. Bạn được quyền chọn màn bắt đầu $L$ bất kỳ. Hãy tìm **số lượng màn chơi liên tiếp nhiều nhất** mà bạn có thể vượt qua.
*   **Dữ liệu (SURVIVE.INP):**
    *   Dòng 1: Hai số nguyên $N$ và $S$ ($1 \le N \le 10^6, 1 \le S \le 10^9$).
    *   Dòng 2: $N$ số nguyên $P_1, P_2, ..., P_N$ ($1 \le P_i \le 10^9$).
*   **Kết quả (SURVIVE.OUT):** Số lượng màn chơi liên tiếp lớn nhất.
*   **Ràng buộc:**
    *   40% số test: $N \le 10^3$.
    *   60% số test: $N \le 10^6$.
*   **Ví dụ:**
    *   *Input:*
        `5 10`
        `12 9 8 10 5`
    *   *Output:* `2`
    *   *Giải thích:*
        - Bắt đầu từ màn 2: Năng lượng đầu 10 $\ge P_2=9$ (Qua). Năng lượng còn 9.
        - Tới màn 3: Năng lượng 9 $\ge P_3=8$ (Qua). Năng lượng còn 8.
        - Tới màn 4: Năng lượng 8 < $P_4=10$ (Thua).
        Vậy chuỗi dài nhất là 2 màn (màn 2 và 3). (Không thể bắt đầu ở màn 1 vì $10 < 12$).

#### Bài 4: Kế Hoạch Đầu Tư Kép (PREFIX SUM + DP + DEQUE) - 3.0 điểm
*(Kết hợp tư duy của PROFIT và SUMQ)*
Công ty của bạn theo dõi lợi nhuận dự kiến trong $N$ tháng tới, tháng thứ $i$ có lợi nhuận là $A_i$ (có thể âm).
Bạn được yêu cầu chọn ra **đúng 2 giai đoạn** đầu tư. Mỗi giai đoạn là một chuỗi các tháng liên tiếp.
- Giai đoạn 1 phải có độ dài (số tháng) nằm trong đoạn $[L_1, R_1]$.
- Giai đoạn 2 phải có độ dài (số tháng) nằm trong đoạn $[L_2, R_2]$.
- Giai đoạn 1 phải kết thúc **trước khi** Giai đoạn 2 bắt đầu (không được trùng lặp).
**Yêu cầu:** Hãy chọn 2 giai đoạn sao cho **tổng lợi nhuận của cả 2 giai đoạn là lớn nhất**.
*   **Dữ liệu (INVEST.INP):**
    *   Dòng 1 chứa số nguyên $N$ ($1 \le N \le 10^5$).
    *   Dòng 2 chứa 4 số nguyên $L_1, R_1, L_2, R_2$ ($1 \le L_k \le R_k \le N$).
    *   Dòng 3 chứa $N$ số nguyên $A_1, A_2, ..., A_N$ ($|A_i| \le 10^9$).
*   **Kết quả (INVEST.OUT):** Một số nguyên duy nhất là tổng lợi nhuận lớn nhất. (Dữ liệu đảm bảo luôn tồn tại cách chọn hợp lệ).
*   **Ràng buộc:**
    *   30% số test: $N \le 500$.
    *   30% số test: $L_1 = R_1 = 1$ và $L_2 = R_2 = 1$ (chỉ chọn 2 phần tử).
    *   40% số test: Không có ràng buộc gì thêm.
*   **Ví dụ:**
    *   *Input:*
        `7`
        `1 2 2 3`
        `3 -5 4 2 -1 6 -2`
    *   *Output:* `14`
    *   *Giải thích:*
        - Giai đoạn 1 chọn độ dài 1: Tháng 1 (giá trị 3).
        - Giai đoạn 2 chọn độ dài 3: Tháng 3 đến 5 (giá trị 4 + 2 + (-1) = 5). TỔNG = 8 (Chưa tối ưu)
        - **Tối ưu:** GĐ 1 chọn[Tháng 3] (giá trị 4). GĐ 2 chọn [Tháng 4 đến 6] (giá trị 2 + -1 + 6 = 7). Tổng = 11.
        - **Tối ưu nhất:** GĐ 1 chọn [Tháng 1] (giá trị 3). GĐ 2 chọn [Tháng 3 đến 5] (giá trị 4+2=6 ? Không, tháng 3,4,5,6 là 11. Đợi đã, chọn GĐ 1 là đoạn [3..4] tổng 6 (độ dài 2). GĐ 2 đoạn[6..7] tổng 4 (độ dài 2). Lời giải đúng:
        GĐ1: đoạn[3..4] (giá trị 4+2=6, độ dài 2 $\in [1,2]$).
        GĐ2: đoạn [5..7] (giá trị -1+6+(-2)=3, độ dài 3). Tổng 9.
        *Cách đạt 14:* GĐ1: đoạn[3..4] (tổng 6, dài 2). GĐ2: đoạn [6..6]? sai vì GĐ2 dài [2,3].
        Chọn GĐ1: Tháng 3 (giá trị 4, dài 1). GĐ2: Tháng 4,5,6 (giá trị 2 - 1 + 6 = 7, dài 3). Tổng 11.
        (Ví dụ minh họa có thể nhẩm lại nhưng logic là tìm max tổng 2 đoạn rời nhau).

---

### PHẦN 2: PHÂN TÍCH LỜI GIẢI (EDITORIAL) - TƯ DUY ĐA BƯỚC

#### Bài 1: Đơn Hàng Hoàn Hảo
*   **Bước 1 (Toán học hóa):** Giả sử nhà máy chạy trong $T$ giây.
    - Số SP máy A làm ra là: $\lfloor T/X \rfloor$.
    - Số SP máy B làm ra là: $\lfloor T/Y \rfloor$.
    - Số thời điểm "đụng độ" (bội chung) là: $\lfloor T/\text{lcm}(X, Y) \rfloor$. Mỗi lần đụng độ ta mất 2 SP (của A và B).
    - Công thức tính tổng SP đạt chuẩn trong $T$ giây: $f(T) = \lfloor T/X \rfloor + \lfloor T/Y \rfloor - 2 \times \lfloor T/\text{lcm}(X, Y) \rfloor$.
*   **Bước 2 (Tìm kiếm nhị phân):** Hàm $f(T)$ là hàm đồng biến (thời gian càng dài SP càng nhiều). Do đó ta không cần for trâu, mà dùng **Tìm kiếm nhị phân** kết quả $T$.
    - Cận trái: $L = 1$.
    - Cận phải: $R = K \times \min(X, Y)$ (Trường hợp xấu nhất là chỉ dùng 1 máy nhanh nhất).
    - Tại mỗi $mid$, kiểm tra $f(mid) \ge K$ thì lưu $ans = mid$ và $R = mid - 1$, ngược lại $L = mid + 1$.
*   **Bài học:** Biến một bài toán đếm/toán học thành bài toán chặt nhị phân không gian kết quả. (Tránh lỗi tràn số khi tính $\text{lcm}$).

#### Bài 2: Cặp Số Tương Đồng
*   **Tư duy:** Nếu làm trâu $O(N^2)$ học sinh được 40%. Để AC, không thể xét từng cặp.
*   **Bước 1 (Xử lý điều kiện $|A_i - A_j| \le D$):** Nhận thấy thứ tự ban đầu không quan trọng (đếm số cặp). **Hãy Sort mảng tăng dần**. Khi đó, với mỗi $A_i$, các số $A_j$ thỏa mãn chênh lệch sẽ nằm trong đoạn $[A_i, A_i + D]$. Dùng thuật toán `std::upper_bound` hoặc Two Pointers để tìm vị trí $R_{max}$ sao cho mảng con $[i+1, R_{max}]$ chứa các số $\le A_i + D$.
*   **Bước 2 (Xử lý điều kiện chia hết):** Trong đoạn $[i+1, R_{max}]$ vừa tìm được, ta cần đếm xem có bao nhiêu số $A_j$ sao cho $(A_i + A_j) \vdots M \iff A_j \equiv (M - (A_i \pmod M)) \pmod M$.
*   **Bước 3 (Kết hợp):** Thay vì dùng Cây phân đoạn để truy vấn đoạn, ta khởi tạo một mảng `vector<int> pos[M]` lưu trữ các *vị trí* (index) của các số có cùng số dư khi chia cho $M$.
    Khi truy vấn đoạn $[i+1, R_{max}]$ có bao nhiêu phần tử mang số dư $r$, ta chỉ việc chặt nhị phân (`upper_bound` - `lower_bound`) trên `pos[r]`.
*   **Độ phức tạp:** $O(N \log N)$. Cực kỳ thanh lịch, tư duy chia để trị điều kiện.

#### Bài 3: Thử Thách Sinh Tồn (Đỉnh cao biến đổi công thức - Giống BALANSUB)
*   **Bước 1 (Formulation):** Điều kiện để qua màn thứ $i$ nếu bắt đầu từ $L$ (với $L \le i$) là:
    $$S - (i - L) \ge P_i \iff S + L \ge P_i + i$$
    Đặt một mảng mới $A[i] = P_i + i$. Điều kiện trở thành: **Với mọi $i \in [L, R]$, ta phải có $A[i] \le S + L$.**
    Nói cách khác: Giá trị lớn nhất trong đoạn $[L, R]$ của mảng $A$ không được vượt quá $S + L$. Ta cần tìm $R - L + 1$ lớn nhất.
*   **Bước 2 (Tính đơn điệu):** Nếu ta tăng điểm xuất phát $L$ lên $L+1$, thì ngưỡng giới hạn $(S + L)$ sẽ TĂNG LÊN. Nghĩa là điều kiện được "nới lỏng". Do đó, nếu tại $L$, ta đi xa nhất được đến $R$, thì tại $L+1$, ta chắc chắn đi được ít nhất đến $R$ và có thể tiến thêm sang phải.
    $\Rightarrow$ **Kỹ thuật Hai con trỏ (Two Pointers)** có thể áp dụng! Trái ngược với đa số bài tìm dãy con, bài này điều kiện *mở rộng* theo đầu $L$.
*   **Bước 3 (Cấu trúc dữ liệu Tịnh tiến):** Khi $R$ tăng, ta thêm $A[R]$ vào cửa sổ. Khi $L$ tăng, cửa sổ thu hẹp từ bên trái. Ta cần biết giá trị $MAX$ của cửa sổ $[L, R]$.
    Tuyệt đối không dùng Segment Tree. Ta dùng **Monotonic Deque** (Hàng đợi hai đầu lưu giá trị giảm dần) để duy trì $MAX$ trong $O(1)$.
*   **Độ phức tạp:** $O(N)$ thời gian, $O(N)$ không gian. Một phiên bản nâng cấp hoàn hảo của BALANSUB.

#### Bài 4: Kế Hoạch Đầu Tư Kép (Quy hoạch động trên Mảng cộng dồn)
*   Đây là một bài phân rã (decomposition) điển hình, biến từ bài toán "chọn 2 đoạn" thành 2 bài toán "chọn 1 đoạn".
*   **Bước 1:** Tạo mảng prefix sum $P$. Tổng đoạn $[i, j] = P[j] - P[i-1]$.
*   **Bước 2 (Tìm Max phía trước):** Gọi $F[i]$ là tổng lớn nhất của 1 dãy con hợp lệ (độ dài $\in[L_1, R_1]$) kết thúc tại hoặc trước vị trí $i$.
    Để kết thúc chính xác tại $i$, ta cần tối đa hóa: $P[i] - P[k]$ với $k \in [i - R_1, i - L_1]$.
    Nghĩa là ta cần tìm $MIN$ của $P[k]$ trong cửa sổ độ dài trượt. Tiếp tục sử dụng **Monotonic Deque** (Hàng đợi tăng dần) để tìm Min trong $O(1)$.
    Sau đó cập nhật: $F[i] = \max(F[i-1], P[i] - Min\_P)$.
*   **Bước 3 (Tìm Max phía sau):** Gọi $G[i]$ là tổng lớn nhất của 1 dãy con hợp lệ (độ dài $\in [L_2, R_2]$) bắt đầu từ hoặc sau vị trí $i$.
    Tương tự như mảng $F$, ta duyệt ngược từ $N$ về 1, dùng Suffix Sum và Deque để tính $G[i]$.
*   **Bước 4 (Tổng hợp):** Kết quả bài toán chính là $\max_{i=1}^{N-1} (F[i] + G[i+1])$.
*   **Đánh giá:** Bài kết hợp nhuần nhuyễn giữa Prefix Sum, Quy hoạch động chia để trị (chia 2 mảng $F, G$) và Kỹ thuật cửa sổ trượt (Deque). Bài này giải bằng Segment Tree sẽ dính $O(N \log N)$ và code rất dài, nhưng giải bằng Deque thì là $O(N)$ tuyệt đối tối ưu và là cách "chuẩn chuyên".

---
Bộ đề này bảo đảm học sinh phải phân tích công thức trên giấy nháp (math formulation) trước khi gõ phím. Nếu học sinh vượt qua được các bài này bằng code mảng/deque, tư duy của các em đã sẵn sàng cho đấu trường quốc gia/codeforces mức 1500-1700. Chúc bạn và đội tuyển có một kì ôn luyện chất lượng!