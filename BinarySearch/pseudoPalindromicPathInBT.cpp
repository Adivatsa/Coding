    void solve(TreeNode* root, int &count,unordered_map<int,int> &m)
    {
        if(root==NULL)
            return;
        int value=root->val;
        m[root->val]++;
        //whem leaf node just check for odd nodes if 1 or 0 then increase count
        if(root->left==NULL && root->right==NULL)
        {
            int s=0;

            for(auto it:m)
            {
                if(it.second%2==1)
                    s++;
                
            }
            if(s<=1)
                    count++;
        }
        if(root->left!=NULL)
            solve(root->left,count,m);
        if(root->right!=NULL)
            solve(root->right,count,m);
        //backtracking
        m[root->val]--;
        
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        
        if(root==NULL)
            return 0;
        
        int count=0;
        vector<int> t(10,0);
        unordered_map<int,int> m;
        solve(root,count,m);
        return count;
        
    }


        void solve(TreeNode* root, int &count,vector<int> &t)
    {
        if(root==NULL)
            return;
        int value=root->val;
        t[value]++;

        //when leaf node just check for odd nodes if 1 or 0 then increase count
        if(root->left==NULL && root->right==NULL)
        {
            int s=0;

            for(auto it:t)
            {
                //Checking for nodes with odd cumber of occurrences
                if(it%2==1)
                    s++; 
            }
            if(s<=1)
                    count++;
        }
        if(root->left!=NULL)
            solve(root->left,count,t);
        if(root->right!=NULL)
            solve(root->right,count,t);
        //backtracking
        t[value]--;
        
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        
        //Approach
        //in this approach we have to take path from root to leaf and store count in vector
        //just check for 1 to 9 in vector if more than one found odd then do not inc count
        //At last return the count
        if(root==NULL)
            return 0;
        
        int count=0;
        vector<int> t(10,0);

        solve(root,count,t);
        return count;
        
    }