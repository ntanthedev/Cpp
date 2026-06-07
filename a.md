[](http://giangday.vst.edu.vn/)
  * [Demo](http://nnlt.vst.edu.vn)
  * [Editor](http://giangday.vst.edu.vn/lab/course/CPP?index=10&chapter=oop)
    * [C++ Shell](https://cpp.sh/)
    * [Programiz](https://www.programiz.com/javascript/online-compiler/)


###  Lập trình C/C++
**A** **A**
1
Giới thiệu C/C++
2
Các thành phần cơ bản
3
Biểu thức và toán tử
4
Cấu trúc rẽ nhánh
5
Các vòng lặp
6
Mảng
7
Con trỏ
8
Hàm
9
Kiểu có cấu trúc
10
Hướng đối tượng
11
Xếp chồng toán tử
12
Kế thừa
13
Bài tập tổng hợp
### 10. Hướng đối tượng
#### 10.1. Đặc điểm của lập trình hướng đối tượng
**Lớp** (_Class_) dùng để mô tả trừu tượng một sự vật trong thực tế gồm:
  * Các tính chất (thuộc tính);
  * Các hành vi (phương thức).


**Đối tượng** (_Object_) là một sự vật trong thực tế thuộc một lớp nào đó.
**Lập trình hướng đối tượng** (OOP) có các đặc điểm cơ bản sau:
  * **Tính đóng gói** (_Encapsulation_)
  * **Tính trừu tượng** (_Abstraction_)
  * **Tính đa hình** (_Polymorphism_)
  * **Tính kế thừa** (_Inheritance_)


**Thiết kế hướng đối tượng.** Để xây dựng chương trình theo phương pháp hướng đối tượng, cần thực hiện các bước cơ bản sau: 
  * Phân loại các đối tượng;
  * Xác định các thuộc tính và hành vi của từng loại đối tượng;
  * Xác định kịch bản hoạt động của chương trình;
  * Định nghĩa các lớp;
  * Khai báo các đối tượng để tham gia vào kịch bản của chương trình.


#### 10.2. Cấu trúc một lớp
```
_class_ tên_lớp {
_private_|_public_|_protected_: _// vùng truy cập_
  _// Các biến thành viên_
_public_:
  _// Các hàm khởi tạo và hàm hủy_
_private_|_public_|_protected_:
  _// Các hàm thành viên_
_public_:
  _// Các hàm toán tử_
};

```

**Hàm khởi tạo** (_Constructor_) có các tác dụng sau:
  * Thiết lập các giá trị ban đầu cho các biến thành viên;
  * Cấp phát bộ nhớ cho các mảng động.


Hàm khởi tạo sẽ được gọi trong các trường hợp sau:
  * Khai báo một đối tượng;
  * Cấp phát bộ nhớ cho một con trỏ bằng toán tử **new**.


Phân loại các hàm khởi tạo:
  * Hàm khởi tạo mặc định - không có tham số đầu vào.
  * Hàm khởi tạo thiết lập - có một hoặc nhiều tham số đầu vào. Khi tất cả các tham số là mặc định thì hàm này được coi là hàm khởi tạo mặc định. 
  * Hàm khởi tạo copy - có **một** tham số đầu vào là đối tượng cùng kiểu. Hàm khởi tạo copy là bắt buộc đối với các lớp có các biến thành viên dạng cấp phát động. 


**Hàm hủy** (_Destructor_) dùng để giải phóng bộ nhớ cho các biến thành viên dạng cấp phát động. 
Hàm hủy sẽ được gọi một cách tự động khi:
  * Kết thúc khối khai báo đối tượng.
  * Giải phóng bộ nhớ cho một con trỏ bằng toán tử **delete**.


**Các hàm thành viên** thực hiện các hành vi của đối tượng. Chúng thường xử lý ngay các biến thành viên của lớp. Những hàm mà khi thực thi không làm thay đổi giá trị các biến thành viên cần thêm từ khóa **const** vào trước thân hàm. 
**Các hàm toán tử** được định nghĩa để các đối tượng có thể đóng vai trò như các toán hạng trong các biểu thức. 
````
#include <iostream>
using namespace std;
class Coord {
public:
	int x; // hoành độ
	int y; // tung độ
public:
	Coord() { 
		x = y = 0;
		cout << "Default constructor: " << *this << endl;
	}
	Coord(int x, int y) {
		this->x = x;
		this->y = y;
		cout << "Initial constructor: " << *this << endl;
	}
	Coord(const Coord& coord)
		: x(coord.x)
		, y(coord.y) {
		
		cout << "Copy constructor: " << *this << endl;
	
	}
	~Coord() {
		cout << "Destructor constructor: " << *this << endl;
	}
public:
	void Offset(int d) { this->Offset(d, d); }
	void Offset(int x, int y);
	int Distance2() const { return x * x + y * y; }
		
public:
	friend ostream& operator<<(ostream& out, const Coord& coord) {
		return out << "x = " << coord.x << ", y = " << coord.y;
	}
};
void Coord::Offset(int x, int y) {
	this->x += x;
	this->y += y;
}
int main() {
	Coord p = new Coord();
	Coord p1(10, 10);
	Coord p2 = p1;
	p2.Offset(40);
	delete p;
}

```
`
**Biến static** được khai báo trong một lớp để sử dụng như một biến toàn cục. Có thể coi biến static như vùng dữ liệu chung của tất cả các đối tượng thuộc lớp đó. 
**Hàm static** được định nghĩa trong một lớp để sử dụng như một hàm toàn cục. Các hàm static chỉ được phép xử lý các biến static của lớp. 
**Một vài đặc thù**
  * Các hàm được định nghĩa ngay trong lớp là các hàm inline;
  * Các hàm cũng có thể được định nghĩa ngoài lớp. Khi đó, tên hàm cần kèm theo tên lớp, ```
_class_ Coord {
  ...
  _void_ Offset(_int_, _int_);
  ...
};
_void_ Coord::Offset(_int_ x, _int_ y) { ... }

```

  * Đối tượng là tham số của hàm cần khai báo dạng tham chiếu, ```
_class_ Coord {
  ...
  Coord(_const_ Coord& coord) { ... }
  ...
};

```

  * Các **biến static** cần khai báo như các biến toàn cục trong một file mã nguồn, ```
_// file Element.h_
_class_ Element {
  _static double_ frequency;
_public_:
  _static double_ Omega() { **return** 2 * 3.14 * frequency; }
};
_// file Element.cpp_
_double_ Element::frequency = 50;

```



#### 10.3. Lớp mảng động
````
#pragma once
class Array {
	int* data;  // mảng cấp phát động
	int capacity; // số phần tử
	void init(int size, const int* values);
	void dispose() {
		if (data) delete[] data;
	}
public:
	~Array() { dispose(); }
	
	Array() : data(0), capacity(0) { }
	Array(int capacity, const int* source = 0) {
		init(capacity, source);
	}
	Array(const Array& source) : data(0) {
		init(source.capacity, source.data);
	}
public:
	int Length() const { return capacity; }
public:
	int GetElement(int index) const { return data[index]; }
	void SetElement(int index, int value) { data[index] = value; }
public:
	Array& operator=(const Array& source) {
		dispose();
		init(source.capacity, source.data);
		return *this;
	}
};
```
` ````
#include "Array.h"
void Array::init(int size, const int* values) {
	data = new int[capacity = size];
	if (values) {
		for (int i = 0; i < size; i++) {
			data[i] = values[i];
		}
	}
}
```
`
#### 10.4. Lớp mẫu
**Lớp mẫu** (_Template_) là công cụ hỗ trợ người lập trình định nghĩa các lớp có cấu trúc giống nhau, chỉ có sự khác biệt về các kiểu biến. 
````
#pragma once
template <class T>
class Array {
	int* data;	// mảng cấp phát động
	int capacity;	// số phần tử
	void init(int size, const T* values);
	void dispose() {
		if (data) delete[] data;
	}
public:
	~Array() { dispose(); }
	
	Array() : data(0), capacity(0) { }
	Array(int capacity, const T* source = 0) {
		init(capacity, source);
	}
	Array(const Array& source) : data(0) {
		init(source.capacity, source.data);
	}
public:
	int Length() const { return capacity; }
public:
	T GetElement(int index) const { return data[index]; }
	void SetElement(int index, T value) { data[index] = value; }
public:
	Array& operator=(const Array& source) {
		dispose();
		init(source.capacity, source.data);
		return *this;
	}
};
template <class T>
void Array<T>::init(int size, const T* values) {
	data = new T[capacity = size];
	if (values) {
		for (int i = 0; i < size; i++) {
			data[i] = values[i];
		}
	}
}
```
` ````
#include "Array.h"
class Coord {
};
int main() {
	Array<int> A(5);
	Array<double> B(10);
	Array<Coord> points(4);
}
```
`
**[Thư viện mẫu chuẩn](https://www.geeksforgeeks.org/the-c-standard-template-library-stl/)**. C++ cung cấp các lớp chuẩn trong bộ thư viện STL:
Lớp mẫu| Ý nghĩa| #include  
---|---|---  
vector| Mảng động| <vector>  
list| Danh sách liên kết| <list>  
stack| Ngăn xếp| <stack>  
queue| Hàng đợi| <queue>  
map| Từ điển| <map>  
Ví dụ sử dụng các lớp trong STL:
````
#include <iostream>
#include <stack>
#include <string>
#include <list>
#include <map>
std::string dec2bin(int number) {
	std::stack<int> stack;
	do {
		stack.push(number % 2);
		number /= 2;
	} while (number);
	std::string s;
	while (!stack.empty()) {
		s += stack.top() + '0';
		stack.pop();
	}
	return s;
}
std::string dec2hex(int number) {
	std::list<char> stack;
	do {
		int d = number % 16;
		stack.push_front(d >= 10 ? d - 10 + 'A' : d + '0');
		number /= 16;
	} while (number);
	std::string s;
	for (auto c : stack) {
		s += c;
	}
	return s;
}
std::map<char, int> get_freq(const std::string& s) {
	std::map<char, int> dic;
	for (auto c : s) {
		auto item = dic.find(c);
		if (item == dic.end()) {
			dic[c] = 1;
		}
		else {
			(*item).second++;
		}
	}
	return dic;
}
int main() {
	std::cout << " 25 = 0b" << dec2bin(25) << std::endl;
	std::cout << "255 = 0x" << dec2hex(255) << std::endl;
	std::string input = "yyyy-MM-dd";
	auto res = get_freq(input);
	std::cout << "Characters in \"" << input << "\" are" << std::endl;
	for (auto item : res) {
		std::cout << item.first << ": " << item.second << std::endl;
	}
}
```
`
#### Câu hỏi trắc nghiệm
1
2
3
4
5
6
7
8
9
10
11
12
13
Đoạn chương trình dưới đây cho kết quả nào?` ```
class Value {  int _v; 
```
 ```
public: 
```
 ```
  Value(int v = 0) : _v(v) { }
```
 ```
  ~Value() { cout << _v; }
```
 ```
};
```
 ```
void main() { Value a(5), b; }
```
 `
A. 55
B. 00
C. 50
D. 05
Đoạn chương trình dưới đây gọi những hàm nào?` ```
class Value {  int _v; 
```
 ```
public: 
```
 ```
  Value(int v = 0) { _v = v; } 
```
 ```
  Value operator+(Value v) { return Value(_v + v._v); }
```
 ```
};
```
 ```
void main() { Value a, b = a + 1; } 
```
 `
A. Value(int)
B. Value operator+(Value)
C. Value operator=(Value)
D. Báo lỗi vì không có toán tử cộng với tham số kiểu int
Đoạn biểu thức sau xuất hiện lỗi ở dòng nào? ` ```
class Value {  int _v; 
```
 ```
public: 
```
 ```
  static int GetFactor(int a) { return _v * a; } //1 
```
 ```
  Value(int value) { _v = value; } //2 
```
 ```
}; 
```
 ```
void main() { 
```
 ```
  Value a(5), b(10);  //3 
```
 ```
  Value::GetFactor(2); //4
```
 ```
}
```
 `
A. //1
B. //2
C. //3
D. //4
Đoạn chương trình dưới đây cho kết quả nào?` ```
class Value {  int _v; 
```
 ```
public: 
```
 ```
  Value(int v = 0) : _v(v) { }
```
 ```
  ~Value() { cout << _v; }
```
 ```
};
```
 ```
void main() { Value a, b(5); }
```
 `
A. 05
B. 00
C. 50
D. 55
Đoạn chương trình dưới đây cho kết quả nào?` ```
class Value {  int _v; 
```
 ```
public: 
```
 ```
  Value(int v = 0) : _v(v) { }
```
 ```
  Value(Value &a) : _v(a._v) { }
```
 ```
  ~Value() { cout << _v; }
```
 ```
};
```
 ```
void main() { Value a(5), b(a); }
```
 `
A. 50
B. 00
C. 55
D. 05
Đoạn chương trình dưới đây gọi hàm nào?` ```
class Complex { double re, im;
```
 ```
public: 
```
 ```
  Complex() { re = im = 0; } 
```
 ```
  Complex(double r, double i = 0) : re(r), im(i) { } 
```
 ```
}; 
```
 ```
void main() { Complex Z(10); }
```
 `
A. Complex()
B. Complex(double)
C. Complex(double, double)
D. Sai cú pháp
Cho class sau: ` ```
class String { char * data; 
```
 ```
public: 
```
 ```
  String() { data = new char[1]; } 
```
 ```
  String(char c, int n) { 
```
 ```
    for (int i = 0; i < n; i++) data[i] = c; 
```
 ```
  } 
```
 ```
  static void Copy(char *dst, char *src) { 
```
 ```
    int i = 0; while (src[i]) dst[i] = src[i++]; 
```
 ```
    dst[i] = 0; 
```
 ```
  } 
```
 ```
}; 
```
 ```
void main() { 
```
 ```
  char s1[100], s2[]="Test"; 
```
 ```
  // Các biểu thức 
```
 ```
} 
```
 `Chương trình sẽ sinh ra lỗi khi chạy đến biểu thức nào? 
A. String a;
B. String b('0', 8);
C. String::Copy(s1, s2);
D. Cả 3 biểu thức trên
Những dòng nào sinh ra lỗi khi dịch đoạn chương trình dưới đây? ` ```
template <class _T, int n> class BaseItem { }; 
```
 ```
class NumberItem : public BaseItem<int, 5> { }; // 1 
```
 ```
void main() { 
```
 ```
  BaseItem<int, int> i;   // 2 
```
 ```
  BaseItem<double, 1.0> d; // 3
```
 ```
}
```
 `
A. // 1
B. // 2
C. // 3
D. Cả 3 phương án trên
Cho class sau: ` ```
class String { char * data; 
```
 ```
public: 
```
 ```
  String() { data = new char[1]; } 
```
 ```
  String(char c, int n) { 
```
 ```
    data = new char[n+1];
```
 ```
    for (int i = 0; i < n; i++) data[i] = c;
```
 ```
  }
```
 ```
  static void Copy(char *dst, char *src) { 
```
 ```
    int i = 0; while (src[i]) dst[i] = src[i++]; 
```
 ```
    dst[i] = 0; } 
```
 ```
}; 
```
 ```
void main() { 
```
 ```
  char s1[10], s2[]="Kiem tra \"Ngon ngu lap trinh\""; 
```
 ```
  // Các biểu thức
```
 ```
} 
```
 `Chương trình sẽ sinh ra lỗi khi chạy đến biểu thức nào? 
A. String a;
B. String b('0', 8);
C. String::Copy(s1, s2);
D. Cả 3 biểu thức trên
Cho Đoạn chương trình dưới đây gọi những hàm nào?` ```
class Complex { double re, im; 
```
 ```
public: 
```
 ```
  Complex(double r = 0, double i = 0) : re(r), im(i) { } 
```
 ```
  friend Complex operator+(const Complex &a, const Complex &b); 
```
 ```
}; 
```
 ```
void main() { Complex Z(10, 5), Z1 = Z + 5; }
```
 `
A. Complex operator+(const Complex&, const Complex&)
B. Complex Complex::operator+(const Complex&, const Complex&)
C. Complex::Complex(double, double)
D. Không có toán tử cộng với số nguyên
Cho các class sau: ` ```
class LogicElement { protected: int input; 
```
 ```
public: 
```
 ```
  LogicElement() : input(0) { } 
```
 ```
  virtual int Output() = 0; 
```
 ```
}; 
```
 ```
class LogicAnd : public LogicElement { 
```
 ```
public: 
```
 ```
  int Output(); 
```
 ```
}; 
```
 `Những biểu thức nào có thể dùng trong hàm int LogicAnd::Output()? 
A. LogicElement *pElem = new LogicAnd();
B. LogicElement *pElem = new LogicElement();
C. LogicElement *pElem;
D. LogicElement element;
Cho biết kết quả của đoạn chương trình dưới đây?` ```
class Value { int _v; 
```
 ```
public: 
```
 ```
  Value(int a): _v(a) { } 
```
 ```
  virtual void Print() { cout << _v; } 
```
 ```
}; 
```
 ```
class ExtValue : public Value { int _u; 
```
 ```
public: 
```
 ```
  ExtValue(int a, int b) : Value(a), _u(b * b) { } 
```
 ```
  void Print() { Value::Print(); cout << _u; }
```
 ```
}; 
```
 ```
void main() { ExtValue v(1, 2); v.Print(); }
```
 `
A. 41
B. 12
C. 21
D. 14
Cho biết kết quả của đoạn chương trình dưới đây?` ```
class Value { int _v; 
```
 ```
public: 
```
 ```
  Value(int a): _v(a) { } 
```
 ```
  virtual void Print() { cout << _v; } 
```
 ```
}; 
```
 ```
class ExtValue : public Value { int _u; 
```
 ```
public: 
```
 ```
  ExtValue(int a, int b) : Value(a), _u(b * b) { } 
```
 ```
  void Print() { cout << _u; Value::Print(); }
```
 ```
}; 
```
 ```
void main() { ExtValue v(1, 2); v.Print(); }
```
 `
A. 14
B. 21
C. 41
D. 12
Kết thúc
