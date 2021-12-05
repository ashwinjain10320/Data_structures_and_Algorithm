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
void preorder_recursive(TreeNode *root)
{
    if(root==NULL) return;
    cout<<root->val<<" ";
    preorder_recursive(root->left);
    preorder_recursive(root->right);
}
void preorder_iterative(TreeNode *root)
{
    stack<TreeNode *> s;
    s.push(root);
    while(!s.empty())
    {
        int i=s.size();
        while(i--)
        {
            TreeNode *temp=s.top();
            s.pop();
            cout<<temp->val<<" ";
            if(temp->right) s.push(temp->right);
            if(temp->left) s.push(temp->left);
        }
    }
    cout<<endl;
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
    preorder_iterative(root);
    preorder_recursive(root);
}