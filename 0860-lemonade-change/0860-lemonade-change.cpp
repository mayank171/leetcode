class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        
        map<int,int> m;
        
        
       
        for(int i=0;i<bills.size();i++)
        {
            if(bills[i]==5)
            {
              
                m[bills[i]]++;
            }
            else if(bills[i]==10)
            {
                if(m[5]==0)
                    return false;
                else
                {
                     
                     m[10]++;
                     m[5]--;
                }
                   
            }
            else
            {
               if(m[10]==0)
               {
                   if(m[5]<3)
                   {
                       return false;
                   }
                   else
                   {
                        
                       
                        m[5]-=3;
                      
                        
                   }
               }   
               else if(m[10]>0 && m[5]>0)
               {
                     
                     m[10]--;
                     m[5]--;
               }
               else
               {
                   return false;
               }
            }
        }
        
        return true;
        
        
    }
};