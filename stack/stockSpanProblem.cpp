    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       //find nearest greater to left index
       //subtract the right stored index from index;
       stack<pair<int,int>> s;
       vector<int> v;
       
       for(int i=0; i<n ;i++)
       {
           int j=i;
           if(s.empty())
                v.push_back(-1);
            else if((!s.empty())&& s.top().first > price[i])
            {
                v.push_back(s.top().second);
            }
            else if((!s.empty())&& (s.top().first <= price[i]))
            {
                while((!s.empty())&& s.top().first <= price[i])
                        s.pop();
            
                if(s.empty())
                    v.push_back(-1);
                else
                v.push_back(s.top().second);
            }
       
            
            s.push({price[i], i});
       }
       
       for(int i=0; i<n; i++)
       {
           v[i]=i-v[i];
       }
       return v;
    }