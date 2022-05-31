long long kthsmall(long long A[], long long n, long long k)
    {
        priority_queue<long long>q;
        for(int i=0; i<n; i++)
        {
            q.push(A[i]);
            if(q.size()>k)
                q.pop();
        }
        return q.top();
    }
    long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2)
    {
        //find the k1th smallest and k2th smallest element
        //after that traverse and find if greater than k1 and small than k2
        //k1th smallst using max heap with size k
        
        long long f=kthsmall(A,N,K1);
        long long l=kthsmall(A,N,K2);
        long long ans=0;
        
        for(int i=0; i<N; i++)
        {
            if(A[i]>f && A[i]<l)
                ans+=A[i];
        }
        return ans;
    }