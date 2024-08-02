Bạn được cho một chuỗi bao gồm ~ n ~ ký tự từ a–z. Các vị trí của chuỗi được đánh chỉ mục ~ 1,2,\dots,n ~.

Nhiệm vụ của bạn là xử lý ~ m ~ thao tác của các loại sau:

1. Thay đổi ký tự tại vị trí ~ k ~ thành ~ x ~
2. Kiểm tra xem chuỗi con từ vị trí ~ a ~ đến vị trí ~ b ~ có phải là một chuỗi đối xứng hay không

## Dữ liệu đầu vào

Dòng đầu tiên của dữ liệu đầu vào có hai số nguyên ~ n ~ và ~ m ~: độ dài của chuỗi và số lượng thao tác.

Dòng tiếp theo có một chuỗi bao gồm ~ n ~ ký tự.

Cuối cùng, có ~ m ~ dòng mô tả các thao tác. Mỗi dòng có dạng "1 ~ k ~ ~ x ~" hoặc "2 ~ a ~ ~ b ~".

## Dữ liệu đầu ra

Đối với mỗi thao tác 2, in ra YES nếu chuỗi con là một chuỗi đối xứng và NO nếu không.

## Ràng buộc

~ 1 \le n, m \le 2 \cdot 10^5 ~

~ 1 \le k \le n ~

~ 1 \le a \le b \le n ~

## Sample input 

```
7 5
aybabtu
2 3 5
1 3 x
2 3 5
1 5 x
2 3 5
```

## Sample output 
```
YES
NO
YES
```

