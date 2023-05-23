class KthLargest {
public:
    
    vector<int> v;
    int kk;
    
    void heapify(vector<int> &v,int i,int size)
    {
        int small=i;
        int left=2*i+1;
        int right=2*i+2;
        
        if(left<size && v[left]<v[small])
            small=left;
        if(right<size && v[right]<v[small])
            small=right;
        
        if(i!=small)
        {
            swap(v[i],v[small]);
            heapify(v,small,size);
        }
    }
    
    KthLargest(int k, vector<int>& nums) {
        
        kk=k;
        int size=nums.size();
        
        if(size!=0)
        {
            for(int i=0;i<kk && i<size;i++)
            {
                v.push_back(nums[i]);
            }

            for(int i=min(kk/2-1,size/2-1);i>=0;i--)
            {
                heapify(v,i,min(kk,size));    
            }

            // for(int i=kk-1;i>=0;i--)
            // {
            //     swap(v[0],v[i]);
            //     heapify(v,0,i);
            //     for(auto &it:v)
            //         cout<<it<<" ";
            //     cout<<endl;
            // }
            sort(v.begin(),v.end());

            for(auto &it:v)
                cout<<it<<" ";
            cout<<endl;

            for(int i=kk;i<size;i++)
            {
                if(nums[i]>=v[0])
                {
                    v[0]=nums[i];
                    heapify(v,0,kk);
                }
            }
        
        }
            
        
        
    }
    
    int add(int val) {
        
        if(v.size()==0)
        {
            v.push_back(val);
            return val;
        }
        
        if(v.size()<kk)
        {
            v.push_back(val);
            heapify(v,0,v.size());
            
        }
        else
        {
           
            if(val>=v[0])
            {
                v[0]=val;
                heapify(v,0,kk);
            }
            
        }
        
            return v[0];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */