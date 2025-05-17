#include <iostream>
#include "../Library/StackItem.h"
#include "../Library/Stack.h"

using namespace std;

/**
 * @brief Главная функция программы.
 * @param argc Количество аргументов командной строки.
 * @param argv Массив аргументов командной строки.
 * @return Код завершения программы (0 в случае успеха).
 */
int main(int argc, char* argv[])
{
    Stack stack(5);
    stack.push(10);
    stack.display();
    stack.push(20);
    stack.display();
    stack.pop();
    stack.display();

    stack.push(30);
    stack.push(31);
    stack.push(32);
    stack.push(33);
    stack.push(363);

    stack.display();

    return 0;
}
