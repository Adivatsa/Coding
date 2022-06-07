/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* cycledetection(ListNode* head)
    {
        //base case
        if(head==NULL || head->next==NULL)
            return NULL;
        
        ListNode* slow= head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
            if(fast->next!=NULL)
                fast=fast->next;
            
            //check for cycle condition
            if(slow==fast)
                return slow;
        }
        return NULL;
    }
    ListNode* startnode(ListNode *head)
    {
        //base case
        if(head==NULL || head->next==NULL)
            return NULL;
        
        ListNode* slow=head;
        ListNode* fast=cycledetection(head);//it will detect cycle and one pointer at that point and other at starting of linked list
        //check for starting node condition
        
        while(fast!=NULL && slow!=NULL &&slow!=fast)
        {
            fast=fast->next;
            slow=slow->next;
            
        }
        if(slow==fast)
            return slow;
        else
            return NULL;
    }
    ListNode *detectCycle(ListNode *head) {
        
        //first step is to detect the loop
        //second step is find the start of loop
        
        //Base case
        if(head==NULL ||head->next==NULL)
            return NULL;
        
        //return the node of starting of the loop
        return startnode(head);
        
        
    }
};