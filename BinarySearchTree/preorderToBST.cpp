class Solution {
public:
    
//     TreeNode* constructBST(TreeNode* &root, int d)
//     {
//         if(root==NULL)
//         {
//             root= new TreeNode(d);
//             return root;
//         }

//         if(d > root->val)
//             root->right= constructBST(root->right,d);
//         else
//             root->left= constructBST(root->left,d);

//         return root;
//     }
    
    
//     TreeNode* constructBST(vector<int>& preorder, int s, int e)
//     {
//        if(s>e)
//            return NULL;
        
//         int mid= (s+(e-s)/2);
//        TreeNode* root= new TreeNode(preorder[mid]); 
        
//         root->left= constructBST(preorder,s,mid-1);
//         root->right=constructBST(preorder,mid+1,e);
        
//         return root;
    
//     }
    
    TreeNode* constructTree(vector<int>& preorder, int mini, int maxi, int &i)
    {

        //agr i ka value array of preorder se bahr chala jaaye
        if(i>=preorder.size())
            return NULL;
        //Check if the node it is range or not
        if(preorder[i]<mini || preorder[i]>maxi)
            return NULL;
        
        //Otherwise create node with increment in i
        TreeNode* root= new TreeNode(preorder[i]);
        i++;
        //left side 
        root->left=constructTree(preorder,mini,root->val,i);
        //right side
        root->right=constructTree(preorder,root->val,maxi,i);
        
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
    
        
//         //Method 1: if root is null then create a node 
//         //after that for each value just compare with root if it is smaller then insert in left                 otherwise right
//         //TC= O(n^2)
       
//         TreeNode* root=NULL;

//         for (int i=0; i<preorder.size(); i++)
//         {
//             constructBST(root,preorder[i]);
//         }
//         return root;
        
            
//         //Method 2: store the preorder traversal 
//         //sort the preorder to get inorder
//         //construct tree from in order
//         //take out the mid as root node and left part as left subtree
//         //and right part is right subtree of node
           //TC=O(nlogn) for sorting
        
//         sort(preorder.begin(), preorder.end());
//         return constructBST(preorder,0,preorder.size());
        
        //Method 3:By using range of nodes
        //Root node range will be min as -infinity and max as +infinity
        //Now if it is lies between the range then ok otherwise return null
        //in left side min will be -infinty and max will be root ka data
        //in right side max will be +infinty and min will be root ka data
        
        int mini=INT_MIN;
        int maxi=INT_MAX;
        int i=0;
        return constructTree(preorder,mini,maxi,i);
        
    }
};