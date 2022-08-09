    #define maxval 1000000007
    int numFactoredBinaryTrees(vector<int>& arr) {
        
        //Store inside map
        unordered_map<int, long long int> m;
        //sort the array
        sort(arr.begin(), arr.end());
        //store the every eleemnt woth value as 11 as it can form leaf node
        for(int i=0; i<arr.size(); i++)
        {
            m[arr[i]]=1;
        }
        
        //for every element just start check from 0 to i-1 and see we can form by multipying
        for(int i=0; i<arr.size(); i++)
        {
            for(int j=0; j<i; j++)
            {
                //check if it is divisible by arr[j]
                if(arr[i]%arr[j]==0)
                {
                    //it means we have to find the which can be multiplied to get desired number
                    int rem=arr[i]/arr[j];
                    if((rem* arr[j]==arr[i]) && m.find(rem)!=m.end())
                    {
                        m[arr[i]]= m[arr[i]]+ (m[arr[j]] * m[rem]);//then find possible ay
                    }
                }
            }
        }

        long long int ans=0;
        for(auto it: m)
        {
            ans=(ans + it.second);
        }
        return ans%maxval;
            
        
    }