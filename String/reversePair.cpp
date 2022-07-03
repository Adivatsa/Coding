    string reverseParentheses(string s) {
        
        //Take one stack for storing characters inside it
        //Approach
        //if found any open bracket then insert into stack
        //if found any letter just check if stack is not empty then push into stack
        //otherwise concatenate to output string as it wil not be reversed it means not enclosed by any bracket 
        //if found any close bracket then
            //take one temporary empty string
            //jab tak open bracket na mil jaaye store the elements into temp string and pop from stack 
            //pop open bracket from stack and put all elemnts into stack if not empty 
        //otherwise put on output string
        stack<char> st;
        
        string temp="";
        string op="";
        
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]=='(')
            {
                st.push(s[i]);
            }
            else if(s[i]==')')
            {
                temp="";
                while(st.top()!='(')
                {
                    temp=temp+ st.top();
                    st.pop();
                }
                st.pop();
                
                if(!st.empty())
                {
                    for(int j=0; j<temp.length(); j++)
                        st.push(temp[j]);
                }
                else
                    op+=temp;
            }
            else
            {
                if(!st.empty())
                    st.push(s[i]);
                else
                    op=op+s[i];
            }
        }
        return op;
        
    }