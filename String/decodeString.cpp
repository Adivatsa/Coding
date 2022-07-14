    string decodeString(string s) {
        
        stack<int>s1;//for storing the number
        stack<string>s2;//for storing string
        
        int currnum=0;//store current number
        string currstr="";
        
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]=='[')//opening bracket
            {
                //we have to push currnum and currstr in stack and make them 0 and empty
               s1.push(currnum);
                s2.push(currstr);
                currnum=0;
                currstr="";
            }
            else if(s[i]==']')//closing bracket
            {
                //take the number and prev string
                //multilpy previous number with currstr and append prev str
                int prevnum=s1.top();

                s1.pop();
                string prevstr=s2.top();

                s2.pop();
                string temp="";
                //printing k times string str  ...k[str]
                while(prevnum>0)
                {
                    temp+=currstr;
                    prevnum--;
                }
                currstr=prevstr+temp;
            }
            else if(s[i]>47 && s[i]<58)//number
            {
                currnum=currnum*10 + (s[i]-48);//making it as integer by sub ascii value
            }
            else//string
            {
                currstr=currstr+s[i];//store the current string
            }
        }
        return currstr;
        
    }