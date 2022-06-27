#include<iostream>
#include<string>

using namespace std;
int pattermatch(string txt, string pat)
{
    int n=txt.length();
    int m=pat.length();
    int i=-1;
    int j=0;
    while(n!=0 && j<txt.length())
    {
         i=txt.find(pat);
        //  if(i!=-1)
        //      break;
        j++;
    }
    return i;
}
int main()
{
    string txt="This is India";
    string pat="India";
    int pos=pattermatch(txt,pat);
    cout<<"Pattern found at position at "<<pos<<endl;
    return 0;
}