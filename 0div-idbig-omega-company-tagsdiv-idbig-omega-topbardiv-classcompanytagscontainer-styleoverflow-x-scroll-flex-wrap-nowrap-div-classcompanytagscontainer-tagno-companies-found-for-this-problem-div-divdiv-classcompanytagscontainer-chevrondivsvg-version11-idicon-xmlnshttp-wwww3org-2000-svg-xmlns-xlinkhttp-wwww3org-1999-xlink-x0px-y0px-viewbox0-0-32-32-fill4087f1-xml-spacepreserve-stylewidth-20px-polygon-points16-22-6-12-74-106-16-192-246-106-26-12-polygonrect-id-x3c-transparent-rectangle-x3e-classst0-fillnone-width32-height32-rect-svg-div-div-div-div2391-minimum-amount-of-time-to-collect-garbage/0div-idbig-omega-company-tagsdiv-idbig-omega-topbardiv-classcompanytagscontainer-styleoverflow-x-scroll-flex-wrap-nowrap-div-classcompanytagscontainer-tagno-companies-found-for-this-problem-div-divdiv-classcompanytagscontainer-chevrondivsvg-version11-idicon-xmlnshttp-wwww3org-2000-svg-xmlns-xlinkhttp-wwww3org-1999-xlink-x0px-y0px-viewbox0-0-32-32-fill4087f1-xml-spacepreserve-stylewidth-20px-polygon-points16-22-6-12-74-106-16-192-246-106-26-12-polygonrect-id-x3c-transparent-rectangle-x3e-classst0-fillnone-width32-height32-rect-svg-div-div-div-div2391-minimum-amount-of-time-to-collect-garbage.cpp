class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        
        int n=garbage.size();
        
        int m=travel.size();
        int lastm=0;
        int lastp=0;
        int lastg=0;
        
        for(int i=0;i<n;i++)
        {
            int l=garbage[i].size();
            for(int j=0;j<l;j++)
            {
                if(garbage[i][j]=='M')
                    lastm++;
                else if(garbage[i][j]=='P')
                    lastp++;
                else if(garbage[i][j]=='G')
                    lastg++;
                
            }
        }
        
        int cost=lastm+lastg+lastp;
        
        int lastmi=1e8;
            int lastgi=1e8;
            int lastpi=1e8;
        
        for(int i=0;i<n;i++)
        {
            
            
            for(int j=0;j<garbage[i].size();j++)
            {
                if(garbage[i][j]=='P')
                {
                    lastpi=i;
                }
                else if(garbage[i][j]=='G')
                {
                    lastgi=i;
                }
                else if(garbage[i][j]=='M')
                {
                    lastmi=i;
                }
                 
            }
            
            
            
            
        }
        
          cout<<lastm<<endl;
            cout<<lastg<<endl;
            cout<<lastp<<endl;
        
            cout<<lastmi<<endl;
            cout<<lastgi<<endl;
            cout<<lastpi<<endl;
            
            
            for(int i=0;i<lastmi;i++)
            {
                if(lastmi==1e8)
                    break;
                cost+=travel[i];
            }
            
            for(int i=0;i<lastgi;i++)
            {
                if(lastgi==1e8)
                    break;
                cost+=travel[i];
            }
            
            for(int i=0;i<lastpi;i++)
            {
                if(lastpi==1e8)
                    break;
                cost+=travel[i];
            }
        
        
        return cost;
        
        
       
        
    }
};