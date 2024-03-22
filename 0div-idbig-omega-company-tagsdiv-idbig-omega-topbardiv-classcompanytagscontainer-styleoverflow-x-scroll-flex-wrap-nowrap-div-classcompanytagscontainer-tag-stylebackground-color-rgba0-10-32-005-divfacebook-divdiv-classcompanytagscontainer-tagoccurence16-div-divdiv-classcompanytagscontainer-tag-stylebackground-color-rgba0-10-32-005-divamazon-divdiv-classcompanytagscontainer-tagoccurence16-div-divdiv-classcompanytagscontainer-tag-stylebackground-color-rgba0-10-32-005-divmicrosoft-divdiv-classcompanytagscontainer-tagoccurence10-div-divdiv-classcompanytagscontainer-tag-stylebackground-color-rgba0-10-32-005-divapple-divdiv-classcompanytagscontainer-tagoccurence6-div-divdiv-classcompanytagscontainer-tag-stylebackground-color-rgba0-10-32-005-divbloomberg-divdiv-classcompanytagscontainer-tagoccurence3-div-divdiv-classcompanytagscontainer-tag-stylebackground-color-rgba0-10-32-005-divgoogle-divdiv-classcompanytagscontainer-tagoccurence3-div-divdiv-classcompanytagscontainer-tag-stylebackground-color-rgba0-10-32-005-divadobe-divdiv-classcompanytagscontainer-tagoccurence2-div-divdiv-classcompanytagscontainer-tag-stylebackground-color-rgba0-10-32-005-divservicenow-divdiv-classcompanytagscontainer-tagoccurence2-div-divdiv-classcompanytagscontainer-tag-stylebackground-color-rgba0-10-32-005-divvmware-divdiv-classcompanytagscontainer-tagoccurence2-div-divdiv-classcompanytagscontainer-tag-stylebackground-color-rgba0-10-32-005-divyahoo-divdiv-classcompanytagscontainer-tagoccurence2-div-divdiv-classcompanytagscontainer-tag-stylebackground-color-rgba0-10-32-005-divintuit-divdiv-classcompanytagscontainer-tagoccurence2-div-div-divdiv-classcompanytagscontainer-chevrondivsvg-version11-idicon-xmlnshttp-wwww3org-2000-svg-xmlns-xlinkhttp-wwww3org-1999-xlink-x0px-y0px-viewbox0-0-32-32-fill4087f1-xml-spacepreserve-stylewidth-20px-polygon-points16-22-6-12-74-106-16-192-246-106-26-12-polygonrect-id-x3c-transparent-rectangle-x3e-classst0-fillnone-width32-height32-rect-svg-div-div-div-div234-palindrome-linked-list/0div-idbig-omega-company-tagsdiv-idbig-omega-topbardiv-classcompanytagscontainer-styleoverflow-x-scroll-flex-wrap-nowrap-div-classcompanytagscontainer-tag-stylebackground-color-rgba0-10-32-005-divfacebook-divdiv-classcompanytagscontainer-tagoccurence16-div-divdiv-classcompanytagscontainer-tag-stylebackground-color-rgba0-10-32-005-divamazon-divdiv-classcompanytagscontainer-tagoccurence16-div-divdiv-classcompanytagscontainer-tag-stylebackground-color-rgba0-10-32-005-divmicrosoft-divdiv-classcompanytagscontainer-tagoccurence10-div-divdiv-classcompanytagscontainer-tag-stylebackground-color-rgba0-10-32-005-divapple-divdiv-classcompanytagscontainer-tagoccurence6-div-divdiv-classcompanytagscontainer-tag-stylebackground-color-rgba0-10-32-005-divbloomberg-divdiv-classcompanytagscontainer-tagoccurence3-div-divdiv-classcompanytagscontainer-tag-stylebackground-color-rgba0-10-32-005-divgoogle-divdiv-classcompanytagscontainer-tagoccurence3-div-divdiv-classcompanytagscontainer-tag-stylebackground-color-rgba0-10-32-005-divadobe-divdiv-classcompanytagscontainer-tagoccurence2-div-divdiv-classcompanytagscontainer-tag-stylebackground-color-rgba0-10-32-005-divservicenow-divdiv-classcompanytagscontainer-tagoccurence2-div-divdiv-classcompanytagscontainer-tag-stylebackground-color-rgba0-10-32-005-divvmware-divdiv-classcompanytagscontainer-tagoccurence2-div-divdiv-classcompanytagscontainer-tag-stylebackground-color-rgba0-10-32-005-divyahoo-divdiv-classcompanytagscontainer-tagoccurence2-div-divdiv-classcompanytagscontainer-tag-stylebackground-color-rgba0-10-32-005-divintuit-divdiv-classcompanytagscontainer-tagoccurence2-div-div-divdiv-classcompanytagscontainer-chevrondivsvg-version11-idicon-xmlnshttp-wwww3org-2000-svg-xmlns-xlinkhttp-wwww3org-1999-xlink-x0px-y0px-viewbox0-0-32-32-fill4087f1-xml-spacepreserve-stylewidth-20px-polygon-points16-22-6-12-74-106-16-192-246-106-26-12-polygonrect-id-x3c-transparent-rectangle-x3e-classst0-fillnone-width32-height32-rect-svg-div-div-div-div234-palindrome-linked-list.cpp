
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        
        if(head->next==NULL)
            return true;
        
        if(head->next->next==NULL)
        {
            if(head->val==head->next->val)
                return true;
            return false;
        }
        
        int ct=0;
        
        ListNode* temp=head;
        while(temp)
        {
            ct++;
            temp=temp->next;
        }
        
        
        int ctr=ct;
        ct=ct/2;

        temp=head;
        ListNode* prev=temp;
        temp=temp->next;
        while(ct-- && temp)
        {
            prev=temp;
            temp=temp->next;
        }
        
        
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode* x=dummy;
        ListNode* y=x->next;
        while(y->next!=prev)
        {
            ListNode* z=y->next;
           
            y->next=z->next;
            z->next=x->next;
            x->next=z;
        }
        
        temp=dummy->next;
        
        ListNode* fast=dummy->next;
        ListNode* slow=dummy->next;
        
        int flag=0;
        if(ctr&1)
            flag=1;
        
        ctr/=2;
        
        while(ctr--)
        {
            fast=fast->next;
        }
        
        if(flag==1)
            fast=fast->next;
        
        while(fast)
        {
            if(slow->val!=fast->val)
                return false;
            slow=slow->next;
            fast=fast->next;
        }
        
        return true;
    }
};