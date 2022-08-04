class Solution {
public:
    
    long int blackBox(vector<int> &quant,int size,int n,long int mid)
    {
        long int ct=0;
        
        for(int i=0;i<size;i++)
        {
            ct+=ceil(quant[i]/(float)mid);
        }
        
        return ct;
    }
    
    
    int minimizedMaximum(int n, vector<int>& quant) {
        
        
        
        
        int size=quant.size();
        
        long int sum=0;
        
        
        for(int i=0;i<size;i++)
        {
            sum+=quant[i];
        }
        
        if(n>sum)
            return 1;
        
        long int low;
        long int high;
        
        
        if(sum%n!=0)
        {
            low=sum/n+1;
        }
        else
        {
            low=sum/n;
        }
        
        high=sum-(n-1);
        
        int ans=high;
        
        while(low<=high)
        {
            long int mid=low+(high-low)/2;
          //  cout<<low<<" "<<high<<" "<<mid<<endl;
            
            long int k=blackBox(quant,size,n,mid);
            
           // cout<<k<<endl;
            
            if(k<=n)
            {
                high=mid-1;
                ans=mid;
            }
            else
            {
                low=mid+1;
            }
        }
        
        return ans;
        
    }
};