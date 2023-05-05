class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        vector<long long> v1;
        vector<long long> v2;
        int n=nums.size();
        
        for(int i=0;i<n;i++)
        {
            v1.push_back(nums[i]);
            v2.push_back(nums[i]);
        }
        
        for(int i=1;i<n;i++)
        {
            v1[i]+=v1[i-1];
        }
        
        if(v1.back()<x)
            return -1;
        
        for(int i=n-2;i>=0;i--)
        {
            v2[i]+=v2[i+1];
        }
        
        reverse(v2.begin(),v2.end());
        
//         for(auto &it:v1)
//         {
//             cout<<it<<" ";
//         }
//         cout<<endl;
        
//         for(auto &it:v2)
//         {
//             cout<<it<<" ";
//         }
//         cout<<endl;
        
        
        vector<int> mini;
        for(int i=0;i<n;i++)
        {
            if(v1[i]==x)
            {
                mini.push_back(i+1);
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(v2[i]==x)
            {
                mini.push_back(i+1);
            }
        }
        
        
        
        vector<pair<long long,pair<int,int>>> temp;
        
        for(int i=0;i<n;i++)
        {
            temp.push_back({v1[i],{1,i+1}});
        }
        
        for(int i=0;i<n;i++)
        {
            temp.push_back({v2[i],{2,i+1}});
        }
        
        
        sort(temp.begin(),temp.end());
        
//         for(auto &it:temp)
//         {
//             cout<<it.first<<","<<it.second.first<<","<<it.second.second<<" ";
//         }
//         cout<<endl;
        
        int i=0;
        int j=temp.size()-1;
        
        while(i<j)
        {
            //cout<<i<<" "<<j<<endl;
            if(temp[i].second.first!=temp[j].second.first)
            {
                if(temp[i].first+temp[j].first==x)
                {
                    mini.push_back(abs(temp[i].second.second+temp[j].second.second));
                    i++;
                    j--;
                }
                else if(temp[i].first+temp[j].first<x)
                {
                    i++;
                }
                else
                {
                    j--;
                }
                
            }
            else if(temp[i].first+temp[j].first<x)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        
        if(mini.size()==0)
            return -1;
        
        sort(mini.begin(),mini.end());
        
        return mini[0];
    }
};














