class Solution {
public:
    int largestVariance(string s) {
        
//         int n=s.length();
        
//         vector<map<char,int>> freq(26);
        
//         map<char,int> mp;
//         int ans=0;
        
//         for(int i=0;i<n;i++)
//         {
//             mp[s[i]]++;
            
//             if(freq[s[i]-'a'].size()==0)
//             {
//                  freq[s[i]-'a']=mp;
//             }
            
//             map<char,int,greater<int>> mp2;
//             for(auto &it:mp)
//             {
//                 mp2[it.first]=it.second;
//             }
            
//             cout<<"cdnvdnvk"<<endl;
            
//             for(auto &it:mp2)
//             {
//                 char ch=it.first;
//                 if(freq[ch-'a'].size()>0)
//                 {
//                     for(auto &it1:freq[ch-'a'])
//                     {
//                         mp2[it1.first]-=it1.second;
//                         if(mp2[it1.first]==0)
//                             mp2.erase(it1.first);
//                     }
//                 }
                
//                 if(mp2.size()>0)
//                 {
//                     int ct1=mp2.begin()->second;
//                     int ct2=prev(mp2.end())->second;
//                     ans=max(ans,abs(ct1-ct2));
//                 }
//             }
//         }
        
//         return ans;
        
        int res = 0;
        unordered_set<char> unique(begin(s), end(s));
        for (char a : unique)
            for (char b : unique) {
                int var = 0, has_b = 0, first_b = 0;
                for (auto ch : s) {
                    var += ch == a;
                    if (ch == b) {
                        has_b = true;
                        if (first_b && var >= 0)
                            first_b = false;
                        else if (--var < 0) {
                            first_b = true;
                            var = -1;
                        }
                    }
                    res = max(res, has_b ? var : 0);
                }
            }
        return res;
    }
};