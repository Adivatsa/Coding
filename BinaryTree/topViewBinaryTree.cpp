class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //agr hum tree to top se dekhe toh har node jo first time aayega wo dikhega
        //hum log yaha map ka use karenge with key has horizontal distance and value as node ka data
        //queue will store node and also the hd 
        vector<int> ans;
        if(root==NULL)
            return ans;
        
        //ek map banna lo 
        map< int, int> m;
        //queue banna lo jaha node aur hd push karenge
        queue< pair <Node*, int> > q;
        
        //root ko push maar do queue me with hd=0
        q.push(make_pair(root, 0));
        
        while(!q.empty())
        {
            //sabse phle front node nekal lo aur hd bhi
            pair<Node*, int> p=q.front();
            q.pop();
            
            Node* curr=p.first;
            int hd= p.second;
            
            //dekh lo ye first time hd aaya hai tbhi value change hga warna nai karenge
            if(m.find(hd)==m.end()) //matlb ye hd first time aaya hai 
                m[hd]=curr->data;
                
            //uska left side wale child node check kr lo with hd= hd-1
            if(curr->left!=NULL)
                q.push(make_pair(curr->left, hd-1));
            
            //right child ke liye check kar lo with hd =hd+1;
            if(curr->right!=NULL)
                q.push(make_pair(curr->right, hd+1));
            
        }
        
        //jo bhi value map me m[hd]=node ka data hga usko apne vector me daal do
        for(auto i: m)
        {
            
                ans.push_back(i.second);
        }
        return ans;
    }

};