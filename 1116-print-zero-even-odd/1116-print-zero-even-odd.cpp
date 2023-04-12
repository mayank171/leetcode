class ZeroEvenOdd {
private:
    int n;
    condition_variable cv;
    mutex m;
    int turn;
    int evn;
    int e;
    int o;
    int i;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
        turn=0;
        evn=-1;
        //n=2*n;
        e=2;
        o=1;
        i=0;

    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        
        for(;i<n;)
        {
            unique_lock<mutex> lock(m);
            while(turn!=0 && i<n)
            {
                cv.wait(lock);
            }

            if(i<n)
            {
                printNumber(0);
                turn=1;
                if(i%2==0)
                   evn=1;
                else
                   evn=-1;
            }

            cv.notify_all();
        }

    }

    void even(function<void(int)> printNumber) {
        
        
        for(;i<n;)
        {
            unique_lock<mutex> lock(m);

            while(evn!=-1 && i<n)
            {
                cv.wait(lock);
            }

            if(i<n)
            {
                printNumber(e);
                turn=0;
                evn=0;
                e+=2;
                i++;
            }

            cv.notify_all();
        }

    }

    void odd(function<void(int)> printNumber) {
        
        
        for(;i<n;)
        {
            unique_lock<mutex> lock(m);

            while(evn!=1 && i<n)
            {
                cv.wait(lock);
            }

            if(i<n)
            {
                printNumber(o);
                turn=0;
                evn=0;
                o+=2;
                i++;
            }

            cv.notify_all();
        }
    }
};