class Solution {
public:
int dfs(int i,int j,vector<vector<int>>& grid)
{
if(i>=grid.size()){
return j;
}
//left to right
if(grid[i][j] == 1 && grid[i][j+1] == 1 && j+1<grid[0].size()){
dfs(i+1,j+1,grid);
}
//right to left
else if(grid[i][j] == -1 && grid[i][j-1] == -1 && j-1>=0){
dfs(i+1,j-1,grid);
}
// condition when ball can't reach end from left
else if(grid[i][j] == 1 && j+1>=grid[0].size()){
return -1;
}
else{
return -1;
}
}
vector<int> findBall(vector<vector<int>>& grid) {
int m = grid.size();
int n = grid[0].size();
vector<int> ans(n);
for(int j=0;j<n;i++){
ans[j] = dfs(0,j,grid);
}
return ans;
}
};