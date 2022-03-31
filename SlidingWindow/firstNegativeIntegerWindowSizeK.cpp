vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
                                                 
    /*deque<long long int> d;
    vector<long long> v;
    
    //for first k elements
    for(int i=0; i<K; i++)
    {
        if(A[i]<0)
            d.push_back(i);
    }
    
    //storing ans
    if(d.size()>0)
        v.push_back(A[d.front()]);
    else
        v.push_back(0);
        
    for(int i=K; i<N; i++)
    {
        //removing the elemet
        if(!d.empty() && i-d.front()>=K)
            d.pop_front();
        
        //Adding element
        if(A[i]<0)
            d.push_back(i);
    
    
        //storing ans
        if(d.size()>0)
            v.push_back(A[d.front()]);
        else
            v.push_back(0);
    }
    
    return v;*/
    
    //Using Sliding window 
    //Main approah here is we will take start and end pointer of window 
    //we will make one list or vector to store all negative numbers in that window
    //inside a window first negative will be front of list/vector
    //if window size less than k then add negative to list and increment end pointer
    //when window size hit then just give list front & if empty then output 0
    //Slide the window 
    //for start pointer check if start is equal to list front then delete from list 
    //slide the window
    
    int i=0;//start
    int j=0;//end
    vector<long long >v;
    queue<int>q;
    while(j<N)
    {
        //step 1: if negative push into vector
        if(A[j]<0)
            q.push(A[j]);
            
        //step 2: check if window is small
        if(j-i+1 < K)
            j++;
        else if(j-i+1 == K)//Got window of size k
        {
            //Output the ans
            if(q.size()==0)
                v.push_back(0);
            else
                v.push_back(q.front());
                
            //Slide the window 
            if(A[i]==q.front())
                q.pop();
            i++;
            j++;
                
        }
    }
    return v;
                                                 
 }