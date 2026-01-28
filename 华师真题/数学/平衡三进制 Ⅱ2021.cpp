#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    // 步骤1: 计算B=3^k中的k
    int k = 0;
    long long power = 1;
    while (power != b) {
        power *= 3;
        k++;
    }

    // 步骤2: 将a转换为普通3进制
    vector<int> ternary;
    int temp = a;
    if (temp == 0) ternary.push_back(0);
    while (temp != 0) {
        ternary.push_back(abs(temp) % 3);
        temp /= 3;
    }

    // 步骤3: 转换为平衡三进制 (-1, 0, 1)
    vector<int> balanced;
    int carry = 0;
    for (int i = 0; i < ternary.size() || carry; i++) {
        int val = carry + (i < ternary.size() ? ternary[i] : 0);
        if (val % 3 == 2) {
            balanced.push_back(-1);
            carry = val / 3 + 1;
        } else if (val % 3 == 1) {
            balanced.push_back(1);
            carry = val / 3;
        } else {
            balanced.push_back(0);
            carry = val / 3;
        }
    }

    // 去除前导0
    while (balanced.size() > 1 && balanced.back() == 0) balanced.pop_back();

    // 输出结果：添加小数点
    for (int i = balanced.size() - 1; i >= 0; i--) {
        if (i == k - 1 && k > 0) cout << '.';
        cout << (balanced[i] == -1 ? '2' : char('0' + balanced[i]));
    }
    cout << endl;

    return 0;
}
