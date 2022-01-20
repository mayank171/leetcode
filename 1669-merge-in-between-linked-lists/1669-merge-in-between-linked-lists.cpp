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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        
        ListNode* temp=list1;
        
        b=b-a+1;
        
        while(a!=1)
        {
         
            temp=temp->next;
            a--;
            if(a==1)
                break;
        }
        
        ListNode* temp1=temp;
        
         while(temp1->next!=NULL)
        {

            temp1=temp1->next;
            
            b--;
             
            if(b==0)
                break;
        }
        temp1=temp1->next;
        
        temp->next=list2;
        
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        
        temp->next=temp1;
        
        
        return list1;
        
    }
};