import os
import subprocess
import shutil

# --- CẤU HÌNH ---
PROBLEM_NAME = "FIREWORK"
GEN_CPP = "gen.cpp"
SOLUTION_CPP = "solution.cpp" # Code AC đã được fix lỗi
NUM_TESTS = 100

# --- Tên file thực thi (thêm .exe cho Windows) ---
# Script sẽ tự động thêm .exe nếu chạy trên Windows
executable_ext = ".exe" if os.name == 'nt' else ""
GEN_EXE = "gen" + executable_ext
SOLUTION_EXE = "solution" + executable_ext

def compile_cpp(source_file, output_exe):
    """Biên dịch một file C++ và kiểm tra lỗi."""
    print(f"Compiling {source_file} -> {output_exe}...")
    # Sử dụng cờ tối ưu O2 và chuẩn C++17 phổ biến
    compile_command = [
        "g++", source_file, "-o", output_exe, 
        "-O2", "-std=c++17", "-static"
    ]
    try:
        subprocess.run(compile_command, check=True, capture_output=True, text=True)
        print(f"Compilation successful.")
    except subprocess.CalledProcessError as e:
        print(f"!!! COMPILE ERROR for {source_file} !!!")
        print(e.stderr)
        exit(1) # Dừng chương trình nếu biên dịch lỗi

def main():
    """Hàm chính điều khiển toàn bộ quá trình."""
    print("--- Starting Test Generation Process ---")

    # 1. Biên dịch các file C++
    compile_cpp(GEN_CPP, GEN_EXE)
    compile_cpp(SOLUTION_CPP, SOLUTION_EXE)

    # 2. Tạo thư mục chính cho bài toán
    if os.path.exists(PROBLEM_NAME):
        print(f"Warning: Folder '{PROBLEM_NAME}' already exists. Files might be overwritten.")
    else:
        os.makedirs(PROBLEM_NAME)
        print(f"Created main folder: '{PROBLEM_NAME}'")

    # 3. Vòng lặp sinh test
    for i in range(1, NUM_TESTS + 1):
        print(f"\n--- Generating Test {i}/{NUM_TESTS} ---")

        # A. Chạy generator để tạo file .INP
        # Truyền Test ID vào cho gen.exe qua command line
        try:
            subprocess.run([f"./{GEN_EXE}", str(i)], check=True)
            print(f"Generated {PROBLEM_NAME}.INP for test {i}")
        except subprocess.CalledProcessError as e:
            print(f"!!! RUNTIME ERROR in {GEN_EXE} for test {i} !!!")
            exit(1)
        
        # B. Chạy solution để tạo file .OUT từ file .INP vừa tạo
        try:
            subprocess.run([f"./{SOLUTION_EXE}"], check=True)
            print(f"Generated {PROBLEM_NAME}.OUT for test {i}")
        except subprocess.CalledProcessError as e:
            print(f"!!! RUNTIME ERROR in {SOLUTION_EXE} for test {i} !!!")
            exit(1)

        # C. Tạo thư mục con và di chuyển file
        test_case_folder = os.path.join(PROBLEM_NAME, f"test{i}")
        os.makedirs(test_case_folder, exist_ok=True)

        # Di chuyển và đổi tên file theo chuẩn
        shutil.move(f"{PROBLEM_NAME}.INP", os.path.join(test_case_folder, f"{PROBLEM_NAME}.INP"))
        shutil.move(f"{PROBLEM_NAME}.OUT", os.path.join(test_case_folder, f"{PROBLEM_NAME}.OUT"))
        print(f"Moved files to {test_case_folder}")

    # 4. Dọn dẹp
    print("\n--- Cleaning up temporary files ---")
    if os.path.exists(GEN_EXE):
        os.remove(GEN_EXE)
    if os.path.exists(SOLUTION_EXE):
        os.remove(SOLUTION_EXE)
    print("Cleanup complete.")
    print(f"\nSUCCESS! All {NUM_TESTS} test cases are generated in the '{PROBLEM_NAME}' folder.")

if __name__ == "__main__":
    main()