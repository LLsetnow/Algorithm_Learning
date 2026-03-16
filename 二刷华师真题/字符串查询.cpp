#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 50005;

int sum[MAXN][26];    // 26个字母出现频次 前缀和 [1-based]
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s; 
    cin >> s;
    int Q; 
    cin >> Q;
    memset(sum, 0, sizeof(sum));
    int n = s.size();
    for(int i = 0; i < s.size(); i++){
        for(int j = 0; j < 26; j++){
            sum[i + 1][j] = sum[i][j];
        }
        sum[i + 1][s[i] - 'a']++;
    }

    // Q次查询
    while(Q--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if(b - a != d - c){
            printf("NE\n");
            continue;
        }
        int flag = 1;
        // 检查26个字母的前缀和
        for(int i = 0; i < 26; i++){
            int cntAB = sum[b][i] - sum[a-1][i];
            int cntCD = sum[d][i] - sum[c-1][i];
            if(cntAB != cntCD){
                flag = 0;
                break;
            }
        }
        if(flag){
            printf("DA\n");
        }
        else{
            printf("NE\n");
        }
    }


}