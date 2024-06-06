class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        int n=hand.size();
        if(n%groupSize!=0)
            return false;
        
        map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[hand[i]]++;
        }
        
        while(mp.size()!=0)
        {
            auto it=mp.begin();
            int prev=it->first;
            mp[prev]--;
            if(mp[prev]==0)
                mp.erase(prev);
            int ct=1;
            while(ct<groupSize)
            {
                if(mp[prev+1]!=0)
                {
                    ct++;
                    mp[prev+1]--;
                    if(mp[prev+1]==0)
                        mp.erase(prev+1);
                    prev++;
                }
                else
                    return false;
            }
         //   cout<<"dv"<<endl;
        }
        
        return true;
    }
};