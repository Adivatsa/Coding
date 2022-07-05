     queue<int>q;
        int n=arr.size();
        q.push(start);
        while(!q.empty()){
            int point=q.front();
            q.pop();
            if(point-arr[point]>=0){
                if(arr[point-arr[point]]==0){
                    return true;
                }
                else if(arr[point-arr[point]]>0){
                    q.push(point-arr[point]);
                }
            }
            if(point+arr[point]<n){
                if(arr[point+arr[point]]==0){
                    return true;
                }
                else if(arr[point+arr[point]]>0){
                    q.push(point+arr[point]);
                }
            }
            arr[point]=-1;
        }
        return false;

            bool canReach(vector<int>& arr, int start) {
        
        //Use BFS traversal to keep track of the elements
//         queue<int> q;
//         q.push(start);
//        int n=arr.size();
        
//         while(!q.empty());
//         {
            
//             //take the index
//                 int i=q.front();
//                 q.pop();
                
//                 //traverse into two direction left or right
//                 //for left i-arr[i]
//                 if(i-arr[i]>=0)
//                 {
//                     //check for eqaulity to 0
//                     if(arr[i-arr[i]]==0)
//                     {
//                         return true;
//                     }
                        
//                     else if(arr[i-arr[i]]>0)//it means it ahs been not visited earlier
//                     {
//                         q.push(i-arr[i]);
//                     }    
//                 }
            
                
//                 //for right side iterate in the fprm i+ arr[i]
//                 if(i+arr[i]<n)
//                 {
//                     //check for eqaulity to 0
//                     if(arr[i+arr[i]]==0)
//                     {
//                         return true;
//                     }
                        
//                     else if(arr[i+arr[i]]>0)//it means it ahs been not visited earlier
//                     {
//                         q.push(i+arr[i]);
//                     }
//                 }
//                 //to overcome from repeated elements put -1 at that position
//                 arr[i]=-1;  
//         }
//         return false;
        
    }