#include "Pokemon.h"
#include "BinaryTree.h"
#include <fstream>

int main(){
    BinaryTree<Pokemon> pokedex;
    ifstream inFile;
    string name;
    string index;
    int numPokemon = 0;
    Pokemon temp;

    inFile.open("pokedex.txt");
    cout << endl;
    cout << string(20, '*') << "POKEDEX:" << string(20, '*');
    cout << endl << endl;

    while(getline(inFile, index, '#')){
        getline(inFile, name, '#');
        temp.setID(index);
        temp.setName(name);
        if(!pokedex.searchNode(pokedex.getRoot(), temp)){
            cout << "Inserting Pokemon with index ";
            cout << temp.getID() << " into the Pokedex." << endl;
            pokedex.insertNode(temp);
            numPokemon++;
        }
        else{
            cout << "Oops!  The Pokemon with index ";
            cout << temp.getID() << " is already in the Pokedex." << endl;
        }
    }

    cout << "\n\n" << numPokemon << " Pokemon have been added to the Pokedex!" << endl;

    cout << "\n\n";
    cout << endl;
    cout << string(20, '*') << "POKEDEX:" << string(20, '*');
    cout << endl << endl;

    pokedex.displayInOrder();

    inFile.close();

    return 0;
}