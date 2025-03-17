Tam giác là một khái niệm cơ bản trong hình học phẳng. Với 3 số nguyên dương ~x, y, z~ có thể tạo thành độ dài 3 cạnh của một tam giác nếu và chỉ nếu 3 điều kiện sau đồng thời thỏa mãn:
~x + y > z~; ~x + z > y~; ~y + z > x~.

## Yêu cầu:  
Cho dãy ~A~ gồm ~n~ số nguyên dương ~a_1, a_2, ..., a_n~. Hãy tìm dãy con liên tiếp dài nhất sao cho khi chọn 3 phần tử bất kỳ trong dãy con đó luôn tạo thành độ dài 3 cạnh của một tam giác.

## Dữ liệu:  
Vào từ file văn bản **CTRIA.INP**:

*   Dòng đầu tiên chứa số nguyên dương ~n~ (~n \le 10^6~);
*   Dòng thứ hai chứa ~n~ số nguyên dương ~a_1, a_2, ..., a_n~ (~1 \le i \le n, a_i \le 10^9~).

## Kết quả:  
Ghi ra file văn bản **CTRIA.OUT** một số nguyên duy nhất là độ dài của dãy con liên tiếp dài nhất tìm được thỏa mãn yêu cầu.

## Ràng buộc:

*   Có ~30\%~ số test ứng với ~30\%~ số điểm của bài thỏa mãn: ~n \le 20~;
*   ~30\%~ số test khác ứng với ~30\%~ số điểm của bài thỏa mãn: ~n \le 10^3~;
*   ~20\%~ số test khác ứng với ~20\%~ số điểm của bài thỏa mãn: ~n \le 10^5~;
*   ~20\%~ số test khác ứng với ~20\%~ số điểm còn lại của bài thỏa mãn: ~n \le 10^6, a_1 \le a_2 \le ... \le a_n~.

## Ví dụ:

**CTRIA.INP**
```
8
8 6 2 5 6 5 8 3
```
**CTRIA.OUT**
```
5
```
**Giải thích**
Dãy con liên tiếp dài nhất thỏa mãn là: ~6 \ 2 \ 5 \ 6 \ 5~ có 3 phần tử bất kỳ luôn tạo thành độ dài 3 cạnh của một tam giác.