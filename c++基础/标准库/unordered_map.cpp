#include <D:\github\Algorithm_Learning\LeetCode\headfile\stdc++.h>
using namespace std;

// 哈希表
// unordered_map 是无序的，不保证元素的排序，但通常提供更快的查找、插入和删除操作
// unordered_map 的迭代器是 const 的，不能修改元素的值
// nordered_map<elemType_1, elemType_2> var_name;
// elemType_1 是键类型，elemType_2 是值类型

int main() {
    system("clear");
    system("chcp 65001>nul");
    // 构造函数
    unordered_map<int, int> m = {{1, 10}, {2, 20}, {3, 30}};

    cout << "当前哈希表的大小为" << m.size() << endl;
    cout << "m[1] = " << m[1] << endl;
    cout << "m[2] = " << m[2] << endl;
    cout << "m[3] = " << m[3] << endl;

    unordered_map<char, int> m2;
    string str = "Hello World";
    for (char c : str){
        m2[c]++;
    }
    char c = 'l';
    cout << "m2['" << c << "'] = " << m2[c] << endl;

    // 遍历
    for (const auto& pair : m2) {
        // pair.first 是键，pair.second 是值
        cout << pair.first << ": " << pair.second << endl;
    }

    // 键值 对应多个值
    unordered_map<int, vector<int>> m3;

    //m3[1] 即为vector<int> 对象
    m3[1].push_back(10);
    m3[1].push_back(20);
    m3[1].push_back(30);
    cout << "m3[1][0] = " << m3[1][0] << endl;
    cout << "m3[1][1] = " << m3[1][1] << endl;
    cout << "m3[1][2] = " << m3[1][2] << endl;

}