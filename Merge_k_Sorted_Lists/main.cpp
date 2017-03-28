#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

struct greater1{
  bool operator()(const ListNode* const a,const ListNode* const b) const{
    return a->val > b->val;
  }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    if(lists.empty()){
        return nullptr;
    }
     size_t len = lists.size();
     vector<ListNode*> v;
     for(int i = 0; i < len; ++i){
         if(lists[i] != nullptr)
            v.push_back(lists[i]);
     }
     ListNode* p = new ListNode(-1);
     ListNode* head = p;
     make_heap(v.begin(), v.end(), greater1());
     while(v.size() > 1){
         p->next = v.front();
         p = p->next;
         pop_heap(v.begin(), v.end(), greater1());
         v.pop_back();
         if(p->next){
            v.push_back(p->next);
            push_heap(v.begin(), v.end(), greater1());
         }
     }
     if(v.size() == 1)
        p->next = v.front();
     return head->next;
}

int main(){
    ListNode* p1 = new ListNode(1);
    ListNode* p2 = new ListNode(2);
    ListNode* p3 = new ListNode(3);
    ListNode* p4 = new ListNode(4);

    ListNode* p5 = new ListNode(2);
    ListNode* p6 = new ListNode(3);
    ListNode* p7 = new ListNode(4);

    ListNode* p8 = new ListNode(1);
    ListNode* p9 = new ListNode(7);
    ListNode* p10 = new ListNode(9);
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;

    p5->next = p6;
    p6->next = p7;

    p8->next = p9;
    p9->next = p10;

    vector<ListNode*> v = {p1,p5,p8};

    mergeKLists(v);
}