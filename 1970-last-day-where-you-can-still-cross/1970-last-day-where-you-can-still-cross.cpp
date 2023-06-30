class dsu
{
    vector<int> parent;
    vector<int> size;
    int sz;
    int col;
    int flag;
    map<int,set<int>> mp;
    public:
    dsu(int s,int c)
    {
        sz=s;
        col=c;
        flag=0;
        for(int i=0;i<sz;i++)
        {
            parent.push_back(i);
            size.push_back(1);
            
        }
    }
    
    int findParent(int u)
    {
        if(parent[u]==u)
            return u;
        return parent[u]=findParent(parent[u]);
    }
    
    void findUnion(int u,int v,int c1,int c2)
    {
        int pu=findParent(u);
        int pv=findParent(v);
        mp[pu].insert(c1);
        mp[pv].insert(c2);
        
        if(pu==pv)
        {
            return ;
        }
        else if(size[pu]>=size[pv])
        {
            parent[pv]=pu;
            size[pu]+=size[pv];
            
            for(auto it:mp[pv])
            {
                mp[pu].insert(it);
            }
            
            if(mp[pu].size()>=col)
            {
       //         cout<<size[pu]<<"p"<<endl;
                flag=1;
            }
        }
        else
        {
            parent[pu]=pv;
            size[pv]+=size[pu];    
            
            for(auto it:mp[pu])
            {
                mp[pv].insert(it);
            }
            
            if(mp[pv].size()>=col)
            {
       //         cout<<size[pv]<<"u"<<endl;
                flag=1;
            }
        }
    }
    
    bool solve()
    {
        return flag;
    }
};


class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        
        int n=cells.size();
        
        dsu d(row*col+col+10,col);
        
        set<int> vis;
        int dx[8]={-1,-1,-1,0,1,1,1,0};
        int dy[8]={-1,0,1,1,1,0,-1,-1};
        int ans=0;
        vector<vector<int>> vp(row,vector<int>(col,0));
        
        for(int i=0;i<n;i++)
        {
            cells[i][0]--;
            cells[i][1]--;
            int x=cells[i][0]*col+cells[i][1];
            vp[cells[i][0]][cells[i][1]]=1;
            vis.insert(cells[i][1]);
         //   cout<<cells[i][0]<<" "<<cells[i][1]<<endl;
            
            for(int ind=0;ind<8;ind++)
            {
                int ind_x=dx[ind]+cells[i][0];
                int ind_y=dy[ind]+cells[i][1];
                
                if(ind_x>=0 && ind_x<row && ind_y>=0 && ind_y<col && vp[ind_x][ind_y]==1)
                {
       //             cout<<ind_x<<" "<<ind_y<<endl;
                    int y=ind_x*col+ind_y;
                    
                    if(d.findParent(x)!=d.findParent(y))
                    {
                        d.findUnion(x,y,cells[i][1],ind_y);
                    }
    
                }
            }
            
            if(vis.size()==col && d.solve())
            {
                ans=i;
                break;
            }
            
          //  cout<<endl;
        }
        
        return ans;
    }
};

















