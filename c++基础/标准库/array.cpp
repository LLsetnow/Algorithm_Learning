#include <D:\github\Algorithm_Learning\LeetCode\headfile\stdc++.h>
using namespace std;

/*
std::array<T, N> array_name;

    T 是数组中元素的类型。
    N 是数组的大小，必须是一个非负整数。
    <array> 需要在编译时确定大小，不能动态改变                  
    
*/  

int main() {
    // 创建一个包含 5 个整数的 std::array
    std::array<int, 5> myArray = {1, 2, 3, 4, 5};

    // 使用范围 for 循环遍历数组
    for (const auto& value : myArray) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    // 使用索引访问数组元素
    std::cout << "Element at index 2: " << myArray.at(2) << std::endl;

    // 获取数组的大小
    std::cout << "Array size: " << myArray.size() << std::endl;

    // 修改数组元素
    myArray[3] = 10;

    // 再次遍历数组以显示修改后的元素
    for (const auto& value : myArray) {
        std::cout << value << " ";
    }
    std::cout << std::endl;


    // 创建n行2列vector
    int n = 3;
    vector<array<int, 2>> dp(n, {1, 1});

    return 0;
}