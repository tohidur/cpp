/* To Lower Case String
 *
 * Given a string make it a lowercase.
 */
#include<algorithm>
#include<iostream>
#include<string>

using namespace std;

void to_lower_stl(string& str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
}


string to_lower(string str) {
    const uint diff = 'a' - 'A';
    string lower;
    lower.reserve(str.length());
    for (int i=0;i<str.size();i++) {
        lower += (str[i] >= 'A' && str[i] <= 'Z') ? str[i] + diff : str[i];
    }

    return lower;
}


int main()
{
    string str {"HeLLo"};
    to_lower_stl(str);
    cout << str << endl;
    cout << endl;
    cout << to_lower(str) << endl;
}

