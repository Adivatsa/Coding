#include<iostream>
#include<map>
#include<unordered_map>

using namespace std;

int main()
{

    unordered_map<string,int> m;

    pair<string,int> p=make_pair("Adi",2);
    m.insert(p);

    pair<string,int>q("vatsa",4);
    m.insert(q);
    cout<<m["Adi"]<<endl;
    cout<<m["vatsa"]<<endl;
    

    m[" "]=5;
    cout<<m[" "]<<endl;
    return 0;
}