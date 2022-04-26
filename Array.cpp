//
// Created by barto on 05.04.2022.
//

#include "Array.h"
#include <string>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <cstdlib>

Array::Array()
{
    numberOfElements = 0;
    pointer = new int[numberOfElements];
}

Array::~Array()
{
    delete[] pointer;
    numberOfElements = 0;
}

void Array::display()
{
    cout << endl;
    if (numberOfElements == 0) cout << "Tablica jest pusta" << endl;
    else
    {
        for (int i = 0; i < numberOfElements; i++)
        {
            cout << pointer[i] << " ";
        }
        cout << endl;
    }
}

void Array::relocate()
{
    int *p = pointer;
    pointer = new int[numberOfElements + 1];
    for (int i = 0; i < numberOfElements; i++)
    {
        pointer[i] = p[i];
    }
    delete[] p;
}

void Array::addAtTheBeginning(int valueOfTheNewElement)
{
    numberOfElements++;
    relocate();
    for (int i = numberOfElements - 1; i > 0 ; i--)
    {
        pointer[i] = pointer[i - 1];
    }
    pointer[0] = valueOfTheNewElement;
}

void Array::addAtTheEnd(int valueOfTheNewElement)
{
    numberOfElements++;
    relocate();
    pointer[numberOfElements - 1] = valueOfTheNewElement;
}

void Array::addAtTheIndex(int indexOfNewElement, int valueOfTheNewElement) {
    if (indexOfNewElement > numberOfElements)
    {
        cout<< "Index nie zawiera sie w tablicy" << endl;
        return;
    }
    if (indexOfNewElement == 0)
    {
        addAtTheBeginning(valueOfTheNewElement);
        return;
    }
    if (indexOfNewElement == numberOfElements)
    {
        addAtTheEnd(valueOfTheNewElement);
        return;
    }
    numberOfElements++;
    relocate();
    for (int i = numberOfElements; i < indexOfNewElement; i--)
    {
         pointer[i] = pointer[i-1];
    }
    pointer[indexOfNewElement] = valueOfTheNewElement;
}

void Array::remove(int indexElementToRemove)
{
    if (indexElementToRemove >= numberOfElements)
    {
        cout << "Index nie zawiera sie w tablicy" << endl;
        return;
    }
    for (int i = indexElementToRemove; i < numberOfElements - 1; i++)
    {
        pointer[i] = pointer[i+1];
    }
    numberOfElements--;
    relocate();
}

void Array::removeFromBeginning()
{
    if (numberOfElements == 0)
    {
        cout << "Tablica jest pusta, nie mozna nic usunac" << endl;
        return;
    }
    numberOfElements--;
    for (int i = 0; i < numberOfElements; i++)
    {
        pointer[i] = pointer[i + 1];
    }
    relocate();
}

void Array::removeFromEnd()
{
    if (numberOfElements == 0)
    {
        cout << "Tablica jest pusta, nie mozna nic usunac" << endl;
        return;
    }
    pointer[numberOfElements] = NULL;
    numberOfElements--;
    relocate();
}

void Array::find(int searchedNumber)
{
    bool flag = false;
    for (int i = 0; i < numberOfElements; i++) {
        if (pointer[i] == searchedNumber) flag = true;
        if(flag) break;
    }
    flag ?
    cout << "Szukany element znajduje sie w tablicy!" << endl :
    cout << "Szukany element nie znajduje sie w tablicy!" << endl;
}

void Array::fillElementsTakenFromFile(string fileName)
{
    string s;
    ifstream plik(fileName);
    if (!plik)
    {
        cout << "Nie udalo sie otworzyc pliku" << endl;
        return;
    }
    getline(plik, s);
    int numberOfElementsFromFile = atoi(s.c_str());
    {

        while (!plik.eof())
            if (numberOfElements  < numberOfElementsFromFile)
            {
                getline(plik, s);
                int val = atoi(s.c_str());
                addAtTheEnd(val);
            }
            else break;
    }
    plik.close();
}

void Array::fillRandomNumbers(int NumberOfElements)
{
    for (int i = 1; i <= NumberOfElements; i++)
        addAtTheBeginning((rand() % 2000) - 1000);
}

int Array::getNumberOfElements() {
    return numberOfElements;
}

void Array::fillFileWithElements(int value, string fileName) {
    ofstream file;
    file.open(fileName);
    if (!file)
    {
        cout << "Nie udalo sie otworzyc pliku" << endl;
        return;
    }
    file << value << endl;
    for (int i = 0; i < numberOfElements; i++) {
        file << pointer[i] << endl;
    }
    file.close();
}




