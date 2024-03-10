import pikepdf
import sys

path = sys.argv[1]

def crack(year, month):
    pwd = f"{i}@{str(j).rjust(2, '0')}"
    try:
        with pikepdf.open(path, password=pwd) as pdf:
            print(f'found {pwd}')
    except pikepdf.PasswordError as  e:
        pass
        #print(f'failed with {pwd}')

for i in range(2000, 2024):
    for j in range(1, 13):
        crack(i, j)

for i in range(00, 24):
    for j in range(1, 13):
        crack(str(i).rjust(2, '0'), j)
