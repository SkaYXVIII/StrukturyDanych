#include <iostream>
#include "List.h"
#include "Array.h"
#include "Heap.h"
#include "BinarySearchTree.h"
#include "TestMenu.h"
#include<conio.h>
#include<string>

using namespace std;
string root = "C:/Users/barto/CLionProjects/SDIZO/testFiles/";

void displayMenu(string info)
{
    cout << endl;
    cout << info << endl;
    cout << "1.Wczytaj z pliku" << endl;
    cout << "2.Usun" << endl;
    cout << "3.Dodaj" << endl;
    cout << "4.Znajdz" << endl;
    cout << "5.Utworz losowo" << endl;
    cout << "6.Wyswietl" << endl;
    cout << "0.Powrot do menu" << endl;
    cout << "Podaj opcje:";
}

void menu_heap()
{
    char opt;
    string fileName;
    int index, value;
    Heap *heap;
    heap = new Heap;

    do{
        displayMenu("--- KOPIEC ---");
        cin>>opt;
        cin.sync();
        switch (opt){
            case '1': //tutaj wczytytwanie  kopca z pliku
                heap -> ~Heap();
                heap = new Heap;
                cout << " Podaj nazwe zbioru:";
                cin >> fileName;
                heap->fillElementsTakenFromFile(root + fileName);
                heap->display("","",0);
                break;

            case '2': //tutaj usuwanie elemenu z kopca
                cout << " podaj Index:";
                cin >> index;
                heap->remove(index);
                heap->display("","",0);
                break;

            case '3': //tutaj dodawanie elemetu do kopca
                cout << " podaj wartosc:";
                cin >> value;
                heap->addNewElement(value);
                heap->display("","",0);
                break;

            case '4': //tutaj znajdowanie elemetu w kopca
                cout << " podaj wartosc:";
                cin >> value;
                if (heap->search(value))
                    cout << "poadana wartosc jest w tablicy";
                else
                    cout << "podanej wartosci NIE ma w tablicy";
                break;

            case '5':  //tutaj generowanie  kopca
                heap -> ~Heap();
                heap = new Heap;
                cout << "Podaj ilosc elementów tablicy:";
                cin >> value;
                heap ->randomFillHeap(value);
                heap->display("","",0);
                break;

            case '6':  //tutaj wyświetlanie kopca
                heap->display("","",0);
                break;

            case '0':
                heap->~Heap();
                break;
        }

    } while (opt != '0');
}

