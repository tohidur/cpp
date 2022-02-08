/* Merge two sorted linked list
 *
 * You are given the heads of two sorted linked list list1 and list2.
 * Merge the two lists in one sorted list. The list should be made by
 * splicing together the nodes of the first two lists.
 */

#include<iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *temp = new ListNode(-1);
        ListNode *cur = temp;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                cur->next = list1;
                list1 = list1->next;
            }
            else {
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }

        cur->next = (list1 != nullptr) ? list2 : list1;
        return temp->next;
    }
};


int main() {
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    Solution *sol = new Solution();
    ListNode *res = sol->mergeTwoLists(list1, list2);
    while (res != nullptr) {
        cout << res->val << endl;
        res = res->next;
    }
}

