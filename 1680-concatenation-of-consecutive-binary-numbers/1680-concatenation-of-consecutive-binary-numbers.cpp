class Solution {
public:
    
    // Here we have to do 2 operations
    // 1. Count the number of digits of a number - Formula = (log₂(i) + 1)
    // 2. Shift the previous number by the number of digits obtained above + i [ans = (ans << len) + i]
    
    int numberOfDigits(int i){
        return (log2(i) + 1);
    }
    
    int concatenatedBinary(int n) {
        long ans = 0;
        long MOD = 1e9 + 7;
        
        
        for(int i=1;i<=n;i++){
            int numOfBinaryDigits = numberOfDigits(i);
            ans = ((ans << numOfBinaryDigits) % MOD + i) % MOD;
        }
        return ans;
    }
};