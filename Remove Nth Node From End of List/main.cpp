#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * */
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};


ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* pFront = head;
    ListNode* pEnd = head;
    if(head->next == NULL){
        return NULL;
    }
    for(int i = 0; i < n; ++i){
        if(pFront->next)
            pFront = pFront->next;
        else
            return head->next;
    }
    while(pFront->next){
        pFront = pFront->next;
        pEnd = pEnd->next;
    }
    pEnd->next = pEnd->next->next;
    return head;
}
int main() {
    ListNode p1 = ListNode(1);
    ListNode p2 = ListNode(2);
    ListNode p3 = ListNode(3);
    ListNode p4 = ListNode(4);
    p1.next = &p2;
    p2.next = &p3;
    p3.next = &p4;

    cout << removeNthFromEnd(&p1,1) << endl;
    return 0;
}