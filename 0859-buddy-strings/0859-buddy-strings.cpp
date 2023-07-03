class Solution {
public:
    bool buddyStrings(string s, string goal) {
        
        int ind1=-1;
        int ind2=-1;
        
        int l1=s.length();
        int l2=goal.length();
        
        if(l1!=l2)
            return false;
        
        for(int i=0;i<l1;i++)
        {
            if(s[i]!=goal[i])
            {
                if(ind1==-1)
                {
                    ind1=i;
                }
                else if(ind2==-1)
                {
                    ind2=i;
                }
                else
                {
                    return false;
                }
            }
        }
        
        if(ind1!=-1 && ind2==-1)
        {
            return false;
        }
        else if(ind1==-1 && ind2==-1)
        {
            
            vector<int> freq(26,0);
            for(int i=0;i<l1;i++)
            {
                freq[s[i]-'a']++;
            }
            
            for(int i=0;i<26;i++)
            {
                if(freq[i]>=2)
                    return true;
            }
            
            return false;
        }
        
        swap(s[ind1],s[ind2]);
        
        for(int i=0;i<l1;i++)
        {
            if(s[i]!=goal[i])
                return false;
        }
        
        return true;
    }
};