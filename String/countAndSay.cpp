    string countAndSay(int n) {
        if(n==1 )
            return "1";
        
        //Recursion call to previous function
        string s=countAndSay(n-1);
        //output string
        string res=""; 
        //we have to store first count of same digits and then digit like 111 as 31 means three 1 are there
        //everytime new digit is been detected intialize count as 0
        //count is integer so typecast to string before putting inside string

        int cnt=0;
        for(int i=0; i<s.length(); i++)
        {
            cnt++;
            if(i>=s.length() || s[i]!=s[i+1])
            {
                res=res+to_string(cnt)+(s[i]);
                cnt=0;
            }
        }
        //return the string
        return res;
        
    }