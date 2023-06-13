class MyHashSet {
public:
    
    vector<list<int>> nums;
    
    MyHashSet() {
        
        vector<list<int>> temp(100);
        nums=temp;
    }
    
    list<int> :: iterator search(int key)
    {
        int ind=key%100;
        
        return find(nums[ind].begin(),nums[ind].end(),key);
    }
    
    void add(int key) {
        
        if(contains(key))
            return ;
        int ind=key%100;
        nums[ind].push_back(key);
    }
    
    void remove(int key) {
        
        if(!contains(key))
            return ;
        
        int ind=key%100;
        nums[ind].erase(search(key));
    }
    
    bool contains(int key) {
        
        int ind=key%100;
        if(search(key)!=nums[ind].end())
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