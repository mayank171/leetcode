class Solution {
public:
    int uniqueLetterString(string s) {
        
        int n=s.length();
        
        int res=0;
        set<int> st;
        for(int i=0;i<n;i++)
        {
            st.insert(s[i]);
        }
        
        vector<int> adj[27];
        
        for(int i=0;i<n;i++)
        {
            adj[s[i]-'A'].push_back(i);
        }
        
        for(int i=0;i<26;i++)
        {
            int ct=0;
            for(int j=0;j<adj[i].size();j++)
            {
                int prev=(j==0)?-1:adj[i][j-1];
                int next=(j==adj[i].size()-1)?n:adj[i][j+1];
                
              //  cout<<prev<<" "<<next<<endl;
                
                ct+=(adj[i][j]-prev)*(next-adj[i][j]);
            }
            res+=ct;
        }
        
        return res;
    }
};