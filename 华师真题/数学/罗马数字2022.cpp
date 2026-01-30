/*
将十进制数字 转化为罗马数字

I   V   X   L   C   D   M
1   5   10  50  100 500 1000

1.左减 I X C， -1 -10 -100
2.左减只能 1位
3.左减不能跨位
4.V L D 只能使用一个
5.右加连续相同数字不超过3位


核心思路：贪心算法
从大到小依次匹配罗马数字符号，用最大的能表示的符号减去。
符号	值
M	    1000
CM	    900
D	    500
CD	    400
C	    100
XC	    90
L	    50
XL	    40
X	    10
IX	    9
V	    5
IV	    4
I	    1

转换步骤（以1994为例）：

1994 ÷ 1000 = 1 → M    余 994
994 ÷ 900 = 1  → CM   余 94
94 ÷ 90 = 1   → XC    余 4
4 ÷ 4 = 1     → IV    余 0
结果：MCMXCIV
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int a;
    cin >> a;

    vector<pair<int, string>> values = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };

    string result;
    for (auto &value : values) {

        int val = value.first;
        string symbol = value.second;
        while (a >= val) {
            result += symbol;
            a -= val;
        }
    }
    
    cout << result;
}