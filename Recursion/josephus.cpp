    void solve(vector<int> v, int k, int index, int &ans)
    {
        //Base case
        if(v.size()==1)
        {
            ans=v[0];
            return;
        }
        
        //find the required index
        index=(index+k)%v.size();
        //Erase  that index
        v.erase(v.begin()+index);
        
        //revcursive call
        solve(v,k,index,ans);
    
    }
    int findTheWinner(int n, int k) {
        
        //This is also called as Josephus Problem
        //Start from ith and go to k then kill that one and again start from next
        
        vector<int> v;
        for(int i=0; i<n; i++)
            v.push_back(i+1);
        
        //Vector indices starting from 0 so we have to always start from 0
        k--;
        // for(int i=0; i<n; i++)
        //     cout<<v[i];
        
        int ans;
        int index=0;
        solve(v,k,index,ans);
        //Return then ans
        return ans;
        
        
    }