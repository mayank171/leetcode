//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
struct Node* modifyTheList(struct Node *head);
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void print(Node *head)
{
    Node *temp=head;
	while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}


// } Driver Code Ends
/*Complete the function below
Node is as follows:
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
class Solution{
    public:
    struct Node* modifyTheList(struct Node *head)
    {
        int n=0;
        Node* temp=head;
        while(temp)
        {
            n++;
            temp=temp->next;
        }
        
        int xx=n/2;
       // cout<<xx<<endl;
        
        Node* dummy=new Node(-1);
        dummy->next=head;
        int nn=xx-1;
        Node* x=dummy;
        Node* y=x->next;
        
        while(nn && y->next)
        {
            Node* z=y->next;
            y->next=z->next;
            z->next=x->next;
            x->next=z;
            nn--;
        }
        
        Node* first=dummy->next;
        if(n&1)
           n=n/2+2;
        else
           n=n/2+1;
        temp=dummy->next;
        while(n && temp)
        {
            n--;
            if(n==0)
               break;
            temp=temp->next;
        }
        
        Node* second=temp;
        
        while(first && second)
        {
            int temp=second->data-first->data;
            second->data=first->data;
            first->data=temp;
            second=second->next;
            first=first->next;
        }
        
        nn=xx-1;
        x=dummy;
        y=x->next;
        
        while(nn && y->next)
        {
            Node* z=y->next;
            y->next=z->next;
            z->next=x->next;
            x->next=z;
            nn--;
        }
        
        return dummy->next;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		struct Node *head = NULL,*temp=NULL;
		while(n--){
		    int a;
            cin>>a;
			Node *newNode = new Node(a);
			if(head==NULL)
                head=newNode;
            else
                temp->next=newNode;
            temp=newNode;
		}
		Solution obj;
		head = obj.modifyTheList(head);
		print(head);
		
	}
    return 0;
}
// } Driver Code Ends