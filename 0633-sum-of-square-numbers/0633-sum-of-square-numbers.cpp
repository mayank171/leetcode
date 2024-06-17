class Solution {
public:
    bool judgeSquareSum(int c) {
        
      //  5^2+9^2=25+81= 106
        if(c==0)
            return true;
            
        for(double i=1;i*i<=c;i++)
        {
            double x=i*i;
            double y=c-(i*i);
            double _y=sqrt(y);
            
            if(_y-floor(_y)==0)
            {
                cout<<_y<<endl;
            
                if(x+y==c)
                {
                    cout<<x<<" "<<y<<endl;
                    return true;
                }
            }
        }
        
        return false;
    }
};