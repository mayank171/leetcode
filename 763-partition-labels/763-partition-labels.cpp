class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        
        int l=s.length();
        
        vector<int> freq(26,0);
        
        for(int i=0;i<l;i++)
        {
            int x=s[i]-'a';
            freq[x]=i;
        }
        
        
        int start=-1;
        int end=-1;
        set<char> st;
        vector<int> ans;
        
        for(int i=0;i<l;i++)
        {
            if(start==-1)
            {
                start=i;
                end=i;
            }
            else
            {
                end++;
            }
            
            if(st.find(s[i])==st.end())
            {
                st.insert(s[i]);
            }
            
            if(freq[s[i]-'a']==i)
            {
                st.erase(s[i]);
            }

            if(st.size()==0)
            {
                ans.push_back(end-start+1);
                start=-1;
                end=-1;
            }
        }
        
        
        return ans;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
//         int l=s.length();
        
//         vector<int> arr(26,0);
        
//         for(int i=0;i<l;i++)
//         {
            
//             arr[s[i]-'a']=i;
//         }
        
        
        
//         int start=0;
//         int end=0;
        
//         vector<int> ans;
        
//         for(int i=0;i<l;i++)
//         {
//             end=max(end,arr[s[i]-'a']);
//             if(i==end)
//             {
//                 ans.push_back(end-start+1);
//                 start=end+1;
//             }
//         }
        
//         return ans;
        
    }
};