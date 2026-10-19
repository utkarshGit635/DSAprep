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
    TreeNode* parent(TreeNode* root, int target, map<TreeNode*, TreeNode*>& nTp) {
        TreeNode* res = NULL;

        queue<TreeNode*> q;
        q.push(root);
        nTp[root] = NULL;

        while(!q.empty()) {
            TreeNode* front = q.front();
            q.pop();

            if(front -> val == target)
                res = front;
            if(front -> left) {
                nTp[front -> left] = front;
                q.push(front -> left);
            }
            if(front -> right) {
                nTp[front -> right] = front;
                q.push(front -> right);
            }
        }
        return res;
    }

    int burntree(TreeNode* root, map<TreeNode*, TreeNode*>& nTp) {
        map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(root);
        visited[root] = true;
        int ans = 0;

        while(!q.empty()) {
            bool flag = 0;
            int size = q.size();
            for(int i = 0; i < size; i++) {
                TreeNode* front = q.front();
                q.pop();

                if(front -> left && !visited[front -> left]) {
                    flag = 1;
                    q.push(front -> left);
                    visited[front -> left] = 1;
                }
                if(front -> right && !visited[front -> right]) {
                    flag = 1;
                    q.push(front -> right);
                    visited[front -> right] = 1;
                }
                if(nTp[front] && !visited[nTp[front]]) {
                    flag = 1;
                    q.push(nTp[front]);
                    visited[nTp[front]] = 1;
                }
            }
            if(flag == 1) {
                ans ++;
            }
        }
        return ans;
    }


    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*, TreeNode*> nTp;
        TreeNode* targetN = parent(root, start, nTp);
        int ans = burntree(targetN,nTp);
        return ans;
    }
};