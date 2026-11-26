#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<string> names = {
        "Hadeer Mahmoud",
        "Youssef Ali",
        "Ahmed Mostafa",
        "Esraa Ebrahim"
    };

    sort(names.begin(), names.end());

    cout << "Names in Ascending Order:" << endl;

    for(int i = 0; i < names.size(); i++)
    {
        cout << names[i] << endl;
    }

    return 0;
}
