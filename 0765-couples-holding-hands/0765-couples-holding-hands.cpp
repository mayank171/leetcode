class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        
        int n=row.size();
        
        map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[row[i]]=i;
        }
        
        int ans=0;
        for(int i=0;i<n;i+=2)
        {
            int next=(row[i]&1)?row[i]-1:row[i]+1;
           // cout<<row[i]<<" "<<next<<endl;
            
            if(row[i+1]!=next)
            {
                int ind=mp[next];
                mp[next]=i;
                mp[row[i+1]]=ind;
                swap(row[i+1],row[ind]);  
                ans++;
            }
        }
        
        return ans;
    }
};