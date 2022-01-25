/* Is Binary Tree Symmetric
 *
 */

#include<iostream>

using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int _data) { data=_data; left = right = nullptr; }
};


bool is_mirror(Node* t1, Node* t2)
{
    if (t1 == nullptr && t2 == nullptr) return true;
    if (t1 == nullptr || t2 == nullptr) return false;
    return (t1->data == t2->data) && is_mirror(t1->left, t2->right) \
        && is_mirror(t1->right, t2->left);

}


bool is_symmetric(Node* root)
{
    return is_mirror(root, root);
}


int main()
{
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    //root->right->right = new Node(3);

    cout << is_symmetric(root) << endl;
}

