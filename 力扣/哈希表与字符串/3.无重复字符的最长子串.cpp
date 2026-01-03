/*
给定一个字符串 s ，请你找出其中不含有重复字符的 最长 子串 的长度。

示例 1:

输入: s = "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。注意 "bca" 和 "cab" 也是正确答案。

示例 2:

输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

示例 3:

输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

 

提示：

    0 <= s.length <= 5 * 104
    s 由英文字母、数字、符号和空格组成


*/


/*
    思路：

    1. 使用滑动窗口，窗口的左指针和右指针分别指向字符串的开头和结尾，窗口中不包含重复字符
    2. 窗口右指针每次右移一个字符。此时窗口内可能包含重复字符，需要检查窗口中是否包含右指针指向的字符
    3. 窗口左指针右移，直到窗口中不包含右指针指向的字符
    4. 更新最大长度
    5. 重复步骤2-4

    时间复杂度：O(n)
    空间复杂度：O(n)

*/
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;


class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            if(s.length() == 0) return 0;
            // 创建空的集合
            unordered_set<char> set;
            int left = 0, right = 0, maxLen = 0;
            while(right < s.length()){
                //窗口左指针右移，直到窗口中不包含右指针指向的字符
                // set.find(s[right]) != set.end() 表示窗口中包含右指针指向的字符
                while(set.find(s[right]) != set.end()){
                    set.erase(s[left]);
                    left++;
                }
                // 窗口右指针右移
                set.insert(s[right]);
                right++;
                // 更新最大长度
                maxLen = max(maxLen, right - left);
            }
            return maxLen;
        }
    };

int main() {
    system("chcp 65001>nul");
    Solution solution;
    string s = "abcabcbb";
    int len = solution.lengthOfLongestSubstring(s);
    cout << "最长子串长度为：" << len << endl;
    return 0;
}