vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    //Sort both the array in increasing order
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());


    //create max heap with {sum, {i,j}}
    int n=A.size();
    priority_queue<pair<int,pair<int,int>>> q;
    //Insert last element to it and its position {i,j} to set
    q.push({A[n-1]+B[n-1],{n-1,n-1}});
    set<pair<int,int>> s;
    s.insert({n-1,n-1});
    //Ans vector
    vector<int> ans;
    

    for(int k=0; k<C; k++)
    {
        pair<int,pair<int,int>> p=q.top();
        q.pop();
        ans.push_back(p.first);
        int i=p.second.first;
        int j=p.second.second;
        int n=A.size();

    //Check to its adjacent of {i,j} as {i-1,j} and {i,j-1}
        if(i >0 && s.count({i-1,j})==0)
        {
            q.push({A[i-1]+B[j],{ i-1, j}});
            s.insert({i-1,j});
        }
        if(j >0 && s.count({i,j-1})==0)
        {
            q.push({A[i]+B[j-1], {i, j-1}});
            s.insert({i, j-1});
        }
    }
    return ans;
}