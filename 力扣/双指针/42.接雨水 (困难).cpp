/*
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
height = [0,1,0,2,1,0,1,3,2,1,2,1]

思路1：栈
    1. 维护一个单调递增的栈，栈中存放的是索引
    2. 遍历数组，如果当前元素小于栈顶元素，则入栈，否则出栈，直到栈为空或者当前元素小于栈顶元素
    3. 出栈时，计算出栈元素和当前元素之间的雨水量，并累加到结果中
    4. 重复步骤2，直到遍历完数组
思路2：双指针

*/
#include<iostream>
#include<vector>
#include<stack>
using namespace std;    
class Solution {
    private:
        void print_stack(stack<int> st, vector<int>& height){
            while (!st.empty()) {
                cout << height[st.top()] << " ";
                st.pop();
            }
            cout << endl;
        }
    public:
        int trap(vector<int>& height) {
            int sum = 0;
            stack<int> st;
            int current = 0;
            while (current < (int)height.size()) {
                cout << "current: " << current << endl;
                // 如果栈不空并且当前指向的高度大于栈顶高度就一直循环
                while (!st.empty() && height[current] > height[st.top()]) {
                    int h = height[st.top()]; // 取出要出栈的元素
                    st.pop(); // 出栈
                    print_stack(st, height);
                    if (st.empty()) { // 栈空就出去
                        break;
                    }
                    int distance = current - st.top() - 1; // 两堵墙之前的距离
                    int min_height = min(height[st.top()], height[current]);
                    sum = sum + distance * (min_height - h);
                    cout << "sum: " << sum << endl;
                }
                st.push(current); // 当前指向的墙入栈
                print_stack(st, height);
                current++; // 指针后移
            }
            return sum;
        }

    };


int main(){
    system("chcp 65001>nul");
    Solution s;
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << s.trap(height) << endl;
    return 0;
}