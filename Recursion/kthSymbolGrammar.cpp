    int kthGrammar(int n, int k) {
        
        //Base case 
        if(n==1 && k==1)
            return 0;
        
        //0        n=0
        //01       n=1
        //0110     n=2
        //01101001 n=3
        //In this right half is just reverse of previous given and left part is same
        //One thing evey time grammar increases with size in multiply by 2
        
        //Find mid for given n
        //n=3 01101001
        int mid= pow(2,n-1)/2;
        
        //for left half part it is same and right half just reverse of previous one
        if(k<=mid)
            return kthGrammar(n-1,k);
        else
            return !kthGrammar(n-1,k-mid);
        
    }