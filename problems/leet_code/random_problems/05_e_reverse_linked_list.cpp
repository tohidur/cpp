/* Reverse Linked List
 *
 * Reverse a single linked list
 *
 */

#include "tools/node/node.h"

Node* reverse_list(Node* head) {
    Node* prev;

    while (head != nullptr) {
        Node* next = head->next; 
        head->next = prev;
        prev = head;
        head = next;
    }

    return prev;
}


int main()
{
    LinkedList list;
    list.insertNode(1);
    list.insertNode(2);
    list.insertNode(3);
    list.insertNode(4);
    list.insertNode(4);
    list.insertNode(4);
    list.printList();
    list.head = reverse_list(list.head);
    list.printList();
}

