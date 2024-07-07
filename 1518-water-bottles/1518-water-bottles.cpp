class Solution {
public:
    int numWaterBottles(int numB, int numE) {
        
        int ans=0;
        
        while(numB)
        {
            ans+=(numB/numE)*numE;
            numB=(numB/numE)+(numB%numE);
            if(numB==0)
            {
                ans++;
                break;
            }    
            else if(numB<numE)
            {
                ans+=numB;
                break;
            }
        }
        
        return ans;
    }
};