class Solution {
public:
    class comparator{
        public:
        bool operator()(pair<int,int> a, pair<int,int> b)
        {
            //first condition is min heap and second is decreasing order
            if(a.first!=b.first){
                return a.first>b.first;
            }    
            return a.second<b.second;
        }
        
    };
     
    vector<int> frequencySort(vector<int>& nums) {
        
        //We will Store frequency of elemeys in map
        //According to question in heap we will create and add the elemets with key as count of element
        //create a comparator class for in which if same count then decreasing order
        //return the ans vector
        
        
        unordered_map<int,int> m;
        
        for(int i=0; i<nums.size(); i++)
        {
                m[nums[i]]++;
        }
       
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, comparator> q;
        
        for(auto i=m.begin(); i!=m.end(); i++)
        {
            q.push({i->second,i->first});
        }
        vector<int> ans;
        while(!q.empty())
        {
            
            int x=q.top().first;
            while(x>0)
            {
                ans.push_back(q.top().second);
                x--;
            }
            q.pop();
        }
        return ans;
        
    }