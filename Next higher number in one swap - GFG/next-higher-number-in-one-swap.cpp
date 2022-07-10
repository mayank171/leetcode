// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
string nxtHighUsingAtMostOneSwap(string num);

int main() {
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        cout << nxtHighUsingAtMostOneSwap(s) << endl;
    }
return 0;
}




// } Driver Code Ends


string nxtHighUsingAtMostOneSwap(string num) { 
    //complete the function here
    int l=num.length();
    
    int largest=l-1;
    int index=-1;
    
    for(int i=l-2;i>=0;i--)
    {
        if(num[i]>=num[largest])
           largest=i;
        else
        {
            index=i;
            break;
        }
    }
    
    if(index==-1)
        return "-1";
        
        
    int greatest=-1;
    
    for(int i=l-1;i>index;i--)
    {
        if(num[i]>num[index])
        {
            if(greatest==-1)
            {
                greatest=i;
            }
            else if(num[i]<=num[greatest])
            {
                greatest=i;
            }
        }
    }
    
    swap(num[index],num[greatest]);
    
    return num;
        

}