class Solution {
public:
    
    int solve(vector<int> &customers,vector<int> &grumpy,int n,int ind1,int ind2,int mid)
    {
        int ct=0;
        for(int i=0;i<n;i++)
        {
            if(i>=ind1 && i<=ind2)
                ct+=customers[i];
            else if(grumpy[i]==0)
                ct+=customers[i];
        }
        
        if(ct>=mid)
            return 1;
        return 0;
    }
    
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        
        int ind1=-1;
        int ind2=-1;
        int n=customers.size();
        
        int sum=0;
        int maxi=0;
        
        vector<int> g=grumpy;
        vector<int> c=customers;
        
        for(int i=0;i<n;i++)
        {
            if(grumpy[i]==0)
            {
                c[i]=0;
            }
        }
        
        for(int i=1;i<n;i++)
        {
            g[i]+=g[i-1];
        }
        
        
        for(int i=0;i<minutes;i++)
        {
            sum+=c[i];
        }
        
        int gc=g[minutes-1];
        int mgc=0;
        //cout<<sum<<endl;
        
        if(maxi<=sum)
        {
                maxi=sum;
                ind1=0;
                ind2=minutes-1;
        }
        
        for(int i=1;i<=n-minutes;i++)
        {
            sum-=c[i-1];
            sum+=c[i+minutes-1];
            //cout<<sum<<endl;
            //gc=g[i+minutes-1]-g[i-1];
            // if(mgc<gc)
            // {
            //     maxi=sum;
            //     ind1=i;
            //     ind2=i+minutes-1;
            // }
            // else if(mgc==gc)
            // {
                if(maxi<=sum)
                {
                    maxi=sum;
                    ind1=i;
                    ind2=i+minutes-1;
                }
            //}
        }
        
        cout<<ind1<<" "<<ind2<<endl;
        
        int low=0;
        int high=accumulate(customers.begin(),customers.end(),0);
        
        int ans=0;
        while(low<=high)
        {
            int mid=high+(low-high)/2;
            
            int kk=solve(customers,grumpy,n,ind1,ind2,mid);
            
            if(kk)
            {
                ans=max(ans,mid);
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        
        return ans;
    }
};



















