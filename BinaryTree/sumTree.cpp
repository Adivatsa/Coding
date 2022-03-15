class Solution
{
    private:
    pair<bool, int> sumTree(Node* root)
    {
        //base case
        if(root==NULL)
        {
            pair<bool, int> p=make_pair(true,0);
            return p;
        }
        if(root->left==NULL && root->right==NULL)
        {
            pair<bool, int> p=make_pair(true,root->data);
            return p;
        }
        
        
        //left side of tree me jao
        pair<bool, int> leftside= sumTree(root->left);
        
        //right side of tree me jao
        pair<bool, int> rightside= sumTree(root->right);
        
        bool sumofLR=(root->data)==(leftside.second + rightside.second);
        
        pair<bool, int> ans;
        
        if(leftside.first && rightside.first &&sumofLR)
            {
                ans.first=true;
                ans.second=root->data+ leftside.second + rightside.second;
            }
            else
            {
                ans.first=false;
                
            }
            return ans;
        
    }
    public:
    bool isSumTree(Node* root)
    {
            return sumTree(root).first;
    }
};