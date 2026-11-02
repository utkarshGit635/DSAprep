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

    void inorder(TreeNode* root, vector<int>& in) {
        if(root == NULL)
            return;

        inorder(root -> left, in);
        in.push_back(root -> val);
        inorder(root -> right, in);
    }

    vector<int> mergearrays(vector<int>& a, vector<int>& b) {
        vector<int> ans(a.size() + b.size());
        int i = 0, j = 0, k = 0;
        while(i < a.size() && j < b.size()) {
            if(a[i] < b[j]) {
                ans[k++] = a[i];
                i++;
            }
            else {
                ans[k++] = b[j];
                j++;
            }
        }
        while(i < a.size()) {
            ans[k++] = a[i];
            i++;
        }
        while(j < b.size()) {
            ans[k++] = b[j];
            j++;
        }
        return ans;
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> bst1, bst2;
        inorder(root1, bst1);
        inorder(root2, bst2);
        vector<int> mergearray = mergearrays(bst1, bst2);
        return mergearray;
    }
};