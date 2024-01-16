class RandomizedSet {
public:
    
    vector<int> v;
    unordered_map<int,int> mp;
    
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
      
        if(mp.find(val)!=mp.end())
            return false;
        
        mp[val]=v.size();
        v.push_back(val);
        
        return true;
    }
    
    bool remove(int val) {
        
        if(mp.find(val)!=mp.end())
        {
            v[mp[val]]=v.back();
            mp[v.back()]=mp[val];
            v.pop_back();
            mp.erase(val);
            return true;
        }
        
        return false;
    }
    
    int getRandom() {
        
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */