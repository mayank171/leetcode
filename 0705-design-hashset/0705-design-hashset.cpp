class MyHashSet {
public:
    
    vector<list<int>> v;
    
    MyHashSet() {
        vector<list<int>> temp(100);
        v=temp;
    }
    
    list<int> :: iterator search(int key)
    {
        int ind=key%100;
        
        return find(v[ind].begin(),v[ind].end(),key);
    }
    
    void add(int key) {
        
        if(contains(key))
            return ;
        int ind=key%100;
        v[ind].push_back(key);
    }
    
    void remove(int key) {
        
        if(!contains(key))
            return ;
        int ind=key%100;
        v[ind].erase(search(key));
    }
    
    bool contains(int key) {
        
        int ind=key%100;
        if(search(key)!=v[ind].end())
            return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */