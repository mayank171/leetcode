class Solution {
public:
    
    void buildTree(vector<int> &seg,vector<int> &arr,int ss,int se,int si)
    {
        if(ss==se)
        {
            seg[si]=arr[ss];
            return ;
        }
        
           
        int mid=(ss+se)/2;
        
        buildTree(seg,arr,ss,mid,2*si+1);
        buildTree(seg,arr,mid+1,se,2*si+2);
        
        seg[si]=max(seg[2*si+1],seg[2*si+2]);
    }
    
    int query(vector<int> &seg,vector<int> &arr,int ss,int se,int si,int qs,int qe)
    {
        if(qs>se || qe<ss)
           return -1e8;
           
        if(ss>=qs && se<=qe)
        {
            return seg[si];
        }
        
        int mid=(ss+se)/2;
        
        int l=query(seg,arr,ss,mid,2*si+1,qs,qe);
        int r=query(seg,arr,mid+1,se,2*si+2,qs,qe);
        
        return max(l,r);
    }
    
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        
       int n=arr.size(); 
       
       vector<int> seg(n*4,-1);
       buildTree(seg,arr,0,n-1,0);
       
       vector<int> ans;
       
       for(int i=0;i<n-k+1;i++)
       {
           int qs=i;
           int qe=i+k-1;
           
           ans.push_back(query(seg,arr,0,n-1,0,qs,qe));
       }
       
       return ans;
        
    }
};