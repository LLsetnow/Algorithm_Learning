/*
给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。

回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

    例如，121 是回文，而 123 不是。

 

示例 1：

输入：x = 121
输出：true

示例 2：

输入：x = -121
输出：false
解释：从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。

示例 3：

输入：x = 10
输出：false
解释：从右向左读, 为 01 。因此它不是一个回文数。

 

提示：

    -231 <= x <= 231 - 1

*/
#include <iostream>
#include <string>
using namespace std;

// 将整数转换为字符串，然后比较字符串的首尾字符是否相同
// 时间复杂度：O(log10(n)) 
// 空间复杂度：O(log10(n))
// class Solution {
//     public:
//         bool isPalindrome(int x) {
//             string s = to_string(x);
//             for(int i = 0; i < s.length() / 2; i++){
//                 if(s[i] != s[s.length() - 1 - i]){
//                     return false;
//                 }
//             }
//             return true;
//         }
//     };

// 反转一半的数字，然后比较
// class Solution {
//     public:
//         bool isPalindrome(int x) {
//             if(x < 0 || (x % 10 == 0 && x != 0)) return false;
//             int revertedNumber = 0;
//             // 只反转一半的数字 中止条件 x <= revertedNumber 
//             while(x > revertedNumber){
//                 revertedNumber = revertedNumber * 10 + x % 10;
//                 x /= 10;
//             }

//             // 偶数位数 反转一半的数字 和 原数字相同
//             // 奇数位数 反转一半的数字 去掉最低位（即为原数字中间位） 和 原数字相同
//             return x == revertedNumber || x == revertedNumber / 10;
//         }
//     };

// 全部反转
class Solution {
    public:
        bool isPalindrome(int x) {
            if(x<0) return false;
            //奇数位数时，反转数会超过int范围
            long long a=0;
            int b=x;
            while(x)
            {
                a*=10;
                a+=x%10;
                x/=10;
            }
            if(a==b)    return true;
            else return false;
        }
    };

int main(){
    system("clear");
    system("chcp 65001>nul");
    Solution s;
    cout << s.isPalindrome(121) << endl;
    cout << s.isPalindrome(-121) << endl;
    cout << s.isPalindrome(10) << endl;


}