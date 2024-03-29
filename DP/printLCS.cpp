#include<iostream>

using namespace std;
int t[10][10];
void printlcs(string x, string y, int m ,int n)
{
    //srep 1: intialization
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

        cout<<" LCS count is  "<<t[m][n]<<endl;
    
    string op="";
    
    int i=m;
    int j=n;
    while(i>0 && j>0)
    {
        if(t[i-1]==t[j-1])
        {
            op=op+x[i-1];
            i--;
            j--;
        }
        else
        {
            if(t[i-1][j]>t[i][j-1]
               i--;
             else
               j--;
        }
    }
    cout<<op<<endl;
}
               
int main()
{

    string x="ACBCF";
    string y="ABCDAF";
    int m=x.length();
    int n=y.length();

    printlcs(x,y,m,n);
    return 0;
}
