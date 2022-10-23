class MedianFinder {
public:
    priority_queue<int> pmin;
    priority_queue<int, vector<int>, greater<int>> pmax;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        pmax.push(num);
        pmin.push(pmax.top());
        pmax.pop();
        
        if(pmin.size() > pmax.size()){
            pmax.push(pmin.top());
            pmin.pop();
        }
    }
    
    double findMedian() {
        if(pmax.size() > pmin.size())
            return pmax.top();
        
        return (double) (pmax.top() + pmin.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */