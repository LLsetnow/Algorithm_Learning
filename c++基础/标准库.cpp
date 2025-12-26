
#pragma region <string>
// #include <iostream>
// #include <string>
// using namespace std;

// int main(){
//     system("clear");
//     system("chcp 65001>nul");
    
//     // 初始化字符串
//     string str = "Hello World";
//     cout << "str = " << str << endl;

//     //字符串大小
//     int len = str.length();
//     cout << "len = " << len << endl;
//     len = str.size();
//     cout << "len = " << len << endl;

//     // 连接字符串
//     string str2 = str + "!";
//     cout << "str2 = " << str2 << endl;

//     // 整形转换为字符串
//     int num = 123;
//     string str3 = to_string(num);
//     cout << "str3 = " << str3 << endl;

//     // 访问字符串中的字符
//     cout << "str[0] = " << str[0] << endl;
//     cout << "str[str.length()-1] = " << str[str.length()-1] << endl;

//     // 判断字符串是否为空
//     if (str.empty()) {
//         cout << "str is empty" << endl;
//     } else {
//         cout << "str is not empty" << endl;
//     }

//     // 返回从指定位置开始的子字符串。
//     string sub = str.substr(0, 5);
//     cout << "sub = " << sub << endl;

//     // 查找字符串中的字符,返回字符串中第一个匹配字符的位置，如果没有找到，则返回 string::npos
//     size_t pos = str.find("World");
//     if (pos != string::npos) {
//         cout << "Found at position " << pos << endl;
//     } else {
//         cout << "Not found" << endl;
//     }

//     // 在字符串末尾添加内容。
//     str.append("!");
//     cout << "str = " << str << endl;

//     // 在指定位置插入内容。
//     str.insert(0, "Hello ");
//     cout << "str = " << str << endl;

    
//     // 清空字符串。
//     str.clear();
//     cout << "str = " << str << endl;

    
//     // 比较两个字符串。
//     string str4 = "Hello";
//     string str5 = "World";
//     int res = str4.compare(str5);
//     if (res == 0) {
//         cout << "str4 == str5" << endl;
//     } else if (res < 0) {
//         cout << "str4 < str5" << endl;
//     } else {
//         cout << "str4 > str5" << endl;
//     }
// }

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
//     cout << "v = ";

//     // 遍历向量
//     for (int x : v) {
//         cout << x << " ";
//     }
//     cout << endl;

//     // 批量初始化
//     vector<int> v1(10);         // 10个0
//     vector<int> v2(10, 5);      // 10个5
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

//     // 迭代访问
//     cout << "v3 = ";
//     for (auto it = v3.begin(); it != v3.end(); it++) {
//         // it 是一个指针，指向当前元素的地址
//         cout << *it << " ";
//     }
//     cout << endl;
// }


#pragma endregion

#pragma region <stack>
#include <iostream>
#include <stack>
using namespace std;

int main(){
    system("clear");
    system("chcp 65001>nul");
    
    // 初始化栈
    stack<int> s;

    // 向栈中添加元素
    s.push(1);
    s.push(2);
    s.push(3);

    // 访问栈顶元素
    std::cout << "Top element is: " << s.top() << std::endl;

    // 移除栈顶元素
    s.pop();
    std::cout << "After popping, top element is: " << s.top() << std::endl;

    // 检查栈是否为空
    if (!s.empty()) {
        std::cout << "Stack is not empty." << std::endl;
    }

    // 打印栈的大小
    std::cout << "Size of stack: " << s.size() << std::endl;

    return 0;
}

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

// }
#pragma endregion