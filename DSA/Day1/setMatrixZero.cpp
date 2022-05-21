void setZeroes(vector<vector<int>>& matrix) {
        
        //Find out no of rows
        int r= matrix.size();
        
        //Find out no of column
        int c=matrix[0].size();
        
        //This solution traverse from reverse direction
        
        int fcol=1;
        
        //Traverse over entire matrix
        for(int i=0; i<r; i++)
        {
            //check for first column first element
            if(matrix[i][0]==0)
                fcol=0;
            //Traverse over entire row
            for(int j=1; j<c; j++)
                if(matrix[i][j]==0)
                {
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
        }
        
        //start filling if corresponding row and column are zero then set as zero
        //start from last postion
        for(int i=r-1; i>=0; i--)
        {
            for(int j=c-1; j>=1; j--)
            {
                if(matrix[i][0]==0 || matrix[0][j]==0)
                    matrix[i][j]=0;
            }
            if(fcol==0)
                matrix[i][0]=0;
        }
        

        
//         //Traverse in front direction
//         bool rzero=false;
//         bool czero=false;
            
//             for(int i=0; i<r; i++)
//             {
//                 for(int j=0; j<c; j++)
//                 {
//                     if(matrix[i][j]==0)
//                     {
//                         if(i==0)//pehla row me zero mila hai [[isme mila hai], [ ],[ ]]
//                             rzero=true;
//                         if(j==0)//phla column me mila hai zero
//                             czero=true;
//                         matrix[i][0]=0; //left side mark ho gya
//                         matrix[0][j]=0; //Upar mark ho gya hai
                    
//                     }
//                 }
//             }
        
//         for(int i=1; i<r; i++)
//             {
//                 for(int j=1; j<c; j++)
//                 {
//                     if(matrix[i][0]==0 || matrix[0][j]==0) //iska matlb ki row side ya clm 0 mark h
//                     {
//                         matrix[i][j]=0;
                    
//                     }
//                 }
//             }
        
//         //now check first row true hai kya agr hga toh saare elemets ko zero maar do
//         if(rzero==true)
//         {
//             for(int i=0; i<c; i++)
//                 matrix[0][i]=0;
//         }
        
//         //check for first column if zero mark all zero
//         if(czero==true)
//         {
//             for(int i=0; i<r; i++)
//                 matrix[i][0]=0;
//         }
        
    }