#include<iostream>
using namespace std;

struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool find(TreeNode* root,TreeNode*x){
        if(root==nullptr){
            return false;
        }
        return root==x || find(root->left,x) || find(root->right,x); 
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr)return nullptr;
        if(p == root|| q == root)return root;
        bool qintleft,qinright,pinleft,pinright;
        qintleft = find(root->left,q);
        qinright = !qintleft;
        pinleft = find(root->left,p);
        pinright = !pinleft;
        if(qintleft && pinright || pinleft && qinright){
            return root;
        }
        if(qinright && pinright){
            return lowestCommonAncestor(root->right,p,q);
        }
        if(qintleft && pinleft){
            return lowestCommonAncestor(root->left,p,q);
        }
        return nullptr;
    }
};


int main(){






    return 0;
}