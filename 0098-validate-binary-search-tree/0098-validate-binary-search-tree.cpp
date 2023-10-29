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

    bool isValidBST(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        return isBST(root, NULL, NULL);
    }
    
    bool isBST(TreeNode* root, TreeNode* max, TreeNode* min){
        if(root==NULL){
            return true;
        }
		// Using the same above logic
		//Just check if max or min-node is NULL, then follow it as true
        if((min==NULL || root->val > min->val) && (max==NULL || root->val < max->val)){
            return isBST(root->left, root, min) && isBST(root->right, max, root);
        }
        return false;
    }
};
