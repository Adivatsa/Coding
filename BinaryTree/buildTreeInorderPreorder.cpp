class Solution{
    public:
    
    /* 
    //using this complexity as O(n^2) as n for traverse n node and n for find position in inorder
    int positionSearch(int in[],int pre[],int n ,int element)
    {
        for(int i=0; i<n; i++)
        {
            if(element==in[i])
                return i;
        }
        return -1;
    }
    */
    void makeMap(int in[], map<int,int> &searchIndex, int n)
    {
        for(int i=0; i<n; i++)
        {
            searchIndex[in[i]]=i;
        }
    }
    
    Node* buildTreeIP(int in[],int pre[], int n, int &preIndex, int instart, int inend,map<int,int> &searchIndex)
    {
        //Base case
        //Base case yeh ho skata hai jab preindex array se bahr chala jaaye
        //inorder me start index end se aage chala jaaye
        if(preIndex>=n || instart>inend)
        {
            return NULL;
        }
        
        //Element nekal ke naya node banna do
        int element=pre[preIndex++];
        //preIndex ko aage bhej do
      
        //naya node bana do
        Node* root= new Node(element);
        
        //khojo ish element ko map e kaha pe 
        int position=searchIndex[element];
        //int position= positionSearch(in,pre,n,element); O(n^2)
        
        //preorder traversal hai toh phle node print ke baad left tree then right subtree
        //phle left wala hga inorder me 0 to postion-1
        root->left= buildTreeIP(in, pre, n, preIndex, instart, position-1, searchIndex);
        //right wala hga inorder me position+1 to n-1
        root->right= buildTreeIP(in, pre, n, preIndex, position+1,inend,searchIndex);
        
        return root;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        //preorder btata hai root kaun sa hga inorder btata hai left or right iske kya hnge
        //iska logic yeh rehta hai preorder ka first element ko root banna lo
        //ush node ko inorder me search karo aur ush element ke left me saare tree ke left side
        //jo bhi elements ke right side hnge wo tree ke right part
        //so left ka element hga 0 to index-1 and right hga index+1 to n in inorder
        
        //complexity ko O(n^2) se kam karane ke liye position function ke jgh ek baar maap me sab inorder daal lo
        //ek element daalne ka O(logn) so O(nlogn) for all them in map phir direct preorder wale index ko inorder me search krne me 
        
        //map me daal lo saare inorder ko with key as data of inorder and value as position
        int preIndex=0;
        map<int, int> searchIndex;
        makeMap(in,searchIndex,n);
        
        Node* ans=buildTreeIP(in , pre , n , preIndex , 0 , n-1 , searchIndex);
        return ans;
    }
};