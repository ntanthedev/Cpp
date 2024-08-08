Tình trạng ùn tắc giao thông ở thành phố TPC ngày càng phức tạp, ảnh hưởng tới sự phát triển kinh tế. Vì vậy, TPC đã đưa ra đề án và tìm kiếm các giải pháp tốt nhất để giảm thiểu ùn tắc. Để giải quyết vấn đề này, đã có nhiều chuyên gia đóng góp những ý kiến quý báu. Là một chuyên gia lập trình, Nguyên đã đưa ra giải pháp nâng cấp một số con đường như sau:

Hiện tại, TPC có ~n~ nút giao thông, các nút giao thông được đánh số từ ~1~ tới ~n~. Các nút giao thông này được nối với nhau bởi các con đường hai chiều. Giữa hai nút giao thông bất kỳ luôn đảm bảo có đường đi trực tiếp hoặc gián tiếp nối chúng với nhau.

Đề án của Nguyên là cần giữ lại một số con đường trọng điểm sao cho tổng độ dài các con đường giữ lại là nhỏ nhất trên nguyên tắc giữa hai nút giao thông bất kỳ chỉ có duy nhất một con đường trực tiếp hoặc gián tiếp nối với nhau. Nhưng vì có thể có nhiều con đường có chiều dài bằng nhau nên Nguyên muốn đưa ra tất cả các phương án đó cho mọi người tham khảo và lựa chọn.

## Yêu cầu:
Hãy cùng Nguyên viết chương trình tính:
- Tổng chiều dài các con đường được giữ lại;
- Số phương án mà Nguyên đã đưa ra.

## Dữ liệu:

- Dòng đầu tiên gồm hai số nguyên dương ~n~ và ~m~, lần lượt là số nút giao thông và số con đường của TPC.
- ~m~ dòng tiếp theo, mỗi dòng gồm ba số nguyên dương ~a, b, w (1 ≤ a, b ≤ n; 1 ≤ w ≤ 10^6)~ – mô tả chiều dài con đường nối từ nút giao thông ~a~ đến nút giao thông ~b~ có chiều dài ~w~. Để số lượng phương án đưa ra không quá lớn, dữ liệu vào đảm bảo không có 4 con đường nào có chiều dài bằng nhau.

## Kết quả:

Ghi ra trên một dòng chứa hai số nguyên, số nguyên đầu tiên là tổng chiều dài ngắn nhất của các con đường được giữ lại, số nguyên thứ hai là phần dư khi chia số lượng phương án cho ~10^9 + 7~. Trong mỗi test, học sinh chỉ trả lời đúng câu ~a~ hoặc câu ~b~ thì được 50% số điểm của test đó (vẫn phải ghi đủ hai số).

## Sample input
```
4 5
1 2 1
3 4 1
1 3 2
1 4 2
2 3 2
```
## Sample ouput

```
4 3
```

## Ràng buộc:

- 50% số điểm có ~1 \le n, m \le 100;~
- 50% số điểm có ~n \le 4 × 10^4, m \le 10^5.~

