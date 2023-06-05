class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        
        int n=coordinates.size();
        
        double m;
        if(coordinates[1][0]-coordinates[0][0]==0)
        {
            m=1e5;
        }
        else
        {
            m=(double)(coordinates[1][1]-coordinates[0][1])/(double)(coordinates[1][0]-coordinates[0][0]);
        }
        
       
        for(int i=1;i<n-1;i++)
        {
            double slope;
            if(coordinates[i+1][0]-coordinates[i][0]==0)
            {
                slope=1e5;
            }
            else
            {
                slope=(double)(coordinates[i+1][1]-coordinates[i][1])/(double)(coordinates[i+1][0]-coordinates[i][0]);
            }
            if(slope!=m)
                return false;
        }
        
        return true;
    }
};