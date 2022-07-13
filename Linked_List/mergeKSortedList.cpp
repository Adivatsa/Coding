class comparator
{
    public:
    
    bool operator()(ListNode* a, ListNode* b)
    {
        return a->val>b->val;//return in opposite function for operator overloading 
    }     
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        //Step 1: Create a Min heap 
        //Step 2: Push all the start of k list to min heap
        //step 3: create dummy node and tail to insert and return ans
        //Step 4: Till heap is not empty take out top node and insert at tail and insert its next
        //step5: At last return dummy ka next as we have to return the head of LL
        
        //Creation of min heap
        priority_queue<ListNode*, vector<ListNode*>, comparator> q;
        
        //push all list first element inside min heap
        for(int i=0; i<lists.size(); i++)
        {
            if(lists[i]!=NULL)
                q.push(lists[i]);
        }
            
        
        //creation of dummy node and tail to insertion
        ListNode* dummy= new ListNode(-1);
        ListNode* tail=dummy;
        
        while(!q.empty())
        {
            //pop the top elemnt and insert the next it to it 
            //insert at tail 
            ListNode* temp=q.top();
            q.pop();
            
            //insert at tail
            tail->next=temp;
            tail=temp;
            
            //insert into min heap next element of temp
            if(temp->next!=NULL)
                q.push(temp->next);
        }
        
        //Return the head of the linked list
        return dummy->next;    
    }