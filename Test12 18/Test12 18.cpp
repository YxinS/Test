#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;
struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vv;
        queue<TreeNode*> q;
        if(root == nullptr)return vv;
        q.push(root);
        while(!q.empty()){
            int len = q.size();
            vector<int> v;
            while(len--){
                TreeNode* cur = q.front();
                q.pop();
                v.push_back(cur->val);
                if(cur->left)q.push(cur->left);
                if(cur->right)q.push(cur->right);
            }
            vv.push_back(v);
        }
        // reverse(vv.begin(),vv.end());
        return vv;
    }
    string tree2str(TreeNode* t) {
        string str;
        if(t == nullptr)return str;
        str += to_string(t->val);
        if(t->left){
            str+='(';
            str+=tree2str(t->left);
            str+=')';
        }
        else if(t->right){
            str+="()";
        }
        if(t->right){
            str+='(';
            str+=tree2str(t->right);
            str+=')';
        }
        return str;
    }
};


int main(){
    



    return 0;
}