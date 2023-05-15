class Solution {
public:
    
    void heapify(vector<int> &temp,int i,int size)
    {
        int smallest=i;
        int left=2*i+1;
        int right=2*i+2;
        
        if(left<size && temp[left]<temp[smallest])
            smallest=left;
        if(right<size && temp[right]<temp[smallest])
            smallest=right;
        
        if(i!=smallest)
        {
            swap(temp[i],temp[smallest]);
            heapify(temp,smallest,size);
        }
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        
        int n=nums.size();
        vector<int> temp;
        for(int i=0;i<k;i++)
        {
            temp.push_back(nums[i]);
        }
        
        for(int i=k/2-1;i>=0;i--)
        {
            heapify(temp,i,k);
        }
        
        for(int i=k;i<n;i++)
        {
            if(nums[i]>temp[0])
            {
                temp[0]=nums[i];
                heapify(temp,0,k);
            }
        }
        
        return temp[0];
        
    }
};


















