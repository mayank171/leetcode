class Solution {
public:
    string getPermutation(int n, int k) {
        
        vector<int> temp;
        int fact=1;
        
        for(int i=1;i<n;i++)
        {
            temp.push_back(i);
            fact*=i;
        }
        
        temp.push_back(n);
        k--;
        
        string ans="";
        
        while(temp.size()>0)
        {
            ans+=to_string(temp[ceil(k/fact)]);
            temp.erase(temp.begin()+k/fact);
            k=(k%fact);
            if(temp.size()==0)
                break;
            fact=fact/temp.size();
        }
        
        return ans;
        
    }
};