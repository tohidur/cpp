#include <iostream>
#include <queue>

using namespace std;


struct Node {
    int key;
    struct Node *left, *right;
};

Node* newNode(int key) {
    Node* temp = new Node;
    temp->key = key;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
};


int countinchild(Node* root)
{
    if (root == NULL)
        return 0;

    int numberofnodes = 0;
    int sum = 0;

    queue<Node*> q;
    q.push(root);

    while (q.size() != 0)
    {
        Node* f = q.front();
        q.pop();

        numberofnodes++;
        sum += f->key;

        if (f->left)
            q.push(f->left);
        if (f->right)
            q.push(f->right);
    }

    return abs(numberofnodes - sum);
};


int distributeCoins(Node* root) {
    int moves = 0;

    if (root == NULL)
        return 0;

    if (!root->left && !root->right)
        return 0;

    queue<Node*> q;
    q.push(root);

    while (!q.empty())
    {
        Node* f = q.front();
        q.pop();

        moves += countinchild(f->left);
        moves += countinchild(f->right);

        if (f->left)
            q.push(f->left);
        if (f->right)
            q.push(f->right);
    }

    return moves;
}


int main()
{
    Node* root = newNode(0);
    root->left = newNode(3);
    root->right = newNode(0);

    cout << distributeCoins(root);

    return 0;
}
