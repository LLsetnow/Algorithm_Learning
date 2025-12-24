#pragma region 函数重载
//函数重载: 函数名相同，参数列表不同
/*
    函数重载的规则:
    1. 函数名相同
    2. 参数列表不同
    3. 返回值类型不同
    4. 参数顺序不同
    5. 参数类型不同
    6. 参数个数不同
    7. 参数类型顺序不同
    8. 参数个数顺序不同
*/
// #include <iostream>
// using namespace std;
// int add(int a, int b){
//     return a + b;
// }
// int add(int a, int b, int c){
//     return a + b + c;
// }
// int main(){
//     cout << add(1, 2) << endl;
//     cout << add(1, 2, 3) << endl;
//     return 0;
// }
#pragma endregion

#pragma region 函数默认参数
//函数默认参数: 函数参数有默认值
/*  
    默认参数在最右边
    默认参数必须连续
    默认参数只能在声明时指定一次
*/
// #include <iostream>
// using namespace std;

// // 默认参数必须从右到左连续设置
// void greet(string name, string greeting = "你好", string punctuation = "！") {
//     cout << greeting << "，" << name << punctuation << endl;
// }

// // 计算面积，默认长度为1
// double calculateArea(double length, double width = 1.0) {
//     return length * width;
// }

// int main() {
//     system("chcp 65001>nup");
//     greet("张三");                    // 使用默认的greeting和punctuation
//     greet("李四", "早上好");          // 使用默认的punctuation
//     greet("王五", "晚上好", "。");    // 全部自定义
    
//     cout << "正方形面积：" << calculateArea(5.0) << endl;      // 5x1
//     cout << "长方形面积：" << calculateArea(5.0, 3.0) << endl; // 5x3
    
//     return 0;
// }
#pragma endregion

#pragma region 函数重载注意事项
/*
    函数重载的注意事项:
    1. 函数返回值类型不同不能重载
    2. 函数参数顺序不同不能重载
    3. 函数参数个数不同不能重载
    4. 函数参数类型顺序不同不能重载
    5. 函数参数个数顺序不同不能重载
    6. 函数参数类型不同不能重载
    7. 函数参数个数不同不能重载
    8. 函数参数类型顺序不同不能重载
*/
// #include <iostream>
// using namespace std;

// // 正确的重载：参数类型不同
// void print(int value) {
//     cout << "整数：" << value << endl;
// }

// void print(string text) {
//     cout << "字符串：" << text << endl;
// }

// // 正确的重载：参数个数不同
// void print(int a, int b) {
//     cout << "两个整数：" << a << " 和 " << b << endl;
// }

// // 错误的重载示例（注释掉避免编译错误）
// // int print(int value) {  // 错误！仅返回类型不同不能重载
// //     return value;
// // }

// int main() {
//     print(42);
//     print("Hello World");
//     print(10, 20);
    
//     return 0;
// }
#pragma endregion

#pragma region 重载的实际应用
// 重载的实际应用
// #include <iostream>
// using namespace std;

// class Calculator {
// public:
//     // 整数运算
//     int calculate(int a, int b, char op) {
//         switch(op) {
//             case '+': return a + b;
//             case '-': return a - b;
//             case '*': return a * b;
//             case '/': return a / b;
//             default: return 0;
//         }
//     }
    
//     // 浮点数运算
//     double calculate(double a, double b, char op) {
//         switch(op) {
//             case '+': return a + b;
//             case '-': return a - b;
//             case '*': return a * b;
//             case '/': return a / b;
//             default: return 0.0;
//         }
//     }
// };

// int main() {
//     system("chcp 65001>nul");
//     Calculator calc;
    
//     cout << "整数运算：5 + 3 = " << calc.calculate(5, 3, '+') << endl;
//     cout << "浮点运算：2.5 * 4.0 = " << calc.calculate(2.5, 4.0, '*') << endl;
    
//     return 0;
// }
#pragma endregion

#pragma region 内联函数
// 内联函数
// 内联函数是编译器在编译时将函数体直接插入到调用处，从而提高执行效率
//简单的计算和简单的条件判断适合使用内联函数
//循环和递归函数则不建议使用内联函数

// #include <iostream>
// using namespace std;

// // 内联函数定义
// inline int max(int a, int b) {
//     return (a > b) ? a : b;
// }

// inline double square(double x) {
//     return x * x;
// }

// // 复杂函数不适合内联
// inline void complexFunction() {
//     for (int i = 0; i < 1000; i++) {
//         cout << i << " ";
//     }
//     cout << endl;
// }

// // 不适合内联：包含循环
// void printNumbers(int n) {  // 没有使用inline
//     for (int i = 1; i <= n; i++) {
//         cout << i << " ";
//     }
//     cout << endl;
// }

// // 不适合内联：递归函数
// int factorial(int n) {      // 没有使用inline
//     if (n <= 1) return 1;
//     return n * factorial(n - 1);
// }

// int main() {
//     system("chcp 65001>nul");
//     int result = max(10, 20);
//     cout << "最大值：" << result << endl;
    
//     double area = square(5.0);
//     cout << "平方：" << area << endl;
    
//     return 0;
// }
#pragma endregion

#pragma region 递归函数
// 递归函数
// #include <iostream>
// using namespace std;

// // 计算阶乘
// int factorial(int n) {
//     if (n <= 1) return 1;
//     return n * factorial(n - 1);
// }

// // 斐波那契数列
// int fibonacci(int n) {
//     if (n <= 1) return n;
//     return fibonacci(n - 1) + fibonacci(n - 2);
// }


// // 递归计算最大公约数
// int gcd(int a, int b) {
//     if (b == 0) {
//         return a;
//     }
//     return gcd(b, a % b);
// }

// int main() {

//     system("chcp 65001>nul");
//     int result = factorial(5);
//     cout << "阶乘：" << result << endl;
    
//     result = fibonacci(10);
//     cout << "斐波那契" << result << endl;
//     return 0;

// }
#pragma endregion

#pragma region 函数指针
// 函数指针
// 函数指针是指‌向函数的指针变量，它可以⁢存储函数的地址，并通过指⁢针来调用函数。     ⁠            ​               
// #include <iostream>
// using namespace std;

// // 定义几个简单函数
// int add(int a, int b) {
//     return a + b;
// }

// int subtract(int a, int b) {
//     return a - b;
// }

// int multiply(int a, int b) {
//     return a * b;
// }

// int main() {
//     // 声明函数指针
//     int (*operation)(int, int);
    
//     // 函数指针指向add函数
//     operation = add;
//     cout << "10 + 5 = " << operation(10, 5) << endl;
    
//     // 函数指针指向subtract函数
//     operation = subtract;
//     cout << "10 - 5 = " << operation(10, 5) << endl;
    
//     // 函数指针指向multiply函数
//     operation = multiply;
//     cout << "10 * 5 = " << operation(10, 5) << endl;
    
//     return 0;
// }

#pragma endregion

#pragma region 函数指针的实际应用
// #include <iostream>
// using namespace std;

// // 排序算法的比较函数
// bool ascending(int a, int b) {
//     return a < b;
// }

// bool descending(int a, int b) {
//     return a > b;
// }

// // 使用函数指针作为参数的排序函数
// void bubbleSort(int arr[], int size, bool (*compare)(int, int)) {
//     for (int i = 0; i < size - 1; i++) {
//         for (int j = 0; j < size - i - 1; j++) {
//             if (!compare(arr[j], arr[j + 1])) {
//                 swap(arr[j], arr[j + 1]);
//             }
//         }
//     }
// }

// void printArray(int arr[], int size) {
//     for (int i = 0; i < size; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }

// int main() {
//     system("chcp 65001>nul");
//     int numbers[] = {64, 34, 25, 12, 22, 11, 90};
//     int size = sizeof(numbers) / sizeof(numbers[0]);
    
//     cout << "原始数组：";
//     printArray(numbers, size);
    
//     // 升序排序
//     // ascending表示该函数调用的首地址
//     bubbleSort(numbers, size, ascending);
//     cout << "升序排序：";
//     printArray(numbers, size);
    
//     // 降序排序
//     bubbleSort(numbers, size, descending);
//     cout << "降序排序：";
//     printArray(numbers, size);
    
//     return 0;
// }

#pragma endregion

