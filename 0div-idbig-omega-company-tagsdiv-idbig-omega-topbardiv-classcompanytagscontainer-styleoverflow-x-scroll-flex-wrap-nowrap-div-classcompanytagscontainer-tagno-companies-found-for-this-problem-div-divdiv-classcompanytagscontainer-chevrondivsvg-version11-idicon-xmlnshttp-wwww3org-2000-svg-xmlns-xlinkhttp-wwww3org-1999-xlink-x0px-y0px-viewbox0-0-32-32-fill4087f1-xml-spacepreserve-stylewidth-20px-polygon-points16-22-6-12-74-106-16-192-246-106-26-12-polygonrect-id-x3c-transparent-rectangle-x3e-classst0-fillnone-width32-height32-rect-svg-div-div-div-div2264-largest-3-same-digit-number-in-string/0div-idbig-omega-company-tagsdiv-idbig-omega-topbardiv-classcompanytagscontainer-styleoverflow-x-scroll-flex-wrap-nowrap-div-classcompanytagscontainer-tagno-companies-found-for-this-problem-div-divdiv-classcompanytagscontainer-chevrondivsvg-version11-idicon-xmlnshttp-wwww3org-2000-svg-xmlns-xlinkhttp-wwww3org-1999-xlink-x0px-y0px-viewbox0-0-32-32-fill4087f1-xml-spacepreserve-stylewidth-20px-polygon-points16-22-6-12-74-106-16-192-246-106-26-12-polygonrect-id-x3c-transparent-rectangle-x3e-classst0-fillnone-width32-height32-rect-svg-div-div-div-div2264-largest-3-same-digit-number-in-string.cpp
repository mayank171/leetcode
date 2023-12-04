class Solution {
public:
    string largestGoodInteger(string nums) {
        
        string ans="";
        
        int n=nums.length();
        
        map<char,int> mp;
        
        int maxi=INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            int j=i;
            int ct=3;
            int ctr=0;
            while(ct-- && j<n)
            {
                if(nums[j]==nums[i])
                    ctr++;
                else
                    break;
                j++;
            }
            i=j;
            i--;
            if(ctr>=3)
               mp[nums[i]]=3;
            
        }
        
//         for(auto &it:mp)
//         {
//             cout<<it.first<<" "<<it.second<<endl;
//         }
        
        for(auto &it:mp)
        {
            if(it.second>=3)
            {
                maxi=max(maxi,it.first-'0');
            }
        }
        
        if(maxi!=INT_MIN)
        {
            char ch=maxi+'0';
            string res="";
            res+=ch;
            res+=ch;
            res+=ch;
            return res;
        }
        
        return ans;
    }
};