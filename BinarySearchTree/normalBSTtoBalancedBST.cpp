void inorder(Node*  root, vector<int> &v)
{
    if(root==NULL)
        return;
    
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}

Node* createBST(int s, int e, vector<int> &v)
{
    
    //Base Case(Jb start end se aage bhaag jaaye)
    if(s>e)
        return NULL;
    
    //find out the mid of inorder 
    int mid= s+ (e-s)/2;
    
    //create node of mid
    Node* root= new Node(v[mid]);
    
    //left call
    root->left=createBST(s,mid-1 ,v);
    
    //right call
    root->right=createBST(mid+1,e,v);
    
    return root;
}

Node* buildBalancedTree(Node* root)
{
	//Input me ek BST milega
	//Humme balance bst ka root return krna hai
	//we know that inorder of BST is sorted
	//we will make BST from inorder
	//mid nekal lenge wo humara root hga and s to mid-1 is left, mid+1 to end right
	
	//Step 1: Store the inorder
	vector<int> v;
	inorder(root,v);
	
	//Step2: Create BST from inorder with s=0, e=vector size-1 
	return createBST(0, v.size()-1, v);
}
