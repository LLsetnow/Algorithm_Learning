/*
请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：

实现 MyQueue 类：

    void push(int x) 将元素 x 推到队列的末尾
    int pop() 从队列的开头移除并返回元素
    int peek() 返回队列开头的元素
    boolean empty() 如果队列为空，返回 true ；否则，返回 false

说明：

    你 只能 使用标准的栈操作 —— 也就是只有 push to top, peek/pop from top, size, 和 is empty 操作是合法的。
    你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。

 

示例 1：

输入：
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
输出：
[null, null, null, 1, 1, false]

解释：
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false

 

提示：

    1 <= x <= 9
    最多调用 100 次 push、pop、peek 和 empty
    假设所有操作都是有效的 （例如，一个空的队列不会调用 pop 或者 peek 操作）

*/

#include <stack>
#include <iostream>
using namespace std;

class MyQueue {
    private:
        stack<int> stack1;
        stack<int> stack2;
    public:
        MyQueue() {
            
        }
        
        void push(int x) {
            stack1.push(x);
        }
        // 队头元素出列
        // 将stack1中的元素移到stack2中，然后弹出stack2的栈顶元素
        int pop() {
            if(stack2.empty()){
                while(!stack1.empty()){
                    stack2.push(stack1.top());
                    stack1.pop();
                }
            }
            int result = stack2.top();
            stack2.pop();
            return result;
        }
        // 返回队列开头的元素
        int peek() {
            if(stack2.empty()){
                while(!stack1.empty()){
                    stack2.push(stack1.top());
                    stack1.pop();
                }
            }
            return stack2.top();
        }
        
        bool empty() {
            return stack1.empty() && stack2.empty();
        }
    };


int main(){
    // 测试用例1
    MyQueue myQueue;
    myQueue.push(1); 
    myQueue.push(2);
    myQueue.push(3);
    myQueue.push(4);
    cout << myQueue.pop() << endl; // 应该输出1
    myQueue.push(5);
    cout << myQueue.pop() << endl; // 应该输出2
    cout << myQueue.pop() << endl; // 应该输出3
    cout << myQueue.pop() << endl; // 应该输出4
    cout << myQueue.pop() << endl; // 应该输出5

    // 测试用例2
    MyQueue myQueue2;
    myQueue2.push(1);
    myQueue2.push(2);
    myQueue2.push(3);
    myQueue2.push(4);
    myQueue2.push(5);
    cout << myQueue2.pop() << endl; 

}