/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        vector<int> temp;
        while(!q.empty())
        {
            Node* curr=q.front();
            q.pop();
            
            if(curr==NULL)
            {
               ans.push_back(temp);
                temp.clear();
                if(!q.empty())
                    q.push(NULL);
            }
            else
            {
                temp.push_back(curr->val);
                //Traverse and just push all the children of parent stored in vector
                for(int i=0; i<curr->children.size(); i++)
                {
                    q.push(curr->children[i]);
                }
            }
        }
        
        return ans;
        
    }
};