/*
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 


示例 1：
输入：l1 = [1,2,4], l2 = [1,3,4]
输出：[1,1,2,3,4,4]

示例 2：

输入：l1 = [], l2 = []
输出：[]

示例 3：

输入：l1 = [], l2 = [0]
输出：[0]

 

提示：

    两个链表的节点数目范围是 [0, 50]
    -100 <= Node.val <= 100
    l1 和 l2 均按 非递减顺序 排列

*/

/*
    思路：
        1.创建指针p1, p2 分别指向l1, l2的头节点
        2.比较p1, p2的值，将较小的值插入到新链表中
        3.移动指针p1, p2 到下一个节点
        4.重复步骤2, 3, 直到其中一个指针为空，将另一个指针的剩余节点插入到新链表中
        5.返回新链表的头节点
*/



#include<iostream>
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
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            ListNode* p1 = list1;
            ListNode* p2 = list2;
            ListNode* head = new ListNode(0);
            ListNode* p = head;
            while(p1 != nullptr && p2 != nullptr){
                if(p1->val < p2->val){
                    p->next = p1;
                    p1 = p1->next;
                    p = p->next;
                }
                else{
                    p->next = p2;
                    p2 = p2->next;
                    p = p->next;
                }
            }
            if(p1 == nullptr){
                p->next = p2;
            }
            else{
                p->next = p1;
            }
            printList(head->next);
            return head->next;
        }
    private:
        void printList(ListNode* head){
            ListNode* p = head;
            while(p != nullptr){
                cout << p->val << " ";
                p = p->next;
            }
            cout << endl;
        }
    };


int main(){
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);

    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    Solution solution;
    ListNode* mergedList = solution.mergeTwoLists(l1, l2);

    return 0;
}