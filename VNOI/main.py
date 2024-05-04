'''
MIT License

Copyright (c) 2023 iotran207

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

AUTHOR King.#4732
'''
import os
import random
import shutil
import time
import sys

def make_random(start:int,end:int) -> int:
    return random.randint(start,end)
    
def make_input(file_name:str,start_line:int,end_line:int,start_random:int,end_random:int) -> None:
    content:str = ""
    with open(f"{file_name}.inp","w+") as file:
        for _line in range(random.randint(start_line,end_line)):
            content += f"{make_random(start=start_random,end=end_random)} {make_random(start=start_random,end=end_random)} {make_random(start=start_random,end=end_random)} {make_random(start=start_random,end=end_random)}\n"
        file.write(content)
        file.close()

if __name__ == "__main__":
    mode:int = 2
    if(mode == 1):
        be_line:int = 1
        ed_line:int = 2
        be_random:int = 100
        ed_random:int = 9999
        file_name = "code"
        try:
            for _test in range(1,26):
                make_input(file_name=file_name,start_line=be_line,end_line=ed_line,start_random=be_random,end_random=ed_random)
                with open(f"{file_name}.out","w") as file:
                    file.close()
                if(os.path.exists(f"out/{file_name}") == False):
                    os.mkdir(f"out/{file_name}")
                if(os.path.exists(f"out/test{_test}") == False):
                    os.mkdir(f"out/test{_test}")
                os.system(f".\code\compile\{file_name}.exe")
                time.sleep(2)
                shutil.move(f"{file_name}.inp",f"out/test{_test}/{file_name}.inp")
                shutil.move(f"{file_name}.out",f"out/test{_test}/{file_name}.out")
        except Exception as error:
            exc_type, exc_obj, exc_tb = sys.exc_info()
            fname = os.path.split(exc_tb.tb_frame.f_code.co_filename)[1]
            print(exc_type, fname, exc_tb.tb_lineno)

    if(mode==2):
        try:
            file_name:str = "code"
            for _test_file in os.listdir(f"inp"):
                _test=_test_file.split(".")[0]
                os.mkdir(f"out/test{_test}")
                os.rename(f"inp\{_test_file}",f"inp\{file_name}.inp")
                shutil.move(f"inp\{file_name}.inp",f"{file_name}.inp")
                with open(f"{file_name}.out","w") as file:
                    file.close()
                os.system(f".\code\compile\{file_name}.exe")
                time.sleep(1.5)
                shutil.move(f"{file_name}.inp",f"out/test{_test}/{file_name}.inp")
                shutil.move(f"{file_name}.out",f"out/test{_test}/{file_name}.out")
        except Exception as error:
            exc_type, exc_obj, exc_tb = sys.exc_info()
            fname = os.path.split(exc_tb.tb_frame.f_code.co_filename)[1]
            print(exc_type, fname, exc_tb.tb_lineno)

    if(mode==3):
        try:
            file_name:str = "code"
            os.system(f"g++ code/origin/{file_name}.cpp -o code/compile/{file_name}.exe")
        except Exception as error:
            print(error)

    
        