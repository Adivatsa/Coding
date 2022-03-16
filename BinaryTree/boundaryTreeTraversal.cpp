class Solution {
public:
    void leftside(Node* root, vector<int> &ans) //reference maara hai ans me he store direct kar rha hu
    {
        //base case(NULL hai ya leaf node hai toh wapas aa jao)
        if(root==NULL)
            return;
            //yeh leaf node ke liye
        if(root->left==NULL && root->right==NULL)
            return;
        
        //print kara do phir left me chale jao
        ans.push_back(root->data);
        
        //check kar lo agr left null hai tb right side jaana boundary bannane
        if(root->left!=NULL)
            leftside(root->left,ans);
        else//matlb left side kuch bhi nai hai toh right ko le kr boundary banna lo
            leftside(root->right,ans);
            
    }
    
    void leafnode(Node* root, vector<int> &ans)
    {
        if(root==NULL)
            return;
        
        //agr leaf node hai toh print kara do
        if(root->left==NULL && root->right==NULL)
        {
            ans.push_back(root->data);
            return;
        }
        
        //left side jao 
        leafnode(root->left, ans);
        leafnode(root->right, ans);
    }
    
    void rightside(Node* root, vector<int> &ans)
    {
       if(root==NULL)
            return;
        
        //agr leaf node hai toh return ho jao kara do
        if(root->left==NULL && root->right==NULL)
        {
            return;
        } 
        
        //reverse me print karana hai toh phle call maaro return time print kara dena
        //check kar lo agr right null hai tb left side jaana boundary bannane
        if(root->right!=NULL)
            rightside(root->right,ans);
        else//matlb right side kuch bhi nai hai toh left ko le kr boundary banna lo
            rightside(root->left,ans);
        
        //print kara de
        ans.push_back(root->data);
    }
    vector <int> boundary(Node *root)
    {
        //sabse phle root ko print kara do uske baad
        //main idea yeh ki phle left subtree excluding leaf node print kara do
        //Sabhi leaf node ko print kara do
        //uske baad right subtree ko ulta print kara do (ulta mtlb return hote time print karna hai dost)
        
        vector<int> ans;
        //Base case
        if(root==NULL)
            return ans;
            
        //root ko print kara dena hai
        ans.push_back(root->data);
        
        //left subtree excluding leaf node print kara do
        leftside(root->left, ans); 
        
        //ab humme saare leaf node ko print kara do
        //left subtree ke leaf node ko print karayega
        leafnode(root->left,ans);
        
        //right subtree ke leaf node ko print karayega
        leafnode(root->right, ans);
        
        //right side ko print kara do boundary ko but reverse me aana hai
        rightside(root->right,ans);
        
        
        //return kara do vector ko
        return ans;
        
    }
};