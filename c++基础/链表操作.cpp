//如何创建链表

#include <iostream>
using namespace std;

typedef struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
}ListNode;

int createList() {
    // 创建链表 一个头指针和一个当前指针
    ListNode* head = new ListNode(1);
    ListNode* p = head;
    p->next = new ListNode(2);
    p = p->next;
    p->next = new ListNode(3);
    p = p->next;
    p->next = new ListNode(4);
    p = p->next;
    p->next = new ListNode(5);
    p = p->next;
    p->next = nullptr;
    


    for (ListNode* p = head; p != nullptr; p = p->next) {
        cout << p->val << " ";
    }
    return 0;
}


int main() {
    createList();
    return 0;
}

