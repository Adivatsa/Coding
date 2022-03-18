void makeMap(int in[], map<int,int> &searchIndex, int n)
    {
        for(int i=0; i<n; i++)
        {
            searchIndex[in[i]]=i;
        }
    }

Node* buildTreeIP(int in[],int post[], int n, int &postIndex, int instart, int inend, map<int,int> &searchIndex)
    {
        //Base case
        //Base case yeh ho skata hai jab postindex array se bahr chala jaaye
        //inorder me start index end se aage chala jaaye
        if(postIndex<0 || instart>inend)
        {
            return NULL;
        }
        
        //Element nekal ke naya node banna do
        int element=post[postIndex--];
        //postIndex ko piche bhej do
      
        //naya node bana do
        Node* root= new Node(element);
        
        //khojo ish element ko map e kaha pe 
        int position=searchIndex[element];
        //int position= positionSearch(in,pre,n,element); O(n^2)
        
        //postorder traversal hai toh last node print ke baad right tree then left subtree LRN
        //right wala hga inorder me position+1 to n-1
        //index kam ho ke phle right pe aayega phir left (yaad karo postorder)
        root->right= buildTreeIP(in, post, n, postIndex, position+1,inend,searchIndex);
        //phle left wala hga inorder me 0 to postion-1
        root->left= buildTreeIP(in, post, n, postIndex, instart, position-1, searchIndex);
        
        
        return root;
    }
//Function to return a tree created from postorder and inoreder traversals.
Node *buildTree(int in[], int post[], int n) {
    
        //postorder btata hai root kaun sa hga piche se and inorder btata hai left or right iske kya hnge
        //iska logic yeh rehta hai postorder ka last element ko root banna lo
        //ush node ko inorder me search karo aur ush element ke left me saare tree ke left side
        //jo bhi elements ke right side hnge wo tree ke right part
        //so left ka element hga 0 to index-1 and right hga index+1 to n in inorder
        
        //complexity ko O(n^2) se kam karane ke liye position function ke jgh ek baar maap me sab inorder daal lo
        //ek element daalne ka O(logn) so O(nlogn) for all them in map phir direct preorder wale index ko inorder me search krne me 
        
        //map me daal lo saare inorder ko with key as data of inorder and value as position
        int postIndex=n-1;
        map<int, int> searchIndex;
        makeMap(in,searchIndex,n);
        
        Node* ans=buildTreeIP(in , post , n , postIndex , 0 , n-1 , searchIndex);
        return ans;
}
