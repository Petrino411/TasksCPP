#include <iostream>
#include "Stack.h"

using namespace std;

Stack::Stack(int size) {
    if (size <= 0)
        throw invalid_argument("Size must be positive.");
    capacity = size;
    count = 0;
    top = nullptr;
}

Stack::Stack(std::initializer_list<StackItem> l) {
    capacity = l.size();
    count = 0;
    top = nullptr;
    for (auto it: l) {
        push(it);
    }
}

Stack::Stack(const Stack &other) : capacity(other.capacity), count(0), top(nullptr) {
    if (!other.top) return;

    StackItem *currentOther = other.top;
    StackItem *prevNew = nullptr;

    while (currentOther) {
        auto *newItem = new StackItem(currentOther->getData());

        if (!top) {
            top = newItem;
        } else {
            prevNew->setNext(newItem);
        }

        prevNew = newItem;
        currentOther = currentOther->getNext();
        count++;
    }
}

Stack::Stack(Stack &&other) noexcept
        : capacity(other.capacity), count(other.count), top(other.top) {
    other.top = nullptr;
    other.count = 0;
    other.capacity = 0;
}

Stack &Stack::operator=(const Stack &other) {
    if (this == &other) return *this;

    while (top) {
        pop();
    }

    capacity = other.capacity;
    count = 0;
    top = nullptr;

    StackItem *currentOther = other.top;
    StackItem *prevNew = nullptr;

    while (currentOther) {
        auto *newItem = new StackItem(currentOther->getData());

        if (!top) {
            top = newItem;
        } else {
            prevNew->setNext(newItem);
        }

        prevNew = newItem;
        currentOther = currentOther->getNext();
        count++;
    }

    return *this;
}

Stack &Stack::operator=(Stack &&other) noexcept {
    if (this == &other) return *this;

    while (top) {
        pop();
    }

    capacity = other.capacity;
    count = other.count;
    top = other.top;

    other.top = nullptr;
    other.count = 0;
    other.capacity = 0;

    return *this;
}

Stack::~Stack() {
    while (top) {
        StackItem *temp = top;
        top = top->getNext();
        delete temp;
    }
}

void Stack::push(const StackItem &item) {
    push(item.getData());
}

void Stack::push(int x) {
    if (count >= capacity) {
        cout << "Stack overflow!" << '\n';
        return;
    }

    auto *newItem = new StackItem(x);
    newItem->setNext(top);
    top = newItem;
    count++;
}

void Stack::pop() {
    if (!top) {
        cout << "Stack is empty!" << '\n';
        return;
    }

    StackItem *temp = top;
    top = top->getNext();
    delete temp;
    count--;
}

void Stack::display() const {
    if (!top) {
        cout << "Stack is empty!" << '\n';
        return;
    }

    StackItem *temp = top;
    cout << "====\n";
    while (temp) {
        cout << temp->getData() << '\n';
        temp = temp->getNext();
    }
    cout << "====\n";
}

int Stack::size() const {
    return count;
}

bool Stack::isEmpty() const {
    return top == nullptr;
}
