class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        
        int n = nums.size();
        
        int orgSum = (n*(n+1))/2;
        
        int sum = 0;
        
        int missing_ele = 0;
        
        unordered_map<int,int> mp;
        
        for(auto e : nums){
            
            mp[e]++;
            sum+= e;
            
            if(mp[e] == 2){
                missing_ele = e;
            }
            
        }
        
        return {missing_ele, orgSum - sum + missing_ele};
        
    }
};