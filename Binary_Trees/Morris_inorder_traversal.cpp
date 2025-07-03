#include <iostream>
#include <vector>
using namespace std;

// Definition of binary tree node
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = right = nullptr;
    }
};

// Morris Inorder Traversal Implementation
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;

        while (curr != NULL) {
            if (curr->left == NULL) {
                ans.push_back(curr->val); // Visit current node
                curr = curr->right;
            } else {
                // Find inorder predecessor
                TreeNode* IP = curr->left;
                while (IP->right != NULL && IP->right != curr) {
                    IP = IP->right;
                }

                if (IP->right == NULL) {
                    IP->right = curr; // Create temporary thread
                    curr = curr->left;
                } else {
                    IP->right = NULL; // Remove thread
                    ans.push_back(curr->val); // Visit current node
                    curr = curr->right;
                }
            }
        }

        return ans;
    }
};

// Helper: build a sample binary tree
TreeNode* buildSampleTree() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    return root;
}

// Driver code
int main() {
    TreeNode* root = buildSampleTree();

    Solution sol;
    vector<int> result = sol.inorderTraversal(root);

    cout << "Inorder traversal using Morris: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
