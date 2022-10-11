class SmallestInfiniteSet {
public:
    map<int, int> m;
    priority_queue<int, vector<int>, greater<int>> pq;
    SmallestInfiniteSet() {
        for(int i=1; i<=1000; i++)
            pq.push(i),
            m[i]++;
    }
    
    int popSmallest() {
        int val = pq.top();
        pq.pop();
        m.erase(val);
        return val;
    }
    
    void addBack(int num) {
        if(m.find(num) == m.end())
            pq.push(num),
            m[num]++;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */