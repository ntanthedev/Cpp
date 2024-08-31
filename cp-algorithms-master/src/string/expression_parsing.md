# Phân tích biểu thức (Expression parsing)

---
tags:
  - Dịch
e_maxx_link: expressions_parsing
---

# Phân tích biểu thức (Expression parsing)

Cho một chuỗi chứa một biểu thức toán học chứa các số và các toán tử khác nhau.
Chúng ta phải tính toán giá trị của nó trong $O(n)$, trong đó $n$ là độ dài của chuỗi.

Thuật toán được thảo luận ở đây dịch một biểu thức sang cái gọi là **ký hiệu Ba Lan nghịch đảo** (reverse Polish notation) (một cách rõ ràng hoặc ngầm định), và đánh giá biểu thức này.

## Ký hiệu Ba Lan nghịch đảo

Ký hiệu Ba Lan nghịch đảo là một dạng viết các biểu thức toán học, trong đó các toán tử nằm sau các toán hạng của chúng.
Ví dụ: biểu thức sau

$$a + b * c * d + (e - f) * (g * h + i)$$

có thể được viết bằng ký hiệu Ba Lan nghịch đảo theo cách sau:

$$a b c * d * + e f - g h * i + * +$$

Ký hiệu Ba Lan nghịch đảo được phát triển bởi nhà triết học và chuyên gia khoa học máy tính người Úc Charles Hamblin vào giữa những năm 1950 dựa trên ký hiệu Ba Lan, được đề xuất vào năm 1920 bởi nhà toán học người Ba Lan Jan Łukasiewicz.

Sự tiện lợi của ký hiệu Ba Lan nghịch đảo là các biểu thức ở dạng này rất **dễ đánh giá** trong thời gian tuyến tính.
Chúng ta sử dụng một _stack_ (ngăn xếp), ban đầu trống.
Chúng ta sẽ lặp qua các toán hạng và toán tử của biểu thức trong ký hiệu Ba Lan nghịch đảo.
Nếu phần tử hiện tại là một số, thì chúng ta đặt giá trị lên trên cùng của _stack_, nếu phần tử hiện tại là một toán tử, thì chúng ta lấy hai phần tử trên cùng từ _stack_, thực hiện phép toán và đặt kết quả trở lại trên cùng của _stack_.
Cuối cùng, sẽ chỉ còn chính xác một phần tử trong _stack_, đó sẽ là giá trị của biểu thức.

Rõ ràng, việc đánh giá đơn giản này chạy trong thời gian $O(n)$.

## Phân tích các biểu thức đơn giản

Hiện tại, chúng ta chỉ xem xét một bài toán đơn giản hóa:
chúng ta giả sử rằng tất cả các toán tử là **nhị phân** (tức là chúng nhận hai đối số) và tất cả đều **kết hợp trái** (nếu các ưu tiên bằng nhau, chúng sẽ được thực thi từ trái sang phải).
Dấu ngoặc đơn được phép.

Chúng ta sẽ thiết lập hai _stack_: một cho số và một cho toán tử và dấu ngoặc đơn.
Ban đầu cả hai _stack_ đều trống.
Đối với _stack_ thứ hai, chúng ta sẽ duy trì điều kiện là tất cả các phép toán được sắp xếp theo thứ tự ưu tiên giảm dần nghiêm ngặt.
Nếu có dấu ngoặc đơn trên _stack_, thì mỗi khối toán tử (tương ứng với một cặp dấu ngoặc đơn) được sắp xếp và toàn bộ _stack_ không nhất thiết phải được sắp xếp.

Chúng ta sẽ lặp qua các ký tự của biểu thức từ trái sang phải.
Nếu ký tự hiện tại là một chữ số, thì chúng ta đặt giá trị của số này lên _stack_.
Nếu ký tự hiện tại là dấu ngoặc đơn mở, thì chúng ta đặt nó lên _stack_.
Nếu ký tự hiện tại là dấu ngoặc đơn đóng, thì chúng ta thực thi tất cả các toán tử trên _stack_ cho đến khi chúng ta đến dấu ngoặc đơn mở (nói cách khác, chúng ta thực hiện tất cả các phép toán bên trong dấu ngoặc đơn).
Cuối cùng, nếu ký tự hiện tại là một toán tử, thì trong khi đầu _stack_ có một toán tử có cùng hoặc cao hơn mức ưu tiên, chúng ta sẽ thực thi toán tử này và đặt toán tử mới lên _stack_.

Sau khi chúng ta đã xử lý toàn bộ chuỗi, một số toán tử có thể vẫn còn trong _stack_, vì vậy chúng ta thực thi chúng.

Đây là cách triển khai phương pháp này cho bốn toán tử $+$ $-$ $*$ $/$:

```{.cpp file=expression_parsing_simple}
bool delim(char c) {
    return c == ' ';
}

bool is_op(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int priority (char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return -1;
}

void process_op(stack<int>& st, char op) {
    int r = st.top(); st.pop();
    int l = st.top(); st.pop();
    switch (op) {
        case '+': st.push(l + r); break;
        case '-': st.push(l - r); break;
        case '*': st.push(l * r); break;
        case '/': st.push(l / r); break;
    }
}

int evaluate(string& s) {
    stack<int> st;
    stack<char> op;
    for (int i = 0; i < (int)s.size(); i++) {
        if (delim(s[i]))
            continue;
        
        if (s[i] == '(') {
            op.push('(');
        } else if (s[i] == ')') {
            while (op.top() != '(') {
                process_op(st, op.top());
                op.pop();
            }
            op.pop();
        } else if (is_op(s[i])) {
            char cur_op = s[i];
            while (!op.empty() && priority(op.top()) >= priority(cur_op)) {
                process_op(st, op.top());
                op.pop();
            }
            op.push(cur_op);
        } else {
            int number = 0;
            while (i < (int)s.size() && isalnum(s[i]))
                number = number * 10 + s[i++] - '0';
            --i;
            st.push(number);
        }
    }

    while (!op.empty()) {
        process_op(st, op.top());
        op.pop();
    }
    return st.top();
}
```

