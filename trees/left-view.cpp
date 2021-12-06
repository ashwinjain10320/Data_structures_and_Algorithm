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

void leftview(TreeNode *root,int lvl,int& sz)
{
    if(root==NULL) return;
    if(lvl==sz)
    {
        cout<<root->val<<" ";
        sz++;
    }
    leftview(root->left,lvl+1,sz);
    leftview(root->right,lvl+1,sz);
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
    root->right->left->left=new TreeNode(7);
    int sz=0;
    leftview(root,0,sz);
}