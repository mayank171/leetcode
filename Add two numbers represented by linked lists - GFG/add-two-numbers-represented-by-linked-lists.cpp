//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        
        
        Node* dummy=new Node(-1);
        dummy->next=first;
        
        Node* x=dummy;
        Node* y=x->next;
        
        while(y->next)
        {
            Node* z=y->next;
            y->next=z->next;
            z->next=x->next;
            x->next=z;
        }
        
        Node* dummy1=new Node(-1);
        dummy1->next=second;
        
        x=dummy1;
        y=x->next;
        
        while(y->next)
        {
            Node* z=y->next;
            y->next=z->next;
            z->next=x->next;
            x->next=z;
        }
        
        // Node* a=dummy->next;
        // while(a)
        // {
        //     cout<<a->data<<" ";
        //     a=a->next;
        // }
        // cout<<endl;
        
        // Node* b=dummy1->next;
        // while(b)
        // {
        //     cout<<b->data<<" ";
        //     b=b->next;
        // }
        // cout<<endl;
        
        
        //return NULL;
        
        Node* temp1=dummy->next;
        Node* temp2=dummy1->next;
        
        int carry=0;
        
        Node* dummy3=new Node(-1);
        Node* temp3=dummy3;
        
        
        while(temp1!=NULL && temp2!=NULL)
        {
            int val=temp1->data+temp2->data+carry;
            Node* node=new Node(0);
            node->data=val%10;
            carry=val/10;
            
            temp3->next=node;
            
            temp3=temp3->next;
            temp1=temp1->next;
            temp2=temp2->next;
            
        }
        
      //  return NULL;
        
        while(temp1)
        {
            int val=temp1->data+carry;
            Node* node=new Node(0);
            node->data=val%10;
            carry=val/10;
            temp3->next=node;
            temp3=temp3->next;
            temp1=temp1->next;
        }
        
        while(temp2)
        {
            int val=temp2->data+carry;
            Node* node=new Node(0);
            node->data=val%10;
            carry=val/10;
            temp3->next=node;
            temp3=temp3->next;
            temp2=temp2->next;
        }
        
        if(carry>0)
        {
            Node* node=new Node(carry);
            temp3->next=node;
            temp3=temp3->next;
        }
        
        x=dummy3;
        y=x->next;
        
        while(y->next)
        {
            Node* z=y->next;
            y->next=z->next;
            z->next=x->next;
            x->next=z;
        }
        
        return dummy3->next;
    }
};




















//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends