    bool isValid(string s) {       
        stack<char>st;
        int i=0;
        while(i<s.length())
        {
            char ch=s[i];
            if(ch=='('|| ch=='[' || ch=='{')
            {
                st.push(ch);
                i++;
            }
            else
            {
                //if starting only close braces came then return false
                if(st.empty())
                    return false;
                else if(ch==')' && st.top()=='(')
                {
                    st.pop();
                    i++;
                }
                else if(ch=='}' && st.top()=='{')
                {
                    st.pop();
                    i++;
                }
                else if(ch==']' && st.top()=='[')
                {
                    st.pop();
                    i++;
                }
                else//when open and close braces are not of same type
                    return false;
            }       
        }
        //only open braces are there
        if(!st.empty())
            return false;
        else
            return true;
    }