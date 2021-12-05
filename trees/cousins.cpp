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
int height(TreeNode *root,int v,int& par,int h)
{
    if(root==NULL) return 0;
    if(root->val== v) return 1;
    par=root->val;
    int left = height(root->left,v,par,h+1);
    if(left) return left;
    par=root->val;
    int right=height(root->right,v,par,h+1);
    if(right) return right;
}
bool arecousins(TreeNode *root,int a,int b)
{
    if(root->val==a || root->val==b) return false;
    int para=-1,parb=-1;
    if(height(root,a,para,0)==height(root,b,parb,0) && para!=parb) return true;
    return false;
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
    root->left->left->right=new TreeNode(7);
    cout<<(arecousins(root,2,6)?"Yes":"No")<<endl;
}