/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        
        if(head->next==NULL || head->next->next==NULL)
        {
            return ;
        }
        
        
        // - - - - -
        int ct=0;
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=slow;
        
        while(fast && fast->next)
        {
            fast=fast->next;
            if(fast->next)
                fast=fast->next;
            prev=slow;
            slow=slow->next;
        }
        
        
        ListNode* temp1=slow;
        prev->next=NULL;
        
        ListNode* dummy=new ListNode(-1);
        dummy->next=temp1;
        ListNode* x=dummy;
        ListNode* y=temp1;
        
        while(y->next)
        {
            ListNode* z=y->next;
            cout<<z->val<<endl;
            y->next=z->next;
            z->next=x->next;
            x->next=z;
        }
        
        
        ListNode* temp2=dummy->next;
        ListNode* temp=head;
        
        while(temp && temp2)
        {
                ListNode* node1=temp->next;
                temp->next=temp2;
                ListNode* node2=temp2->next;
                temp2->next=node1;
                temp=node1;
                prev=temp2;
                temp2=node2;
            
        }
        
        if(temp2)
        {
            ListNode* x=new ListNode(temp2->val);
            prev->next=x;
        }
        
    }
};