#include<stack>
bool findRedundantBrackets(string &s)
{
    stack<char>st;
    for(int i=0; i<s.length(); i++)
    {
        char ch=s[i];
        if(ch=='(' || ch=='+' || ch=='-' || ch=='*' || ch=='/')
            st.push(ch);
        else
        {
            bool valid=true;
            if(ch==')')
            {
                while(st.top()!='(')
                {
                    char temp=st.top();
                    if(temp=='+' || temp=='-' || temp=='*' || temp=='/')
                    {
                        valid=false;
                    }
                    st.pop();
                }
                    if(valid==true)
                        return true;
                    st.pop();
            }
        }
    }
   return false;
}