#pragma region 类的定义和对象的创建
//面向对象的特征：封装、继承、多态

// 类的基本语法
// #include <iostream>
// #include <string>
// using namespace std;

// class Student {
// private:
//     string name;
//     int age;
//     double score;
    
// public:
//     // 设置学生信息
//     void setInfo(const string& n, int a, double s) {
//         name = n;
//         age = a;
//         score = s;
//     }
    
//     // 获取学生信息
//     string getName() const { return name; }
//     int getAge() const { return age; }
//     double getScore() const { return score; }
    
//     // 显示学生信息
//     void display() const {
//         cout << "姓名：" << name << ", 年龄：" << age 
//              << ", 成绩：" << score << endl;
//     }
    
//     // 判断是否及格
//     bool isPass() const {
//         return score >= 60.0;
//     }
// };

// int main() {
//     system("clear");
//     system("chcp 65001>nul");

//     // 创建对象
//     Student student1;
//     Student student2;
    
//     // 设置信息
//     student1.setInfo("张三", 20, 85.5);
//     student2.setInfo("李四", 19, 58.0);
    
//     // 显示信息
//     student1.display();
//     student2.display();
    
//     // 检查是否及格
//     cout << student1.getName() << (student1.isPass() ? " 及格" : " 不及格") << endl;
//     cout << student2.getName() << (student2.isPass() ? " 及格" : " 不及格") << endl;
    
//     return 0;
// }

// 访问控制
// #include <iostream>
// #include <string>
// using namespace std;

// class Rectangle {
// private:
//     double width;   // 私有成员，只能在类内访问
//     double height;
    
// protected:
//     string color;   // 受保护成员，类内和派生类可访问
    
// public:
//     // 公有成员，任何地方都可访问
//     Rectangle(double w, double h, const string& c) 
//         : width(w), height(h), color(c) {}
    
//     // 公有接口
//     double getWidth() const { return width; }
//     double getHeight() const { return height; }
//     string getColor() const { return color; }
    
//     void setWidth(double w) {
//         if (w > 0) width = w;
//     }
    
//     void setHeight(double h) {
//         if (h > 0) height = h;
//     }
    
//     double area() const {
//         return width * height;
//     }
    
//     double perimeter() const {
//         return 2 * (width + height);
//     }
    
//     void display() const {
//         cout << "矩形信息：" << endl;
//         cout << "宽度：" << width << ", 高度：" << height << endl;
//         cout << "颜色：" << color << endl;
//         cout << "面积：" << area() << ", 周长：" << perimeter() << endl;
//     }
// };

// int main() {
//     system("clear");
//     system("chcp 65001>nul");
//     Rectangle rect(5.0, 3.0, "红色");
    
//     // 可以访问公有成员
//     cout << "宽度：" << rect.getWidth() << endl;
//     rect.setWidth(6.0);
    
//     // 无法直接访问私有成员
//     // cout << rect.width;  // 错误！无法访问private成员
    
//     rect.display();
    
//     return 0;
// }


// 成员函数的定义
// #include <iostream>
// #include <string>
// using namespace std;

// class Circle {
// private:
//     double radius;
//     static const double PI;  // 静态常量成员
    
// public:
//     // 在类内定义的成员函数（内联函数）
//     Circle(double r) : radius(r) {}
    
//     double getRadius() const { return radius; }
    
//     // const 表示该函数不修改类的任何成员变量
//     // 函数内部只能读取成员变量，不能修改它们
//     // 在类外定义的成员函数的声明
//     void setRadius(double r);
//     double area() const;
//     double circumference() const;
//     void display() const;
// };

// // 静态常量成员的定义
// const double Circle::PI = 3.14159;

// // 在类外定义成员函数
// void Circle::setRadius(double r) {
//     if (r > 0) {
//         radius = r;
//     } else {
//         cout << "半径必须大于0" << endl;
//     }
// }

// double Circle::area() const {
//     return PI * radius * radius;
// }

// double Circle::circumference() const {
//     return 2 * PI * radius;
// }

// void Circle::display() const {
//     cout << "圆的半径：" << radius << endl;
//     cout << "圆的面积：" << area() << endl;
//     cout << "圆的周长：" << circumference() << endl;
// }

// int main() {
//     system("clear");
//     system("chcp 65001>nul");
//     Circle circle(5.0);
    
//     circle.display();
    
//     cout << "\n修改半径后：" << endl;
//     circle.setRadius(8.0);
//     circle.display();
    
//     return 0;
// }

#pragma endregion


#pragma region 静态成员
// 静态成员属于整个类，而不是某个特定的对象：
// #include <iostream>
// #include <string>
// using namespace std;

