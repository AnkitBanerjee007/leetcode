class Solution {
public:
    bool isUgly(int n) {
        
        if(n<=0) return false;
        
        for(auto factor : {2,3,5}){
            n = keepDividing(n,factor);
        }
        
        return n == 1;
    }
    
    
    int keepDividing(int dividend, int divisor){
        while(dividend % divisor == 0){
            dividend /= divisor;
        }
        
        return dividend;
    }
};