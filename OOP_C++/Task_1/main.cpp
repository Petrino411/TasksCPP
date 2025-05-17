#include <iostream>
#include <ostream>
#include <string>

using namespace std;

/**
*@brief Класс, представляющий человека с ФИО
*/
class Person
{
    string lastname;
    string firstname;
    string patronymic;

public:
    Person();

    /**
  * @brief Параметризованный конструктор
  * @param lastname Фамилия
  * @param firstname Имя
  * @param patronymic Отчество
  */
    Person(const string& lastname, const string& firstname, const string& patronymic)
    {
        this->lastname = lastname;
        this->firstname = firstname;
        this->patronymic = patronymic;
    }

    /**
     * @brief Вывод краткой информации (Фамилия Имя)
     */
    void Show() const
    {
        cout << this->lastname << " " << this->firstname << endl;
    }

    /**
     * @brief Вывод полной информации (Фамилия Имя Отчество)
     */
    void ShowFormal() const
    {
        cout << this->lastname << " " << this->firstname << " " << this->patronymic << endl;
    }
};


/**
    *@brief Точка входа в программу
    *@param argc Количество аргументов командной строки
    *@param argv Массив аргументов командной строки
    *@return Код возврата
 */
int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "rus");
    const Person p1("Иванов", "Иван", "Иванович");
    p1.Show();
    p1.ShowFormal();

    return 0;
}
