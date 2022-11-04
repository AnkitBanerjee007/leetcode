class Solution {
public:
    
    bool isVowel(char ch){
        char currch = tolower(ch);
        
        if(currch == 'a' ||currch == 'e' ||currch == 'i' ||currch == 'o' ||currch == 'u'){
            return true;
        }
        return false;
    }
    
    string reverseVowels(string s) {
        
        int n = s.size();
        int low = 0;
        int high = n - 1;
        
        while(low < high){
            bool islowVowel = isVowel(s[low]);
            bool ishighVowel = isVowel(s[high]);
            
            if(islowVowel && ishighVowel){
                swap(s[low],s[high]);
                low++;
                high--;
            }
            
            if(!islowVowel) low++;
            if(!ishighVowel) high--;
        }
        return s;
    }
};