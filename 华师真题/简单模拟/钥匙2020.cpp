/*
经济危机席卷全球，L国也收到冲击，大量人员失业。

然而，作为L国的风云人物，X找到了自己的新工作。从下周开始，X将成为一个酒店的助理锁匠，
当然，他得先向部门领导展示他的开锁能力。

领导给了X一串钥匙，这串钥匙串在一个大圆环上，每把钥匙有一个编号（1..N）。
然后蒙上X的眼睛并把他带到一个圆形的大房间中。在这个房间中有N个上锁的门，用1..N表示，
这串N把钥匙每一把正好打开一扇门（钥匙编号和门编号一致就可以打开）。

X的工作就是打开每扇门。他因为蒙着眼睛，不过可以沿着房间的墙壁移动，不能改变方向，
直到他摸着一扇门，然后他会尝试用第一把钥匙（最左边）来打开门，
如果钥匙不能打开门，他会将钥匙移到另外一侧（最右边），重复这样直到找到正确的钥匙，当他把所有门打开就结束任务。
不过X不知道的是，领导并不是测试 他开锁能力，而是测试他的耐心，所以领导故意把X带到圆形房间，
这样X每开一扇门后，领导就会在后面悄悄把门再次锁上，
这样以来，X打开最后一扇门后又回到第一扇门然后一直重复下去。
不过X是一个勤奋和耐心的人，他一直毫无怨言的做着这件事，不说任何抱怨的话，
只是在每开一扇门他会默默的统计自己已经错误了多少次，不过慢慢时间太久他的计算能力不足，需要你来帮助他计算错误的次数。

任务：给定数字k，回答当X打开第k扇门时，一共错误了多少次？
输入输出格式
输入描述:
第一行是2个整数N,K

接下来N行，每行包含一个整数Vi，表示钥匙串从第一把（左侧）到最后一把，第i把钥匙的编号。
输出描述:
一个整数，回答第k次打开一扇门，已经错误的次数。
输入输出样例
输入样例#:

4 6
4
2
1
3

输出样例#:
复制

13

提示
样例解释
打开第1扇门的尝试（1号门）：4 2 1 3，错误2次，打开后钥匙排列：1 3 4 2
打开第2扇门的尝试（2号门）：1 3 4 2，错误3次，打开后钥匙排列：2 1 3 4
打开第3扇门的尝试（3号门）：2 1 3 4，错误2次，打开后钥匙排列：3 4 2 1
打开第4扇门的尝试（4号门）：3 4 2 1，错误1次，打开后钥匙排列：4 2 1 3
打开第5扇门的尝试（1号门）：4 2 1 3，错误2次，打开后钥匙排列：1 3 4 2
打开第6扇门的尝试（2号门）：1 3 4 2，错误3次，打开后钥匙排列：2 1 3 4
总错误13次
数据规模
40%数据：1<=N,K<=1000
另外60%数据：1<=K<=50000
100%数据：1<=N<=100000,1<=Vi<=N，1<=K<=10^9

*/
#include <bits/stdc++.h>
using namespace std;

// 哈希表 记忆化搜索
void test1(){
    system("clear");
    system("chcp 65001>nul");
    // 足够大的测试案例，能达成循环
    int n = 5;
    int k = 12;  // 2个完整周期(10) + 余数(2)
    vector<int> key(n+1);
    key[1] = 3;
    key[2] = 1;
    key[3] = 5;
    key[4] = 2;
    key[5] = 4;

    int res = 0;
    int index = 1;
    unordered_map<long long, int> map;
    for(int i = 1; i <= k; i++){
        int door = (i - 1) % n + 1;
        cout << "第" << i << "次开门 " << "开" << door << "号门" << endl;
        long long mapKey = (long long)door << 32 | index;
        if(map.find(mapKey) != map.end()){
            int shift = map[mapKey];
            res += shift;
            index = (index + shift - 1) % n + 1;
            cout << "door = " << door << " index = " << index << endl;
            cout << "发现循环 shift = " << shift << endl;
        }
        else{
            int count = 0;
            while(key[index] != door){
                index = index % n + 1;
                res++;
                count++;
            }
            map[mapKey] = count;
            cout << "door = " << door << " index = " << index << " count = " << count << endl;
        }

    }
    cout << res;
    return;
}


// 暴力解 按照题意模拟
void test2(){
    system("clear");
    system("chcp 65001>nul");
    // 足够大的测试案例，能达成循环
    int n = 5;
    int k = 12;  // 2个完整周期(10) + 余数(2)
    vector<int> key(n+1);
    key[1] = 3;
    key[2] = 1;
    key[3] = 5;
    key[4] = 2;
    key[5] = 4;

    // int n, k;
    // cin >> n >> k;
    // vector<int> key(n+1);
    // for(int i = 1; i <= n; i++){
    //     cin >> key[i];
    // }

    int res = 0;
    int index = 1;
    for(int i = 1; i <= k; i++){
        int door = (i - 1) % n + 1;
        while(key[index] != door){
            index = index % n + 1;
            res++;
        }
        cout << "i = " << i << " res = " << res << endl;
    }
    cout << res;
    return;
}


int main(){
    test1();
}