    
    //TLE as not optimised
    
    bool ispalindrome(string s, int i, int j)
    {

        while(i<=j)
        {
            if(s[i]!=s[j])
                return false;
            else
                {
                    i++;
                    j--;
                }
        }
        return true;;
    }
    int solve(string s, int i, int j)
    {
        //Base condtion
        if(i>=j)
            return 0;
        
        if(ispalindrome(s,i,j)==true)
        {
            return 0;
        }
        int mini=INT_MAX;
        //k will used to partiotion between i to j-1 as j will be taken then will rule out of string
        for(int k=i; k<j; k++)
        {
            int currAns= solve(s,i,k)+solve(s,k+1,j)+1;
            mini=min(currAns,mini);
        }
        
        return mini;
    }
    int minCut(string s) {
        
        //Method 1: Recursive Approach
        //In this we have find out the patition we will do do make the string as palindrome
        //Base condtions is if string is empty and string length is 1 it is already a palindrome then return 0 no of partition or cut to make the string palindrome
        //If the string is palindrom just check it , if yes then return 0
        //Now we have to find start and end index as i and j
        //i will be 0 as it will take a single char also and j as last 
        //whenever partiton is been made recursive calls are made and one will be aaded as partiton done just now
        int i=0;
        int j=s.size()-1;
        return solve(s,i,j);
        
       
    }