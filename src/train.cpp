// Copyright 2021 NNTU-CS
#include "train.h"
#include <iostream>
Train::Train() : countOp(0), first(nullptr) {}
Train::~Train() {
    if (!first) return;
    Car* temp = first->next;
    while (temp != first) {
        Car* next = temp->next;
        delete temp;
        temp = next;
    }
    delete first;
}
void Train::addCar(bool light) {
    Car* newCar = new Car();
    newCar->light = light;
    newCar->next = nullptr;
    newCar->prev = nullptr;
    if (!first) {
        first = newCar;
        first->next = first;
        first->prev = first;
    } else {
        Car* last = first->prev;
        last->next = newCar;
        newCar->prev = last;
        newCar->next = first;
        first->prev = newCar;
    }
}
int Train::getLength() {
    if (!first) return 0;
    Car* current = first;
    if (!current->light) {
        current->light = true;
    }
    int length = 0;
    bool done = false;
    while (!done) {
        while (true) {
            current = current->next;
            countOp++;
            length++;
            if (current->light) {
                current->light = false;
                break;
            }
        }
        int back = 0;
        while (back < length) {
            current = current->prev;
            countOp++;
            back++;
        }
        if (!current->light) {
            done = true;
        } else {
            length = 0;
        }
    }
    return length;
}
int Train::getOpCount() {
    return countOp;
}
