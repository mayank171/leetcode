class Solution {
public:
    int blackBox(vector<int> position,int n,int mid)
    {
        int ct=1;
        int pos=position[0];
        
        while(true)
        {
            pos+=mid;
            int ind=upper_bound(position.begin(),position.end(),pos)-position.begin();
          //  cout<<pos<<" "<<mid<<" "<<ind<<endl;
            if(ind>0 && position[ind-1]==pos)
            {
                ct++;
                pos=position[ind-1];
            }
            else if(ind<n)
            {
                ct++;
                pos=position[ind];
            }
            else if(ind==n)
            {
                break;
            }
        }
        return ct;
    }
    
    int maxDistance(vector<int>& position, int m) {
        
        int n=position.size();
        
        sort(position.begin(),position.end());
        
        int low=1;
        int high=position[n-1];
        int ans=high;
        
        while(low<=high)
        {
            int mid=low+(high-low)/2;
           // cout<<"mid"<<mid<<endl;
            int k=blackBox(position,n,mid);
           // cout<<k<<endl;
            if(k>=m)
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


























































