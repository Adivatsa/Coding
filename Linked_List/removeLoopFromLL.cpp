structure of linked list node:

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        //first detect loop
        //find start of loop
        //point before start to null
        
        
            
        Node* fast=head;
        Node* slow=head;
        
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
            if(fast->next!=NULL)
                fast=fast->next;
            if(slow==fast)
                break;
        }
        //Loop detected so place one pointer to strt position to find start of loop
        slow=head;
        
        while(slow!=NULL && fast!=NULL && slow!=fast)
        {
            slow=slow->next;
            fast=fast->next;
        }
        
        //Iska matlba slow and fast equal ho gye hai
        while(slow->next!=fast)
        {
            slow=slow->next;
        }
        //Make pointer point to NULL to break the loop
        slow->next=NULL;
    }
};