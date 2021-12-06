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
    void rootleafnum(TreeNode *root,int& sum,int& c)
    {
        c=c*10 +(root->val);
        if(root->left) rootleafnum(root->left,sum,c);
        if(root->right) rootleafnum(root->right,sum,c);
        if(root->left==NULL && root->right==NULL) sum+=c;
        c/=10;
    }
};
int main()
{
    Tree *t=new Tree(1);
    t->root->left=new TreeNode(2);
    t->root->right=new TreeNode(3);
    t->root->left->left=new TreeNode(4);
    t->root->left->right=new TreeNode(8);
    t->root->right->left=new TreeNode(7);
    t->root->right->right=new TreeNode(5);
    int sum=0,c=0;
    t->rootleafnum(t->root,sum,c);
    cout<<sum<<endl;
}
