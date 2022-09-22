class Solution {
public:
    string reverseWords(string s) {
        
        stringstream ss(s);
        string ans,word;
        
        // t will have individual words from s seperated by spaces.
        while(getline(ss,word,' ')){
            // Reversing each word
            reverse(word.begin(),word.end());
            // Storing with an empty space added at the end.
            ans+= word + ' ';
        }
        // Trim the space added to the final word at last.
        return ans.substr(0,ans.size()-1);
    }
};