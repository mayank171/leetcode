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
        ListNode* temp1;
   
        for(int i=0;i<=b;i++)
        {
            if(i==a-1)
            {
                temp1=temp;
            }
            temp=temp->next;
        }
        
        temp1->next=list2;
        
        while(temp1->next!=NULL)
        {
            temp1=temp1->next;
        }
        
        temp1->next=temp;
        
        
        return list1;
        
    }
};