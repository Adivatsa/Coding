    int minAddToMakeValid(string s) {
        
        stack<char> st;
        //if empty hai toh push kar do stack me
        //if open hai toh stack m daal do
        //if close hai and top pe open hai toh stack se pop kara do
        //if close hai and stack ke top pe close hai toh daal do stack mr
        for(int i=0; i<s.length(); i++)
        {
            char ch=s[i];
            if(st.empty())
                st.push(ch);
            else if(ch=='(')
                st.push(ch);
            else if(ch==')' && st.top()=='(')
                st.pop();
            else
                st.push(ch);
        }
        int ans=0;
        while(!st.empty())
        {
            ans++;
            st.pop();
        }
        return ans;   
    }