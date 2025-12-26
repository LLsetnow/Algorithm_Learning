/*
编写一个函数来查找字符串数组中的最长公共前缀。
如果不存在公共前缀，返回空字符串 ""。


示例 1：

输入：strs = ["flower","flow","flight"]
输出："fl"

示例 2：

输入：strs = ["dog","racecar","car"]
输出：""
解释：输入不存在公共前缀。

 

提示：

    1 <= strs.length <= 200
    0 <= strs[i].length <= 200
    strs[i] 如果非空，则仅由小写英文字母组成

*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 暴力解法
// class Solution {
//     public:
//         string longestCommonPrefix(vector<string>& strs) {
//             string prefix = "";
//             // 正确获取 vector 中元素个数的方法
//             int strNumber = (int)strs.size();
//             // 实现最长公共前缀逻辑
//             if (strNumber == 0) return "";
//             if (strNumber == 1) return strs[0];

//             // 找到最短的字符串长度
//             int min_len = 0x7fffffff;
//             for (int i = 0; i < strNumber; i++) {
//                 if((int)strs[i].length() < min_len)
//                     min_len = strs[i].length();
//             }

//             for (int i = 0; i < min_len; i++){
//                 // cout << "i = " << i << endl;
//                 char c = strs[0][i];
//                 for(int j = 1; j < strNumber; j++){
//                     // cout << "str[" << j << "][" << i << "] = " << strs[j][i] << endl;
//                     if(strs[j][i] != c)
//                         return prefix;
//                 }
//                 prefix += c;
//                 // cout << "prefix = " << prefix << endl;
                
//             }
//             return prefix;
//         }
//     };

// 分治法
// 以第一个字符串为基准，找到与第二个字符串的公共前缀，记作 prefix
// 以prefix为基准，找到与第三个字符串的公共前缀，更新prefix
class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            string prefix = strs[0];
            for(int i = 1; i < (int)strs.size(); i++){
                int j = 0;
                while(j < (int)prefix.length() && j < (int)strs[i].length() && prefix[j] == strs[i][j]) j++;
                prefix = prefix.substr(0, j);
            }
            return prefix;
        }
    };


int main(){
    system("chcp 65001>nul");
    Solution solution;
    vector<string> strs = {"flower","flow","flight"};
    string res = solution.longestCommonPrefix(strs);
    cout << res << endl;
    vector<string> strs2 = {"dog","racecar","car"};
    string res2 = solution.longestCommonPrefix(strs2);
    cout << res2 << endl;
}