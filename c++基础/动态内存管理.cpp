#pragma region 动态内存分配基础

// #include <iostream>
// using namespace std;


// // 为什么需要动态内存分配
// int main(){
//     system("chcp 65001>nul");

//     int n;
//     cout << "请输入要存储的数字个数：";
//     cin >> n;
    
//     // 静态分配无法处理这种情况
//     // int arr[n];  // 错误！数组大小必须是常量
    
//     // 动态分配可以根据运行时的值分配内存
//     int* arr = new int[n];
    
//     cout << "请输入" << n << "个数字：";
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }
    
//     cout << "您输入的数字是：";
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
    
//     // 释放内存
//     delete[] arr;
    
//     return 0;
// }


// 栈内存和堆内存
// 栈内存：自动分配和释放，速度快，但大小固定
// 堆内存：手动分配和释放，速度慢，但大小可变


// void demonstrateMemoryTypes() {
//     // 栈内存：自动管理，作用域结束时自动释放
//     int stackVar = 42;
//     int stackArray[10];
    
//     cout << "栈变量地址：" << &stackVar << endl;
//     cout << "栈数组地址：" << stackArray << endl;

//     // 堆内存：手动管理，需要显式释放

//     // heapVar 分配单个整型变量并初始化为100
//     int *heapVar = new int(100);
//     // heapArray 分配包含10个整型元素的数组，未初始化
//     int *heapArray = new int[10];

//     cout << "堆变量地址：" << heapVar << endl;
//     cout << "堆数组地址：" << heapArray << endl;
    
//     // 堆内存必须手动释放
//     delete heapVar;
//     delete[] heapArray;
// }

// int main() {
//     demonstrateMemoryTypes();
    
//     cout << "函数执行完毕，栈内存自动释放，堆内存已手动释放" << endl;
    
//     return 0;
// }


#pragma endregion

#pragma region new delete class构造函数

// 基本用法
// #include <iostream>
// using namespace std;

// int main() {
//     // 分配单个整数
//     int* ptr1 = new int;        // 分配但不初始化
//     int* ptr2 = new int(42);    // 分配并初始化为42
//     int* ptr3 = new int{100};   // C++11统一初始化语法
    
//     cout << "ptr1指向的值：" << *ptr1 << endl;  // 未初始化，值不确定
//     cout << "ptr2指向的值：" << *ptr2 << endl;  // 42
//     cout << "ptr3指向的值：" << *ptr3 << endl;  // 100
    
//     // 分配数组
//     int size = 5;
//     int* arr = new int[size];
    
//     // 初始化数组
//     for (int i = 0; i < size; i++) {
//         // 指针解引用方式
//         // *（arr + i） = i * 10;
//         // 数组下标方式
//         // arr[i] = i * 10;
//         arr[i] = i * 10;
//     }
    
//     cout << "动态数组内容：";
//     for (int i = 0; i < size; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
    
//     // 释放内存
//     delete ptr1;
//     delete ptr2;
//     delete ptr3;
//     delete[] arr;  // 注意数组使用delete[]
    
//     return 0;
// }

// 动态分配对象

// #include <iostream>
// #include <string>
// using namespace std;

// class Student {
// private:
//     string name;
//     int age;
//     double score;
    
// public:
//     Student() : name("未知"), age(0), score(0.0) {
//         cout << "Student默认构造函数被调用" << endl;
//     }
    
//     Student(const string& n, int a, double s) : name(n), age(a), score(s) {
//         cout << "Student参数构造函数被调用：" << name << endl;
//     }
    
//     ~Student() {
//         cout << "Student析构函数被调用：" << name << endl;
//     }
    
//     void display() const {
//         cout << "姓名：" << name << ", 年龄：" << age 
//              << ", 成绩：" << score << endl;
//     }
    
//     void setInfo(const string& n, int a, double s) {
//         name = n;
//         age = a;
//         score = s;
//     }
// };

// int main() {
//     system("chcp 65001>nul");
//     // 静态分配对象
//     // Student() student;
//     // student.setInfo("张三", 20, 85.5);
//     // student.display();

//     // 动态分配单个对象
//     Student* student1 = new Student();
//     student1->setInfo("张三", 20, 85.5);
//     student1->display();
    
//     Student* student2 = new Student("李四", 21, 92.0);
//     student2->display();
    
//     // 动态分配对象数组
//     int count = 3;
//     Student* students = new Student[count];
    
//     students[0].setInfo("王五", 19, 78.0);
//     students[1].setInfo("赵六", 20, 88.5);
//     students[2].setInfo("孙七", 21, 91.0);
    
//     cout << "\n学生列表：" << endl;
//     for (int i = 0; i < count; i++) {
//         students[i].display();
//     }
    
//     // 释放内存
//     delete student1;
//     delete student2;
//     delete[] students;
    
//     return 0;
// }

// 注意事项

// #include <iostream>
// using namespace std;

// int main() {
//     system("chcp 65001>nul");
//     // 正确的配对使用
//     int* ptr1 = new int(42);
//     delete ptr1;  // 正确
    
//     int* arr1 = new int[10];
//     delete[] arr1;  // 正确
    
//     // 错误的使用方式（注释掉避免程序崩溃）
//     // int* ptr2 = new int(42);
//     // delete[] ptr2;  // 错误！new对应delete，不是delete[]
    
