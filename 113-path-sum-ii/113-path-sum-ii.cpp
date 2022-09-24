/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void dfs(TreeNode* root,int targetSum,vector<vector<int>> &ans,vector<int> ds){
        
        if(root == NULL) return;
        
        ds.push_back(root->val);
        
        targetSum -= root->val;
        
        // Condition for our path sum = targetSum
        if(targetSum == 0 && root->left == NULL && root->right == NULL){
            ans.push_back(ds);
            return;
        }
        
        dfs(root->left,targetSum,ans,ds);
        dfs(root->right,targetSum,ans,ds);
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> ds;
        // while(root == NULL) return ans;
        dfs(root,targetSum,ans,ds);
        return ans;
        
        
    }
};