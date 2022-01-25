/*  Merge two binary trees
 *
 *  The merge rule.
 *  If two nodes overlap, then sum node values up as the new value of the
 *  merged node. Otherwise, the NOT null node will be used as the node of
 *  new tree
 */

#include<iostream>
#include<stack>

using namespace std;


class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node() { data=0; }
    Node(int _data) { data=_data; }
};

Node* merge(Node* r1, Node* r2) {
    if (r2 == nullptr)
        return r1;
    if (r1 == nullptr)
        return r2;

    r1->data += r2->data;
    r1->left = merge(r1->left, r2->left);
    r1->right = merge(r1->right, r2->right);

    return r1;
}

void printInOrder(Node* r) {
    stack<Node*> st;
    Node* curr = r;

    while (curr != nullptr || !st.empty()) {
        if (curr != nullptr) {
            st.push(curr);
            curr = curr->left;
        } else {
            curr = st.top();
            st.pop();
            cout << curr->data << " " << endl;
            curr = curr->right;
        }
    }
}

int main()
{
    Node* r1 = new Node(3);
    r1->left = new Node(2);
    r1->right = new Node(5);
    r1->left->left = new Node(1);

    Node* r2 = new Node(2);
    r2->left = new Node(1);
    r2->right = new Node(3);
    r2->left->right = new Node(4);
    r2->right->right = new Node(9);

    Node* merged_tree = merge(r1,r2);
    printInOrder(merged_tree);
}

