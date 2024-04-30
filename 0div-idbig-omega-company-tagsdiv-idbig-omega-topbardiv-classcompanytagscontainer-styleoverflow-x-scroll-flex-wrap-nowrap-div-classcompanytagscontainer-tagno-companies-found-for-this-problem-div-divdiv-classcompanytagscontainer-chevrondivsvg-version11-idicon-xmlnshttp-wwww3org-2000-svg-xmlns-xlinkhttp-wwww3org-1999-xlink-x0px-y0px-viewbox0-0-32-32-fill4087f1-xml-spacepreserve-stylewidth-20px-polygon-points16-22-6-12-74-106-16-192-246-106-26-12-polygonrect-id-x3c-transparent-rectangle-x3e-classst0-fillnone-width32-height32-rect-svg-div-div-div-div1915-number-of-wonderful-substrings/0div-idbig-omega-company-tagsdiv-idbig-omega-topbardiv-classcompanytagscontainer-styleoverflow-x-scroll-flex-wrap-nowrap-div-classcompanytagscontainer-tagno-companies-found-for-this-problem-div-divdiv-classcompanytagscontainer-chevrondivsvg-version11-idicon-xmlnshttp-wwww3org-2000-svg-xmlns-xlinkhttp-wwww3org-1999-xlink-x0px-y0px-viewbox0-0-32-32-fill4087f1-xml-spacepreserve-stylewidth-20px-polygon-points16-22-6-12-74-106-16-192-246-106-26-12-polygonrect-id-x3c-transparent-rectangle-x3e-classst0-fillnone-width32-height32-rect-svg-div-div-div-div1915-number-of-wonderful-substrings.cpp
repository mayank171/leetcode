class Solution {
public:
    long long wonderfulSubstrings(string word) {
        
        int n=word.size();
        vector<int> freq(1024,0);
        freq[0]=1;
        
        long long ans=0;
        int mask=0;
        for(int i=0;i<n;i++)
        {
            mask^=(1<<(word[i]-'a'));
            ans+=freq[mask];
            
            for(int j=0;j<10;j++)
            {
                ans+=freq[mask^(1<<j)];    
            }
            
            freq[mask]++;
        }
        
        return ans;
    }
};