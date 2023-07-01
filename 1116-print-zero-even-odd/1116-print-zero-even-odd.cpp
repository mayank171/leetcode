class ZeroEvenOdd {
private:
    int n;
    mutex m;
    condition_variable cv;
    int turn;
    int flag;
    int i;
    int j;
    int e;
    int o;
public:
    ZeroEvenOdd(int n) {
        turn=0;
        flag=1;
        i=1;
        j=1;
        e=2;
        o=1;
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        
        unique_lock<mutex> lock(m);
        while(i<=n)
        {
            while(i<=n && turn!=0)
            {
                cv.wait(lock);
            }
            
            if(i<=n)
            {
                printNumber(0);
           //     cout<<0<<endl;
                i++;
            }
            else
                break;
            turn=(turn+1)%2;
            if(i&1)
                flag=1;
            else
                flag=-1;
            cv.notify_all();

        }
    }

    void even(function<void(int)> printNumber) {
        
        unique_lock<mutex> lock(m);
        while(j<=n)
        {
            while(j<=n && flag!=1)
            {
                cv.wait(lock);
            }
            
            
            if(j<=n)
            {
                printNumber(e);
         //       cout<<e<<endl;
                j++;
                e+=2;
            }
            else
                break;
            turn=(turn+1)%2;
            flag=0;
            cv.notify_all();

        }
    }

    void odd(function<void(int)> printNumber) {
        
        unique_lock<mutex> lock(m);
        while(j<=n)
        {
            while(j<=n && flag!=-1)
            {
                cv.wait(lock);
            }
            
            
            if(j<=n)
            {
                printNumber(o);
      //          cout<<o<<endl;
                j++;
                o+=2;
            }
            else
                break;
            turn=(turn+1)%2;
            flag=0;
            cv.notify_all();
        }
    }
};