    string longestCommonPrefix(vector<string>& strs) {
        
        //Approach:
        //Traverse for first string and compare with all other strings
        //If it matches then add to output string 
        //otherwise return null string
        
        string op;
        int n=strs.size();
        
        // this loop is for first string
        for(int i=0; i<strs[0].length(); i++)
        {
            bool match=true;
            //Take out the character and compare with other characters
            char ch=strs[0][i];
            
            //This loop is for all other strings
            for(int j=1; j<n;j++)
            {
                //if does not match then break and mark match as false
                
                if(strs[j][i]!=ch)
                {
                    match=false;
                    break;
                }
            }
            //Check if it has been match then put into output string otherwise break
            if(match==true)
                op.push_back(ch);
            else
                break;
            
        }
        return op;
        
    }