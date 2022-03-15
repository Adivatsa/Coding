class Solution {

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
    pair<int,int> diameterHeight(Node* root)
    
    {
        //In this pair means <Diameter, Height>
        
        //Base case 
        if(root==NULL)
        {
            pair<int,int> p=make_pair(0,0);
            return p;
        }
        
            //pair waise me diamter aur height nekal ke le aaao
            pair<int,int> left=diameterHeight(root->left);
            pair<int,int> right=diameterHeight(root->right);
            
            //diamter agr kewal left subtree hai
            int leftDiameter=left.first;
            //agr kewal right subtree hai toh
            int rightDiameter=right.first;
            //agr mix hai toh heights(left+right) ko nekl ke 1 add kar do 
            int mix=left.second+right.second+1;
            
            //ans banna lo jaha first me diamter and second me height
            pair<int, int> ans;
            ans.first=max(leftDiameter,max(rightDiameter,mix));
            ans.second=max(left.second,right.second)+1;
            return ans;
            
    
    }
    
  public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        
        //Methode 1
        /* Time complexity =O(n^2) as inside diamter we are finding height
        //Base case
        if(root==NULL)
            return 0;
        
        //recursive call to only having left subtree
        int left=diameter(root->left);
        //recursive call to only have right subtree
        int right=diameter(root->left);
        //agr tree has left and right subtree both height nekal ke add kar do wo longest path hga 
        int mix= height(root->left)+ height(root->right)+1;
        
        int result=max(left, max(right,mix));
        return result;
        */
        
        //Methode 2
        //To reduce the complexity we can use pair where first will calculte diameter
        //and scond will calculate height so TC=O(n)
        
        pair<int,int> p=diameterHeight(root);
        
        return p.first;
        
        
    }
};