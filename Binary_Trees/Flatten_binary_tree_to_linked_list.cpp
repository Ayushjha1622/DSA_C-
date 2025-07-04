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

// class Solution {
// public:
//     TreeNode* nextRight = NULL;

//     void flatten(TreeNode* root) {
//         if (root == NULL) {
//             return;
//         }

//         flatten(root->right);
//         flatten(root->left);

//         root->left = NULL;
//         root->right = nextRight;
//         nextRight = root;
//     }
// };

class Solution{
    public:
    TreeNode* nextRight = NULL;

    void flatten(TreeNode* root){
        if(root == NULL){
            return;
        }

        flatten(root->right);
        flatten(root->left);

        root->left = NULL;
        root->right = nextRight;
        nextRight =    root;

    }



    };

// Build tree from preorder array with -1 as NULL
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

// Print right-skewed (flattened) tree
void printFlattened(TreeNode* root) {
    while (root != NULL) {
        cout << root->val << " ";
        root = root->right;
    }
    cout << endl;
}

int main() {
    vector<int> preorder = {1, 2, 3, -1, -1, 4, -1, -1, 5, -1, 6, -1, -1};
    int idx = 0;

    TreeNode* root = buildTree(preorder, idx);

    Solution sol;
    sol.flatten(root);

    cout << "Flattened Tree (Right Skewed): ";
    printFlattened(root);

    return 0;
}
