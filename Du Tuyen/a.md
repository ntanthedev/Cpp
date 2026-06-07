Ở Hà Tĩnh, đã nhắc đến quà quê mà quên kẹo cu đơ thì khác gì ăn bún bò mà quên ớt. Trước ngày đội tuyển học sinh giỏi lên đường đi thi, cô chủ lò cu đơ quyết định xếp các mẻ kẹo thành một hàng dài. Mẻ thứ ~i~ có độ ngon cơ bản ~a_i~. Nhưng đời không đơn giản: có hôm thêm lạc, có hôm thêm mật, cô phụ bếp "quá tay" nên một đoạn mẻ kẹo được tăng độ ngon đồng loạt. 

Sau mọi điều chỉnh, thầy giáo muốn chia toàn bộ dãy kẹo thành ít nhất ~M~ hộp quà liên tiếp, sao cho mỗi hộp đều có tổng độ ngon càng lớn càng tốt. Vì ai cũng muốn phần mình "không thua bạn ngồi cạnh", thầy yêu cầu giá trị nhỏ nhất trong các hộp quà phải được lớn nhất có thể. Nói ngắn gọn: hãy chia dãy thành ít nhất ~M~ đoạn liên tiếp, tối ưu hóa giá trị nhỏ nhất của tổng một đoạn.

**Đề bài:** Cho dãy ~N~ mẻ cu đơ. Ban đầu mẻ thứ ~i~ có độ ngon ~a_i~. Có ~Q~ lần điều chỉnh, mỗi lần cho ~l, r, v~, nghĩa là cộng ~v~ vào mọi phần tử từ ~l~ đến ~r~. Sau khi hoàn tất mọi điều chỉnh, thu được dãy ~b[1..N]~.

Hãy chia dãy ~b~ thành **ít nhất** ~M~ đoạn liên tiếp không rỗng. Gọi tổng của mỗi đoạn là độ ngon của hộp quà tương ứng. Tìm giá trị lớn nhất có thể của: ~\min(\text{tổng các đoạn})~ trong mọi cách chia hợp lệ.

## Input
Vào từ tệp `QUAQUE.INP`:
- Dòng 1: ~N, M, Q~ (~1 \le N \le 2 \cdot 10^5; 1 \le M \le N; 0 \le Q \le 2 \cdot 10^5~).
- Dòng 2: ~N~ số nguyên ~a_1, a_2, \dots, a_N~ (~0 \le a_i \le 10^9~).
- ~Q~ dòng tiếp theo: Mỗi dòng chứa ba số ~l, r, v~ (~0 \le v \le 10^9; 1 \le l \le r \le N~).

## Output
Ghi ra tệp `QUAQUE.OUT` một số nguyên duy nhất: giá trị lớn nhất của tổng nhỏ nhất có thể đạt được.

## Subtask
- **30% số điểm:** ~N \le 3000, Q \le 3000~.
- **40% số điểm:** ~N, Q \le 10^5~.
- **30% số điểm:** Không có ràng buộc gì thêm.

## Sample Input 1
```text
6 3 2
2 1 3 2 4 2
1 3 1
5 6 2
```

## Sample Output 1
```text
5
```
**Giải thích 1:**
Sau cập nhật, dãy thành: ~b =[3, 2, 4, 2, 6, 4]~.
Có thể chia thành 3 hộp: 
- `[3, 2]` tổng 5.
- `[4, 2]` tổng 6.
- `[6, 4]` tổng 10.
Giá trị nhỏ nhất là 5. Không thể đạt 6, vì khi đó không chia được ít nhất 3 đoạn đều có tổng từ 6 trở lên.

## Sample Input 2
```text
7 4 1
1 2 3 4 5 6 7
2 6 1
```

## Sample Output 2
```text
6
```
**Giải thích 2:**
Sau cập nhật: ~b =[1, 3, 4, 5, 6, 7, 7]~.
Một cách chia thành 4 đoạn: 
- `[1, 3, 4] = 8`
- `[5, 6] = 11`
- `[7] = 7`
- `[7] = 7`
Giá trị nhỏ nhất là 7? Chưa chắc tối ưu. Nếu thử ngưỡng 6, có thể chia được ít nhất 4 đoạn. Nếu thử ngưỡng 8, không đủ 4 đoạn. Kết quả tối ưu là 6.
