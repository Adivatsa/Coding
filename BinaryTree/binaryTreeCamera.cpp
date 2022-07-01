class Solution {
public:
    int camera=0;
    int minCameraCover(TreeNode* root) {
        
        if(countcamera(root)=="Require")
            camera++;
        return camera;
        
    }
    //similar to corona vaccine problem gfg
    //No means it has been covered with another camera
    //Reuire means camera is required
    //Need means we have camera can cover
    string countcamera(TreeNode* root)
    {
        if(root==NULL)
            return "No";
        
        string l=countcamera(root->left);
        string r=countcamera(root->right);
        
        if(l=="Require" || r=="Require")
        {
            camera++;
            return "Need";
        }
        else if(l=="Need" || r=="Need")
            return "No";
        else
            return "Require";
    }
};