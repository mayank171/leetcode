
class Solution {
private:
    void check(int ind,int n,vector<int> &ans)
    {
        if(ind>n)
        {
            return;
        }
        
//         if(ind==n)
//         {
//             return ;
//         }
        
        if(ans.size()==n)
            return ;
        
        int ct=0;
        while(ct<=9)
        {
             
                if(ind>n)
                    break;
                ans.push_back(ind);
                check(ind*10,n,ans);
                if(ans.size()==n)
                    break;
            
            ct++;
            ind++;
        }
        
    }
public:
    vector<int> lexicalOrder(int n) {
        
        int start=1;
        
        vector<int> ans;
        //ans.push_back(1);
        
        check(1,n,ans);
        
        return ans;
    }
};






