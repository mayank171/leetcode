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
    ListNode* partition(ListNode* head, int x) 
    {
        if(head==NULL)
            return head;
        
        ListNode* head1;
        ListNode* head2;
        
        
        ListNode* temp=head;
        ListNode* temp1=new ListNode(-10000);
        ListNode* temp2=new ListNode(10000);
        
        
        head1=temp1;
        head2=temp2;
        
        
        while(temp)
        {
            if(temp->val<x)
            {
                if(temp1->val==-10000)
                {
                    temp1->val=temp->val;
                    temp1->next=NULL;    
                }
                else
                {
                    ListNode* a=new ListNode(temp->val);
                    temp1->next=a;
                    a->next=NULL;
                    temp1=temp1->next;
                
                }
            }
            else
            {
                if(temp2->val==10000)
                {
                    temp2->val=temp->val;
                    temp2->next=NULL;    
                }
                else
                {
                    ListNode* a=new ListNode(temp->val);
                    temp2->next=a;
                    a->next=NULL;
                    temp2=temp2->next;
                }
                
            }
            temp=temp->next;
        }
        
        
        temp1=head1;
        temp2=head2;
        
        while(temp1->next!=NULL)
        {
            temp1=temp1->next;
        }
        cout<<endl;
        
        if(temp2->val!=10000)
        temp1->next=temp2;
        
        
        if(head1->val==-10000)
            return head1->next;
        
        
        return head1;
        
    }
};