//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Twitter {
  public:
    
     map<int,set<int>> mp;
    map<int,pair<int,int>,greater<int>> post;
    int tweetCt;
    // Initialize your data structure here
    Twitter() {
        tweetCt=0;
    }

    // Compose a new tweet
    void postTweet(int userId, int tweetId) {
        
          tweetCt++;
        post[tweetCt]={userId,tweetId};
        mp[userId].insert(userId);
        
    }

    // Retrieve the 10 most recent tweet ids as mentioned in question
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(auto &it:mp[userId])
        {
          //  cout<<userId<<" "<<it<<"frient"<<endl;
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

    // Follower follows a followee. If the operation is invalid, it should be a
    // no-op.
    void follow(int followerId, int followeeId) {
         mp[followerId].insert(followeeId);
    }

    // Follower unfollows a followee. If the operation is invalid, it should be
    // a no-op.
    void unfollow(int followerId, int followeeId) {
         mp[followerId].erase(followeeId);
    }
};

//{ Driver Code Starts.

int main() {
    Twitter obj;

    int total_queries;
    cin >> total_queries;
    while (total_queries--) {
        int query;
        cin >> query;

        // if query = 1, postTweet()
        // if query = 2, getNewsFeed()
        // if query = 3, follow()
        // if query = 4, unfollow()

        if (query == 1) {
            int userId, tweetId;
            cin >> userId >> tweetId;
            obj.postTweet(userId, tweetId);
        } else if (query == 2) {
            int userId;
            cin >> userId;
            vector<int> vec = obj.getNewsFeed(userId);
            for (int a : vec) cout << a << " ";
            cout << endl;
        } else if (query == 3) {
            int follower, followee;
            cin >> follower >> followee;
            obj.follow(follower, followee);
        } else {
            int follower, followee;
            cin >> follower >> followee;
            obj.unfollow(follower, followee);
        }
    }
    return 0;
}
// } Driver Code Ends