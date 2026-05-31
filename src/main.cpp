// Copyright 2022 NNTU-CS
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "train.h"

int main() {


    std::srand(static_cast<unsigned int>(time(nullptr)));

    std::cout << "Quantity\tFalse\t\tTrue\t\tRandom\n";

    for (int Quantity = 2; Quantity <= 50; ++Quantity) {
        int opTrue;
        int opFalse;
        int opRandom;
        Train train1;
        for (int i = 0; i < Quantity; i++)
            train1.addCar(false);
        train1.getLength();
        opFalse = train1.getOpCount();
        
        Train train2;
        for (int i = 0; i < Quantity; i++)
            train2.addCar(true);
        train2.getLength();
        opTrue = train2.getOpCount();
        
        Train train3;
        for (int i = 0; i < Quantity; i++)
            train3.addCar(std::rand() % 2);
        train3.getLength();
        opRandom = train3.getOpCount();

        std::cout << Quantity << "\t\t" << opFalse << "\t\t" << opTrue << "\t\t" << opRandom << "\n";

    }

    return 0;
}
