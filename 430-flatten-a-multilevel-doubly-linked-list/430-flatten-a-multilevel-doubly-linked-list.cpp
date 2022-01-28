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
                    temp1->next=temp2;
                    temp2->prev=temp1;
                    temp->next=temp->child;
                    temp->child->prev=temp;
                    temp->child=NULL;
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
        
        
        return head;
        
    }
};