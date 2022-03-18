class Solution{
  public:
  
  pair<int, int> maxSum(Node* root)
  {
      if(root==NULL)//root null hai tb max sum include, exclude tht node will be zero
      {
          pair<int,int> p=make_pair(0,0);
          return p;
          
      }
    
    //left side jao aur maxsum nekal ke le aao first me include root node and second me not include root node karke
    pair<int, int> leftside=maxSum(root->left);
    //right side se max sum le ka r aao irst me include root node and second me not include root node karke
    pair<int, int> rightside=maxSum(root->right);
    
    pair<int, int> ans;
    
    //Isme hum ush root node ko include ka rhe hai so next wale ko consider nai karna hai so next wale ke second me hga
    ans.first=root->data+ leftside.second+ rightside.second;
    //Isme ush root node ko consider nai kar rhe hai toh jo max hga left ke first ya second se and for same right
    ans.second=max(leftside.first,leftside.second) + max(rightside.first,rightside.second);
    
    return ans;
      
  }
    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) 
    {
        //approach yeh kehta hai ki ek pair banna lo 
        //jaha pe first wala jo hai waha pe ush root node ko consider karna hai phir sum nekal lo
        //second sum nekalo jaha pe ush root node ko consider nai krna hai phir sum nekalo
        pair<int, int>p=maxSum(root);//pehla will include that node , second will exclude that node
        return max(p.first, p.second);
    }
};