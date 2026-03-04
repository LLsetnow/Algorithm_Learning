
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int vec[50001][26] = {0};

    for(int i = 0; i < s.size(); i++){
        for(int j = 0; j < 26; j++){
            vec[i + 1][j] = vec[i][j];
        }
        vec[i + 1][s[i] - 'a']++;
    }

    int n;
    cin >> n;
    while(n--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if(b - a != d - c){
            printf("NE\n");
            continue;
        }
        bool flag = true;
        for(int i = 0; i < 26; ++i){
            int cnt1 = vec[b][i] - vec[a - 1][i];
            int cnt2 = vec[d][i] - vec[c - 1][i];

            if(cnt1 != cnt2){
                flag = false;
                break;
            }
        }
        if(flag)
            printf("DA\n");
        else    
            printf("NE\n");

    }
    return 0;
}
