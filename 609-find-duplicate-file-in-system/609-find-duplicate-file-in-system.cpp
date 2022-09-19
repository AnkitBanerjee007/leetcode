class Solution {
public:
    // Tech Adora By Nivedita
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        
        unordered_map<string,vector<string>> m;
        
        for(auto paths:paths){
            stringstream str(paths);
            string dir;
            string file;
            
            // Seperating the dir name based on first space in the string
            getline(str,dir,' ');
            
            // Seperating files based on the following empty spaces and storing them
            while(getline(str,file,' ')){
                // content - 'abcd' / 'efgh'
                string content = file.substr(file.find('(') + 1, file.find(')') - file.find('(') - 1);
                // name - root/a 
                string name = dir + '/' + file.substr(0, file.find('('));
                // m = {'abcd' : ['root/a','root/c'], 'efgh' : ['root/c/d','root'] }
                m[content].push_back(name);
            }
        }
            vector<vector<string>> ans;
        // x = 'abcd' : ['root/a','root/c']
            for(auto x:m){
                if(x.second.size() > 1){
                    ans.push_back(x.second);
                }
            }
            
        
        return ans;
    }
};