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
    bool hasCycle(ListNode *head) {
    
        if(head==NULL)
            return false;
        if(head->next==NULL)
            return false;
        
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
            if(fast)
                fast=fast->next;
            else
                break;
            
            if(slow==fast)
                break;
        }

        if(fast==NULL)
            return false;
        
        return true;
    }
};