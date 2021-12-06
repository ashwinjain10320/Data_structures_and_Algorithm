#include<bits/stdc++.h>
using namespace std;

class TreeNode
{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int v)
    {
        val=v;
        left=right=NULL;
    }
};
class Tree
{
    public:
    TreeNode *root;
    Tree(int v)
    {
        root=new TreeNode(v);
    }
    int tosum(TreeNode *root)
    {
        if(root==NULL) return 0;
        int ov=root->val;
        root->val = tosum(root->left)+tosum(root->right);
        return root->val+ov;
    }
    
};
int main()
{
    Tree *t=new Tree(10);
    t->root->left=new TreeNode(-2);
    t->root->right=new TreeNode(6);
    t->root->left->left=new TreeNode(8);
    t->root->left->right=new TreeNode(-4);
    t->root->right->left=new TreeNode(7);
    t->root->right->right=new TreeNode(5);
    t->tosum(t->root);
    cout<<t->root->val<<endl;
    cout<<t->root->left->val<<" "<<t->root->right->val<<endl;
    cout<<t->root->left->left->val<<" "<<t->root->left->right->val<<" "<<t->root->right->left->val<<" "<<t->root->right->right->val<<endl;
}
