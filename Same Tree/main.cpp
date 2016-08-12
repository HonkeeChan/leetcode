#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSameTree(TreeNode* p, TreeNode* q) {
    queue<TreeNode*> q1;
    queue<TreeNode*> q2;
    if(p == NULL && q==NULL){
        return true;
    }
    if(p) q1.push(p);
    if(q) q2.push(q);

    while(!q1.empty() && !q2.empty()){
        TreeNode* p1 = q1.front();
        TreeNode* p2 = q2.front();
        q1.pop();
        q2.pop();
        if(p1 -> val != p2 -> val)
            return false;
        if(p1->left) {
            q1.push(p1->left);
        }else{
            if(p2->left)
                return false;
        }
        if(p1->right) {
            q1.push(p1->right);
        }else{
            if(p2->right)
                return false;
        }
        if(p2->left) {
            q2.push(p2->left);
        }else{
            if(p1->left)
                return false;
        }
        if(p2->right) {
            q2.push(p2->right);
        }else{
            if(p2->right)
                return false;
        }
    }
    if(q1.empty() && q2.empty())
        return true;
    else
        return false;
}
int main() {
    cout << "Hello, World!" << endl;
    return 0;
}