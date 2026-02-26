/*
 * @lc app=leetcode.cn id=23 lang=cpp
 * @lcpr version=30400
 *
 * [23] 合并 K 个升序链表
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

// 用分治算法合并 k 个有序链表
class Solution {
    public:
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            if (lists.empty()) {
                return nullptr;
            }
            return mergeKLists3(lists, 0, lists.size() - 1);
        }
    
        // 定义：合并 lists[start..end] 为一个有序链表
        ListNode* mergeKLists3(vector<ListNode*>& lists, int start, int end) {
            if (start == end) {
                return lists[start];
            }
    
            int mid = start + (end - start) / 2;
            // 合并左半边 lists[start..mid] 为一个有序链表
            ListNode* left = mergeKLists3(lists, start, mid);
    
            // 合并右半边 lists[mid+1..end] 为一个有序链表
            ListNode* right = mergeKLists3(lists, mid + 1, end);
    
            // 合并左右两个有序链表
            return mergeTwoLists(left, right);
        }
    
        // 双指针技巧合并两个有序链表
        // https://labuladong.online/algo/essential-technique/linked-list-skills-summary/
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
            ListNode dummy(-1), *p = &dummy;
            ListNode* p1 = l1, *p2 = l2;
    
            while (p1 != nullptr && p2 != nullptr) {
                if (p1->val > p2->val) {
                    p->next = p2;
                    p2 = p2->next;
                } else {
                    p->next = p1;
                    p1 = p1->next;
                }
                p = p->next;
            }
    
            if (p1 != nullptr) {
                p->next = p1;
            }
    
            if (p2 != nullptr) {
                p->next = p2;
            }
    
            return dummy.next;
        }
    };
// @lc code=end



/*
// @lcpr case=start
// [[1,4,5],[1,3,4],[2,6]]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [[]]\n
// @lcpr case=end

 */

