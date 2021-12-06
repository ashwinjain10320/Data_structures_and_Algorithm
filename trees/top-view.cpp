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
void topview(TreeNode* root,int lvl,map<int,int>& m)
{
    if(root==NULL) return;
    if(m.find(lvl)==m.end()) m[lvl]=root->val;
    topview(root->left,lvl-1,m);
    topview(root->right,lvl+1,m);
}
void display(map<int,int> m)
{
    for(auto i:m) cout<<i.second<<" ";
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
    map<int,int> m;
    topview(root,0,m);
    display(m);
}