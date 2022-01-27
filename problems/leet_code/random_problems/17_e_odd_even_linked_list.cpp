/* Odd Even Linked List
 * Break the linked list into even and odd position nodes.
 */

#include<iostream>
#include<forward_list>
#include<vector>

using namespace std;

vector<forward_list<int>> odd_even_list(forward_list<int>& l)
{
    vector<forward_list<int>> result;
    if (l.empty()) return result;

    forward_list<int> odd, even;
    int count = 0;
    for (auto i = l.begin(); i != l.end(); ++i) {
        if (count % 2 == 0) {
            cout << "pushing to even: - " << *i << endl;
            even.push_front(*i);
        } else {
            cout << "pushing to odd: - " << *i << endl;
            odd.push_front(*i);
        }
        count++;
    }

    odd.reverse();
    even.reverse();
    result.push_back(odd);
    result.push_back(even);

    return result;
}

int main()
{
    forward_list<int> l;
    int nums[] = {7,4,6,5,3,1,2};
    for (int i : nums)
        l.push_front(i);
    l.reverse();

    vector<forward_list<int>> r = odd_even_list(l);

    cout << "Odd: " << endl;
    for (auto i = r[0].begin(); i != r[0].end(); ++i)
        cout << *i << endl;

    cout << "Even: " << endl;
    for (auto i = r[1].begin(); i != r[1].end(); ++i)
        cout << *i << endl;
}

