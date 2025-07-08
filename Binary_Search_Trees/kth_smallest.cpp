#include <iostream>
using namespace std;

// Definition for a binary tree node.
class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Solution class with kthSmallest logic
class Solution {
private:
    int count = 0;
    int result = -1;

    void inorder(TreeNode* root, int k) {
        if (root == nullptr || count >= k)
            return;

        inorder(root->left, k);

        count++;
        if (count == k) {
            result = root->val;
            return;
        }

        inorder(root->right, k);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        count = 0;
        result = -1;
        inorder(root, k);
        return result;
    }
};

// Test the code
int main() {

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(1);

    Solution sol;
    int k = 3;
    cout << "The " << k << "rd smallest element is: " << sol.kthSmallest(root, k) << endl;

    return 0;
}
