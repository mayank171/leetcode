class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        
        for(int i=0;i<=n-3;i++)
        {
            for(int j=0;j<=m-3;j++)
            {
                set<int> st;
                if(i+3<=n && j+3<=m)
                {
                    int s=0;
                    for(int a=i;a<i+3;a++)
                    {
                        for(int b=j;b<j+3;b++)
                        {
                            s+=grid[a][b];
                            st.insert(grid[a][b]);
                        }
                    }
                    
                    
                    if(st.size()!=9)
                        continue;
                    
                    int flag=0;
                    for(int a=1;a<=9;a++)
                    {
                        if(st.find(a)==st.end())
                        {
                            flag=1;
                            break;
                        }
                    }
                    
                    if(flag==1)
                        continue;
                    
                    st.clear();
                    
                    for(int a=i;a<i+3;a++)
                    {
                        int sum=0;
                        for(int b=j;b<j+3;b++)
                        {
                            sum+=grid[a][b];
                        }
                        st.insert(sum);
                    }
                    
                    for(int b=j;b<j+3;b++)
                    {
                        int sum=0;
                        for(int a=i;a<i+3;a++)
                        {
                            sum+=grid[a][b];
                        }
                        st.insert(sum);
                    }
                    
                    int dsum1=0;
                    for(int a=i,b=j;a<i+3 && b<j+3;a++,b++)
                    {
                        dsum1+=grid[a][b];
                    }
                    st.insert(dsum1);
                    
                    int dsum2=0;
                    for(int a=i+2,b=j+2;a>=i && b>=j;a--,b--)
                    {
                        dsum2+=grid[a][b];
                    }
                    st.insert(dsum2);
                    
                }
                
                if(st.size()==1)
                    ans++;
            }
            
        }
        
        return ans;
        
    }
};