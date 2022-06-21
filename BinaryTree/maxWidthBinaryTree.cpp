    int max(int a,int b)
    {
        if(a>b)
            return a;
        else
            return b;
    }
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;
        
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        int ans=0;
        while(!q.empty())
        {
            int s=q.size();
            //take out both start and end index
            long start=q.front().second;
            long end=q.back().second;
            ans=max(ans,(end-start+1));
            for(int i=0; i<s; i++)
            {
                //assign the indexes
                pair<TreeNode*,int> p=q.front();
                q.pop();
                TreeNode* curr=p.first;
                long index=p.second;
                if(curr->left!=NULL)
                    q.push({curr->left,2*index+1});
                if(curr->right!=NULL)
                    q.push({curr->right,2*index+2});
            }
        }
       return ans; 
    } 