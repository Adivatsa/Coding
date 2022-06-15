    void solve(int one, int zero, string op, vector<string> &ans, int n)
    {
        
        //Base condition
        //when n=0 then it will be valid string
        if(n==0)
        {
            ans.push_back(op);
            return;
        }
        
        if(one>zero)
        {
            //if no of 1 is greater than only we can add 0 or 1 
            string op1=op;
            string op2=op;
            op1.push_back('0');
            op2.push_back('1');
            solve(one,zero+1,op1,ans,n-1);
            solve(one+1,zero,op2,ans,n-1);
        }
        else
        {
            //if no of 1 is eqaul than only we can add 0 
            string op1=op;
            op1.push_back('1');
            solve(one+1,zero,op1,ans,n-1);
        }
    }
	vector<string> NBitBinary(int N)
	{
	    //we have every time choice of 0 and 1 with no of 1 greater or equal to 0
	    //if no of zero <no of one then we can insert 0 to string
	    //otherwise insert everytime one's to string
	    //everytime decrement n by recursive call
	    
	    int one=0;
	    int zero=0;
	    string op;
	    vector<string> ans;
	    solve(one,zero,op,ans,N);
	    //sort in reverse order
	    sort(ans.begin(), ans.end(),greater<>());
	    return ans;
	}