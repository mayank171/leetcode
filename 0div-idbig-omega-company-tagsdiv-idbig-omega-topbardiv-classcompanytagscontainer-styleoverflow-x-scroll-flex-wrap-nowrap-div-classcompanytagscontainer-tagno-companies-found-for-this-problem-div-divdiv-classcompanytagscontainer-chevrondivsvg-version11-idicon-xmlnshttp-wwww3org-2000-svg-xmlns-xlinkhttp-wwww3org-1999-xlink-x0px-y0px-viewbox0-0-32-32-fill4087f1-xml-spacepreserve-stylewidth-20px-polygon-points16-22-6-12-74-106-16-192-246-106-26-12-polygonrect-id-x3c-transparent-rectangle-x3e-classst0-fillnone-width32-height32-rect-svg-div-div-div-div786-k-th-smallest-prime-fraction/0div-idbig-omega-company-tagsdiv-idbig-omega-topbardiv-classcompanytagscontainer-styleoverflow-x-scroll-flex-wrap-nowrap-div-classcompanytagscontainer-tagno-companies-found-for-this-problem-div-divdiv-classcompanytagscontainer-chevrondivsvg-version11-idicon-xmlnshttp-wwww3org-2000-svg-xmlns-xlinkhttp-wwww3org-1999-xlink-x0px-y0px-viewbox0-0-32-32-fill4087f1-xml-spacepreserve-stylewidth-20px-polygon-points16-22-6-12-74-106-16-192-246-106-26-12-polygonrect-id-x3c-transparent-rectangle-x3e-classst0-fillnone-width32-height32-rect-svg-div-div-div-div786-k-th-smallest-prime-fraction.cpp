class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        
        int n=arr.size();
        
        priority_queue<vector<double>,vector<vector<double>>,greater<vector<double>>> pq;
        
        for(int i=0;i<n-1;i++)
        {
            pq.push({1.0*arr[i]/arr[n-1],(double)i,(double)(n-1)});
        }
        
        int smallest=1;
        
        while(smallest<k)
        {
            vector<double> temp= pq.top();pq.pop();
            int i=temp[1];
            int j=temp[2];
            
            pq.push({1.0*arr[i]/arr[j-1],(double)i,(double)(j-1)});
            
            smallest++;
        }
        
        vector<double> temp=pq.top();
        int ii=arr[temp[1]];
        int jj=arr[temp[2]];
        
        return {ii,jj};
    }
};
























