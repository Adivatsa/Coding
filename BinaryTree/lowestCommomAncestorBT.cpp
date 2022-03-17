class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       //Iska brute force yeh hga ki n1 se root ka path nekal phir n2 se root ka
       //dono ke path ko ulta reverse se traverse karo jo sabse phla same aayega whi hga
       //Isme 2 space use hga aur har ek node ko ek se jyada baar visit hnge
       
       //ish approach me main idea yeh hai ki agr left & right dono null to upar null bhejo
       //koi bhi ek not null hga toh uske value ko upar bhej do
       //ans wo node hga jha dono left and right not null hga
       
       //Base case
       if(root==NULL)//agr null hai root toh ans NULL bhej
            return NULL;
        
        //check kar lo wo element n1 ya n2 hai kya ...agr hai toh root ko bhej do(root me n1 ya n2 he hga jo milega)
        if(root->data==n1  || root->data==n2  )
            return root;
        
        //left se ans le ke aao
        Node* leftside=lca(root->left, n1, n2);
        //right se ans le ke aao
        Node* rightside=lca(root->right,n1,n2);
        
        //check kar lo left aur right se kya kya aaya hai 
        
        //agr dono side se not null aaya matlb whi node lca hga
        if(leftside!=NULL && rightside!=NULL)
        {
            return root;//LCA yhi hga janab
            
        }//agr left se jo ans aaya woh not null hai whi right se null aya toh not null wale ko upar bhejo tbhi toh check karega
        else if(leftside!=NULL && rightside==NULL)
        {
            return leftside;
        }
        else if(leftside==NULL && rightside!=NULL)
        {
            return rightside;
        }
        else//dono side null he aaya toh null bhejo upar
            return NULL;
    }
};