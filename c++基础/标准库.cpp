#pragma region 标准库
/*
https://www.runoob.com/cplusplus/cpp-standard-library.html

输入输出

    <iostream>: 标准输入输出流
    <fstream>: 文件输入输出流
    <sstream>: 字符串流
    <iomanip>: 输入输出流格式化

容器

    <array>: 定长数组容器
    <vector>: 动态数组容器
    <deque>: 双端队列容器
    <list>: 双向链表容器
    <forward_list>: 单向链表容器
    <stack>: 栈容器适配器
    <queue>: 队列容器适配器
    <priority_queue>: 优先队列容器适配器
    <set>: 集合容器（基于平衡二叉树）
    <unordered_set>: 无序集合容器（基于哈希表）
    <map>: 映射容器（键值对，基于平衡二叉树）
    <unordered_map>: 无序映射容器（基于哈希表）
    <bitset>: 二进制位容器

算法和迭代器

    <algorithm>: 常用算法（如排序、查找等）
    <iterator>: 迭代器

函数对象和绑定

    <functional>: 定义函数对象及相关工具

数学和数值运算

    <numeric>: 数值操作（如累计、乘积等）
    <complex>: 复数运算
    <valarray>: 数组类及相关操作
    <cmath>: 数学函数

字符串和正则表达式

    <string>: 标准字符串类
    <regex>: 正则表达式

时间和日期

    <ctime>: 时间处理
    <chrono>: 时间库

多线程和并发

    <thread>: 多线程支持
    <mutex>: 互斥量
    <condition_variable>: 条件变量
    <future>: 异步编程支持
    <atomic>: 原子操作

内存管理

    <memory>: 智能指针及动态内存管理
    <new>: 动态内存分配

类型特性和运行时类型识别

    <type_traits>: 类型特性
    <typeinfo>: 运行时类型识别

异常处理

    <exception>: 异常处理基类及相关工具
    <stdexcept>: 常用异常类（如 std::runtime_error 等）

输入输出操作

    <cstdio>: C 风格输入输出
    <cstdint>: 定长整数类型

其他工具

    <utility>: 通用工具（如 std::pair 和 std::move 等）
    <random>: 随机数生成
    <locale>: 本地化支持
    <codecvt>: 字符编码转换
    <cassert>: 断言
    <cctype>: 字符处理
    <cstring>: 字符串处理
    <cwchar>: 宽字符处理
    <climits>: 数值极限
    <cfloat>: 浮点极限
    <cstdlib>: 常用工具（如 std::rand 和 std::abs 等）

*/
#pragma endregion

#pragma region <string>
#include <iostream>
#include <string>
using namespace std;

int main(){
    system("clear");
    system("chcp 65001>nul");
    
    // 初始化字符串
    string str = "Hello World";
    cout << "str = " << str << endl;

    //字符串大小
    int len = str.length();
    cout << "len = " << len << endl;
    len = str.size();
    cout << "len = " << len << endl;

    // 连接字符串
    string str2 = str + "!";
    cout << "str2 = " << str2 << endl;

    // 整形转换为字符串
    int num = 123;
    string str3 = to_string(num);
    cout << "str3 = " << str3 << endl;

    // 访问字符串中的字符
    cout << "str[0] = " << str[0] << endl;
    cout << "str[str.length()-1] = " << str[str.length()-1] << endl;

    // 判断字符串是否为空
    if (str.empty()) {
        cout << "str is empty" << endl;
    } else {
        cout << "str is not empty" << endl;
    }

    // 返回从指定位置开始的子字符串。
    string sub = str.substr(0, 5);
    cout << "sub = " << sub << endl;

    // 查找字符串中的字符,返回字符串中第一个匹配字符的位置，如果没有找到，则返回 string::npos
    size_t pos = str.find("World");
    if (pos != string::npos) {
        cout << "Found at position " << pos << endl;
    } else {
        cout << "Not found" << endl;
    }

    // 在字符串末尾添加内容。
    str.append("!");
    cout << "str = " << str << endl;

    // 在指定位置插入内容。
    str.insert(0, "Hello ");
    cout << "str = " << str << endl;

    // 复制局部字符串
    string str4 = str.substr(0, 5);
    cout << "str4 = " << str4 << endl;
    
    // 清空字符串。
    // 清空字符串。
    str.clear();
    cout << "str = " << str << endl;

    
    // 比较两个字符串。
    string str4 = "Hello";
    string str5 = "World";
    int res = str4.compare(str5);
    if (res == 0) {
        cout << "str4 == str5" << endl;
    } else if (res < 0) {
        cout << "str4 < str5" << endl;
    } else {
        cout << "str4 > str5" << endl;
    }
}

