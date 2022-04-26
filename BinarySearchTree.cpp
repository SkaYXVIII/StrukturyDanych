//
// Created by barto on 10.04.2022.
//

#include "BinarySearchTree.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>


using namespace std;


BinarySearchTree::BinarySearchTree() {
    numberOfElements = 0;

    sentinel.parent = sentinel.leftSon = sentinel.rightSon = root = &sentinel;

    // character strings used in displaying tree
    cr = cl = cp = "  ";
//    cr = "┌─";
//    cl = "└─";
//    cp[0] = '|';
    cr = 218;
    cl = 192;
    cp[0] = 179;

}

BinarySearchTree::~BinarySearchTree() {
    numberOfElements = 0;
    deleteTree(root);
}

void BinarySearchTree::deleteTree(Node *node) {
    if (node != &sentinel)
    {
        deleteTree(node->leftSon);
        deleteTree(node->rightSon);
        delete node;
    }
}

void BinarySearchTree::buildRandomly(int enteredAmount) {
    for (int i = 0; i < enteredAmount; i++)
        addNode((rand() % 101) + 0);
}

void BinarySearchTree::buildFromFile(string fileName) {
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
                addNode(val);
            }
            else break;
    }
    plik.close();
}



void BinarySearchTree::printTree(string sp, string sn, Node * p) {
    std::string t;

    if (p != &sentinel)
    {
        t = sp;
        if (sn == cr) t[t.length() - 2] = ' ';
        printTree(t + cp, cr, p->rightSon);

        t = t.substr(0, sp.length() - 2);
        std::cout << t << sn <<  ":" << p->key << std::endl;

        t = sp;
        if (sn == cl) t[t.length() - 2] = ' ';
        printTree(t + cp, cl, p->leftSon);
    }
}

void BinarySearchTree::display() {
    printTree("", "", root);
}

Node *BinarySearchTree::findNode(int val, Node* node) {
    if (node == &sentinel || node->key == val) return node;
    if (val < node->key)
        return findNode(val,node->leftSon);
    return findNode(val,node->rightSon);
}

void BinarySearchTree::addNode(int enteredValue) {
    numberOfElements++;
    Node *currentParent = &sentinel;
    Node *currentNode = root;
    Node *addedNode = new Node;
    while(currentNode != &sentinel)
    {
        currentParent = currentNode;
        if (enteredValue < currentNode->key)
            currentNode = currentNode->leftSon;
        else
            currentNode = currentNode->rightSon;
    }
    addedNode->parent = currentParent;
    addedNode->key = enteredValue;
    addedNode->rightSon = &sentinel;
    addedNode->leftSon = &sentinel;
    if (currentParent == &sentinel)
        root = addedNode;
    else
    {
        if (enteredValue < currentParent->key)
            currentParent->leftSon = addedNode;
        else
            currentParent->rightSon = addedNode;
    }

}

bool BinarySearchTree::findKey(int enteredValue) {
    Node *foundNode = findNode(enteredValue,root);
    if (foundNode == &sentinel)
        return false;
    else
        return true;
}

Node *BinarySearchTree::findMaxValue(Node *node) {
    while(node -> rightSon != &sentinel)
        node =  node -> rightSon;
    return node;
}

Node *BinarySearchTree::findMinValue(Node *node) {
    while(node -> leftSon != &sentinel)
        node =  node -> leftSon;
    return node;
}

Node *BinarySearchTree::findSuccessor(Node *node) {
    if (node->rightSon != &sentinel)
        return findMinValue(node->rightSon);
    Node* parent = node->parent;
    while(parent != &sentinel && parent->leftSon != node)
    {
        node = parent;
        parent = parent->parent;
    }
    return parent;
}

Node *BinarySearchTree::findPredecessor(Node *node) {
    if (node->leftSon != &sentinel)
        return findMaxValue(node ->leftSon);
    Node* parent = node->parent;
    while (parent != &sentinel && parent->rightSon != node)
    {
        node = parent;
        parent = parent->parent;
    }
    return parent;
}

void BinarySearchTree::remove(int value) {
    if (numberOfElements == 0){
        cout<<"Drzewo jest puste! \n";
        return;
    }
    Node* nodeToRemove = findNode(value,root);
    Node* tmp = &sentinel;
    Node* tmpRoot = &sentinel;

    if (nodeToRemove->leftSon == &sentinel || nodeToRemove->rightSon == &sentinel)
        tmp = nodeToRemove;
    else
        tmp = findSuccessor(nodeToRemove);

    if (tmp->leftSon != &sentinel)
        tmpRoot = tmp->leftSon;
    else
        tmpRoot = tmp->rightSon;

    if (tmpRoot != &sentinel)
        tmpRoot->parent = tmp->parent;

    if (tmp->parent == &sentinel)
        root = tmpRoot;
    else
    {
        if (tmp == tmp->parent->leftSon)
            tmp->parent->leftSon = tmpRoot;
        else
            tmp->parent->rightSon = tmpRoot;
    }
    if (tmp != nodeToRemove)
    {
        nodeToRemove->key = tmp->key;
    }
    delete tmp;
    numberOfElements--;

}






