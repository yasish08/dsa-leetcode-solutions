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
    vector<vector<int>>ans;
    void helper(TreeNode* root,int targetSum,int sum,vector<int>path){
        if(root==NULL){
            return;
        }
        sum+=root->val;
        path.push_back(root->val);
        if(root->left==NULL&&root->right==NULL){
            if(sum==targetSum){
                ans.push_back(path);
            }
            return;
        }
        helper(root->left,targetSum,sum,path);
        helper(root->right,targetSum,sum,path);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>path;
        helper(root,targetSum,0,path);
        return ans;
    }
};