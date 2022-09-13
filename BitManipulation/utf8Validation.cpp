    bool validUtf8(vector<int>& data) {
        
        //UTF* Representation of integer from 1 to 4 bytes
        //1st byte 0.......
        //2 bytes 110..... 10......
        //3 bytes 1110.... 10...... 10......
        //4 bytes 11110... 10...... 10...... 10......
        //All these are valid UTF8 conversion
        
        //to get one byte shift seven times and check if bit is 0 
        //To get 2 byte shift 5 bits and check for 110 and also 10
        
        int rbytes=0;
        for(auto b: data)
        {
           if(rbytes==0)
           {
              if(b>>7==0)
                  rbytes=0;//It is valid as no remmaining bytes left
               else if(b>>5==0b110)
                   rbytes=1;//It is valid and one byte is remaining
               else if(b>>4==0b1110)
                   rbytes=2;//It is valid and two byte is remaining
               else if(b>>3==0b11110)
                   rbytes=3;//It is valid and two byte is remaining
               else
                   return false;
           }
            else//checking remaing bytes with 10......
            {
                if(b>>6==0b10)
                    rbytes--;
                else
                    return false;
            }
        }
        if(rbytes==0)
            return true;
        else
            return false;
        
        
    }