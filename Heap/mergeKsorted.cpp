class Solution
{
    public:
    class node 
    {
        public:
        int val, row, col;
        node(int value, int i, int j)
        {
            val=value;
            row=i;
            col=j;
        }
    };
    struct comp
    {
        bool operator()(node a ,node b)
        {
            return a.val>b.val;
        }
    };
    
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //min heap creation 
        vector<int> ans;
        //defining comparator for min heap
        priority_queue<node ,vector<node>, comp> m;
        //push all rows 1st elememt to min heap
        for(int i=0; i<K; i++)
        {
            m.push(node(arr[i][0],i,0));
        }
        //take out the top element and find out its column value and increase and insert into heap
        while(!m.empty())
        {
            node p=m.top();
            m.pop();
            int data=p.val;
            int r=p.row;
            int c=p.col;
            
            ans.push_back(data);
            
            if(c+1<K)
                m.push(node(arr[r][c+1], r, c+1));
        }
        return ans;
        
    }
};