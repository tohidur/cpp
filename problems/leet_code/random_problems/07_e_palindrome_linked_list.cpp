/* Palindrome Linked List
 *
 * Given a singly linked list, determine if it is a palindrome
 *
 * Do it in O(n) time and O(1) space
 *
 */

#include<forward_list>
#include<iostream>
#include "tools/node/node.h"

using namespace std;


bool is_palindrome_stl(forward_list<int>& fl)
{
    forward_list<int> copy(fl);
    copy.reverse();
    forward_list<int>::iterator b1 = fl.begin(), b2=copy.begin();
    while (b1 != fl.end()) {
        if (*b1 != *b2) return false;
        b1++;
        b2++;
    }
    return true;
}

template<typename T>
bool is_palindrome_stl_i1(forward_list<T>& lf) {
    auto iter = lf.begin();
    forward_list<decltype(iter)> bv;
    int sz = 0;
    for (;iter!=lf.end();++iter) {
        bv.push_front(iter);
        ++sz;
    }

    sz /= 2;
    iter = lf.begin();
    for (auto it2=bv.begin();sz;--sz,++iter,++it2) {
        if (**it2!=*iter) return false;
    }
    return true;
}


int main()
{
    // Using STL
    forward_list<int> fl1{1,1,3,1,1};
    forward_list<int> fl2{1,5,3,1,1};
    cout << is_palindrome_stl(fl1) << endl;
    cout << is_palindrome_stl(fl2) << endl;
    cout << endl;


    cout << is_palindrome_stl_i1(fl1) << endl;
    cout << is_palindrome_stl_i1(fl2) << endl;
}

