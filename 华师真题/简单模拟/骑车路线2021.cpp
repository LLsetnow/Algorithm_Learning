/*
Tomislav最近发现自己的身材完全走样了，她走楼梯都变得很累。
一天早上她起来以后，她决定恢复姣好的身材。
她最喜欢的运动是骑自行车，因此她决定在本地的小山上做一次旅行。

她骑自行车的路线可以描述为N个数字的数列，每个数字表示每一段路地海拔高度。
Tomislav最感兴趣的是最长的高度一直上升的子序列，
她称这一段路为爬坡，Tomislav只想考虑这段爬坡的高度差（即开始和最后的数字的差距），
而不是什么路程长度。

一段爬坡路被定义为至少两个连续的上升数列。
例如，我们考虑如下路线数列12 3 5 7 10 6 1 11，
这里有两个爬坡，第一个爬坡（3 5 7 10）的高度差是7，第二个爬坡的高度差是10（1 11）。

帮助Tomislav计算高度差最大的爬坡的高度差。

输入输出格式
输入描述:
多组
测试数据输入。
第一行是一个正整数N (1<= N <= 1000), 描述了路线数列。
第二行有N个正整数，每个正整数Pi (1<= Pi <= 1000)表示相应路段的海拔高度。
输出描述:
所有爬坡中的最大高度差，如果路线数列里面没有爬坡，就输出0。
输入输出样例
输入样例#:

5
1 2 1 4 6
6
10 8 8 6 4 3

输出样例#:
复制

5
0

*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        int maxHeight = 0;
        int left, right;
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            if(i == 0) left = right = x;
            else if(x >= right){
                right = x;
            }
            else{
                maxHeight = max(maxHeight, right - left);
                left = right = x;
            }
        }
        maxHeight = max(maxHeight, right - left);
        cout << maxHeight << endl;
    }
}
