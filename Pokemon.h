/*
    File: Pokemon.h
    Author: J.T. Brooks
    Date: 11/14/24
    Purpose: Header file containing Pokemon class
*/
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
    //constructor
    Pokemon()
    {
        ID = "0";
        name = "None";
    }

    //setters
    void setID(string newID)
    {
        ID = newID;
    }

    void setName(string newName)
    {
        name = newName;
    }

    //getters
    string getID()
    {
        return ID;
    }

    string getName()
    {
        return name;
    }

    //overloaded comparison & output operators
    friend ostream &operator<<(ostream &os, Pokemon &poke)
    {
        os << "Pokemon Index Number: " << setw(10) << left << poke.ID;
        os << "Name: " << poke.name << endl;
        return os;
    }

    bool operator<(const Pokemon &poke)
    { // compares by Pokemon ID
        return (stoi(ID) < stoi(poke.ID)); //stoi() converts string to int
    }

    bool operator==(const Pokemon &poke)
    { // compares by Pokemon ID
        return (stoi(ID) == stoi(poke.ID)); //stoi() converts string to int
    }
};
#endif