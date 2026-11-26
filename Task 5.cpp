#include <iostream>
#include <fstream>
#include <limits>
using namespace std;

int main()
{
    ofstream file("students.txt", ios::app);

    char name[20];
    int id;
    float grade;
    char choice;

    do
    {
        cout << "Enter student name: ";
        cin.getline(name, 20);

        cout << "Enter student ID: ";
        cin >> id;

        cout << "Enter student grade: ";
        cin >> grade;

        file << name << ", "
             << id << ", "
             << grade << " $"
             << endl;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Add another student? (y/n): ";
        cin >> choice;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (choice == 'y' || choice == 'Y');

    file.close();

    return 0;
}
