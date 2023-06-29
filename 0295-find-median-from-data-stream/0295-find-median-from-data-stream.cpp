class MedianFinder {
public:
    
    priority_queue<int> maxi;
    priority_queue<int,vector<int>,greater<int>> mini;
    
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxi.push(num);
        
        if(maxi.size()>0 && mini.size()>0 && maxi.top()>mini.top())
        {
            int val=maxi.top();maxi.pop();
            mini.push(val);
        }
        
        if(maxi.size()>mini.size()+1)
        {
            int val=maxi.top();maxi.pop();
            mini.push(val);    
        }
        
        if(mini.size()>maxi.size()+1)
        {
            int val=mini.top();mini.pop();
            maxi.push(val);    
        }
    }
    
    double findMedian() {
        if(maxi.size()>mini.size())
        {
            return maxi.top();
        }
        else if(maxi.size()<mini.size())
        {
            return mini.top();
        }
        else
        {
            return (maxi.top()+mini.top())/(double)2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */