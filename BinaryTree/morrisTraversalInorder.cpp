#include<iostream>

using namespace std;

class Node
{

    public:
    int data;
    Node* left;
    Node* right;

    Node(int d)
    {
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

Node* buildBinaryTree(Node* root)
{
    
    int data;
    cout<<" Enter the node"<<endl;
    cin>>data;
    root= new Node(data);

    if(data==-1)
        return NULL;

    cout<<" Enter the left child of "<<data<<endl;
    root->left=buildBinaryTree(root->left);
    cout<<" Enter the right child of "<<data<<endl;
    root->right=buildBinaryTree(root->right);
    return root;
}

//Traverse inorder using Morris with Sc=O(1) and TC=O(n)
void morrisTraversal(Node* root)
{
    //Alg 
    /*
        Initialize current as root 
        While current is not NULL
            If the current does not have left child
                a) Print current’s data
                b) Go to the right, i.e., current = current->right
            Else
                a) Find rightmost node in current left subtree OR node whose right child == current.
                If we found right child == current
                    a) Update the right child as NULL of that node whose right child is current
                    b) Print current’s data
                    c) Go to the right, i.e. current = current->right
                Else
                    a) Make current as the right child of that rightmost node we found; and 
                    b) Go to this left child, i.e., current = current->left
    */

   Node* curr=root;
   while(curr!=NULL)
   {
       if(curr->left==NULL)
       {
           cout<< curr->data<<" ";
           curr=curr->right;
       }
       else
       {
           //predessaor find kar lo
           Node* pred=curr->left;
           while(pred->right!=NULL && pred->right!=curr)
                pred=pred->right;

            //create a link to curr data
            if(pred->right==NULL)
            {
                pred->right=curr;
                curr=curr->left;
            }
            else//this means links already there broke them 
            {
                pred->right=NULL;
                cout<<curr->data<<" ";
                curr=curr->right;
            }
       }
   }
}

int main()
{

    //creation of root node 
    Node* root=NULL;
    root= buildBinaryTree(root);

    morrisTraversal(root);
    return 0;
}