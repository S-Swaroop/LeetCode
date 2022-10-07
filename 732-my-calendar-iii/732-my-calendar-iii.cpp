class MyCalendarThree {
private: 
    map<int , int> timeline ;
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        timeline[start]++ ; 
        timeline[end]-- ;
        int k = 0 , ongoing = 0 ; 
        for (auto &[x , y] : timeline) {
            ongoing += y ; 
            k = max(k , ongoing) ;
        }
        return k ;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */