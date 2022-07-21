#include<iostream>

using namespace std;

//Time Complexity is O(2^n)n since outer loop runs for 2^n and for each time n times string traversed
void powerset(string s)
{
    int n=s.length();
    //In bits 2^n= 1<<n
    for(int i=0; i<=((1<<n)-1) ; i++)
    {
        string op="";
        for(int j=0; j<n; j++)
        {
            //check if jth bit is set then put the character
            //to check jth bit is set or not i& (1<<j)
            if(i & (1<<j))
                op=op+ s[j];
        }
        if(op=="")
            cout<<"{}"<<endl;
        else
            cout<<op<<endl;
    }
}

int main()
{
    string s="abc";
    cout<<" Printing All the Subsequences Using Power Set"<<endl;

    powerset(s);

    return 0;
}