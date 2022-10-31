class Solution {
public:
    int findShortestSubArray(vector<int>& a) {
        
        int n=a.size();
        map<int,int> mp;
    	map<int,pair<int,int>> mp1;
    	
    	for(int i=0;i<n;i++)
    	{
    	    mp[a[i]]++;
    	    mp1[a[i]]={-1,-1};
    	}
    	
    	int maxict=0;
    	for(auto &it:mp)
    	{
    	    if(it.second>maxict)
    	    {
    	        maxict=it.second;
    	    }
    	}
    	
    	vector<int> v;
    	
    	for(auto &it:mp)
    	{
    	    if(it.second==maxict)
    	    {
    	        v.push_back(it.first);
    	    }
    	}
    	
    	for(int i=0;i<n;i++)
    	{
    	    if(mp1[a[i]].first==-1)
    	    {
    	        mp1[a[i]].first=i;
    	        mp1[a[i]].second=i;
    	    }
    	    else
    	    {
    	        mp1[a[i]].second=i;
    	    }
    	}
    	
    	int mini=1e8;
    	for(int i=0;i<v.size();i++)
    	{
    	    mini=min(mini,mp1[v[i]].second-mp1[v[i]].first+1);
    	}
    	
    	return mini;
        
    }
};