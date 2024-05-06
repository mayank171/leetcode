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
    ListNode* removeNodes(ListNode* head) {
        
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
        
        ListNode* temp1=dummy->next;
        
        // while(temp1)
        // {
        //     cout<<temp1->val<<" ";
        //     temp1=temp1->next;
        // }
        
        int maxi=0;
        ListNode* prev=dummy;
        ListNode* temp=dummy->next;
        
        while(temp)
        {
            if(temp->val<maxi)
            {
                prev->next=temp->next;
                temp->next=NULL;
                temp=prev->next;
            }
            else
            {
                maxi=max(maxi,temp->val);
                prev=temp;
                temp=temp->next;
            }
        }
        
       // return NULL;
        
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




















