class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b)
    {
        if(a[0]==b[0] && a[1]<b[1])
        {
            return false;
        }
        else if(a[0]==b[0] && a[1]>b[1])
        {
            return true;
        }
        else 
        {
            if(a[0]<b[0])
                return true;
            return false;
        }
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        
        sort(properties.begin(),properties.end(),comp);
        
        // for(auto &it:properties)
        // {
        //     cout<<it[0]<<' '<<it[1]<<endl;
        // }
        
        int ct=0;
        
        int n=properties.size();
        int min=properties[n-1][1];
        for(int i=n-2;i>=0;i--)
        {
            if(properties[i][1]>min)
                min=properties[i][1];
            else if(properties[i][1]<min)
                ct++;
        }
        
        return ct;
        
    }
};