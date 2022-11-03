class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        
        map<string,int> m;
        
        int len = 0;
        int ans = 0;
        
        bool flag = false;
        
        // Store frequency of each string in map
        for(auto word : words){
            m[word]++;
        }
        
        for(auto x : m){
            
            // Case when both letters in a word is same eg : gg cc aa
            if(x.first[0] == x.first[1]){
                
                // When the number of times the pairs occur is ODD
                if(x.second % 2 == 1){
                    flag = true;
                    len += (x.second - 1);
                }
                else{
                    len+= m[x.first];
                }
                m.erase(x.first);
            }
            // Case when both the letters are not same eg :lc cl
            else{
                string str = x.first;
                reverse(str.begin(),str.end());
                
                if(m.find(str) != m.end()){
                    ans+= min(m[str],x.second) * 4;
                }
                m.erase(str);
                m.erase(x.first);
            }
        }
        
        if(flag){
            return ans+len*2+2;
        }
        return ans+len*2;
    }
};