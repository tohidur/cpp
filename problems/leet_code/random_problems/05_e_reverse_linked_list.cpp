/* Reverse Linked List
 *
 * Reverse a single linked list
 *
 */

#include "tools/node/node.h"

LinkedList& reverse_list(LinkedList& head) {
    return head;
}


int main()
{
    LinkedList head;
    head.insertNode(1);
    head.insertNode(2);
    head.insertNode(3);
    head.insertNode(4);
    head.insertNode(4);
    head.insertNode(4);
    head.printList();
}