#pragma region Lambda 表达式
// // Lambda 表达式允许我们定义匿名函数，特别适合用于简短的、一次性的函数操作。
// /*
// Lambda 表达式语法：
//     [capture] (parameters) -> return-type { body }
//     说明：
//         [capture] 捕获外部变量:用于获取Lambda表达式外部的变量 甚至修改外部变量的值
//         (parameters) 参数列表
//         -> return-type 返回类型（可省略）
//         { body } 函数体
// 例1：
//     [outerVar](int x, int y) -> int {return OuterVar + x + y;}
//     说明：
//         [outerVar] 表示捕获外部变量 outerVar
//         (int x, int y) 表示参数列表
//         -> int 表示返回类型（可省略）
//         {return OuterVar + x + y;} 表示函数体

// 例2：

//     auto f = [](int x, int y){return x + y;}
//     说明：
//         [] 表示不捕获任何外部变量
//         (int x, int y) 表示参数列表
//         -> 返回类型（可省略）
//         {return x + y;} 表示函数体
// */
// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;

// int main() {
//     system("chcp 65001>nul");
//     // 基本Lambda表达式
//     auto add = [](int a, int b) -> int {
//         return a + b;
//     };
    
//     cout << "5 + 3 = " << add(5, 3) << endl;
    
//     // 捕获外部变量
//     int multiplier = 10;
//     auto multiply = [multiplier](int x) -> int {
//         return x * multiplier;
//     };
    
//     cout << "7 * 10 = " << multiply(7) << endl;
    
//     // 在算法中使用Lambda
//     vector<int> numbers = {1, 2, 3, 4, 5};
    
//     // 使用Lambda进行变换
//     transform(numbers.begin(), numbers.end(), numbers.begin(),
//               [](int x) { return x * x; });

//     // 等价于
//     // for (int i = 0; i < numbers.size(); i++) {
//     //     numbers[i] = numbers[i] * numbers[i];
//     // }
    
//     cout << "平方后的数组：";
//     for (int num : numbers) {
//         cout << num << " ";
//     }
//     cout << endl;
    
//     return 0;
// }

#pragma endregion

#pragma region 实践练习
/*
练习1：函数重载实践
创建一个重载函数calculate，分别实现：

    两个整数的加法
    两个浮点数的加法
    三个整数的加法
*/

// #include <iostream>
// using namespace std;

// int calculate(int a, int b){
//     return a + b;
// }

// float calculate(float a, float b){
//     return a + b;
// }

// int calculate(int a, int b, int c){
//     return a + b + c;
// }

// int main(){
//     system("chcp 65001>nul");
//     cout << "5 + 3 = " << calculate(5, 3) << endl;
//     cout << "5.5 + 3.5 = " << calculate(5.5f, 3.5f) << endl;
//     cout << "5 + 3 + 2 = " << calculate(5, 3, 2) << endl;
// }


/*
练习2：递归应用

使用递归实现：

    计算数字的数位和（如：123 → 1+2+3 = 6）
    判断字符串是否为回文
*/
// #include <iostream>
// using namespace std;
// int sumDigits(int n){
//     // 递归终止条件
//     if(n < 10){
//         return n;
//     }

//     // 递归调用
//     return n % 10 + sumDigits(n / 10);
// }

// int main(){
//     system("chcp 65001>nul");
//     cout << "123 的数位和为：" << sumDigits(123) << endl;

// }


/*
练习3：函数指针应用
创建一个简单‌的计算器程序，使用函数⁢指针实现不同的运算⁢操作。   
*/

#include <iostream>
using namespace std;
int add(int a, int b){
    return a + b;
}

int subtract(int a, int b){
    return a - b;
}

int multiply(int a, int b){
    return a * b;
}



int main(){
    system("chcp 65001>nul");
    int (*operater)(int, int);
    char op = '+';

    switch(op){
        case '+':
            operater = add;
            break;
        case '-':
            operater = subtract;
            break;
        case '*':
            operater = multiply;
            break;
    }

    cout << "5 + 3 = " << operater(5, 3) << endl;

    operater = add;
    cout << "5 + 3 = " << operater(5, 3) << endl;
    operater = subtract;
    cout << "5 - 3 = " << operater(5, 3) << endl;
    operater = multiply;
    cout << "5 * 3 = " << operater(5, 3) << endl;
}

#pragma endregion