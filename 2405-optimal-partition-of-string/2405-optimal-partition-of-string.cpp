class Solution {
public:
    int partitionString(string s) {
        
        int len=s.length();
        
        int ans=0;
        for(int i=0;i<len;i++)
        {
            int j=i;
            set<char> st;
        
            for(;j<len;j++)
            {
                if(st.find(s[j])==st.end())
                {
                    st.insert(s[j]);
                }
                else
                {
                    break;
                }
            }
            
            if(st.size()>0)
                ans++;
            
            i=j-1;
            
        }
        
        return ans;
        
        
    }
};