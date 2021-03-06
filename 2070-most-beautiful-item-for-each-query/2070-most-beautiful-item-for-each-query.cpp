class Solution {
public:
    // static bool comp(vector<int> a,vector<int> b)
    // {
    //     if(a[0]<b[0])
    //         return true;
    //     return false;
    // }
    
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& q) {
        
        int n=items.size();
        
        int size=q.size();
        
        sort(items.begin(),items.end());
        
        
        unordered_set<int> s;
        
        for(int i=0;i<n;i++)
        {
            s.insert(items[i][0]);
        }
        
        for(int i=1;i<n;i++)
        {
            items[i][1]=max(items[i][1],items[i-1][1]);
        }
        
        vector<int> res;
        
        for(int i=0;i<size;i++)
        {
            int low=0;
            int high=n-1;
            
            if(s.find(q[i])!=s.end())
            {
                cout<<q[i]<<endl;
                
                int ans=0;
                while(low<=high)
                {
                    int mid=low+(high-low)/2;
                    
                    if(items[mid][0]==q[i])
                    {
                        ans=mid;
                        low=mid+1;
                    }
                    else if(items[mid][0]>q[i])
                    {
                        high=mid-1;
                    }
                    else
                    {
                        low=mid+1;
                    }
                }
              //  cout<<"***"<<ans<<endl;
                res.push_back(items[ans][1]);
            }
            else
            {
              //  cout<<q[i]<<endl;
                
                if(q[i]>items[n-1][0])
                {
                    res.push_back(items[n-1][1]);
                    continue;
                }
                
                int ans=-1;
                while(low<=high)
                {
                    int mid=low+(high-low)/2;
                 //   cout<<ans<<" "<<mid<<endl;
                    
                    if(items[mid][0]<q[i])
                    {
                        ans=mid;
                        low=mid+1;
                    }
                    else
                    {
                        high=mid-1;
                        //ans=mid;
                    //    break;
                    }
                }
                
                
                
                if(ans==-1)
                {
                    res.push_back(0);
                }
                else
                    res.push_back(items[ans][1]);
            }
        }
        
        return res;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
//         sort(items.begin(),items.end());
        
        
        
//         for(int i=1;i<n;i++)
//         {
//             items[i][1]=max(items[i-1][1],items[i][1]);
//         }
        
//         vector<int> ans;
        
        
//         for(int i=0;i<size;i++)
//         {
//             int low=0;
//             int high=n-1;
            
//             if(queries[i]<items[0][0])
//             {
//                  ans.push_back(0);
//                  continue;
//             }   
            
//             while(low<high)
//             {
            
//                 int mid=(low+high)/2;
                
//                 if(items[mid][0]==queries[i])
//                 {
//                     cout<<mid<<endl;
//                     low=mid+1;
//                     if(items[low][0]!=queries[i])
//                     {
//                         low=mid;
//                         break;
//                     }   
//                 }
//                 else if(items[mid][0]>queries[i])
//                 {
//                     high=mid-1;
//                     if(items[high][0]<queries[i])
//                     {
//                         high=mid;
//                         break;
//                     }
//                 }
//                 else
//                 {
//                     low=mid+1;
//                     if(items[low][0]>queries[i])
//                     {
//                         low=mid;
//                         break;
//                     }
//                 }
//             }
            
//             if(items[low][0]==queries[i])
//             ans.push_back(items[low][1]);
//             else
//                 ans.push_back(items[low-1][1]);
            
//         }
        
//         return ans;
        
        
    }
};