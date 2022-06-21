    bool solve(TreeNode* lroot, TreeNode* rroot)
    {
        if(lroot!=NULL && rroot!=NULL)
        {
            //Inside the tree we have to go in left subtree left
            //then right subtree to right part
            bool temp1=solve(lroot->left,rroot->right);
            bool temp2=solve(lroot->right,rroot->left);//in left subtree right then
            //in right subtre left side
        
            if(lroot->val==rroot->val && temp1==true && temp2==true)
                return true;
            else
                return false;
        }
        
        if(lroot==NULL && rroot==NULL)
            return true;
        else
            return false;    
    }
    
    bool isSymmetric(TreeNode* root) {
        
        //For symmetrical just check for mirror image
        //in left subtree left part is becoming right in right subtree
        if(root==NULL)
            return true;
        
        //we have to check symmtery to root left and root right part
        return solve(root->left, root->right);
        
    }