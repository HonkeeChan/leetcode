#include <iostream>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
ListNode* swapPairs(ListNode* head) {
    if(!head || !head->next){
        return head;
    }
    ListNode* tmp = new ListNode(0);
    ListNode* tmpHead = tmp;
    tmp->next = head;
    ListNode* p1 = head;
    ListNode* p2 = head->next;
    while(p1 && p2){
        p1->next = p2->next;
        p2->next = p1;
        tmp->next = p2;
        tmp = p1;
        if(p1->next){
            p1 = p1->next;
            p2 = p1->next;
        }else{
            break;
        }
    }
    return tmpHead->next;
}
int main()
{
    ListNode p1 = ListNode(1);
    ListNode p2 = ListNode(2);
    ListNode p3 = ListNode(3);
    ListNode p4 = ListNode(4);
    ListNode p5 = ListNode(5);
    p1.next = &p2;
    p2.next = &p3;
    p3.next = &p4;
    p4.next = &p5;
    cout << swapPairs(&p1) << endl;
    return 0;
}
