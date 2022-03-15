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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        
        int ct=0;
        
        ListNode* temp=head;
        
        while(temp!=NULL)
        {
            ct++;
            temp=temp->next;
        }
        
        vector<int> v;
        int a=1;
        int sum=0;
        while(sum<=ct)
        {
            if(a+sum<=ct)
            {
               v.push_back(a);
               sum+=a; 
            }
            else
            {
                v.push_back(ct-sum);
                break;
            }
            a++;
               
        }
        
        // for(auto &it:v)
        // {
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        
        if(v[v.size()-1]==0)
            v.pop_back();
        
        temp=head;
        
        ListNode* prev=head;
        ListNode* current=temp;
        ListNode* prev1;
        ListNode* cur1;
        int flag=0;
        for(int i=0;i<v.size();i++)
        {
            if(v[i]&1)
            {
                while(v[i]--)
                {
                     prev=current;
                     if(current->next!=NULL)
                        current=current->next;
                     else
                         break;
                }
            }
            else if(v[i]%2==0)
            {
                int x=v[i];
                ListNode* nxt;
                prev1=prev;
               // cout<<"-"<<prev->val<<"-"<<current->val<<endl;
                cur1=current;
                while(x--)
                {
                    
                    nxt=current->next;
                    current->next=prev;
                    prev=current;
                    current=nxt;
                }
               // cout<<prev->val<<"*"<<current->val<<endl;
                prev1->next=prev;
                cur1->next=current;
                
                if(i+1<v.size() && v[i+1]%2==0)
                {
                    cout<<prev->val<<"*"<<current->val<<endl;
                    flag=1;
                    break;
                }
                
            }
           
        }
       // cout<<prev->val<<" "<<prev1->val<<" "<<cur1->val<<" "<<current->val<<endl;
        
        if(flag==1)
        {
            int x=v[v.size()-1];
            ListNode* nxt;
            prev=cur1;
            prev1=prev;
            current=prev->next;
            cur1=prev->next;
            while(x--)
            {
                if(current==NULL)
                    break;
                nxt=current->next;
                current->next=prev;
                prev=current;
                current=nxt;
            }
            prev1->next=prev;
            cur1->next=NULL;
        }
        
        
        
        return temp;
    }
};