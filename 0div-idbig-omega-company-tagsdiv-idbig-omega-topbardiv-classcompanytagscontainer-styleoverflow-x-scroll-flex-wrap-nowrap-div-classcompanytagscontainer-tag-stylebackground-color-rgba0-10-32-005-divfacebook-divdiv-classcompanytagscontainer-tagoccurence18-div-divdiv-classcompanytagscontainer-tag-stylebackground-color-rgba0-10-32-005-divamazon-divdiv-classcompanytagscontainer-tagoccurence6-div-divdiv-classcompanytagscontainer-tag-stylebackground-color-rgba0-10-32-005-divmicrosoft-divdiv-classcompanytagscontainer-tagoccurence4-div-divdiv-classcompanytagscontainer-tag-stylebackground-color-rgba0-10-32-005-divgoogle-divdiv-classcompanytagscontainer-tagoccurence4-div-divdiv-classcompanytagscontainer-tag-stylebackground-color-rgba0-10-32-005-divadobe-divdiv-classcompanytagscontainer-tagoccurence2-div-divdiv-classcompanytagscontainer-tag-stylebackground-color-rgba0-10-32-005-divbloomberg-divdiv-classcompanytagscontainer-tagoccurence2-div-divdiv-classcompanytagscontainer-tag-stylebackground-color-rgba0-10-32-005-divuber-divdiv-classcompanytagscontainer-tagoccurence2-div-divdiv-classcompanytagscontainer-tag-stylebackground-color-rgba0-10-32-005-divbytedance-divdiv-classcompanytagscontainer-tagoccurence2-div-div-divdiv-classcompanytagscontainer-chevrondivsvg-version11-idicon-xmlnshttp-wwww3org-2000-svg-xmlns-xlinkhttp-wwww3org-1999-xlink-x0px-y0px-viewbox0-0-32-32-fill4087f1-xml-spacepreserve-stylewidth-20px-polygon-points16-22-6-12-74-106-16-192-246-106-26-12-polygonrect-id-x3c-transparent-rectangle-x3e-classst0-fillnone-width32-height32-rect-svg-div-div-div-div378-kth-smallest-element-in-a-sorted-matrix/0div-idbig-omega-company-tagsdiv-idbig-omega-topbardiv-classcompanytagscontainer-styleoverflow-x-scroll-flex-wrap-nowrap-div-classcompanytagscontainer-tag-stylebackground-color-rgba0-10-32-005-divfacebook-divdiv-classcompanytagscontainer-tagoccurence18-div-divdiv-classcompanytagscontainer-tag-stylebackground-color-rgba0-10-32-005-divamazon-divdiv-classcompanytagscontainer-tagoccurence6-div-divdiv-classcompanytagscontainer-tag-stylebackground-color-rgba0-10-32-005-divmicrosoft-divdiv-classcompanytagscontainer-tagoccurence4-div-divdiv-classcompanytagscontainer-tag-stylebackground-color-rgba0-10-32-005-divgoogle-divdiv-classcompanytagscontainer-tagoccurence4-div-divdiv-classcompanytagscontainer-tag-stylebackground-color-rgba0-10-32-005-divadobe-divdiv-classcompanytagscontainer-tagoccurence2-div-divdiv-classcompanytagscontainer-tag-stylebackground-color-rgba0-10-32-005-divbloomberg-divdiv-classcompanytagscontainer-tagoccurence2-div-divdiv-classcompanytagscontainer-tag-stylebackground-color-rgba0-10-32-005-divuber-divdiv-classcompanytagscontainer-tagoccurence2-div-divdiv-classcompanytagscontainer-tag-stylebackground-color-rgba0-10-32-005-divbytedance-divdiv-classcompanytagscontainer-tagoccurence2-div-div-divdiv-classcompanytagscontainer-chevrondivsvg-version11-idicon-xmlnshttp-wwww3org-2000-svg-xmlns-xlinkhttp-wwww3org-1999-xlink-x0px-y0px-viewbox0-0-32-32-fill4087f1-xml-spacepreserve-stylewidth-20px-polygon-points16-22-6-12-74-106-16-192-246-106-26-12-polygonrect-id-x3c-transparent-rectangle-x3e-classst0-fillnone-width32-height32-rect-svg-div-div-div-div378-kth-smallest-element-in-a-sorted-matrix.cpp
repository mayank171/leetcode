class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        
        int n=matrix.size();
        int m=matrix[0].size();
        
        for(int i=0;i<n;i++)
        {
            pq.push({matrix[i][0],i,0});
        }
        
        int smallest=1;
        
        while(smallest<k)
        {
            vector<int> temp=pq.top();pq.pop();
            int i=temp[1];
            int j=temp[2];
            
            if(j+1<m)
            {
                pq.push({matrix[i][j+1],i,j+1});
            }
            smallest++;
        }
        
        vector<int> ans=pq.top();
        return ans[0];
    }
};