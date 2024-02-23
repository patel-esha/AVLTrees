#include "Node_AVL.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    Tree AVL; // tree instance
    string line; // this string will hold the input lines
    int commands = 0;

    if (getline(cin, line)) // first line of input
    {
        stringstream stream(line);
        stream >> commands; // this many things to do
    }

    int completedCommands = 0; // keeps track of our progress
    while (completedCommands < commands)
    {
        if (!getline(cin, line)) // break for when there is no more input
        {
            break;
        }

        stringstream stream(line);
        string command;
        stream >> command;

        if (command == "insert")
        {
            string name, gatorID;
            getline(stream, name, '"'); // skipping to the name
            getline(stream, name, '"'); // find the name
            stream >> gatorID;
            AVL.insert(name, gatorID);
        }
        else if (command == "remove")
        {
            string gatorID;
            stream >> gatorID;
            AVL.remove(gatorID);
        }
        else if (command == "search")
        {
            string identifier;
            if (stream.peek() == ' ') // to see if there is a space or we receive the info we want
            {
                stream.ignore();
            }
            if (stream.peek() == '"')
            {
                getline(stream, identifier, '"');
                getline(stream, identifier, '"');
                AVL.searchName(identifier);
            } else
            {
                stream >> identifier;
                AVL.searchID(identifier);
            }
        }
        else if (command == "printInorder")
        {
            AVL.printInorder();
        }
        else if (command == "printPreorder")
        {
            AVL.printPreorder();
        }
        else if (command == "printPostorder")
        {
            AVL.printPostorder();
        }
        else if (command == "printLevelCount")
        {
            AVL.printLevelCount();
        }
        else if (command == "removeInorder")
        {
            int N;
            stream >> N;
            AVL.removeInorder(N);
        }
        else
        {
            cout << "unsuccessful" << endl; // invalid input of some kind
        }

        completedCommands =+ 1;
    }

    return 0;
}
