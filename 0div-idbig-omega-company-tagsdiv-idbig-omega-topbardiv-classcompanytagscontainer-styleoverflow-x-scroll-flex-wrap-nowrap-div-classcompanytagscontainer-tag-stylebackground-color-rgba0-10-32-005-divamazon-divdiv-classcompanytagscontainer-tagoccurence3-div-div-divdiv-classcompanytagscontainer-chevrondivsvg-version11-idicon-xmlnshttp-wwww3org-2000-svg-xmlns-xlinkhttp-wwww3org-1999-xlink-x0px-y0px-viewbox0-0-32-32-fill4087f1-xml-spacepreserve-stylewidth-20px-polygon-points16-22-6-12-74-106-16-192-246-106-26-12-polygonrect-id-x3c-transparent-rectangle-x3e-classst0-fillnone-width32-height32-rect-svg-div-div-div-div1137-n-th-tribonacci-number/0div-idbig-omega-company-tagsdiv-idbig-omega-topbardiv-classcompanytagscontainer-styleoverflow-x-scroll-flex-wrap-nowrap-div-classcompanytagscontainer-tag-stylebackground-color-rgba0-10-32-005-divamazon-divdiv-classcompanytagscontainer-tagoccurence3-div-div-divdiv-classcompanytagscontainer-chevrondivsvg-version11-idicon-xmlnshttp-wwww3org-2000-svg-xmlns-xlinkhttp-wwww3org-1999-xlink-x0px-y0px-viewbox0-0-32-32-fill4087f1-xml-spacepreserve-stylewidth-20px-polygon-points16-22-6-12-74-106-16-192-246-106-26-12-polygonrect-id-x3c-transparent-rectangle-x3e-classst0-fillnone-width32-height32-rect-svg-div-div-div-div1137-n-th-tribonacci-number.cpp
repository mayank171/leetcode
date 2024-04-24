class Solution {
public:
    int tribonacci(int n) {
        
        // 0 1 1 2 4 7
        
        if(n==0)
            return 0;
        
        int first=0;
        int second=1;
        int third=1;
        
        for(int i=1;i<n-1;i++)
        {
            int fourth = first+second+third;
            first=second;
            second=third;
            third=fourth;
        }
        
        return third;
    }
};