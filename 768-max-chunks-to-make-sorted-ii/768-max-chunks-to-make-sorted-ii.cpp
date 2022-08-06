class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        
        int n=arr.size();
        
        vector<int> leftMax;
        leftMax.push_back(arr[0]);
        
        for(int i=1;i<n;i++)
        {
            leftMax.push_back(max(leftMax[i-1],arr[i]));
        }
        
        cout<<"lllssll"<<endl;
        leftMax.push_back(leftMax[leftMax.size()-1]);
        
        vector<int> rightMin(n+1);
        rightMin[n]=1e8;
        
        for(int i=n-1;i>=0;i--)
        {
            rightMin[i]=min(rightMin[i+1],arr[i]);
        }
        cout<<"vdvdv"<<endl;
        int ct=0;
        
        for(int i=0;i<n;i++)
        {
            if(leftMax[i]<=rightMin[i+1])
            {
                ct++;
            }
        }
        
        return ct;
    }
};