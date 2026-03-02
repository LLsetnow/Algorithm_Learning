/*
 * @lc app=leetcode.cn id=344 lang=cpp
 * @lcpr version=30400
 *
 * [344] 反转字符串
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        for(int i = 0; i < n / 2; i++){
            swap(s[i], s[n - i - 1]);
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["h","e","l","l","o"]\n
// @lcpr case=end

// @lcpr case=start
// ["H","a","n","n","a","h"]\n
// @lcpr case=end

 */

