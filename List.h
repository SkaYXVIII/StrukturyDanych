//
// Created by barto on 23.03.2022.
//

#ifndef SDIZO_LIST_H
#define SDIZO_LIST_H

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

struct ElemList
{
    int data;
    ElemList *next, *prev;
};

class List {
    ElemList *head, *tail;
    int numberOfElements;
    ElemList * searchUtility(int searchedNumber);
    void showReverse();

public:
    List();
    ~List();
    void display();
    bool find(int searchedNumber);
    void fillElementsTakenFromFile(string fileName);
    void remove(int keyToRemove);
    void randomFillList(int amountOfElements);
    void addAtTheIndex(int val, int index);
    void addAtTheEnd(int val);
    void addAtTheBeginning(int val);
    void removeFromBeginning();
    void removeFromEnd();
    int getNumberOfElements();

};


#endif //SDIZO_LIST_H
