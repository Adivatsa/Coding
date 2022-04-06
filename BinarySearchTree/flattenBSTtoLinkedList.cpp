//TC=O(n) but SC=O(n) 
// codestudio TLE
void inorder(TreeNode<int>* root, vector<TreeNode<int>*> &v)
{
    if(root==NULL)
        return ;
    
    inorder(root->left,v);
    v.push_back(root);
    inorder(root->right,v);
}
TreeNode<int>* flatten(TreeNode<int>* root)
{
    //sabse phle inorder nekal lo for node
    //har ek node ka left ko null and right ko next node pe point kara do
    //last ke dono null kara do
    vector<TreeNode<int>*> v;
    inorder(root,v);
 
    TreeNode<int>* curr=v[0];
   root=curr;
    for(int i=1; i<v.size(); i++)
    {
		TreeNode<int>* temp=v[i];
       	curr->left=NULL;
        curr->right=temp;
        curr=temp;

    }
    curr->left=NULL;
    curr->right=NULL;
       return root;
}
