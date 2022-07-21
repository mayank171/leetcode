class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int i=-1;
        int j=-1;
        int l=s.length();
        int ans=0;
        
        map<char,int> mp;
        
        while(true)
        {
            int flag1=0;
            int flag2=0;
            
            //acquire
            while(i<l-1)
            {
                flag1=1;
                i++;
                mp[s[i]]++;
                if(mp[s[i]]>1)
                    break;
                else
                {
                    int size=mp.size();
                    if(size>ans)
                    {
                        ans=size;
                    }
                }
                
            }
            
            //release
            while(j<i)
            {
                flag2=1;
                j++;
                mp[s[j]]--;
                if(mp[s[j]]==0)
                    mp.erase(s[j]);
                else if(mp[s[j]]==1)
                    break;
            }
            
            if(flag1==0 && flag2==0)
                break;
        }
        
        return ans;
    }
};