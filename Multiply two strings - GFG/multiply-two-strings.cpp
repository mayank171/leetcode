//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2) {
       
       
         
         if(s1.compare("0")==0 || s2.compare("0")==0)
            return "0";
            
         int neg=0;
         if(s1[0]=='-')
         {
             reverse(s1.begin(),s1.end());
             s1.pop_back();
             reverse(s1.begin(),s1.end());
             neg++;
         }
         
         if(s2[0]=='-')
         {
             reverse(s2.begin(),s2.end());
             s2.pop_back();
             reverse(s2.begin(),s2.end());
             neg++;
         }
         
         
       
         int l1=s1.length();
         int l2=s2.length();
         
         int i=l2-1;
         
         vector<int> res(l1+l2,0);
         int pf=0;
         
         while(i>=0)
         {
             int ival=s2[i]-'0';
             i--;
             int carry=0;
             int k=l1+l2-1-pf;
             
             int j=l1-1;
             
             while(j>=0 || carry!=0)
             {
                 int jval=(j>=0)?(s1[j]-'0'):0;
                 j--;
                 int prod=ival*jval+carry+res[k];
                 
                 res[k]=prod%10;
                 carry=prod/10;
                 
                 k--;
             }
             
             pf++;
         }
         
         string ans="";
         int flag=0;
         for(int i=0;i<l1+l2;i++)
         {
             if(res[i]==0 && flag==0)
                continue;
             else
             {
                 flag=1;
                 ans+=(res[i]+'0');
             }
         }
         
         if(neg==1)
         {
             reverse(ans.begin(),ans.end());
             ans.push_back('-');
             reverse(ans.begin(),ans.end());
             
         }
         
         return ans;
       
    }

};

//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends