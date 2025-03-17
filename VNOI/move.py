import os
import shutil

def clear_folder(folder_path):
    """Clear a folder by removing it and recreating it empty"""
    if os.path.exists(folder_path):
        shutil.rmtree(folder_path)
    os.makedirs(folder_path, exist_ok=True)
    print(f"Cleared folder '{folder_path}'")

def move_inp_files(source_folder, destination_folder):
    """Move all .inp files from source_folder to destination_folder"""
    if not os.path.exists(source_folder):
        print(f"Source folder '{source_folder}' does not exist.")
        return
    
    if not os.path.exists(destination_folder):
        os.makedirs(destination_folder, exist_ok=True)
    
    count = 0
    for file_name in os.listdir(source_folder):
        if file_name.endswith('.inp'):
            source_path = os.path.join(source_folder, file_name)
            destination_path = os.path.join(destination_folder, file_name)
            shutil.move(source_path, destination_path)
            count += 1
    
    print(f"Moved {count} .inp files from '{source_folder}' to '{destination_folder}'")

# Define the paths (relative to VNOI folder where the script is located)
inp_folder = "inp"
out_folder = "out"
sinhtest_folder = "sinhtest"

# Clear inp and out folders
clear_folder(inp_folder)
clear_folder(out_folder)

# Move .inp files
move_inp_files(sinhtest_folder, inp_folder)
print("Task completed successfully!")