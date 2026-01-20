/*
整数 n (1≤n≤10000)，从右往左读得到它的反数 m，判断 n 与 m 的和 s 是否是一个回文数。
回文数是从左往右读和从右往左读结果一样的整数。
若 s 不是一个回文数，则继续判断 s 和它的反数的和是否是一个回文数。
重复这一过程，直至达到和为一个回文数为止。

例如，n 为 195，则 m 为 591，s 为 786；再计算 786+687=1473; 1473+3741=5214; 
5214+4125=9339。在达到回文数 9339 之前总共进行了 4 次加法操作。

对于 n，要求计算出达到回文数之前所进行的加法操作的最小次数和最终达到的回文数。

n 本身不是一个回文数。保证对于 n 来说一定能在 1000 次加法操作之前达到回文数，
并且在计算过程中的和一定小于 2000000000。


输入描述:
由一个整数 n 组成的一行信息。
输出描述:
一行信息，用一个空格分隔的最小加法次数及最终达到的回文数。
输入输出样例
输入样例#:

195

输出样例#:
复制

4 9339



*/
#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;


bool isPalindrome(int x) {
    if(x < 0) return false;
    if(x < 10) return true;
    if(x % 10 == 0) return false;  // 以0结尾的非0数不是回文
    
    int reversed = 0;
    while(x > reversed){
        reversed = reversed * 10 + x % 10;
        x /= 10;
    }
    // x == reversed (偶数位) 或 x == reversed/10 (奇数位)
    return x == reversed || x == reversed / 10;
}

int reverse(int x){
    int reversed = 0;
    while(x){
        reversed = reversed * 10 + x % 10;
        x /= 10;
    }
    return reversed;
}

// 暴力解
int main(){
    int x;
    cin >> x;

    int count = 1;
    while(!isPalindrome(x + reverse(x))){
        count++;
        x = x + reverse(x);
    }
    cout << count << ' ' << x + reverse(x);
    return 0;
}


