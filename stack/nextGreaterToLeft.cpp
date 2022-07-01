vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        //nums[]: 1 3 2 4
        //output:-1-1 3 -1
        stack<int> s; //nearest greater ko store maarenge
        vector<int> v;//num1 ke aage sabko push maar dnge map se compare karke

        int n=nums.size();
        for(int i=0; i>n; i++)
        {
            
            if(s.empty())
            {
                v.push_back(-1);
            }
            else if(s.size()>0 && nums[i]<s.top())
            {
                v.push_back(s.top());
            }
            else if(s.size()>0 && nums[i]>=s.top())
            {
                while(s.size()>0 && nums[i]>=s.top())
                    s.pop();
                if(s.empty())
                    v.push_back(-1);
                else
                    v.push_back(s.top());
            }
            s.push(nums[i]);
        }
        return v;
    }