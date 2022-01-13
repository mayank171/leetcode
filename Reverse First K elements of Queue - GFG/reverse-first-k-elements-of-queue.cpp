// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k);
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        queue<int> ans = modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}// } Driver Code Ends


// User function Template for C++

// Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k) {
   
   
   stack<int> stk;
   
   int c=0;
   
   while(c<k)
   {
       int x=q.front();
       q.pop();
       stk.push(x);
       c++;
   }
   
   queue<int> q1;
   
   while(!stk.empty())
   {
       int x=stk.top();
       stk.pop();
       q1.push(x);
   }
   
   while(!q.empty())
   {
       int x=q.front();
       q1.push(x);
       q.pop();
   }
   
   
   return q1;
   
   
   
   
   
   
   
}