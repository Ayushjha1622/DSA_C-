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

// Build tree from preorder traversal with -1 as null
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

// Height of the tree
int height(Node* root) {
    if (root == NULL) return 0;
    return max(height(root->left), height(root->right)) + 1;
}

// Count number of nodes
int countNodes(Node* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    int idx = -1;

    Node* root = buildTree(preorder, idx);

    cout << "Height of the tree: " << height(root) << endl;
    cout << "Total number of nodes: " << countNodes(root) << endl;

    return 0;
}
