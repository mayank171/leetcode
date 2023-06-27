class Twitter {
public:
    
    map<int,set<int>> mp;
    map<int,pair<int,int>,greater<int>> post;
    int tweetCt;
    
    Twitter() {
        tweetCt=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetCt++;
        post[tweetCt]={userId,tweetId};
        mp[userId].insert(userId);
        
        for(auto &it:mp)
        {
            cout<<it.first<<"->";
            for(auto &it1:it.second)
            {
                cout<<it1<<" ";
            }
            cout<<endl;
        }
    }
    
    vector<int> getNewsFeed(int userId) {
        
        cout<<"----"<<endl;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(auto &it:mp[userId])
        {
            cout<<userId<<" "<<it<<"frient"<<endl;
            for(auto &it1:post)
            {
                if(it1.second.first==it)
                {
                    if(pq.size()<10)
                    {
                        pq.push({it1.first,it1.second.second});
                    }
                    else
                    {
                        if(it1.first>pq.top().first)
                        {
                            pq.pop();
                            pq.push({it1.first,it1.second.second});
                        }
                    }
                }
            }
        }
        
        vector<int> ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        
        mp[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        
        mp[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */