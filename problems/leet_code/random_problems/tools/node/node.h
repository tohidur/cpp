#include<iostream>
#include<vector>

using namespace std;


// Node class to represent a node of linked list.
class Node {
public:
    int data;
    Node* next;


    // Default constructor
    Node() {
        data = 0;
        next = nullptr;
    }

    // Parameterised constructor
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};


class NTreeNode {
public:
    int data;
    vector<NTreeNode*> childs;

    NTreeNode(int data) {
        this->data = data;
    }
};


// LinkedList class to implement a linked list.
class LinkedList {
public:
    Node* head;

    // Default constructor
    LinkedList() { head = nullptr; }

    // Function to insert a node at the end of the linked list.
    void insertNode(int);

    // Function to print the linked list.
    void printList();

    // Function to delete a node at give position
    void deleteNode(int);
};

