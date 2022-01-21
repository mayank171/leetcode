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
        
        while(temp!=NULL)
        {
            ct++;
            temp=temp->next;
        }
        cout<<ct<<endl;
        
        k=k%ct;
        
        cout<<k<<endl;
        
        while(k--)
        {
            temp=head;
            int x=temp->val;
            temp=temp->next;
            while(temp!=NULL)
            {
                
                int y=temp->val;
                temp->val=x;
                x=y;
                temp=temp->next;
            }
            
            head->val=x;
        }
        
        return head;
        
    }
};