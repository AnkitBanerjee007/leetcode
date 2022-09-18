class Solution {
public:
    
    // CODE WITH ALISHA
    int trap(vector<int>& arr) {
        int n = arr.size();
        int left = 0;
        int right = n-1;
        
        int leftbar = arr[0];
        int rightbar = arr[n-1];
        
        long long ans = 0;
        
        while(left<=right){
            // 2 conditions
            if(leftbar <= rightbar){
                // Again 2 conditions
        // CASE 1 - When leftbar is less than arr[left] , we need to keep the leftbar to max on left side
                if(leftbar<arr[left]){
                    leftbar = arr[left];
                }
        // CASE 2 - We need to add (leftbar-arr[left] to our ans)
                else{
                    ans+=leftbar-arr[left];
                    left++;
                }
            }
            else{
                if(rightbar<arr[right]){
                    rightbar = arr[right];
                }else{
                    ans+=rightbar-arr[right];
                    right--;
                }
            }
        }
        return ans;
    }
};