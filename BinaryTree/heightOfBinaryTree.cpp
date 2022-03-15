class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        
        
        //base case
        if(node==NULL)
            return 0;
        
        int left=height(node->left); //kewal left side wala me jyada node ho
        int right=height(node->right);//kewal right side wale me jyada nodes ho
        int result=max(left,right)+1;//1 add kar rhe ush root node ko consider ka rhe hai
      
        return result;
        /*
        //return (node!=NULL)?(max(height(node->left),height(node->right))+1):0;
        
        
        //direct use ternatory operator c?T:f  condition true hga toh T hga warna f
        return node?(max(height(node->left),height(node->right))+1):0;
        */
    }
};