#pragma endregion

#pragma region <array>
/*
std::array<T, N> array_name;

    T 是数组中元素的类型。
    N 是数组的大小，必须是一个非负整数。
    <array> 需要在编译时确定大小，不能动态改变                  
    
*/  
#include <iostream>
#include <array>
#include <vector>
using namespace std;

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
#pragma endregion


#pragma region <vector>
// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
//     system("clear");
//     system("chcp 65001>nul");

//     // 初始化向量
//     vector<int> v = {1, 2, 3, 4, 5};
//     vector<int> v1(10);         // 10个0
//     vector<int> v2(10, 5);      // 10个5
//     cout << "v = ";
//     cout << "v1 = ";
//     for (int x : v1) {
//         cout << x << " ";
//     }
//     cout << endl;
//     cout << "v2 = ";
//     for (int x : v2) {
//         cout << x << " ";
//     }
//     cout << endl;

//     // 遍历向量
//     for (int x : v) {
//         cout << x << " ";
//     }
//     cout << endl;



//     // 向量大小
//     int size = v.size();
//     cout << "size = " << size << endl;

//     // 添加元素
//     v.push_back(6);
//     cout << "v = ";
//     for (int x : v) {
//         cout << x << " ";
//     }
//     cout << endl;

//     // 删除元素
//     // 删除最后一个元素
//     v.pop_back();
//     cout << "v = ";
//     for (int x : v) {
//         cout << x << " ";
//     }
//     cout << endl;

//     // 访问元素
//     cout << "v[0] = " << v[0] << endl;
//     cout << "v[0] = " << v.at(0) << endl;
//     cout << "v.back() = " << v.back() << endl;
//     cout << "v.front() = " << v.front() << endl;

//     //清空向量
//     v.clear();
//     cout << "v = ";
//     for (int x : v) {
//         cout << x << " ";
//     }
//     cout << endl;

//     vector<int> v3 = {1, 2, 3, 4, 5};

    // // 迭代访问
    // cout << "v3 = ";
    // for (auto it = v3.begin(); it != v3.end(); it++) {
    //     // it 是一个指针，指向当前元素的地址
    //     cout << *it << " ";
    // }
    // // 使用范围for循环
    // cout << "v3 = ";
    // for(auto& x : v3){
    //     cout << x << " ";
    // }
//     cout << endl;
// }


#pragma endregion

#pragma region <stack>
/*
    std::stack<int> s;
    push(): 在栈顶添加一个元素。
    pop(): 移除栈顶元素。
    top(): 返回栈顶元素的引用，但不移除它。
    empty(): 检查栈是否为空。
    size(): 返回栈中元素的数量。

*/
// #include <iostream>
// #include <stack>
// using namespace std;

// int main(){
//     system("clear");
//     system("chcp 65001>nul");
    
//     // 初始化栈
//     stack<int> s;

//     // 向栈中添加元素
//     s.push(1);
//     s.push(2);
//     s.push(3);

//     // 访问栈顶元素
//     std::cout << "Top element is: " << s.top() << std::endl;

//     // 移除栈顶元素
//     s.pop();
//     std::cout << "After popping, top element is: " << s.top() << std::endl;

//     // 检查栈是否为空
//     if (!s.empty()) {
//         std::cout << "Stack is not empty." << std::endl;
//     }

//     // 打印栈的大小
//     std::cout << "Size of stack: " << s.size() << std::endl;

//     return 0;
// }

