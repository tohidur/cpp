#include <iostream>
#include "Node.cpp"
using namespace std;
int main()
{
    Node<char> *p,*q,*r;
    // Link the nodes with each other
    q = new Node<char>('B');
    p = new Node<char>('A',q);
    r = new Node<char>('c');

    // modify the list
    q->InsertAfter(r)
    
    cout << "p:" << p->data << endl;
    cout << "p_next:" << p->NextNode()->data << endl;
    cout << "q:" << q->data << endl;
    cout << "q_next:" << q->NextNode()->data << endl;
    cout << "r:" << r->data << endl;

    p = p->NextNode();

    cout << endl;
}

