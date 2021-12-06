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
    TreeNode* lca(TreeNode *root,TreeNode* a,TreeNode* b)
    {
        if(root==NULL || root==a || root==b) return root;
        TreeNode *left=lca(root->left,a,b);
        TreeNode *right=lca(root->right,a,b);
        if(left==NULL) return right;
        if(right==NULL) return left;
        return root;
    }
    
};
int main()
{
    Tree *t=new Tree(4);
    t->root->left=new TreeNode(5);
    t->root->right=new TreeNode(1);
    t->root->left->left=new TreeNode(2);
    t->root->left->right=new TreeNode(6);
    t->root->right->left=new TreeNode(0);
    t->root->right->right=new TreeNode(3);
    t->root->left->left->right=new TreeNode(7);
    TreeNode *a= t->root->right->right;
    TreeNode *b= t->root->left->right;
    cout<<t->lca(t->root,a,b)->val<<endl;
}