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
void inorder_recursive(TreeNode *root)
{
    if(root==NULL) return;
    inorder_recursive(root->left);
    cout<<root->val<<" ";
    inorder_recursive(root->right);
}
void inorder_iterative(TreeNode *root)
{
    stack<TreeNode *> s;
    TreeNode *temp=root;
    while(true)
    {
        if(temp!=NULL)
        {
            s.push(temp);
            temp=temp->left;
        }
        else
        {
            if(s.empty()) break;
            temp=s.top();
            s.pop();
            cout<<temp->val<<" ";
            temp=temp->right;
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
    inorder_iterative(root);
    inorder_recursive(root);
}