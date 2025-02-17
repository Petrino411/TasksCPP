#include <iostream>
using namespace std;

class StackItem
{
private:
    int data;

public:
    StackItem* next;

    StackItem(int value) : data(value), next(nullptr)
    {
    }

    int getData()
    {
        return data;
    }
    
};

class Stack
{
private:
    int size;
    StackItem* top;

public:
    Stack(int size) : size(size), top(nullptr)
    {
    }

    ~Stack()
    {
        while (top != nullptr)
        {
            StackItem* temp = top;
            top = top->next;
            delete temp;
        }
    }

    void push(int x)
    {
        if (size <= 0)
        {
            std::cout << "Stack overflow!" << std::endl;
            return;
        }
        StackItem* temp = new StackItem(x);
        if (top == nullptr)
        {
            top = temp;
        }
        else
        {
            temp->next = top;
            top = temp;
        }
        size--;
    }

    void pop()
    {
        if (top == nullptr)
        {
            std::cout << "Stack is empty!" << std::endl;
            return;
        }
        StackItem* temp = top;
        top = top->next;
        this->size++;
        delete temp;
    }

    void display()
    {
        if (top == nullptr)
        {
            std::cout << "Stack is empty!" << std::endl;
            return;
        }
        StackItem* temp = top;
        cout << "====\n";
        while (temp != nullptr)
        {
            cout << temp->getData() << endl;
            temp = temp->next;
        }
        cout << "====\n";
        
    }
};

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
