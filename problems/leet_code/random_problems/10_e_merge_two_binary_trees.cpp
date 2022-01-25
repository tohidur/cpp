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


struct snode
{
    Node *l, *r;
};


Node* merge_itr(Node* t1, Node* t2)
{
    if (! t1)
        return t2;
    if (! t2)
        return t1;

    stack<snode> s;
    snode temp;
    temp.l = t1;
    temp.r = t2;
    s.push(temp);

    snode n;
    while (!s.empty())
    {
        n = s.top();
        s.pop();
        if (n.l == nullptr || n.r == nullptr)
            continue;

        n.l->data += n.r->data;

        if (n.l->left == nullptr)
            n.l->left = n.r->left;
        else
        {
            snode t;
            t.l = n.l->left;
            t.r = n.r->left;
            s.push(t);
        }

        if (n.l->right == nullptr)
            n.l->right = n.r->right;
        else
        {
            snode t;
            t.l = n.l->right;
            t.r = n.r->right;
            s.push(t);
        }
    }

    return t1;
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

    cout << "Recursive Solution" << endl;
    Node* merged_rec = merge(r1,r2);
    printInOrder(merged_rec);
    cout << endl << endl;

    cout << "Iterative Solution" << endl;
    Node* merged_itr = merge_itr(r1,r2);
    printInOrder(merged_itr);
    cout << endl << endl;
}

