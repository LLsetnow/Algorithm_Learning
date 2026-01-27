/*
就是输入一个数，比如201，让数字随意组合，是否能组合出30的倍数，如果能够组合成30的倍数，就输出最大的倍数，不能就输出-1；

例如输入201你可以随意组合成

201，210，012，021，102，120等数字

其中120，210都是30的倍数，由于要找最大的，所以答案是210
输入输出格式
输入描述:
如题
输出描述:
如题
输入输出样例
输入样例#:

201

输出样例#:
复制

210


*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int x;
    cin >> x;
    vector<int> numbers;
    int numberSum = 0;
    int ifZero = 0;
    while(x > 0){
        int a = x % 10;
        x /= 10;
        numbers.push_back(a);
        if(a == 0) ifZero = 1;
        numberSum += a;
    }
    if(ifZero == 0 || (numberSum % 3)){
        cout << -1;
        return 0;
    }
    // 降序排序
    sort(numbers.begin(), numbers.end(), 
    [](const int &a, const int &b){
        return a > b;
    });
    int res = 0;
    for(auto &number : numbers){
        res = res * 10 + number;
    }
    cout << res;
}