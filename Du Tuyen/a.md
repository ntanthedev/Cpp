<<<<<<< HEAD
Có một mảng gồm ~ n ~ số nguyên. Một số giá trị của mảng sẽ được cập nhật, và sau mỗi lần cập nhật, nhiệm vụ của bạn là báo cáo tổng dãy con lớn nhất trong mảng.

# Đầu vào

Dòng đầu tiên chứa số nguyên ~ n ~ và ~ m ~: kích thước của mảng và số lần cập nhật. Mảng được đánh chỉ mục từ ~ 1,2,\ldots,n ~. 

Dòng tiếp theo có ~ n ~ số nguyên: ~ x_1,x_2,\ldots,x_n ~: nội dung ban đầu của mảng. 

Sau đó là ~ m ~ dòng mô tả các thay đổi. Mỗi dòng có hai số nguyên ~ k ~ và ~ x ~: giá trị tại vị trí ~ k ~ trở thành ~ x ~.

# Đầu ra

Sau mỗi lần cập nhật, in ra tổng dãy con lớn nhất. Các dãy con rỗng (có tổng ~ 0 ~) được cho phép.
=======
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
>>>>>>> c7e76b725856ffdaf47cdbebfbc87e10154cfe18

# Ràng buộc

<<<<<<< HEAD
- ~ 1 \le n, m \le 2 \cdot 10^5 ~
- ~ -10^9 \le x_i \le 10^9 ~
- ~ 1 \le k \le n ~
- ~ -10^9 \le x \le 10^9 ~

# Sample input 1
```
5 3
1 2 -3 5 -1
2 6
3 1
2 -2
```
# Sample output 1
```
9
13
6
```
=======
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

>>>>>>> c7e76b725856ffdaf47cdbebfbc87e10154cfe18
