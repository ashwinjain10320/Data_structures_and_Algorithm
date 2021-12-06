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
bool isleaf(TreeNode *root)
{
    return root->left==NULL && root->right==NULL;
}
void lefttrav(TreeNode *root,vector<int>& ans)
{
    TreeNode* temp=root->left;
    while(temp)
    {
        if(!isleaf(temp)) ans.push_back(temp->val);
        if(temp->left) temp=temp->left;
        else temp=temp->right;
    }
}
void leaf(TreeNode *root,vector<int>& ans)
{
    if(isleaf(root)) 
    {
        ans.push_back(root->val);
        return;
    }
    if(root->left) leaf(root->left,ans);
    if(root->right) leaf(root->right,ans);
}
void righttrav(TreeNode *root,vector<int>& ans)
{
    stack<int> s;
    TreeNode* temp=root->right;
    while(temp)
    {
        if(!isleaf(temp)) s.push(temp->val);
        if(temp->right) temp=temp->right;
        else temp=temp->left;
    }
    while(!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
}
void boundarytraversal(TreeNode *root)
{
    vector<int> ans;
    if(root==NULL) return;
    if(!isleaf(root)) ans.push_back(root->val);
    lefttrav(root,ans);
    leaf(root,ans);
    righttrav(root,ans);
    for(int i:ans)
    {
        cout<<i<<" ";
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
    root->right->left->left=new TreeNode(7);
    boundarytraversal(root);
    
}