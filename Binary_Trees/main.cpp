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

// Preorder traversal
void preOrderTraversal(Node* root) {
    if (root == NULL) return;

    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// Inorder traversal
void inOrderTraversal(Node* root) {
    if (root == NULL) return;

    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

// Postorder traversal
void postOrderTraversal(Node* root) {
    if (root == NULL) return;

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

// Level order traversal (BFS)
void levelOrderTraversal(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        if(curr == NULL){
            if(!q.empty()){
                cout << endl;
                q.push(NULL);
                continue;
            } else{
                break;
            }
        }

        cout << curr->data << " ";

        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
}

int main() {
    vector<int> preOrder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    int idx = -1;

    Node* root = buildTree(preOrder, idx);

    cout << "Preorder traversal: ";
    preOrderTraversal(root);
    cout << endl;

    cout << "Inorder traversal: ";
    inOrderTraversal(root);
    cout << endl;

    cout << "Postorder traversal: ";
    postOrderTraversal(root);
    cout << endl;

    cout << "Level order traversal: ";
    levelOrderTraversal(root);
    cout << endl;

    return 0;
}
