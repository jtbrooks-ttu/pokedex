/*
    File: Program3.cpp
    Author: J.T. Brooks
    Date: 11/14/24
    Purpose: Driver file. Includes main and program flow.
*/
#include "Pokemon.h"
#include "BinaryTree.h"
#include <fstream>

int main()
{
    BinaryTree<Pokemon> pokedex;
    ifstream inFile;
    string name;
    string index;
    int numPokemon = 0;
    Pokemon temp;

    inFile.open("pokedex.txt");
    cout << endl;
    cout << string(20, '*') << "POKEDEX:" << string(20, '*');
    cout << endl
         << endl;

    //file extraction
    while (getline(inFile, index, '#'))
    {
        getline(inFile, name, '#');
        temp.setID(index);
        temp.setName(name);
        if (!pokedex.searchNode(temp)) //node is not in tree
        {
            cout << "Inserting Pokemon with index ";
            cout << temp.getID() << " into the Pokedex." << endl;
            pokedex.insertNode(temp);
            numPokemon++;
        }
        else //node already existed in tree
        {
            cout << "Oops!  The Pokemon with index ";
            cout << temp.getID() << " is already in the Pokedex." << endl;
        }
    }

    //prints loaded pokemon
    cout << "\n\n"
         << numPokemon << " Pokemon have been added to the Pokedex!" << endl;

    cout << "\n\n";
    cout << endl;
    cout << string(20, '*') << "POKEDEX:" << string(20, '*');
    cout << endl
         << endl;
    //prints in ascending order by ID
    pokedex.displayInOrder();

    inFile.close();

    return 0;
}