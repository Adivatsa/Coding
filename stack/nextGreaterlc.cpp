    
    //leetcode format written in notebook
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        
        stack<int> s; //nearest greater ko store maarenge
        vector<int> v;//num1 ke aage sabko push maar dnge map se compare karke
        unordered_map<int, int> m;//key value num2 ka store kar lo phir last me match kareke 
                                  //num1 ke liye vector me push maar dena
        
        //store next grater to right for num2 array and for nums1 array just copy it from map with same elment
        for(int i=nums2.size()-1; i>=0; i--)
        {
            
            if(s.empty())
            {
                m[nums2[i]]=-1;
            }
            else if(s.size()>0 && nums2[i]<s.top())
            {
                m[nums2[i]]=s.top();
            }
            else if(s.size()>0 && nums2[i]>=s.top())
            {
                while(s.size()>0 && nums2[i]>=s.top())
                    s.pop();
                if(s.empty())
                    m[nums2[i]]=-1;
                else
                    m[nums2[i]]=s.top();
            }
            s.push(nums2[i]);
        }
        
        for(int i=0; i<nums1.size(); i++)
        {
            v.push_back(m[nums1[i]]);
        }
        return v;
        

    }

    //leetcode

        vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        
        stack<int> s; //nearest greater ko store maarenge
        vector<int> v;//num1 ke aage sabko push maar dnge map se compare karke
        unordered_map<int, int> m;//key value num2 ka store kar lo phir last me match kareke 
                                  //num1 ke liye vector me push maar dena
        for(int i=nums2.size()-1; i>=0; i--)
        {
            
            while((!s.empty()) && (s.top()<nums2[i]))
                s.pop();
            //chek kar lo agr empty hai toh -1 daal do map value pair me
            if(s.empty())
            {
                m[nums2[i]]=-1;
            }
            else //iska mtlb ki stack ka top bada hai element se toh top daal do
                m[nums2[i]]=s.top();
            
            //last me wo elemet ko stack me push maar do direct
            
            s.push(nums2[i]);
        }
        
        for(int i=0; i<nums1.size(); i++)
        {
            v.push_back(m[nums1[i]]);
        }
        return v;
        

    }

