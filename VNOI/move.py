import os
import shutil

def move_files():
    source_dir = 'prehsg9_8'
    dest_dir = 'inp'
    out_dir = 'out'

    # Ensure destination directory exists
    if not os.path.exists(dest_dir):
        os.makedirs(dest_dir)

    # Move files 1.inp to 50.inp
    for i in range(1, 51):
        filename = f"{i}.inp"
        src_file = os.path.join(source_dir, filename)
        dest_file = os.path.join(dest_dir, filename)
        
        if os.path.exists(src_file):
            shutil.move(src_file, dest_file)
            print(f"Moved {filename} to {dest_dir}")
        else:
            print(f"{filename} does not exist in {source_dir}")

    # Delete all files in out_dir
    if os.path.exists(out_dir):
        for filename in os.listdir(out_dir):
            file_path = os.path.join(out_dir, filename)
            try:
                if os.path.isfile(file_path) or os.path.islink(file_path):
                    os.unlink(file_path)
                    print(f"Deleted file: {filename}")
                elif os.path.isdir(file_path):
                    shutil.rmtree(file_path)
                    print(f"Deleted directory: {filename}")
            except Exception as e:
                print(f"Failed to delete {filename}. Reason: {e}")
    else:
        print(f"The directory {out_dir} does not exist.")

if __name__ == "__main__":
    move_files()