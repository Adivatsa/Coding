Node* solve(Node* root)
    {
        
        //it is for the leaf node will have no any pointer 
        if(root->left==NULL && root->right==NULL)
            return root;
        else
        {
            //connect left and right of root 
            Node* curr=root;
            curr->left->next=curr->right;
            if(curr->next!=NULL)
                curr->right->next=curr->next->left;
            else
                curr->right->next=NULL;
            curr=curr->next;
        }
        //left and right recursive call 
        root->left=solve(root->left);
        root->right=solve(root->right);
        
        return root;
    }
    Node* connect(Node* root) {
        
        if(root==NULL)
            return root;
        root->next=NULL;
        return solve(root);
        
    }