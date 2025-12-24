#pragma region 结构体基础

// 结构体初始化
// #include <iostream>
// #include <string>
// using namespace std;

// struct Book {
//     string title;
//     string author;
//     int pages;
//     double price;
// };

// int main() {
//     system("chcp 65001>nul");
//     // 方法1：逐个赋值
//     Book book1;
//     book1.title = "C++程序设计";
//     book1.author = "张教授";
//     book1.pages = 500;
//     book1.price = 58.0;
    
//     // 方法2：初始化列表
//     Book book2 = {"数据结构", "李教授", 400, 45.0};
    
//     // 方法3：部分初始化
//     // pages和price会被初始化为0
//     Book book3 = {"算法导论", "王教授"};  
    
//     // 方法4：C++11统一初始化
//     Book book4{"操作系统", "赵教授", 350, 52.0};
    
//     cout << "书籍1：" << book1.title << " - " << book1.author << endl;
//     cout << "书籍2：" << book2.title << " - " << book2.author << endl;
//     cout << "书籍3：" << book3.title << " - " << book3.author << 
//             " (页数：" << book3.pages << ")" << endl;
//     cout << "书籍4：" << book4.title << " - " << book4.author << endl;
    
//     return 0;
// }

// 结构体嵌套
// #include <iostream>
// #include <string>
// using namespace std;

// // 地址结构体
// struct Address {
//     string city;
//     string street;
//     int zipCode;
// };

// // 人员结构体（包含地址）
// struct Person {
//     string name;
//     int age;
//     Address address;  // 嵌套结构体
// };

// int main() {
//     system("chcp 65001>nul");
//     Person person1;
    
//     // 设置基本信息
//     person1.name = "李明";
//     person1.age = 25;
    
//     // 设置地址信息
//     person1.address.city = "北京";
//     person1.address.street = "中关村大街";
//     person1.address.zipCode = 100086;
    
//     cout << "人员信息：" << endl;
//     cout << "姓名：" << person1.name << endl;
//     cout << "年龄：" << person1.age << endl;
//     cout << "地址：" << person1.address.city << "市" 
//          << person1.address.street << endl;
//     cout << "邮编：" << person1.address.zipCode << endl;

//     return 0;
// }

#pragma endregion

#pragma region 结构体数组

// #include <iostream>

// #include <iostream>
// #include <string>
// using namespace std;

// struct Product {
//     string name;
//     double price;
//     int quantity;
// };

// int main() {
//     system("chcp 65001>nul");
//     // 创建结构体数组
//     Product products[3] = {
//         {"笔记本电脑", 5999.0, 10},
//         {"手机", 2999.0, 25},
//         {"耳机", 299.0, 50}
//     };
    
//     cout << "产品清单：" << endl;
//     cout << "名称\t\t价格\t数量" << endl;
//     cout << "------------------------" << endl;
    
//     for (int i = 0; i < 3; i++) {
//         cout << products[i].name << "\t\t" 
//              << products[i].price << "\t" 
//              << products[i].quantity << endl;
//     }
    
//     // 计算总价值
//     double totalValue = 0;
//     for (int i = 0; i < 3; i++) {
//         totalValue += products[i].price * products[i].quantity;
//     }
    
//     cout << "\n总价值：" << totalValue << "元" << endl;
    
//     return 0;
// }
#pragma endregion

#pragma region 结构体指针
// 多用于链表节点
// #include <iostream>
// #include <string>
// using namespace std;

// struct Car {
//     string brand;
//     string model;
//     int year;
//     double price;
// };

// int main() {
//     system("chcp 65001>nul");
//     Car car1 = {"丰田", "卡罗拉", 2023, 128000.0};
    
//     // 创建结构体指针
//     Car* carPtr = &car1;
    
//     // 通过指针访问结构体成员（两种方式）
//     // 方式1：使用(*pointer).member
//     // 方式2：使用pointer->member
//     cout << "方式1 - 使用(*pointer).member：" << endl;
//     cout << "品牌：" << (*carPtr).brand << endl;
//     cout << "型号：" << (*carPtr).model << endl;
    
//     cout << "\n方式2 - 使用pointer->member：" << endl;
//     cout << "品牌：" << carPtr->brand << endl;
//     cout << "型号：" << carPtr->model << endl;
//     cout << "年份：" << carPtr->year << endl;
//     cout << "价格：" << carPtr->price << endl;
    
//     // 通过指针修改数据
//     carPtr->price = 125000.0;
//     cout << "\n修改后的价格：" << car1.price << endl;
    
//     return 0;
// }
#pragma endregion

#pragma region 动态分配结构体

// #include <iostream>
// #include <string>
// using namespace std;

// struct Employee {
//     string name;
//     int id;
//     string department;
//     double salary;
// };

// int main() {
//     system("chcp 65001>nul");
//     // 动态创建结构体
//     Employee* emp = new Employee{"张三", 1001, "销售部", 6000.0};
    
//     // 初始化数据
//     // emp->name = "王五";
//     // emp->id = 2001;
//     // emp->department = "技术部";
//     // emp->salary = 8000.0;
    
//     cout << "员工信息：" << endl;
//     cout << "姓名：" << emp->name << endl;
//     cout << "工号：" << emp->id << endl;
//     cout << "部门：" << emp->department << endl;
//     cout << "薪资：" << emp->salary << endl;
    
//     // 释放内存
//     delete emp;
//     emp = nullptr;
    
