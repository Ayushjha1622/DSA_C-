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

// Build tree from preorder (-1 means NULL)
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

// Find node with given value
Node* find(Node* root, int val) {
    if (root == NULL) return NULL;

    if (root->data == val) return root;

    Node* left = find(root->left, val);
    if (left != NULL) return left;

    return find(root->right, val);
}

// Lowest Common Ancestor function
Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
    if (root == NULL) return NULL;

    if (root->data == p->data || root->data == q->data) {
        return root;
    }

    Node* leftLCA = lowestCommonAncestor(root->left, p, q);
    Node* rightLCA = lowestCommonAncestor(root->right, p, q);

    if (leftLCA && rightLCA) return root;
    return leftLCA != NULL ? leftLCA : rightLCA;
}

int main() {
    vector<int> preorder = {3, 5, 6, -1, -1, 2, 7, -1, -1, 4, -1, -1, 1, 0, -1, -1, 8, -1, -1};
    int idx = -1;

    Node* root = buildTree(preorder, idx);

    int val1 = 5, val2 = 1;
    Node* p = find(root, val1);
    Node* q = find(root, val2);

    Node* lca = lowestCommonAncestor(root, p, q);
    if (lca) {
        cout << "Lowest Common Ancestor of " << val1 << " and " << val2 << " is: " << lca->data << endl;
    } else {
        cout << "One or both nodes not found in the tree." << endl;
    }

    return 0;
}
