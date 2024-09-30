Cho một dãy số ~A~ gồm ~n~ số nguyên dương ~a_1, a_2, ..., a_n~, mỗi số có giá trị không quá ~10^9~. Một dãy con từ ~l~ đến ~r~ (~l \leq r~) được gọi là một dãy cân bằng nếu ~a_l \geq 1~, ~a_{l+1} \geq 2~, ..., ~a_r \geq (r - l + 1)~. Hãy xác định độ dài dãy con cân bằng dài nhất của dãy số đã cho.

Dữ liệu vào từ tệp văn bản `BALANSUB.INP` có cấu trúc:
- Dòng đầu tiên gồm duy nhất một số nguyên dương ~n~ (~1 \leq n \leq 10^5~);
- Dòng thứ hai gồm ~n~ số nguyên dương ~a_1, a_2, \dots, a_n~ được ghi cách nhau ít nhất một dấu cách.

Dữ liệu ra ghi vào tệp văn bản `BALANSUB.OUT` một số duy nhất là độ dài dãy con tìm được.

### Ràng buộc:
- Có 35\% số test ứng với 35\% số điểm của bài có ~n \leq 200~;
- 15\% số test ứng với 15\% số điểm của bài có ~n \leq 5 \times 10^3~;
- 50\% số test còn lại ứng với 50\% số điểm không có ràng buộc gì thêm.

### Ví dụ:

| BALANSUB.INP | BALANSUB.OUT | Giải thích                             |
|--------------|--------------|----------------------------------------|
| 6            | 4            | Dãy con cân bằng là ~1, 4, 3, 6~.      |
|--------------|--------------|                                        |
| 2 1 1 4 3 6  |              | ~l = 3~, ~r = 6~ và độ dài bằng 4.     |
