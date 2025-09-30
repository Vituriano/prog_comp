#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    string S;
    string result;
    getline(cin, S);

    for (unsigned long i = 0; i < S.size(); ++i)
    {
        char curr = S[i];

        result.push_back(curr);

        char last = result.size() - 1;

        if (result.size() >= 3 && result.substr(last - 2, 3) == "ABC")
        {
            result.pop_back();
            result.pop_back();
            result.pop_back();
        }
    }
    cout << result;

    return 0;
}
