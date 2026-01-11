/*
给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。

输入：head = [1,2,2,1]
输出：true

输入：head = [1,2]
输出：false


思路1：
    使用栈，将链表的值压入栈中，然后遍历链表，比较栈顶元素和链表节点的值，如果相等，则继续遍历，否则返回false。
思路2：
    使用快慢指针，快指针每次走两步，慢指针每次走一步，当快指针走到链表末尾时，慢指针正好走到链表中间。
    使用一个栈，将慢指针走过的节点值压入栈中。
    奇数个节点时，慢指针正好走到中间节点，偶数个节点时，慢指针正好走到中间节点的下一个节点。
    然后从中间开始遍历链表，比较链表节点的值和栈顶元素的值，如果相等，则继续遍历，否则返回false。
    时间复杂度：O(n)
    空间复杂度：O(n/2) = O(n)
思路3：
    找到中间节点后，翻转后半链表，从头节点和中间节点开始比对两半链表的值，如果相等，则继续遍历，否则返回false。
    时间复杂度：O(n)
    空间复杂度：O(1)
*/

#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        // 思路1：使用栈
        bool isPalindrome(ListNode* head) {
            stack<int> s;
            ListNode* p = head;
            while(p != nullptr){
                s.push(p->val);
                p = p->next;
            }
            p = head;
            while(p != nullptr){
                if(p->val != s.top())
                    return false;
                s.pop();
                p = p->next;
            }
            return true;
        }
        // 思路2：使用快慢指针
        bool isPalindrome2(ListNode* head) {
            stack<int> s;
            ListNode* slow = head;
            ListNode* fast = head;
            while(fast != nullptr && fast->next != nullptr){
                s.push(slow->val);
                slow = slow->next;
                fast = fast->next->next;
            }
            // 奇数个节点时，慢指针正好走到中间节点，偶数个节点时，慢指针正好走到中间节点的下一个节点。
            if(fast != nullptr)
                slow = slow->next;
            // 从中间开始遍历链表，比较链表节点的值和栈顶元素的值，如果相等，则继续遍历，否则返回false。
            while(slow != nullptr){
                if(slow->val != s.top())
                    return false;
                s.pop();
                slow = slow->next;
            }
            return true;
        }

        bool isPalindrome3(ListNode* head) {
            ListNode* slow = head;
            ListNode* fast = head;
            while(fast != nullptr && fast->next != nullptr){
                slow = slow->next;
                fast = fast->next->next;
            }
            // 奇数个节点时，慢指针正好走到中间节点，偶数个节点时，慢指针正好走到中间节点的下一个节点。
            // 奇数个节点时，慢指针需要再走一步，偶数个节点时，慢指针不需要再走一步。
            if(fast != nullptr)
                slow = slow->next;
            // 翻转后半链表
            ListNode* mid = reverseList(slow);
            // 从头节点和中间节点开始比对两半链表的值，如果相等，则继续遍历，否则返回false。
            while(head != nullptr && mid != nullptr){
                if(head->val != mid->val)
                    return false;
                head = head->next;
                mid = mid->next;
            }
            return true;
        }
        ListNode* reverseList(ListNode* head) {
            ListNode* prev = nullptr;
            ListNode* curr = head;
            while(curr != nullptr){
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            return prev;
        }
    };

int main() {
    system("clear");
    system("chcp 65001>nul");
    Solution solution;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
    cout << solution.isPalindrome3(head) << endl;
    return 0;
}