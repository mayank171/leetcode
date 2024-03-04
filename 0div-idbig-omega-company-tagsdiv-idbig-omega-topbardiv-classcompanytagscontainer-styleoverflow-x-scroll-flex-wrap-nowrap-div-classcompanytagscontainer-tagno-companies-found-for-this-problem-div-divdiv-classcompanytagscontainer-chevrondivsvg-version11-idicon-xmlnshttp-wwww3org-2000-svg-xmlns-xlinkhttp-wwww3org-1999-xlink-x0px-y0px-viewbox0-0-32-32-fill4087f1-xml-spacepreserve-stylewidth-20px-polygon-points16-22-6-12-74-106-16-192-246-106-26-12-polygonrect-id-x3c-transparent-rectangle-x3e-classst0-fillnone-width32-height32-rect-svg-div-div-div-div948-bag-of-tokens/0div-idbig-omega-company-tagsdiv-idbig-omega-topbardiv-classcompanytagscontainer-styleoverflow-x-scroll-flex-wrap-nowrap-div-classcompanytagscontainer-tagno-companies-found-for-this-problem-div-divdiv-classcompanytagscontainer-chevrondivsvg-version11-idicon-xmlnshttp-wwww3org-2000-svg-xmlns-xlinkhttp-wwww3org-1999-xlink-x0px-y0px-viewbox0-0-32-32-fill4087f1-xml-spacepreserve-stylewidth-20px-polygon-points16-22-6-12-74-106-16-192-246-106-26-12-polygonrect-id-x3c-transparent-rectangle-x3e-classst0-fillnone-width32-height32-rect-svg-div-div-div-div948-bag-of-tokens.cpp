class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        multiset<int> st1;
        multiset<int> st2;
        
        int n=tokens.size();
        
        for(int i=0;i<n;i++)
        {
            st1.insert(tokens[i]);
            st2.insert(tokens[i]);
        }
        
        int maxi=0;
        int score=0;
        while(st1.size()>0 && st2.size()>0)
        {
            if(power-*st1.begin()>=0)
            {
                int x=*st1.begin();
                power-=x;
                auto it=st1.begin();
                if(it!=st1.end())
                    st1.erase(it);
                if(st2.find(x)!=st2.end())
                {
                    st2.erase(x);
                }
                score++;
            }
            else if(score>0)
            {
                int x=*(--st2.end());
                power+=x;
                score--;
                auto it=--st2.end();
                if(it!=st2.end())
                    st2.erase(it);
                if(st1.find(x)!=st1.end())
                {
                    st1.erase(x);
                }
            }
            else
                break;
            
            maxi=max(maxi,score);
          //  cout<<power<<" "<<score<<endl;
        }
        
        return maxi;
    }
};