class BSTIterator {
public:
    //Stack for storing the left elements
    stack<TreeNode* > s;
    
    //constructor to push all the elements
    BSTIterator(TreeNode* root) {
        pushleft(root);
        
    }
    
    int next() {
        
        //next element will always at the top of stack
        TreeNode* temp=s.top();
        s.pop();
        
        //Check if left is present push that to stack and all its left 
        if(temp->right!=NULL)
            pushleft(temp->right);
        
        //return the element
        return temp->val;
    }
    
    bool hasNext() {
        //if stack is empty then sure next will present
        if(!s.empty())
            return true;
        else
            return false;
    }
    
    void pushleft(TreeNode* root)
    {
        //push it should not become null
        while(root!=NULL)
        {
          s.push(root);
            root=root->left;
        }
    }
};