import os
import shutil

def transfer_inp_files(parent_dir):
    # Đường dẫn đến thư mục nguồn và đích
    source_dir = os.path.join(parent_dir, "sinhtest")
    dest_dir = os.path.join(parent_dir, "inp")

    # Tạo thư mục đích nếu nó chưa tồn tại
    if not os.path.exists(dest_dir):
        os.makedirs(dest_dir)

    # Duyệt qua tất cả các file trong thư mục nguồn
    for filename in os.listdir(source_dir):
        if filename.endswith(".inp"):
            source_file = os.path.join(source_dir, filename)
            dest_file = os.path.join(dest_dir, filename)
            
            # Di chuyển file
            shutil.move(source_file, dest_file)
            print(f"Đã chuyển {filename} từ {source_dir} sang {dest_dir}")

# Sử dụng script
if __name__ == "__main__":
    # Thay đổi đường dẫn này thành đường dẫn đến thư mục cha của bạn
    parent_directory = "C:\\Users\\nhatt\\Documents\\Cpp\\VNOI\\"
    transfer_inp_files(parent_directory)