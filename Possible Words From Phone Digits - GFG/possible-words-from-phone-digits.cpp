//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    
    void solve(int a[],int ind,int n,vector<string> &ans,string &temp,map<int,string> &mp)
    {
        if(ind==n)
        {
            ans.push_back(temp);
            return ;
        }
        
        int x=a[ind];
        for(auto &it:mp[x])
        {
            temp+=it;
            solve(a,ind+1,n,ans,temp,mp);
            temp.pop_back();
        }
    }
    
    vector<string> possibleWords(int a[], int N)
    {
        vector<string> ans;
        string temp="";
        
        map<int,string> mp;
        mp[2]="abc";
        mp[3]="def";
        mp[4]="ghi";
        mp[5]="jkl";
        mp[6]="mno";
        mp[7]="pqrs";
        mp[8]="tuv";
        mp[9]="wxyz";
        
        solve(a,0,N,ans,temp,mp);
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}
// } Driver Code Ends