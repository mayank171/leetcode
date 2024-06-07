class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        
        
        int n=sentence.size();
        string ans="";
        set<string> st;
        
        for(int i=0;i<dict.size();i++)
        {
            st.insert(dict[i]);
        }
        
        
        for(int i=0;i<n;i++)
        {
            int j=i;
            string s="";
            int flag=0;
            while(j<n && sentence[j]!=' ')
            {
                if(flag==0)
                {
                    s+=sentence[j];
                    if(st.find(s)!=st.end())
                    {
                        ans+=s;
                        flag=1;
                    }    
                }
                j++;
            }
            if(flag==0)
                ans+=s;
            ans+=' ';
            i=j;
        }
        
        ans.pop_back();
        
        return ans;
    }
};