// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string previousNumber(string s){
        // code here 
        
        int l=s.length();
        int smallest=l-1;
        int index=-1;
        
        for(int i=l-2;i>=0;i--)
        {
            if(s[i]<=s[smallest])
            {
                smallest=i;
            }
            else
            {
                index=i;
                break;
            }
           // cout<<index<<endl;
        }
        
        //cout<<index<<endl;
        
        if(index==-1)
           return "-1";
           
        int smallPos=-1;
        
        for(int i=l-1;i>index;i--)
        {
        
            if(s[i]<s[index])
            {
                if(smallPos==-1)
                  smallPos=i;
                else if(s[i]>=s[smallPos])
                  smallPos=i;
            }
          //  cout<<smallPos<<endl;
        }
        
        if(smallPos==-1)
           return "-1";
        
        if(s[smallPos]=='0' && index==0)
          return "-1";
        
        swap(s[index],s[smallPos]);
        
        return s;
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.previousNumber(S) << endl;
    }
    return 0; 
}   // } Driver Code Ends