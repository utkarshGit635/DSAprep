/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& in) {
        if (root == NULL)
            return;

        inorder(root->left, in);
        in.push_back(root->val);
        inorder(root->right, in);
    }

    TreeNode* increasingBST(TreeNode* root) {
        vector<int> inorderval;
        inorder(root, inorderval);
        int n = inorderval.size();

        TreeNode* newRoot = new TreeNode(inorderval[0]);
        TreeNode* curr = newRoot;

        for (int i = 1; i < n; i++) {
            TreeNode* temp = new TreeNode(inorderval[i]);

            curr->left = NULL;
            curr->right = temp;
            curr = temp;
        }
        curr->left = NULL;
        curr->right = NULL;

        return newRoot;
    }
};