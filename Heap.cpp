//
// Created by barto on 07.04.2022.
//

#include "Heap.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>
using namespace std;

Heap::Heap()
{
    size = 0;
    heap = new int[size];
    numberOfLvl = 0;
}

Heap::~Heap()
{
    size = 0;
    delete[] heap;
}

void Heap::display(std::string sp, std::string sn, int valueOfElement) {
    std::string stringR, stringL, stringP; // �a�cuchy do znak�w ramek
    std::string s;
    stringR = stringL = stringP = "  ";
    /*
    LEGENDA

    196 -

    218 |

    192 |_

    179 |

    �r�d�o ->	http://eduinf.waw.pl/inf/alg/001_search/0113.php
    */
    stringR[0] = 218;
    stringR[1] = 196;
    stringL[0] = 192;
    stringL[1] = 196;
    stringP[0] = 179;

    if (valueOfElement < size) {
        s = sp;
        if (sn == stringR) { s[s.length() - 2] = ' '; }

        display(s + stringP, stringR, 2 * valueOfElement + 2);
        s = s.substr(0, sp.length() - 2);
        std::cout << s << sn << heap[valueOfElement] << std::endl;

        s = sp;
        if (sn == stringL) { s[s.length() - 2] = ' '; }

        display(s + stringP, stringL, 2 * valueOfElement + 1);
    }
}

void Heap::repair() {
    for (int i = 0; i < size; i++)
    {
        int element = heap[i];
        for (int c = 0; c < (numberOfLvl - 1); c++)
        {
            int j = ceil((i - 1) / 2);
            while (i > 0 && heap[j] < element)
            {
                heap[i] = heap[j];
                heap[j] = element;
                i = j;
                j = ceil((i - 1) / 2);
            }
            heap[i] = element;
        }
    }
}

void Heap::level()
{
    numberOfLvl = 0;

    int quantity = size;

    while (quantity > 0)
    {
        quantity = quantity - pow(2, numberOfLvl);
        numberOfLvl++;
    }
}

void Heap::resize(bool isBigger, int value) {
    isBigger ? size++ : size--;
    int *pointer = new int[size];
    for (int i = 0; i < size - 1; i++)
    {
     isBigger ? pointer[i] = heap[i] :
             pointer[i] = heap[i+1];
    }
    if (isBigger) pointer[size - 1] = value;
    else pointer[size -1] = heap[size];
    delete[] heap;
    heap = new int[size];
    for (int i = 0; i < size; i++) { heap[i] = pointer[i]; }
    delete[] pointer;
}

void Heap::addNewElement(int valueOfElement)
{
    resize(true, valueOfElement);
    level();
    repair();
}

void Heap::remove(int index)
{
    int val = heap[index];
    heap[index] = heap[0];
    heap[0] = val;
    resize(false,0);
    level();
    repair();
}

void Heap::fillElementsTakenFromFile(string fileName)
{
    ifstream file;
    string element;
    file.open(fileName);
    file >> element;
    size = atoi(element.c_str());
    heap = new int[size];

    for (int i = 0; i < size; i++)
    {
        file >> element;
        heap[i] = atoi(element.c_str());
    }

    file.close();
    level();
    repair();
}

bool Heap::search(int value) {
    if (heap[0] == value) { return true; }

    for (int i = 0; i < size; i++) //dla kazdego elementu
    {
        // lewy syn
        if ((2 * i + 1) < size) //jesli lewy syn istnieje
        {
            if (heap[2 * i + 1] == value) { return true; }

                // prawy syn
            else if ((2 * i + 2) < size)  //jesli prawy syn istnieje
            {
                if (heap[2 * i + 2] == value) { return true; }
            }

        }
    }
    return false;
}

void Heap::randomFillHeap(int amountOfElements)
{
    size = amountOfElements;
    heap = new int[size];
    level();

    for (int i = 0; i < size; i++)
    {
        int element = ((rand() % 2000) - 1000); // wype�nianie liczbami pseudolosowymi
        heap[i] = element;
    }
    repair();
}

void Heap::displayTab() {
    for (int i = 0; i < size; i++)
    {
        cout<< heap[i];
        cout << " ";
    }
    cout<<endl;
}

int Heap::getsize() {
    return size;
}

int Heap::getValueFromIndex(int index) {
    return heap[index];
}


