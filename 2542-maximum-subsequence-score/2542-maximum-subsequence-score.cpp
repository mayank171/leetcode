class Solution {
public:
    
//     static bool comp(pair<int,int> &a,pair<int,int> &b)
//     {
//         if(a.second>b.second)
//             return true;
//         return false;
//     }
    
//     void heapify(vector<int> &temp,int i,int size)
//     {
//         int smallest=i;
//         int left=2*i+1;
//         int right=2*i+2;
        
//         if(left<size && temp[left]<temp[smallest])
//            smallest=left;
//         if(right<size && temp[right]<temp[smallest])
//            smallest=right;
        
//         if(smallest!=i)
//         {
//             swap(temp[smallest],temp[i]);
//             heapify(temp,smallest,size);
//         }
//     }
    
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        
        vector<pair<int, int>> p ;
        
        for(int i = 0 ; i<nums1.size() ; i++)
        {
            p.push_back({nums2[i] , nums1[i]});
        }
        
        sort(p.rbegin() , p.rend());
        
        long long ans  = 0;
        long long sum  = 0;
        priority_queue<int> pq;
        for(int i = 0 ; i<k-1 ; i++)
        {
            sum += p[i].second;
            pq.push(-p[i].second);
        }

        for(int i = k-1 ; i<nums1.size() ; i++)
        {

            sum += p[i].second;
            pq.push(-p[i].second);
            
            ans = max(ans, sum * p[i].first );

            sum += pq.top();
            pq.pop();
        }
        
        return ans;
    }
};
















