#include<stack>
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        vector<int> v;
        stack<pair<int, int>> s; //stack ek pair me banna lo ek me largest store karna dhushre me index rakhna
        
        for(int i= temperatures.size()-1; i>=0; i--)
        {
        
            while((!s.empty())&& (s.top().first<= temperatures[i])) //stack ke first wale ko compare maaron temperature se agr chota hai toh pop maar do 
            {
                s.pop();
                //cnt++;
            }
            if(s.empty())
                v.push_back(0);
            else
                v.push_back(s.top().second-i); //agr bada hai toh uska index j second pe hai usse index ko hatta do distance aa jaayega 
            
            s.push({temperatures[i], i}); //push maaro temp with index 
        }
        
        reverse(v.begin(), v.end());
        
        return v;
        
    }
};