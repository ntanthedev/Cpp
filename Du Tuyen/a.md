Bạn phải hoàn thành ~n~ khóa học. Có ~m~ yêu cầu dưới dạng "khóa học ~a~ phải được hoàn thành trước khóa học ~b~". Nhiệm vụ của bạn là tìm một thứ tự mà bạn có thể hoàn thành các khóa học.

## Input

Dòng đầu tiên của đầu vào có hai số nguyên ~n~ và ~m~: số lượng khóa học và yêu cầu. Các khóa học được đánh số ~1,2,\dots,n~.

Sau đó, có ~m~ dòng mô tả các yêu cầu. Mỗi dòng có hai số nguyên ~a~ và ~b~: khóa học ~a~ phải được hoàn thành trước khóa học ~b~.

## Output

In một thứ tự mà bạn có thể hoàn thành các khóa học. Bạn có thể in bất kỳ thứ tự hợp lệ nào bao gồm tất cả các khóa học.

Nếu không có giải pháp nào, hãy in "KHÔNG THỂ".

## Ràng buộc

- ~ 1 \le n \le 10^5 ~
- ~ 1 \le m \le 2 \cdot 10^5 ~
- ~ 1 \le a,b \le n ~

## Ví dụ

| Input    | Output       |
|----------|--------------|
| 5 3      | 3 4 1 5 2    |
| 1 2      | 3 1          |
| 4 5      |              |
