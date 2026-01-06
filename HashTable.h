#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "LinkedListHash.h"

#include <iostream>
#include <vector>

using namespace std;

class HashLinear
{
    public:
        HashLinear();

        void insertLinear(int userVal); //inserts userVal using linear probing rules
        void searchLinear(int userVal); //searches for userVal
        void deleteHashLinear(int userVal); //deletes userVal if present
        void printLinear(); //prints the hash table

    private:
        int getHash(int key); //takes in the user's input and uses modular hashing to produce a key 0-9

        vector<int> table; //used for linear probing method of insertion
};

class HashChain
{
    public:
        HashChain();

        void insertChain(int userVal); //inserts userVal using chaining rules
        void searchChain(int userVal); //searches for userVal
        void deleteHashChain(int userVal); //deletes userVal if present
        void printChain(); //prints the hash table

    private:
        int getHash(int key); //takes in the user's input and uses modular hashing to produce a key 0-9

        vector<LinkedList> linked_table; //used for chain method of insertion
};

#endif