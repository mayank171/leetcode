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
    
    
//     void insert(int x)
//     {
//         ListNode* list3=new ListNode();
        
//         ListNode* head=NULL;
        
//         list3->val=x;
//         list3->next=NULL;
        
//         if(head==NULL)
//         {
//             head=list3;
//         }
//         else
//         {
//             ListNode* temp=new ListNode();
            
//             temp=head;
            
//             while(temp!=NULL)
//             {
//                 temp=temp->next;
//             }
            
//             temp->next=list3;
//             list->next=NULL;
//         }
        
        
//     }
    
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
    
//         while(list1!=NULL && list2!=NULL)
//         {
//             if(list1->val<=list2->val)
//             {
//                 insert(list1->val);
//                 list1=list1->next;
//             }
//         }
        
        if(list1==NULL)
            return list2;
        if(list2==NULL)
            return list1;
        
        if(list1->val>list2->val)
        {
            ListNode* temp=list1;
            list1=list2;
            list2=temp;
        }
        
        ListNode* res=list1;
        
        while(list1!=NULL && list2!=NULL)
        {
            ListNode* temp=NULL;
            while(list1!=NULL && list1->val<=list2->val)
            {
                temp=list1;
                list1=list1->next;
            }
            temp->next=list2;
            
            ListNode* temp1=list1;
            list1=list2;
            list2=temp1;
        }
        
        return res;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    }
};