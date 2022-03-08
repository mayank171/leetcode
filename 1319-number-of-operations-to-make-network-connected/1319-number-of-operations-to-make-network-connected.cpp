// class dsu
// {

// private:
//     vector<int> parent,size;
//     int size1;
// public:

//     dsu(int n)
//     {
//         size1=n;
//         for(int i=0;i<n;i++)
//         {
//             parent.push_back(i);
//             size.push_back(1);
//         }
//     }

//     int find_parent(int u)
//     {
//         if(parent[u]==u)
//             return u;
//         else
//             //path compression  TC-> logn
//             return parent[u]=find_parent(parent[u]);
//     }

//     void find_union(int u,int v)
//     {
//         int pu=find_parent(u);
//         int pv=find_parent(v);
//         if(pu==pv)
//             return ;

//          // size compression   -< TC -> 4XAlpha
//         else if(size[pu]<=size[pv])
//         {
//             size[pv]+=size[pu];
//             parent[pu]=pv;
//         }
//         else
//         {
//             size[pu]+=size[pv];
//             parent[pv]=pu;
//         }
//     }

//     void show()
//     {
//         for(int i=0;i<size1;i++)
//         {
//             cout<<parent[i]<<" ";
//         }
//         cout<<endl;

//         for(int i=0;i<size1;i++)
//         {
//             cout<<size[i]<<" ";
//         }
//     }
    
//     int check()
//     {
//         int ct=0;
//         for(int i=0;i<size1;i++)
//         {
//             if(parent[i]==i)
//             {
//                 ct++;
//             }
//         }
//         return ct;
//     }

// };










class dsu
{
    private:
    vector<int> parent;
    vector<int> size;
    int n;
    public:
    dsu(int s)
    {
        n=s;
        for(int i=0;i<n;i++)
        {
            parent.push_back(i);
        }
        
        for(int i=0;i<n;i++)
        {
            size.push_back(1);
        }
        
    }
    
    int getParent(int u)
    {
        if(parent[u]==u)
            return u;
        
        return parent[u]=getParent(parent[u]);
    }
    
    void unionFind(int u,int v)
    {
        int pu=parent[u];
        int pv=parent[v];
        
        if(pu==pv)
            return ;
        
        if(size[pu]>=size[pv])
        {
            size[pu]+=size[pv];
            parent[pv]=pu;
        }
        else
        {    
            size[pv]+=size[pu];
            parent[pu]=pv;
        }
    }
    
    int minWire()
    {
        int ct=0;
        for(int i=0;i<n;i++)
        {
            if(parent[i]==i)
                ct++;
        }
        return ct-1;
    }
    
    void disp()
    {
        for(int i=0;i<n;i++)
        {
            cout<<parent[i]<<" ";
        }
        cout<<endl;
        
        for(int i=0;i<n;i++)
        {
            cout<<size[i]<<" ";
        }
        cout<<endl;
        
    }
};



class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        
        int size=connections.size();
        
        dsu d(n);
        
        int ct=0;
        int ct1=0;
        
        for(int i=0;i<size;i++)
        {
            if(d.getParent(connections[i][0])!=d.getParent(connections[i][1]))
            {
                d.unionFind(connections[i][0],connections[i][1]);
                ct1++;
            }
            else
                ct++;
        }
        
        //d.disp();
        
        int x=d.minWire();
        
        cout<<ct<<endl;
        
        
        if(x<=ct)
            return x;
        else
            return -1;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
//         if(connections.size()<n-1)
//             return -1;
        
//         dsu d(n);
        
//         int ct=0;
        
//         for(int i=0;i<connections.size();i++)
//         {
//             int src=connections[i][0];
//             int dest=connections[i][1];
    
            
//             if(d.find_parent(src)!=d.find_parent(dest) )
//             {
               
//                 d.find_union(src,dest);
//             }
//             else
//             {
//                 ct++;
//             }
//         }
        
//         return d.check()-1;
        
        
// //         int rem=0;
// //         for(int i=0;i<n;i++)
// //         {
// //             if(vis[i]==0)
// //             {
// //                 ++rem;
// //             }
// //             cout<<vis[i]<<" ";
// //         }
// //         cout<<endl;
        
// //         cout<<ct<<endl;
// //         cout<<rem<<endl;
        
// //         if(ct>=rem)
// //         {
// //             return rem;
// //         }
// //         else
// //         {
// //             return -1;
// //         }
        
        
    }
};