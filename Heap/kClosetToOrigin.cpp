  vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        //Sabse phle max heap banna lo kyuki closer wala chahiye
        //push kar do {dist, {x,y}}
        //dist hga always from origin so slope formual x^2+y^2
        //uske baad agr k se bada ho jaaye toh pop kar do
        //last me ek ek karke pop karke vector me daal do
        typedef pair<int,pair<int,int>> p; 
        priority_queue<p> q;
        
        for(int i=0; i<points.size(); i++)
        {
            int x=points[i][0];
            int y=points[i][1];
            
            q.push({x*x+y*y,{x,y}});
            
            if(q.size()>k)
                q.pop();
        }
        vector<vector<int>>ans;
        
        while(!q.empty())
        {
            vector<int> temp;
            temp.push_back(q.top().second.first);
            temp.push_back(q.top().second.second);
            ans.push_back(temp);
            q.pop();
        }
        
        return ans;
    }