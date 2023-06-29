class MedianFinder {
public:
    map<int,int> mp;
    int ct=0;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        mp[num]++;
        ct++;
    }
    
    double findMedian() {
        
        int x=ct/2;
        if(ct&1)
        {
            int x=ct/2+1;
            int t=0;
            for(auto &it:mp)
            {
                t+=it.second;
                if(t>=x)
                {
                    return it.first;
                }
            }
        }
        else
        {
            int x=ct/2;
       //     cout<<ct/2<<endl;
            int t=0;
            for(auto it=mp.begin();it!=mp.end();it++)
            {
                t+=it->second;
            //    cout<<t<<endl;
                if(t==x)
                {
                    double ans=it->first;
                    it++;
                    ans+=it->first;
                    return ans/2;
                }
                else if(t>x)
                {
                    double ans=it->first;
         //           cout<<ans<<endl;
                    ans+=ans;
                    return ans/2;    
                }
            }
            
        }
        
        return 0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */