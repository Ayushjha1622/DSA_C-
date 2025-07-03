#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// Definition for a binary tree node
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

// Build binary tree from preorder with -1 as NULL
TreeNode* buildTree(vector<int>& preorder, int& idx) {
    if (idx >= preorder.size() || preorder[idx] == -1) {
        idx++;
        return NULL;
    }

    TreeNode* root = new TreeNode(preorder[idx++]);
    root->left = buildTree(preorder, idx);
    root->right = buildTree(preorder, idx);
    return root;
}

// Main solution class
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        int maxWidth = 0;

        while (!q.empty()) {
            int levelSize = q.size();
            unsigned long long stIdx = q.front().second;
            unsigned long long endIdx = q.back().second;

            maxWidth = max(maxWidth, int(endIdx - stIdx + 1));

            for (int i = 0; i < levelSize; i++) {
                auto curr = q.front();
                q.pop();

                unsigned long long idx = curr.second - stIdx;  // Normalize to prevent overflow

                if (curr.first->left) {
                    q.push({curr.first->left, 2 * idx + 1});
                }
                if (curr.first->right) {
                    q.push({curr.first->right, 2 * idx + 2});
                }
            }
        }

        return maxWidth;
    }
};

// Test
int main() {
    vector<int> preorder = {1, 3, 5, 6, -1, -1, -1, -1, 2, -1, 9, -1, 7, -1, -1};
    int idx = 0;
    TreeNode* root = buildTree(preorder, idx);

    Solution sol;
    int width = sol.widthOfBinaryTree(root);
    cout << "Maximum width of binary tree: " << width << endl;

    return 0;
}
