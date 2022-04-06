class Solution{
  public:
  
    void inorder(struct Node* root, vector<int> &v)
    {
        if(root==NULL)
            return;
        
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }
    // root : the root Node of the given BST
    // target : the target sum
    int isPairPresent(struct Node *root, int target)
    {
        //Yaha pe two pair ka sum agr target ke equal hai toh 1 return kara do warna 0
        //first step inorder nekal lo 
        //second step two pointer approach se check kar lo sum agr mil jaay toh 1 return
        //agr sum badda ho toh right ko kam kar do aur chota ho toh left ko badda do
        
        //STep1: find the inorder 
        vector<int> v;
        inorder(root,v);
        
        //Step 2: Use two pointer approach to find sum
        int i=0;
        int j=v.size()-1;
        while(i<j)
        {
            if(v[i] + v[j]==target)//sum mil gya 
                return 1;
            else if(v[i] + v[j] > target)//sum jyada aa gya kam karo 
                j--;
            else//sum kam aa gya thora jyada karo
                i++;
        }//koi aisa sum nai mil paaya hai
        return 0;
    }
};
