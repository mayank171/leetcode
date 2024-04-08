class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        
        
        queue<int> q1;
        for(int i=0;i<students.size();i++)
        {
            q1.push(students[i]);
        }
        
        int i=0;
        int ct=0;
        while(ct!=q1.size())
        {
            if(q1.front()==sandwiches[i])
            {
                ct=0;
                i=(i+1)%sandwiches.size();
                q1.pop();
            }
            else
            {
                int x=q1.front();q1.pop();
                q1.push(x);
                ct++;
            }
        }
        
        return q1.size();
    }
};