class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        
        int n=nums.size();
        int i=-1;
        int j=-1;
        multiset<int> st;
        int ans=0;
        
        while(true)
        {
            int flag1=0;
            int flag2=0;
            
            while(i<n-1)
            {
                flag1=1;
                i++;
                st.insert(nums[i]);
                
                int first=*(st.begin());
                int last=*(--st.end());
                
                if(last-first>limit)
                {
                    break;
                }
                else
                {
                    ans=max(ans,i-j);
                }
            }
            
            while(j<i && st.size()>0)
            {
                flag2=1;
                j++;
                auto it=st.find(nums[j]);
                if(it!=st.end())
                    st.erase(it);
                
                if(st.size()==0)
                    break;
                int first=*(st.begin());
                int last=*(--st.end());
                
                if(last-first<=limit)
                {
                    ans=max(ans,i-j);
                    break;
                }
            }
            
            if(flag1==0 && flag2==0)
                break;
        }
        
        return ans;
    }
};