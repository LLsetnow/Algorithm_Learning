/*
 * @lc app=leetcode.cn id=5 lang=cpp
 * @lcpr version=30400
 *
 * [5] 最长回文子串
 */
#include <bits/stdc++.h>
using namespace std;
/*

思路：
    for 0 <= i < len(s):
    找到以 s[i] 为中心的回文串
    更新最长回文子串
*/
// @lc code=start
class Solution {
    public:
        string longestPalindrome(string s) {
            string res = "";
            for (int i = 0; i < s.length(); i++) {
                // 以 s[i] 为中心的最长回文子串
                string s1 = palindrome(s, i, i);
                // 以 s[i] 和 s[i+1] 为中心的最长回文子串
                string s2 = palindrome(s, i, i + 1);
                // res = longest(res, s1, s2)
                res = res.length() > s1.length() ? res : s1;
                res = res.length() > s2.length() ? res : s2;
            }
            return res;
        }
    
    private:
        string palindrome(string s, int l, int r) {
            // 防止索引越界
            while (l >= 0 && r < s.length() && s[l] == s[r]) {
                // 向两边展开
                l--;
                r++;
            }
            // 此时 s[l+1..r-1] 就是最长回文串
            return s.substr(l + 1, r - l - 1);
        }
    };
// @lc code=end



/*
// @lcpr case=start
// "babad"\n
// @lcpr case=end

// @lcpr case=start
// "cbbd"\n
// @lcpr case=end

 */

