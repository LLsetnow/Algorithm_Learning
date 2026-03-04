/*
特性	        map	                    unordered_map
底层实现	红黑树（平衡二叉搜索树）	    哈希表
顺序	        有序（按键升序）	        无序
查找时间	    O(log n)	        平均 O(1)，最坏 O(n)
插入时间	    O(log n)	        平均 O(1)，最坏 O(n)
删除时间	    O(log n)	        平均 O(1)，最坏 O(n)
内存占用	    较高（树节点开销）	        较低


*/
#include <iostream>
#include <map>
using namespace std;


int main(){
    map<int, int> mp;
    // 插入
    mp[1] = 10;           // 直接赋值
    mp.insert({2, 20});   // insert
    mp.emplace(3, 30);    // emplace

    // 访问
    int val1 = mp[1];      // 不存在会自动创建默认值
    int val2 = mp.at(1);    // 不存在会抛出异常

    // 查找
    if (mp.count(2)){
        cout << "has key_value 2" << endl;
    }
    auto it = mp.find(2);           // 返回迭代器，找不到返回end()
    if (it != mp.end()) {
        cout << it->first << " " << it->second;
    }

    // 删除
    mp.erase(2);       // 按key删除
    mp.erase(it);        // 按迭代器删除

    // 大小
    int sz = mp.size();
    cout << "size: " << sz << endl;
    mp.clear();          // 清空




}