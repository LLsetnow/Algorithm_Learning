#include <bits/stdc++.h>
using namespace std;

int main(){
    int turns, Wn, Sn;
    cin >> turns;
    while(turns--){
        // 输入
        cin >> Wn;
        vector<int> weights(Wn);
        for(auto &x : weights){
            cin >> x;
        }
        cin >> Sn;
        vector<int> searchs(Sn);
        for(auto &x : searchs){
            cin >> x;
        }

        // 存储所有组合结果
        vector<int> hasWeight(10004, 0);
        // 枚举所有组合：每个数字有3种状态（加、减、不用）
        // 用三进制枚举：0=不用，1=加，2=减
        int total = pow(3, Wn);  // 3^Wn种组合
        for (int mask = 0; mask < total; mask++) {
            int sum = 0;
            int temp = mask;
            for (int i = 0; i < Wn; i++) {
                int state = temp % 3;  // 取当前数字的状态
                temp /= 3;
                if (state == 1) {
                    sum += weights[i];
                } else if (state == 2) {
                    sum -= weights[i];
                }
                // state == 0 表示不使用该数字
            }
            if (sum >= 1 && sum <= 10003) {
                hasWeight[sum] = 1;
            }
        }

        // 查找
        for(int i = 0; i < Sn; i++){
            if(hasWeight[searchs[i]])
                cout << 1;
            else 
                cout << 0;
        }
        cout << endl;
    }
}