class Solution {
public:
    bool checkIfPangram(string sentence) {
        
        unordered_set<char> alphabets(sentence.begin(),sentence.end());
        
        return alphabets.size() == 26;
    }
};