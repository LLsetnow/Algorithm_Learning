#include<bits/stdc++.h>
using namespace std;
string s;
int ans = 0;

void cal(string s) {
    
	int n = s.size();
	int sign = 1;
	stack<int> st;
	
	for(int i = 0; i < n; i++) {
		if(isdigit(s[i])) {
			int sum = 0;
			while(i < n && isdigit(s[i])) {
				  sum = sum * 10 + s[i] - '0';
				  i++;
			}
			i--;
			ans += sign * sum;
		} else if(s[i] == '-') {
		   sign = -1;	
		} 
        // 遇到左括号：开始新的子表达式
        else if(s[i] == '(') {
			st.push(ans);
			st.push(sign);
			ans = 0;
			sign = 1;
		}
        // 遇到空格：跳过 
        else if(s[i] == ' ') {
		   continue;	
		}else if(s[i] == '+') {
		    sign = 1;	
		}
        // 遇到右括号：结束子表达式
        else if(s[i] == ')'){
		  	int pre_sign = st.top(); st.pop();
			int pre_sum = st.top(); st.pop();
			ans = pre_sum + pre_sign * ans;
		}
	}
}

int main() {
	getline(cin, s);
	cal(s);
	cout << ans << endl;
	return 0;
}
