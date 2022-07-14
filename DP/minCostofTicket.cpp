    int solve(vector<int>& days, vector<int>& costs, int i, vector<int>&t)
    {
        //Base case
        if(i==days.size())
            return 0;
        
        //Memoization Step
        if(t[i]!=-1)
            return t[i];
        
        //one day pass
        int oneday=costs[0]+ solve(days,costs, i+1,t);
        
        //seven day pass
        //take the j when it will be not covered by seven day pass
        int j;
        for(j=i; j<days.size(); j++)
        {
            if(days[j]>=days[i]+7)
                break;
        }
        int sevenday=costs[1]+ solve(days, costs, j,t);
        
        
        //30 day pass
        //take the day to which not covered by 30day pass
        int k;
        for(k=i; k<days.size(); k++)
        {
            if(days[k]>=days[i]+30)
                break;
        }
        int thirtyday=costs[2]+ solve(days, costs, k, t);
        
        //return minimum  among them
        return t[i]=min(oneday, min(sevenday, thirtyday));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        
        //Recursion
        
        //In this we have explore all the three passs and which provides the minimum we have to return
        //Start from index 0 and check for one day, seven day ,thirty day 
        
        //Memoization
        // vector<int> t(days.size(),-1);
        // return solve(days, costs, 0,t);
        
    }