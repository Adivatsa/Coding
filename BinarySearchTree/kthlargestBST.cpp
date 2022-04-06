class Solution
{
    public:
    void kthLarge(Node* root, int &i, int k, int &ans)
    {
        if(root==NULL)
            return;
        //Step 1:Go to right part
        kthLarge(root->right,i,k,ans);
        //Step2: increment and check
        i++;
        if(i==k)
        {
            ans=root->data;
            return;
        }
        //Step3: Go to left part
        kthLarge(root->left,i,k,ans);
    }
    
    int kthLargest(Node *root, int K)
    {
        //Traverse inorder in reverse direction  instead of LNR use RNL
        //then will be decreasing order 
        //check i==k then return it
        int i=0;
        int ans=-1;
        kthLarge(root,i,K,ans);
        return ans;
        
    }
};