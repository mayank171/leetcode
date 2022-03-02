class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        
        priority_queue<int> pq;
        pq.push(matrix[0][0]);
        
        for(int i=1;i<m;i++)
        {
            matrix[0][i]^=matrix[0][i-1];
            pq.push(matrix[0][i]);
        }
        
        for(int i=1;i<n;i++)
        {
            matrix[i][0]^=matrix[i-1][0];
            pq.push(matrix[i][0]);
        }
        
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                matrix[i][j]=matrix[i][j]^matrix[i-1][j]^matrix[i][j-1]^matrix[i-1][j-1];
                pq.push(matrix[i][j]);
            }
        }
        
        int ct=1;
        
        while(!pq.empty())
        {
            if(ct==k)
            {
                break;
            }
            
//             int x=pq.top();
//             cout<<x<<endl;
            pq.pop();
            ct++;
        }
        
        return pq.top();
        
    }
};