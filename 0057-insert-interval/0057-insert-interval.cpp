class Solution {
public:
    
    int lower_bound(vector<vector<int>> arr, int N, int X)
    {
        int mid;

        int low = 0;
        int high = N;

        while (low < high) 
        {
            mid = low + (high - low) / 2;
     
            if (X <= arr[mid][0]) {
                high = mid;
            }

            else {
                low = mid + 1;
            }
        }

        if(low < N && arr[low][0] < X) {
           low++;
        }
        
        cout<<low<<endl;
        return low;
    }
    
    int upper_bound(vector<vector<int>> arr, int N, int X)
    {
        int mid;

        int low = 0;
        int high = N;

        while (low < high) 
        {
            mid = low + (high - low) / 2;

            if (X >= arr[mid][0]) {
                low = mid + 1;
            }

            else {
                high = mid;
            }
        }

        if(low < N && arr[low][0] <= X) {
           low++;
        }

        return low;
    }
    
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        if(intervals.size()==0)
        {
            return {newInterval};
        }
        
        if(newInterval[0]>intervals[intervals.size()-1][1])
        {
            intervals.push_back(newInterval);
            return intervals;
        }
        
        if(newInterval[0]>=intervals[intervals.size()-1][0] && newInterval[0]<=intervals[intervals.size()-1][1])
        {
            intervals[intervals.size()-1][1]=max(intervals[intervals.size()-1][1],newInterval[1]);
            return intervals;
        }
        
        int ind1=lower_bound(intervals,intervals.size(),newInterval[0]);
        
        if(ind1-1<intervals.size() && intervals[ind1-1][1]>=newInterval[0])
            ind1--;
        
        if(ind1<0)
            ind1++;
        
        cout<<ind1<<"--"<<endl;
        
        int ind2=upper_bound(intervals,intervals.size(),newInterval[1]);
        
        cout<<ind2<<endl;
        
        int minix=newInterval[0];
        int maxix=newInterval[1];
        
        for(int i=ind1;i<ind2;i++)
        {
            minix=min(minix,intervals[i][0]);
            maxix=max(maxix,intervals[i][1]);
        }
        
        vector<vector<int>> ans;
        for(int i=0;i<ind1;i++)
        {
            ans.push_back({intervals[i][0],intervals[i][1]});
        }
        
        ans.push_back({minix,maxix});
        
        for(int i=ind2;i<intervals.size();i++)
        {
            ans.push_back({intervals[i][0],intervals[i][1]});
        }
        
        return ans;
    }
};