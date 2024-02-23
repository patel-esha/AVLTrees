#ifndef PROJECT1_AVL_NODE_AVL_H
#define PROJECT1_AVL_NODE_AVL_H
#include <iostream>
using namespace std;

struct Node {
    string _name;
    string _gatorID;
    Node* _left;
    Node* _right;

    Node(string name, string gatorID) : _name(name), _gatorID(gatorID), _left(nullptr), _right(nullptr) {}
};


class Tree {
private:
    // hidden functions to help public functions execute
    int getHeight(Node* &root);
    int getBalance(Node* &root);
    Node* rightRotate(Node* &two);
    Node* leftRotate(Node* &one);
    Node* insertNode(Node* &root, string &name, string &gatorID);
    Node* findInorderSuccessor(Node*& root);
    Node* removeHelper(Node* &root, const string &gatorID, bool &success);
    void searchIDHelper(Node* &root, const string &gatorID);
    void searchNameHelper(Node* &root, const string &name, int &counter);
    void printInorderHelper(Node* &root, int &comma);
    void printPreorderHelper(Node* &root, int &comma);
    void printPostorderHelper(Node* &root, int &comma);
    void removeInorderHelper(Node* &root, int &N, int &counter);
    void clear(Node* &root);

public:

    Tree();
    ~Tree();
    Node* _root;
    void insert(string name, string gatorID);
    void remove(const string &gatorID);
    void searchID(const string &gatorID);
    void searchName(const string &name);
    void printInorder();
    void printPreorder();
    void printPostorder();
    void printLevelCount();
    void removeInorder(int N);
};

#endif //PROJECT1_AVL_NODE_AVL_H

