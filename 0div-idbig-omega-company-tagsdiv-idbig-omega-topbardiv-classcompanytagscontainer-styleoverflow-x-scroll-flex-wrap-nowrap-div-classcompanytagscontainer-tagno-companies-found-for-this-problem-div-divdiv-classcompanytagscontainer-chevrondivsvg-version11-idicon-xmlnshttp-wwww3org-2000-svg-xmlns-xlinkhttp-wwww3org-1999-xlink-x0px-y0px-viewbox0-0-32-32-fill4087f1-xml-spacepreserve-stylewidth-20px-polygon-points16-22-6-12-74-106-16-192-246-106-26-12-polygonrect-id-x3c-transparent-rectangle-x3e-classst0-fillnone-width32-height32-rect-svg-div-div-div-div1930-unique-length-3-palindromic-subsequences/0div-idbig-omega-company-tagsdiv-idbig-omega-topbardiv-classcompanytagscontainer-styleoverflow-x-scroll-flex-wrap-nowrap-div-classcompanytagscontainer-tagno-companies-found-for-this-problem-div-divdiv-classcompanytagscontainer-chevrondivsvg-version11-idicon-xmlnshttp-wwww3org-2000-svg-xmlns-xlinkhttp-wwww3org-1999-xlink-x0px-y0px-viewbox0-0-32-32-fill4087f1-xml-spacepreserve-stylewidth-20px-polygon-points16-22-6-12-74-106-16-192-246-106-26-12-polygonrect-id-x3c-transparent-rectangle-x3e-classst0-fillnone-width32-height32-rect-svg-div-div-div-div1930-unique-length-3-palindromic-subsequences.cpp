class Solution {
public:
    
    int countPalindromicSubsequence(string s) {
        
        int n=s.length();
        
        unordered_map<char,int> left;
        unordered_map<char,int> right;
        
        for(int i=0;i<n;i++)
        {
            right[s[i]]++;
        }
        
        right[s[0]]--;
       // right[s[1]]--;
        left[s[0]]++;
        int ans=0;
        unordered_set<string> st;
        
        for(int i=1;i<n-1;i++)
        {
             right[s[i]]--;
           
            for(char ch='a';ch<='z';ch++)
            {
               // cout<<left[s[ch]]<<" "<<right[s[ch]]<<endl;
                if(left[ch]>0 && right[ch]>0)
                {
                    string str="";
                    str+=ch;
                    str+=s[i];
                    str+=ch;
                   // cout<<str<<endl;
                    st.insert(str);
                }
            }
            left[s[i]]++;
        }
        
        return st.size();
        
    }
};