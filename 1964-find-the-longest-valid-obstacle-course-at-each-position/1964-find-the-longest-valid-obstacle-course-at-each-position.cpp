class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obs) {
        
        int n=obs.size();
        vector<int> ans;
        
        vector<int> temp;
        for(int i=0;i<n;i++)
        {
            if(temp.size()==0)
            {
                temp.push_back(obs[i]);
                ans.push_back(1);
            }
            else
            {
                int ind=lower_bound(temp.begin(),temp.end(),obs[i])-temp.begin();
                if(ind==temp.size())
                {
                    temp.push_back(obs[i]);
                    ans.push_back(temp.size());
                }
                else if(temp[ind]==obs[i])
                {
                    int ind1=upper_bound(temp.begin(),temp.end(),obs[i])-temp.begin();
                    if(ind1==temp.size())
                    {
                        temp.push_back(obs[i]);
                        ans.push_back(temp.size());
                    }
                    else
                    {
                        temp[ind1]=obs[i];
                        ans.push_back(ind1+1);
                    }
                }
                else
                {
                    temp[ind]=obs[i];
                    ans.push_back(ind+1);
                }
            }
        }
        
        return ans;
    }
};