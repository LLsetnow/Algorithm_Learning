// #include <iostream>
// #include <string>
// using namespace std;

// int main() {
//     string fullName;
    
//     cout << "input your full name:";
//     getline(cin, fullName);  // 可以读取包含空格的字符串
    
//     cout << "your full name is: " << fullName << endl;
    
//     return 0;
// }

// #include <iostream>
// using namespace std;

// int main() {
//     system("chcp 65001>nul"); 
//     // 数字字面量
//     int decimal = 42;        // 十进制
//     int octal = 052;         // 八进制（以0开头）
//     int hex = 0x2A;          // 十六进制（以0x开头）
    
//     cout << "十进制：" << decimal << endl;
//     cout << "八进制：" << octal << endl;
//     cout << "十六进制：" << hex << endl;
    
//     // 浮点字面量
//     double d1 = 3.14;
//     double d2 = 1.23e-4;     // 科学计数法
//     float f1 = 3.14f;        // f 后缀表示 float
    
//     cout << "普通浮点数：" << d1 << endl;
//     cout << "科学计数法：" << d2 << endl;
//     cout << "float 类型：" << f1 << endl;
    
//     // 字符字面量和转义字符
//     char newline = '\n';     // 换行符
//     char tab = '\t';         // 制表符
//     char quote = '\'';       // 单引号
//     char backslash = '\\';   // 反斜杠
    
//     cout << "第一行" << newline << "第二行" << endl;
//     cout << "姓名：" << tab << "张三" << endl;
//     cout << "单引号：" << quote << endl;
//     cout << "反斜杠：" << backslash << endl;
    
//     // 字符串字面量
//     string message = "Hello\tWorld\n";
//     cout << message;
    
//     return 0;
// }


// #include <iostream>
// using namespace std;

// int main() {
//     system("chcp 65001>nul"); 
//     double pi = 3.14159;
    
//     // C 风格的强制转换
//     int intPi1 = (int)pi;
    
//     // C++ 风格的强制转换
//     int intPi2 = static_cast<int>(pi);
    
//     cout << "原始值：" << pi << endl;
//     cout << "C 风格转换：" << intPi1 << endl;
//     cout << "C++ 风格转换：" << intPi2 << endl;
    
//     // 字符和数字的转换
//     char digit = '5';
//     int number = digit - '0';  // 字符转数字的技巧
    
//     cout << "字符 '" << digit << "' 转换为数字：" << number << endl;
    
//     return 0;
// }


// #include <iostream>
// using namespace std;

// int main() {
//     system("chcp 65001>nul"); 
//     int x = 5;
//     int y = 0;
    
//     // 短路求值：如果第一个条件为假，后面的条件不会被计算
//     bool result1 = (y != 0) && (x / y > 2);
//     cout << "短路求值结果：" << result1 << endl;
    
//     // 如果没有短路求值，下面的代码会导致除零错误
//     // bool result2 = (x / y > 2) && (y != 0);  // 危险！
    
//     // 复合条件判断
//     int temperature = 25;
//     bool isSunny = true;
    
//     bool goodWeather = (temperature > 20) && (temperature < 30) && isSunny;
//     cout << "天气很好：" << goodWeather << endl;
    
//     return 0;
// }

// 数组基础
// #include <iostream>
// #include <cstring>
// using namespace std;

// int main() {
//     // 声明数组
//     int scores[5];  // 声明一个能存储5个整数的数组
    
//     // 声明并初始化
//     int numbers[5] = {10, 20, 30, 40, 50};
    
//     // 部分初始化
//     int values[5] = {1, 2};  // 前两个元素为1和2，其余为0
    
//     // 自动推断数组大小
//     int data[] = {100, 200, 300};  // 编译器自动推断为3个元素
    
//     for(int i = 0; i < 5;i++){

//         cout << scores[i] << " ";
//     }
//     cout << endl;
//     for(int i = 0; i < 5;i++){

//         cout << values[i] << " ";
//     }

//     return 0;
// }

// 字符串
// #include <iostream>
// #include <cstring>
// using namespace std;

// int main() {
//     system("chcp 65001>nul");
//     // string的声明和初始化
//     string greeting = "你好";
//     string name = "小明";
    
//     // 字符串连接
//     string message = greeting + "," + name + "!";
//     cout << message << endl;
    
//     // 字符串长度
//     cout << "消息长度：" << message.length() << endl;
    
