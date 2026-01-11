
#include <D:\github\Algorithm_Learning\LeetCode\headfile\stdc++.h>
using namespace std;

/*
    std::stack<int> s;
    push(): 在栈顶添加一个元素。
    pop(): 移除栈顶元素。
    top(): 返回栈顶元素的引用，但不移除它。
    empty(): 检查栈是否为空。
    size(): 返回栈中元素的数量。

*/

int main(){
    system("clear");
    system("chcp 65001>nul");
    
    // 初始化栈
    stack<int> s;

    // 向栈中添加元素
    s.push(1);
    s.push(2);
    s.push(3);

    // 访问栈顶元素
    std::cout << "Top element is: " << s.top() << std::endl;

    // 移除栈顶元素
    s.pop();
    std::cout << "After popping, top element is: " << s.top() << std::endl;

    // 检查栈是否为空
    if (!s.empty()) {
        std::cout << "Stack is not empty." << std::endl;
    }

    // 打印栈的大小
    std::cout << "Size of stack: " << s.size() << std::endl;

    return 0;
}