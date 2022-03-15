class Solution{
    
    private:
    
    /*
    int height(Node* root)
    {
        if(root==NULL)
            return 0;
        
        int left=height(root->left);
        int right=height(root->right);
        int result=max(left,right)+1;
        
        return result;
    }
    */
    pair<int,int> balancedHeight(Node* root)
    
    {
        //In this pair means <balance hai ya nai wo node, Height>
        
        //Base case 
        if(root==NULL)
        {
            pair<bool,int> p=make_pair(true,0);
            return p;
        }
        
            //left aur right wala check karo balance hai ya nai
            pair<bool,int> leftside=balancedHeight(root->left);
            pair<bool,int> rightside=balancedHeight(root->right);
            //ush node ko check karo jiske right and left node hai
            bool temp=abs(leftside.second-rightside.second)<=1;
            
            
            pair<bool, int> ans;
            ans.second=max(leftside.second ,rightside.second)+1;
            if(leftside.first && rightside.first && temp)
            {
                ans.first=1;
                
            }
                
            else
                ans.first=0;
            return ans;
    }
    
    
    public:
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        /*
        //Methode 1
        //Time complexity =O(n^2) as inside diamter we are finding height
        //Base case
        if(root==NULL)
            return 1;
        
        //recursive call to only having left subtree balance hai ya nai
        bool leftside=isBalanced(root->left);
        //recursive call to only have right subtree ko balance karne ke liye
        bool rightside=isBalanced(root->right);
        //wo node ko check karne ke liye left and right subtree both height nekal ke subtract kar lo agr equal less than 1 hga toh true
        bool temp= abs( height(root->left)- height(root->right)) <= 1;
        
        if(leftside && rightside && temp)//teeno ka true check kar lena left side , right side wo wala node bhi
            return 1;
        else
            return 0;
        */
        
        //Methode 2
        //To reduce the complexity we can use pair where first will calculte is balance or not
        //and scond will calculate height so TC=O(n)
        
        pair<bool,int> p=balancedHeight(root);
        
        return p.first;
    }
};