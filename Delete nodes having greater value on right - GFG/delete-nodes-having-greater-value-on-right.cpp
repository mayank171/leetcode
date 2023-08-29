//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    Node *compute(Node *head)
    {
        // int ct=0;
        // Node* temp=head;
        
        // while(temp)
        // {
        //     ct++;
        //     temp=temp->next;
        // }
        
        Node* dummy=new Node(-1);
        dummy->next=head;
        
        while(true)
        {
            Node* prev=dummy;
            Node* temp=dummy->next;
            
            int x=0;
            int flag=0;
           // Node* temp1;
            while(temp && temp->next)
            {
                if(flag==0 && temp->data<temp->next->data)
                {
                    x=1;
                    flag=1;
                   // temp1=temp;
                    temp=temp->next;
                }
                else if(flag==1 && temp->data<temp->next->data)
                {
                    temp=temp->next;
                }
                else if(flag==1 && temp->data>=temp->next->data)
                {
                    flag=0;
                    prev->next=temp;
                    prev=prev->next;
                    temp=temp->next;
                }
                else
                {
                    prev=prev->next;
                    temp=temp->next;
                }
            }
            
            if(flag==1)
            {
                flag=0;
                prev->next=temp;
                prev=prev->next;
                temp=temp->next;
            }
            
            if(x==0)
               break;
        }
        
        return dummy->next;
    }
    
};

















   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends