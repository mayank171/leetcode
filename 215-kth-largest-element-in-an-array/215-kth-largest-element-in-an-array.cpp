class Solution {
private:
    
     void heapify(vector<int> &v,int size,int i)
    {
        int small=i;
        int left=2*i+1;
        int right=2*i+2;
        
        if(left<size && v[small]>v[left])
            small=left;
        if(right<size && v[small]>v[right])
            small=right;
        if(small!=i)
        {
            swap(v[small],v[i]);
            heapify(v,size,small);
        }
    }
    
public:
    int findKthLargest(vector<int>& arr, int k) {
        
        int n=arr.size();
        
        vector<int> v(k);
        
        for(int i=0;i<k;i++)
        {
            v[i]=arr[i];
        }
        
        for(int i=k/2;i>=0;i--)
        {
            heapify(v,k,i);
        }
        
        // for(auto &it:v)
        // {
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        
        for(int i=k;i<n;i++)
        {
            if(arr[i]>v[0])
            {
                v[0]=arr[i];
                heapify(v,k,0);
            }
        }
        
        // for(auto &it:v)
        // {
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        
        return v[0];
    }
};