/* Middle of Linked List
 *
 * Given a non-empty, singly linked list with head node `head`, return the
 * middle node of a linked list.
 * if there are two middle node return the second middle node.
 */


#include<iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if (head == nullptr) return head;

        ListNode *slow=head, *fast=head;

        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast->next != nullptr)
            return slow->next;
        return slow;
    }
};


int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);

    Solution *sol = new Solution();
    cout << sol->middleNode(head)->val << endl;
}

