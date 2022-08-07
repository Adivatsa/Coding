class Solution {
public:
    #define maxval 1000000007
    int countVowelPermutation(int n) {
        
        //we can take a 0,e 1, i 2,o 3,u 4
        //at n=1 we know that everything will be 1
        //but at n=2 we can have t[2][a]= t[1][e]+ t[1][i]+ t[1][u]
        //we can get a after e,i,u so take from previous table so ans stored will be 3
        
        vector<vector<int>> t(n+1, vector<int> (5,1));
        
        for(int i=2;i<=n; i++)
        {
            t[i][0]=((t[i-1][1]+ t[i-1][2])%maxval+ t[i-1][4])%maxval;
            t[i][1]=(t[i-1][0]+ t[i-1][2])%maxval;
            t[i][2]=(t[i-1][1]+ t[i-1][3])%maxval;
            t[i][3]=(t[i-1][2])%maxval;
            t[i][4]=(t[i-1][2]+ t[i-1][3])%maxval;
        }
        

        int ans=0;
        for(int i=0; i<5; i++)
            ans=(ans+t[n][i]) %maxval;
        return ans%maxval;
    }