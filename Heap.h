//
// Created by barto on 07.04.2022.
//

#ifndef SDIZO_HEAP_H
#define SDIZO_HEAP_H


#include <string>

class Heap{
    int * heap;
    int size;
    int numberOfLvl;

    void resize(bool isBigger, int value);

public:
    Heap();
    ~Heap();

    void displayTab();
    void display(std::string sp, std::string sn, int valueOfElement);
    void repair();
    void addNewElement(int valueOfElement);
    void remove(int index);
    void level();
    void fillElementsTakenFromFile(std::string fileName);
    void randomFillHeap(int amountOfElements);
    bool search(int value);
    int getsize();
    int getValueFromIndex(int index);
};


#endif //SDIZO_HEAP_H
