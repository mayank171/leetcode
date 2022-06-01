class DetectSquares {
    map<pair<int,int>,int>mp;
public:
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        
        mp[{point[0],point[1]}]++;
        
    }
    
    int count(vector<int> point) {
        
        int x=point[0];
        int y=point[1];
        
        int ct=0;
        
        for(auto &it:mp)
        {
            if(abs(x-it.first.first)==abs(y-it.first.second) && x!=it.first.first && y!=it.first.second)
            {
                if(mp.find({it.first.first,y})!=mp.end() && mp.find({x,it.first.second})!=mp.end())
                {
                     ct+=mp[{it.first.first,it.first.second}]*mp[{it.first.first,y}]*mp[{x,it.first.second}];
                }
            }
        }
        
        return ct;
        
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */