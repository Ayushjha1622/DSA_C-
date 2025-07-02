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

    if (preOrder[idx] == -1) {
        return NULL;
    }

    Node* root = new Node(preOrder[idx]);
    root->left = buildTree(preOrder, idx);
    root->right = buildTree(preOrder, idx);

    return root;
}

// Print all nodes at Kth level (root at level 1)
void KthLevel(Node* root, int k) {
    if (root == NULL) return;

    if (k == 1) {
        cout << root->data << " ";
        return;
    }

    KthLevel(root->left, k - 1);
    KthLevel(root->right, k - 1);
}

int main() {
    vector<int> preOrder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    int idx = -1;

    Node* root = buildTree(preOrder, idx);

    int k = 3;
    cout << "Nodes at level " << k << ": ";
    KthLevel(root, k);
    cout << endl;

    return 0;
}
