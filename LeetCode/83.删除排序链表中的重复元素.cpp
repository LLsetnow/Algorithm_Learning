/*
 * @lc app=leetcode.cn id=83 lang=cpp
 * @lcpr version=30400
 *
 * [83] 删除排序链表中的重复元素
 */
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
    
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode* pre = head;
        ListNode* p = head->next;
        while(p != nullptr){
            if(pre->val == p->val){
                ListNode* tmp = p;
                pre->next = p->next;
                p = p->next;
                delete tmp;
            }
            else{
                pre = p;
                p = p->next;
            }
        }
        //printList(head);
        return head;
    }

    void printList(ListNode* head){
        ListNode* p = head;
        while(p != nullptr){
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }

};
// @lc code=end
int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);
    Solution s;
    s.deleteDuplicates(head);
}


/*
// @lcpr case=start
// [1,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,2,3,3]\n
// @lcpr case=end

 */

