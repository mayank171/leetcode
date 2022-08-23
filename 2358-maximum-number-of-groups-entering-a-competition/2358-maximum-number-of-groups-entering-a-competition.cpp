class Solution {
private:
    int blackBox(vector<int> &grades,int n,int mid)
    {
        int ind=1;
        int ct=0;
        int p=1;
        for(int i=0;i<n;i++)
        {
            if(p==ind)
            {
                ct++;
                p=1;
                ind++;
            }
            else
            {
                p++;
            }
        }
        
       // cout<<ct<<endl;
        
        if(ct>=mid)
            return 1;
        return 0;
    }
    
public:
    int maximumGroups(vector<int>& grades) {
        
        int n=grades.size();
        
        sort(grades.begin(),grades.end());
        
        int low=1;
        int high=n;
        
        int ans=1;
        
        while(low<=high)
        {
            //cout<<low<<" "<<high<<endl;
            int mid=low+(high-low)/2;
            //cout<<"mid "<<mid<<endl;
            int ki=blackBox(grades,n,mid);
            
            if(ki)
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