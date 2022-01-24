/*  Binary Tree inorder traversal
 *
 * Given a binary tree return the inorder traversal of its nodes' values.
 *
 * I: [1, null, 2, 3]
 * O: [1 , 3, 2]
 */

#include<iostream>
#include<stack>
#include<vector>

using namespace std;


template<typename T>
class Node {
public:
    T data;
    Node* left;
    Node* right;
    Node() {
        data = NULL;
        left = nullptr;
        right = nullptr;
    }

    Node(T _data) {
        data = _data;
    }

    Node (T _data, Node* _left, Node* _right) {
        data = _data;
        left = _left;
        right = _right;
    }

    ~Node() {
        delete data;
        delete left;
        delete right;
    }
};


vector<int> inorder(Node<int>* root) {
    stack<Node<int>*> st;
    vector<int> r;

    Node<int>* curr = root;
    while (curr != nullptr || !st.empty()) {
        if (curr != nullptr) {
            st.push(curr);
            curr = curr->left;
        } else {
            curr = st.top();
            st.pop();
            r.push_back(curr->data);
            curr = curr->right;
        }
    }

    return r;
}

int main()
{
    Node<int>* root = new Node<int>(1);
    root->right = new Node<int>(2);
    root->right->left = new Node<int>(3);

    vector<int> r = inorder(root);
    for (int i : r) cout << i << endl;
}
