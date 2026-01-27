#include <D:\github\Algorithm_Learning\LeetCode\headfile\stdc++.h>
using namespace std;

void printVector(vector<int> &v){
    for (int i = 0; i < (int)v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main(){
    system("clear");
    system("chcp 65001>nul");

    //排序算法
    vector<int> v = {1, 3, 5, 7, 9, 2, 4, 6, 8, 0};
    sort(v.begin(), v.end());
    printVector(v);
    /*
    // 形式1：默认升序排序
    void sort(RandomAccessIterator first, RandomAccessIterator last);

    // 形式2：自定义比较函数
    void sort(RandomAccessIterator first, RandomAccessIterator last, Compare comp);
    
    first: 起始迭代器（包含）
    last: 结束迭代器（不包含）
    comp: 比较函数/lambda，返回 true 表示第一个参数应该排在前面

    */

    string str = "bdefozeaca";
    // 字母升序排序
    sort(str.begin(), str.end());
    cout << str << endl;

    // 搜索算法
    string str2 = "Hello World";
    // 在容器中查找与给定值匹配的第一个元素。 
    // 如果找到，it 将指向匹配的元素；
    // 如果没有找到，it 将等于 container.end()。
    auto it = find(str2.begin(), str2.end(), 'l');
    if (it != str2.end()) {
        cout << "找到字符 'l' 的位置: " << it - str2.begin() << endl;
    } else {
        cout << "未找到字符 'l'" << endl;
    }

    // 二分查找 要求容器必须是升序排列
    sort(str2.begin(), str2.end());
    auto it2 = binary_search(str2.begin(), str2.end(), 'l');
    if (it2) {
        cout << "找到字符 'l'的位置" << it - str2.begin() << endl;
    } else {
        cout << "未找到字符 'l'" << endl;
    }

    // 复制算法
    vector<int> v2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> v3(10);
    copy(v2.begin(), v2.end(), v3.begin());
    printVector(v3);

    // 反转算法
    // 将容器中的元素反转
    reverse(v3.begin(), v3.end());
    printVector(v3);

    // 替换算法
    // 将容器中所有等于 old_value 的元素替换为 new_value
    replace(v3.begin(), v3.end(), 5, 100);
    printVector(v3);

    // 赋值算法
    fill(v3.begin(), v3.end(), 0);
    printVector(v3);

    // 比较算法
    vector<int> v4 = {1, 2, 3, 4, 5};
    vector<int> v5 = {1, 2, 3, 4, 5};
    // 检查两个容器是否相等
    bool isEqual = equal(v4.begin(), v4.end(), v5.begin());
    cout << "两个向量是否相等: " << (isEqual ? "是" : "否") << endl;

    // 交换算法
    swap(v4, v5);
    printVector(v4);
    printVector(v5);

    // 归并
    vector<int> v6 = {1, 3, 5, 7, 9};
    vector<int> v7 = {2, 4, 6, 8, 10};
    vector<int> v8(10);
    merge(v6.begin(), v6.end(), v7.begin(), v7.end(), v8.begin());
    printVector(v8);

    // 随机数
    srand(time(0));
    for (int i = 0; i < 10; i++) {
        cout << rand() % 100 << " ";
    }
    cout << endl;

}