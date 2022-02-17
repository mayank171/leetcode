class Solution {
public:
    int minPartitions(string s) {
        
        int l=s.length();
        
        int maxi=INT_MIN;
        
        for(int i=0;i<l;i++)
        {
            if(s[i]-'0'>maxi)
                maxi=s[i]-'0';
        }
        
        return maxi;
        
    }
};