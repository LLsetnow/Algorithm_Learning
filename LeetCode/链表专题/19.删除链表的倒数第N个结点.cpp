/*
给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

输入：head = [1,2,3,4,5], n = 2
输出：[1,2,3,5]

示例 2：

输入：head = [1], n = 1
输出：[]

示例 3：

输入：head = [1,2], n = 1
输出：[1]

 

*/

#include <iostream>
using namespace std;

 struct ListNode {
     int val;
     ListNode* next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            ListNode *p, *q;
            p = q = head;
            while(p != nullptr && n > 0) {
                p = p->next;
                n--;
            }
            // 如果p为空，则删除头节点
            if(p == nullptr) {
                return head->next;
            }
            while(p->next != nullptr) {
                p = p->next;
                q = q->next;
            }
            // 删除倒数第n个节点
            q->next = q->next->next;
            return head;
        }
    };


int main() {
    Solution solution;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    int n = 2;
    ListNode* result = solution.removeNthFromEnd(head, n);
    while(result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
}