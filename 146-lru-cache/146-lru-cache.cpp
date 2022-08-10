class LRUCache {
    
public:
    
    class node
    {
        public:
        int key;
        int val;
        node* next;
        node* prev;
        node(int _key,int _val)
        {
            key=_key;
            val=_val;
        }
    };
             
    node* head=new node(-1,-1);
    node* tail=new node(-1,-1);
    int cap;
    map<int,node*> mp;
    
    
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
             
             
    void addnode(node* temp)
    {
        temp->next=head->next;
        temp->prev=head;
        head->next->prev=temp;
        head->next=temp;
    }
             
    void delnode(node* temp)
    {
        node* prev=temp->prev;
        node* next=temp->next;
        prev->next=next;
        next->prev=prev;
    }
    
    int get(int key) {
        
        if(mp.find(key)!=mp.end())
        {
            node* temp=mp[key];
            int res=temp->val;
            mp.erase(key);
            delnode(temp);
            addnode(temp);
            mp[key]=head->next;
            return res;
        }
        
        return -1;
    }
    
    void put(int key, int value) {
        
        if(mp.find(key)!=mp.end())
        {
            node* temp=mp[key];
            mp.erase(key);
            delnode(temp);
        }
        if(mp.size()==cap)
        {
            mp.erase(tail->prev->key);
            delnode(tail->prev);
        }
        
        addnode(new node(key,value));
        mp[key]=head->next;
        
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */