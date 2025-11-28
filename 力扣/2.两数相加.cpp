/*
2.两数相加
给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头。


示例 1：
输入：l1 = [2,4,3], l2 = [5,6,4]
输出：[7,0,8]
解释：342 + 465 = 807.

示例 2：

输入：l1 = [0], l2 = [0]
输出：[0]

示例 3：

输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
输出：[8,9,9,9,0,0,0,1]


*/
#include <iostream>
#include <vector>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* head = new ListNode(0);
        ListNode* p = head;

        while(l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum / 10;
            p->next = new ListNode(sum % 10);
            p = p->next;
        }
        return head->next;
        return head;
    }

    ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2) {
        // 链表需要一个头节点 和 一个当前节点
        ListNode *l3 = nullptr, *cur = nullptr;
        int carry = 0;
        // 当l1或l2或carry不为空时，继续循环
        while(l1 || l2 || carry){
            int val = carry;
            carry = 0;
            if (l1) {
                val += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                val += l2->val;
                l2 = l2->next;
            }
            if (val > 9) {
                val -= 10;
                carry = 1;                
            }
            if (!cur) {
                l3 = new ListNode(val);
                cur = l3;
            } else {
                cur->next = new ListNode(val);
                cur = cur->next;
            }
        }
        return l3;
        }
};

ListNode* createList(const std::vector<int>& values) {
    ListNode* head = new ListNode(0);
    ListNode* current = head;
    for (int val : values) {
        current->next = new ListNode(val);
        current = current->next;
    }
    return head->next;
}


int main() {
    Solution solution;
    // 测试用例1
    // ListNode* l1 = createList({2,4,3});
    // ListNode* l2 = createList({5,6,4});
    // 测试用例2
    // ListNode* l1 = createList({0});
    // ListNode* l2 = createList({0});
    // 测试用例3
    ListNode* l1 = createList({9,9,9,9,9,9,9});
    ListNode* l2 = createList({9,9,9,9});

    ListNode* result = solution.addTwoNumbers(l1, l2);
    while(result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}