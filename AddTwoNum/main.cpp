#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* cur1 = l1;
    ListNode* cur2 = l2;
    ListNode* retHeadNode = NULL;
    ListNode* curNode = NULL;
    int carry = 0;
    while(cur1 != NULL && cur2 != NULL){
        int sum = cur1->val + cur2->val;
        int val = sum + carry;
        ListNode* tmp = new ListNode(val % 10);
        carry = val / 10;
        if(curNode == NULL){
            retHeadNode = tmp;
            curNode = tmp;
        }else {
            curNode->next = tmp;
            curNode = tmp;
        }
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    if(cur1 != NULL){
        do{
            int val = cur1->val + carry;
            carry = val / 10;
            cur1->val = val % 10;
            curNode->next = cur1;
            curNode = curNode->next;
            cur1 = cur1->next;
        }while(carry != 0 && cur1 != NULL);


    }
    if(cur2 != NULL){
        do{
            int val = cur2->val + carry;
            carry = val / 10;
            cur2->val = val % 10;
            curNode->next = cur2;
            curNode = curNode->next;
            cur2 = cur2->next;
        }while(carry != 0 && cur2 != NULL);

    }
    if(cur1 == NULL && cur2 == NULL && carry != 0){

        ListNode* tmp = new ListNode(carry);
        curNode->next = tmp;
    }

    return retHeadNode;
}


int main() {
    ListNode* l1 = new ListNode(3);
    l1->next = new ListNode(2);
    ListNode* l2 = new ListNode(9);
    l2->next = new ListNode(7);

    addTwoNumbers(l1,l2);
    return 0;
}