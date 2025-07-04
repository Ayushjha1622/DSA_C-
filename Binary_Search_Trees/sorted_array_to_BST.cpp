#include<iostream>
#include<vector>
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

class Solution {
public:
    TreeNode* helper(vector<int>& nums, int st, int end) {
        if (st > end) {
            return NULL;
        }

        int mid = st + (end - st) / 2;
        TreeNode* root = new TreeNode(nums[mid]);

        root->left = helper(nums, st, mid - 1);
        root->right = helper(nums, mid + 1, end);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
};

// Inorder traversal to verify BST
void inorder(TreeNode* root) {
    if (root == NULL) return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    vector<int> nums = {-10, -3, 0, 5, 9};

    Solution sol;
    TreeNode* root = sol.sortedArrayToBST(nums);

    cout << "Inorder traversal of BST: ";
    inorder(root);
    cout << endl;

    return 0;
}
