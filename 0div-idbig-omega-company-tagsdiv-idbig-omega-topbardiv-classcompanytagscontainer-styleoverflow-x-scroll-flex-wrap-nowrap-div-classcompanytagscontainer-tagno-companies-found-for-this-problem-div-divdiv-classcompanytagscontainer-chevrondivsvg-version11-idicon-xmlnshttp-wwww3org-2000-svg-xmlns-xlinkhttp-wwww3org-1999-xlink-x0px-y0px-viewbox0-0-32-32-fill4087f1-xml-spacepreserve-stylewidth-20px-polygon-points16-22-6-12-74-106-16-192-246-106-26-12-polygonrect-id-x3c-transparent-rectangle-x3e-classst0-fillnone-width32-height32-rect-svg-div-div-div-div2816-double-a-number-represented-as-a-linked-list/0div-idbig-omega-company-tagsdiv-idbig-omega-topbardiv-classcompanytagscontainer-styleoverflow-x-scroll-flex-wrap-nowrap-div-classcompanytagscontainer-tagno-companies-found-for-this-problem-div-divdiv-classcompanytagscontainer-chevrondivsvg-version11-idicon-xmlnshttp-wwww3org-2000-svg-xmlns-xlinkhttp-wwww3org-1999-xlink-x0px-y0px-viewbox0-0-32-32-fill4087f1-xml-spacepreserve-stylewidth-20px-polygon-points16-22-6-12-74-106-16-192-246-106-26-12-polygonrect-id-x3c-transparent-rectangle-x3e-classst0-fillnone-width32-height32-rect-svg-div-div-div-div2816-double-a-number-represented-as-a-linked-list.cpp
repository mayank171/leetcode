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
    ListNode* doubleIt(ListNode* head) {
        
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        
        ListNode* x=dummy;
        ListNode* y=head;
        
        while(y->next)
        {
            ListNode* z=y->next;
            y->next=z->next;
            z->next=x->next;
            x->next=z;
        }
        
        ListNode* temp2=dummy;
        
        int carry=0;
        
        ListNode* temp=dummy->next;
        ListNode* last;
        while(temp)
        {
            int x=temp->val;
            x=x+x+carry;
            temp->val=x%10;
            carry=x/10;
            if(temp->next==NULL)
                last=temp;
            temp=temp->next;
        }
        
        if(carry>0)
        {
            ListNode* temp1=new ListNode(carry);
            last->next=temp1;
        }
        
        //return dummy;
        
        x=dummy;
        y=dummy->next;
        
        while(y->next)
        {
            ListNode* z=y->next;
            y->next=z->next;
            z->next=x->next;
            x->next=z;
        }
        
        return dummy->next;
        
    }
};