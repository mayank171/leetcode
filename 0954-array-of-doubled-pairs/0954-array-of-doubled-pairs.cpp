class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        
        int n=arr.size();
        
        sort(arr.begin(),arr.end());
        
        vector<int> temp;
        
        multiset<int> st;
        
        for(int i=0;i<n;i++)
        {
            st.insert(arr[i]);
            // if(arr[i]&1)
            //     temp.push_back(-1);
            // else
            //     temp.push_back(arr[i]/2);
        }
        
        int ct=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]&1 || st.find(arr[i])==st.end())
                continue;
            
            auto it=st.find(arr[i]/2);
            
            if(it!=st.end())
            {
                 st.erase(it);
                 auto it1=st.find(arr[i]);
                 if(it1!=st.end())
                    st.erase(it1);
                 else
                    return false;
                 ct++;
            }   
        }
        cout<<ct<<endl;
        
        if(ct>=n/2)
            return true;
        return false;
    }
};