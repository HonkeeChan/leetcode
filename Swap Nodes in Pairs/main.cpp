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
    ListNode* p1 = head;
    ListNode* p2 = head->next;
    head = p2;
    while(p1 && p2){
        p1->next = p2->next;
        p2->next = p1;
        if(p1->next){
            p1 = p1->next;
            p2 = p1->next;
        }else{
            break;
        }
    }
    return head;
}
int main()
{
    ListNode p1 = ListNode(1);
    ListNode p2 = ListNode(2);
    p1.next = &p2;
    cout << swapPairs(&p1) << endl;
    return 0;
}