//     // 字符串比较
//     if (greeting == "你好") {
//         cout << "问候语是'你好'" << endl;
//     }
    
//     // 字符串查找
//     if (message.find("小明") != string::npos) {
//         cout << "消息中包含'小明'" << endl;
//     }
    
//     // 字符串替换
//     string newMessage = message;
//     newMessage.replace(newMessage.find("小明"), 2, "小红");
//     cout << "替换后：" << newMessage << endl;
    
//     return 0;
// }


// 数组排序
// #include <iostream>
// #include <algorithm>
// using namespace std;

// int main() {
//     system("chcp 65001>nup");
//     int scores[] = {85, 92, 78, 96, 88, 73, 91};
//     int n = sizeof(scores) / sizeof(scores[0]);
//     cout << sizeof(scores[0]) << endl;
    
//     cout << "排序前：";
//     for (int i = 0; i < n; i++) {
//         cout << scores[i] << " ";
//     }
//     cout << endl;
    
//     // 使用标准库排序
//     sort(scores, scores + n);
    
//     cout << "排序后：";
//     for (int i = 0; i < n; i++) {
//         cout << scores[i] << " ";
//     }
//     cout << endl;
    
//     return 0;
// }

// // 数组查找
// #include <iostream>
// using namespace std;

// int main() {
//     system("chcp 65001>nul");
//     int numbers[] = {3, 7, 1, 9, 4, 6, 8, 2, 5};
//     int n = sizeof(numbers) / sizeof(numbers[0]);
//     int target = 6;
    
//     // 线性查找
//     bool found = false;
//     int position = -1;
    
//     for (int i = 0; i < n; i++) {
//         if (numbers[i] == target) {
//             found = true;
//             position = i;
//             break;
//         }
//     }
    
//     if (found) {
//         cout << "找到了！" << target << "在位置" << position << endl;
//     } else {
//         cout << "没有找到" << target << endl;
//     }
    
//     return 0;
// }


// 地址

// #include <iostream>
// using namespace std;

// int main() {
//     system("chcp 65001>nul");
//     int num = 42;
//     cout << "变量num的值:" << num << endl;
//     cout << "变量num的地址:" << &num << endl;

//     double price = 29.99;
//     cout << "变量price的值:" << price << endl;
//     cout << "变量price的地址:" << &price << endl;
    
//     return 0;
// }

// 指针
// #include <iostream>
// using namespace std;
// int main() {
    
//     system("chcp 65001>nul");
//     int num = 42;
//     int* ptr = &num;

//     // *ptr 解引用 获取指针所指向的值
//     // &num 获取变量的地址

//     cout << "变量num的值:" << num << endl;
//     cout << "变量num的地址:" << &num << endl;
//     cout << "指针ptr的值:" << *ptr << endl;
//     cout << "指针ptr的地址:" << ptr << endl;
//     return 0;
// }


// 动态内存分配
// #include <iostream>
// using namespace std;
// int main() {
//     system("chcp 65001>nul");
//     // new 分配内存
//     // delete 释放内存
//     int* ptr = new int;
//     *ptr = 42;
//     cout << "指针ptr的值:" << *ptr << endl;
//     delete ptr;
//     return 0;
// }

// 动态内存分配数组
// #include <iostream>
// using namespace std;
// int main() {
//     system("chcp 65001>nul");
//     // new 分配内存
//     // delete 释放内存
//     // ptr 指向数组的首地址
//     // ptr[i] 访问数组元素
//     // delete[] ptr 释放数组内存
//     int* ptr = new int[10];
//     for (int i = 0; i < 10; i++) {
//         ptr[i] = i + 1;
//     }
//     for (int i = 0; i < 10; i++) {
//         cout << ptr[i] << " ";
//     }
//     delete[] ptr;
//     return 0;
// }


// 指针算术
// #include <iostream>
// using namespace std;
// int main() {
//     system("chcp 65001>nul");
//     int numbers[6] = {1, 2, 3, 4, 5, 6};
//     int* ptr = numbers;
    
