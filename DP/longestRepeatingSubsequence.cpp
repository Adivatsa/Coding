		int LongestRepeatingSubsequence(string str){
		    
		    //In this question we have to find the repeating subsequence
		    //which means we have to find the repated subsequence which appeared more than once
		    //To apply lcs we will take twice the same string
		    //Now we will find LCS with constraint as same charater not taking twice
		    //So use if index i== index j when characters are same then don't include which means
		    //Taking from repeated one 
		    
		    string str2=str;
		    int m=str.length();
		    int n=m;
		    
		    int t[m+1][n+1];
		    for(int i=0; i<m+1; i++)
		    {
		        for(int j=0; j<n+1; j++)
		        {
		            if(i==0 || j==0)
		                t[i][j]=0;
		        }
		    }
		    
		    for(int i=1; i<m+1; i++)
		    {
		        for(int j=1; j<n+1; j++)
		        {
		            if(str[i-1]==str2[j-1]  && i!=j)
		                t[i][j]=1+t[i-1][j-1];
		            else
		                t[i][j]=max(t[i-1][j], t[i][j-1]);
		        }
		    }
		    
		    return t[m][n];
		}