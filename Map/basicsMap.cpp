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

    cout<<m.at("Adi")<<endl;

    cout<<m.size()<<endl;
    m.erase("Adi");

    unordered_map<string,int> ::iterator it=m.begin();
    while(it!=m.end())
    {
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }
    return 0;
}