class Solution {
public:
    
    int solve(int n)
    {
        int sum=0;
        while(n)
        {
            sum+=(n%10)*(n%10);
            //cout<<sum<<endl;
            n/=10;
        }
        
        return sum;
    }
    
    bool isHappy(int n) {
        
        set<int> st;
        
        while(st.find(n)==st.end())
        {
           // cout<<n<<endl;   
            st.insert(n);
            int sum=solve(n);
            
            if(sum==1)
                return true;
            
            n=sum;
        }
        
        return false;
    }
};