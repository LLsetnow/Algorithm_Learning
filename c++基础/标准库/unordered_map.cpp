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


    // 查找
    unordered_map<int, string> m4 = {{1, "apple"}, {2, "banana"}};
    int key = 1;

        // 方法1: count() - 推荐（最简洁）
        if (m4.count(key)) {
            cout << "键 " << key << " 存在" << endl;
        }
        
        // 方法2: find() - 推荐（还可以获取迭代器）
        auto it = m4.find(key);
        if (it != m4.end()) {
            cout << "键 " << key << " 存在，值为: " << it->second << endl;
        }
        
        // 方法3: at() - 存在时返回值，不存在抛异常
        try {
            cout << "值为: " << m4.at(key) << endl;
        } catch (const out_of_range& e) {
            cout << "键不存在" << endl;
        }

}