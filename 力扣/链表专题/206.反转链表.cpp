/*
给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。

示例 1：
输入：head = [1,2,3,4,5]
输出：[5,4,3,2,1]

示例 2：
输入：head = [1,2]
输出：[2,1]

示例 3：

输入：head = []
输出：[]

 

提示：

    链表中节点的数目范围是 [0, 5000]
    -5000 <= Node.val <= 5000

   进阶：链表可以选用迭代或递归方式完成反转。你能否用两种方法解决这道题？ 
*/

#include <iostream>
using namespace std;


 struct ListNode {
     int val;
     ListNode* next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode* next) : val(x), next(next) {}
};
 
class Solution {
    public:
        // 反转链表
        // 1. 定义前一个节点和当前节点
        // 2. 记录下一个节点
        // 3. 将当前节点的next指向前一个节点
        // 4. 更新前一个节点和当前节点
        // 5. 最后返回前一个节点
        ListNode* reverseList(ListNode* head) {
            ListNode* prev = nullptr; // 前一个节点
            ListNode* curr = head;  // 当前节点
            while (curr != nullptr) {
                ListNode* next = curr->next; // 下一个节点
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            // prev 是最后一轮的当前节点，也是反转后的头节点
            return prev;
        }
        // 反转链表2
        // 递归反转链表
        ListNode* reverseList2(ListNode* head) {
            if (head == nullptr || head->next == nullptr) {
                return head;
            }
            ListNode* newHead = reverseList2(head->next);
            head->next->next = head;
            head->next = nullptr;
            return newHead;
        }
        // 打印链表
        void printList(ListNode* head) {
            while (head != nullptr) {
                cout << head->val << " ";
                head = head->next;
            }
            cout << endl;
        }
};

int main() {
    Solution solution;
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    solution.printList(head);
    ListNode* result = solution.reverseList2(head);
    solution.printList(result);

    return 0;
}