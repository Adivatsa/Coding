#include<iostream>
#include<queue>
#include<stack>

using namespace std;

//creation of node class

class node
{
    public:
    int data;
    node* left;
    node*right;

    //constructor
    node(int d)
    {

        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

node* buildBinaryTree(node* root)
{
    
    int data;
    cout<<" Enter the node"<<endl;
    cin>>data;
    root= new node(data);

    if(data==-1)
        return NULL;

    cout<<" Enter the left child of "<<data<<endl;
    root->left=buildBinaryTree(root->left);
    cout<<" Enter the right child of "<<data<<endl;
    root->right=buildBinaryTree(root->right);
    return root;
}

void levelOrderTraversal(node* root)
{
    //sabse phle queue banna ke usme root push maar do
    queue<node*> q;
    q.push(root);

    //check karo jab tk queue empty na ho jaaye
    while(!q.empty())
    {
        //queue ke front ko store kar lo phir check karo left or right child ke liye
        node* temp=q.front();
        //pop maar do ush element ko ab 
        q.pop();
        cout<<temp->data<<" ";

        //check kar lo left or right child ke liye

        if(temp->left!=NULL)
            {
                //quueue me push maar do
                q.push(temp->left);
            } 
        if(temp->right!=NULL)
            {
                //quueue me push maar do
                q.push(temp->right);
            } 
    }
    cout<<endl;
}


//level order using seperator

void levelOrderTraversalSeperator(node* root)
{
    //sabse phle queue banna ke usme root push maar do
    queue<node*> q;
    q.push(root);
    q.push(NULL); //seperator ke liye null push maar do

    //check karo jab tk queue empty na ho jaaye
    while(!q.empty())
    {
        //queue ke front ko store kar lo phir check karo left or right child ke liye
        node* temp=q.front();
        //pop maar do ush element ko ab 
        q.pop();
        if(temp==NULL)
        {
            cout<<endl;
            if(!q.empty())//check kar lo for next level agr empty nai hai toh
                q.push(NULL);
        }
        else{
                cout<<temp->data<<" ";

            //check kar lo left or right child ke liye

            if(temp->left!=NULL)
                {
                    //quueue me push maar do
                    q.push(temp->left);
                } 
            if(temp->right!=NULL)
                {
                    //quueue me push maar do
                    q.push(temp->right);    
                }
            } 
    }
}


void reverselevelOrderTraversal(node* root)
{
    //sabse phle queue banna ke usme root push maar do
    queue<node*> q;
    stack<node*>s ;
    q.push(root);

    //check karo jab tk queue empty na ho jaaye
    while(!q.empty())
    {
        //queue ke front ko store kar lo phir check karo left or right child ke liye
        node* temp=q.front();
        //pop maar do ush element ko ab 
        q.pop();
        s.push(temp);

        //

        //check kar lo left or right child ke liye

        if(temp->left!=NULL)
            {
                //quueue me push maar do
                q.push(temp->left);
            } 
        if(temp->right!=NULL)
            {
                //quueue me push maar do
                q.push(temp->right);
            } 
    }
    while(!s.empty())
    {
        node* temp=s.top();
        s.pop();
        cout<<temp->data<<" ";
    }
    cout<<endl;
}

void reverselevelOrderTraversalSeperator(node* root)
{
    //sabse phle queue banna ke usme root push maar do
    queue<node*> q;
    stack<node*>s ;
    q.push(root);
    q.push(NULL); //seperator ke liye null push maar do

    //check karo jab tk queue empty na ho jaaye
    while(!q.empty())
    {
        //queue ke front ko store kar lo phir check karo left or right child ke liye
        node* temp=q.front();
        //pop maar do ush element ko ab 
        q.pop();
        
        
        if(temp==NULL)
        {
            //cout<<endl;
            s.push(NULL);
            if(!q.empty())//check kar lo for next level agr empty nai hai toh
                q.push(NULL);
        }
        else{
                s.push(temp);
                //cout<<temp->data<<" ";

            //check kar lo left or right child ke liye

            if(temp->left!=NULL)
                {
                    //quueue me push maar do
                    q.push(temp->left);
                } 
            if(temp->right!=NULL)
                {
                    //quueue me push maar do
                    q.push(temp->right);    
                }
            } 
    }
    while(!s.empty())
    {
        node* temp=s.top();
        s.pop();
        if(temp==NULL)
        {
            cout<<endl;

        }
        else
        {
            cout<<temp->data<<" ";
        }
        
    }
}


void inorder(node* root)
{
    if(root==NULL)
        return;
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void inorderiterative(node* root)
{
    stack <node*>s;
    node* curr=root;
    while(curr!=NULL || !s.empty())
    {
        while(curr!=NULL)
        {
            s.push(curr);
            curr=curr->left;
        }

        //null mil gya 
        curr=s.top();
        s.pop();
        cout<<curr->data<<" ";
        curr=curr->right;
    }
}

void postorder(node* root)
{
    if(root==NULL)
        return;
    
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
    
}

void postorderiterative(node* root)
{
    stack<node*>s1;
    stack<node*> s2;
    node* curr=root;
    s1.push(curr);

    while(!s1.empty())
    {
        curr=s1.top();
        s1.pop();
        s2.push(curr);
        if(curr->left!=NULL)
            s1.push(curr->left);
        if(curr->right!=NULL)
            s1.push(curr->right);
    }
    while(!s2.empty())
    {
        curr=s2.top();
        s2.pop();
        cout<<curr->data<<" ";
    }
}

void preorder(node* root)
{
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
    
}

void preorderiterative(node* root)
{
    stack<node* > s;
    node* curr=root;
    s.push(curr);
    while(!s.empty())
    {
        curr=s.top();
        s.pop();
        cout<<curr->data<<" ";
        if(curr->right!=NULL)
            s.push(curr->right);
        if(curr->left!=NULL)
            s.push(curr->left);
    }
}

int sizeofTree(node* root)
{
    
    if(root!=NULL)
    {
        return (1+sizeofTree(root->left)+sizeofTree(root->right));
        
    }
    else
        return 0;
    //return root?(1+sizeofTree(root->left) + sizeofTree(root->right)):0;
}
int main()
{

    //creation of root node 
    node* root=NULL;
    root= buildBinaryTree(root);

    /*
    //level order travesal
    cout<<" Level order traversal is "<<endl;
    levelOrderTraversal(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    levelOrderTraversalSeperator(root);
    reverselevelOrderTraversal(root);
    reverselevelOrderTraversalSeperator(root);
    */
   //inorder(root);
   //inorderiterative(root);
    //postorder(root);
    //postorderiterative(root);
    //preorder(root);
    preorderiterative(root);
    int size=sizeofTree(root);
    cout<<endl<<"Size of Tree is "<<size<<endl;
    
    return 0;
}