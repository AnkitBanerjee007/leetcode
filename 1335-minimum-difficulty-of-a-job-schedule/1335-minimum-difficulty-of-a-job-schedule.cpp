class Solution {
public:
    
    int dp[301][11];
    
    int solve(vector<int> &jobDifficulty,int n,int d,int index){
        
        if(d == 1){
            return *max_element(begin(jobDifficulty)+index, end(jobDifficulty));
        }
        
        if(dp[index][d] != -1) return dp[index][d];
        
        int result = INT_MAX;
        int currD = INT_MIN;
        for(int j=index;j<=n-d;j++)
        {
            currD=max(currD,jobDifficulty[j]);
            result = min(result,currD + solve(jobDifficulty,n,d-1,j+1));
        }
        dp[index][d]=result;
        return dp[index][d];
        
    }
    
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        memset(dp,-1,sizeof(dp));
        
        int n = jobDifficulty.size();
        if(d > n){
            return -1;
        }
        
        return solve(jobDifficulty,n,d,0);
    }
};