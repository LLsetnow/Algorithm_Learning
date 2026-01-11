/*
给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。

示例 1:

输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]

输出: [["bat"],["nat","tan"],["ate","eat","tea"]]

解释：

    在 strs 中没有字符串可以通过重新排列来形成 "bat"。
    字符串 "nat" 和 "tan" 是字母异位词，因为它们可以重新排列以形成彼此。
    字符串 "ate" ，"eat" 和 "tea" 是字母异位词，因为它们可以重新排列以形成彼此。

示例 2:

输入: strs = [""]

输出: [[""]]

示例 3:

输入: strs = ["a"]

输出: [["a"]]


提示：

    1 <= strs.length <= 104
    0 <= strs[i].length <= 100
    strs[i] 仅包含小写字母


思路：
    将原字符串进行排序
    strs =  ["eat", "tea", "tan", "ate", "nat", "bat"] 
    排序后为["aet", "aet", "ant", "aet", "ant", "abt"]
    将排序后的字符串作为键，原字符串作为值存储在哈希表中
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            unordered_map<string, vector<string>> map;
            for(auto &str : strs){
                string tmp = str;
                sort(tmp.begin(), tmp.end());
                map[tmp].push_back(str);
            }
            vector<vector<string>> res;
            for(auto &it : map){
                // it.second（值） 是 vector<string> 类型
                res.push_back(it.second);
            }
            return res;
        }
    };

int main(){
    Solution solution;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = solution.groupAnagrams(strs);
    
    for(const auto& group : result){
        cout << "[";
        for(const auto& word : group){
            cout << "\"" << word << "\" ";
        }
        cout << "]" << endl;
    }
    
    return 0;
}