// class Counter {
// private:
//     // 所有类对象共享同一个静态数据成员
//     static int objectCount;  // 静态数据成员
//     int id;
    
// public:
//     Counter() {
//         id = ++objectCount;
//         cout << "创建了第" << id << "个Counter对象" << endl;
//     }
    
//     ~Counter() {
//         --objectCount;
//         cout << "销毁了第" << id << "个Counter对象" << endl;
//     }
    
//     // 静态成员函数
//     static int getObjectCount() {
//         return objectCount;
//     }
    
//     int getId() const { return id; }
// };

// // 静态数据成员的定义
// int Counter::objectCount = 0;

// int main() {
//     system("clear");
//     system("chcp 65001>nul");
//     cout << "当前对象数量：" << Counter::getObjectCount() << endl;
    
//     Counter c1;
//     Counter c2;
    
//     cout << "当前对象数量：" << Counter::getObjectCount() << endl;
    
//     {
//         Counter c3;
//         Counter c4;
//         cout << "当前对象数量：" << Counter::getObjectCount() << endl;
//     }
    
//     cout << "作用域结束后，当前对象数量：" << Counter::getObjectCount() << endl;
    
//     return 0;
// }

#pragma endregion


#pragma region 友元函数
//在类中定义了‌私有和保护成员后，外部⁢无法直接访问这些成员，
//⁢而友元函数则提供了一个⁠入口，让外部可以访问类​的私有和受保护成员：

// #include <iostream>
// #include <string>
// #include <cmath>
// using namespace std;

// class Point {
// private:
//     double x, y;
    
// public:
//     Point(double x_val, double y_val) : x(x_val), y(y_val) {}
    
//     // 友元函数声明
//     friend double distance(const Point& p1, const Point& p2);
//     friend void displayPoint(const Point& p);
    
//     // 友元类声明
//     friend class PointManager;
// };

// // 友元函数定义
// double distance(const Point& p1, const Point& p2) {
//     double dx = p1.x - p2.x;
//     double dy = p1.y - p2.y;
//     return sqrt(dx * dx + dy * dy);
// }

// void displayPoint(const Point& p) {
//     cout << "点的坐标：(" << p.x << ", " << p.y << ")" << endl;
// }

// // 友元类
// class PointManager {
// public:
//     void movePoint(Point& p, double dx, double dy) {
//         p.x += dx;
//         p.y += dy;
//     }
    
//     Point midPoint(const Point& p1, const Point& p2) {
//         return Point((p1.x + p2.x) / 2, (p1.y + p2.y) / 2);
//     }
// };

// int main() {
//     system("clear");
//     system("chcp 65001>nul");
//     Point p1(1.0, 2.0);
//     Point p2(4.0, 6.0);
    
//     displayPoint(p1);
//     displayPoint(p2);
    
//     cout << "两点间距离：" << distance(p1, p2) << endl;
    
//     PointManager manager;
//     manager.movePoint(p1, 1.0, 1.0);
//     cout << "移动后：" << endl;
//     displayPoint(p1);
    
//     Point mid = manager.midPoint(p1, p2);
//     cout << "中点：" << endl;
//     displayPoint(mid);
    
//     return 0;
// }


#pragma endregion


#pragma region 常量成员和常量成员函数
// #include <iostream>
// #include <string>
// using namespace std;

// class Book {
// private:
//     const string isbn;  // 常量成员变量
//     string title;
//     string author;
//     double price;
    
// public:
//     // 常量成员必须在初始化列表中初始化
//     Book(const string& isbn_val, const string& title_val, 
//          const string& author_val, double price_val)
//         : isbn(isbn_val), title(title_val), author(author_val), price(price_val) {}
    
//     // 常量成员函数，不能修改对象的状态
//     string getISBN() const { return isbn; }
//     string getTitle() const { return title; }
//     string getAuthor() const { return author; }
//     double getPrice() const { return price; }
    
//     // 非常量成员函数，可以修改对象的状态
//     void setPrice(double newPrice) {
//         price = newPrice;
//     }
    
//     void setTitle(const string& newTitle) {
//         title = newTitle;
//     }
    
//     // 常量成员函数
//     void display() const {
//         cout << "ISBN: " << isbn << endl;
//         cout << "书名: " << title << endl;
//         cout << "作者: " << author << endl;
//         cout << "价格: " << price << endl;
//     }
// };

// int main() {
//     system("clear");
//     system("chcp 65001>nul");
//     Book book("978-7-111-12345-6", "C++程序设计", "张三", 59.0);
    
//     book.display();
    
//     // 修改价格
//     book.setPrice(55.0);
//     cout << "\n修改价格后：" << endl;
//     book.display();
    