#pragma endregion

#pragma region <queue>
/*
    #include <queue>
    std::queue<Type> q;
    empty(): 检查队列是否为空。
    size(): 返回队列中的元素数量。
    front(): 返回队首元素的引用。
    back(): 返回队尾元素的引用。
    push(): 在队尾添加一个元素。
    pop(): 移除队首元素。
*/

// #include <iostream>
// #include <queue>

// int main() {
//     system("clear");
//     system("chcp 65001>nul");

//     // 创建一个整数队列
//     std::queue<int> q;

//     // 向队列中添加元素
//     q.push(10);
//     q.push(20);
//     q.push(30);

//     // 打印队列中的元素数量
//     std::cout << "队列中的元素数量: " << q.size() << std::endl;

//     // 打印队首元素
//     std::cout << "队首元素: " << q.front() << std::endl;

//     // 打印队尾元素
//     std::cout << "队尾元素: " << q.back() << std::endl;

//     // 移除队首元素
//     q.pop();
//     std::cout << "移除队首元素后，队首元素: " << q.front() << std::endl;

//     // 再次打印队列中的元素数量
//     std::cout << "队列中的元素数量: " << q.size() << std::endl;

//     return 0;
// }

#pragma endregion

#pragma region  <unordered_set>
// unordered_set 不保证元素的排序，但通常提供更快的查找、插入和删除操作
// unordered_set 的迭代器是 const 的，不能修改元素的值

// #include <iostream>
// #include <unordered_set>
// using namespace std;

// int main() {
//     system("clear");
//     system("chcp 65001>nul");
    
//     // 构造函数
//     // 集合内的元素是无序的，且不允许重复
//     unordered_set<int> s = {1, 2, 3, 4, 5, 5};
//     cout << "当前集合的大小为" << s.size() << endl;
//     // 遍历集合
//     for (int x : s) {
//         // 不保证元素的排序
//         cout << x << " ";
//     }
//     cout << endl;
//     // 插入元素
//     s.insert(6);
    
//     // 删除元素
//     s.erase(3);
    
//     // 查找元素
//     if (s.find(4) != s.end()) {
//         cout << "元素 4 存在" << endl;
//     }
    
//     // 大小
//     size_t size = s.size();
//     cout << "集合的大小：" << size << endl;
    
//     // 空检查
//     if (s.empty()) {
//         cout << "集合为空" << endl;
//     }
    
//     // 清空集合
//     s.clear();

//     // 将字符串转换为集合
//     string str = "Hello World";
//     cout << "\n原字符串: \"" << str << "\"" << endl;
//     cout << "字符串长度: " << str.length() << endl;
    
//     // 展示迭代器指向的内容
//     cout << "*str.begin() = '" << *str.begin() << "'" << endl;  // 'H'
//     cout << "str[0] = '" << str[0] << "'" << endl;              // 'H'
//     cout << "str[str.length()-1] = '" << str[str.length()-1] << "'" << endl;  // 'd'
    
//     // 使用迭代器范围构造unordered_set
//     unordered_set<char> s2(str.begin(), str.end());
    
//     cout << "\n转换后的unordered_set内容（自动去重）：" << endl;
//     for (char c : s2) {
//         cout << "'" << c << "' ";
//     }

//     return 0;
// }

#pragma endregion

#pragma region <unordered_map>
// 哈希表
// unordered_map 是无序的，不保证元素的排序，但通常提供更快的查找、插入和删除操作
// unordered_map 的迭代器是 const 的，不能修改元素的值
// nordered_map<elemType_1, elemType_2> var_name;
// elemType_1 是键类型，elemType_2 是值类型

// #include <iostream>
// #include <unordered_map>
// #include <string>
// #include <vector>
// using namespace std;

// int main() {
//     system("clear");
//     system("chcp 65001>nul");
//     // 构造函数
//     unordered_map<int, int> m = {{1, 10}, {2, 20}, {3, 30}};

//     cout << "当前哈希表的大小为" << m.size() << endl;
//     cout << "m[1] = " << m[1] << endl;
//     cout << "m[2] = " << m[2] << endl;
//     cout << "m[3] = " << m[3] << endl;

