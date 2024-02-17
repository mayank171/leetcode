class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        int n=heights.size();
        
        priority_queue<int,vector<int>,greater<int>> pq;
        int ans=n-1;
        for(int i=0;i<n-1;i++)
        {
            int x=heights[i]-heights[i+1];
            if(x<0)
            {
                pq.push(abs(x));
                
                if(ladders>=pq.size())
                {
                    continue;
                   // ans=i+1;
                }
                else
                {
                    if(pq.top()<=bricks)
                    {
                        bricks-=pq.top();
                     //   ans=i+1;
                        pq.pop();
                    }
                    else
                    {
                        ans=i;
                        break;
                    }
                }
            }
        }
        
        return ans;
        
        /*
        
        8,5
        
        */
    }
};