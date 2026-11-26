#include <iostream>
#include <fstream>
#include <filesystem>
using namespace std;

int main()
{
    ofstream file("welcome.txt");

    file << "Hello Everybody";

    file.close();

    fstream f("welcome.txt", ios::in | ios::out);

    f.seekp(11);

    f << "one";

    f.close();

    filesystem::resize_file("welcome.txt", 14);

    ifstream result("welcome.txt");

    string line;

    getline(result, line);

    cout << line;

    result.close();

    return 0;
}
