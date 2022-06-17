   void solve(TreeNode* root, vector<vector<int>> &ans, vector<int> op)
    {
        queue<TreeNode*>q;
        q.push(root);
        //For sepearting each level we have to insert NULL
        q.push(NULL);
        
        while(!q.empty())
        {
            TreeNode* temp=q.front();
            q.pop();
            
            //NULL found means it is level has been completed
            if(temp==NULL)
            {
                //Pushing the level at ans vector
                ans.push_back(op);
                //Emptying the vector
                op.clear();
                //Check if elements are present in queue which will be thier child so push one sepeartor to it
                if(!q.empty())
                    q.push(NULL);
            }
            else
            {
                //Pushing the current node data to output vector and make left , right recursive calls
                op.push_back(temp->val);
                if(temp->left!=NULL)
                    q.push(temp->left);
                if(temp->right!=NULL)
                    q.push(temp->right);
                
            }
        }
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        vector<int> op;
       solve(root,ans,op);
       //Use this for reverse level order traversal 
        //reverse(ans.begin(), ans.end());
        return ans;
        
    }