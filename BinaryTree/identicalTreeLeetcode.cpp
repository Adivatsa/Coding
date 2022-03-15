class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
       //Base case 
        if(p==NULL && q==NULL)
            return true;
        if(p==NULL && q!=NULL)
            return false;
        if(p!=NULL && q==NULL)
            return false;
        
        //jao left side check karo ek ek karke saare elements compare maaro
        bool leftdata= isSameTree(p->left,q->left);
        
        //jao right side check karo ek ek karke saare elements compare maaro
        bool rightdata= isSameTree(p->right,q->right);
        
        //check kar lo data ek baar
        
        bool checkData=(p->val==q->val) ;
        
        //agar sb true hai toh return true warna false
        if(leftdata && rightdata && checkData)
            return true;
        else
            return false;
        
        
    }
};