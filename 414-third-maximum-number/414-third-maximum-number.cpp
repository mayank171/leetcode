class Solution {
public:
    int thirdMax(vector<int>& nums) {
        
        set<int> st;
        
        int n=nums.size();
        
        for(int i=0;i<n;i++)
        {
            st.insert(nums[i]);
        }
        
        long max1=LONG_MIN;
        long max2=LONG_MIN;
        long max3=LONG_MIN;
        
        for(auto &it:st)
        {
            if(it>max1)
            {
                max3=max2;
                max2=max1;
                max1=it;
            }
            else if(it>max2)
            {
                max3=max2;
                max2=it;
            }
            else if(it>max3)
            {
                max3=it;
            }
        }
        
        cout<<max2<<" "<<max3<<endl;
        
        if(max2==LONG_MIN || max3==LONG_MIN)
            return max1;
        
        return max3;
        
    }
};