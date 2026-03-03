/*

给n个字符串，这些字符串表示数字，对数字按从小到大排序输出（小数点前最多5位，小数点后最多9位）
输入输出格式
输入描述:
第一行：一个正整数n，后面n行，每行一个字符串
输出描述:
按序输出n个字符串

输入输出样例
输入样例#:
4
28.334
-14.3456
5.9
1256

输出样例#:
-14.3456
5.9
28.334
1256


*/

#include <bits/stdc++.h>
using namespace std;

typedef struct Number
{
    string s;      // 原始字符串
    int sign;      // 符号位 0为正 1为负
    int front;     // 小数点前
    long long second; // 小数点后
};

void splitNumber(Number &num){
    string s = num.s;

    // 处理符号
    if(s[0] == '-'){
        num.sign = 1;
        s = s.substr(1);
    }else{
        num.sign = 0;
    }

    // 找小数点位置
    size_t dot_pos = s.find('.');

    if(dot_pos != string::npos){
        num.front = stoi(s.substr(0, dot_pos));
        string decimal = s.substr(dot_pos + 1);
        // 补齐到10位
        while(decimal.size() < 10) decimal += "0";
        // 截取前10位
        decimal = decimal.substr(0, 10);
        num.second = stoll(decimal);
    }else{
        num.front = stoi(s);
        num.second = 0;
    }
}

int main(){

    int n;
    cin >> n;
    vector<Number> numbers(n);
    for(auto &number : numbers){
        cin >> number.s;
        splitNumber(number);
    }
    // 先按照 符号位 降序, 再按照 整数位升序，最后按照 小数位 升序 
    // 小升 大降
    sort(numbers.begin(), numbers.end(), [](Number &a, Number &b){
        // 两个负数
        if(a.sign && b.sign){
            if(a.front == b.front)
                return a.second > b.second;
            return a.front > b.front;
        }
        if(a.sign == b.sign && a.front == b.front)
            return a.second < b.second;
        if(a.sign == b.sign)
            return a.front < b.front;
        return a.sign > b.sign; 
    });

    for(auto &number : numbers){
        cout << number.s << endl;
    }
}