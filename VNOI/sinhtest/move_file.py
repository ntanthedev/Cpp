import os
import shutil
import stat
import sys

def manage_files(parent_dir):
    source_dir = os.path.join(parent_dir, "sinhtest")
    dest_dir = os.path.join(parent_dir, "inp")
    out_dir = os.path.join(parent_dir, "out")


    if not os.path.exists(dest_dir):
        os.makedirs(dest_dir)
        print(f"Đã tạo thư mục {dest_dir}")

    if os.path.exists(out_dir):
        try:
            os.chmod(out_dir, stat.S_IWRITE)
            shutil.rmtree(out_dir)
            os.makedirs(out_dir)
            print(f"Đã xóa toàn bộ nội dung trong thư mục {out_dir}")
        except Exception as e:
            print(f'Không thể xóa {out_dir}. Lý do: {e}')
    else:
        print(f"Thư mục {out_dir} không tồn tại")

    if os.path.exists(dest_dir):
        for filename in os.listdir(dest_dir):
            file_path = os.path.join(dest_dir, filename)
            try:
                if os.path.isfile(file_path) or os.path.islink(file_path):
                    os.unlink(file_path)
                elif os.path.isdir(file_path):
                    shutil.rmtree(file_path)
            except Exception as e:
                print(f'Không thể xóa {file_path}. Lý do: {e}')
        print(f"Đã xóa toàn bộ nội dung trong thư mục {dest_dir}")
    else:
        print(f"Thư mục {dest_dir} không tồn tại")

    # Chuyển các file .inp từ "sinhtest" sang "inp"
    for filename in os.listdir(source_dir):
        if filename.endswith(".inp"):
            source_file = os.path.join(source_dir, filename)
            dest_file = os.path.join(dest_dir, filename)
            
            # Di chuyển file
            shutil.move(source_file, dest_file)
            print(f"Đã chuyển {filename} từ {source_dir} sang {dest_dir}")

# Sử dụng script
if __name__ == "__main__":
    # Sử dụng đường dẫn tương đối đến thư mục cha
    parent_directory = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
    manage_files(parent_directory)