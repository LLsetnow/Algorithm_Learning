#include <D:\github\Algorithm_Learning\LeetCode\headfile\stdc++.h>
using namespace std;

int main() {
    system("cls");

    // 创建1
    tuple<int, int, int> t1(1, 2, 3);

    // 创建2
    tuple<int, int, int> t2 = make_tuple(1, 2, 3);

    // 创建3
    tuple<int, int, int> t3 = {1, 2, 3};

    // 读取1：get<index>(tuple)
    cout << get<0>(t1) << endl;
    cout << get<1>(t1) << endl;
    cout << get<2>(t1) << endl;

    // 读取2：结构化绑定（c++17)
    auto [a, b, c] = t1;
    cout << a << " " << b << " " << c << endl;

    // 读取3: tie 解包到变量
    int d; double e; string f;
    tie(d, e, f) = t1;

    // 遍历
    // 使用结构化绑定遍历
    vector<tuple<int, int, int, int>> patterns = {
        {0, 2, 0, 6},
        {1, 0, 1, 6}
    };

    for(auto &[c2, c3, c4, sum] : patterns){
        cout << c2 << " " << c3 << " " << c4 << " " << sum << endl;
    }

    // 或者使用引用
    for(auto &t : patterns){
        auto &[c2, c3, c4, sum] = t;
        // 使用变量...
    }

    cout << "-------------eeesss------------" << endl;

    return 0;
}