    bool checkValidString(string s) {
        
        stack<int> open; //Store open bracket position
        stack<int> star; //store star position
        
        //traverse over string s and check if open bracket satck is empty then return true
        //otherwise check to compensate open bracket with star bracket
        for(int i=0; i<s.length(); i++)
        {
            char ch=s[i];
            if(ch=='(' )
                open.push(i);
            else if(ch=='*')
                star.push(i);
            else if(ch==')')
            {
                //for closing bracket check two conditins
                
                //first it has some opening bracket then pop it 
                //second if there is no any open bracket check if there are any star present
                //otherwise false
                if(!open.empty())
                    open.pop();
                else if(!star.empty())
                    star.pop();
                else
                    return false;
            }
        }
        
        //Iterate over open bracket stack if it is not empty
        //check for star which shuld has value greater than open bracket value then pop 
        //otherwise return false;
        
        while(!open.empty())
        {
            //check if star stack is empty then  we can not compensate for open bracket then return false
            //otherwise check if star stack top should be greater value to compensate the open bracket
            //otherwise false
            
            if(star.empty())
                return false;
            else if(open.top()<star.top())
            {
                star.pop();
                open.pop();
            }
            else
                return false;
        }
        return true;
        
    }