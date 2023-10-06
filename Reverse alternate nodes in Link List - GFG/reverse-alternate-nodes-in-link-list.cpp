//{ Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* A linked list node */


struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert()
{
    int n,value;
    cin>>n;
    struct Node *temp;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}


// } Driver Code Ends
/*
  reverse alternate nodes and append at the end
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
      int data;
      struct Node *next;
    
      Node(int x){
        data = x;
        next = NULL;
      }
    
   };

*/
class Solution
{
    public:
    void rearrange(struct Node *odd)
    {
        if(odd->next==NULL)
           return ;
           
        Node* temp=odd;
        Node* temp1=odd->next;
        Node* odd1=temp1;
        temp->next=temp1->next;
        temp=temp->next;
        
        while(temp1 && temp1->next)
        {
            temp1->next=temp->next;
            temp1=temp1->next;
            if(temp1==NULL)
               break;
            temp->next=temp1->next;
            temp=temp->next;
        }
        
        Node* dummy=new Node(-1);
        dummy->next=odd1;
        
        Node* x=dummy;
        Node* y=x->next;
        while(y->next)
        {
            Node* z=y->next;
            y->next=z->next;
            z->next=x->next;
            x->next=z;
        }
        
        
        
        Node* x1=odd;
        Node* y1=x->next;
        
        while(x1->next)
        {
       //     cout<<x1->data<<" ";
            x1=x1->next;
        }
       // cout<<endl;
        
        // while(y1)
        // {
        //     cout<<y1->data<<" ";
        //     y1=y1->next;
        // }
        // cout<<endl;
        
        x1->next=y1;
        
    }
};



//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while (t--) {
        insert();
        Solution ob;
        ob.rearrange(start);
        printList(start);
    }
    return 0;
}

// } Driver Code Ends