    vector<int> topKFrequent(vector<int>& nums, int k) {
        //frequency means map
        //k and top means min heap
        
        //map me daal do key value pair with value as count
        //heap me count,elememt daal lo min heap 
        //last me bache hue elements ko array me daal do
        
        unordered_map<int,int> m;
        
        for(int i=0; i<nums.size(); i++)
        {
                m[nums[i]]++;
        }
        
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>>q;
        
        for(auto i=m.begin(); i!=m.end(); i++)
        {
            
            q.push({i->second, i->first});
            if(q.size()>k)
            {
                q.pop();
            }
        }
        vector<int>ans;
        while(!q.empty())
        {
           ans.push_back(q.top().second);
            q.pop();
        }
        return ans;
        
    }