//return the address of the string
char* reverse(char *S, int len)
{
    
   
    //phle step me ek ek karke sab element to push maar dnge 
    //uske baad stack ke top ko le kar insert maarte jaayenge string me
    //phir stack ke top ko delete kar dena 
    //return maar dena string ka pointer
    stack<int> s;
    for(int i=0; i<len; i++)
    {
        char ch= S[i];
        s.push(ch);
    }
    int i=0;
   while(!s.empty()&& i<len)
    {
        S[i]=s.top();
        i++;
        s.pop();
    }
    return S;
}