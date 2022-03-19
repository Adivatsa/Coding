void calculate(Node* root, map<int, vector<int> > &m, int hd)
{
    //root ko map ke vector me daal do
    //jab bhi left me jao hd distance ko increase kar do 1 se
    //jab bhi right me jao hd same rakhna in call recursive
    
    //Base case
    if(root==NULL)
        return;
    //Use find function when we use unordered map inside it
    m[hd].push_back(root->data);
    //Recursive call
    if(root->left!=NULL)
        calculate(root->left,m,hd+1);
    if(root->right!=NULL)
        calculate(root->right,m,hd);
}
vector<int> diagonal(Node *root)
{
    /*
    //method 1:
    
    //in this method push the left of nay node ko queue 
    //push root node to q and check if curr jab tk null na ho
    //if left child exits then push into queue and right child ans into vector
    //agr go in right side when curr = null then pop from queue and process them 
    //last return the vector
    queue<Node*> q;
    vector<int> ans;
       
    if(root==NULL)
        return ans;
        
    q.push(root);
    while(!q.empty())
    {
        Node* curr=q.front();
        q.pop();
        while(curr!=NULL)
        {
            ans.push_back(curr->data);
            //left walo ko queue push kar do
            if(curr->left!=NULL)
                q.push(curr->left);
           
            
            curr=curr->right;
        }
    }
    return ans;
    */
    
    //Method 2: Using maps
    //in this map will store of hd and vector for storing all nodes with same hd
    map<int, vector<int> > m;
    vector<int> ans;
    
    calculate(root,m,0);
    for(auto i: m)
    {
        for(auto j:i.second)
            ans.push_back(j);
    }
    return ans;
}