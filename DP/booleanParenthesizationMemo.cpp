    int t[201][201][2];
    int solve(string s, int i, int j, bool istrue)
    {
        //base condition
        if(i>j)
            return 0;
        
        if(i==j)//only one element
        {
            if(istrue==true)//we are looking for true
                return s[i]=='T';//if it will T then T will be returned otherwise F
            else//We are looking for false
                return s[i]=='F';//check karega agr false hga toh T return otherwise F
        }
        if(t[i][j][istrue]!=-1)
        {
            return t[i][j][istrue];
        }
        //operators are present at every alternate distance so k will be from i to j-1
        //with jump of 2
        int ans=0;
        for(int k=i+1; k<j; k=k+2)
        {
            //find out all the combinations with k
            //left side true and false value 
            //right side true and false value 
            //To apply the operator present at k
            int lt=solve(s,i,k-1,true);//as k will be operator so i to k-1
            int lf=solve(s,i,k-1,false);
            int rt=solve(s,k+1,j,true);
            int rf=solve(s,k+1,j,false);
            //find out the ways which will give ans
            if(s[k]=='&')//agr xor operator hai toh
            {
                if(istrue==true)
                    ans+=(lt*rt);//it will go for true value
                else
                    ans+=(lt*rf)+(lf*rt)+(lf*rf);//otherwise false will be calculated
            }
            else if(s[k]=='|')
            {
                if(istrue==true)
                    ans+=(lt*rt)+(lt*rf)+(lf*rt);
                else
                    ans+=(lf*rf);
            }
            else
            {
                if(istrue==true)
                    ans+=(lt*rf)+(lf*rt);
                else
                    ans+=(lt*rt)+(lf*rf);
            }
        }
        return t[i][j][istrue]=(ans%1003);
    }
    int countWays(int N, string S){
        
        //In this question we have to put paranthesis in such a way that expression should be true
        //Give the number of ways we can use paranthesis
        //here i will start from 0 and j will be at last
        
        int i=0;
        int j=N-1;
        bool istrue=true;
        memset(t,-1,sizeof(t));
        return solve(S,i,j,istrue);
    }