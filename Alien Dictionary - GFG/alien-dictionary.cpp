//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string findOrder(string dict[], int n, int k) {
        
        map<char,set<char>> mp;
        
        for(int i=0;i<n-1;i++)
        {
            
                string s1=dict[i];
                string s2=dict[i+1];
                int l1=s1.length();
                int l2=s2.length();
                int ind1=0;
                int ind2=0;
                while(ind1<l1 && ind2<l2)
                {
                    if(s1[ind1]!=s2[ind2])
                    {
                        mp[s1[ind1]].insert(s2[ind2]);
                        break;
                    }
                    ind1++;
                    ind2++;
                }
            
        }
        
        map<char,int> indeg;
        for(auto &it:mp)
        {
            for(auto &it1:it.second)
            {
                indeg[it1]++;
            }
        }
        
        queue<char> q;
        
        for(auto &it:mp)
        {
            if(indeg[it.first]==0)
            {
                q.push(it.first);
            }
        }
        
        string ans="";
        
        while(!q.empty())
        {
            char ch=q.front();
            q.pop();
            
            ans+=ch;
            
            for(auto &it:mp[ch])
            {
                indeg[it]--;
                if(indeg[it]==0)
                {
                    q.push(it);
                }
            }
        }
        
        return ans;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends