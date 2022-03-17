class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        //ish question ko hum level wise traverse karenge
        //sabhi nodes ke liye horizontal distance from root calculate karenge
        //root ka horizontal distance(hd) 0 he hga
        //left side me - hga and right side me distance + hga
        //ek map banayenge jha hum sabse phle hd hga and second ek map hga jisme har level hga jiska value 
        //dhushra ek vector hga jo ki store karega ush level ke saare nodes
        //Level order traversal hai toh ek queue hga 
        //queue me hum log pair store karenge jisme 1st hga node ko store karenge jisse uske left aur right child ko push maarenge
        //second pair hga jaha hum hd and level ko push karenge which will be used to tack the vector in map 
        //sorting order of hd ke hum vector ko print kara denge
        
        //map bana lo jisme first hd hga and second map hga jo level ke value hnge vector hold karega sabhi nodes
        map< int, map< int, vector<int> > > m;
        //queue banna lo jaha pe pair hga jisme first node ko store karega and second wala 
        //pair hga jo hd aur level store karega
        queue< pair< Node* , pair< int, int> > > q;
        
        //vector banna lo ans return karne ke liye
        vector<int> ans;
        
        if(root==NULL)
            return ans;
        //root node ko push kiye with hd=0 and level =0;
        q.push(make_pair(root, make_pair(0,0)));
        
        while(!q.empty())
        {
            //front elelment nekal lo 
            pair< Node* , pair< int, int> > p= q.front();
            q.pop();
            
            //Node nekal lo
            Node* curr= p.first;
            //hd nekal lo
            int hd=p.second.first;
            //level nekal lo
            int level= p.second.second;
            
            //map me nodes ke data ko push kar do with hd and level
            m[hd][level].push_back(curr->data);
            
            //check kar lo left child 
            if(curr->left!=NULL)
             {
                //yaha pe child ko push karna hai lekin left me hd -1 hga , level increase hga +1
                q.push(make_pair(curr->left, make_pair(hd-1,level+1)));
              }
            if(curr->right!=NULL)
             {
                //yaha pe child ko push karna hai lekin right me hd +1 hga , level increase hga +1
                q.push(make_pair(curr->right, make_pair(hd+1,level+1)));
              }
            
        }
        
        //yaha pe humme map me jo nodes store hua hai vector me ushe ans vector me daal denge
        //first loop map ke aage wale ko jaayega
        for(auto i: m)
        {
            //yaha pe second me jao
            for(auto j:i.second )
            {
                //second ke second me ja ke copy maar do
                for(auto k: j.second)
                    ans.push_back(k);
                
            }
        }
        return ans;
    }
};