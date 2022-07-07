    //bool t[101][101];
    
    bool solve1(string s1, string s2, string s3, int i, int j, vector<vector<bool>> &t)
    {
        //Base case
        if(i==s1.length() && j==s2.length())
            return true;
        //check if not null return from here
        if(t[i][j]>=0)
        {
            return t[i][j];
        }
            
        //check for string s1 and s3 if matches then return true
        if(i<s1.length() && s1[i]==s3[i+j])
        {
            bool str1=solve1(s1,s2,s3,i+1,j,t);
            t[i][j]=str1;
            if(str1==true)
                return true;
        }
        //check for string s2 and s3 if matches then return true
        if(j<s2.length() && s2[j]==s3[i+j])
        {
            bool str2=solve1(s1,s2,s3,i,j+1,t);
            bool str3=solve1(s1,s2,s3,i+1,j+1,t);
            t[i][j]=str2 ||str3;
            if(str2==true)
                return true;
        }
        t[i][j]=false;
        return false;
    }
        
//     bool solve(string s1, string s2, string s3, int i, int j, int)
//     {
//         //Base case
//         if(i==s1.length() && j==s2.length())
//             return true;
        
//         //check for string s1 and s3 if matches then return true
//         if(i<s1.length() && s1[i]==s3[i+j])
//         {
//             bool str1=solve(s1,s2,s3,i+1,j);
//             if(str1==true)
//                 return true;
//         }
//         //check for string s2 and s3 if matches then return true
//         if(j<s2.length() && s2[j]==s3[i+j])
//         {
//             bool str2=solve(s1,s2,s3,i,j+1);
//             if(str2==true)
//                 return true;
//         }
//         return false;
//     }
    bool isInterleave(string s1, string s2, string s3) {
        
        //Method 1: Usinmg Reccursion TC=)(2^m+n)  GOT TLE
        
        //Base Case
        
        if(s1.length()+s2.length() != s3.length())
            return false;
        
        // //call recursion with i and j pointer
        // return solve(s1,s2,s3,0,0);
        
        //Method 2: Memoization or Top Down TC=O(n*m)
        
        vector<vector<bool>> t(s1.length()+1, vector<bool>(s2.length()+1, 0));
        
        return solve1(s1,s2,s3,0,0,t);
        
        // bool t[s1.length()+1][s2.length()+1];
        // memset(t,false,sizeof(t));
        // for(int i=0; i<s1.length()+1; i++)
        // {
        //     for(int j=0; j<s2.length()+1; j++)
        //     {
        //         if(i==0 && j==0)
        //             t[i][j]=true;
        //         else if(i==0)
        //         {
        //             if(s2[j-1]==s3[i+j-1])
        //                 t[i][j]=t[i][j-1];
        //             else
        //                 t[i][j]=false;
        //         }
        //         else if(j==0)
        //         {
        //             if(s1[i-1]==s3[i+j-1])
        //                 t[i][j]=t[i-1][j];
        //             else
        //                 t[i][j]=false;
        //         }
        //         else
        //         {
        //             if(s1[i-1]==s3[i+j-1])
        //             {
        //                 t[i][j]=t[i-1][j];
        //             }
        //             if( s2[j-1]==s3[i+j-1])
        //             {
        //                     t[i][j]=t[i][j-1] ||t[i][j];
        //             }
        //         }
        //     }
        // }
        // return t[s1.length()][s2.length()];
        
    }