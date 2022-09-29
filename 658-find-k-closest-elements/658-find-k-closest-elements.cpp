class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        
        // pq = { [abs(arr[index] - x) , arr[index]] }
        priority_queue<pair<int,int>> pq;
        
        for(auto &a : arr) {
            if(pq.size() >=k && abs(a-x) < pq.top().first){
                pq.pop();
            }else if(pq.size() >= k){
                continue;
            }
            
            pq.push({abs(a-x),a});
        }
        
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};