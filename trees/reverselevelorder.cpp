#include<bits/stdc++.h>
using namespace std;
class TreeNode 
{
    public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int v)
    {
        val=v;
        left=right=NULL;
    }
};

void reverse_level_order(TreeNode *root)
{
    if(root==NULL) return;
    queue<TreeNode*> q;
    stack<int> s;
    q.push(root);
    while(!q.empty())
    {
        int sz=q.size();
        while(sz--)
        {
            TreeNode *curr=q.front();
            q.pop();
            s.push(curr->val);
            if(curr->right) q.push(curr->right);
            if(curr->left) q.push(curr->left);
        }
    }
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}
int main()
{
    TreeNode *root=new TreeNode(4);
    root->left=new TreeNode(5);
    root->right=new TreeNode(1);
    root->left->left=new TreeNode(2);
    root->left->right=new TreeNode(6);
    root->right->left=new TreeNode(0);
    root->right->right=new TreeNode(3);
    reverse_level_order(root);
}