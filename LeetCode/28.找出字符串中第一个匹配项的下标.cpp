/*
给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。如果 needle 不是 haystack 的一部分，则返回  -1 。

示例 1：

输入：haystack = "sadbutsad", needle = "sad"
输出：0
解释："sad" 在下标 0 和 6 处匹配。
第一个匹配项的下标是 0 ，所以返回 0 。

示例 2：

输入：haystack = "leetcode", needle = "leeto"
输出：-1
解释："leeto" 没有在 "leetcode" 中出现，所以返回 -1 。

提示：

    1 <= haystack.length, needle.length <= 104
    haystack 和 needle 仅由小写英文字符组成

*/


#include<iostream>
#include<string>
using namespace std;

// 使用string::find()函数
// class Solution {
//     public:
//         int strStr(string haystack, string needle) {
//             size_t pos = haystack.find(needle);
//             if(pos == string::npos){
//                 return -1;
//             }else{
//                 return pos;
//             }
//         }
//     };

// kmp算法
class Solution {
    public:
        int strStr(string haystack, string needle) {
            if(needle.empty()){
                return 0;
            }
            if(haystack.empty()){
                return -1;
            }
            // j 表示当前匹配的字符数
            int i = 0, j = 0;
            while(i < haystack.size() && j < needle.size()){
                if(haystack[i] == needle[j]){
                    i++;
                    j++;
                }else{
                    // 回退到上一次匹配的字符后一位
                    i = i - j + 1;
                    j = 0;
                }
            }
            if(j == needle.size()){
                return i - j;
            }else{
                return -1;
            }
        }
    };


int main() {
    Solution solution;
    string haystack = "sadbutsad";
    string needle = "sad";
    int result = solution.strStr(haystack, needle);
    cout << "Result: " << result << endl;
    return 0;
}