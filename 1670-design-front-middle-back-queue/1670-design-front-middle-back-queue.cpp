struct node
{
    int val;
    struct node* next;
};

class FrontMiddleBackQueue {
private:
   struct node* head;  
public:
    FrontMiddleBackQueue() {
        head=NULL;
    }
    
    void pushFront(int val) {
        node* newnode=new node();
        
        newnode->val=val;
        newnode->next=NULL;
        
        if(head==NULL)
            head=newnode;
        else
        {
            newnode->next=head;
            head=newnode;
        }
        
        newnode=head;
        while(newnode)
        {
            newnode=newnode->next;
        }
    }
    
    void pushMiddle(int val) {
        
        node* temp=new node();
        temp->val=val;
        temp->next=NULL;
        
        if(head==NULL)
        {
            head=temp;
            temp->next=NULL;
            return;
        }
        
        if(head->next==NULL)
        {
            temp->next=head;
            head=temp;
            return ;
        }
        
        node* newnode=head;
        int ct=0;
        while(newnode!=NULL)
        {
            ct++;
            newnode=newnode->next;
        }
        
        int p=ct/2-1;
        
        newnode=head;
        while(p--)
        {
            if(newnode!=NULL)
            newnode=newnode->next;
        }
     
        temp->next=newnode->next;
        newnode->next=temp;
        
        temp=head;
        while(temp!=NULL)
        {
            temp=temp->next;
        }
    }
    
    void pushBack(int val) {
        
        node* temp1=new node();
        temp1->val=val;
        temp1->next=NULL;
        
        if(head==NULL)
        {
            head=temp1;
            temp1->next=NULL;
            return;
        }
        
        if(head->next==NULL)
        {
            head->next=temp1;
            temp1->next=NULL;
            return ;
        }
        
        
        node* temp=head;
        
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        
        temp->next=temp1;
        temp1->next=NULL;
        
        temp=head;
        while(temp)
        {
            temp=temp->next;
        }
    }
    
    int popFront() {
        if(head==NULL)
            return -1;
        else if(head->next==NULL)
        {
            int x=head->val;
            head=NULL;
            return x;
        }
        else
        {
            int x=head->val;
            head=head->next;
            return x;
        }
    }
    
    int popMiddle() {
        node* temp=head;
        int ct=0;
        while(temp!=NULL)
        {
            ct++;
            temp=temp->next;
        }
       // ct/=2;
        
        if(ct==0)
            return -1;
        else if(ct==1)
        {
            int x=head->val;
            head=NULL;
            return x;
        }
        else if(ct==2)
        {
            int x=head->val;
            head=head->next;
            cout<<x<<endl;
            return x;
        }
       
        int x;
        if(ct&1)
        {
            node* temp=head;
            while(temp!=NULL)
            {
                temp=temp->next;
            }
            int p=ct/2-1;
            node* newnode=head;
            
            while(p--)
            {
                newnode=newnode->next;
            }
            x=newnode->next->val;
            newnode->next=newnode->next->next;
            //newnode->next->next=NULL;
        }
        else
        {
            node* temp=head;
            while(temp!=NULL)
            {
                
                temp=temp->next;
            }
            int p=ct/2-2;
            node* newnode=head;
            
            while(p--)
            {
                newnode=newnode->next;
            }
            x=newnode->next->val;
            newnode->next=newnode->next->next;
            //newnode->next->next=NULL;
        }
        
        return x;
        
    }
    
    int popBack() {
        node* temp=head;
        
        int x;
        if(temp==NULL)
            return -1;
        else if(temp->next==NULL)
        {
            x=temp->val;
            head=NULL;
            return x;
        }
        
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        x=temp->next->val;
        temp->next=NULL;
        return x;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */