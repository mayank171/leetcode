class Solution {
public:
    int maxProduct(vector<int>& arr) {
        
        int n=arr.size();
        
        int max_left=1;
	    int maxi1=INT_MIN;
	    int max_right=1;
	    int maxi2=INT_MIN;
	    
	    for(int i=0;i<n;i++)
	    {
	        max_left=arr[i]*max_left;
            maxi1=max(maxi1,max_left);
	        if(max_left==0)
            {
                max_left=1;
	            //continue;      
            }
	        
           // cout<<maxi1<<endl;
	    }
	    
	    for(int i=n-1;i>=0;i--)
	    {
	        max_right=arr[i]*max_right;
	        maxi2=max(maxi2,max_right);
            if(max_right==0)
	        {
                max_right=1;
	            //continue;     
            }
          //  cout<<maxi2<<endl;
        }
	    
	    return max(maxi1,maxi2);
    }
};