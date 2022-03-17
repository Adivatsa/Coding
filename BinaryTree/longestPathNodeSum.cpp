class Solution
{
public:
    
    void calculate(Node* root, int len , int &maxlen, int sum, int &maxsum)//reference isliye update show hga
    {
        if (root==NULL)//iska matlb hum niche aa gye ya koi node he nai hai
        {
            if(len>maxlen) //ish case me len humari maxlen se jyada hai tb maxsum update karo
            {
                maxlen=len;//len ko update maar do ye longest path hga
                maxsum=sum;
                
            }
            else if(len==maxlen)//iska matlb length same hai toh maxsum update kar do jo bada hga ushe
                maxsum=max(sum,maxsum);
                
            return;//agr koi node nai toh return ho jao
        }
        
        //sum nekal lo
        sum=sum+root->data;
        
        //left me jao length toh ek increase hga
        calculate(root->left, len+1,maxlen,sum,maxsum);
        //right me chale jao length ko badha lo 
        calculate(root->right, len+1,maxlen,sum,maxsum);
        
        
        
    }
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        //yaha pe upar se niche aao ek length , max length, sum aur maxsum rakh lo
        //check kar lena agr len jayda hai tb maxsum ko update maar do aur max len ko bhi
        
        int len=0;//ye length ko track karega jaise start me root ka 0 hga
        int maxlen=0;//ye btayega ki max len kya hai agr len jyada hga toh maxlen ko update kar do
        //max len me hamesha maximum length possible store hga 
        int sum=0;
        int maxsum=INT_MIN;
        
        //call for calculate the sum of node for longest path
        calculate(root, len,maxlen, sum,maxsum);
        
        return maxsum;
    }
};