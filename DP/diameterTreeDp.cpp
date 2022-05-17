//TC=O(n)
    
    int solve(TreeNode* root, int &res)
    {

        //for finding the diamter we require height of tree 
        //Base condition
        //if root is null then daimter will be 0
        if(root==NULL)
            return 0;
        
        //we have find out the hypothesis which will be calculate for right and left side
        int l=solve(root->left,res);
        int r=solve(root->right,res);
        
        //we will formulate the ans
        //it might be possible that calculated node will not be ans then it will pass max height
        int temp=1+max(l,r);//that node is also added in height max
        
        //it might be possible that this is the diamter of tree
  
        
        res=max(res,1+r+l);
        
        //return max height 
        return temp;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        //We will use Dp approach as many times we have calculate the height to find the diameter of tree
        
        int res=INT_MIN;
        solve(root,res);
        return res-1;//asking for edges as we calculated for nodes
        
    }