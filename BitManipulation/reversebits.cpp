    uint32_t reverseBits(uint32_t n) {
        uint32_t ans=0;
        
        int steps=31;
        while(steps--)
        {
            //check last bit and perform OR operation with ans
            ans= ans| (n&1);
            //perform left and right shift to ans and n
            ans<<=1;
            n>>=1;
        }
        //for last 32 bit perform
        //Don't do left snd right shift as it will call overflow
        return ans|(n&1);
    }