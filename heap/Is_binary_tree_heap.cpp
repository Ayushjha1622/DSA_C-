#include <iostream>
using namespace std;

// Node class to define binary tree structure
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Solution class to check heap properties
class Solution {
public:
    // Count total number of nodes in the tree
    int countNodes(Node* root) {
        if (root == nullptr) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    // Check if the tree is Complete Binary Tree
    bool isCBT(Node* root, int index, int count) {
        if (root == nullptr) return true;
        if (index >= count) return false;

        bool left = isCBT(root->left, 2 * index + 1, count);
        bool right = isCBT(root->right, 2 * index + 2, count);
        return left && right;
    }

    // Check if the tree follows Max-Heap order property
    bool isMaxOrder(Node* root) {
        if (root->left == nullptr && root->right == nullptr)
            return true;

        if (root->right == nullptr)
            return root->data >= root->left->data && isMaxOrder(root->left);

        else {
            bool left = isMaxOrder(root->left);
            bool right = isMaxOrder(root->right);
            return (root->data >= root->left->data &&
                    root->data >= root->right->data &&
                    left && right);
        }
    }

    // Final function to check if the tree is a heap
    bool isHeap(Node* root) {
        int totalCount = countNodes(root);
        return isCBT(root, 0, totalCount) && isMaxOrder(root);
    }
};

// Example usage
int main() {
    Node* root = new Node(10);
    root->left = new Node(9);
    root->right = new Node(8);
    root->left->left = new Node(7);
    root->left->right = new Node(6);
    root->right->left = new Node(5);

    Solution sol;
    if (sol.isHeap(root))
        cout << "The binary tree is a Max Heap." << endl;
    else
        cout << "The binary tree is NOT a Max Heap." << endl;

    return 0;
}