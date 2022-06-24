    bool isPalindrome(string s) {
      //It has three steps
        //phle me faaltu characters htao other than alphanumeric
        //second me sab ko lower case me daal do
        //last me palindrome check kar lo
        
        //Step 1: Eliminate all the characters other than alpha numeric
        
        string temp="";
        for(int i=0; i<s.length(); i++)
        {
            if((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z')|| (s[i]>='0' && s[i]<='9'))
                temp.push_back(s[i]);

                  
        }
        //cout<<temp<<endl;
        //Step 2:Convert to small case 
        for(int i=0; i<temp.length(); i++)
        {
            if(temp[i]>='A' && temp[i]<='Z')
                temp[i]+=32;
        }
        //cout<<temp;
        //Step 3: Check for palindrome
        int i=0;
        int j=temp.length()-1;
        while(i<j)
        {
            if(temp[i]!=temp[j])
                return false;
            i++;
            j--;
            
        }
        return true;
    }