//     // 常量对象只能调用常量成员函数
//     const Book constBook("978-7-111-54321-0", "数据结构", "李四", 45.0);
//     constBook.display();
//     // constBook.setPrice(40.0);  // 错误！常量对象不能调用非常量成员函数
    
//     return 0;
// }
#pragma endregion

#pragma region 时间类的设计
// #include <iostream>
// #include <iomanip>
// using namespace std;

// class Time {
// private:
//     int hour;
//     int minute;
//     int second;
    
//     // 私有辅助函数
//     void normalize() {
//         if (second >= 60) {
//             minute += second / 60;
//             second %= 60;
//         }
//         if (minute >= 60) {
//             hour += minute / 60;
//             minute %= 60;
//         }
//         hour %= 24;
//     }
    
// public:
//     // 构造函数
//     Time(int h = 0, int m = 0, int s = 0) : hour(h), minute(m), second(s) {
//         normalize();
//     }
    
//     // 获取时间分量
//     int getHour() const { return hour; }
//     int getMinute() const { return minute; }
//     int getSecond() const { return second; }
    
//     // 设置时间
//     void setTime(int h, int m, int s) {
//         hour = h;
//         minute = m;
//         second = s;
//         normalize();
//     }
    
//     // 增加秒数
//     void addSeconds(int seconds) {
//         second += seconds;
//         normalize();
//     }
    
//     // 增加分钟数
//     void addMinutes(int minutes) {
//         minute += minutes;
//         normalize();
//     }
    
//     // 增加小时数
//     void addHours(int hours) {
//         hour += hours;
//         normalize();
//     }
    
//     // 显示时间
//     void display() const {
//         cout << setfill('0') << setw(2) << hour << ":"
//              << setfill('0') << setw(2) << minute << ":"
//              << setfill('0') << setw(2) << second << endl;
//     }
    
//     // 比较时间
//     bool isEarlierThan(const Time& other) const {
//         if (hour != other.hour) return hour < other.hour;
//         if (minute != other.minute) return minute < other.minute;
//         return second < other.second;
//     }
    
//     // 计算时间差（返回秒数）
//     int differenceInSeconds(const Time& other) const {
//         int thisSeconds = hour * 3600 + minute * 60 + second;
//         int otherSeconds = other.hour * 3600 + other.minute * 60 + other.second;
//         return thisSeconds - otherSeconds;
//     }
// };

// int main() {
//     system("clear");
//     system("chcp 65001>nul");
//     Time time1(9, 30, 45);
//     Time time2(14, 25, 30);
    
//     cout << "时间1：";
//     time1.display();
//     cout << "时间2：";
//     time2.display();
    
//     cout << "\n时间1增加90秒后：";
//     time1.addSeconds(90);
//     time1.display();
    
//     cout << "时间2增加45分钟后：";
//     time2.addMinutes(45);
//     time2.display();
    
//     cout << "\n时间比较：";
//     if (time1.isEarlierThan(time2)) {
//         cout << "时间1早于时间2" << endl;
//     } else {
//         cout << "时间1晚于或等于时间2" << endl;
//     }
    
//     return 0;
// }

#pragma endregion

#pragma region 银行账户类的设计
// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;

// class Transaction {
// public:
//     enum Type { DEPOSIT, WITHDRAWAL };
    
// private:
//     Type type;
//     double amount;
//     string description;
    
// public:
//     Transaction(Type t, double amt, const string& desc)
//         : type(t), amount(amt), description(desc) {}
    
//     Type getType() const { return type; }
//     double getAmount() const { return amount; }
//     string getDescription() const { return description; }
    
//     void display() const {
//         cout << (type == DEPOSIT ? "存款" : "取款") << ": "
//              << amount << " - " << description << endl;
//     }
// };

// class BankAccount {
// private:
//     string accountNumber;
//     string ownerName;
//     double balance;
//     vector<Transaction> transactions;
    
// public:
//     BankAccount(const string& accNum, const string& name, double initialBalance = 0.0)
//         : accountNumber(accNum), ownerName(name), balance(initialBalance) {}
    
//     string getAccountNumber() const { return accountNumber; }
//     string getOwnerName() const { return ownerName; }
//     double getBalance() const { return balance; }
    
//     bool deposit(double amount, const string& description = "") {
//         if (amount <= 0) {
//             cout << "存款金额必须大于0" << endl;
//             return false;
//         }
        
//         balance += amount;
//         transactions.push_back(Transaction(Transaction::DEPOSIT, amount, description));
//         cout << "存款成功！当前余额：" << balance << endl;
//         return true;
//     }
    
//     bool withdraw(double amount, const string& description = "") {
//         if (amount <= 0) {
//             cout << "取款金额必须大于0" << endl;
//             return false;
//         }
        
