class Solution {
public:
    
     map<int,int> mp;
    
    void partition(vector<int> &arr1, int pivot,int low,int high)
    {
        int pindex=low;
        for(int i=low;i<=high;i++)
        {
            if(mp.find(arr1[i])==mp.end())
            {
                if(arr1[i]<pivot)
                {
                    swap(arr1[i],arr1[pindex]);
                    pindex++;    
                }
            }
            else if(mp[arr1[i]]<mp[pivot])
            {
                swap(arr1[i],arr1[pindex]);
                pindex++;
            }
        }
    }
    
    // static bool comp(int a,int b)
    // {
    //     if(mp.find(a)==mp.end() && mp.find(b)==mp.end())
    //     {
    //         if(a<b)
    //             return true;
    //         return false;
    //     }
    //     return false;
    // }
    
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        
        int n1=arr1.size();
        int n2=arr2.size();
        
        for(int i=0;i<n2;i++)
        {
            mp[arr2[i]]=i;
        }
        
        vector<int> v1;
        
        for(int i=0;i<n1;i++)
        {
            if(mp.find(arr1[i])!=mp.end())
                v1.push_back(arr1[i]);
        }
        
        int n=v1.size();
        for(int i=n2-1;i>=0;i--)
        {
            partition(v1,arr2[i],0,n-1);
        }
        
        for(auto &it:v1)
            cout<<it<<" ";
        cout<<endl;
        
        for(int i=0;i<n1;i++)
        {
            if(mp.find(arr1[i])==mp.end())
                v1.push_back(arr1[i]);
        }
        
        sort(v1.begin()+n,v1.end());
        
        return v1;
    }
};
