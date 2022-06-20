void sol(TreeNode* A, int B, vector<int> &ans)
 {
     if(A==NULL)
        return;
    //if node has been found then insert and return
    if(A->val==B)
    {
        ans.push_back(A->val);
        return;
    }
    //insert the node and make left and right call
    //Ensure onr thing that while coming back from recursive call if vector contain ans just return otherwise
    //go to right call
    //then not found simply pop back
    ans.push_back(A->val);
    if(A->left!=NULL)
        sol(A->left,B,ans);
    if(ans.back()==B) return;
    if(A->right!=NULL)
        sol(A->right,B,ans); 
    if(ans.back()==B) return; 
    ans.pop_back();  
    return; 
 }
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> ans;
    if(A==NULL)
    return ans;
    //call for finding path from root to node B
    sol(A,B,ans);
    return ans;
}

 void sol(TreeNode* A, int B, vector<int> &ans, vector<int>&op)
 {
     if(A==NULL)
        return;
    //if node has been found then insert all to ans vector and return
    
    //Another method just another vector to store only output path
    if(A->val==B)
    {
        op.push_back(A->val);
        for(auto it:op)
            ans.push_back(it);
        return;
    }
    //insert the node and make left and right call
    //then not found simply pop back
    op.push_back(A->val);
    if(A->left!=NULL)
        sol(A->left,B,ans,op);
    if(A->right!=NULL)
        sol(A->right,B,ans,op); 
    op.pop_back();  
    return; 
 }
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> ans;
    vector<int>op;
    if(A==NULL)
    return ans;
    //call for finding path from root to node B
    sol(A,B,ans,op);
    return ans;
}