//     int t[101];
//     int solve(int n, vector<int>& nums)
//     {
//         //base case
//         if(n==0)
//             return nums[0];
//         if(n<0)
//             return 0;
//         if(t[n]!=-1)
//             return t[n];
        
//         int pick=nums[n]+ solve(n-2,nums);
//         int npick=solve(n-1, nums);
        
//         t[n]=max(pick, npick);
//         return t[n];
//     }
    int rob(vector<int>& nums) {
        
        //In this we can alternate houses so that police can not be infromed
        //there will be two cases where in first case u have to pick and go to next next house
        //otherwise do not pick and go to next house
        //Recursion and Memoization
        // memset(t,-1,sizeof(t));
        // return solve(nums.size()-1,nums);
        
        //Bottom Up
//         int n=nums.size();
//         vector<int> t(n+1,0);
//         t[0]=nums[0];
//         int neg=0;
//         for(int i=1; i<n; i++)
//         {
//             int tk=nums[i];
//             if(i>1)
//             {
//                 tk=tk+t[i-2];
//             }
            
//             int ntk=t[i-1];
            
//             t[i]=max(tk,ntk);
            
//         }
//         return t[n-1];
        
        //Sapce optimization
        int prev=nums[0];
        int prev2=0;
        int curr;
        for(int i=1; i<nums.size(); i++)
        {
            int fhouse=prev;
            int shouse=nums[i]+prev2;
            
            curr=max(fhouse,shouse);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }