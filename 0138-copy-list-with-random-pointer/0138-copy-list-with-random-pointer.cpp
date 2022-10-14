/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {

public:
    Node* copyRandomList(Node* head) {
        
//        map<Node*,Node*> mp;
        
//         Node* temp=head;
        
//         while(temp)
//         {
//             mp[temp]=new Node( temp->val);
//             temp=temp->next;
//         }
        
//         temp=head;
        
//         while(temp)
//         {
//             mp[temp]->next=mp[temp->next];
//             mp[temp]->random=mp[temp->random];
//             temp=temp->next;
//         }
        
//         return mp[head];
        
//         Node* temp=head;
        
//         while(temp)
//         {
//             Node* temp1=new Node(temp->val);
            
//             temp1->next=temp->next;
//             temp->next=temp1;
            
//             temp=temp->next;
//             temp=temp->next;
//         }
        
//         temp=head;
        
//         while(temp)
//         {
//             if(temp->next!=NULL)
//             {
//                 if(temp->random!=NULL)
//                 temp->next->random=temp->random->next;
//                 else
//                 temp->next->random=temp->random;
                    
//             }
//             temp=temp->next;
//         }
        
//         temp=head;
//         temp=temp->next;
//         Node* head2=temp;
        
//         int flag=1;
//         while(temp)
//         {
//             if(flag==-1)
//             {
//                 if(temp->next->next!=NULL && temp->next!=NULL)
//                 temp->next=temp->next->next;
//             }
//             temp=temp->next;
//             flag*=-1;
//         }
        
//         temp=head2;
        
//         while(temp)
//         {
//             cout<<temp->val<<" ";
//             temp=temp->next;
//         }
        
//         return head2;
        
        if(head==NULL)
        {
            return NULL;
        }
        
        
        Node * temp=head;
        while(temp)
        {
            Node* temp1=new Node(temp->val);
            temp1->next=temp->next;
            temp->next=temp1;
            temp=temp->next->next;
        }
        
        
        temp=head;
        while(temp)
        {
            if(temp->random==NULL)
               temp->next->random=NULL;
            else
               temp->next->random=temp->random->next;
            temp=temp->next->next;
        }
       
        
        Node* copy=head->next;
        Node* original=head;
        Node* ans=copy;
        
        while(copy!=NULL && original!=NULL)
        {
            original->next=original->next->next;
            copy->next=copy->next?copy->next->next:copy->next;
            original=original->next;
            copy=copy->next;
        }
        
        
        
        return ans;
        
        
        
        
        
        
        
        
        
        
        
    }
};