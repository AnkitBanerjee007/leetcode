class MyCalendarThree {
public:
    map<int,int> m;
    
    
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        m[start]++;
        m[end]--;
        int count = 0;
        int maxCount = 0;
        
        for(auto &it: m){
            count+= it.second;
            maxCount = max(maxCount,count);
        }
        
        return maxCount;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */