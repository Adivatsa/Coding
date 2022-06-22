void solve(TreeNode<int> * root, int x, int &ans)
{
    if(root==NULL)
        return;
    TreeNode<int> * curr=root;
    while(curr!=NULL)
    {
        if(curr->val==x)
        {
            ans=curr->val;
            return;
        }
        else if(curr->val<x)//chota mil gaya hai then store and find bigger than this so move to right
        {
            ans=curr->val;
            curr=curr->right;
        }
        else//we want smaller than x so go to left side
        {
            curr=curr->left;
        }
    }
    
}
int floorInBST(TreeNode<int> * root, int X)
{
    int ans=-1;
    if(root==NULL)
        return ans;
    solve(root,X,ans);
    return ans;
}