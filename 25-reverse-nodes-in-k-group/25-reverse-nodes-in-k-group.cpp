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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        
        
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        
        ListNode* x=dummy;
        ListNode* y=dummy;
        
        while(true)
        {
            ListNode* y=x->next;
            
            ListNode* temp=y;
            int p=0;
            while(temp)
            {
                if(p==k)
                    break;
                temp=temp->next;
                p++;
            }
            //cout<<p<<endl;
            if(p<k)
                break;
            
            
            if(y==NULL)
                break;
            
            int ct=1;
            while(ct<k)
            {
                ListNode* z=y->next;
                if(z==NULL)
                {
                    break;
                }
                y->next=z->next;
                z->next=x->next;
                x->next=z;
                ct++;
            }
            
            if(ct<k)
                break;
            
            ct=0;
            while(ct<k)
            {
                x=x->next;
                ct++;
            }
                
        }
    
        return dummy->next;
        
        
    }
};