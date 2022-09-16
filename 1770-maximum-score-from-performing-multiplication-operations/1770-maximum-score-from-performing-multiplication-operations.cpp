class Solution {
public:
    // FRAZ
    
    vector<vector<int>> dp;
    int f(int index,vector<int> &nums,vector<int> &multipliers,int start){
        if(index == multipliers.size()) return 0;
        
        int end = nums.size() - (index - start) - 1;
        
        if(dp[index][start]!=INT_MIN) return dp[index][start];
        
        int opt1 = multipliers[index]*nums[start] + f(index+1,nums,multipliers,start+1);
        int opt2 = multipliers[index]*nums[end] + f(index+1,nums,multipliers,start);
        
        return dp[index][start] = max(opt1,opt2);
    }
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        
        int m=multipliers.size();
        
        // Failing in the case of
//[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
//[1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1]
        // Therefore INT_MIN
        dp.resize(m+1,vector<int>(m+1,INT_MIN)); 
        return f(0,nums,multipliers,0);
    }
};