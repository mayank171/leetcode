class MyHashMap {
public:
    
    vector<list<pair<int,int>>> nums;
    
    MyHashMap() {
        vector<list<pair<int,int>>> temp(100);
        nums=temp;
    }
    
    list<pair<int,int>> ::iterator search(int key)
    {
        int ind=key%100;
        
        auto it=nums[ind].begin();
        
        while(it!=nums[ind].end())
        {
            if(it->first==key)
                return it;
            ++it;
        }
        return it;
    }
    
    void put(int key, int value) {
        
        int ind=key%100;
        remove(key);
        nums[ind].push_back({key,value});
    }
    
    int get(int key) {
        
        int ind=key%100;
        list<pair<int,int>>::iterator x=search(key);
        if(x==nums[ind].end())
            return -1;
        return x->second;
    }
    
    void remove(int key) {
        
        int ind=key%100;
        if(search(key)==nums[ind].end())
        {
            return ;
        }
        else
        {
            nums[ind].erase(search(key));
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */