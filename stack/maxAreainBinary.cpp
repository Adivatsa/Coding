    int getMaxArea(vector<int> arr, int n)
    {
        //Store the index of nearest smaller to left and to right
        //Subtract between both and multiply with height
        stack<pair<int ,int>> s;
        vector<int> left;
        vector<int> right;
        
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
        
        int ans=0;
        for(int i=0; i<n; i++)
        {
            ans=max(ans,(right[i]-left[i]-1)*arr[i]);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        //Apply area of histogram to each row
        //if any row element found as 0 then put 0
        //otherwise going down if u encounter 1 then add to previous abd call maximum 
        //histogram function and store ans
        //for each row calcuate and and return
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=0;
        vector<int> heights(m,0);
        
        for(int j=0;j<m;j++)
        {
            if(matrix[0][j]=='0')
                heights[j]=0;
            else if(matrix[0][j]=='1')
                heights[j]=1;
        }
        
        ans=max(ans,getMaxArea(heights,m));
        
        for(int i=1; i<n;i++)
        {
            for(int j=0; j<m; j++)
            {
                if(matrix[i][j]=='0')
                    heights[j]=0;
                else if(matrix[i][j]=='1')
                    heights[j]=heights[j]+1;
            }
            ans=max(ans,getMaxArea(heights,m) );
        }
        return ans; 
    }