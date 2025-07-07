#include <iostream>
#include <vector>
#include <climits>
using namespace std;

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

// Insert into BST
TreeNode* insert(TreeNode* root, int val) {
    if (root == NULL) return new TreeNode(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Build BST from vector
TreeNode* buildBST(const vector<int>& arr) {
    TreeNode* root = NULL;
    for (int val : arr) {
        root = insert(root, val);
    }
    return root;
}

class Solution {
public:
    TreeNode* prev = NULL;

    int minDiffInBST(TreeNode* root) {
        if (root == NULL) return INT_MAX;

        int ans = INT_MAX;

        if (root->left != NULL) {
            ans = min(ans, minDiffInBST(root->left));
        }

        if (prev != NULL) {
            ans = min(ans, root->val - prev->val);
        }

        prev = root;

        if (root->right != NULL) {
            ans = min(ans, minDiffInBST(root->right));
        }

        return ans;
    }
};

int main() {
    vector<int> arr = {4, 2, 6, 1, 3};

    TreeNode* root = buildBST(arr);

    Solution sol;
    int minDiff = sol.minDiffInBST(root);

    cout << "Minimum difference between any two nodes in BST: " << minDiff << endl;

    return 0;
}
