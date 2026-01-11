#include <D:\github\Algorithm_Learning\LeetCode\headfile\stdc++.h>
using namespace std;

// unordered_set 不保证元素的排序，但通常提供更快的查找、插入和删除操作
// unordered_set 的迭代器是 const 的，不能修改元素的值

int main() {
    system("clear");
    system("chcp 65001>nul");
    
    // 构造函数
    // 集合内的元素是无序的，且不允许重复
    unordered_set<int> s = {1, 2, 3, 4, 5, 5};
    cout << "当前集合的大小为" << s.size() << endl;
    // 遍历集合
    for (int x : s) {
        // 不保证元素的排序
        cout << x << " ";
    }
    cout << endl;
    // 插入元素
    s.insert(6);
    
    // 删除元素
    s.erase(3);
    
    // 查找元素
    if (s.find(4) != s.end()) {
        cout << "元素 4 存在" << endl;
    }
    
    // 大小
    size_t size = s.size();
    cout << "集合的大小：" << size << endl;
    
    // 空检查
    if (s.empty()) {
        cout << "集合为空" << endl;
    }
    
    // 清空集合
    s.clear();

    // 将字符串转换为集合
    string str = "Hello World";
    cout << "\n原字符串: \"" << str << "\"" << endl;
    cout << "字符串长度: " << str.length() << endl;
    
    // 展示迭代器指向的内容
    cout << "*str.begin() = '" << *str.begin() << "'" << endl;  // 'H'
    cout << "str[0] = '" << str[0] << "'" << endl;              // 'H'
    cout << "str[str.length()-1] = '" << str[str.length()-1] << "'" << endl;  // 'd'
    
    // 使用迭代器范围构造unordered_set
    unordered_set<char> s2(str.begin(), str.end());
    
    cout << "\n转换后的unordered_set内容（自动去重）：" << endl;
    for (char c : s2) {
        cout << "'" << c << "' ";
    }

    return 0;
}
