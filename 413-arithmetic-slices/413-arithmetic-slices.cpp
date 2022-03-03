class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int size=nums.size();
        
        if(size<3)
            return 0;
        
        
        queue<pair<int,int>> q;
        
        for(int i=0;i<size-2;i++)
        {
            if(abs(nums[i]-nums[i+1])==abs(nums[i+1]-nums[i+2]))
            {
                q.push({i,i+2});
            }
        }
        
        
        int ct=0;
        while(!q.empty())
        {
            int s=q.front().first;
            int e=q.front().second;
//             ct++;
            cout<<s<<" "<<e<<endl;
            
            int diff=nums[s]-nums[s+1];
            for(int i=s;i<size-2;i++)
            {
                if( nums[i]-nums[i+1]==diff && diff==nums[i+1]-nums[i+2])
                {
                    // if(i+2>e)
                    // {
                        cout<<i+2<<endl;
                        ct++;
//                     }
                
                }
                else
                {
                    break;
                }
                
            }
            q.pop();
        }
        
        return ct;
    }
};