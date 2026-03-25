/*


有一个很长的由小写字母组成字符串。为了便于对这个字符串进行分析，需要将它划分成若干个部分，每个部分称为一个单词。

出于减少分析量的目的，我们希望划分出的单词数越少越好。你就是来完成这一划分工作的。
输入格式

第一行为一整数 T，表示有 T 组测试数据。

每组测试数据第一行为一字符串。(长度小于 256)

第二行为一整数 N。（1<=N<=100）

以下 N 行，每行一个单词，每个单词长度小于 128。
输出格式

每组测试数据占一行 , 这一行只有一个整数，表示字符串可以被划分成的最少的单词数。我们保证单词是可划分的。
样例
Input

1
realityour
5
real
reality
it
your
our

Output

2


*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300;
const int INF = 1e9;

int T, n;
string s;
string words[105];
int dp[MAXN];   // dp[i] 表示字符串前 i 个字符最少可以划分成多少个单词。
unordered_set<string> dict;

int main() {
    cin >> T;
    while (T--) {
        cin >> s;
        cin >> n;
        dict.clear();
        for (int i = 0; i < n; i++) {
            cin >> words[i];
            dict.insert(words[i]);
        }
        
        int len = s.length();
        dp[0] = 0;
        for (int i = 1; i <= len; i++) {
            dp[i] = INF;
            for (int j = 0; j < i; j++) {
                string sub = s.substr(j, i - j);
                if (dict.count(sub)) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        cout << dp[len] << endl;
    }
    return 0;
}
