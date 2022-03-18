//METHOD 1:


int calculatekth(Node* root, int k, int node, vector<int> path)
{
    if(root==NULL)//agr root null hga toh -1 ko return kara do
        return  -1;
    
    path.push_back(root->data);//root node ke data ko vector me push maar do 
    
    if(root->data==node)//check kr lo ki root ke data agr node ke equal hai kya
    {//agar hai toh
        int size=path.size();//vector ka size nekal lo
        if(size>k)//check kar lo size kya kth ancestor neklna hai usse bada h ya nai
        {
            int ans=path[size-1-k];//badha hai size toh vector me se last k element uska kth acestor hga
            return ans;//ans return kara do
        }
        else
        {
            return -1;//warna koi aur bhi elemnt node hga isse hum kth ancestor nai nekal sakte
        }
            
            
    }
    
    int leftside=calculatekth(root->left, k,node,path);//left ka value le aao
    int rightside=calculatekth(root->right, k,node,path);//right ka value le aao
    
    if(leftside!=-1 && rightside==-1)//agr -1 nai toh humme data return kara do
        return leftside;
    else if(leftside==-1 && rightside!=-1)
        return rightside;
    else if(leftside==-1 && rightside==-1 )//agr dono side se -1 aya toh -1 mtlb nai mila
        return -1;

}
int kthAncestor(Node *root, int k, int node)
{

    //iska main idea yeh hai ki yaha pe hum path ko store karenge vector me 
    //phir traverse karke agr node hai toh uska ans ulta side se k ke value se nekal lnge
    //usko print kara do
    //ek vector banna do path store karne ke liye
    vector<int> path;
    return calculatekth(root,k,node,path);;    
}


//METHOD 2:

Node* calculateK(Node* root, int &k, int node)//decrement karte time k ka vlue reflct ho
{
    //Base case
    if(root==NULL)
        return NULL;
    
    if(root->data==node)//agr mil gya hai value toh ush node ko return kar do
        return root;
    
    //left se khoj ke le aao
    Node* leftside=calculateK(root->left,k,node);
    //right se khoj ke le aao
    Node* rightside=calculateK(root->right,k,node);
    
    //wapas jaane ke time ka operation hai sab
    //check kar lo agr left se jo node aaya not null and right se aaay woh null hai then 
    //k ko decrement karna hai aur check kar lo agr k ==0 hai toh root ko bhej do warna left node ko upar with decrement
    if(leftside!=NULL && rightside==NULL)
    {
        k--;
        if(k==0)//matlb yhi wala node hai
        {
            k=INT_MAX;//k ko aisa value daal do wo kabhi 0 na ho paaye
            return root;
        }
        return leftside;
    }
    else if(leftside==NULL && rightside!=NULL)
    {
        k--;
        if(k==0)//matlb yhi wala node hai
        {
            k=INT_MAX;//k ko aisa value daal do wo kabhi 0 na ho paaye
            return root;
        }
        return rightside;
    }
        return NULL;//dono side se null aya hga tb
}

int kthAncestor(Node *root, int k, int node)
{
    //Method 2::::::
    //isf method me left me ya right me node ko search karenge
    //agr wo koi bhi root->data ke equal ho jaaye tb 
    //upar bhej do ans with decrement of k--
    //jaise he k==0 ho jaaye toh ush root node ke data ko return kara do
    //agr dono side se NULL aye toh upar bhi null bhej do
    //ek edge kaise yaad rakhna k=1 to 100 so root node of tree nai hona chahiye
    
    Node* ans=calculateK(root,k,node);
    if(ans==NULL || ans->data==node)
        return -1;
    else
        return ans->data;
}
