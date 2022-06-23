class Solution
{
    public: 
    
    Node* head=NULL;
    Node* prev=NULL;
    
    //Traverse in the form of inorder
    void inorder(Node* root)
    {
        if(root==NULL)
        return ;
        
        //LNR
        inorder(root->left);
        //if it is first node then assign it to head
        //otherwise
        //root ka left to prev and prev ka next to root
        //at last assign prev as root node
        if(prev==NULL)
            head=root;
        else
        {
            root->left=prev;
            prev->right=root;
        }
        prev=root;
        
        inorder(root->right);
    }
    //Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root)
    {
        
        inorder(root);
        return head;
    }
};