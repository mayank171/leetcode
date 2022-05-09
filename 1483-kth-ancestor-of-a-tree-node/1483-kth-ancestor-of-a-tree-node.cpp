class TreeAncestor {
    vector<vector<int>> prec;
    int max_h;
public:
    TreeAncestor(int n, vector<int>& parent) {
    
        max_h=20;
        vector<vector<int>> adj(max_h,vector<int> (n,-1));
        prec=adj;
    
       // parent[0]=0;
        for(int i=0;i<n;i++)
        {
            prec[0][i]=parent[i];
        }
      
        
        for(int i=1;i<max_h;i++)
        {
          //  cout<<i<<" ";
            for(int j=0;j<n;j++)
            {
                
                int x=prec[i-1][j];
                if(x!=-1)
                    prec[i][j]=prec[i-1][x];
                
            }
        }
    //    cout<<"llll";
    }
    
    int getKthAncestor(int node, int k) {
        
        for(int i=0;i<max_h;i++)
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