/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
private:
    Node* check(Node* &temp)
    {
        cout<<temp->val<<endl;
        if(temp->next==NULL && temp->child==NULL)
            return temp;
        
        if(temp->next!=NULL)
        {
            while(temp->next!=NULL)
            {
                if(temp->child!=NULL)
                {
                    Node* temp1=temp->child;
                    Node* temp2=temp->next;
                    temp1=check(temp1);
                    cout<<"cdvdv"<<temp1->val<<endl;
                    temp1->next=temp2;
                    temp2->prev=temp1;
                    temp->next=temp->child;
                    temp->child->prev=temp;
                    temp->child=NULL;
                    cout<<temp->val<<endl;
                }
                temp=temp->next;
            }
        }
        else if(temp->next==NULL && temp->child!=NULL)
        {
            
                temp->next=temp->child;
                temp->child=NULL;
                temp->next->prev=temp;
                if(temp->next->next==NULL)
                return check(temp->next);
                else
                return check(temp);
                cout<<temp->val<<"dvd"<<endl;
        }
        
        return temp;
    }
public:
    Node* flatten(Node* head) {
        
        if(head==NULL)
            return head;
        
        Node* temp=head;
        
        Node* temp1=check(temp);
        
        temp=head;
        
        while(temp->next!=NULL)
        {
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
        
        while(temp!=NULL)
        {
            cout<<temp->val<<" ";
            temp=temp->prev;
        }
        
        return head;
        
    }
};