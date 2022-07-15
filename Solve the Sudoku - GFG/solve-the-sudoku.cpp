// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


 // } Driver Code Ends
class Solution 
{
    bool canPlace(int matrix[9][9],int k,int i1,int j1)
{
    for(int i=0;i<9;i++)
    {
        if(matrix[i][j1]==k)
            return false;
    }
    
    for(int i=0;i<9;i++)
    {
        if(matrix[i1][i]==k)
            return false;
    }
    
    // int v1[3]={0,3,6};
    // int v2[3]={0,3,6};
    
    // int row=*lower_bound(v1,v1+3,i1);
    // int col=*lower_bound(v2,v2+3,j1);
    
    int p=i1/3*3;
    int q=j1/3*3;
    
    
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(matrix[i+p][j+q]==k)
                return false;
        }
    }
    return true;
}

bool check(int matrix[9][9],int i,int j,int n,int m)
{
    
    if(j==9)
    {
        j=0;
        i++;
    }
    
    if(i==9)
    {
        return true;
    }
    
            if(matrix[i][j]==0)
            {
                for(int k=1;k<=9;k++)
                {
                    if(canPlace(matrix,k,i,j))
                    {
                        matrix[i][j]=k;
                        if(check(matrix,i,j+1,n,m))
                            return true;
                        matrix[i][j]=0;
                    }
           
                }
           }
           else
           {
               
               if(check(matrix,i,j+1,n,m))
                   return true;
           }
               
    return false;
}
    public:
    //Function to find a solved Sudoku. 
    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here
        if(check(grid,0,0,9,9))
             return true;
        return false;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here 
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                cout<<grid[i][j]<<" ";
            }
        
        }
    }
};

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}  // } Driver Code Ends