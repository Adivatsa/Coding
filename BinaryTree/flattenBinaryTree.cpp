class Solution
{
    public:
    void flatten(Node *root)
    {
        //Method 1: just traverse and create node of LL TC=O(n) SC=in-place not followed(same specified u have to use )
        //Method 2: Using recursion TC=O(n) SC=O(n)
        //Method 3: Using Morris traversal
        
        //root node ko curr ke equal akr lo
        //jab tk curr null na ho jaaaye tb tk
        //check kr curr ka left null nai hona chahiye
        //predessasor nekal lo matlb ek baar left then right me jaate raho jab tk null na ho jaaye
        //predessasor ko curr ke right se point kara do
        //curr ke right ko left me point kara do
        //question me dia hai curr ke left ko null kar do
        Node* curr=root;
        
        while(curr!=NULL)
        {
            if(curr->left!=NULL)
            {
                Node* pred=curr->left;
                while(pred->right!=NULL)
                    pred=pred->right;
                
                pred->right=curr->right;
                curr->right=curr->left;
                curr->left=NULL;
            }
            curr=curr->right;
        }
    }
};