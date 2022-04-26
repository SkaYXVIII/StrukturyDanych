//
// Created by barto on 10.04.2022.
//

#ifndef SDIZO_BINARYSEARCHTREE_H
#define SDIZO_BINARYSEARCHTREE_H

#include <string>

using namespace std;

struct Node
{
    Node* parent;
    Node* leftSon;
    Node* rightSon;
    int key;
};

class BinarySearchTree {
private:
    Node sentinel;
    string cr, cl, cp;
    Node* findNode(int val, Node* node);
    Node* findMaxValue(Node* node);
    Node* findMinValue(Node* node);
    Node* findSuccessor(Node* node);
    Node* findPredecessor(Node* node);

public:
    Node *root;
    int numberOfElements;
    BinarySearchTree();
    ~BinarySearchTree();
    void deleteTree(Node *node);
    void buildRandomly(int enteredAmount);
    void buildFromFile(string filename);
    bool findKey(int enteredValue);
    void addNode(int enteredValue);
    void printTree(string sp, string sn, Node * p);
    void display();
    void remove(int value);

};


#endif //SDIZO_BINARYSEARCHTREE_H
