class Node
{
    public:
    int x;
    int y;
    Node* next;
    Node* prev;
    
    Node(int x,int y)
    {
        this->x=x;
        this->y=y;
    }
};

class LRUCache {
public:
    Node* head;
    Node* tail;
    int size;
    map<int, Node*> mp;
    
    
    LRUCache(int capacity) {
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
        size=capacity;
    }
    
    int get(int key) {
        
        if(mp.find(key)==mp.end())
            return -1;
        else
        {
            Node* node=mp[key];
            Node* p=node->prev;
            Node* n=node->next;
            p->next=n;
            n->prev=p;
            head->next->prev=node;
            node->next=head->next;
            head->next=node;
            node->prev=head; 
            
            return node->y;
        }
    }
    
    void put(int key, int value) {
        
        if(mp.find(key)==mp.end())
        {
            if(mp.size()<size)
            {
                Node* node=new Node(key,value);
                head->next->prev=node;
                node->next=head->next;
                head->next=node;
                node->prev=head;    
                mp[key]=node;
            }
            else
            {
                mp.erase(tail->prev->x);
                Node* node=new Node(key,value);
                tail->prev->prev->next=tail;
                tail->prev=tail->prev->prev;
                head->next->prev=node;
                node->next=head->next;
                head->next=node;
                node->prev=head;    
                mp[key]=node;    
            }
        }
        else
        {
            Node* node=mp[key];
            node->y=value;
            Node* p=node->prev;
            Node* n=node->next;
            p->next=n;
            n->prev=p;
            head->next->prev=node;
            node->next=head->next;
            head->next=node;
            node->prev=head;    
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */