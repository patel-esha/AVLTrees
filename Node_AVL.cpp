#include <iostream>
#include <string>
#include <regex>
#include "Node_AVL.h"
#include <climits>
using namespace std;

/* CITATIONS: geeksforgeeks was utilized for the development of rotate right and rotate
left functions & Professor Kapoor's code from "Trees"/"Balanced Trees" along woth inspiration
 from psuedocode was utilized
*/

// PRIVATE MEMBER FUNCTIONS

int Tree::getHeight(Node* &root) // used instead of storing to ensure we don't have to keep track
{
    if (root == nullptr)
    {
        return 0;
    }

    int leftHeight = getHeight(root->_left); // recursive calls to get the height
    int rightHeight = getHeight(root->_right);

    return 1 + max(leftHeight, rightHeight); // height formula
}

int Tree::getBalance(Node* &root)
{
    int balance = 0;
    if (root == nullptr)
    {
        balance = 0;
    }
    else
    {
        balance = getHeight(root->_left) - getHeight(root->_right); // balance factor formula
    }
    return balance;
}

Node* Tree::rightRotate(Node* &two) // implemented from geeksforgeeks
{
    Node* one = two->_left; // initializations of node placement
    Node* three = one->_right;

    one->_right = two; // rotations
    two->_left = three;

    return one;
}

Node* Tree::leftRotate(Node* &one) // implemented from geeksforgeeks
{
    Node* two = one->_right; // initializations of node placement
    Node* three = two->_left;

    two->_left = one; // rotations
    one->_right = three;

    return two;

}

Node* Tree::insertNode(Node* &root, string &name, string &gatorID)
{
    if (root == nullptr) // if the tree is empty, we insert the first node
    {
        cout << "successful" << endl;
        return new Node(name, gatorID);
    }
    else if (gatorID < root->_gatorID) // left subtree holds the values less than the root
    {
        root->_left = insertNode(root->_left, name, gatorID);
    }
    else if (gatorID > root->_gatorID) // right subtree holds the values greater than the root
    {
        root->_right = insertNode(root->_right, name, gatorID);
    }
    else
    {
        cout << "unsuccessful" << endl;
        return root;
    }

    int balance = getBalance(root);

    // If tree is right heavy (negative = right heavy, positive = left heavy)
    if (balance < -1)
    {
        // If tree's right subtree is left heavy
        if (getBalance(root->_right) > 0)
        {
            // RIGHT LEFT
            root->_right = rightRotate(root->_right);
            return leftRotate(root);
        }
        else
        {
            // Else perform LEFT rotation
            return leftRotate(root);
        }
    }
        // Else if tree is left heavy
    else if (balance > 1)
    {
        // If tree's left subtree is right heavy
        if (getBalance(root->_left) < 0)
        {
            // LEFT RIGHT
            root->_left = leftRotate(root->_left);
            return rightRotate(root);
        }
        else
        {
            // Else perform RIGHT rotation
            return rightRotate(root);
        }
    }

    return root;


}

Node* Tree::findInorderSuccessor(Node*& root)
{
    Node* inorderSuccessor = root->_right; // inorder successors are right subtree's leftmost child
    while (inorderSuccessor->_left != nullptr)
    {
        inorderSuccessor = inorderSuccessor->_left;
    }
    return inorderSuccessor;
}

Node* Tree::removeHelper(Node* &root, const string &gatorID, bool &success) // utilized Professor Kapoor's pseudocode
{
    if (root == nullptr) // if the root is null
    {
        cout << "unsuccessful" << endl;
        return root;
    }

    if (gatorID < root->_gatorID) // if the item is < the data at the local root
    {
        root->_left = removeHelper(root->_left, gatorID, success); // return recursive result of deleting from left
    }
    else if (gatorID > root->_gatorID) // if the item is > the data at the local root
    {
        root->_right = removeHelper(root->_right, gatorID, success); // return recursive result of deleting from right
    }
    else // the item is in the local root
    {
        if ((root->_left == nullptr) || (root->_right == nullptr)) // if the local root has one child (|| = OR)
        {
            Node* temp = root->_left ? root->_left : root->_right; // ? to find which child "exists"
            if (temp == nullptr) // set the parent of the local root to reference that child
            {
                temp = root;
                root = nullptr;
            }
            else
            {
                *root = *temp;
            }
            delete temp;
            success = true;
        }
        else // find the inorder successor
        {
            Node* temp = findInorderSuccessor(root);
            root->_gatorID = temp->_gatorID;
            root->_name = temp->_name;
            root->_right = removeHelper(root->_right, temp->_gatorID, success);
        }
    }
    if (root == nullptr) {
        return root;
    }

    int balance = getBalance(root);

    // If tree is right heavy (negative = right heavy, positive = left heavy)
    if (balance < -1)
    {
        // If tree's right subtree is left heavy
        if (getBalance(root->_right) > 0)
        {
            // RIGHT LEFT
            root->_right = rightRotate(root->_right);
            return leftRotate(root);
        }
        else
        {
            // Else perform LEFT rotation
            return leftRotate(root);
        }
    }
        // Else if tree is left heavy
    else if (balance > 1)
    {
        // If tree's left subtree is right heavy
        if (getBalance(root->_left) < 0)
        {
            // LEFT RIGHT
            root->_left = leftRotate(root->_left);
            return rightRotate(root);
        }
        else
        {
            // Else perform RIGHT rotation
            return rightRotate(root);
        }
    }

    return root;
}

void Tree::searchIDHelper(Node* &root, const string &gatorID)
{
    if (root == nullptr)
    {
        cout << "unsuccessful";
        return;
    }
    if (root->_gatorID == gatorID) // the root gatorID is the target gatorID
    {
        cout << root->_name;
    }
    else if (gatorID > root->_gatorID) // if the target gatorID > root gator ID, perform binary search accordingly
    {
        return searchIDHelper(root->_right, gatorID);
    }
    else if (gatorID < root->_gatorID)
    {
        return searchIDHelper(root->_left, gatorID);
    }

}

void Tree::searchNameHelper(Node* &root, const string &name, int &counter)
{
    if (root == nullptr)
    {
        return;
    }
    if (root->_name == name)
    {
        counter = 1;
        cout << root->_gatorID << endl;
    }
    searchNameHelper(root->_left, name, counter);
    searchNameHelper(root->_right, name, counter);

}

void Tree::printInorderHelper(Node* &root, int &comma) // ascending order
{
    if (root != nullptr)
    {
        printInorderHelper(root->_left, comma);

        if (comma == 0)
        {
            cout << ", ";
        }
        else
        {
            comma = 0;
        }
        cout << root->_name;
        printInorderHelper(root->_right, comma);
    }

}

void Tree::printPreorderHelper(Node* &root, int &comma) // root visited first
{
    if (root != nullptr)
    {
        if (comma == 0)
        {
            cout << ", ";
        }
        else
        {
            comma = 0;
        }
        cout << root->_name;
        printPreorderHelper(root->_left, comma);
        printPreorderHelper(root->_right, comma);
    }

}

void Tree::printPostorderHelper(Node* &root, int &comma) // root visited last
{
    if (root != nullptr)
    {
        printPostorderHelper(root->_left, comma);
        printPostorderHelper(root->_right, comma);
        if (comma == 0)
        {
            cout << ", ";
        }
        else
        {
            comma = 0;
        }
        cout << root->_name;
    }
}

void Tree::removeInorderHelper(Node* &root, int &N, int &counter)
{
    if (root == nullptr) // base case
    {
        return;
    }

    if (counter <= N) // binary search
    {
        removeInorderHelper(root->_left, N, counter);
    }

    if (counter == N) // target node has been found
    {
        bool success = false;
        removeHelper(root, root->_gatorID, success);
        if (success) {
            cout << "successful" << endl;
        }
        N = INT_MAX; // N is updated to the max int value to stop further executions
        return;
    }
    counter++;

    if (counter <= N) // binary search
    {
        removeInorderHelper(root->_right, N, counter);
    }
}

void Tree::clear(Node* &root)
{
    if (root != nullptr) // assistant for the destructor
    {
        clear(root->_left);
        clear(root->_right);
        delete root;
        root = nullptr;
    }
}

// PUBLIC MEMBER FUNCTIONS

Tree::Tree()
{
    _root = nullptr;
}

Tree::~Tree()
{
    clear(_root);
}

void Tree::insert(string name, string gatorID)
{
    regex name_("^[a-zA-Z ]+$"); // name validation
    regex id_("^[0-9]{8}$"); // ID validation

    if (regex_match(name, name_))
    {
        if (regex_match(gatorID, id_))
        {
            _root = insertNode(_root, name, gatorID); // node is inserted if the name and id are valid
        }
    }
    else
    {
        cout << "unsuccessful" << endl;
    }
}

void Tree::remove(const string& gatorID)
{
    bool success = false; // newly implemented to compensate for "successful" overprinting issues
    _root = removeHelper(_root, gatorID, success);
    if (success)
    {
        cout << "successful" << endl;
    }
}

void Tree::searchID(const string &gatorID)
{
    searchIDHelper(_root, gatorID);
    cout << endl;
}

void Tree::searchName(const string &name)
{
    int counter = 0; // implemented to keep track of "successful" statements
    searchNameHelper(_root, name, counter);
    if (counter == 0)
    {
        cout << "unsuccessful" << endl;
    }
}

void Tree::printInorder()
{
    int comma = 1; // aids in the "," not showing up for the first and last nodes
    printInorderHelper(_root, comma);
    cout << endl;
}

void Tree::printPreorder()
{
    int comma = 1;
    printPreorderHelper(_root, comma);
    cout << endl;
}

void Tree::printPostorder()
{
    int comma = 1;
    printPostorderHelper(_root, comma);
    cout << endl;
}

void Tree::printLevelCount()
{
    int levelCount = getHeight(_root);
    cout << levelCount << endl;
}

void Tree::removeInorder(int N)
{
    int counter = 0;
    removeInorderHelper(_root, N, counter);
}
