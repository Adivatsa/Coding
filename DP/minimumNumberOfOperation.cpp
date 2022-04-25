	int t[1001][1001];
	int minOperations(string str1, string str2) 
	{ 
	    // In this question we have to convert str1 to str2
	    //Now for that we have return no of deletions + no of insertions
	    //Main logic here is string is given, asking for min operations i.e. to optimize
	    //So it belongs to lCS with Dp approach
	    
	    //Sabse phle lcs nekal lo
	    //str1 me se lcs ke aalwa sabko delete maar do
	    //str2 banne ke liye jitna chahiye wo sabko add kar do lcs ke aalwa
	    for(int i=0; i<str1.length()+1; i++)
	    {
	        for(int j=0; j<str2.length()+1; j++)
	        {
	            if(i==0 || j==0)
	                t[i][j]=0;
	        }
	    }
	    
	    for(int i=1; i<str1.length()+1; i++)
	    {
	        for(int j=1; j<str2.length()+1; j++)
	        {
	            if(str1[i-1]==str2[j-1])
	                t[i][j]=1+t[i-1][j-1];
	            else
	                t[i][j]=max(t[i-1][j], t[i][j-1]);
	        }
	    }
	    //No of deletions = str1 length - lcs(sab kachra hat jaayega)
	    int m=str1.length()-t[str1.length()][str2.length()];
	    //No of insertions =  str2-lcs(kaam ki chiz kitna daalna pdega lcs me str2 banane ke liye)
	    int n=str2.length()-t[str1.length()][str2.length()];
	    
	    return n+m;
	}