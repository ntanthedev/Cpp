import os
import subprocess
import shutil
import glob

def main():
    # Lấy đường dẫn thư mục hiện tại
    base_dir = os.path.dirname(os.path.abspath(__file__))
    
    # Nhập tên bài
    problem_name = input("Nhập tên bài: ").strip()
    if not problem_name:
        print("Tên bài không được để trống!")
        return
    
    # Compile gentest.cpp
    gentest_cpp = os.path.join(base_dir, "gentest.cpp")
    gentest_exe = os.path.join(base_dir, "gentest.exe")
    
    print("\n[1/4] Đang compile gentest.cpp...")
    compile_result = subprocess.run(
        ["g++", "-o", gentest_exe, gentest_cpp, "-O2"],
        capture_output=True, text=True
    )
    if compile_result.returncode != 0:
        print(f"Lỗi compile gentest.cpp:\n{compile_result.stderr}")
        return
    print("Compile gentest.cpp thành công!")
    
    # Compile solution.cpp
    solution_cpp = os.path.join(base_dir, "solution.cpp")
    solution_exe = os.path.join(base_dir, "solution.exe")
    
    print("\n[2/4] Đang compile solution.cpp...")
    compile_result = subprocess.run(
        ["g++", "-o", solution_exe, solution_cpp, "-O2"],
        capture_output=True, text=True
    )
    if compile_result.returncode != 0:
        print(f"Lỗi compile solution.cpp:\n{compile_result.stderr}")
        return
    print("Compile solution.cpp thành công!")
    
    # Chạy gentest để sinh các file input
    print("\n[3/4] Đang chạy gentest để sinh test cases...")
    print(f"       (Đang chờ gentest.exe hoàn thành...)")
    
    # Dùng subprocess.call để đảm bảo blocking cho đến khi process kết thúc hoàn toàn
    return_code = subprocess.call([gentest_exe], cwd=base_dir)
    
    if return_code != 0:
        print(f"Lỗi khi chạy gentest!")
        return
    
    print("       Gentest hoàn thành!")
    
    # Tìm tất cả các file .inp đã được sinh ra (hỗ trợ cả test01.inp và 1.inp)
    all_files = os.listdir(base_dir)
    inp_files = []
    for f in all_files:
        if f.endswith(".inp"):
            inp_files.append(os.path.join(base_dir, f))
    
    # Hàm để extract số từ tên file (hỗ trợ cả "1.inp" và "test01.inp")
    import re
    def extract_number(filepath):
        filename = os.path.basename(filepath).replace(".inp", "")
        # Tìm số trong tên file
        numbers = re.findall(r'\d+', filename)
        if numbers:
            return int(numbers[-1])  # Lấy số cuối cùng
        return 0
    
    inp_files = sorted(inp_files, key=extract_number)
    
    if not inp_files:
        print("Không tìm thấy file .inp nào được sinh ra!")
        return
    
    num_tests = len(inp_files)
    print(f"Đã sinh {num_tests} test cases!")
    
    # Tạo folder chung mang tên bài
    problem_folder = os.path.join(base_dir, problem_name)
    os.makedirs(problem_folder, exist_ok=True)
    
    # Tạo các folder TEST và sinh output
    print(f"\n[4/4] Đang tạo các folder TEST và sinh output...")
    for i, inp_file in enumerate(inp_files, 1):
        # Tạo folder TEST i trong folder tên bài
        test_folder = os.path.join(problem_folder, f"TEST{i}")
        os.makedirs(test_folder, exist_ok=True)
        
        output_file = inp_file.replace(".inp", ".out")
        
        # Chạy solution để sinh output
        with open(inp_file, "r") as fin:
            with open(output_file, "w") as fout:
                result = subprocess.run(
                    [solution_exe],
                    stdin=fin,
                    stdout=fout,
                    text=True
                )
        
        # Copy và đổi tên file vào folder TEST
        dest_inp = os.path.join(test_folder, f"{problem_name}.INP")
        dest_out = os.path.join(test_folder, f"{problem_name}.OUT")
        
        shutil.copy(inp_file, dest_inp)
        shutil.copy(output_file, dest_out)
        
        # Xóa file tạm
        os.remove(inp_file)
        os.remove(output_file)
        
        print(f"  Đã tạo folder TEST {i}")
    
    print(f"\n✓ Hoàn thành! Đã tạo {num_tests} test cases cho bài {problem_name}")
    print(f"  Folder: {problem_name}/")
    print(f"    ├── TEST 1, TEST 2, ..., TEST {num_tests}")
    print(f"    └── Mỗi folder chứa: {problem_name}.INP và {problem_name}.OUT")

if __name__ == "__main__":
    main()
