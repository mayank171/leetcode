class Solution {
public:
    
    void solve(vector<string> &arr,int n,int ind,int &ct,int &maxi,set<char> &st)
    {
        if(ind>=n)
        {
            if(maxi<st.size())
                maxi=st.size();
            return ;
        }
        
        int flag=0;
        vector<int> freq(26,0);
        for(int i=0;i<arr[ind].size();i++)
        {
            if(st.find(arr[ind][i])!=st.end() || freq[arr[ind][i]-'a']==1)
            {
                flag=1;
                break;
            }
            
            freq[arr[ind][i]-'a']=1;
        }
        
        if(flag==0)
        {
            set<char> st1=st;
            for(int i=0;i<arr[ind].size();i++)
            {
                st.insert(arr[ind][i]);
            }
            solve(arr,n,ind+1,ct,maxi,st);
            solve(arr,n,ind+1,ct,maxi,st1);
        }
        else
        {
            solve(arr,n,ind+1,ct,maxi,st);    
        }
    }
    
    int maxLength(vector<string>& arr) {
        
        int n=arr.size();
        int ct=0;
        int maxi=0;
        
        set<char> st;
        solve(arr,n,0,ct,maxi,st);
        return maxi;
    }
};