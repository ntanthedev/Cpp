Cho dãy ~A~ gồm ~n~ số nguyên dương ~a_1, a_2, \dots, a_n~ và một số nguyên dương ~x~. Cho ~q~ truy vấn có dạng ~l, r~.

## Yêu cầu:
Với mỗi truy vấn ~l, r~, hãy đếm số lượng các giá trị dương và nhỏ hơn ~x~ từ phần tử thứ ~l~ đến phần tử thứ ~r~ của dãy ~A~.

## Dữ liệu:
Vào từ file văn bản `COUNT.INP` có cấu trúc:
- Dòng thứ nhất ghi 3 số nguyên dương ~n, x, q~ ~(1 \leq n, x, q \leq 10^5)~;
- Dòng thứ hai ghi ~n~ số nguyên dương ~a_1, a_2, \dots, a_n~, số thứ ~i~ có giá trị là ~a_i~ ~(1 \leq i \leq n, |a_i| \leq 10^5)~;
- ~q~ dòng tiếp theo, mỗi dòng chứa hai số nguyên dương ~l, r~ ~(1 \leq l \leq r \leq 10^5)~.

Các số trên cùng một dòng ghi cách nhau một dấu cách.

## Kết quả:
Ghi ra file văn bản `COUNT.OUT` gồm ~q~ dòng, mỗi dòng ghi một số nguyên là kết quả tìm được tương ứng với mỗi truy vấn.

## Ràng buộc:
- Có 50% số test ứng với 50% số điểm có ~q = 1~;
- 50% số test còn lại ứng với 50% số điểm không có ràng buộc gì thêm.

## Ví dụ:
### COUNT.INP:
```
9 6 2
8 -1 6 5 -2 7 -3 4 -8
1 6
4 9
```

### COUNT.OUT:
```
1
2
```

## Giải thích: 
- Đoạn từ phần tử thứ 1 đến phần tử thứ 6 có 1 số là số dương và nhỏ hơn 6 là số 5.
- Đoạn từ phần tử thứ 4 đến phần tử thứ 9 có 2 số là số dương và nhỏ hơn 6 là số 5 à số 4.