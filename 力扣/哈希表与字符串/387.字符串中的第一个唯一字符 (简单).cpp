/*
给定一个字符串 s ，找到 它的第一个不重复的字符，并返回它的索引 。如果不存在，则返回 -1 。

示例 1：

输入: s = "leetcode"
输出: 0

示例 2:

输入: s = "loveleetcode"
输出: 2

示例 3:

输入: s = "aabb"
输出: -1

提示:

    1 <= s.length <= 105
    s 只包含小写字母

*/
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
    public:
        int firstUniqChar(string s) {
            unordered_map<char, int> map;
            for(auto c:s){
                map[c]++;
            }
            for(int i = 0; i< s.size(); i++)
                if(map[s[i]] == 1) return i;
            return -1;
        }
        // 桶排序
        int firstUniqChar(string s) {
            int arr[26];
            for(size_t i = 0;i<26;i++)
            {
                arr[i] = 0;
            }
            //统计字符出现的次数
            for(auto c : s)
            {
                arr[c-'a']++;
            }
    
            for(auto e : s)
            {
                if(arr[e-'a'] == 1)
                {
                    return s.find(e);
                }
            }
            return -1;
        }
    };