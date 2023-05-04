class Solution {
public:
    string predictPartyVictory(string senate) {
        
        int n=senate.size();
        
        set<int> r;
        set<int> d;
        
        for(int i=0;i<n;i++)
        {
            if(senate[i]=='R')
                r.insert(i);
            else
                d.insert(i);
        }
        
        while(r.size()>0 && d.size()>0)
        {
//           
            for(int i=0;i<n;i++)
            {
                if(senate[i]=='R' && r.find(i)!=r.end())
                {
                    auto it2=d.lower_bound(i);
                    if(it2!=d.end())
                    {
                        d.erase(it2);
                    }
                    else
                    {   
                        if(d.size()==0)
                           break;
                        d.erase(d.begin());
                    }
                }
                else if(senate[i]=='D' && d.find(i)!=d.end())
                {
                    auto it2=r.lower_bound(i);
                    if(it2!=r.end())
                    {
                        r.erase(it2);
                    }
                    else
                    {
                        if(r.size()==0)
                           break;
                        r.erase(r.begin());
                    }
                }
            }
        }
        
        if(r.size()==0)
            return "Dire";
        return "Radiant";
        
        if(r.size()>0)
            return "Radiant";
        return "Dire";
        
    }
};