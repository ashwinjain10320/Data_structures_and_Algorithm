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

    int height(TreeNode* root,int &maxh)
    {
        if(root==NULL) return 0;
        int lh=height(root->left,maxh);
        int rh=height(root->right,maxh);
        maxh=max(maxh,1+lh+rh);
        return 1+max(lh,rh);
    }
    int diameter()
    {
        int maxh=0;
        height(root,maxh);
        return maxh;
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
    cout<<t->diameter()<<endl;
}