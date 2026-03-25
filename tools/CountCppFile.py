import os

def count_cpp_files(target_dir):
    """
    统计目标目录及其所有子目录内所有后缀为.cpp的文件数量

    Args:
        target_dir: 目标目录路径

    Returns:
        cpp文件数量
    """
    count = 0

    for root, dirs, files in os.walk(target_dir):
        for file in files:
            if file.endswith('.cpp'):
                count += 1

    return count

def main():
    # 目标目录，可根据需要修改
    target_directory = "../"

    result = count_cpp_files(target_directory)
    print(f"目录 '{target_directory}' 及其子目录中的 .cpp 文件数量: {result}")

main()
