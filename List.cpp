#include <windows.h>
#include "List.h"
#include <cstdlib>

List::List() {
    tail = NULL;
    head = NULL;
    numberOfElements = 0;
}

List::~List(){
    ElemList *elem;
    while (head != NULL)
    {
        elem = head -> next;
        delete head;
        head = elem;
    }
    numberOfElements = 0;
}

void List::display() {
    if(head == NULL) cout << "Lista jest pusta" << endl;
    else
    {
        ElemList *elem;
        elem = head;
        while (elem != NULL)
        {
            cout<< elem -> data << " ";
            elem = elem -> next;
        }
        cout << endl;
        delete elem;
    }
    cout << endl;
    showReverse();
}

ElemList * List::searchUtility(int searchedNumber) {
    ElemList * elem;
    elem = head;
    for (int i = 0; i < numberOfElements ; i++){
        if(elem -> data == searchedNumber){return elem;}
        elem = elem -> next;
    }
    return NULL;
}

void List::fillElementsTakenFromFile(string fileName)
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

void List::addAtTheEnd(int val) {
    if (head == NULL){
        ElemList *listHead = new ElemList;
        listHead -> next = NULL;
        listHead -> prev = NULL;
        listHead -> data = val;
        head = listHead;
        tail = head;
        numberOfElements++;
        return;
    }

    ElemList *p = new ElemList;
    p -> data = val;
    p -> prev = tail;
    p -> next = NULL;
    tail -> next = p;
    tail = p;
    numberOfElements++;
}

void List::addAtTheBeginning(int val) {
    ElemList *elemList = new ElemList;
    elemList -> next = head;
    elemList -> prev = NULL;
    if (head) {head -> prev = elemList;}
    head = elemList;
    if (!tail) {tail = head;}
    elemList -> data = val;
    numberOfElements++;
}

void List::removeFromBeginning() {
    if (head == NULL)
    {
        cout << "Lista nie posiada elementow do usuniecia"<< endl;
        return;
    }
    ElemList *elemList;
    elemList = head;
    head = head -> next;
    head -> prev = NULL;
    delete elemList;
    numberOfElements--;
}

void List::removeFromEnd() {
    if (tail == NULL)
    {
        cout << "Lista nie posiada elementow do usuniecia"<< endl;
        return;
    }
    ElemList *elemList;
    elemList = tail;
    tail = tail -> prev;
    tail -> next = NULL;
    delete elemList;
    numberOfElements--;
}

void List::remove(int keyToRemove) {
    ElemList * elemToRemove;
    ElemList *elemPrev, *elemNext;
    elemToRemove = searchUtility(keyToRemove);

    if(elemToRemove == NULL)
    {
        cout << "Taka wartosc nie znajduje sie w tablicy!" << endl;
        return;
    }
    elemPrev = elemToRemove -> prev;
    elemNext = elemToRemove -> next;
    if (elemPrev != NULL) elemPrev -> next = elemNext;
    else head = elemNext;
    if (elemNext != NULL) elemNext -> prev = elemPrev;
    else tail = tail -> prev;

    delete elemToRemove;
    numberOfElements--;
}

bool List::find(int searchedNumber) {
    if (searchUtility(searchedNumber) == NULL)
    {
        return false;
    }
    return true;
}

void List::randomFillList(int amountOfElements)
{
        for (int i = 1; i <= amountOfElements; i++)
            addAtTheBeginning((rand() % 2000) - 1000);
}

void List::showReverse() {
    ElemList *elem;
    elem = tail;
    while (elem != NULL)
    {
        cout << elem -> data << " ";
        elem = elem -> prev;
    }
    cout << endl;
    delete elem;
}

void List::addAtTheIndex(int val, int index) {
    if(index == 0)
    {
        addAtTheBeginning(val);
        return;
    }
    if (index == numberOfElements)
    {
        addAtTheEnd(val);
        return;
    }
    if (index > numberOfElements)
    {
        cout <<endl << "Index znajduje sie poza lista!" << endl;
        return;
    }

    ElemList *elemToAdd = new ElemList;
    elemToAdd -> data = val;
    ElemList *elemPrev;
    ElemList *elemNext;
    elemPrev = head;
    for (int i = 1; i < index; ++i) {
        elemPrev = elemPrev -> next;
    }
    elemNext = elemPrev -> next;
    elemPrev -> next = elemToAdd;
    elemNext -> prev = elemToAdd;
    elemToAdd -> prev = elemPrev;
    elemToAdd -> next = elemNext;
    numberOfElements++;
}

int List::getNumberOfElements() {
    return numberOfElements;
}

