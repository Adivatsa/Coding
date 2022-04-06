void predesassor(Node* root, Node*& pre, Node*& suc, int k)
{
   if(root==NULL)
        return;
    //predecessor means key se sabse phla chota 
    Node* curr=root;
    while(curr!=NULL)
    {
        //ushe chota mil gya
        if(curr->key < k)
        {
            //jo chota mila yeh bhi predecessor ho skta hai toh store kara lo 
            //aur isse badha and key se chota khojo isliye ab curr se right me jao
            pre=curr;
            curr=curr->right;
        }
        else//chota wala element nai mila hai so chota milega left side me
            curr=curr->left;
    }
}

void succesassor(Node* root, Node*& pre, Node*& suc, int k)
{
    if(root==NULL)
        return;
    
    //Successor matlb key node se just bada wala element la ke do
    //check kar lo agr curr ka data key se jyada hai matlb whi successor ho sakta hai
    //isliye store kara lo ushe aur chota possible ho but key se bada le aao so left jao
    //warna bada nai mila toh aur right jao badda milega key se 
    Node* curr=root;
    while(curr!=NULL)
    {
        if(curr->key > k)
        {
            suc=curr;
            curr=curr->left;
        }
        else
            curr=curr->right;
    }
}
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    
    //Predecessor matlb ushe just chota wala
    //Successor means usse just bada wala 
    
    predesassor(root,pre,suc,key);
    succesassor(root,pre,suc,key);
}