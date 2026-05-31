// Copyright 2021 NNTU-CS
#include "train.h"
#include <iostream>
Train::Train() : countOp(0), first(nullptr) {
}
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

void Train::addCar(bool light)  
{
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

int Train::getLength()
{
    if (!first)
        return 0;

    countOp = 0;
    Car* current = first;
    current->light = true;

    while (true) {
        current = current->next;
        countOp++;
        if (!current->light) {
            current->light = true;
        } else {
            break;
        }
    }

    int length = 1;
    Car* start = current; 

    while (true) {
        current = current->prev;
        countOp++;
        if (current == start) {
            break;
        }
        length++;
    }
    return length;
}

int Train::getOpCount()
{
    return countOp;
}
