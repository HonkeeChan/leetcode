#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin); 
TreeNode* BuildCore(const vector<int>& pre, int& preBeg, int& preEnd, 
            const vector<int>&  mid, int midBeg, int midEnd);
void visitPreOrder(TreeNode* proot);
int main(){
    vector<int> pre = {1,2,4,7,3,5,6,8};
    vector<int> mid = {4,7,2,1,5,3,8,6};
    TreeNode* root = reConstructBinaryTree(pre, mid);
    visitPreOrder(root);
}

TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin){
    if(pre.size() != vin.size() || pre.size() < 1){
        return NULL;
    }
    int preBeg = 0;
    int preEnd = pre.size();
    return BuildCore(pre, preBeg, preEnd, vin, 0, vin.size());
}

TreeNode* BuildCore(const vector<int>& pre,
                    int& preBeg, int& preEnd,
                    const vector<int>&  mid,
                    int midBeg, int midEnd){
    
    if(preBeg == preEnd){
        return NULL;
    }
    int rootVal = pre[preBeg++];
    int rootIdx = midBeg;
    TreeNode* pRoot = new TreeNode(rootVal);
   

    while(rootIdx != midEnd){
        if(mid[rootIdx] == rootVal){
            break;
        }
        rootIdx++;
    }

    cout << "pre val: " << rootVal << endl;
    cout << "mid left: ";
    copy(mid.begin() + midBeg, mid.begin() + rootIdx, ostream_iterator<int>(cout, " "));
    cout << endl;
    cout << "mid left: ";
    copy(mid.begin() + rootIdx + 1, mid.begin() + midEnd, ostream_iterator<int>(cout, " "));
    cout << endl;

    if(rootIdx - midBeg > 0){
        pRoot->left =  BuildCore(pre, preBeg,preEnd, mid, midBeg, rootIdx);
    }
    if(midEnd - rootIdx - 1 > 0){
        pRoot->right = BuildCore(pre, preBeg,preEnd, mid, rootIdx + 1, midEnd);
    }
    return pRoot;
}
void visitPreOrder(TreeNode* proot){
    if(proot == NULL){
        return;

    }
    cout << proot->val << " ";
    visitPreOrder(proot->left);
    visitPreOrder(proot->right);
}