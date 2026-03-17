#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 105;
char G[MAXN][MAXN];
// 上、下、左、右、左上、右上、左下、右下
int dr[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dc[] = {0, 0, -1, 1, -1, 1, -1, 1};

int main(){

    int n;
    cin >> n;
    memset(G, 0, sizeof(G));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> G[i][j];
        }
    }
    string s; cin >> s;
    int length = s.size();
    int res = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(G[i][j] == s[0]){
                // 尝试8个方向
                bool found = false;
                for(int k = 0; k < 8; k++){
                    int sIdx = 1;
                    while(sIdx < length){
                        int nextR = i + dr[k] * sIdx;
                        int nextC = j + dc[k] * sIdx;
                        if(nextR > n || nextR < 1 || nextC > n || nextC < 1) break;
                        if(G[nextR][nextC] == s[sIdx]){
                            sIdx++;
                        }
                        else break;
                    }
                    if(sIdx == length){
                        found = true;
                        break;
                    }
                }
                if(found){
                    cout << i << " " << j << endl;
                    res++;  
                } 
            }
        }
    }
    if(res == 0) cout << "Not Found";
}