//
// Created by barto on 05.04.2022.
//

#ifndef SDIZO_ARRAY_H
#define SDIZO_ARRAY_H

#include <string>

using namespace std;

class Array {
int *pointer;
int numberOfElements;

public:
    Array();
    ~Array();
    void display();
    void relocate();
    void addAtTheBeginning(int  valueOfTheNewElement);
    void addAtTheEnd(int valueOfTheNewElement);
    void addAtTheIndex(int  indexOfNewElement, int valueOfTheNewElement);
    void remove(int indexElementToRemove);
    void removeFromBeginning();
    void removeFromEnd();
    void find(int searchedNumber);
    void fillElementsTakenFromFile(string fileName);
    void fillRandomNumbers(int NumberOfElements);
    int getNumberOfElements();
    void fillFileWithElements(int value, string fileName);
};


#endif //SDIZO_ARRAY_H
