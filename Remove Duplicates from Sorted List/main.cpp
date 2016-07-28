#include <iostream>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* deleteDuplicates20s(ListNode* head) {
    if(head == NULL)
        return NULL;
    int val = head->val;

    ListNode* p = head;
    while(p->next){
        if(p->next->val == val){
            p->next = p->next->next;
        }else{
            val = p->next->val;
            p = p->next;
        }
    }
    return head;
};

ListNode* deleteDuplicates_my_16s(ListNode* head) {
    if(head == NULL)
        return NULL;

    ListNode* p = head;
    while(p->next){
        if(p->next->val == p->val){
            p->next = p->next->next;
        }else{
            p = p->next;
        }
    }
    return head;
};

ListNode* deleteDuplicates12s(ListNode* head) {
    if(!head) return NULL;

    ListNode* temp = head;
    while( temp->next ) {
        if( temp->val == temp->next->val ) temp->next = temp->next->next;
        else temp = temp->next;
    }
    return head;
};
ListNode* deleteDuplicates17s(ListNode* head) {
    if(!head) return NULL;

    ListNode* temp = head;
    while( temp->next ) {
        if( temp->val == temp->next->val ) {
            temp->next = temp->next->next;
        }else {
            temp = temp->next;
        }
    }
    return head;
};

ListNode* deleteDuplicates16s(ListNode* head) {
    ListNode *cur = head;
    while (cur) {
        while (cur->next && cur->val == cur->next->val)
            cur->next = cur->next->next;
        cur = cur->next;
    }
    return head;
}
int main() {
    cout << "Hello, World!" << endl;
    return 0;
}