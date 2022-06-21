    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(root==NULL)
            return root;
        
        if(root->val==key)
        {
            //elemet found so perform deletion
            //0 child case
            if(root->left==NULL && root->right==NULL)
            {
                delete root;
                return NULL;
            }
            
            //1 child case
            if(root->left==NULL && root->right!=NULL)
            {
                //Store the child node and dete and return child node
                TreeNode* temp=root->right;
                delete root;
                return temp;
            }
            if(root->left!=NULL && root->right==NULL)
            {
                //Store the child node and dete and return child node
                TreeNode* temp=root->left;
                delete root;
                return temp;
            }
            
            //2 Child case
            if(root->left!=NULL && root->right!=NULL)
            {
                //we can find minimum value from left an replace the root data from min value and call recursively to delete the min value root ka left part
                TreeNode* curr=root->right;
                while(curr->left!=NULL)
                    curr=curr->left;
                int  mini=curr->val;
                root->val=mini;
                root->right=deleteNode(root->right,mini);
                return root;
            }
        }
        else if(root->val>key)
            root->left= deleteNode(root->left,key);
        else
            root->right= deleteNode(root->right,key);
        
        return root;
        
    }