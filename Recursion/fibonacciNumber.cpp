//     int t[31];
//     int fibb(int n)
//     {
//         if(n<=1)
//             return n;
        
//         if(t[n]!=-1)
//             return t[n];
//         return t[n]=fibb(n-1)+fibb(n-2);
//     }
    int fib(int n) {
        
//             Method 1: Using Recursion
                
//             if(n<=1)
//                 return  n;
            
//         return fib(n-1)+fib(n-2);
        
//         Method 2: Using Dp
//         memset(t,-1,sizeof(t));
//         return fibb(n);
        
//         //Method 3: Using O(1) Space and Time
            
//             if(n<=1)
//                 return n;
            
//             int num1=0;
//             int num2=1;
//             int sum=num1+num2;

//             for(int i=2; i<n; i++)
//             {
//                num1=num2;
//                 num2=sum;
//                 sum=num1+num2;
//             }
        
//         return sum;
//     }