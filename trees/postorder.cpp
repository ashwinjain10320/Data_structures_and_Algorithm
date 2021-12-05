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
void postorder_recursive(TreeNode *root)
{
    if(root==NULL) return;
    postorder_recursive(root->left);
    postorder_recursive(root->right);
    cout<<root->val<<" ";
}
void postorder_iterative(TreeNode *root)
{
    stack<TreeNode *> s;
    TreeNode *curr=root;
    while(curr!=NULL || !s.empty())
    {
        if(curr!=NULL)
        {
            s.push(curr);
            curr=curr->left;
        }
        else
        {
            TreeNode *temp=s.top()->right;
            if(temp!=NULL)
            {
                curr=temp;
            }
            else
            {
                do
                {
                    temp=s.top();
                    s.pop();
                    cout<<temp->val<<" ";
                } while (!s.empty() && temp==s.top()->right);
            }
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
    postorder_iterative(root);
    postorder_recursive(root);
}