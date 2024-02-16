class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        
        map<int,int> mp;
        map<int,vector<int>> mp1;
        
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]]++;
        }
        
        for(auto &it:mp)
        {
            mp1[it.second].push_back(it.first);
        }
        
        /*
            1-2,4
            2-1
            3-3
            3
        */
        
         int ans=0;
        for(auto &it:mp1)
        {
            while(k>0)
            {
                mp1[it.first].pop_back();
                
                if(k-it.first<0)
                {
                    ans++;
                }
                k-=it.first;
                
                if(mp1[it.first].size()==0)
                    break;
            }
            
            if(k<=0)
                break;
        }
        
        for(auto &it:mp1)
        {
            ans+=it.second.size();
        }
        
        return ans;
        /*
        
        4 3 5 3 3 6 6 2 5 6 7 8 4 6 2 
        5
        
        4-2
        3-3
        5-2
        6-4
        2-2
        7-1
        8-1
        
        8,7,2,2,6
        
        */
    }
};