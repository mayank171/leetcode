class Solution {
public:
    int blackBox(string s,string p,vector<int> &removable,int mid,int n)
    {
        string temp=s;
        
        for(int i=0;i<mid;i++)
        {
            temp[removable[i]]='-';
        }
        
        int ind=0;
        int l=temp.length();
        int p_l=p.length();
        for(int i=0;i<l;i++)
        {
            if(temp[i]==p[ind])
            {
                ind++;
            }
            if(ind==p_l)
                return 1;
        }
        
        return 0;
    }
    
    
    int maximumRemovals(string s, string p, vector<int>& removable) {
        
        int n=removable.size();
        
        int low=0;
        int high=n;
        int ans=0;
        
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            
            int pk=blackBox(s,p,removable,mid,n);
            
            if(pk==1)
            {
                ans=mid;
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