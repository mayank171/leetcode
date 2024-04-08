class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        
        int ct0=0;
        int ct1=0;
        for(auto &it:students)
        {
            if(it==0)
                ct0++;
            else
                ct1++;
        }
        
        for(auto &it:sandwiches)
        {
            if(it==0)
            {
                if(ct0==0)
                    break;
                ct0--;
            }
            else
            {
                if(ct1==0)
                    break;
                ct1--;
            }
        }
        
        return ct0+ct1;
    }
};