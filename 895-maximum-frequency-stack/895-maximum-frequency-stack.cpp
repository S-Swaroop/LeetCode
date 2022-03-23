class FreqStack {
public:
    map<int , int> frequency ; 
    map<int , stack<int>> groups ;
    int max_freq ;
    FreqStack() {
        max_freq = 0 ;
    }
    
    void push(int val) {
        frequency[val]++ ;
        max_freq = max(max_freq , frequency[val]) ;
        groups[frequency[val]].push(val) ;
    }
    
    int pop() {
        int x = groups[max_freq].top() ;
        groups[max_freq].pop() ;
        frequency[x]-- ;
        if (groups[max_freq].empty()) {
            max_freq-- ;
        }
        return x ;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */