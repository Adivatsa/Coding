    int solve(TreeNode* root)
    {
        //Base case
        if(root==NULL)
            return 0;
        //check if it is leaf node then return the value of the node
        if(root->left==NULL && root->right==NULL)
        {
            //check if root is 0 then return 0 else return  1
            if(root->val==0)
                return 0;
            else
                return 1;
        }
        //left and right recursive call
        int leftside=solve(root->left);
        int rightside=solve(root->right);
        
        //if left part has 0 number of ones then make it as null
        if(leftside==0)
            root->left=NULL;
        //if right part has 0 number of ones then make it as null
        if(rightside==0)
            root->right=NULL;
        //check value of root node
        int value=0;
        if(root->val==1)
            value=1;
        //return all the number of ones collected from left right and root value
        return leftside + rightside + value;
    }
    TreeNode* pruneTree(TreeNode* root) {
        
        //Approach
        //we will only count only number of ones 
        //if number of ones in left side is 0 then make left part it as null
        //if number of ones in right side is 0 then make right part it as null
        //otheriwse return count of ones from left side + right side + root ka value
        if(solve(root)==0)//if all has only 0 then return NULL
            return NULL;
        return root;
        
    }