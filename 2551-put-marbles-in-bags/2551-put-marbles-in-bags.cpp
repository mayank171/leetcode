class Solution {
public:
    
//     long long solve(vector<int> &v,int ind,int n,int k,int flag)
//     {
        
//         if(flag==0)
//         {
//             return v[ind]+solve(v,ind,n,k,1);
//         }
//         else
//         {
//             return max(v[ind]+solve(v,ind,n,k,0),0+solve(v,ind+1,n,))
//         }
//     }
    
    long long putMarbles(vector<int>& vp, int k) {
        
        int n=vp.size();
        vector<int> temp;
        for(int i=0;i<n-1;i++)
        {
            temp.push_back(vp[i]+vp[i+1]);
        }
        
        k--;
        sort(temp.begin(),temp.end());
        
        int ct=k;
        long long sum1=0;
        for(int i=n-2;i>=0;i--)
        {
            sum1+=temp[i];
            ct--;
            if(ct==0)
                break;
        }
        
        sum1+=vp[0];
        sum1+=vp[n-1];
        
        
        ct=k;
        long long sum2=0;
        for(int i=0;i<n-1;i++)
        {
            sum2+=temp[i];
            ct--;
            if(ct==0)
                break;
        }
        
        sum2+=vp[0];
        sum2+=vp[n-1];
        
        return sum1-sum2;
    }
};