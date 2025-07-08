#include <iostream>
using namespace std;

// TreeNode class definition
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Solution class with lowestCommonAncestor method
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return nullptr;
        }

        if (root->val > p->val && root->val > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        } else if (root->val < p->val && root->val < q->val) {
            return lowestCommonAncestor(root->right, p, q);
        } else {
            return root;
        }
    }
};

// Main class to build tree and test the function
class Main {
public:
    void run() {
        /*
                  6
                /   \
               2     8
              / \   / \
             0   4 7   9
                / \
               3   5
        */

        TreeNode* root = new TreeNode(6);
        root->left = new TreeNode(2);
        root->right = new TreeNode(8);
        root->left->left = new TreeNode(0);
        root->left->right = new TreeNode(4);
        root->left->right->left = new TreeNode(3);
        root->left->right->right = new TreeNode(5);
        root->right->left = new TreeNode(7);
        root->right->right = new TreeNode(9);

        TreeNode* p = root->left;             // Node with value 2
        TreeNode* q = root->left->right;      // Node with value 4

        Solution sol;
        TreeNode* lca = sol.lowestCommonAncestor(root, p, q);
        if (lca) {
            cout << "Lowest Common Ancestor of " << p->val << " and " << q->val << " is: " << lca->val << endl;
        } else {
            cout << "Lowest Common Ancestor not found." << endl;
        }
    }
};

int main() {
    Main m;
    m.run();
    return 0;
}
