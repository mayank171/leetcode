//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class MyHashMap {
public:
    /** Initialize your data structure here. */
    vector<list<pair<int,int>>> nums;
    MyHashMap() {
        vector<list<pair<int,int>>> temp(100);
        nums=temp;
    }
    
    list<pair<int,int>> ::iterator search(int key)
    {
        int ind=key%100;
        
        auto it=nums[ind].begin();
        while(it!=nums[ind].end())
        {
            if(it->first==key)
               return it;
            ++it;
        }
        
        return it;
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        
        remove(key);
        int ind=key%100;
        nums[ind].push_back({key,value});
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        
        auto it=search(key);
        int ind=key%100;
        
        if(it==nums[ind].end())
        {
            return -1;
        }
        
        return it->second;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        
        int ind=key%100;
        if(search(key)==nums[ind].end())
        {
            return ;
        }
        else
        {
            nums[ind].erase(search(key));
        }
    }

};













//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        MyHashMap obj;
        int q;
        cin >> q;
        while (q--) {
            string s;
            cin >> s;
            if (s == "put") {
                int key, val;
                cin >> key >> val;
                obj.put(key, val);
            }
            else if ( s == "remove") {
                int key;
                cin >> key;
                obj.remove(key);
            }
            else {
                int key;
                cin >> key;
                cout << obj.get(key) << endl;
            }
        }
}
    return 0;
}

// } Driver Code Ends