class Solution {
public:
    bool isValidSerialization(string preorder) {
        
        int ct_hash=0;
        
        int ct_num=0;
        
        int l=preorder.length();
        
        vector<int> v;
        
        for(int i=0;i<l;i++)
        {
            if(preorder[i]==',')
                continue;
            if(preorder[i]>='0' && preorder[i]<='9')
            {
                int k=0;
                int j=i;
                while(j<l && preorder[j]>='0' && preorder[j]<='9')
                {
                    k=k*10+preorder[j]-'0';
                    j++;
                }
                
                v.push_back(k);
                i=j-1;
            }
            else
            {
                v.push_back(-1);
            }
        }
        
        for(auto &it:v)
        {
            cout<<it<<" ";
        }
        
        if(v[0]==-1)
        {
            if(l>1)
                return false;
            return true;
        }
        else
        {
            if(v.size()==1)
                return false;
        }
        
        
        
        int ct=1;
        
        int size=v.size();
        
        if(v[size-2]!=-1)
            return false;
        
        if(v[size-1]!=-1)
            return false;
        
        
        
        
        for(int i=0;i<size;i++)
        {
            if(v[i]!=-1)
            {
                ct--;
                if(ct<0)
                    return false;
                ct+=2;
            }
            else
            {
                ct--;
            }
            
            // if(ct<0)
            //     return false;
        }
        
        
        if(ct==0)
        {
            return true;
        }
        
        return false;
        
    }
};