class Solution
{
    public:
    
    void BSTToDLL(Node<int> *root,Node<int> * &head){
        if( root == NULL){
           return;
    
        }   
       BSTToDLL( root->right,head);
       root->right = head;
       if(head != NULL){
           head->left = NULL;
       }
       head = root;
       BSTToDLL(root->left,head);
    }

 

Node<int>* mergeSortedDLL(Node<int> *head1,Node<int> *head2){
       if(head1 == NULL){
           return head2;
       }
    
       if(head2 == NULL){
           return head1;
       }

    
       Node<int> *head = NULL;
       Node<int> *tail = NULL;
       while(head1!= NULL && head2!=NULL) {
           if(head1->data <head2->data){
               if(head == NULL){
                 head = head1;
                   tail = head1;
                   head1 = head1->right;
               }
               else{
                   tail ->right = head1;
                   head1->left = tail;
                   tail =head1;
                   head1 = head1->right;
               }
           }
           else{
               if(head == NULL){
                 head = head2;
                   tail = head2;
                   head2 = head2->right;
               }
               else{
                   tail ->right = head2;
                   head2->left = tail;
                   tail =head2;
                   head2 = head2->right;
               }
           }
       }

       while(head1 != NULL){
           tail->right = head1;
           head1->left = tail;
           tail = head1;
           head1=head1->right;
    
       }
        while(head2 != NULL){
           tail->right = head2;
           head2->left = tail;
           tail = head2;
           head2=head2->right;
       }
       return head;

}

int countNodes(Node<int> * head){
   Node<int> *temp = head;
   int count =0;

   while(temp!=NULL){
       count ++;
       temp=temp->right;
   }
   return count;
}

Node<int>* sortedDLLToBST(Node<int>* &head,int n){

   if(n<=0 || head == NULL){
       return NULL;
   }
   
   Node<int>* left = sortedDLLToBST(head,n/2);
   Node<int>* root = head;
   root->left = left;
   head = head->right;
   root->right = sortedDLLToBST(head,n-(n/2)-1);
   return root;

}
    void inorder(Node * root, vector<int> &v)
    {
        if(root==NULL)
            return;
        
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    
    void mergeInorder(vector<int> v1, vector<int> v2, vector<int> &ans)
    {
        int i=0;
        int j=0;
        int k=0;
        
        //if both exists
        while(i<v1.size() && j<v2.size())
        {
            if(v1[i]<v2[j])
            {
                ans[k]=v1[i];
                k++;
                i++;
                
            }
            else
            {
                ans[k]=v2[j];
                k++;
                j++;
            }
        }
        while(i<v1.size())//v2 doesn't exist
            {
                ans[k]=v1[i];
                k++;
                i++;
            }
            
        while(j<v2.size())//v1 doesn't exist
            {
                ans[k]=v2[j];
                k++;
                j++;
            }
            
    }
    
    
    vector<int> merge(Node *root1, Node *root2)
    {
        //Method 1: TC=O(m+n)  SC=O(m+n)
        //In this method we will save BST inorder for both the trees
        //Merge both the BST into single vector as total inorder with sort
        //Create BST from inorder
        
        //Step 1: Save inorder for both the trees
        vector<int> v1;
        vector<int>v2;
        inorder(root1,v1);
        inorder(root2,v2);
        
        //Step2: Merge both the inorder
        
         //Merge both the inorder vector of two trees to single vector ans   
        vector<int> ans(v1.size() + v2.size());
        mergeInorder(v1,v2,ans);
        return ans;
        
        //Method 2: Using Linked list traversal
        //step 1: convert both bst into sorted linked list
        //step 2: merge the two linked list to get sorted Linked list
        //step 3: Draw BST from sorted linked list
        
        //TC=O(n+m) sc=O(h1 + h2)
        
        //code 
        
        Node<int> *head1 = NULL;

        BSTToDLL(root1,head1);

        head1->left = NULL;

   

       Node<int> *head2 = NULL;
    
       BSTToDLL(root2,head2);
    
       head1->left = NULL;
    
       
    
       Node<int>* head = mergeSortedDLL(head1,head2);
       Node<int>* tail = head;
       head->left = NULL;
    
       
    
       int count = countNodes(head);
       TreeNode<int>* ansRoot = sortedDLLToBST(head,count);
        return ansRoot;
        
        
        
    }
};