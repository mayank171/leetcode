class Solution {
public:
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        int n=arr.size();
        
        vector<int> ans;
    
        int ind=upper_bound(arr.begin(),arr.end(),x)-arr.begin();
        
        //cout<<ind<<endl;
        
        if(ind==n)
        {
            ind--;
            while(k--)
            {
                ans.push_back(arr[ind]);
                ind--;
            }
            
        }
        else if(ind==0)
        {
            while(k--)
            {
                ans.push_back(arr[ind]);
                ind++;
            }
        }
        else if(arr[ind-1]==x)
        {
            int flag=0;
            int i=ind-1;
            int j=ind-1;
            
            while(k--)
            {
                if(i==j)
                {
                    ans.push_back(arr[i]);
                    i--;
                    j++;
                }
                else
                {
                    int a,b;
                   if(i>=0 && j<n)
                   {
                      a=abs(arr[i]-x);
                      b=abs(arr[j]-x);                                 
                   }
                    if(a<=b)
                    {
                        if(i<0)
                        {
                            ans.push_back(arr[j]);
                            j++;
                        }
                        else
                        {
                            ans.push_back(arr[i]);
                            i--;    
                        }
                    }
                    else if(a>b)
                    {
                        if(j>n-1)
                        {
                            ans.push_back(arr[i]);
                            i--;
                        }
                        else
                        {
                            ans.push_back(arr[j]);
                            j++;    
                        } 
                    }
                    
                }
            }
        }
        else
        {
            int flag=0;
            int i=ind-1;
            int j=ind;
            
            while(k--)
            {
                int a,b;
                if(i>=0 && j<n)
                {
                   a=abs(arr[i]-x);
                   b=abs(arr[j]-x);                                 
                }

                //cout<<i<<" "<<j<<endl;
                
                if(a<=b)
                {
                    if(i<0)
                    {
                        ans.push_back(arr[j]);
                        j++;
                    }
                    else
                    {
                        ans.push_back(arr[i]);
                        i--;    
                    }
                }
                else if(a>b)
                {
                    if(j>n-1)
                    {
                        ans.push_back(arr[i]);
                        i--;
                    }
                    else
                    {
                        ans.push_back(arr[j]);
                        j++;    
                    } 
                }
                    
                
            }
        }
            
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};