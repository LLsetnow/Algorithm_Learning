#include <bits/stdc++.h>
using namespace std;

vector<char> path;
int used[30];
void backTrack(string s){
    // 成功回溯：路径长度等于字符串长度
    if(path.size() == s.size()){
        for(char c : path) cout << c;
        cout << endl;
        return;
    }
    // 遍历所有字符
    for(int i = 0; i < s.size(); i++){
        // 该字母没用过
        if(!used[s[i] - 'a']){
            // 选择
            path.push_back(s[i]);
            used[s[i] - 'a'] = 1;

            // 递归
            backTrack(s);

            // 撤销选择
            path.pop_back();
            used[s[i] - 'a'] = 0;            
        }
    }

}

int main(){
    string s;
    cin >> s;
    memset(used, 0, sizeof(used));
    backTrack(s);
}