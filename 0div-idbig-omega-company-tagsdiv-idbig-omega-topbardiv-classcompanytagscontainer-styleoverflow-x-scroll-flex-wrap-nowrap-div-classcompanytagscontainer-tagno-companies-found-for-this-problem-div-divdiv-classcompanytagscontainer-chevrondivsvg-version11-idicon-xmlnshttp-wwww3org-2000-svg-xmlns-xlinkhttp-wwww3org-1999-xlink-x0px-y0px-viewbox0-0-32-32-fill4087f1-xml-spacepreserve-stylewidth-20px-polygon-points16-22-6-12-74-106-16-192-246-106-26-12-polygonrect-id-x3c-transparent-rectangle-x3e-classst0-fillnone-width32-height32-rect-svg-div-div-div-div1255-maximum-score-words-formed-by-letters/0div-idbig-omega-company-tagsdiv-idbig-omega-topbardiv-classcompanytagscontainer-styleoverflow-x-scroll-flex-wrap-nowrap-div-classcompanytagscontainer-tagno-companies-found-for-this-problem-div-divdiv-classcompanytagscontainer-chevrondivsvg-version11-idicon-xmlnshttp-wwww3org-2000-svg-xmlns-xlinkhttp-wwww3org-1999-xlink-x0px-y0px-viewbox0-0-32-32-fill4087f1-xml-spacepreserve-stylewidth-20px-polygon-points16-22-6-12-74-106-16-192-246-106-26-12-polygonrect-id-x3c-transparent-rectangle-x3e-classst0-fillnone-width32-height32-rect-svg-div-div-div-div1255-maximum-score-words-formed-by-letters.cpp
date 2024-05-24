class Solution {
public:
    
    void solve(vector<string> &words,int n,int ind,int &maxi,int &cur,map<char,int> &mp,multiset<char> &st, vector<int> &freq)
    {
        if(ind==n)
        {
            maxi=max(maxi,cur);
            return ;
        }
        
        int flag=0;
        map<char,int> mp1;
        for(int i=0;i<words[ind].size();i++)
        {
            mp1[words[ind][i]]++;
        }
        
        for(auto &it:mp1)
        {
            if(it.second>freq[it.first-'a'])
            {
                flag=1;
                break;
            }
        }
        
        if(flag==0)
        {
            int score=0;
            multiset<char> st1;
            vector<int> freq1(26,0);
            for(int i=0;i<words[ind].size();i++)
            {
                if(mp.find(words[ind][i])!=mp.end())
                {
                    if(st.find(words[ind][i])!=st.end())
                    {
                        auto it=st.find(words[ind][i]);
                        score+=mp[words[ind][i]];
                        st.erase(it);
                        st1.insert(words[ind][i]);
                        freq1[words[ind][i]-'a']++;
                        freq[words[ind][i]-'a']--;
                    }
                }
            }

            cur+=score;
            solve(words,n,ind+1,maxi,cur,mp,st,freq);
            cur-=score;

            for(auto &it:st1)
                st.insert(it);
            
            for(int i=0;i<26;i++)
            {
                freq[i]+=freq1[i];
            }
        }
        
        solve(words,n,ind+1,maxi,cur,mp,st,freq);
    }
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        
        map<char,int> mp;
        multiset<char> st;
        vector<int> freq(26,0);
        for(int i=0;i<letters.size();i++)
        {
            freq[letters[i]-'a']++;
            st.insert(letters[i]);
            mp[letters[i]]=score[letters[i]-'a'];
        }
        
        int maxi=0;
        int cur=0;
        int n=words.size();
        
        solve(words,n,0,maxi,cur,mp,st,freq);
        
        return maxi;
    }
};