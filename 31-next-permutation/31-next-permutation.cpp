class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        
        int index=-1;
        
        int N=arr.size();
        
        for(int i=1;i<N;i++)
        {
            if(arr[i-1]<arr[i])
            {
                index=i;
            }
        }
        
        if(index==-1)
        {
            reverse(arr.begin(),arr.end());
            return ;
        }
        
        int lastInd=-1;
        for(int i=index+1;i<N;i++)
        {
            if(arr[index-1]<arr[i])
            {
                lastInd=i;
            }
        }
        
        if(lastInd==-1)
        {
            swap(arr[index],arr[index-1]);
            reverse(arr.begin()+index,arr.end());
            return ;
        }
        else
        {
            swap(arr[index-1],arr[lastInd]);
            reverse(arr.begin()+index,arr.end());    
        }
        
        
    }
};