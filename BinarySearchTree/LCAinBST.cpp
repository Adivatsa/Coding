Node* LCA(Node *root, int n1, int n2)
{
    //LCA for BST can have threee options
    //if n1 and n2 both are smaller than root data then go to left side for small value
    //if n1 and n2 both are larger than root data go to right side for big value
    //if n1 less than root data and n2 greater than root ka data ans will be root and Same Vice Versa
    
    if(root==NULL)
        return NULL;
    
    //Both smaller than root ka data go to left side
    if(n1 < root->data && n2 < root->data )
        return LCA(root->left,n1,n2);
    
    //Both Larger than root ka data go to right side
    if(n1 > root->data && n2 > root->data )
        return LCA(root->right,n1,n2);
    
    //for any other case
    return root;
}