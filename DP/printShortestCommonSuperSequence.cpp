#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
using namespace std;


//We have to print the shortest common supersequence
//supersequence means it should conatin both  the strings
//BUt the final string lenth should be smallest
//Find out LCS which will be common in both the strings which will be repeated twice
//In final string take all strings and subtract one time LCS
//print is similar to LCS
//go into backtrack side with rinting when they are not equal also
//At last go to (0,0) so that Supersequence should include remaining also
int t[101][101];
void printLCSS(string x, string y, int m, int n)
{
    for(int i=0; i<m+1; i++)
    {
        for(int j=0; j<n+1; j++)
        {
            if(i==0 || j==0)
                t[i][j]=0;
        }
    }

    for(int i=1; i<m+1; i++)
    {
        for(int j=1; j<n+1; j++)
        {
            if(x[i-1]==y[j-1])
                t[i][j]=1+t[i-1][j-1];
            else
                t[i][j]=max(t[i-1][j], t[i][j-1]);
        }
    }
    int i=m;
    int j=n;
    string s="";
    while(i>0 && j>0)
    {
        if(x[i-1]==y[j-1])
        {
            s.push_back(x[i-1]);
            i--;
            j--;
        }
        else
        {
            if(t[i-1][j]>t[i][j-1])
            {
                s.push_back(x[i-1]);
                i--;
            }
            else
            {
                s.push_back(y[j-1]);
                j--;
            }
        }
    }

    while(i>0)
    {
        s.push_back(x[i-1]);
        i--;
    }

    while(j>0)
    {
        s.push_back(y[j-1]);
        j--;
    }

    reverse(s.begin(), s.end());
    cout<<s;

}
int main()
{
    string x="acbcf";
    string y="abcdaf";
    printLCSS(x,y,x.length(),y.length());
    return 0;
}