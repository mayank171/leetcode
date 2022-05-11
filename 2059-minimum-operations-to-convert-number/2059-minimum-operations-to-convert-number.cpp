

class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        
        int n=nums.size();
        
//         int mini=*min_element(nums.begin(),nums.end());
        
//         if(mini>goal)
//             return -1;
        
        set<long long>s ;
        
        queue<pair<long long,long long>> q;
        
        q.push({start,0});
        
        int ans=0;
        
        while(!q.empty())
        {
            
                    long long x=q.front().first;
                    long long ctr=q.front().second;
                    q.pop();
                    
                    if(x==goal)
                    {
                        return ctr;
                    }
                    
                    if(x<0 || x>1000 || s.find(x)!=s.end())
                        continue;
                    
                    s.insert(x);
                    
                    int flag=0;
                    for(int i=0;i<n;i++)
                    {
                        long long a=x+nums[i];
                        long long b=x-nums[i];
                        long long c=x^nums[i]; 
                        q.push({a,ctr+1});
                        //s.insert(a);         
                        q.push({b,ctr+1});
                        //s.insert(b);  
                        q.push({c,ctr+1});
                        //s.insert(c);  
                         
                    }
                ans++;
                
            }
            
        
        return -1;
        
        
    }
};