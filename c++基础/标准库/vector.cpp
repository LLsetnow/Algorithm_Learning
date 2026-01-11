#include <D:\github\Algorithm_Learning\LeetCode\headfile\stdc++.h>
using namespace std;

int main() {
    system("clear");
    system("chcp 65001>nul");

    // 初始化向量
    vector<int> v = {1, 2, 3, 4, 5};
    vector<int> v1(10);         // 10个0
    vector<int> v2(10, 5);      // 10个5
    cout << "v = ";
    cout << "v1 = ";
    for (int x : v1) {
        cout << x << " ";
    }
    cout << endl;
    cout << "v2 = ";
    for (int x : v2) {
        cout << x << " ";
    }
    cout << endl;

    // 遍历向量
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;



    // 向量大小
    int size = v.size();
    cout << "size = " << size << endl;

    // 添加元素
    v.push_back(6);
    cout << "v = ";
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;

    // 删除元素
    // 删除最后一个元素
    v.pop_back();
    cout << "v = ";
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;

    // 访问元素
    cout << "v[0] = " << v[0] << endl;
    cout << "v[0] = " << v.at(0) << endl;
    cout << "v.back() = " << v.back() << endl;
    cout << "v.front() = " << v.front() << endl;

    //清空向量
    v.clear();
    cout << "v = ";
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;

    vector<int> v3 = {1, 2, 3, 4, 5};

    // 迭代访问
    cout << "v3 = ";
    for (auto it = v3.begin(); it != v3.end(); it++) {
        // it 是一个指针，指向当前元素的地址
        cout << *it << " ";
    }
    // 使用范围for循环
    cout << "v3 = ";
    for(auto& x : v3){
        cout << x << " ";
    }
    cout << endl;
}