class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        vector<int> deg(n+1,0);
        
        for(auto &it:trust)
        {
            int x=it[0];
            int y=it[1];
            
            deg[y]++;
            deg[x]--;
        }
        
        for(int i=1;i<=n;i++)
        {
            if(deg[i]==n-1)
              return i;
        }
        
        return -1;
    }
};