//
// Created by barto on 11.04.2022.
//

#include "TestMenu.h"
#include <iostream>
#include "List.h"
#include "Array.h"
#include "Heap.h"
#include "BinarySearchTree.h"
#include<conio.h>
#include<string>
#include <cstdlib>

using namespace std;

void TestMenu::displayMenuForArrayAndList(string info)
{
    cout << endl;
    cout << info << endl;
    cout << "1.Wczytaj z pliku populacje" << endl;
    cout << "2.Usun na dowolnej pozycji" << endl;
    cout << "3.Usun na poczatku" << endl;
    cout << "4.Usun na koncu" << endl;
    cout << "5.Dodaj na dowolnej pozycji" << endl;
    cout << "6.Dodaj na poczatku" << endl;
    cout << "7.Dodaj na koncu" << endl;
    cout << "8.Znajdz losowa liczbe" << endl;
    cout << "9.Utworz populacje" << endl;
    cout << "0.Powrot do menu" << endl;
    cout << "Podaj opcje:";
}

void TestMenu::menu_array_tests(){
    char opt;
    string fileName;
    int index, value;
    Array *array;
    array = new Array;

    do{
        displayMenuForArrayAndList("--- TABLICA ---");
        cin>>opt;
        cin.sync();
        switch (opt){
            case '1':
                array->~Array();
                array = new Array;
                cout << " Podaj nazwe zbioru:";
                cin >> fileName;
                array -> fillElementsTakenFromFile(root + fileName);
                break;

            case '2':
                timer->startCounter();
                for (int i = 0; i < 100; i++) {
                    index = (rand() % array->getNumberOfElements());
                    array -> remove(index);
                }
                timer->getCounter();
                array -> fillElementsTakenFromFile(root + fileName);
                    break;

            case '3':
                timer->startCounter();
                for (int i = 0; i < 100; i++) {
                    array->removeFromBeginning();
                }
                timer->getCounter();
                array -> fillElementsTakenFromFile(root + fileName);
                break;

            case '4':
                timer->startCounter();
                for (int i = 0; i < 100; i++) {
                    array->removeFromEnd();
                }
                timer->getCounter();
                array -> fillElementsTakenFromFile(root + fileName);
                break;

            case '5':
                timer->startCounter();
                for (int i = 0; i < 100; i++) {
                    value = ((rand() % 2000) - 1000);
                    index = (rand() % array->getNumberOfElements());
                    array->addAtTheIndex(index, value);
                }
                timer->getCounter();
                array -> fillElementsTakenFromFile(root + fileName);
                break;

            case '6':
                timer->startCounter();
                for (int i = 0; i < 100; i++) {
                    value = ((rand() % 2000) - 1000);
                    array->addAtTheBeginning(value);
                }
                timer->getCounter();
                array -> fillElementsTakenFromFile(root + fileName);
                break;

            case '7':
                timer->startCounter();
                for (int i = 0; i < 100; i++) {
                    value = ((rand() % 2000) - 1000);
                    array->addAtTheEnd(value);
                }
                timer->getCounter();
                array -> fillElementsTakenFromFile(root + fileName);
                break;

            case '8':
                timer->startCounter();
                for (int i = 0; i < 100; i++) {
                    value = ((rand() % 2000) - 1000);
                    array->find(value);
                }
                timer->getCounter();
                array -> fillElementsTakenFromFile(root + fileName);
                break;

            case '9':
                cout<< "Podaj wielkosc pliku"<<endl;
                cin >> value;
                array->fillRandomNumbers(value);
                array->fillFileWithElements(value,root + "8k.txt");
                break;

            case '0':
                array->~Array();
                break;
        }

    } while (opt != '0');
}
void TestMenu::menu_list_test() {
    char opt;
    string fileName;
    int index, value;
    List *list;
    list = new List;

    do{
        displayMenuForArrayAndList("--- Lista ---");
        cin>>opt;
        cin.sync();
        switch (opt){
            case '1':
                list->~List();
                list = new List;
                cout << " Podaj nazwe zbioru:";
                cin >> fileName;
                list -> fillElementsTakenFromFile(root + fileName);
                break;

            case '2':
                timer->startCounter();
                for (int i = 0; i < 100; i++) {
                    value = ((rand() % 2000) - 1000);
                    list->remove(value);
                }
                timer->getCounter();
                list -> fillElementsTakenFromFile(root + fileName);
                break;

            case '3':
                timer->startCounter();
                for (int i = 0; i < 100; i++) {
                    list->removeFromBeginning();
                }
                timer->getCounter();
                list -> fillElementsTakenFromFile(root + fileName);
                break;

            case '4':
                timer->startCounter();
                for (int i = 0; i < 100; i++) {
                    list->removeFromEnd();
                }
                timer->getCounter();
                list -> fillElementsTakenFromFile(root + fileName);
                break;

            case '5':
                timer->startCounter();
                for (int i = 0; i < 100; i++) {
                    index = (rand() % list->getNumberOfElements());
                    value = ((rand() % 2000) - 1000);
                    list->addAtTheIndex(value, index);
                }
                timer->getCounter();
                list -> fillElementsTakenFromFile(root + fileName);
                break;

            case '6':
                timer->startCounter();
                for (int i = 0; i < 100; i++) {
                    value = ((rand() % 2000) - 1000);
                    list->addAtTheBeginning(value);
                }
                timer->getCounter();
                list -> fillElementsTakenFromFile(root + fileName);
                break;

            case '7':
                timer->startCounter();
                for (int i = 0; i < 100; i++) {
                    list->addAtTheEnd(100);
                }
                timer->getCounter();
                list -> fillElementsTakenFromFile(root + fileName);
                break;

            case '8':
                timer->startCounter();
                for (int i = 0; i < 100; i++) {
                    value = ((rand() % 2000) - 1000);
                    list->find(value);
                }
                timer->getCounter();
                list -> fillElementsTakenFromFile(root + fileName);
                break;

            case '0':
                list->~List();
                break;
        }

    } while (opt != '0');
}

