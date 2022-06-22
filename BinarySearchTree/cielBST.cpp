void solve(BinaryTreeNode<int> *root, int x, int &ans)
{
    if(root==NULL)
        return ;
   BinaryTreeNode<int> *curr=root;
    while(curr!=NULL)
    {
        if(x==curr->data)
        {
            ans=curr->data;
            return;
            
        }//just greater mil gaya hai store kara ke left se ishe chota dekho
        else if(x<curr->data)
        {
            ans=curr->data;
            curr=curr->left;
        }
        else//if smaller then go to right and find bigger value
            curr=curr->right;
    }
}
int findCeil(BinaryTreeNode<int> *node, int x){
    
    if(node==NULL)
        return -1;
    int ans=-1;
    solve(node,x,ans);
    return ans;
    
}