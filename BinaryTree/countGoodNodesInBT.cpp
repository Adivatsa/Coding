    int solve(TreeNode* root, int maxNode)
    {
        if(root==NULL)
            return 0;
        
        //At each level caluate the max value node
        maxNode=max(maxNode,root->val);
        //left call if root value is greater or equal to max node 
        if(root->val>=maxNode)
            return 1+solve(root->left,maxNode)+ solve(root->right,maxNode);
        else
            return solve(root->left,maxNode)+ solve(root->right,maxNode);   
    }
    int goodNodes(TreeNode* root) {
        
        //Steps:
        //Base case when   root is Null then there is no any node is present
        //maxNode will have the value to that level 
        //every time making left and right call id root value is greater than maxvalue 
        //ocunt will be increased by 1 for good nodes
        if(root==NULL)
            return 0;
        
        
        int maxNode=INT_MIN;
        return solve(root,maxNode);
    }