    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        
        //Steps:
        //Make pair of efficiency and speed and sort according to efficiency in dec order
        //calculate the sum and push speed into min heap
        //find the max performance and if size of heap greater than k then pop 
        //from sum subtract the poped speed 
        vector<pair<int,int>> v;
        for(int i=0; i<speed.size(); i++)
        {
            v.push_back({efficiency[i], speed[i]});
        }
        
        //Min heap
        priority_queue<int, vector<int>, greater<int>> q;
        long result=0;
        long sum=0;
        sort(v.begin(), v.end());
        for(int i=n-1; i>=0; i--)
        {
            sum+=v[i].second;
            q.push(v[i].second);
            if(q.size()>k)
            {
                sum-=q.top();
                q.pop();
            }
            if((sum*(v[i].first))>result)
                result=sum*(v[i].first);
        }
        return result%1000000007;
        
    }