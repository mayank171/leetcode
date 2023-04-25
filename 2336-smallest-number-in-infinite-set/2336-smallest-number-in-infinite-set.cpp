class SmallestInfiniteSet {
    
    set<int> st;
    
public:
    SmallestInfiniteSet() {
       
        for(int i=0;i<1000;i++)
        {
            st.insert(i+1);
        }
        
    }
    
    int popSmallest() {
        
        auto it=st.begin();
        int x=*it;
        if(it!=st.end())
            st.erase(it);
        return x;
        
    }
    
    void addBack(int num) {
        
        st.insert(num);
        
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */