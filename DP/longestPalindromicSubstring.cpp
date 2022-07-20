    string longestPalindrome(string s) {

//         int n=s.length();
//         vector<vector<int>> t(n, vector<int> (n,0));
//         int maxlen=0;
//         string op;
//         //Traverse in the from of diagonal way
//         for(int diff=0; diff<n; diff++)
//         {
//             for(int i=0, j=i+diff; j<n; i++,j++)
//             {
//                 //first diagonal row
//                 if(i==j)
//                 {
//                     //Single element will always be palindrome
//                     t[i][j]=1;
//                 }
//                 else if(diff==1)//2nd diagonal row
//                 {
//                     //check for two elements if equal then size is 2 otheriwse 0
//                     if(s[i]==s[j])
//                         t[i][j]=2;;
//                 }
//                 else// for all other diagonal
//                 {
//                    //two ends are equal end inner string is palindrome then increment count
//                     //middle elements will be [i,j] is i+1, j-1
//                     if(s[i]==s[j]  && t[i+1][j-1]>0) 
//                             t[i][j]= t[i+1][j-1] +2;
//                 }
                
//                 //Check for maximum length palindrome and store it
//                 //if value is greater than 0 then check maximum between current length and maxlen
//                 //update it and store the string
//                 if(t[i][j]>0)
//                 {
//                     int currlen=j-i+1;
//                     if(currlen > maxlen)
//                     {
//                         maxlen=currlen;
//                         //put the substring starting from i and of length maxlen
//                         op=s.substr(i, maxlen); 
//                     }
//                 }
//             }
//         }
//         return op;
        
        
       //Same like Longest Palindromic Subsequenece 
        int n=s.length();
        string ss=s;
        reverse(ss.begin(), ss.end());
        int t[n+1][n+1];
        string op;
        int maxlen=0;
        for(int i=0; i<n+1; i++)
        {
            for(int j=0; j<n+1; j++)
            {
                if(i==0 || j==0)
                    t[i][j]=0;
            }
        }
        for(int i=1; i<n+1; i++)
        {
            for(int j=1; j<n+1; j++)
            {
                if(s[i-1]==ss[j-1])
                    t[i][j]= 1+ t[i-1][j-1];
                else//not matched then start from begining
                    t[i][j]=0;
                
                //Check for if it is greater than maxlen then check for palindrome
                if(t[i][j]>maxlen)
                {
                    //substring will start from i-len 
                    //then reverse and check if both equal then update maxlen and output string
                    string temp=s.substr(i-t[i][j], t[i][j]);
                    string temp2=temp;
                    reverse(temp2.begin(), temp2.end());
                    if(temp==temp2)
                    {
                        op=temp;
                        maxlen=t[i][j];
                    }
                }
            }
        }
        return op;
        
    }