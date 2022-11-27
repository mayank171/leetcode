//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache
{
    
    class node
    {
        public:
        int x;
        int y;
        node* next;
        node* prev;
        
        node(int x,int y)
        {
            this->x=x;
            this->y=y;
        }
    };
    
    node* head=new node(-1,-1);
    node* tail=new node(-1,-1);
    
    
    int size;
    map<int,node*> mp;
    
    public:
    LRUCache(int cap)
    {
     
        size=cap;
        head->next=tail;
        tail->prev=head;
    }
    
    void addNode(node* x)
    {
        node* temp=head->next;
        x->next=head->next;
        x->prev=head;
        head->next=x;
        temp->prev=x;
    }
    
    void deleteNode(node* x)
    {
        node* delprev=x->prev;
        node* delnext=x->next;
        delprev->next=delnext;
        delnext->prev=delprev;
    }
    
    int GET(int key)
    {
        if(mp.find(key)!=mp.end())
        {
            node* res=mp[key];
            mp.erase(key);
            deleteNode(res);
            addNode(res);
            mp[key]=head->next;
            return res->y;
        }
        
        return -1;
    }
    
    void SET(int key, int value)
    {
        if(mp.find(key)!=mp.end())
        {
            node* res=mp[key];
            mp.erase(key);
            deleteNode(res);
        }
        else if(mp.size()==size)
        {
            mp.erase(tail->prev->x);
            deleteNode(tail->prev);
        }
        
        addNode(new node(key,value));
        mp[key]=head->next;
        
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->SET(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->GET(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends