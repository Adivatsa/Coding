
    int solve(vector<int>& nums, int index, int pindex, vector<vector<int>> &t)
    {
        //Base case
        if(index==nums.size())
            return 0;
        
        //Memoization step
        //shift one index for pindex
        if(t[index][pindex+1]!=-1)
            return t[index][pindex+1];
        
        //we have two conditions as we can pick or not pick
        int len=0;
        //For not pick condition previous index will not change
        len= 0+ solve(nums,index+1,pindex,t);
        //for pick we have to see if previous index is -1 then we can pick otherwise we can pick in increasing order
        if(pindex==-1 || nums[index]>nums[pindex])
        {
            //in this length will be increased and pindex will changed to current index
            len=max(len,1+ solve(nums, index+1, index,t));
        }
        return t[index][pindex+1]=len;
    }
    int lengthOfLIS(vector<int>& nums) {
        
        int n=nums.size();
        //Recursion Approach
        //at starting previous Index will be at -1
        
        
        //Memoization Step
        //here we are storing pindex as -1 so shift ur index with -1 to n-1 as 0 to n
        //vector<vector<int>> t(n, vector<int> (n+1, -1));
        //return solve(nums, 0, -1,t);
        
        //Tabulation Approach
        //TC= O(n^2) sc=O(n^2)
        
//         vector<vector<int>> t(n+1, vector<int> (n+1, 0));
//         for(int index=n-1; index>=0; index--)
//         {
//             for(int pindex=index-1; pindex>=-1; pindex--)//previous index will be -1 to index-1
//             {
//                 int len=0;

//                 len= 0+ t[index+1][pindex+1];

//                 if(pindex==-1 || nums[index]>nums[pindex])
//                 {
//                     len=max(len,1+ t[index+1][index+1]);
//                 }
//                 t[index][pindex+1]=len;
//             }
//         }
//         return t[0][-1+1];
        
        //Space optimization
        //TC= O(n^2) SC=O(n)
//         vector<int> curr(n+1,0);
//         vector<int> prev(n+1,0);
        
//         for(int index=n-1; index>=0; index--)
//         {
//             for(int pindex=index-1; pindex>=-1; pindex--)//previous index will be -1 to index-1
//             {
//                 int len=0;

//                 len= 0+ prev[pindex+1];

//                 if(pindex==-1 || nums[index]>nums[pindex])
//                 {
//                     len=max(len,1+prev[index+1]);
//                 }
//                 curr[pindex+1]=len;
//             }
//             prev=curr;
//         }
//         return prev[-1+1];
        
        //Another Approach of tabulation
        //Used for LIS printing Purpose
        //TC=O(n^2)
       //  vector<int> t(n+1, 1);
       //  int maxi=0;
       //  for(int index=0 ; index<n; index++)
       //  {
       //      for(int pindex=0; pindex<index; pindex++)
       //      {
       //          if(nums[pindex] < nums[index])
       //              t[index]= max(1 + t[pindex], t[index]);
       //      }
       //      maxi=max(maxi, t[index]);
       //  }
       // return maxi; 
        
        
        //Printing the LIS
        
        
        vector<int> t(n, 1);
        //Track will store which ahs been last added for lis index
        vector<int> track(n,0);
        //used for backtarcking
        int startIndex=0;
        //finding the max length LIS
        int maxi=0;
        for(int index=0 ; index<n; index++)
        {
            track[index]=index;
            for(int pindex=0; pindex<index; pindex++)
            {
                if(nums[pindex] < nums[index] && t[pindex]+1 > t[index])
                {
                    t[index]=t[pindex]+1;
                    //updation on track vector
                    track[index]=pindex;
                }
                    
            }
            if(t[index]>maxi)
            {
                maxi=t[index];
                startIndex=index;
            }
        }
        for(auto it: track)
            cout<<it<<endl;
       
        
        vector<int> print;
        print.push_back(nums[startIndex]);
        //Backtrack and print the LIS
        while(track[startIndex]!=startIndex)
        {
            startIndex=track[startIndex];
            print.push_back(nums[startIndex]);
        }
        reverse(print.begin(), print.end());
        for(auto it: print)
            cout<<it<<" "<<endl;
        //Printing code ended 
        
        return maxi;
    }