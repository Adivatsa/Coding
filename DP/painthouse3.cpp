    # define maxval 1000001
    
    //To ptimise use 3D dp
    int t[100][101][21];

    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        
        //Method 1: Recursive Solution
        //intially the hnouse no as 0 total neigbour is 0 and previous color=0
        
        //Method 2: memoization
        //ans should be equal to target and coor indexing is from 1

        int i=0;
        memset(t,-1, sizeof(t));
        int ans=solve(houses,cost,m,n,target,0,i,0);
        if(ans==maxval)
            return -1;
        else
            return ans;
        
    }
    
    int solve(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target, int hno, int tnbr, int pcolor)
    {
        
        
        //Base case 
        //when house number reaches to the total houses then check if neighbour equal to target then return 0 otherwise infinity
        if(hno==m)
        {
            if(tnbr==target)
                return 0;//it will take 0 cost to paint as it has already reached to end
            else
                return maxval;//it wll take infinity cost to paint house
        }
        
        //check when neighbour greater than target
        if(tnbr> target)
            return maxval;
        
        if(t[hno][tnbr][pcolor]!=-1)
            return t[hno][tnbr][pcolor];
        
        //if it has been not beeen colored
        if(houses[hno]==0)
        {
            int mincost=maxval;
            //we will try here to color with every possible color available and find the cost
            for(int clr=1; clr<=n; clr++)
            {
                //check for if color is not eqaul to its neighbour color then update the tnbr count
                int nbr=tnbr;
                if(pcolor!=clr)
                    nbr++;
                //upadte the mincost
                mincost=min(mincost, cost[hno][clr-1]+ solve(houses,cost,m,n,target, hno+1,nbr,clr));
            }
            t[hno][tnbr][pcolor]=mincost;
            return mincost;
        }
        else//house has been already painted
        {
            //so here we will check if it has been painted with neighbour color or not
            //if yes then don not upadte if not painted with same color then upadte it
            int nbr=tnbr;
            if(pcolor!=houses[hno])
                nbr++;
         
            t[hno][tnbr][pcolor]=solve(houses,cost,m,n,target, hno+1,nbr,houses[hno]);
            return t[hno][tnbr][pcolor];
        }
    }