void TestMenu::displayMenuForHeap(string info) {
    cout << endl;
    cout << info << endl;
    cout << "1.Wczytaj populacje z pliku" << endl;
    cout << "2.Usun z randomowego miejsca" << endl;
    cout << "3.Dodaj do kopca" << endl;
    cout << "4.Znajdz randomowa wartosc" << endl;
    cout << "0.Powrot do menu" << endl;
    cout << "Podaj opcje:";
}

void TestMenu::menu_heap_test() {
    char opt;
    string fileName;
    int index, value;
    Heap *heap;
    heap = new Heap;

    do{
        displayMenuForHeap("--- KOPIEC ---");
        cin>>opt;
        cin.sync();
        switch (opt){
            case '1': //tutaj wczytytwanie  kopca z pliku
                heap -> ~Heap();
                heap = new Heap;
                cout << " Podaj nazwe zbioru:";
                cin >> fileName;
                heap -> fillElementsTakenFromFile(root + fileName);
                break;

            case '2': //tutaj usuwanie elemenu z kopca
                timer->startCounter();
                for (int i = 0; i < 100; i++) {
                    index = (rand() % heap->getsize());
                    heap->remove(index);
                }
                timer->getCounter();
                heap -> fillElementsTakenFromFile(root + fileName);
                break;

            case '3': //tutaj dodawanie elemetu do kopca
                timer->startCounter();
                for (int i = 0; i < 100; i++) {
                    value = ((rand() % 2000) - 1000);
                    heap->addNewElement(value);
                }
                timer->getCounter();
                heap -> fillElementsTakenFromFile(root + fileName);
                break;

            case '4': //tutaj znajdowanie elemetu w kopca
                timer->startCounter();
                for (int i = 0; i < 100; i++) {
                    value = ((rand() % 2000) - 1000);
                    heap->search(value);
                }
                timer->getCounter();
                heap -> fillElementsTakenFromFile(root + fileName);
                break;

            case '0':
                heap->~Heap();
                break;
        }

    } while (opt != '0');
}

void TestMenu::startedMenu()
{
    char option;
    do{
        cout << endl;
        cout << "==== MENU GLOWNE ===" << endl;
        cout << "1.Tablica" << endl;
        cout << "2.Lista" << endl;
        cout << "3.Kopiec" << endl;
        cout << "0.Wyjscie" << endl;
        cout << "Podaj opcje:";
        cin>>option;
        cin.sync();
        cout << endl;
        switch (option){
            case '1':
                menu_array_tests();
                break;

            case '2':
                menu_list_test();
                break;

            case '3':
                menu_heap_test();
                break;

        }

    } while (option != '0');
}