void menu_list()
{
    char opt;
    string fileName;
    int index, value;
    List *list;
    list = new List;

    do{
        displayMenu("--- LISTA ---");
        cin>>opt;
        cin.sync();
        switch (opt){
            case '1': //tutaj wczytytwanie  listy z pliku
                list->~List();
                list = new List;
                cout << " Podaj nazwe zbioru:";
                cin >> fileName;
                list->fillElementsTakenFromFile(root + fileName);
                list->display();
                break;

            case '2': //tutaj usuwanie elemenu z listy
                cout << " podaj wartosc:";
                cin >> value;
                list->remove(value);
                list->display();
                break;

            case '3': //tutaj dodawanie elemetu do listy
                cout << " podaj index:";
                cin >> index;
                cout << " podaj wartosc:";
                cin >> value;
                list->addAtTheIndex(value, index);
                list->display();
                break;

            case '4': //tutaj znajdowanie elemetu w listy
                cout << " podaj wartosc:";
                cin >> value;
                if (list->find(value))
                    cout << "poadana wartosc jest w liscie";
                else
                    cout << "podanej wartosci NIE ma w liscie";
                break;

            case '5':  //tutaj generowanie  listy
                list->~List();
                list = new List;
                cout << "Podaj ilosc elementów tablicy:";
                cin >> value;
                list->randomFillList(value);
                list->display();
                break;

            case '6':  //tutaj wyświetlanie listy
                list->display();
                break;

            case '0':
                list->~List();
                break;
        }

    } while (opt != '0');
}
void menu_array()
{
    char opt;
    string fileName;
    int index, value;
    Array *array;
    array = new Array;

    do{
        displayMenu("--- TABLICA ---");
        cin>>opt;
        cin.sync();
        switch (opt){
            case '1': //tutaj wczytytwanie  tablicy z pliku
                array->~Array();
                array = new Array;
                cout << " Podaj nazwe zbioru:";
                cin >> fileName;
                array -> fillElementsTakenFromFile(root + fileName);
                array -> display();
                break;

            case '2': //tutaj usuwanie elemenu z tablicy
                cout << " podaj Index:";
                cin >> index;
                array -> remove(index);
                array->display();
                break;

            case '3': //tutaj dodawanie elemetu do tablicy
                cout << " podaj index:";
                cin >> index;
                cout << " podaj wartosc:";
                cin >> value;
                array ->addAtTheIndex(index, value);
                array->display();
                break;

            case '4': //tutaj znajdowanie elemetu w tablicy
                cout << " podaj wartosc:";
                cin >> value;
                array ->find(value);
                break;

            case '5':  //tutaj generowanie  tablicy
                array->~Array();
                array = new Array;
                cout << "Podaj ilosc elementów tablicy:";
                cin >> value;
                array->fillRandomNumbers(value);
                array->display();
                break;

            case '6':  //tutaj wyświetlanie tablicy
                array -> display();
                break;

            case '0':
                array->~Array();
                break;
        }

    } while (opt != '0');
}
void menu_tree()
{
    char opt;
    string fileName;
    int index, value;
    BinarySearchTree *bst;
    bst = new BinarySearchTree;

    do{
        displayMenu("--- Drzewo Binarne ---");
        cin>>opt;
        cin.sync();
        switch (opt){
            case '1': //tutaj wczytytwanie  kopca z pliku
                bst -> ~BinarySearchTree();
                bst = new BinarySearchTree;
                cout << " Podaj nazwe zbioru:";
                cin >> fileName;
                bst->buildFromFile(root + fileName);
                bst->display();
                break;

            case '2': //tutaj usuwanie elemenu z kopca
                cout << " podaj wartosc";
                cin >> value;
                bst->remove(value);
                bst->display();
                break;

            case '3': //tutaj dodawanie elemetu do kopca
                cout << " podaj wartosc:";
                cin >> value;
                bst->addNode(value);
                bst->display();
                break;

            case '4': //tutaj znajdowanie elemetu w kopca
                cout << " podaj wartosc: \n";
                cin >> value;
                if (bst->findKey(value))
                    cout << "podana wartosc jest w drzewie \n";
                else
                    cout << "podanej wartosci NIE ma w drzewie \n";
                break;

            case '5':  //tutaj generowanie  kopca
                bst -> ~BinarySearchTree();
                bst = new BinarySearchTree;
                cout << "Podaj ilosc elementów tablicy:";
                cin >> value;
                bst->buildRandomly(value);
                bst->display();
                break;

            case '6':  //tutaj wyświetlanie kopca
                bst->display();
                break;

            case '0':
                bst -> ~BinarySearchTree();
                break;
        }

    } while (opt != '0');
}

int main() {
    bool isTest = false;
    if (!isTest) {
        char option;
        do {
            cout << endl;
            cout << "==== MENU GLOWNE ===" << endl;
            cout << "1.Tablica" << endl;
            cout << "2.Lista" << endl;
            cout << "3.Kopiec" << endl;
            cout << "4.Drzewo binarne" << endl;
            cout << "0.Wyjscie" << endl;
            cout << "Podaj opcje:";
            cin >> option;
            cin.sync();
            cout << endl;
            switch (option) {
                case '1':
                    menu_array();
                    break;

                case '2':
                    menu_list();
                    break;

                case '3':
                    menu_heap();
                    break;

                case '4':
                    menu_tree();
                    break;
            }

        } while (option != '0');
    }
    if (isTest){
//        TestMenu *testMenu = new TestMenu;
//        testMenu->startedMenu();
    }
    return 0;
}