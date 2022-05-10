class Solution {
public:
    int uniquePaths(int m, int n) {
        
        
    vector<int> prev(n,0);
	
	for(int i=0;i<m;i++)
	{
		vector<int> temp(n,0);
		temp[0]=1;
		for(int j=1;j<n;j++)
		{
			temp[j]=temp[j-1]+prev[j];
		}
		prev=temp;
	}
	
	return prev[n-1];
        
        
    }
};