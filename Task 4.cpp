#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

struct Person
{
    string name;
    int age;
};

int main()
{
    int n;
    Person p;

    
    cout << "Enter number of persons: ";
    cin >> n;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    ofstream out("persons.txt");

    for (int i = 0; i < n; i++)
    {
        cout << "Enter name: ";
        getline(cin, p.name);

        cout << "Enter age: ";
        cin >> p.age;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        out << p.name << endl;
        out << p.age << endl;
    }

    out.close();

    
    ifstream in("persons.txt");

    vector<Person> people;

    while (getline(in, p.name))
    {
        if (!(in >> p.age))
            break;

        in.ignore(numeric_limits<streamsize>::max(), '\n');

        people.push_back(p);
    }

    in.close();

    if (people.empty())
    {
        cout << "No persons found!";
        return 0;
    }

    
    int minAge = people[0].age;
    int maxAge = people[0].age;

    for (int i = 1; i < people.size(); i++)
    {
        if (people[i].age < minAge)
            minAge = people[i].age;

        if (people[i].age > maxAge)
            maxAge = people[i].age;
    }

    
    ofstream result("results.txt");

    result << "Younger persons:\n";

    for (int i = 0; i < people.size(); i++)
    {
        if (people[i].age == minAge)
            result << people[i].name << " " << people[i].age << endl;
    }

    result << "Older persons:\n";

    for (int i = 0; i < people.size(); i++)
    {
        if (people[i].age == maxAge)
            result << people[i].name << " " << people[i].age << endl;
    }

    result.close();

    cout << "Data saved successfully!";

    return 0;
}
