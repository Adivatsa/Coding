class Solution
{
    public:
    
    void inorder(Node* root, Node* &prev, bool &flag)
    {
        //check for null condition
        if(root==NULL)
            return;
        
        //step1: Inorder me LNR
        inorder(root->left,prev,flag);
        
        //Step2: Here check root ka data if greater than prev or not if not then make flag as false
        //whenever it is first element then prev will be NULL then don't check
        if((prev!=NULL) && (prev->data >= root->data))
        {
            flag=false;
            return;
        }
        //matlb prev chota hai root se so aage ke liye check karo so prev ko aage le aao
        prev=root;
        
        inorder(root->right, prev,flag);
        
    }
    /*
    bool checkBST(Node* root, int min, int max)
    {
        //Check for root if null return as true
        if(root==NULL)
            return true;
        //get the root data
        int ele=root->data;
        //this codition checks that root data is lies between min and max value
        if(ele>min && ele<max)//if it lies then perform these operation
        {
            //now check for root ke data left subtree and right subtree
            //Now for left subtree min can be upper min value but not max then root data
            bool leftside=checkBST(root->left,min,ele);
            //Now for right subtree max can be upper max value but not min then root data
            bool rightside=checkBST(root->right,ele,max);
            
            //check if both leftside and rightside return true then return true to above
            return leftside && rightside;
        }
        else//this means it not lies then BST proprty failed
            return false;//return false to it
    }
    
    */
    
    //Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) 
    {
        /*
        //Method1: this method works like value range 
        //consider that root will always lie between -infinity to +infinity
        //if we go to left side that it can minimum to -infinity but max value not more than root->data
        //same if we go to right side its min value should be root->data and max value can be infinity
        //this approch is applies to every node 
        return checkBST(root,INT_MIN,INT_MAX);
        */
        
        //Method2: this method is based upon inorder traversal
        //ish me hum inorder ki tarah traverse karenge bs pichle wla node ko check kar lenge
        //agr pichla wala bada hga toh false kar denge
        
        bool flag=true;//ye wala false ho jaayega jaise he koi chota mil jaayega prev se
        Node* prev=NULL; //previous node ka track rakhega
        inorder(root,prev,flag);
        return flag;
        
        /*
        //Method 3: Here simply just find inorder of that binary tree
        //then check for if it is increasing order or not
        //Only leetcode it will submit
        void inorder(TreeNode * root, vector<int> &v)
        {
            if(root==NULL)
            return;
    
            inorder(root->left, v);
            v.push_back(root->val);
            inorder(root->right,v);
        }
        bool isValidBST(TreeNode* root) {
            
        vector<int> ans;
        if(root==NULL)
            return true;
        inorder(root, ans);
        
        for(int i=1; i<ans.size(); i++)
        {
            if(ans[i-1] >= ans[i])
              return false;  
        }
        return true;
        }
        */
};