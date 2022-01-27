/*
 * To represent is a cycle in the given linked list, we use an integer,
 * pos which represents  the position (0-indexed) in the linked list where
 * tail connects to. If pos is -1 then there is no cycle in the linked list
 *
 * Ex: Input: head = [3,2,0,-4], pos = 1
 *     Output: true
 */
#include<iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode* next;
    ListNode(int _val): val(_val), next(nullptr) {}
};


class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (head == nullptr) return false;
        ListNode *s = head, *f = head->next;

        while (s != f) {
            if (f->next == nullptr || f->next->next == nullptr) return false;
            s = s->next;
            f = f->next->next;
        }
        return true;
    }
};


int main()
{
    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next;

    Solution *sol = new Solution();
    cout << sol->hasCycle(head) << endl;
}

