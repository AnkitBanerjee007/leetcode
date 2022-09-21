class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        vector<int> ans;
        int sum = 0;
        
        // Taking the sum of all the even numbers from nums initially
        for(auto n : nums){
            if(n%2 == 0){
                sum+=n;                
            }
        }
        
        
        for(auto x:queries){
            int value = x[0];
            int index = x[1];
            
            // If the num at the index is even then we initially decrease it from sum
            if(nums[index]%2 == 0){
                sum-=nums[index];
            }
            // Then add the value to our num[index] and again check if it is eveb or odd
            nums[index]+=value;
            
            // If it is even we add it to our sum again
            if(nums[index]%2 == 0){
                sum+=nums[index];
            }

            ans.push_back(sum);
        }
        return ans;
        
    }
};