 
    long long toh(int N, int from, int to, int aux) {
        
        if(N>0)
        {
            if(N==1)
            {
                //When only one disk is present
                cout<<"move disk "<<N<<" from rod "<<from<<" to rod "<<to<<endl;
                return 1;
            }
            //format is source, destination, temperoray
            //move n-1 disk from source to temp    
            toh(N-1,from,aux,to);
            //move last disk from source to destination
            cout<<"move disk "<<N<<" from rod "<<from<<" to rod "<<to<<endl;
            //move n-1 disk from temp to destintsion
            toh(N-1,aux,to,from);
        }
        //total operations are eqaul to (2^n-1)
        return pow(2,N)-1;
    }