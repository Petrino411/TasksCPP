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

Stack::Stack(Stack&& other) noexcept
        : capacity(0), count(0), top(nullptr) {
    swap(*this, other);
}

Stack &Stack::operator=(const Stack &other) {
    if (this == &other) return *this;

    clearStack();

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
    clearStack();
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

bool Stack::push(const StackItem &item) {
    return push(item.getData());
}

bool Stack::push(int x) {
    if (count >= capacity) {
        cout << "Stack overflow!" << '\n';
        return false;
    }

    auto *newItem = new StackItem(x);
    newItem->setNext(top);
    top = newItem;
    count++;
    return true;
}

bool Stack::pop() {
    if (!top) {
        cout << "Stack is empty!" << '\n';
        return false;
    }

    StackItem *temp = top;
    top = top->getNext();
    delete temp;
    count--;
    return true;
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

void Stack::swap(Stack &first, Stack &second) noexcept {
    using std::swap;
    swap(first.top, second.top);
    swap(first.count, second.count);
    swap(first.capacity, second.capacity);
}

void Stack::clearStack() {
    while (top) {
        pop();
    }
}
