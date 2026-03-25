/*
现有若干半导体元件，元件之间的联通关系具有传递性：若元件a与b联通，b与c联通，则a与c也联通。给定n条关于元件联通状态的记录，每条记录格式为（i, j, is_connected），其中：
- i和j为半导体元件的唯一编号（正整数）；
- is_connected为布尔值，1表示“i和j必须相互联通”，0表示“i和j必须相互不联通”。

请编写程序判断给定的n条记录是否能够同时成立（即不存在相互矛盾的联通规则）。
输入输出格式
输入描述:
1. 第一行输入一个整数T（1 ≤ T ≤ 10），表示测试用例的数量。
2. 每个测试用例的第一行输入一个整数n（1 ≤ n ≤ 10^4），表示记录的条数。
3. 接下来n行，每行包含两个正整数i、j和一个整数is_connected（0或1），表示一条联通状态记录。
输出描述:
对于每个测试用例，若所有记录可同时成立，输出一行“YES”；否则输出一行“NO”。
输入输出样例
输入样例#:

2
3
1 3 1
3 5 1
1 5 0
4
2 4 1
4 6 1
7 8 0
2 6 1

输出样例#:
复制

NO
YES


*/


#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4 + 10;
struct Edge {
    int u, v, w;
};

int T, n, p[MAXN];
vector<Edge> records; // 暂存记录

int Find(int x) {
    if (p[x] == x) return x;
    return p[x] = Find(p[x]);
}

int main() {
    cin >> T;
    while (T--) {
        cin >> n;
        records.clear();
        for (int i = 1; i <= MAXN; i++) p[i] = i;
        
        // 暂存所有记录
        for (int i = 0; i < n; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            if (w == 1) {
                int pu = Find(u), pv = Find(v);
                if (pu != pv) p[pu] = pv;
            }
            else{
                records.push_back({u, v, w});
            }
        }
      
        // 第二步：检查不连通关系是否矛盾
        bool flag = true;
        for (int i = 0; i < n; i++) {
            int u = records[i].u, v = records[i].v, w = records[i].w;

            if (Find(u) == Find(v)) {
                flag = false;
                break;
            }

        }
        
        cout << (flag ? "YES" : "NO") << endl;
    }
}
