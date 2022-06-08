    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        //Method 1: Using For loop for finding the sum
        //TC=O(n^4)logn where logn for duplicay removal in set
        
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n=nums.size();
        set<vector<int>>s;
        int sum;
//         for(int i=0; i<n-3; i++)
//         {
//             if(i>0 and nums[i]==nums[i-1]) continue;
//             for(int j=i+1; j<n-2; j++)
//             {
//                 if(j>i+1 and nums[j]==nums[j-1]) continue;
//                  int ntarget=target-nums[i]-nums[j];
//                 for(int k=j+1; k<n-1; k++)
//                 {
//                     if(k>j+1 and nums[k]==nums[k-1]) continue;
//                     for(int l=k+1; l<n; l++)
//                     {
//                         if(l>k+1 and nums[l]==nums[l-1]) continue;
//                         sum=nums[k]+nums[l];
//                         if(sum>ntarget)
//                             break;
//                         else if(sum==ntarget)
//                         {
//                             vector<int> temp;
//                             temp.push_back(nums[i]);
//                             temp.push_back(nums[j]);
//                             temp.push_back(nums[k]);
//                             temp.push_back(nums[l]);
//                             s.insert(temp);
 
//                         }
//                     }
//                 }
//             }
        
//         }
//         //copy the answer from set to vector of vector
//         for(auto it: s)
//         {
//             ans.push_back(it);
//         }
//         return ans;
        
        
        //Method 2: Using two for loop and pointer problem 
        //TC=O(n^3)logn
        
        for(int i=0; i<n-3; i++)
        {
            if(i>0 and nums[i]==nums[i-1]) continue;
            for(int j=i+1; j<n-2; j++)
            {
                if(j>i+1 and nums[j]==nums[j-1]) continue;
                
                //use two pointer approach
                
                //two overcome from integer overflow i have done this
                int ntarget= target-nums[i]-nums[j];
                int left=j+1;
                int right=n-1;
                while(left<right)
                {

                    sum=nums[left]+nums[right];
                    if(sum>ntarget)
                            right--;
                    else if(sum==ntarget)
                        {
                            vector<int> temp;
                            temp.push_back(nums[i]);
                            temp.push_back(nums[j]);
                            temp.push_back(nums[left]);
                            temp.push_back(nums[right]);
                            s.insert(temp);
                        left++;
 
                        }
                    else
                        left++;
                }
                        
            }
        
        }
        //copy the answer from set to vector of vector
        for(auto it: s)
        {
            ans.push_back(it);
        }
        return ans;
        
        
    }