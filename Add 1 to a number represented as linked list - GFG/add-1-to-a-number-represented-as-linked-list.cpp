//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data%10; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* addOne(Node *head) 
    {
        Node* dummy=new Node(-1);
        dummy->next=head;
        Node* x=dummy;
        Node* y=head;
        
        while(y->next)
        {
            Node* z=y->next;
            y->next=z->next;
            z->next=x->next;
            x->next=z;
        }
        
        Node* temp=dummy->next;
        int carry=0;
        Node* last=head;
        int sum=1;
        while(temp)
        {
            int x=temp->data+carry+sum;
        
            sum=0;
            carry=x/10;
            x=x%10;
            temp->data=x;
            if(temp->next==NULL)
               last=temp;
            temp=temp->next;
            
        }
        
        if(carry)
        {
            Node* temp1=new Node(carry);
            last->next=temp1;
        }
        
        x=dummy;
        y=dummy->next;
        
        while(y->next)
        {
            Node* z=y->next;
            y->next=z->next;
            z->next=x->next;
            x->next=z;
        }
        
        return dummy->next;
    }
};










//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends