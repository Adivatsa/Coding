    string reverseWords(string s) {
        
        string op;
        
        int len=s.length();
        int i=0;
        while(i<s.length())
        {
           //Step 1: Spaces ko nai daalna hai
            while(i<len && s[i]==' ')
                i++;
            //traversal on string has been completed
            if(i>=len)
                break;
            //store the substring till do not encunter any space
            int j=i;
            while(j<len && s[j]!=' ')
                j++;
            
            //Store the subtsring in resultant string
            //substr(start index, length)
            string temp=s.substr(i,j-i);
            
            //if outstring is empty then insert string otherwise insert one space and string
            if(op.length()==0)
                op=temp;
            else
                op=temp + ' ' + op;
            
            i=j+1;
        }
        return op;
    }