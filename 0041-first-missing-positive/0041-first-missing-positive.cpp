class Solution {
public:
    int firstMissingPositive(vector<int>& arr) {
        
        int n=arr.size();
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]<0)
            {
                arr[i]=0;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]==0)
                continue;
            else
            {
                int pos=abs(arr[i]);
                pos--;
                if(pos>=0 && pos<n)
                {
                    if(arr[pos]>0)
                    {
                        arr[pos]*=-1;
                    }
                    else if(arr[pos]==0)
                    {
                        arr[pos]=-1*(n+1);
                    }
                }
            }
        }
        
        int ans=n+1;
        for(int i=1;i<=n;i++)
        {
            int pos=i-1;
            if(arr[pos]>=0)
            {
                ans=pos+1;
                break;
            }
        }
        
        return ans;
    }
};