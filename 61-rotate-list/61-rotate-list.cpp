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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head==NULL)
            return head;
        
        if(k==0)
            return head;
        
        int ct=0;
        
        ListNode* temp=head;
        
        while(temp->next!=NULL)
        {
            ct++;
            temp=temp->next;
        }
        
        ct++;
        
        cout<<ct<<endl;
        
        temp->next=head;
        
        k=k%ct;
        
        ct=ct-k;
        
        cout<<ct<<endl;
        
        temp=head;
        ListNode* temp1=temp->next;
        
        cout<<temp->val<<endl;
        cout<<temp1->val<<endl;
        
        ct--;
        
        while(ct--)
        {
            temp=temp->next;
            temp1=temp1->next;
        }
        
        temp->next=NULL;
        
        return temp1;
        
       
//         k=k%ct;
        
//         while(k--)
//         {
//             temp=head;
//             int x=temp->val;
//             temp=temp->next;
//             while(temp!=NULL)
//             {
                
//                 int y=temp->val;
//                 temp->val=x;
//                 x=y;
//                 temp=temp->next;
//             }
            
//             head->val=x;
//         }
        
//         return head;
        
    }
};