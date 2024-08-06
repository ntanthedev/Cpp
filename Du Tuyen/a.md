Cho $Q$ truy vấn, mỗi truy vấn có dạng một số nguyên $n$, tìm tất cả các ước nguyên tố của $n$.

## Input:

Vào từ tệp văn bản **ERAPRIME.INP** theo cấu trúc:
- Dòng đầu tiên là số nguyên $Q$ $(1 \leq Q \leq 5 \times 10^5)$
- $Q$ dòng tiếp theo, mỗi dòng gồm một số nguyên $n$ $(2 \leq n \leq 10^9)$

## Ouput:

Ghi ra file văn bản **ERAPRIME.OUT** gồm $Q$ dòng, dòng thứ $i$ là tổng số lượng các ước nguyên tố của truy vấn thứ $i$.

## Ví dụ

### ERAPRIME.INP
```
2
9
24
```
### ERAPRIME.OUT
```
3
2 3
```
## Ràng buộc:
- Có 30% số test ứng với 30% số điểm với $Q \leq 10$ và $n \leq 10^9$.
- Có 40% số test ứng với 40% số điểm với $Q \leq 10^5$ và $n \leq 10^4$.
- Có 30% số test ứng với 30% số điểm với $Q \leq 5 \times 10^5$ và $n \leq 10^6$.