Như vậy, chúng ta đã học cách tính giá trị của một biểu thức trong $O(n)$, đồng thời chúng ta đã sử dụng ngầm định ký hiệu Ba Lan nghịch đảo.
Bằng cách sửa đổi một chút cách triển khai ở trên, cũng có thể thu được biểu thức trong ký hiệu Ba Lan nghịch đảo ở dạng rõ ràng.

## Toán tử đơn nhất

Bây giờ giả sử rằng biểu thức cũng chứa các toán tử **đơn nhất** (toán tử nhận một đối số).
Phép cộng đơn nhất và phép trừ đơn nhất là những ví dụ phổ biến về các toán tử như vậy.

Một trong những điểm khác biệt trong trường hợp này là chúng ta cần xác định xem toán tử hiện tại là toán tử đơn nhất hay toán tử nhị phân.

Bạn có thể nhận thấy rằng trước toán tử đơn nhất, luôn có một toán tử khác hoặc dấu ngoặc đơn mở hoặc không có gì cả (nếu nó ở ngay đầu biểu thức).
Ngược lại, trước toán tử nhị phân sẽ luôn có một toán hạng (số) hoặc dấu ngoặc đơn đóng.
Vì vậy, rất dễ dàng để gắn cờ cho biết toán tử tiếp theo có thể là toán tử đơn nhất hay không.

Ngoài ra, chúng ta cần thực thi toán tử đơn nhất và toán tử nhị phân khác nhau.
Và chúng ta cần chọn mức ưu tiên của toán tử đơn nhất cao hơn tất cả các toán tử nhị phân.

Ngoài ra, cần lưu ý rằng một số toán tử đơn nhất (ví dụ: phép cộng đơn nhất và phép trừ đơn nhất) thực sự là **kết hợp phải**.

## Kết hợp phải

Kết hợp phải có nghĩa là, bất cứ khi nào các mức ưu tiên bằng nhau, các toán tử phải được đánh giá từ phải sang trái.

Như đã lưu ý ở trên, các toán tử đơn nhất thường kết hợp phải.
Một ví dụ khác cho toán tử kết hợp phải là toán tử lũy thừa ($a \wedge b \wedge c$ thường được hiểu là $a^{b^c}$ chứ không phải là $(a^b)^c$).

Chúng ta cần thực hiện sự khác biệt nào để xử lý chính xác các toán tử kết hợp phải?
Hóa ra những thay đổi là rất nhỏ.
Sự khác biệt duy nhất sẽ là, nếu các mức ưu tiên bằng nhau, chúng ta sẽ hoãn việc thực thi phép toán kết hợp phải.

Dòng duy nhất cần được thay thế là
```cpp
while (!op.empty() && priority(op.top()) >= priority(cur_op))
```
với
```cpp
while (!op.empty() && (
        (left_assoc(cur_op) && priority(op.top()) >= priority(cur_op)) ||
        (!left_assoc(cur_op) && priority(op.top()) > priority(cur_op))
    ))
```
trong đó `left_assoc` là một hàm quyết định xem một toán tử có kết hợp trái hay không.

Dưới đây là cách triển khai cho các toán tử nhị phân $+$ $-$ $*$ $/$ và các toán tử đơn nhất $+$ và $-$.

```{.cpp file=expression_parsing_unary}
bool delim(char c) {
    return c == ' ';
}

bool is_op(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

bool is_unary(char c) {
    return c == '+' || c=='-';
}

int priority (char op) {
    if (op < 0) // toán tử đơn nhất
        return 3;
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return -1;
}

void process_op(stack<int>& st, char op) {
    if (op < 0) {
        int l = st.top(); st.pop();
        switch (-op) {
            case '+': st.push(l); break;
            case '-': st.push(-l); break;
        }
    } else {
        int r = st.top(); st.pop();
        int l = st.top(); st.pop();
        switch (op) {
            case '+': st.push(l + r); break;
            case '-': st.push(l - r); break;
            case '*': st.push(l * r); break;
            case '/': st.push(l / r); break;
        }
    }
}

int evaluate(string& s) {
    stack<int> st;
    stack<char> op;
    bool may_be_unary = true;
    for (int i = 0; i < (int)s.size(); i++) {
        if (delim(s[i]))
            continue;
        
        if (s[i] == '(') {
            op.push('(');
            may_be_unary = true;
        } else if (s[i] == ')') {
            while (op.top() != '(') {
                process_op(st, op.top());
                op.pop();
            }
            op.pop();
            may_be_unary = false;
        } else if (is_op(s[i])) {
            char cur_op = s[i];
            if (may_be_unary && is_unary(cur_op))
                cur_op = -cur_op;
            while (!op.empty() && (
                    (cur_op >= 0 && priority(op.top()) >= priority(cur_op)) ||
                    (cur_op < 0 && priority(op.top()) > priority(cur_op))
                )) {
                process_op(st, op.top());
                op.pop();
            }
            op.push(cur_op);
            may_be_unary = true;
        } else {
            int number = 0;
            while (i < (int)s.size() && isalnum(s[i]))
                number = number * 10 + s[i++] - '0';
            --i;
            st.push(number);
            may_be_unary = false;
        }
    }

    while (!op.empty()) {
        process_op(st, op.top());
        op.pop();
    }
    return st.top();
}
```



