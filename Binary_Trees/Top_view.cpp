#include<iostream>
#include<vector>
#include<queue>
#include<map>
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

// Build tree from preorder with -1 as NULL
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

// Top view of binary tree
void topView(Node* root) {
    if (root == NULL) return;

    map<int, int> m; // horizontal distance -> node value
    queue<pair<Node*, int>> q; // node, horizontal distance
    q.push({root, 0});

    while (!q.empty()) {
        Node* curr = q.front().first;
        int currHD = q.front().second;
        q.pop();

        if (m.find(currHD) == m.end()) {
            m[currHD] = curr->data; // store only first node at each HD
        }

        if (curr->left) {
            q.push({curr->left, currHD - 1});
        }
        if (curr->right) {
            q.push({curr->right, currHD + 1});
        }
    }

    // Print top view
    for (auto it : m) {
        cout << it.second << " ";
    }
    cout << endl;
}

int main() {
    vector<int> preOrder = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    int idx = -1;

    Node* root = buildTree(preOrder, idx);

    cout << "Top View: ";
    topView(root);

    return 0;
}
