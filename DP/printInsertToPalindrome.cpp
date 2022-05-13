#include<algorithm>
 #include<iostream>
 #include<string>
 using namespace std;
 void minInsertions(string s) {
        
        
        //This question is similat to number of deletions to make a string palindrome
        //Instead of deletion we can insert that much elements
        //That much insertions leads to same palindromic string
        //print Palindrome
        
        string r=s;
        reverse(s.begin(), s.end());
        
        int m=r.length();
        int n=s.length();
        
        int t[m+1][n+1];
        
        for(int i=0; i<m+1; i++)
        {
            for(int j=0; j<n+1; j++)
            {
                if(i==0 ||j==0)
                    t[i][j]=0;
            }
        }
        
        for(int i=1; i<m+1; i++)
        {
            for(int j=1; j<n+1; j++)
            {
                if(r[i-1]==s[j-1])
                    t[i][j]=1+t[i-1][j-1];
                else
                    t[i][j]=max(t[i-1][j], t[i][j-1]);
                
            }
        }
        
        int i=m, j=n;
        string str="";

        while(i>0 && j>0)
        {
            if(r[i-1]==s[j-1])
            {
                str.push_back(r[i-1]);
                i--;
                j--;
            }
            else
            {
                str.push_back(r[i-1]);
                str.push_back(s[j-1]);
                i--;
                j--;
            }
        }

        cout<<str;
        
    }

    int main()
    {
        string str ="aebcdba";
        minInsertions(str);
        return 0;

    }