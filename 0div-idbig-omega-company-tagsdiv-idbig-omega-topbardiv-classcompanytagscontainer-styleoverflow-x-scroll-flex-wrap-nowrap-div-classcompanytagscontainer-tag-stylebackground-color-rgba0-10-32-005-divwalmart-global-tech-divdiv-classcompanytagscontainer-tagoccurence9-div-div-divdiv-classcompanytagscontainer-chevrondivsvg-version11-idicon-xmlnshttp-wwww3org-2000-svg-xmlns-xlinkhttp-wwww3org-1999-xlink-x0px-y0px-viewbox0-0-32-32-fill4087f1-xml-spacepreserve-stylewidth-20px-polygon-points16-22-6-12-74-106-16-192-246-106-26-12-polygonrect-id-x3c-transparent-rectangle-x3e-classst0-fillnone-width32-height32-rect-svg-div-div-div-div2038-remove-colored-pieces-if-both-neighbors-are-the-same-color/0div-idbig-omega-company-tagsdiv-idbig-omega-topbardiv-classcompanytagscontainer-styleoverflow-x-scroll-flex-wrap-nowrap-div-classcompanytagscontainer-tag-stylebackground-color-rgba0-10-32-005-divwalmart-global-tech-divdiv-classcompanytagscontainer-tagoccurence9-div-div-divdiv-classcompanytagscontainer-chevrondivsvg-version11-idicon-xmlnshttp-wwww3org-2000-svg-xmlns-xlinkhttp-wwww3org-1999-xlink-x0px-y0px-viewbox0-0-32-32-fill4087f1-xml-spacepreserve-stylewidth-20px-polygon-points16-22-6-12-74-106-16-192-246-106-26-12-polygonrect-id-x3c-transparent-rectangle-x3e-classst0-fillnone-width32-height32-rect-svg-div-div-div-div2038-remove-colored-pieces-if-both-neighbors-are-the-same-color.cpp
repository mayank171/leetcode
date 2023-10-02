class Solution {
public:
    bool winnerOfGame(string s) {
        
        int n=s.length();
        
        priority_queue<int> pqA;
        priority_queue<int> pqB;
        
        for(int i=0;i<n;i++)
        {
            if(s[i]=='A')
            {
                int j=i;
                int ct=0;
                while(j<n && s[j]=='A')
                {
                    ct++;
                    j++;
                }
                
              //  cout<<ct<<endl;
                
                pqA.push(ct);
                i=j-1;
            }
            else if(s[i]=='B')
            {
                int j=i;
                int ct=0;
                while(j<n && s[j]=='B')
                {
                    ct++;
                    j++;
                }
                
            //    cout<<ct<<endl;
                
                pqB.push(ct);
                i=j-1;
            }
        }
        
        int flag=1;
        while(true)
        {
            if(flag==1)
            {
                if(pqA.size()==0)
                {
                    return false;
                }
                
                int x=pqA.top();
                pqA.pop();
                if(x>=3)
                {
                    x-=1;
                    if(x>0)
                       pqA.push(x);
                }
                else
                {
                    return false;
                }
            }
            else if(flag==-1)
            {
                if(pqB.size()==0)
                {
                    return true;
                }
                
                int x=pqB.top();
                pqB.pop();
                if(x>=3)
                {
                    x-=1;
                    if(x>0)
                       pqB.push(x);
                }
                else
                {
                    return true;
                }
            }
            flag*=-1;
        }

        return true;
    
    }
};










