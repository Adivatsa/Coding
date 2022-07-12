    bool solve(vector<int>& matchsticks, int i, int slen, vector<int> &v)
    {
        //Base case
        //when index reaches at last then check for each side length i equal then return true otherwise false
        if(i==matchsticks.size())
        {
            if(v[0]==v[1] && v[1]==v[2] && v[2]==v[3] && v[3]==v[0])
                return true;
            else
                return false;
        }
        
        //traverse over vector of side and assign it with matstick length
        for(int j=0; j<4; j++)
        {
            //check if matchstick and side length in vector should not exceed side length of square
            //if exceeds then go and fill next side length vector
            if(v[j] + matchsticks[i]<=slen)
            {
                v[j]=v[j]+matchsticks[i];

                //call for dfs 
                if(solve(matchsticks, i+1, slen, v))
                    return true;
                //backtracking
                v[j]=v[j]-matchsticks[i];
            }
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        
        //Check if array contain size less than 4 return false as we can not make square with lees than 4 size
        
        if(matchsticks.size()<4)
            return false;
        
        //check if sum of all sides divides bt 4 is not even then we can't divide into 4 equal parts
        int sum=0;
        for(int i=0; i<matchsticks.size(); i++)
            sum+=matchsticks[i];
        
        if(sum%4!=0)
            return false;
        
        //check for if any side has length greater than sum/4 then return false
        sort(matchsticks.rbegin(), matchsticks.rend());
        
        //to store the lenth of four sides
        vector<int> v(4,0);

        return solve(matchsticks, 0, sum/4, v);
        
    }