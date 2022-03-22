#include<iostream>
#include<queue>

using namespace std;


class node
{
    public:
    int data;
    node* left;
    node* right;

    node(int d)
    {
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};


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


node* makeBST(node* root, int data)
{
    if(root==NULL)
    {
        //this will be first root node
        root= new node(data);
        return root;
    }

    //checl lar lo left ya right
    //if data is freater than root ka data then right otherwise left side
    if(root->data > data)
    {
        //left part me 
        root->left=makeBST(root->left, data);
    }
    else
        root->right=makeBST(root->right,data);

    return root;
}
void takeinput(node* & root)
{
    int data;
    cin>>data;

    while(data!=-1)
    {
        root=makeBST(root,data);
        cin>>data;
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

void preorder(node* root)
{
    if(root==NULL)
        return;
    
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root)
{
    if(root==NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";

}

node* minimumValue(node* root)
{
    //Minimum value hamesha BST ke sabsde left side hga
    node* curr= root;

    //Ek baar check kar lo node ka left null nai hona chahiye
    while(curr->left!=NULL)
    {
            curr=curr->left;
    }
    return curr;
}

node* maximumValue(node* root)
{
    //Maximum value will be always in right most side of BST
    node* curr=root;
    //Once check for the node right should not be null
    while(curr->right!=NULL)
        curr=curr->right;
    
    return curr;
}

node* succesorIN(node* root, int d)
{
    node* curr= root;
    //ek node ktype ka variable baana lo usko null ke equal kar do
    node* successor=NULL;
    while(curr!=NULL)
    {   
        //agr mann lo wo node ke data se chota hai toh there is a possiblity ki whi node successor ho
        if(curr->data > d)
        {
            //store kara lo aur ushe chota khoj ke le aao 
            successor=curr;
            //chota matlb left
            curr=curr->left;
        }
        else //otherwise chota hai toh right side bada le aao
            curr=curr->right;
    }
    return successor;
}

node* predesassorIP(node* root, int d)
{
    node* curr=root;
    node* predessasor=NULL;
    while(curr!=NULL)
    {
        if(curr->data < d) //chota aaya toh wo bhi ho skata hai ushe baada khoj ke le aao
        {
            predessasor=curr;
            curr=curr->right;
        }
        else
            curr=curr->left;
    }

    return predessasor;
}

node* delte(node* root, int d)
{
    if(root==NULL)
        return root;

    
    if(root->data==d)
    {
        //0 child ko delete karo
        if(root->left==NULL && root->right==NULL)
        {
            delete root;
            return NULL;
        }

        //1 child hai bs uska
        //agr left ya right koi ek null ho
        if(root->left!=NULL && root->right==NULL)
        {
            node* curr=root->left;//age ke elements child ke baad khe saare nodes ho
            delete root;
            return curr;
        }
        
        if(root->left==NULL && root->right!=NULL)
        {
            node* curr=root->right;//age ke elements child ke baad khe saare nodes ho
            delete root;
            return curr;
        }

        //2 child case
        //isme right ka min ya left ka max le ke aao minimumValue function jo likha hai ushe
        //ya maxval le ke aao right side 
        //usko copy kar do us node pe
        //call kar main function agr mini hai toh ya right subtree with value as mini to delete
        if(root->left!=NULL && root->right!=NULL)
        {
            //minimum value le aao right side
            int mini= minimumValue(root->right)->data;
            //copy maar do uske root ke data pe
            root->data=mini;
            //ab right side se mimi wale value ko delete kar do
            root->right=delte(root->right, mini);
            return root;
        }

    }
    else if(root->data >d)
        root->left=delte(root->left,d);
    else if(root->data <=d)
       root->right=delte(root->right,d); 
    else 
        return NULL;
}

int main()
{

    node* root=NULL;
    cout<<" Enter the data to create BST "<<endl;
    takeinput(root);
    levelOrderTraversalSeperator(root);

    cout<<endl<<" Printing the Inorder "<<endl;
    inorder(root);

    cout<<endl<<" Printing the Preorder "<<endl;
    preorder(root);

    cout<<endl<<" Printing the Postorder "<<endl;
    postorder(root);

    cout<<endl<<" Minimum value inside BST is "<<minimumValue(root)->data <<endl;
    cout<<endl<<" Maximum value inside BST is "<<maximumValue(root)->data <<endl;

    node* temp=succesorIN(root,56);
    cout<<" Successor of 56 is "<<temp->data<<endl;

    node* temp1=predesassorIP(root,6);
    cout<<" Predesassor of 6 is "<<temp1->data<<endl;

    root=delte(root,9);
    levelOrderTraversalSeperator(root);

    return 0;
}