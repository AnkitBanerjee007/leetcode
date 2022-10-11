class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int first = INT_MAX;
        int second = INT_MAX;
        
        for(auto x : nums){
            
            // For the first smallest element
            if(x < first){
                first = x;
            }
            // For the second smallest element
            else if(x > first && x < second){
                second = x;
            }
            // For the third smallest element
            else if(x > second){
                return true;
            }
            
            
        }
        return false;
    }
};