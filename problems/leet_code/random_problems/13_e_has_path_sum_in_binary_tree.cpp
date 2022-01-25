/* Has Path Sum In Binary Tree
 *
 * Given a number and a tree check if any path in the tree starting from root
 * Has path sum equal to the number.
 */

#include<iostream>

using namespace std;


struct Node {
    int data;
    Node *left, *right;
    Node(int _data) { data = _data; left = right = nullptr; }
};


bool has_path_sum(Node* root, int n)
{
    if (root == nullptr)
        return (n == 0) ? true : false;

    n -= root->data;
    return has_path_sum(root->left, n) || has_path_sum(root->right, n);
}


int main()
{
    Node* r = new Node(5);
    r->left = new Node(4);
    r->right = new Node(8);
    r->left->left = new Node(11);
    r->right->left = new Node(13);
    r->right->right = new Node(4);
    r->left->left->left = new Node(7);
    r->left->left->right = new Node(2);
    r->right->right->right = new Node(1);

    cout << has_path_sum(r, 18) << endl;
    cout << has_path_sum(r, 23) << endl;
}

