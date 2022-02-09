// class dsu
// {

// private:
//     vector<int> parent,size;
//     int size1;
// public:

//     dsu(int n)
//     {
//         size1=n;
//         for(int i=0;i<=n;i++)
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

// };



class dsu
{
   private:
           vector<int> parent;
           vector<int> size;
   public:
           dsu(int s)
           {
               for(int i=0;i<s+1;i++)
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
           
           void findUnion(int u,int v)
           {
               int pu=parent[u];
               int pv=parent[v];
               
               if(pu==pv)
               {
                   return ;
               }
               else if(size[pu]>=size[pv])
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
};



class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n=edges.size();
        
        dsu d(n);
        
        
        cout<<n<<endl;
        
        vector<int> v;
        
        for(int i=0;i<n;i++)
        {
            cout<<"vkdvdkvkv";
            if(d.findParent(edges[i][0])!=d.findParent(edges[i][1]))
            {
                cout<<"vnnvdk"<<endl;
                d.findUnion(edges[i][0],edges[i][1]);
            }
            else
            {
                cout<<"amiho"<<endl;
                v.push_back(edges[i][0]);
                v.push_back(edges[i][1]);
            }
        }
        
        vector<int> ans;
        
        ans.push_back(v[v.size()-2]);
        ans.push_back(v[v.size()-1]);
        
        
        return ans;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
//         int n=edges.size();
        
//         dsu d(n);
        
//         vector<pair<int,int>> v;
        
//         for(int i=0;i<n;i++)
//         {
//             if(d.find_parent(edges[i][0])!=d.find_parent(edges[i][1]))
//             {
//                 d.find_union(edges[i][0],edges[i][1]);
//             }
//             else
//             {
//                 v.push_back({edges[i][0],edges[i][1]});              
//             }
               
//         }
        
//          vector<int> ans;
               
//         for(int i=0;i<v.size();i++)
//        {
//             cout<<v[i].first<<" "<<v[i].second;
//        }
               
//         ans.push_back(v[v.size()-1].first);
//         ans.push_back(v[v.size()-1].second);
       
        
//         return ans;
    }
};