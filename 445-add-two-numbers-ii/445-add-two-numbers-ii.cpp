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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int ct1=0;
        
        ListNode* temp=l1;
        
        stack<int> stk1;
        
        while(temp!=NULL)
        {
            ct1++;
            stk1.push(temp->val);
            temp=temp->next;
        }            

        int ct2=0;
        
        ListNode* temp1=l2;
        
        stack<int> stk2;
        
        while(temp1!=NULL)
        {
            ct2++;
            stk2.push(temp1->val);
            temp1=temp1->next;
        }            

        stack<int> stk3;
        
        if(ct1>=ct2)
        {
            int carry=0;
            while(!stk2.empty())
            {
                int x=stk2.top();
                stk2.pop();
                x+=stk1.top();
                stk1.pop();
                if(carry>0)
                {
                    x+=carry;
                    carry=0;
                }
                if(x>9)
                {
                    carry+=x/10;
                    x=x%10;
                }
                stk3.push(x);
            }
            
            while(!stk1.empty())
            {
                int x=stk1.top();
                stk1.pop();
                if(carry>0)
                {
                    x+=carry;
                    carry=0;
                }
                if(x>9)
                {
                    carry+=x/10;
                    x=x%10;
                }
                stk3.push(x);
            }
            
            cout<<carry<<endl;
            temp=l1;
            
            while(temp!=NULL)
            {
                temp->val=stk3.top();
                cout<<temp->val<<endl;
                stk3.pop();
                temp=temp->next;
            }
            
            if(carry>0)
            {
                ListNode* front=new ListNode();
                front->val=carry;
                front->next=l1;
                temp=front;
            }
            else
                temp=l1;
        }
        else
        {
            int carry=0;
            while(!stk1.empty())
            {
                int x=stk1.top();
                stk1.pop();
                x+=stk2.top();
                stk2.pop();
                if(carry>0)
                {
                    x+=carry;
                    carry=0;
                }
                if(x>9)
                {
                    carry+=x/10;
                    x=x%10;
                }
                stk3.push(x);
            }
            
            while(!stk2.empty())
            {
                int x=stk2.top();
                stk2.pop();
                if(carry>0)
                {
                    x+=carry;
                    carry=0;
                }
                if(x>9)
                {
                    carry+=x/10;
                    x=x%10;
                }
                stk3.push(x);
            }
            
            temp=l2;
            
            while(temp!=NULL)
            {
                temp->val=stk3.top();
                cout<<temp->val<<endl;
                stk3.pop();
                temp=temp->next;
            }
            //cout<<carry<<endl;
            if(carry>0)
            {
                ListNode* front=new ListNode();
                front->val=carry;
                front->next=l2;
                temp=front;
            }
            else
                temp=l2;
        }
        
        return temp;
        
    }
};