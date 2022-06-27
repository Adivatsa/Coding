#include<iostream>
#include<string>

using namespace std;

//As total ASCII characters
#define d 128

void rabinKarpSearch(string txt, string pat, int q)
{

    //Length of pattern string
    int m=pat.length();

    //length of text string
    int n=txt.length();

    int i;
    //SToring the hash code for txt
    int t=0;
    //Storing the hash code for pattern string
    int p=0;

    //h will store d^(m-1) where d is total characters
    int h=1;

    //find h=d^(m-1);
    for(i=0; i<m-1; i++)
        h=(h*d)%q;

    //Store the hash code for pat strng and txt string with window eqaul to pat string
    for(i=0; i<m; i++)
    {
        //hash code will be calculated as p*d+ascii value
        p=(p*d+pat[i])%q;
        t=(t*d+txt[i])%q;
    }

    //slide the pat string over txt string and if hash code matches then go for checking string
    //for m lenth has been already processed
    for(i=0;i<=n-m; i++)
    {

        //Check if hash codes are eqaul or not
        //if equal then check the string if matches out then return index
        //otherwise break out
        if(t==p)
        {
            //check for string in window of txt and pat
            int j;
            for( j=0; j<m; j++)
            {
                if(pat[j]!=txt[i+j])
                    break;

            }
            //check equal then return index
            if(j==m)
                cout<<"String Found at the position "<<i<<endl;
        }

        //otherwise slide window by one postion and calculate the hash value
        if(i<n-m)
        {
            //remove the value of first caharacter and add from txt one character
            //since h=d^(m-1)
            t=(d*t-d*txt[i]*h+txt[i+m])%q;
        }
        if(t<0)
            t=q+t;
    }
}
int main()
{
    //search the postion of 
    string txt="I love my country country";
    string pat="country";

    //To overcome from overflow inside integer
    int q=11;

    rabinKarpSearch(txt,pat,q);
    return 0;

}

