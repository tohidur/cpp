 /* Invert a binary tree
 */

#include<iostream>
#include<vector>

using namespace std;


struct Node {
    int val;
    struct Node *left, *right;
    Node(int v): val{v}, left{nullptr}, right{nullptr} {}

    void repr() {
        cout << this->val << '\n';
        cout << this->left->val << '\n';
        cout << this->right->val << '\n';
        cout << this->left->left->val << '\n';
        cout << this->left->right << '\n';
        cout << this->right->left << '\n';
        cout << this->right->right->val << '\n';
    }
};

Node* invert_tree(Node* root) {
    if (root==nullptr) return root;

    Node* left = invert_tree(root->left);
    Node* right = invert_tree(root->right);

    root->right = left;
    root->left = right;
    return root;
}

int main() {
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->right->right = new Node(9);
    Node* inverted_node = invert_tree(root);
    inverted_node->repr();
}

