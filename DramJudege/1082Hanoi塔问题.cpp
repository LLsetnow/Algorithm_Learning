#include <bits/stdc++.h>
using namespace std;
int cnt = 0;  // 计数器

void Hanoi(int n, char start, char target, char another){
    if(n == 1){
        if(cnt > 0 && cnt % 5 == 0) cout << endl;
        cout << start << "-->" << target << "   ";
        cnt++;
        return;  
    }
    Hanoi(n - 1, start, another, target);
    Hanoi(1, start, target, another);
    Hanoi(n - 1, another, target, start);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while(cin >> n){
        if(n == 0) break;
        cnt = 0;
        Hanoi(n, 'A', 'C', 'B');
        cout << endl;
    }
    return 0;
}
