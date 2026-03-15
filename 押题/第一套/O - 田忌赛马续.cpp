/*
你一定听过田忌赛马的故事吧？
如果3匹马变成1000匹，齐王仍然让他的马按从优到劣的顺序出赛，田忌可以按任意顺序选择他的赛马出赛。
赢一局，田忌可以得到200两银子，输一局，田忌就要输掉200两银子，平局的话不输不赢。

请问田忌最多能赢多少银子?
输入输出格式
输入描述:
输入包含多组测试数据.
每组测试数据的第一行是一个整数n(1<=n<=1000),表示田忌和齐王都拥有n匹马。
接下来一行是n个整数，表示田忌的马的速度，
下一行也是n个整数，表示齐王的马的速度。
输入的最后以一个0表示结束。
输出描述:
对每组数据，输出一个整数，表示田忌至多可以赢多少银子，如果田忌赢不了，就输出一个负数，表示田忌最少要输多少银子。
输入输出样例
输入样例#:

3
92 83 71
95 87 74
2
20 20
20 20
2
20 19
22 18
0

输出样例#:

200
0
0

核心思路：枚举策略
枚举田忌用前 i 匹最慢的马对抗齐王后 i 匹最快的马，寻找最优解。
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e3 + 5;

int n;
int a[N], b[N];
int comp(int ida, int idb)
{
	if(a[ida] > b[idb]) return 1;
	if(a[ida] < b[idb]) return -1;
	return 0;
}
int main()
{
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
 
	while(cin>>n)
	{
		if(n==0) break;
		for(int i=1; i<=n; i++) cin >> a[i];
		for(int i=1; i<=n; i++) cin >> b[i];

		sort(a+1, a+n+1);
		sort(b+1, b+n+1);

		int ans = -n;
		for(int i=1; i<=n; i++)
		{
			int cnt = 0;
			for(int j=1; j<=i; j++)
			{
				cnt += comp(n+1-j, i+1-j);
			}
			for(int j=1; j<=n-i; j++)
			{
				cnt += comp(j, n+1-j);
			}
			ans = max(ans, cnt);
		}
		cout << ans * 200 << "\n";

	}

	return 0;
}