//         if (amount > balance) {
//             cout << "余额不足！当前余额：" << balance << endl;
//             return false;
//         }
        
//         balance -= amount;
//         transactions.push_back(Transaction(Transaction::WITHDRAWAL, amount, description));
//         cout << "取款成功！当前余额：" << balance << endl;
//         return true;
//     }
    
//     void displayInfo() const {
//         cout << "账户信息：" << endl;
//         cout << "账号：" << accountNumber << endl;
//         cout << "户主：" << ownerName << endl;
//         cout << "余额：" << balance << endl;
//     }
    
//     void displayTransactions() const {
//         cout << "交易记录：" << endl;
//         for (const auto& transaction : transactions) {
//             transaction.display();
//         }
//     }
// };

// int main() {
//     system("clear");
//     system("chcp 65001>nul");
//     BankAccount account("123456789", "张三", 1000.0);
    
//     account.displayInfo();
    
//     cout << "\n进行一些交易：" << endl;
//     account.deposit(500.0, "工资");
//     account.withdraw(200.0, "购买日用品");
//     account.withdraw(2000.0, "购买电脑");  // 余额不足
//     account.deposit(300.0, "奖金");
    
//     cout << "\n最终账户信息：" << endl;
//     account.displayInfo();
    
//     cout << "\n交易历史：" << endl;
//     account.displayTransactions();
    
//     return 0;
// }

#pragma endregion

#pragma region 实践1-设计一个学生类

/*
要求：

    包含姓名、学号、年龄、成绩等属性
    提供设置和获取信息的方法
    实现成绩等级判断功能
    提供比较成绩的方法
*/
    
// #include <iostream>
// #include <string>
// using namespace std;
// class student{
//     private:
//         string name;
//         string studentID;
//         int age;
//         int score;
//     public:

//     student(string name_val, string studentID_val, int age_val, int score_val)
//         : name(name_val), studentID(studentID_val), age(age_val), score(score_val) {}

//     string getName(){return name;}
//     string getStudentID(){return studentID;}
//     int getAge(){return age;}
//     int getScore(){return score;}
//     void setAge(int age_val){age = age_val;}
//     void setScore(int score_val){score = score_val;}

//     void display() const {
//         cout << "姓名：" << name << ", 学号：" << studentID 
//              << ", 年龄：" << age << ", 成绩：" << score << endl;
//     }

//     string getGrade() const {
//         if (score >= 90) return "A";
//         if (score >= 80) return "B";
//         if (score >= 70) return "C";
//         if (score >= 60) return "D";
//         return "E";
//     }

//     bool compareScore(const student& other) const {
//         return score < other.score;
//     }

// };

// int main(){
//     system("clear");
//     system("chcp 65001>nul");
//     student stu1("张三", "1001", 18, 85);
//     student stu2("李四", "1002", 19, 92);
    
//     stu1.display();
//     cout << "等级：" << stu1.getGrade() << endl;
    
//     stu2.display();
//     cout << "等级：" << stu2.getGrade() << endl;
    
//     if (stu1.compareScore(stu2)) {
//         cout << stu1.getName() << "的成绩低于" << stu2.getName() << endl;
//     } else {
//         cout << stu1.getName() << "的成绩不低于" << stu2.getName() << endl;
//     }
//     return 0;
// }

#pragma endregion



#pragma region 实践2-图书类
/*
要求：
    包含书名、作者、ISBN、价格等属性
    提供借阅和归还功能
    实现图书信息的显示
    提供按不同条件查找的方法
*/

#include <iostream>
#include <string>
using namespace std;
class Book{
    private:
        string title;
        string author;
        string ISBN;
        double price;
        bool isBorrowed;

    public:
        Book(string t, string a, string i, double p) : title(t), author(a), ISBN(i), price(p), isBorrowed(false) {}
        void borrow(){isBorrowed = true;}
        void turnIn(){isBorrowed = false;}
        
        void display() const {
            cout << "书名：" << title << ", 作者：" << author << ", ISBN：" << ISBN << ", 价格：" << price << endl;
        }
        // 按书名查找
        bool findByTitle(string t) const {
            return title == t;
        }
        // 按作者查找
        bool findByAuthor(string a) const {
            return author == a;
        }
        bool findByISBN(string i) const {
            return ISBN == i;
        }
        bool ifBorrowed() const {
            return isBorrowed;
        }

};


int main(){
    system("clear");
    system("chcp 65001>nul");
    
    Book book1("C++ Primer", "Stanley B. Lippman", "978-0-321-71411-4", 99.0);
    book1.display();
    book1.borrow();
    cout << "是否被借出: " << (book1.ifBorrowed() ? "是" : "否") << endl;
    book1.turnIn();

    return 0;
}
#pragma endregion
