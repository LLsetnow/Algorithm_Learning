
/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

    左括号必须用相同类型的右括号闭合。
    左括号必须以正确的顺序闭合。
    每个右括号都有一个对应的相同类型的左括号。

 

示例 1：

输入：s = "()"

输出：true

示例 2：

输入：s = "()[]{}"

输出：true

示例 3：

输入：s = "(]"

输出：false

示例 4：

输入：s = "([])"

输出：true

示例 5：

输入：s = "([)]"

输出：false

 

提示：

    1 <= s.length <= 104
    s 仅由括号 '()[]{}' 组成



*/


/*
    思路：
    使用栈来匹配括号，遍历字符串：
    - 遇到左括号时，将其压入栈中
    - 遇到右括号时，检查栈顶是否为对应的左括号，如果是则弹出栈顶，否则返回false
    最终检查栈是否为空，如果为空则括号匹配成功，否则返回false
*/
#include <iostream>
#include <string>
#include <stack>
using namespace std;
class Solution {
    public:
        bool isValid(string s) {
            stack <char> st;
            for (char c : s){
                if(isLeft(c))
                    st.push(c);
                else{
                    if(st.empty() || !isMatch(st.top(), c))
                        return false;
                    else    
                        st.pop();
                }

            }
            // 检查栈是否为空，如果为空则括号匹配成功，否则返回false
            return st.empty();
        }

    private:
        bool isLeft(char c) {
            return c == '(' || c == '[' || c == '{';
        }
        bool isMatch(char c1, char c2){
            return (c1 == '(' && c2 == ')') || 
                   (c1 == '[' && c2 == ']') || 
                   (c1 == '{' && c2 == '}');
        }
    };

int main() {
    Solution solution;
    cout << solution.isValid("()") << endl;
    cout << solution.isValid("()[]{}") << endl;
    cout << solution.isValid("(]") << endl;
    cout << solution.isValid("([])") << endl;
    cout << solution.isValid("([)]") << endl;
    return 0;
}

