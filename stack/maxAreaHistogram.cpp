//Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        //Store the index of nearest smaller to left and to right
        //Subtract between both and multiply with height
        stack<pair<long long ,long long>> s;
        vector<long long> left;
        vector<long long> right;
        
        for(int i=0; i<n; i++)
        {
            if(s.empty())
                left.push_back(-1);
            else if(s.size()>0 && s.top().first<arr[i])
                left.push_back(s.top().second);
            else if(s.size()>0 && s.top().first>=arr[i])
            {
                while(s.size()>0 && s.top().first>=arr[i])
                    s.pop();
                if(s.empty())
                   left.push_back(-1);
                  else
                    left.push_back(s.top().second);
            }
            s.push({arr[i],i});
        }
        while(!s.empty())
        {
            s.pop();
        }
        for(int i=n-1; i>=0; i--)
        {
            if(s.empty())
                right.push_back(n);
            else if(s.size()>0 && s.top().first<arr[i])
                right.push_back(s.top().second);
            else if(s.size()>0 && s.top().first>=arr[i])
            {
                while(s.size()>0 && s.top().first>=arr[i])
                    s.pop();
                if(s.empty())
                   right.push_back(n);
                  else
                    right.push_back(s.top().second);
            }
            s.push({arr[i],i});
        }
        reverse(right.begin(),right.end());
        
        long long ans=0;
        for(int i=0; i<n; i++)
        {
            ans=max(ans,(right[i]-left[i]-1)*arr[i]);
        }
        return ans;
    }