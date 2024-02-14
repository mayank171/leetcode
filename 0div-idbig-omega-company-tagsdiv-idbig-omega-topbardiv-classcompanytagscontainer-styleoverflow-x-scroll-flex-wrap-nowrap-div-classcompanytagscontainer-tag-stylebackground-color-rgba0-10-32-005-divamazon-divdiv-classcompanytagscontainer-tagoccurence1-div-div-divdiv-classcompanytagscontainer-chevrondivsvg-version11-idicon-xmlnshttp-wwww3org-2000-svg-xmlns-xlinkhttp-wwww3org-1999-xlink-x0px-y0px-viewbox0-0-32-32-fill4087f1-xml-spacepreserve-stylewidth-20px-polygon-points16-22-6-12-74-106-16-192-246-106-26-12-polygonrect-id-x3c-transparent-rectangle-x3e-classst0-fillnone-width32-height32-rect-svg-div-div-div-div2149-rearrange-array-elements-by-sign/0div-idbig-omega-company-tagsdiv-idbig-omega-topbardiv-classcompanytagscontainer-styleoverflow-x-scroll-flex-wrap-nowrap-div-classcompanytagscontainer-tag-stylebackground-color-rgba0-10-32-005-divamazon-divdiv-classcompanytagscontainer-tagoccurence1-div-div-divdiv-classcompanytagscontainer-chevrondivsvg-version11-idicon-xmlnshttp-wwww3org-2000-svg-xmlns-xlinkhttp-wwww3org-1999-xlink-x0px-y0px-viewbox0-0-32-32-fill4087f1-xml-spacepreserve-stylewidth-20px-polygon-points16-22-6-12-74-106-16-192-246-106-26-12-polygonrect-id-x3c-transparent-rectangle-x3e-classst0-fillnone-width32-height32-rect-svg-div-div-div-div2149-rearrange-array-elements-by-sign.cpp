class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        queue<int> neg;
        queue<int> pos;
        
        int size=nums.size();
        
        for(int i=0;i<size;i++){
            
            if(nums[i]<0)
            {
                neg.push(nums[i]);
            }
            else
            {
                pos.push(nums[i]);
            }
            
        }
        
        int flag=1;
        
        for(int i=0;i<size;i++)
        {
            if(flag==1)
            {
                nums[i]=pos.front();
                pos.pop();
            }
            else
            {
                nums[i]=neg.front();
                neg.pop();    
            }
            
            flag*=-1;
        }
        
        return nums;
    }
};