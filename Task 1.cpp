
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string name;
    string id;
    float grade;

    cout << "Enter Student Full Name: ";
    getline(cin, name);

    cout << "Enter Student ID: ";
    getline(cin, id);

    cout << "Enter Student Grade: ";
    cin >> grade;

    ofstream myfile("Student.txt");

    if (!myfile.is_open())
    {
        cout << "Error, file is not opened";
    }
    else
    {
        myfile << "Student Name: " << name << endl;
        myfile << "Student ID: " << id << endl;
        myfile << "Student Grade: " << grade << endl;

        cout << "Data saved successfully";
    }

    myfile.close();

    return 0;
}



