class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<int> v1;
        v1.push_back(1);
        
        if(rowIndex==0)
            return v1;
        
        
        for(int i=1;i<=rowIndex;i++)
        {
            vector<int> v2;
            v2.push_back(v1[0]);
            for(int j=0;j<v1.size()-1;j++)
            {
                v2.push_back(v1[j]+v1[j+1]);
            }
            v2.push_back(v1[v1.size()-1]);
            v1=v2;
        }
        
        return v1;
    }
};