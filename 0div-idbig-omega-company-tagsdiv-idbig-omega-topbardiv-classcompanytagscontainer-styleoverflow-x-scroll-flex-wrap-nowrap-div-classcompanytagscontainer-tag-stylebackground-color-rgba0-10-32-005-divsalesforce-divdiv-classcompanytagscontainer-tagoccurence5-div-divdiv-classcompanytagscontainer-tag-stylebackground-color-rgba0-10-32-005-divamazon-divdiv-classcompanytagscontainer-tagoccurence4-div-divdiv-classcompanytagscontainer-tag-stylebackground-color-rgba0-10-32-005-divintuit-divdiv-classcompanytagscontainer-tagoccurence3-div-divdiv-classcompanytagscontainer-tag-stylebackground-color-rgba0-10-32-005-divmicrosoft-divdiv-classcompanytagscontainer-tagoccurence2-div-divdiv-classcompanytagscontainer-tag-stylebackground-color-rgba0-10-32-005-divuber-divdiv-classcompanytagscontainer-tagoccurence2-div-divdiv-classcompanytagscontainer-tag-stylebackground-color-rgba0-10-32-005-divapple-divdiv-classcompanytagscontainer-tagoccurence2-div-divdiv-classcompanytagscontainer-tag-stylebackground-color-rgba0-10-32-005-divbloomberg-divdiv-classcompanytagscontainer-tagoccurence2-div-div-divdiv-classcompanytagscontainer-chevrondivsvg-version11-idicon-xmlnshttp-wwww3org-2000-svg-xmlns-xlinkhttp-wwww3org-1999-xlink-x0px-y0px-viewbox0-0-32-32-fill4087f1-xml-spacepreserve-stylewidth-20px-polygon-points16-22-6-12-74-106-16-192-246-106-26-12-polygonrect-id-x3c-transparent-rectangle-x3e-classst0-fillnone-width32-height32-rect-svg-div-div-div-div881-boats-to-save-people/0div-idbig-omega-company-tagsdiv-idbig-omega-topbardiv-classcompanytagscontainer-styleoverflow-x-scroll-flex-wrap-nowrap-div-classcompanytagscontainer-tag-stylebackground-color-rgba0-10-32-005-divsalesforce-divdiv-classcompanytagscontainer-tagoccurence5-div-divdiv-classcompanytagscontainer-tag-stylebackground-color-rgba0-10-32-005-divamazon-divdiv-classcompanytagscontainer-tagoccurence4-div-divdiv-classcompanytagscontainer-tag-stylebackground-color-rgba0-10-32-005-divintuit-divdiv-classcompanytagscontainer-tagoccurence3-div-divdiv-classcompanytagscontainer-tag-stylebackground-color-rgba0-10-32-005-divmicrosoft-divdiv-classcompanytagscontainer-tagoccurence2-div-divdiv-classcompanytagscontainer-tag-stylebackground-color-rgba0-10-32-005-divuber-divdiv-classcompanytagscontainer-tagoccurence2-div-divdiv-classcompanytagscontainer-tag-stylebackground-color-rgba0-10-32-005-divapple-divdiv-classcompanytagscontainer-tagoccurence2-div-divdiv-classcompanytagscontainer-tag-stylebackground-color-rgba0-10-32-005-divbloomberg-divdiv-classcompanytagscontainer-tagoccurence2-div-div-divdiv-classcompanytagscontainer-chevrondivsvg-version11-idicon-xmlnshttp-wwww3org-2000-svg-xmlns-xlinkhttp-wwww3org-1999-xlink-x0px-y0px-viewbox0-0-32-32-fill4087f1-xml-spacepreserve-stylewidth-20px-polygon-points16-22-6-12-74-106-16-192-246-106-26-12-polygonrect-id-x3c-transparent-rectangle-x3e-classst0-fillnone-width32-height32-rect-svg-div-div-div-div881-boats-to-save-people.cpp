class Solution {
public:

    int blackBox(vector<int> &people,int mid,int n,int limit)
    {
        multiset<int> st;
        for(auto &it:people)
        {
            st.insert(it);
        }

        int peps=0;
        while(mid--)
        {
           // cout<<"cdcdc"<<endl;
            int space=limit;
            auto it=st.begin();

            if(it==st.end())
               continue;

            //cout<<*it<<" "<<space<<endl;

            if((*it)<=space)
            {
                peps++;
                space-=(*it);
                st.erase(it);
            }
           
            if(space>0)
            {
                
                if(st.size()==0)
                   continue;
                auto it=st.lower_bound(space);
                
                if(it==st.end())
                {
                    --it;
                    peps++;
                    space-=*it;
                    st.erase(it);
                }
                else if(it==st.begin() && *it!=space)
                    continue;
                else if(*it==space)
                {
                    peps++;
                    space-=*it;
                    st.erase(it);
                    
                }
                else
                {
                    --it;
                    peps++;
                    space-=*it;
                    st.erase(it);
                    
                }

              //  cout<<space<<"-"<<endl;
            }
        }

        if(peps<n)
           return 0;
        return 1;
    }

    int numRescueBoats(vector<int>& people, int limit) {
        
        int n=people.size();

        int low=1;
        int high=n;
        int ans=n;

        while(low<=high)
        {
            int mid=low+(high-low)/2;

            int k=blackBox(people,mid,n,limit);

            if(k)
            {
                ans=min(ans,mid);
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }

        return ans;

    }
};