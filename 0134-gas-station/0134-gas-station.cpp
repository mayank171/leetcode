class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n=gas.size();
        
        for(int i=0;i<n;i++)
        {
            gas.push_back(gas[i]);
            cost.push_back(cost[i]);
        }
        
        int cur=0;
        int ind=-1;
        int ct=0;
        
        for(int i=0;i<2*n;i++)
        {
            
            if(cur+gas[i]-cost[i]>=0)
            {
                ct++;
          //      cout<<i<<endl;
                cur=cur+gas[i]-cost[i];
                if(ind==-1)
                   ind=i%n;
            }
            else
            {
                cur=0;
                ind=-1;
                ct=0;
            }
            
            if(ct==n)
                return ind;
        }
        
        cout<<ct<<endl;
        
        
        return -1;
        
    }
};