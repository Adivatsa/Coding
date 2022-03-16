class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	//same code like level order traversal
    	//littlr modification to everse in every alternate step
    	
    	vector<int> ans;
    	if(root==NULL)
    	    return ans;
    	    
    	//ek queue banna lo jisme root daal lo
    	queue<Node*> q;
    	q.push(root);
    	bool sidha=true;
    	
    	while(!q.empty())
    	{
    	    //size nekal lo kitna item queue me hai phir usko reverse ya straight print karna hai
    	    int size=q.size();
    	    //Temperoaray vector banna lo ushi me sidha ya ulta store karenge har ek level
    	    vector<int>temp(size);
    	    
    	    for(int i=0; i<size ; i++)
    	    {
    	        //element ko process karo jo queue me hai 
    	        Node* curr=q.front();
    	        q.pop();
    	        
    	        //vector me ulta ya sidha daalna hai 
    	        int index= sidha?i:size-i-1;
    	        temp[index]=curr->data;
    	        
    	        //check kar lo agr left child uska hai ya nai , agr hai toh push maaro
    	        if(curr->left!=NULL)
    	            q.push(curr->left);
    	       
    	        //check kar lo agr right child uska hai ya nai , agr hai toh push maaro
    	        if(curr->right!=NULL)
    	            q.push(curr->right);
    	        
    	    }
    	    
    	    //ek baar sidha daal dia ab ulta aa jao
    	    sidha=!sidha;
    	    
    	    //temp vector se main vector me copy maar do
    	    for(auto i: temp)
    	        ans.push_back(i);
    	}
    	
    	return ans;
    	
    }
};