//     // 动态创建结构体数组
//     int count = 3;
//     Employee* employees = new Employee[count];
    
//     // 初始化数组
//     employees[0] = {"张三", 1001, "销售部", 6000.0};
//     employees[1] = {"李四", 1002, "技术部", 7500.0};
//     employees[2] = {"王五", 1003, "人事部", 5500.0};
    
//     cout << "\n员工列表：" << endl;
//     for (int i = 0; i < count; i++) {
//         cout << employees[i].name << " - " 
//              << employees[i].department << " - " 
//              << employees[i].salary << "元" << endl;
//     }
    
//     // 释放数组内存
//     delete[] employees;
//     employees = nullptr;
    
//     return 0;
// }
#pragma endregion

#pragma region 枚举体
// #include <iostream>
// using namespace std;

// // 定义星期枚举
// enum Weekday {
//     MONDAY,     // 0
//     TUESDAY,    // 1
//     WEDNESDAY,  // 2
//     THURSDAY,   // 3
//     FRIDAY,     // 4
//     SATURDAY,   // 5
//     SUNDAY      // 6
// };

// // 定义颜色枚举（指定值）
// enum Color {
//     RED = 1,
//     GREEN = 2,
//     BLUE = 3
// };

// int main() {
//     system("chcp 65001>nul");
//     Weekday today = FRIDAY;
//     Color favoriteColor = BLUE;
    
//     cout << "今天是星期：" << today << endl;  // 输出：4
//     cout << "最喜欢的颜色：" << favoriteColor << endl;  // 输出：3
    
//     // 使用枚举进行条件判断
//     if (today == FRIDAY) {
//         cout << "今天是星期五，明天休息！" << endl;
//     }
    
//     // 枚举可以用于switch语句
//     switch (today) {
//         case MONDAY:
//             cout << "新的一周开始了！" << endl;
//             break;
//         case FRIDAY:
//             cout << "终于到周五了！" << endl;
//             break;
//         case SATURDAY:
//         case SUNDAY:
//             cout << "周末愉快！" << endl;
//             break;
//         default:
//             cout << "工作日，加油！" << endl;
//     }
    
//     return 0;
// }

#pragma endregion

#pragma region 强类型枚举
// 强类型枚举是 C++11 的语法特性，包括作用域限定和显式类型转换要求

// #include <iostream>
// using namespace std;

// // 强类型枚举（enum class）
// enum class Status {
//     PENDING,
//     APPROVED,
//     REJECTED
// };

// enum class Priority {
//     LOW,
//     MEDIUM,
//     HIGH
// };

// // 指定底层类型
// enum class ErrorCode : int {
//     SUCCESS = 0,
//     FILE_NOT_FOUND = 404,
//     ACCESS_DENIED = 403,
//     INTERNAL_ERROR = 500
// };

// int main() {
//     Status orderStatus = Status::PENDING;
//     Priority taskPriority = Priority::HIGH;
//     ErrorCode result = ErrorCode::SUCCESS;
    
//     // 强类型枚举不能直接与整数比较
//     // if (orderStatus == 0) { }  // 错误！
    
//     // 正确的比较方式
//     if (orderStatus == Status::PENDING) {
//         cout << "订单状态：等待处理" << endl;
//     }
    
//     // 可以显式转换为整数
//     cout << "任务优先级值：" << static_cast<int>(taskPriority) << endl;
//     cout << "错误代码：" << static_cast<int>(result) << endl;
    
//     // 使用switch语句
//     switch (orderStatus) {
//         case Status::PENDING:
//             cout << "订单正在处理中..." << endl;
//             break;
//         case Status::APPROVED:
//             cout << "订单已批准！" << endl;
//             break;
//         case Status::REJECTED:
//             cout << "订单被拒绝。" << endl;
//             break;
//     }
    
//     return 0;
// }
#pragma endregion

#pragma region 实践练习
/*
练习1：学生管理系统

创建一个学‌生管理系统，包含：⁢         ⁢         ⁠         ​     sIqs0tFIjb3S1uzJwtvS++7m5PbHl0cpQlMEBpPHB/I=

    学生结构体（姓名、学号、成绩）
    成绩等级枚举（A、B、C、D、F）
    实现成绩等级转换功能

*/

// #include <iostream>
// using namespace std;

// enum Grade{
//     A,
//     B,
//     C,
//     D,
//     F
// };

// struct Student
// {
//    string name;
//    string id;
//    int score;
//    Grade grade;
// };

// Grade convertToGrade(int score) {
//     if (score >= 90) {
//         return Grade::A;
//     } else if (score >= 80) {
//         return Grade::B;
//     } else if (score >= 70) {
//         return Grade::C;
//     } else if (score >= 60) {
//         return Grade::D;
//     } else {
//         return Grade::F;
//     }
// }

// string Grade2String(Grade grade){
//     switch (grade)
//     {
//         case Grade::A:
//             return "A";
//         case Grade::B:
//             return "B";
//         case Grade::C:
//             return "C";
//         case Grade::D:
//             return "D";
//         case Grade::F:
//             return "F";
//         default:
//             return "Unknown";
//     }
// }

// int main(){
//     system("chcp 65001>nul");
//     Student student = {"张三", "1001", 85};
//     student.grade = convertToGrade(student.score);
//     cout << "姓名：" << student.name << endl;
//     cout << "学号：" << student.id << endl;
//     cout << "成绩：" << student.score << endl;
//     cout << "等级：" << Grade2String(student.grade) << endl;
// }
#pragma endregion