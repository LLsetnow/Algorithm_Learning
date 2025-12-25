/*
给定两个字符串 s 和 t，长度分别是 m 和 n，返回 s 中的 最短窗口 子串，使得该子串包含 t 中的每一个字符（包括重复字符）。如果没有这样的子串，返回空字符串 ""。

测试用例保证答案唯一。

 

示例 1：

输入：s = "ADOBECODEBANC", t = "ABC"
输出："BANC"
解释：最小覆盖子串 "BANC" 包含来自字符串 t 的 'A'、'B' 和 'C'。

示例 2：

输入：s = "a", t = "a"
输出："a"
解释：整个字符串 s 是最小覆盖子串。

示例 3:

输入: s = "a", t = "aa"
输出: ""
解释: t 中两个字符 'a' 均应包含在 s 的子串中，
因此没有符合条件的子字符串，返回空字符串。

 

提示：

    m == s.length
    n == t.length
    1 <= m, n <= 105
    s 和 t 由英文字母组成

 
进阶：你能设计一个在 O(m + n) 时间内解决此问题的算法吗？

*/


/*
    思路：
    这是一个典型的 滑动窗口问题。我们要用一个窗口 [l, r] 扫描 s，在窗口内维护 t 的字符需求情况。
    1. 需求统计

        先统计 t 中每个字符的数量，存入数组/哈希表 cnt。
        用变量 k 表示当前还需要多少字符。

    2. 扩展右边界r

        每次把 s[r] 加入窗口：
        如果 cnt[s[r]] > 0，说明它是需要的字符，k--。
        不管需不需要，都执行 cnt[s[r]]--，表示“窗口里多了一个 s[r]”。

    3. 收缩左边界l

        当 k == 0 时，说明窗口[l, r]已经包含所有所需字符。
        在收缩过程中不断更新 bestlen 和 bestStart 。
        这时尝试收缩左边界 l，一旦移掉一个关键字符（++cnt[s[l]] > 0），就不再满足覆盖，k++，收缩结束。

    r++ 用于探索满足调节的窗口
    l++ 用于尝试收缩窗口，获取最小覆盖。 
    获取当前窗口的最小覆盖后，l在+1 用于寻找下一个符合条件的窗口

    时间复杂度：O(n)
    空间复杂度：O(1)

*/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#define INT_MAX 0x7fffffff
using namespace std;

class Solution {
    public:
        string minWindow(string s, string t) {
            if(s == t) return s;
            // k 记录 t 中每个字符需要多少个
            int n = s.size(), k = t.size();
            
            // cnt 记录 t 中每个字符需要多少个
            //包含128个整数的向量，并将所有元素初始化为0。
            // 实际上只用到“A" - "z" 65-122
            vector<int> cnt(128, 0); 
            for(char x : t)
                cnt[x] ++;
    
            int l = 0, r = 0;
            int bestlen = INT_MAX, bestStart = -1;
            string res = "";
            while(r < n)
            {
                if(-- cnt[s[r]] >= 0) // 用掉一个需要的字符
                    k --;
    
                while(k == 0) // [l, r] 窗口已经覆盖了所有字符，可以尝试收缩
                {
                    if(bestlen > r - l + 1) // 更新答案
                    {
                        bestlen = r - l + 1;
                        bestStart = l;
                    }
                    if(++ cnt[s[l]] > 0) // 一旦移掉一个关键字符，就不再满足覆盖，k++，收缩结束
                        k ++;
                    l ++;
                }
                r ++;
            }
            return bestStart == -1 ? "" : s.substr(bestStart, bestlen);
        }
    };


int main() {

    Solution s;
    string s1 = "ADOBECODEBANC";
    string t1 = "ABC";
    cout << s.minWindow(s1, t1) << endl;
    return 0;

}