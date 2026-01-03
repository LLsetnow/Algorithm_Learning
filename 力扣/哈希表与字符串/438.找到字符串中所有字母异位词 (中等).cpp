/*
给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。

示例 1:

输入: s = "cbaebabacd", p = "abc"
输出: [0,6]
解释:
起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。

 示例 2:

输入: s = "abab", p = "ab"
输出: [0,1,2]
解释:
起始索引等于 0 的子串是 "ab", 它是 "ab" 的异位词。
起始索引等于 1 的子串是 "ba", 它是 "ab" 的异位词。
起始索引等于 2 的子串是 "ab", 它是 "ab" 的异位词。

 

提示:

    1 <= s.length, p.length <= 3 * 104
    s 和 p 仅包含小写字母

思路：
    1. 滑动窗口 初始窗口大小为p的长度（left = 0, right = p.size() - 1）
    2. 将p 排序后变为p_sorted 
    3. 将窗口内的字符排序后变为window_sorted
    4. 如果window_sorted == p_sorted 则将窗口起始索引加入结果res.push_back(left)
    5. 在4成立的基础上, 直接判断  
        若s[left] == s[right] 则反复执行 res.push_back(left)和步骤5，否则回到步骤3
    

*/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
    public:
        // 滑动窗口 排序字符串
        vector<int> findAnagrams(string s, string p) {
            int left = 0, right = p.size() - 1;
            string p_sorted = p;
            sort(p_sorted.begin(), p_sorted.end());
            vector<int> res;
            while(right < (int)s.size()){
                string window_sorted = s.substr(left, right - left + 1);
                sort(window_sorted.begin(), window_sorted.end());
                if(window_sorted == p_sorted)
                {
                    res.push_back(left);
                    while(right < (int)s.size() - 1 && s[left] == s[right + 1] ){
                        left++;
                        right++;
                        res.push_back(left);
                    }
                }
                left++;
                right++;
            }
            return res;
        }
        vector<int> findAnagrams2(string s, string p) {
            unordered_map<char, int> p_map;
            // 统计p中每个字符出现的次数
            for(auto c : p){
                p_map[c]++;
            }
            vector<int> res;
            int left = 0, right = 0;
            int count = p.size();
            // 滑动窗口 更新串口内的字符出现次数
            while(right < (int)s.size()){
                if(p_map[s[right]] > 0) count--;
                p_map[s[right]]--;
                right++;
                if(count == 0) res.push_back(left);
                if(right - left == (int)p.size()){
                    if(p_map[s[left]] >= 0) count++;
                    p_map[s[left]]++;
                    left++;
                }
            }
            return res;
        }
    };


int main(){
    system("clear");
    Solution solution;
    string s = "abab";
    string p = "ab";
    vector<int> res = solution.findAnagrams2(s, p);
    for(auto i : res){
        cout << i << " ";
    }


}