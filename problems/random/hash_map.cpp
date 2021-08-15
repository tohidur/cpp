#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cctype>
#include <algorithm>

class HashTable
{
public:
    HashTable();
    std::string status = "";
    std::string object = "";
};

HashTable::HashTable()
{
    status = "never used";
}

}

int main()
{
    std::string str;
    std::vector<std::string> userInput;
    getLine(std::cin, str);
    InputFormatter(str, userInput);
    int numInput = userInput.size();


    HashTable arrayOfObjects[26];

    for (int i=0; i < 26
}

