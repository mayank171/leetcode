class Solution {
private:
    int blackBox(vector<vector<int>> &matrix,int n,int mid)
    {
        int i=0;
        int j=n-1;
        int ct=0;
        int ctr=0;
        
        while(i<n && j>=0)
        {
            if(matrix[i][j]<=mid)
            {
                ct+=(j+1);
                i++;
            }
            else
            {
       
                j--;
            }
           // cout<<"ct"<<ct<<endl;
        }
        
        
        return ct+ctr;
    }
    
    
    
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int n=matrix.size();
        
        int low=matrix[0][0];
        int high=matrix[n-1][n-1];
        
        int ans=high;
        
        while(low<=high)
        {
            int mid=low+(high-low)/2;
           // cout<<mid<<" "<<low<<" "<<high<<endl;
            int rank=blackBox(matrix,n,mid);
            
            //cout<<rank<<endl;
            
            if(rank<k)
            {
                low=mid+1;
            }
            else if(rank>=k)
            {
                ans=mid;
                high=mid-1;
            }
  
        }
        
        return ans;
        
        
    }
};