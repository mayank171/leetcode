class RangeFreqQuery {
private:
    unordered_map<int,vector<int>> mp;
    unordered_map<int,int> mp1;
    
public:
    RangeFreqQuery(vector<int>& arr) {
        int size=arr.size();
        
        for(int i=0;i<size;i++)
        {
           mp[arr[i]].push_back(i);     
        }
        
        for(auto &it:mp)
        {
            cout<<it.first<<endl;
            mp1[it.first]=it.second.size();
        }
    }
    
    int query(int left, int right, int value) {
        
        int back=upper_bound(mp[value].begin(),mp[value].end(),right)-mp[value].begin();
        int front=lower_bound(mp[value].begin(),mp[value].end(),left)-mp[value].begin();
        
        return back-front;
        
        
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */