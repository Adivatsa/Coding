		string FirstNonRepeating(string A){
		    
		    
		    string result="";
		    unordered_map<char, int> m;
		    queue<char> q;
		    
		    for(int i=0; i<A.length(); i++)
		    {
		        char ch=A[i];
		        
		        //count badha lo
		        m[ch]++;
		        
		        //queueu me push maaro
		        q.push(ch);
		        
		        //condition check karo
		        //agar repaeting character hga toh uska count 1 se jatda hga to pop kar do
		        //otherwise ans me store kara lo break karke next character pe chale jao
		        //if queue empty ho jaaye toh # daal do
		        while(!q.empty())
		        {
		            if(m[q.front()]>1)
		                q.pop();
		            else
		            {
		                result.push_back(q.front());
		                break;
		            }
		                
		        }
		        
		        //empty wala condition check karo
		        if(q.empty())
		            result.push_back('#');
		    }
		   return result;
		}