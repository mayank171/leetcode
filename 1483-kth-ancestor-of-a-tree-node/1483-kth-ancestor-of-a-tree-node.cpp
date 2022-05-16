class TreeAncestor {
    vector<vector<int>> prec;
    int max_h;
public:
    TreeAncestor(int n, vector<int>& parent) {
    
        vector<vector<int>> adj(20,vector<int>(n,-1));
        
        prec=adj;
        
        for(int i=0;i<n;i++)
        {
            prec[0][i]=parent[i];
        }
        
        for(int i=1;i<20;i++)
        {
            for(int j=0;j<n;j++)
            {
                int x=prec[i-1][j];
                if(x!=-1)
                    prec[i][j]=prec[i-1][x];
            }
        }
       
    }
    
    int getKthAncestor(int node, int k) {
        
        int ans;
        
       // cout<<"vmdl";
        for(int i=31;i>=0;i--)
        {
            if(k&(1<<i))
            {
                node=prec[i][node];
                if(node==-1)
                    return -1;
            }
        }
      
        return node;
        
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */