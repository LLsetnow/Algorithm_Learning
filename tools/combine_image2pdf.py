# 将文件夹内的jpg图片按文件名中的数字排序后合并为pdf


import os
import re
from PIL import Image

def extract_number(filename):
    """从文件名中提取数字"""
    match = re.search(r'(\d+)', filename)
    return int(match.group(1)) if match else 0

def combine_images_to_pdf(input_folder, output_pdf):
    """
    将文件夹中的 JPG 文件按文件名中的数字排序后合并为 PDF
    :param input_folder: 包含 JPG 文件的文件夹路径
    :param output_pdf: 输出的 PDF 文件路径
    """
    # 获取所有 JPG 文件
    jpg_files = [f for f in os.listdir(input_folder) if f.lower().endswith('.jpg')]
    
    # 按文件名中的数字排序
    jpg_files.sort(key=extract_number)
    
    # 打开所有图片并保存为 PDF
    images = [Image.open(os.path.join(input_folder, f)) for f in jpg_files]
    if images:
        images[0].save(
            output_pdf, "PDF", resolution=100.0, save_all=True, append_images=images[1:]
        )
        print(f"成功合并 {len(jpg_files)} 张图片到 {output_pdf}")
    else:
        print("未找到 JPG 文件")

if __name__ == "__main__":
    book_name = "可看 绘画造型表现指南.pdf"
    input_folder = "D:\桌面中转\绘画\细分4\可看 绘画造型表现指南"
    output_folder = "D:\桌面中转\绘画\细分4\可看 绘画造型表现指南"
    output_path = os.path.join(output_folder, book_name)
    combine_images_to_pdf(input_folder, output_path)