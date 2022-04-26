//
// Created by barto on 11.04.2022.
//

#ifndef SDIZO_TESTMENU_H
#define SDIZO_TESTMENU_H


#include<string>
#include "Timer.h"
using namespace std;

class TestMenu {
string root = "C:/Users/barto/CLionProjects/SDIZO/testFiles/";
Timer *timer = new Timer;
public:
    void displayMenuForArrayAndList(string info);
    void displayMenuForHeap(string info);
    void menu_array_tests();
    void menu_list_test();
    void menu_heap_test();
    void startedMenu();
};


#endif //SDIZO_TESTMENU_H
