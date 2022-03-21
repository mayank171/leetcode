class MyCircularQueue {
private:
    int size;
    int v[10000];
    int front;
    int rear;
public:
    MyCircularQueue(int k) {
        size=k;
        front=-1;
        rear=-1;
    }
    
    bool enQueue(int value) {
        if(isFull())
        {
            return false;
        }
        
        else if(isEmpty())
        {
            front=rear=0;
        }
        else
        {
            rear=(rear+1)%size;
            
        }
        v[rear]=value;
        //cout<<front<<" "<<rear<<endl;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())
        {
            return false;
        }
        
        if(front==rear)
        {
            front=rear=-1;
            return true;
        }
        
        front=(front+1)%size;
        
        
        return true;
    }
    
    int Front() {
        if(isEmpty())
            return -1;
        return v[front];
    }
    
    int Rear() {
        if(isEmpty())
            return -1;
        // if(rear==-1)
        //     return -1;
        return v[rear];
    }
    
    bool isEmpty() {
        if(front==-1 && rear==-1)
            return true;
        return false;
    }
    
    bool isFull() {
        if((rear+1)%size==front)
            return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */