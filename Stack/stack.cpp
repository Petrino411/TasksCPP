#include <iostream>
using namespace std;

class StackItem
{
    int data;

public:
    StackItem* next;

    explicit StackItem(const int value) : data(value), next(nullptr)
    {
    }

    int getData() const
    {
        return data;
    }
    
};

class stack
{
    int size;
    StackItem* top;

public:
    explicit stack(const int size) : size(size), top(nullptr)
    {
    }

    ~stack()
    {
        while (top != nullptr)
        {
            const StackItem* temp = top;
            top = top->next;
            delete temp;
        }
    }

    void push(const int x)
    {
        if (size <= 0)
        {
            cout << "Stack overflow!" << '\n';
            return;
        }
        const auto temp = new StackItem(x);
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
            cout << "Stack is empty!" << '\n';
            return;
        }
        const StackItem* temp = top;
        top = top->next;
        this->size++;
        delete temp;
    }

    void display() const
    {
        if (top == nullptr)
        {
            cout << "Stack is empty!" << '\n';
            return;
        }
        StackItem* temp = top;
        cout << "====\n";
        while (temp != nullptr)
        {
            cout << temp->getData() << '\n';
            temp = temp->next;
        }
        cout << "====\n";
        
    }
};

int main(int argc, char* argv[])
{
    stack stack(5);
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
