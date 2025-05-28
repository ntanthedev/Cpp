s = input("Nhập xâu s: ")

first_space = -1
last_space = -1

try:
    first_space = s.index(' ')
except ValueError:
    print("Không có dấu cách trong chuỗi")
else:
    try:
        last_space = s.rindex(' ')
    except ValueError:
        print("Không có dấu cách trong chuỗi")
    else:
        if first_space < last_space:
            middle_words = s[first_space + 1 : last_space]
            print(middle_words)
        else:
            print("")
