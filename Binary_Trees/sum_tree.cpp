#include<iostream>
#include<vector>
#include<queue>
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
    if (preOrder[idx] == -1) return NULL;

    Node* root = new Node(preOrder[idx]);
    root->left = buildTree(preOrder, idx);
    root->right = buildTree(preOrder, idx);

    return root;
}

// Preorder traversal
void preOrderTraversal(Node* root) {
    if (root == NULL) return;

    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// Convert to sum tree (non-leaf nodes = sum of left & right subtree values)
int sumTree(Node* root) {
    if (root == NULL) return 0;

    int leftSum = sumTree(root->left);
    int rightSum = sumTree(root->right);

    root->data += leftSum + rightSum;
    return root->data;
}

int main() {
    vector<int> preOrder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    int idx = -1;

    Node* root = buildTree(preOrder, idx);

    cout << "Original Preorder: ";
    preOrderTraversal(root);
    cout << endl;

    // Convert tree into sum tree
    sumTree(root);

    cout << "After sumTree Preorder: ";
    preOrderTraversal(root);
    cout << endl;

    return 0;
}