//     unordered_map<char, int> m2;
//     string str = "Hello World";
//     for (char c : str){
//         m2[c]++;
//     }
//     char c = 'l';
//     cout << "m2['" << c << "'] = " << m2[c] << endl;

//     // 遍历
//     for (const auto& pair : m2) {
//         // pair.first 是键，pair.second 是值
//         cout << pair.first << ": " << pair.second << endl;
//     }

//     // 键值 对应多个值
//     unordered_map<int, vector<int>> m3;

//     //m3[1] 即为vector<int> 对象
//     m3[1].push_back(10);
//     m3[1].push_back(20);
//     m3[1].push_back(30);
//     cout << "m3[1][0] = " << m3[1][0] << endl;
//     cout << "m3[1][1] = " << m3[1][1] << endl;
//     cout << "m3[1][2] = " << m3[1][2] << endl;

// }
#pragma endregion

#pragma region <algorithm>
// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <string>
// #include <time.h>
// using namespace std;
// void printVector(vector<int> &v){
//     for (int i = 0; i < (int)v.size(); i++) {
//         cout << v[i] << " ";
//     }
//     cout << endl;
// }

// int main(){
//     system("clear");
//     system("chcp 65001>nul");

//     //排序算法
//     vector<int> v = {1, 3, 5, 7, 9, 2, 4, 6, 8, 0};
//     sort(v.begin(), v.end());
//     printVector(v);

//     string str = "bdefozeaca";
//     // 字母升序排序
//     sort(str.begin(), str.end());
//     cout << str << endl;

//     // 搜索算法
//     string str2 = "Hello World";
//     // 在容器中查找与给定值匹配的第一个元素。 
//     // 如果找到，it 将指向匹配的元素；
//     // 如果没有找到，it 将等于 container.end()。
//     auto it = find(str2.begin(), str2.end(), 'l');
//     if (it != str2.end()) {
//         cout << "找到字符 'l' 的位置: " << it - str2.begin() << endl;
//     } else {
//         cout << "未找到字符 'l'" << endl;
//     }

//     // 二分查找 要求容器必须是升序排列
//     sort(str2.begin(), str2.end());
//     auto it2 = binary_search(str2.begin(), str2.end(), 'l');
//     if (it2) {
//         cout << "找到字符 'l'的位置" << it - str2.begin() << endl;
//     } else {
//         cout << "未找到字符 'l'" << endl;
//     }

//     // 复制算法
//     vector<int> v2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     vector<int> v3(10);
//     copy(v2.begin(), v2.end(), v3.begin());
//     printVector(v3);

//     // 反转算法
//     // 将容器中的元素反转
//     reverse(v3.begin(), v3.end());
//     printVector(v3);

//     // 替换算法
//     // 将容器中所有等于 old_value 的元素替换为 new_value
//     replace(v3.begin(), v3.end(), 5, 100);
//     printVector(v3);

//     // 赋值算法
//     fill(v3.begin(), v3.end(), 0);
//     printVector(v3);

//     // 比较算法
//     vector<int> v4 = {1, 2, 3, 4, 5};
//     vector<int> v5 = {1, 2, 3, 4, 5};
//     // 检查两个容器是否相等
//     bool isEqual = equal(v4.begin(), v4.end(), v5.begin());
//     cout << "两个向量是否相等: " << (isEqual ? "是" : "否") << endl;

//     // 交换算法
//     swap(v4, v5);
//     printVector(v4);
//     printVector(v5);

//     // 归并
//     vector<int> v6 = {1, 3, 5, 7, 9};
//     vector<int> v7 = {2, 4, 6, 8, 10};
//     vector<int> v8(10);
//     merge(v6.begin(), v6.end(), v7.begin(), v7.end(), v8.begin());
//     printVector(v8);

//     // 随机数
//     srand(time(0));
//     for (int i = 0; i < 10; i++) {
//         cout << rand() % 100 << " ";
//     }
//     cout << endl;

// }


#pragma endregion

