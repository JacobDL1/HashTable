#include "HashTable.h"

using namespace std;

HashLinear::HashLinear() : table(10, -9995) //-9995 is used as the value representing empty, 10 is used for size since modular hashing is what is used
{
}

HashChain::HashChain() : linked_table(10) //10 is used for size since modular hashing is what is used
{
}

int HashLinear::getHash(int key) //used modular hashing to assign the key a 0-9 index
{
    if(key >= 0) //if the key is negative, its multiplied by -1 so that the index produced isn't negative
    {
        return key % table.size();
    }
    else
    {
        return(key * -1) % table.size();
    }
}

void HashLinear::insertLinear(int userVal) //inserts userVal into a vector<int> using linear probing rules
{
    int hashed = getHash(userVal); //holds modular hashing of userVal

    int collisions = 0;

    while(collisions < table.size()) //makes sure each spot in the vector isn't full
    {
        if(table[hashed] == -9995) //spot is empty
        {
            table[hashed] = userVal;
            cout << "Element " << userVal << " successfully inserted" << endl;
            return;
        }
        else
        {
            collisions += 1;
            hashed = (hashed + 1) % table.size(); //makes sure hashed doesn't go past 9 for indexing purposes
        }
    }

    if(collisions == table.size())
    {
        cout << "Insert rejected due to too many collisions" << endl;
    }
}

void HashLinear::searchLinear(int userVal)
{
    bool check = false; //used to track if userVal was found

    for(int i = 0; i < table.size(); i++) //loops through the hash table and compares each value to userVal, changing check to true if userVal is found
    {
        if(table[i] == userVal)
        {
            cout << "Element " << userVal << " exists" << endl;
            check = true;
            break;
        }
    }

    if(check == false)
    {
        cout << "Element " << userVal << " does not exist" << endl;
    }
}

void HashLinear::deleteHashLinear(int userVal) //deletes userVal from hash table if present
{
    bool check = false; //used to track if userVal was found

    for(int i = 0; i < table.size(); i++) //loops through hash table and compares each value to userVal, changing check to true and the spot userVal was found to -9995 (number chosen to represent an empty spot) if it was found
    {
        if(table[i] == userVal)
        {
            table[i] = -9995;
            cout << "Element " << userVal << " exists and was removed" << endl;
            check = true;
            return; //stops method so only first instance of number is deleted
        }
    }

    if(check == false)
    {
        cout << "Element " << userVal << " does not exist" << endl;
    }
}

void HashLinear::printLinear() //prints the hash table
{
    for(int i = 0; i < table.size(); i++) //loops throught he hash table and prints all its values
    {
        if(table[i] == -9995)
        {
            cout << "Index " << i << ": Empty" << endl;
        }
        else
        {
            cout << "Index " << i << ": " << table[i] << endl;
        }
    }
}

int HashChain::getHash(int key) //used modular hashing to assign the key a 0-9 index
{
    if(key >= 0) //if the key is negative, its multiplied by -1 so that the index produced isn't negative
    {
        return key % linked_table.size();
    }
    else
    {
        return(key * -1) % linked_table.size();
    }
}

void HashChain::insertChain(int userVal)
{
    int hashed = getHash(userVal); //holds modular hashing of userVal

    linked_table[hashed].insert(userVal); //calls class LinkedList's insert method at index [hashed] in linked_table
    cout << "Element " << userVal << " successfully inserted" << endl;
}

void HashChain::searchChain(int userVal)
{
    bool check = false; //used to track if userVal was found in the hash table

    for(int i = 0; i < linked_table.size(); i++) //runs through each index of the vector, calling LinkedList's search() at each index, and if that returns true, check is set to true so the following if statement doesn't print
    {
        if(linked_table[i].search(userVal) == true)
        {
            cout << "Element " << userVal << " exists" << endl;
            check = true;
        }
    }

    if(check == false)
    {
        cout << "Element " << userVal << " does not exist" << endl;
    }
}

void HashChain::deleteHashChain(int userVal) //deletes userVal if present in the hash table
{
    bool check = false; //used to track if a deletion occurs

    for(int i = 0; i < linked_table.size(); i++) //runs through each index of the vector, calling LinkedList's deleteElement() at each index, and if that returns true, check is set to true so the following if statement doesn't print
    {
        if(linked_table[i].deleteElement(userVal) == true)
        {
            cout << "Element " << userVal << " exists and was removed" << endl;
            check = true;
        }
    }

    if(check == false)
    {
        cout << "Element " << userVal << " does not exist" << endl;
    }
}

void HashChain::printChain() //prints the hash table
{
    for(int i = 0; i < linked_table.size(); i++) //runs through each index of the vector, calling LinkedLists's print_list() at each index
    {
        cout << "Index " << i << ": ";
        linked_table[i].print_list();
        cout << endl;
    }
}