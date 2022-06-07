struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/


class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
        
        // Approach 1: Check for each one with all other
        //TC=O(n^2) and SC=O(1)
        
        //Approach 2: Sort the Linked list and use sortd alg to eliminate the duplicates
        //TC=O(nlongn) and SC=O(1)
     
        //method 3: Using Map method
        //Using map to track the node which has been visited
        //TC=O(n) and SC=O(n)
        if(head==NULL && head->next==NULL)
            return head;
        unordered_map<int, bool>m;
        Node* curr=head;
        Node* prev=NULL;
        while(curr!=NULL)
        {
            
            if(m[curr->data]==true)
            {
                //Delete opertaion
                Node* temp=curr;
                curr=curr->next;
                prev->next=curr;
                delete temp;
                
            }
            else
            {
                m[curr->data]=true;
                prev=curr;
                curr=curr->next;
            }
            
            
        }
        return head;
        
    }
};