//     // int* arr2 = new int[10];
//     // delete arr2;  // 错误！new[]对应delete[]，不是delete
    
//     // 避免重复释放
//     int* ptr3 = new int(42);
//     delete ptr3;
//     ptr3 = nullptr;  // 设置为空指针
    
//     // 现在可以安全地再次删除
//     delete ptr3;  // 删除空指针是安全的
    
//     // 检查分配是否成功
//     // nothrow 告诉编译器：如果内存分配失败，抛出异常而不是返回 nullptr
//     int* ptr4 = new(std::nothrow) int[1000000000];  // 可能失败的大内存分配
//     if (ptr4 == nullptr) {
//         cout << "内存分配失败！" << endl;
//     } else {
//         cout << "内存分配成功！" << endl;
//         delete[] ptr4;
//     }
//     return 0;
// }


#pragma endregion


#pragma region 内存泄漏和悬挂指针
/*
内存泄漏是指
    程序在动态分配内存后，未能正确释放不再使用的内存空间，导致系统可用内存不断减少的现象。
    这些泄漏的内存无法被程序再次使用，也无法被操作系统回收，直到程序终止才被释放。
*/


//内存泄漏的问题
// #include <iostream>
// using namespace std;

// // 错误示例：内存泄漏
// void memoryLeakExample() {
//     int* ptr = new int(42);
//     cout << "分配了内存，值为：" << *ptr << endl;
    
//     // 函数结束时没有delete，造成内存泄漏
//     // delete ptr;  // 应该有这行代码
// }

// // 正确示例：避免内存泄漏
// void properMemoryManagement() {
//     int* ptr = new int(42);
//     cout << "分配了内存，值为：" << *ptr << endl;
    
//     // 正确释放内存
//     delete ptr;
//     ptr = nullptr;
// }

// // 异常安全的内存管理
// void exceptionSafeExample() {
//     int* ptr = new int(42);
    
//     try {
//         // 可能抛出异常的代码
//         if (*ptr > 40) {
//             throw runtime_error("值太大了！");
//         }
        
//         cout << "处理完成" << endl;
//     } catch (...) {
//         // 即使发生异常也要释放内存
//         delete ptr;
//         throw;  // 重新抛出异常
//     }
    
//     delete ptr;
// }

// int main() {
//     system("chcp 65001>nul");
//     cout << "演示内存泄漏（注意：这会造成内存泄漏）" << endl;
//     memoryLeakExample();
    
//     cout << "\n演示正确的内存管理" << endl;
//     properMemoryManagement();
    
//     cout << "\n演示异常安全的内存管理" << endl;
//     try {
//         exceptionSafeExample();
//     } catch (const exception& e) {
//         cout << "捕获异常：" << e.what() << endl;
//     }
    
//     return 0;
// }


// 悬挂指针问题
// 释放内存后，指针仍然指向已释放的内存
// 正确的做法是将所有指向该内存的指针设置为空指针

// #include <iostream>
// using namespace std;


// int main() {
//     system("chcp 65001>nul");
//     int* ptr1 = new int(42);
//     int* ptr2 = ptr1;  // 两个指针指向同一内存
    
//     cout << "ptr1指向的值：" << *ptr1 << endl;
//     cout << "ptr2指向的值：" << *ptr2 << endl;
    
//     delete ptr1;  // 释放内存
//     ptr1 = nullptr;  // ptr1设置为空指针
    
//     // 现在ptr2成为悬挂指针
//     cout << "ptr1 == nullptr: " << (ptr1 == nullptr) << endl;
    
//     // 下面的操作是危险的！
//     // cout << "ptr2指向的值：" << *ptr2 << endl;  // 危险！访问已释放的内存
    
//     // 正确的做法：也将ptr2设置为nullptr
//     ptr2 = nullptr;
    
//     cout << "现在ptr2也是空指针了" << endl;
    
//     return 0;
// }
#pragma endregion

#pragma region 动态内存管理的最佳实践

// RAII（资源获取即初始化）
#include <iostream>
#include <string>
using namespace std;

class SafeArray {
private:
    int* data;
    int size;
    
public:
    SafeArray(int s) : size(s) {
        data = new int[size];
        cout << "SafeArray构造函数：分配了" << size << "个整数的内存" << endl;
    }
    
    ~SafeArray() {
        delete[] data;
        cout << "SafeArray析构函数：释放了内存" << endl;
    }
    
    // 禁止拷贝构造和赋值（避免浅拷贝问题）
    SafeArray(const SafeArray&) = delete;
    SafeArray& operator=(const SafeArray&) = delete;
    
    int& operator[](int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("索引超出范围");
        }
        return data[index];
    }
    
    int getSize() const { return size; }
};

int main() {
    try {
        SafeArray arr(5);
        
        // 使用数组
        for (int i = 0; i < arr.getSize(); i++) {
            arr[i] = i * 10;
        }
        
        cout << "数组内容：";
        for (int i = 0; i < arr.getSize(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        
        // 即使发生异常，析构函数也会被调用
        // arr[10] = 100;  // 这会抛出异常
        
    } catch (const exception& e) {
        cout << "异常：" << e.what() << endl;
    }
    
    cout << "程序结束，内存自动释放" << endl;
    
    return 0;
}



#pragma endregion