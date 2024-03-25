class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
//         1 2 1 3 2 5
        
//             011
//             101
//             110
            
//         1 2 1 3 2     5
        
        int xxor=0;
        for(int i=0;i<nums.size();i++)
        {
            xxor^=nums[i];
        }
        
        int idx=0;
        for(int i=31;i>=0;i--)
        {
            int b=xxor&(1<<i);
            if(b)
            {
                idx=i;
                break;
            }
        }
        
        int xxor1=0;
        int xxor2=0;
        
        for(int i=0;i<nums.size();i++)
        {
            int b=nums[i]&(1<<idx);
            if(b)
                xxor2^=nums[i];
            else
                xxor1^=nums[i];
        }
        
        return {xxor1,xxor2};
    }
};