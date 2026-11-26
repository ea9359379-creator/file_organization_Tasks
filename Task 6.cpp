
#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

int main()
{
    int grade;


    ofstream out("grades.txt");

    if (!out)
    {
        cout << "Error creating file!";
        return 1;
    }

    cout << "Enter 5 grades:\n";

    for (int i = 0; i < 5; i++)
    {
        cin >> grade;
        out << grade << endl;
    }

    out.close();


    ifstream in("grades.txt");

    if (!in)
    {
        cout << "Error opening file!";
        return 1;
    }

    cout << "\nGrades before deletion:\n";

    while (in >> grade)
    {
        cout << grade << endl;
    }

    in.close();


    int deleteGrade;
    bool found = false;

    cout << "\nEnter grade to delete: ";
    cin >> deleteGrade;

    ifstream original("grades.txt");
    ofstream temp("temp.txt");

    if (!original || !temp)
    {
        cout << "Error opening files!";
        return 1;
    }

    while (original >> grade)
    {
        if (grade != deleteGrade)
        {
            temp << grade << endl;
        }
        else
        {
            found = true;
        }
    }

    original.close();
    temp.close();


    if (remove("grades.txt") == 0 &&
        rename("temp.txt", "grades.txt") == 0)
    {
        cout << "\nFile updated successfully!\n";

        if (!found)
            cout << "Grade not found!\n";
    }
    else
    {
        cout << "Error replacing file!\n";
        return 1;
    }


    ifstream result("grades.txt");

    cout << "\nGrades after deletion:\n";

    while (result >> grade)
    {
        cout << grade << endl;
    }

    result.close();

    return 0;
}