//     //ptr + i 指针移动到第i个元素
//     // *(ptr + i) 访问第i个元素
//     // ptr[i] 访问第i个元素
//     // ptr++ 指针移动到下一个元素
//     // ptr-- 指针移动到上一个元素
//     // ptr += i 指针移动到第i个元素
//     // ptr -= i 指针移动到第i个元素
//     // ptr = numbers 重新指向数组开头
//     // ptr = numbers + i 重新指向第i个元素
//     // ptr = numbers - i 重新指向第i个元素
//     // ptr = numbers + i 重新指向第i个元素
//     cout << "使用指针遍历数组：" << endl;
//     for (int i = 0; i < 6; i++) {
//         cout << "元素" << i << "：" << *(ptr + i) << endl;
//     }
    
//     // 指针递增
//     cout << "\n使用指针递增遍历：" << endl;
//     ptr = numbers;  // 重新指向数组开头
//     for (int i = 0; i < 6; i++) {
//         cout << "元素" << i << "：" << *ptr << endl;
//         ptr++;  // 指针移动到下一个元素
//     }
    
//     return 0;
// }

/*
引用:
    引用相当于一个别名
    引用必须在定义时初始化
    引用不能为空
    引用不能重复初始化
    引用不能修改
    引用不能删除
    引用不能重新赋值
    引用不能重新赋值
*/
// #include <iostream>
// using namespace std;
// int main() {
//     system("chcp 65001>nul");
//     int num = 42;
//     int& ref = num;
//     cout << "变量num的值:" << num << endl;
//     cout << "变量num的地址:" << &num << endl;
//     cout << "引用ref的值:" << ref << endl;
//     cout << "引用ref的地址:" << &ref << endl;
//     return 0;
// }   


// 函数参数传递
// 值传递: 传递的是值的副本
// 指针传递: 传递的是值的地址
// 引用传递: 传递的是值的别名（本质就是传值）
// #include <iostream>
// using namespace std;

// // 值传递
// // 执行该函数调用时 相当于执行了 int x = num;
// void func1(int x) {
//     x = 100;
//     cout << "func1中x = " << x << endl;
// }

// // 指针传递
// // 执行该函数调用时 相当于执行了 int* x = &num;
// void func2(int* x) {
//     *x = 200;
//     cout << "func2中*x = " << *x << endl;
// }

// // 引用传递
// // 执行该函数调用时 相当于执行了 int& x = num;
// void func3(int& x) {
//     x = 300;
//     cout << "func3中x = " << x << endl;
// }

// int main() {
//     system("chcp 65001>nul");
//     int num = 50;
    
//     cout << "原始值：" << num << endl;
    
//     func1(num);
//     cout << "调用func1后：" << num << endl;
    
//     func2(&num);
//     cout << "调用func2后：" << num << endl;
    
//     func3(num);
//     cout << "调用func3后：" << num << endl;
    
//     return 0;
// }


//练习1：指针基础操作

//编写程序，声明两个整数变量，使用指针交换它们的值。

// #include <iostream>
// using namespace std;
// int main(){
//     int a = 10;
//     int b = 20;

//     int* ptr1 = &a;
//     int* ptr2 = &b;
//     int temp = *ptr1;
//     *ptr1 = *ptr2;
//     *ptr2 = temp;

//     cout << "a = " << a << endl;
//     cout << "b = " << b << endl;
// }

//练习2：数组指针操作

//编写程序，‌使用指针找出数组中的⁢最大值和最小值。
// #include <iostream>
// using namespace std;

// int main(){
//     int numbers[6] = {1, 2, 3, 4, 5, 6};
//     int* ptr = numbers;
//     // 初始化最大值和最小值
//     int max = *ptr;
//     int min = *ptr;
//     for (int i = 0; i < 6; i++) {
//         if (*(ptr + i) > max) max = *(ptr + i);
//         if (*(ptr + i) < min) min = *(ptr + i);
//     }
//     cout << "max = " << max << endl;
//     cout << "min = " << min << endl;
//     return 0;
// }

//练习3：引用的应用

// 编写一个函‌数，使用引用参数计算⁢并返回两个数的和⁢与差。         ⁠          ​      
// #include <iostream>
// using namespace std;
// void calculate(int a, int b, int& sum, int& diff);
// int main(){
//     int a = 10;
//     int b = 20;
//     int sum;
//     int diff;
//     calculate(a, b, sum, diff);
//     cout << "sum = " << sum << endl;
//     cout << "diff = " << diff << endl;
//     return 0;
// }

// void calculate(int a, int b, int& sum, int& diff){
//     sum = a + b;
//     diff = a - b;
// }


