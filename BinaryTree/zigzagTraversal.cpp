    void solve(TreeNode* root, vector<vector<int>> &ans, vector<int> op)
    {
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        bool valid=true;//his is for once towards LR and then once RL
        
        while(!q.empty())
        {
            TreeNode* temp=q.front();
            q.pop();
            
            if(temp==NULL)
            {
                //check if fasle then reverse and input after that clear the vector
                if(valid==false)
                    reverse(op.begin(), op.end());
                ans.push_back(op);
                op.clear();
                if(!q.empty())
                {
                    q.push(NULL);
                    valid=!valid;//once cycle completed just reverse it
                }
                    
            }
            else
            {
                op.push_back(temp->val);
                if(temp->left!=NULL)
                    q.push(temp->left);
                if(temp->right!=NULL)
                    q.push(temp->right);
            }
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        vector<int> op;
        solve(root,ans,op);
        return ans;
        
    }