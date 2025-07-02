#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to build tree from preorder with -1 as NULL
Node* buildTree(vector<int>& preorder, int& idx) {
    idx++;

    if (preorder[idx] == -1) {
        return NULL;
    }

    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder, idx);
    root->right = buildTree(preorder, idx);

    return root;
}

// Height + Diameter in one traversal
int height(Node* root, int& ans) {
    if (root == NULL) return 0;

    int leftHt = height(root->left, ans);
    int rightHt = height(root->right, ans);

    ans = max(ans, leftHt + rightHt); // diameter in edges
    return max(leftHt, rightHt) + 1;
}

int diameter(Node* root) {
    int ans = 0;
    height(root, ans);
    return ans;
}

int main() {
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    int idx = -1;

    Node* root = buildTree(preorder, idx);

    cout << "Diameter of the tree (in edges): " << diameter(root) << endl;

    return 0;
}
