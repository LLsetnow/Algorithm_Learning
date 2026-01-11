/*
给你一个链表的头节点 head ，判断链表中是否有环。
如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。
为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
注意：pos 不作为参数进行传递 。仅仅是为了标识链表的实际情况。
如果链表中存在环 ，则返回 true 。 否则，返回 false 。

进阶：你能用 O(1)（即，常量）内存解决此问题吗？
*/

#include <iostream>
#include <unordered_set>
using namespace std;


/*
    思路1：
    1. 使用快慢指针
    2. 快指针每次走两步，慢指针每次走一步
    3. 如果快指针和慢指针相遇，则链表中存在环
    4. 如果快指针走到链表末尾，则链表中不存在环

    时间复杂度：O(n)
    空间复杂度：O(1)

    思路2：
    1. 使用哈希表
    2. 遍历链表，将每个节点加入哈希表
    3. 如果链表中存在环，则哈希表中会存在重复的节点
    4. 如果链表中不存在环，则哈希表中不会存在重复的节点
*/

 struct ListNode {
     int val;
     ListNode* next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
    public:
        bool hasCycle(ListNode *head) {
            ListNode* slow = head;
            ListNode* fast = head;
            while(fast != nullptr && fast->next != nullptr){
                slow = slow->next;
                fast = fast->next->next;
                if(slow == fast)
                    return true;
            }
            return false;            
        }
        bool hasCycle2(ListNode *head) {
            unordered_set<ListNode*> set;
            while(head != nullptr){
                if(set.find(head) != set.end())
                    return true;
                set.insert(head);
                head = head->next;
            }
            return false;
        }
    };

int main() {
    Solution solution;
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next;
    cout << solution.hasCycle(head) << endl;
    return 0;
}