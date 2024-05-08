class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        
        vector<string> ans;
        map<int,string> mp;
        vector<int> temp=score;
        
        sort(score.rbegin(),score.rend());
        
        for(int i=0;i<score.size();i++)
        {
            if(i==0)
                mp[score[i]]="Gold Medal";
            else if(i==1)
                mp[score[i]]="Silver Medal";
            else if(i==2)
                mp[score[i]]="Bronze Medal";
            else
                mp[score[i]]=to_string(i+1);
        }
        
        for(int i=0;i<temp.size();i++)
        {
               ans.push_back(mp[temp[i]]);
        }
        
        return ans;
    }
};