class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        
        int n=arr.size();
        int ans=0;
        int p=0;
        
        for(int i=0;i<n;i++)
        {
            int right=n-i-p;
            int left=i+1-p;
            int total=right*left;
            if(total&1)
            {
                ans+=(arr[i]*((total/2)+1));
            }
            else
            {
                ans+=(arr[i]*(total/2));
            }
            //p++;
        }
        
        return ans;
//         for(int i=1;i<n;i++)
//         {
//             arr[i]+=arr[i-1];
//         }
        
//         for(auto &it:arr)
//         {
//             cout<<it<<" ";
//         }
//         cout<<endl;
 
//         int sum=arr[n-1];
//         for(int i=2;i<n;i+=2)
//         {
//             for(int j=i;j<n;j++)
//             {
//             //    cout<<j<<" "<<i<<endl;
//                 if(j-i>=0)
//                 {
//                     cout<<j<<endl;
//                     cout<<j-i-1<<endl;
//                     int x=((j-i-1>=0)?arr[j-i-1]:0);
//                     //cout<<arr[j]<<" "<<x<<endl;
//                     sum+=(arr[j]-x);
//                    // cout<<"cdcdc"<<endl;
//                 }
//                 else
//                     break;
//             }
//         }
        
//         return sum;
        
    }
};