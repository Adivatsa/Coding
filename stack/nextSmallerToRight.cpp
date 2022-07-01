vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        //nums[]: 1 3 2 4
        //output: -1 2 -1 -1
        stack<int> s; //nearest smaller ko store maarenge
        vector<int> v;//

        
        for(int i=nums.size()-1; i>=0; i--)
        {
            
            if(s.empty())
            {
                v.push_back(-1);
            }
            else if(s.size()>0 && nums[i]>s.top())
            {
                v.push_back(s.top());
            }
            else if(s.size()>0 && nums[i]<=s.top())
            {
                while(s.size()>0 && nums[i]<=s.top())
                    s.pop();
                if(s.empty())
                    v.push_back(-1);
                else
                    v.push_back(s.top());
            }
            s.push(nums[i]);
        }
        
        reverse(v.begin(),v.end());
        return v;
    }