#include <D:\github\Algorithm_Learning\LeetCode\headfile\stdc++.h>
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