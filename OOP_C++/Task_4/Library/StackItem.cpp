#include "StackItem.h"

StackItem::StackItem(const int value) {
    data = value;
    next = nullptr;
}

int StackItem::getData() const {
    return data;
}

StackItem *StackItem::getNext() {
    return next;
}

void StackItem::setNext(StackItem *next_item) {
    next = next_item;
}
