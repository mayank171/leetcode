// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
  public:
        string smallestNumber(string num)
        { 
            //code here.
            int l=num.length();
            vector<int> right(l,-1);
            
            int smallest=l-1;
            
            for(int i=l-2;i>0;i--)
            {
                if(num[i]>=num[smallest])
                   right[i]=smallest;
                else
                {
                   smallest=i;
                   right[i]=-1;
                }
            }
            
            int small=-1;
            
            for(int i=1;i<l;i++)
            {
                if(num[i]!='0')
                {
                    if(small==-1)
                    {
                        if(num[i]<num[0])
                           small=i;
                    }
                    else
                    {
                        if(num[i]<=num[small])
                           small=i;
                    }
                }
            }
            
            if(small!=-1)
            {
                swap(num[small],num[0]);
            }
            else
            {
                for(int i=1;i<l;i++)
                {
                    if(right[i]!=-1 && num[i]!=num[right[i]])
                    {
                        swap(num[i],num[right[i]]);
                        break;
                    }
                }
            }
            
            return num;
            
        } 
 
};

// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
       string s;
       cin >> s;
       Solution ob;
       cout <<ob.smallestNumber(s) << endl;
    }
return 0;
}

  // } Driver Code Ends