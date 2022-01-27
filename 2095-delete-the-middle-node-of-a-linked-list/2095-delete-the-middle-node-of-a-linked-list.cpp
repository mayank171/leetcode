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
    ListNode* deleteMiddle(ListNode* head) {
        
        if(head==NULL)
            return head;
        
        if(head->next==NULL)
            return NULL;
        
        int ct=0;
        ListNode* temp=head;
        
        while(temp!=NULL)
        {
            temp=temp->next;
            ct++;
        }
       // cout<<ct<<endl;
        
        temp=head;
        
        ct=ct/2-1;
        
        while(ct && temp!=NULL)
        {
            temp=temp->next;
            ct--;
        }
        
        temp->next=temp->next->next;
        
        return head;
        
        
    }
};