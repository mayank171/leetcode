//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    
    string multiply(string &num1,string &num2)
    {
        int l1=num1.length();
        int l2=num2.length();
        vector<int> ans(l1+l2,0);
        int i=l1-1;
        int pf=0;
        
        while(i>=0)
        {
            int ival=num1[i]-'0';
            int carry=0;
            int k=l1+l2-1-pf;
            int j=l2-1;
            while(j>=0 || carry!=0)
            {
                int jval=(j>=0)?(num2[j]-'0'):0;
                int val=ival*jval+carry+ans[k];
                ans[k]=val%10;
                carry=val/10;
                j--;
                k--;
            }
            pf++;
            i--;
        }
        
        string res="";
        for(int i=0;i<l1+l2;i++)
        {
            res.push_back(ans[i]+'0');
        }
        
        
       // cout<<res<<endl;
        
        reverse(res.begin(),res.end());
    
        while(res.back()=='0')
        {
            res.pop_back();
        }
        
        reverse(res.begin(),res.end());
        
        if(res.size()==0)
           res="1";
        
        return res;
    }

    vector<int> factorial(int N){
        // code here
        string num1="1";
        string num2=to_string(N);
        int x=N;
        
        while(N)
        {
            num1=multiply(num1,num2);
       //     cout<<num1<<endl;
            N--;
            num2=to_string(N);
        }
        
        vector<int> ans;
        int l=num1.length();
        
        for(int i=0;i<l;i++)
        {
            ans.push_back(num1[i]-'0');
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends