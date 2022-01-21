#include "node.h"


// Function to delete a node at a given position.
void LinkedList::deleteNode(int nodeOffset)
{
    Node *temp1 = head, *temp2 = nullptr;
    int ListLen = 0;

    if (head == nullptr) {
        cout << "List Empty." << endl;
        return;
    }

    // Find the lenght of the linked-list.
    while (temp1 != nullptr) {
        temp1 = temp1->next;
        ListLen++;
    }

    // Check if the position to be deleted is less
    // than the length of the linked list.
    if (ListLen < nodeOffset) {
        cout << "Index out of range" << endl;
        return;
    }

    // Declare temp1.
    temp1 = head;

    // Deleting the head.
    if (nodeOffset == 1) {
        head = head->next;
        delete temp1;
        return;
    }

    // Traverse the list to
    // find the node to be deleted.
    while (nodeOffset-- > 1) {
        // Update temp2
        temp2 = temp1;

        // Update temp1
        temp1 = temp1->next;
    }

    // Change the next pointer of the previous node.
    temp2->next = temp1->next;

    // Delete the node.
    delete temp1;
}


// Function to insert a new node at the end.
void LinkedList::insertNode(int data) {
    // Crete the new node.
    Node* newNode = new Node(data);

    // Assign to head
    if (head == nullptr) {
        head = newNode;
        return;
    }

    // Traverse till the end of the list.
    Node* temp = head;
    while (temp->next != nullptr) {
        // Update temp
        temp = temp->next;
    }

    // Insert at the last.
    temp->next = newNode;
}


void LinkedList::printList() {
    Node* temp = head;
    if (head == nullptr) {
        cout << "List Empty." << endl;
        return;
    }

    while (temp!=nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

