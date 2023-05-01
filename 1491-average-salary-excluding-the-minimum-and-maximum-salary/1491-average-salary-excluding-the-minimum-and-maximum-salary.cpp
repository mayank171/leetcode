class Solution {
public:
    double average(vector<int>& salary) {
        
        int mini=1e9;
        int maxi=-1e9;
        
        for(int i=0;i<salary.size();i++)
        {
            mini=min(mini,salary[i]);
            maxi=max(maxi,salary[i]);
        }
        
        double sum=0;
        int ct=0;
        for(int i=0;i<salary.size();i++)
        {
            if(salary[i]!=mini && salary[i]!=maxi)
            {
               ct++;
               sum+=salary[i];     
            }
        }
        
        return sum/ct;
        
    }
};