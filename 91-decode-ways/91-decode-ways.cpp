class Solution {
public:
    vector<int> dp;
    int numDecodings(string s) {
        dp.resize(s.size());
        dp.assign(s.size(),-1);
        return nways(s,0);
    }
    
    int nways(string s,int index){
        if(index >= s.size()) return 1;
        else if(s[index] == '0') return 0;
        else if(index == s.size()-1) return 1;
        
        else if(dp[index] != -1) return dp[index];
        
        else if(s[index] == '1' || (s[index] == '2' && (s[index+1]>=48 && s[index+1]<=54))){
            return dp[index] = nways(s,index+1) + nways(s,index+2);
        }
        else{
            return dp[index] = nways(s,index+1);
        }
        
    }
    
};