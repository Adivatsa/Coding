#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void insertelement(vector<int> &v, int ele)
{
    //base case 
    if(v.size()==0 || v[v.size()-1]<=ele)
    {
        v.push_back(ele);
        return;
    }
        
    int temp=v[v.size()-1];
    v.pop_back();
    insertelement(v,ele);
    v.push_back(temp);

}
void sortarray(vector<int>& v)
{
    //Base case
    if(v.size()==0)
        return ;

    int ele=v[v.size()-1];
    v.pop_back();
    sortarray(v);
    insertelement(v,ele);
}

int main()
{
    vector<int> v={5,3,8,9,2};
    //Sort an Array Using Recursion
    sortarray(v);
    for(auto it: v)
        cout<< it<< " ";


}