#include <iostream>
#include <ostream>
#include <string>

using namespace std;

class Person
{
    string lastname;
    string firstname;
    string patronymic;

public:
    Person();

    Person(const string& lastname, const string& firstname, const string& patronymic)
    {
        this->lastname = lastname;
        this->firstname = firstname;
        this->patronymic = patronymic;
    }

    void Show() const
    {
        cout << this->lastname << " " << this->firstname << endl;
    }

    void ShowFormal() const
    {
        cout << this->lastname << " " << this->firstname << " " << this->patronymic << endl;
    }
};


int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Rus");
    const Person p1("Иванов", "Иван", "Иванович");
    p1.Show();
    p1.ShowFormal();

    return 0;
}
