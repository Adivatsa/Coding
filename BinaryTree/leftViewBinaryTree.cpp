void leftviewFunction(Node* root, vector<int> &ans, int level)
{
    //Base case
    if(root==NULL)
        return ;
    
    //yaha pe check kar lo ush level ka first element hai kya woh
    //vector ke size se pata chalega kis level ke pe hai
    if(level==ans.size())//iska matlb new level pe aagye hai aur first element hai
        ans.push_back(root->data);//push kar iske data ko
        
    //left side chale jao 
    leftviewFunction(root->left, ans, level+1);
    //right side chale jao
    leftviewFunction(root->right, ans, level+1);
}
vector<int> leftView(Node *root)
{
   // har ek level ke first element ko print karna hai whi humara left view hga
   vector<int>ans;
   leftviewFunction(root,ans, 0);//start me level 0 he hga
   return ans;
}