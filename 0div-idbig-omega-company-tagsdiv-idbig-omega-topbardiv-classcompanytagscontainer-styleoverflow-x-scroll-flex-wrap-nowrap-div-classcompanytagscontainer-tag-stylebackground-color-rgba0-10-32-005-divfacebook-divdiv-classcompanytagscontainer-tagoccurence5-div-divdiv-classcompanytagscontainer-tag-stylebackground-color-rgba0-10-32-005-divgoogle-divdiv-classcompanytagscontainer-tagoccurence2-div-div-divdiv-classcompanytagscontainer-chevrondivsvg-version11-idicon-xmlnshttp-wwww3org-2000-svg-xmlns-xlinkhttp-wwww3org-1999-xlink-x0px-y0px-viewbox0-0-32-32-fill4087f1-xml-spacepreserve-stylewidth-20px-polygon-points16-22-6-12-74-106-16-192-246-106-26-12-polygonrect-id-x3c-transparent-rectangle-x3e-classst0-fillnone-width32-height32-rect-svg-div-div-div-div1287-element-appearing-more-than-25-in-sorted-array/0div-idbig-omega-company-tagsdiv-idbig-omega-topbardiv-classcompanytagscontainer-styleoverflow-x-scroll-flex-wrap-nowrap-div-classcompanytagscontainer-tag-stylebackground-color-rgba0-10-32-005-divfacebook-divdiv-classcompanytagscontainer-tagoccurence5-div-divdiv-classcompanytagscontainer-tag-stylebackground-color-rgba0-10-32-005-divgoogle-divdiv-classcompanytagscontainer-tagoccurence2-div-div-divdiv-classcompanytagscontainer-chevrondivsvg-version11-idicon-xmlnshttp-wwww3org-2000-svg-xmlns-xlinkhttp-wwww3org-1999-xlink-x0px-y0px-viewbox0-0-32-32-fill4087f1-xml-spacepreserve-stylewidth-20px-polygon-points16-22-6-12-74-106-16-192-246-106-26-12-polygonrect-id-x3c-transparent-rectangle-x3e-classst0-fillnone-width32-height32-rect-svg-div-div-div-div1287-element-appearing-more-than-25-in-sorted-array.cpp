class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        
        int n=arr.size();
        
        float ctr=n*(25.0/100.0);
        
        int x;
        if(ctr-floor(ctr)==0)
        {
            x=ctr+1;
        }
        else
        {
            x=ceil(ctr);
        }
        
        
        cout<<x<<endl;
        
        for(int i=0;i<n;i++)
        {
            int ct=0;
            int val=arr[i];
            int j=i;
            while(j<n && arr[j]==val)
            {
                ct++;
                j++;
            }
            
            i=j-1;
            
            if(ct>=x)
                return arr[i];
        }
        
        
        
        return 0;
    }
};

/*



*/