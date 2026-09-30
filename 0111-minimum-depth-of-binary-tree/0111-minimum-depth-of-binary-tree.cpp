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
    int mini=0;
    int height(TreeNode* root){
       if(root==NULL){
        return 0;
       }
       int lheight=height(root->left);
       int rheight=height(root->right);
       if(root->left==NULL){
        return 1+rheight;
       } 
       if(root->right==NULL){
        return 1+lheight;
       }
       return 1+min(lheight,rheight);
    }
    int minDepth(TreeNode* root) {
        return height(root);
        
    }
};