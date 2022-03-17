 void rightviewFunction(Node* root, vector<int> &ans, int level)
    {
        //Base case
        if(root==NULL)
            return ;
        
        //yaha pe check kar lo ush level ka first element hai kya woh
        //vector ke size se pata chalega kis level ke pe hai
        if(level==ans.size())//iska matlb new level pe aagye hai aur first element hai
            ans.push_back(root->data);//push kar iske data ko
            
        //phle right side chale jao kyuki right view lena hai
        rightviewFunction(root->right, ans, level+1);
        
        //left side chale jao 
        rightviewFunction(root->left, ans, level+1);
        
    }

    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
        // har ek level ke first element ko print karna hai whi humara right view hga
        //level by level ayenge but right side se
        vector<int>ans;
        rightviewFunction(root,ans, 0);//start me level 0 he hga
        return ans;
    }