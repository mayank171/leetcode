//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    
    
    
    string caseSort(string str, int n)
    {
        string patt="";
        string small="";
        string big="";
        for(int i=0;i<n;i++)
        {
            if(str[i]>='a' && str[i]<='z')
            {
                patt+='l';
                small+=str[i];
            }
            else
            {
                patt+='u';
                big+=str[i];
            }
        }
        
        sort(small.begin(),small.end());
        sort(big.begin(),big.end());
        
        int ind1=0;
        int ind2=0;
        for(int i=0;i<n;i++)
        {
            if(patt[i]=='l')
            {
                str[i]=small[ind1];
                ind1++;
            }
            else if(patt[i]=='u')
            {
                str[i]=big[ind2];
                ind2++;
            }
            
        }
        
        return str;
        
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends