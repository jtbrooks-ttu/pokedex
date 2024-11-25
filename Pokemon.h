#ifndef POKEMON_H
#define POKEMON_H
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;
class Pokemon
{
private:
    string ID;
    string name;

public:
    Pokemon()
    {
        ID = "0";
        name = "None";
    }

    void setID(string newID)
    {
        ID = newID;
    }

    void setName(string newName)
    {
        name = newName;
    }

    string getID()
    {
        return ID;
    }

    string getName()
    {
        return name;
    }

    friend ostream &operator<<(ostream &os, Pokemon& poke)
    {
        os << "Pokemon Index Number: " << setw(10) << left << poke.ID;
        os << "Name: " << poke.name << endl;
        return os;
    }

    bool operator<(const Pokemon &poke)
    { // compares by Pokemon ID
        return (stoi(ID) < stoi(poke.ID));
    }

    bool operator==(const Pokemon &poke)
    { // compares by Pokemon ID
        return (stoi(ID) == stoi(poke.ID));
    }
};
#endif