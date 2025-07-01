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

// Build tree from preorder with -1 as null
Node* buildTree(vector<int>& preOrder, int& idx) {
    idx++;

    if (preOrder[idx] == -1) {
        return NULL;
    }

    Node* root = new Node(preOrder[idx]);
    root->left = buildTree(preOrder, idx);
    root->right = buildTree(preOrder, idx);

    return root;
}

// Height of tree
int height(Node* root) {
    if (root == NULL) {
        return 0;
    }

    int leftHt = height(root->left);
    int rightHt = height(root->right);
    return max(leftHt, rightHt) + 1;
}

int main() {
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    int idx = -1;

    Node* root = buildTree(preorder, idx);

    cout << "Height of the tree: " << height(root) << endl;

    return 0;
}
