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
                    cout<<temp->val<<"**"<<endl;
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
            cout<<temp1->val<<" ";
            temp1=temp1->next;
        }
        cout<<endl;
        
        if(temp2->val!=10000)
        temp1->next=temp2;
        
        
        while(temp2)
        {
            cout<<temp2->val<<" ";
            temp2=temp2->next;
        }
        cout<<endl;
        
        if(head1->val==-10000)
            return head1->next;
        
        
        return head1;
        
        
        
        
        
        
        
        
        
        
//          queue<ListNode*> q1;
//          queue<ListNode*> q2;
        
//          queue<int> ms;
        
//          ListNode* temp=head;
        
//         int flag=0;
        
//         while(temp)
//         {
//             if(temp->val==x)
//             {
//                 flag=1;
//                 //ms.push(temp);
//                 cout<<temp->val<<"*"<<endl;
                
//             }
//             else if(temp->val>x && flag==0)
//             {
//                 cout<<temp->val<<"("<<endl;
//                 q1.push(temp);
//                 //ms.push(temp);
//                 cout<<temp->val<<"-"<<endl;
                
//             }
//             else if(temp->val<x && flag==1)
//             {
//                 cout<<temp->val<<"("<<endl;
//                 q2.push(temp);
//             }
//             temp=temp->next;
//         }
        
//         temp=head;
        
//         while(temp)
//         {
//             if(temp->val>x)
//                 ms.push(temp->val);
//             temp=temp->next;
//         }
        
        
        
//         while(!q1.empty() && !q2.empty())
//         {
//             ListNode* a=q1.front();
//             q1.pop();
            
//             ListNode* b=q2.front();
//             q2.pop();
            
//             swap(a->val,b->val);
            
//         }
        
        
//         int n=q2.size();
//         cout<<n<<endl;
        
//         if(q1.empty() && q2.empty())
//         {
//             //return head;
//         }
//         else
//         {
//             temp=head;
        
//             while(temp)
//             {
//                 if(temp->val==x)
//                 {
//                     if(q1.empty())
//                     {
//                         ListNode* a=q2.front();
//                         q2.pop();
//                         swap(temp->val,a->val);
//                     }
//                     else
//                     {
//                         ListNode* a=q1.front();
//                         q1.pop();
//                         swap(temp->val,a->val);
//                     }
//                     break;
//                 }
//                 temp=temp->next;
//             }
//         }
        
//         // for(auto &it:ms)
//         // {
//         //     cout<<it<<" ";
//         // }
//         // cout<<endl;
        
//         temp=head;
        
//         while(temp)
//         {
//             if(temp->val>=x)
//             {
                
//                 break;
//             }
//             temp=temp->next;
//         }
        
//         while(!ms.empty())
//         {
//             if(temp)
//             {
//                 temp->val=ms.front();
//                 cout<<temp->val<<"$"<<endl;
//                 ms.pop();
//             }
//             temp=temp->next;
//         }
        
        
//         return head;
    }
};