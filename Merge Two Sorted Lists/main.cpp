#include <iostream>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(l1 == NULL)
        return l2;
    if(l2 == NULL)
        return l1;

    ListNode* ret = new ListNode(-1);
    ListNode* cur = ret;

    while(l1 && l2){
        if(l1->val < l2->val){
            if(l1){
                cur->next = l1;
                l1 = l1->next;
                cur = cur->next;
            }else{
                break;
            }
        }else{
            if(l2){
                cur->next = l2;
                l2 = l2->next;
                cur = cur->next;
            }else{
                break;
            }
        }
    }
    if(l2){
        cur->next = l2;
    }
    if(l1){
        cur->next = l1;
    }
    return ret->next;
}

int main() {
    ListNode l11 = ListNode(1);
    ListNode l12 = ListNode(2);
    ListNode l13 = ListNode(2);
    ListNode l14 = ListNode(3);
    ListNode l21 = ListNode(3);
    ListNode l22 = ListNode(4);
    l11.next = &l12;
    l12.next = &l13;
    l13.next = &l14;

    l21.next = &l22;
    //ListNode l23 = ListNode(1);
    //ListNode l21 = ListNode(1);
    mergeTwoLists(&l11, &l21);
    return 0;
}