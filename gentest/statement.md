# Chiến Dịch Quảng Cáo

Một công ty lên kế hoạch chạy quảng cáo trong ~N~ ngày tới. Nếu ngày thứ ~i~ có chạy quảng cáo, công ty thu được lợi nhuận là ~P_i~ (có thể âm do lỗ).

Công ty có thể tổ chức **nhiều đợt** quảng cáo. Tuy nhiên, để tối ưu hóa chi phí vận hành, mỗi đợt quảng cáo phải tuân thủ các quy tắc sau:

1. Mỗi đợt phải kéo dài liên tục **ít nhất ~L~ ngày** và **nhiều nhất ~R~ ngày**.
2. Mỗi khi bắt đầu một đợt quảng cáo, công ty phải trả một khoản phí cố định là ~C~.
3. Giữa hai đợt quảng cáo liên tiếp phải có **ít nhất ~D~ ngày nghỉ** (trong các ngày này không chạy quảng cáo).

Hãy lên lịch các đợt quảng cáo sao cho tổng lợi nhuận thu được là lớn nhất.

Lưu ý: công ty có thể chọn **không chạy đợt nào**, khi đó lợi nhuận là ~0~.

## Input

- Dòng đầu gồm 5 số nguyên ~N, L, R, C, D~.
- Dòng thứ hai gồm ~N~ số nguyên ~P_1, P_2, ..., P_N~.

## Output

- In ra một số nguyên duy nhất: tổng lợi nhuận lớn nhất có thể đạt được.

## Constraints

- ~1 <= L <= R <= N <= 10^5~
- ~0 <= C <= 10^9~
- ~0 <= D <= N~
- ~|P_i| <= 10^9~

Đáp án luôn nằm trong kiểu số nguyên có dấu 64-bit.

## Sample Input

```txt
8 2 3 5 1
10 -2 8 -1 7 5 -3 10
```~

## Sample Output

```txt
18
```

## Subtasks

* ~30%~ số test: ~N <= 500~
* ~30%~ số test: ~D = 0~ và ~C = 0~
* ~40%~ số test: không có ràng buộc gì thêm

## Note

Một phương án tối ưu là:

* Chạy đợt 1 từ ngày ~1~ đến ngày ~3~:

  * lợi nhuận thuần = ~(10 + (-2) + 8) - 5 = 11~
* Nghỉ ngày ~4~
* Chạy đợt 2 từ ngày ~5~ đến ngày ~6~:

  * lợi nhuận thuần = ~(7 + 5) - 5 = 7~

Tổng lợi nhuận là ~11 + 7 = 18~.

Không thể chỉ chạy ngày ~8~ thành một đợt riêng vì ~L = 2~, tức mỗi đợt phải kéo dài ít nhất 2 ngày.