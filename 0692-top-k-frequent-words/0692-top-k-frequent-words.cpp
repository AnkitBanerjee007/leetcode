class Solution {
public:
    // Operator Overloading
    class comp {
        public :
            bool operator()(pair<int,string> &a,pair<int,string> &b)
            {
                if(a.first!=b.first) return a.first>b.first;
                else return a.second<b.second;
            }
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        unordered_map<string,int> mp;
        
        for(int i=0;i<words.size();i++){
            mp[words[i]]++;
        }
        
        vector<string> ans;
        
        priority_queue<pair<int,string>,vector<pair<int,string>>,comp> pq;
        
        for(auto e : mp){
            if(pq.size() < k){
                pq.push({e.second,e.first});
            }else{
                if(pq.top().first < e.second){
                    pq.pop();
                    pq.push({e.second,e.first});
                }else if(pq.top().first == e.second && pq.top().second > e.first){
                    pq.pop();
                    pq.push({e.second,e.first});
                }
            }
        }
        
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};