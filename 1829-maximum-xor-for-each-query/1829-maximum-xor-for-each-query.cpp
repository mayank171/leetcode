class Solution {

private:
    
    vector<int> compute(vector<int>& nums,int size,int max)
    {
        
        vector<int> xorv;
        
        
        int temp=0;
        for(int i=0;i<size;i++)
        {
            xorv.push_back(temp^nums[i]);
            temp=temp^nums[i];
        }
        
        
        vector<int> ans;
        
        for(int i=size-1;i>=0;i--)
        {
            
            temp=xorv[i];
           
            for(int i=0;i<max;i++)
            {
                if(temp&(1<<i))
                {
                    temp=temp&(~(1<<i));
                }
                else
                {
                    temp=temp|(1<<i);
                }
            }
            ans.push_back(temp);
            
        }
        return ans;
    }
    
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        
      
        int N=nums.size();
        
        
        vector<int> ans=compute(nums,N,maximumBit);
        
        return ans;
        
    }
};