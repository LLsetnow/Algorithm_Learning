/*

给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的 字母异位词。


示例 1:

输入: s = "anagram", t = "nagaram"
输出: true

示例 2:

输入: s = "rat", t = "car"
输出: false


提示:

    1 <= s.length, t.length <= 5 * 104
    s 和 t 仅包含小写字母


进阶: 如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？

*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
    public:
        // 无脑排序法
        bool isAnagram(string s, string t) {
            sort(s.begin(), s.end());
            sort(t.begin(), t.end());
            return s == t;
        }

        // 哈希表法
        bool isAnagram2(string s, string t) {
            unordered_map<char, int> map;
            for(auto &c : s){
                map[c]++;
            }
            for(auto &c : t){
                map[c]--;
            }
            for(auto &it : map){
                if(it.second != 0){
                    return false;
                }
            }
            return true;
        }
};


int main(){
    Solution solution;
    string s = "anagram";
    string t = "nagaram";
    bool res = solution.isAnagram(s, t);
    cout << res << endl;


}