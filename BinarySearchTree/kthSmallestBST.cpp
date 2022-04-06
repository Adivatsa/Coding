class Solution {
  public:
  //i as a reference rahega uska track karna hai humme
  void Kthelement(Node* root, int &i, int k, int &result)
  {
        //Base case
        //in question given agar koi nai hga toh -1 return kar dena hai
        if(root==NULL)
            return;
        
        //Left side in inorder traversal
        Kthelement(root->left,i,k,result);
        
        //INorder me bich wala node jaha print karte hai
        i++;
        if(i==k)
        {
            result=root->data;
            return;
        }
            
        
        //rightside in inorder
        Kthelement(root->right,i,k,result);
  }
    // Return the Kth smallest element in the given BST
    int KthSmallestElement(Node *root, int K) {
        
        //Method1: Here main logic yeh hai ki inorder me traverse karte jaayenge LNR
        //jab jab inorder me node ko print karte the waha pe bs i ko increment kara lenge
        //Phir check kar lenge ki i==k aa gya kya, agr haa to ush node ke data ko return kara do
        
        int i=0;
        int result=-1;
        Kthelement(root,i,K,result);
        return result;
    }
};