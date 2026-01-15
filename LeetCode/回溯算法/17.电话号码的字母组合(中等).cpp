#include <D:\github\Algorithm_Learning\LeetCode\headfile\stdc++.h>
using namespace std;

class Solution {
    private:
        vector<string> phone = {
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
        };
    public:
        vector<string> letterCombinations(string digits) {
            vector<string> res;
            string path;
            function<void(int)> dfs = [&](int start){
                // 成功判断
                if(start == digits.size()){
                    res.push_back(path);
                    return;
                }
                int n = 0;
                if(digits[start] == '7' || digits[start] == '9')
                    n = 4;
                else
                    n = 3;
                for(int i = 0; i < n; i++){
                    path.push_back(phone[digits[start] - '2'][i]);
                    // 递归处理
                    dfs(start + 1);
                    // 成功回溯
                    path.pop_back();
                }
            };
            if(!digits.empty()) dfs(0);
            return res;
        }
    };

int main(){
    Solution s;
    vector<string> res = s.letterCombinations("23");
    for(auto &str : res)
        cout << str << " ";
    return 0;

}