import os
import random
import shutil
import time
be = 100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
ed = 10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
be_line = 50
ed_line = 200
def make(start:int,end:int):
    return random.randint(start,end)

for _test in range(76,86):
    try:
        content:str = ""
        with open("PSWGAME.inp","w+") as file:
            for _line in range(random.randint(be_line,ed_line)):
                content += f"{make(start=be,end=ed)} {make(start=be,end=ed)} {make(start=be,end=ed)} {make(start=be,end=ed)} \n"
            file.write(content)
            file.close()
        with open("PSWGAME.out","w") as file:
            file.close()
        #() {} = + - 
        os.mkdir(f"PSWGAME/test{_test}")
        os.system(".\code\PSWGAME.exe")
        time.sleep(4)
        shutil.move("PSWGAME.inp",f"PSWGAME/test{_test}/PSWGAME.inp")
        shutil.move("PSWGAME.out",f"PSWGAME/test{_test}/PSWGAME.out")
    except Exception as e:
        print(e)#thông báo lỗi nếu có