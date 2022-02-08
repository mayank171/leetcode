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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        int ct=0;
        
        ListNode* temp=head;
        
        vector<ListNode*> ans;
        
        while(temp!=NULL)
        {
            ct++;
            temp=temp->next;
        }
        
        ListNode* temp1=head;
        
        if(ct>k)
        {
            if(ct%k==0)
            {
                int q=ct/k;
                int c=0;
                temp=head;
                while(temp!=NULL)
                {
                    if(c<q)
                    {
                        c++;
                        if(c==q)
                        {
                            temp1=temp;
                        }
                        temp=temp->next;
                        
                        
                    }
                    else
                    {
                        c=1;
                        temp1->next=NULL;
                        ans.push_back(head);
                        head=temp;
                        temp=temp->next;
                    }
                    
                }
                ans.push_back(head);
            }
            else
            {
                int t=ct%k;
                int rem=abs(t-k);
                int q=ct/k+1;
                int q2=ct/k;
                
                cout<<t<<endl;
             
                int c=0;
                temp=head;
                while(temp!=NULL)
                {
                    if(c<q)
                    {
                        c++;
                        if(c==q)
                        {
                            temp1=temp;
                        }
                        temp=temp->next;   
                    }
                    else
                    {
                        c=1;
                        temp1->next=NULL;
                        ans.push_back(head);
                        t--;
                        
                        head=temp;
                        if(t==0)
                            break;
                        temp=temp->next;
                        
                        
                    }
                }

                cout<<q2<<endl;
                c=0;
                
                if(q2==1)
                {
                    while(temp!=NULL)
                    {
                        ListNode* temp1=temp;
                        temp=temp->next;
                        temp1->next=NULL;
                        head=temp1;
                        ans.push_back(head);
                        
                    }
                    
                }
                else
                {
                     while(temp!=NULL)
                     {
                         if(c<q2)
                         {
                             c++;
                             if(c==q2)
                             {
                                 temp1=temp;
                             }
                             temp=temp->next;
                             
                             
                         }
                         else
                         {
                             c=1;
                             temp1->next=NULL;
                             ans.push_back(head);
                             rem--;
                             
                             head=temp;
                             if(rem==0)
                                 break;
                             temp=temp->next;
                             
                             
                         }
                         
                     }
                     ans.push_back(head);
                    
                }
            }
               
            
        }
        else if(ct==k)
        {
            cout<<ct<<endl;
            ListNode* temp1=head;
            temp=head;
            while(temp!=NULL)
            {
                ListNode* temp1=temp;
                temp=temp->next;
                temp1->next=NULL;
                head=temp1;
                ans.push_back(head);
                
            }
        }
        else
        {
            ListNode* temp1=head;
            temp=head;
            int rem=k-ct;
            while(temp!=NULL)
            {
                ListNode* temp1=temp;
                temp=temp->next;
                temp1->next=NULL;
                head=temp1;
                ans.push_back(head);
                
            }
            
            while(rem--)
            {
                ListNode* temp1=NULL;
                ans.push_back(temp1);
            }
            
        }
        
        return ans;
    }
};