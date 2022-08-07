class Solution {
public:
    #define maxval 1000000007
    int solve(int index, char prev, int n, unordered_map<char,vector<char>> &m,
             vector<vector<int>> &t)
    {
        //Base case
        //when index reaches to last return 1
        if(index==n)
            return 1;
        
        //Memoization Step
        if(t[index][prev-'a']!=-1)
            return t[index][prev-'a'];
        int ans=0;
        //iterate over all vector char stored in map of prev and call function
        for(auto c: m[prev])
        {
            ans= (ans%maxval + solve(index+1, c,n,m,t)%maxval)%maxval;
        }
        return t[index][prev-'a']=ans%maxval;
    }
    int countVowelPermutation(int n) {
        
        //Recursive solution
        //Store the mapping inside the map with intial s as all vowels
        //call the recursive funtion with intail as s
        unordered_map<char,vector<char>> m;
        m['s']={'a', 'e','i','o','u'};
        m['a']={'e'};
        m['e']={'a', 'i'};
        m['i']={'a', 'e', 'o', 'u'};
        m['o']={'i','u'};
        m['u']={'a'};
        
        //Memoization step
        vector<vector<int>> t(n+1, vector<int> (26,-1));
        return solve(0,'s',n,m,t);
        
        
        
        //Tabaulation Approach
        //we can take a 0,e 1, i 2,o 3,u 4
        //at n=1 we know that everything will be 1
        //but at n=2 we can have t[2][a]= t[1][e]+ t[1][i]+ t[1][u]
        //we can get a after e,i,u so take from previous table so ans stored will be 3
        
//         vector<vector<int>> t(n+1, vector<int> (5,1));
        
//         for(int i=2;i<=n; i++)
//         {
//             t[i][0]=((t[i-1][1]+ t[i-1][2])%maxval+ t[i-1][4])%maxval;
//             t[i][1]=(t[i-1][0]+ t[i-1][2])%maxval;
//             t[i][2]=(t[i-1][1]+ t[i-1][3])%maxval;
//             t[i][3]=(t[i-1][2])%maxval;
//             t[i][4]=(t[i-1][2]+ t[i-1][3])%maxval;
//         }
        

//         int ans=0;
//         for(int i=0; i<5; i++)
//             ans=(ans+t[n][i]) %maxval;
//         return ans%maxval;
    }
};
