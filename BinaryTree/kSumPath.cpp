void checkSum(Node* root, int k, int &cnt, vector<int> &path)//cnt sabhi ka track store karega
    {
        //ek catch hai yaha reference pass karoge path tb pop back use warna no use
        if(root==NULL)
            return;
        
        //vector me node ka data ko push maar do
        path.push_back(root->data);
        
        //left subtree me jao 
        checkSum(root->left,k,cnt,path);
        //right subtrr me jao
        checkSum(root->right,k,cnt,path);
        
        //iska matlb ush tree ke ek node ke leaf tk ke sab path aa gye like 1 3 2
        //ab sum check kar lo phir pop maarke wapas ho jao
        //sum check kar lo
        int sum=0;
        int size=path.size();
        //reverse wy me check kar lo
        for(int i=size-1; i>=0; i-- )
        {
            sum=sum+path[i];
            if(sum==k)
                cnt++;//iska matlb ek k ke equal sum mil gya
        }
        
        //ja rhe ho pop kar lo vector se phir new path daal lena
        path.pop_back(); //phle 1 3 2 phir nrxt me 1 3 phir next 1 3 1
        
    }
    int sumK(Node *root,int k)
    {
        //iska approach yeh rahega ki ek vector bana lo jisme sab path store kara lo
        //phir check kar lo k ke equal hai ya nai 
        //agr equal hai toh count increase kar do
        //aur element ko pop kar do jaate time phir dhushra path insert karo
        
        int cnt=0;
        vector<int> path;
        checkSum(root,k,cnt,path);
        
        return cnt;
    }