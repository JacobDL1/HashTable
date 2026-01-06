#ifndef LINKEDLISTHASH_H
#define LINKEDLISTHASH_H

#include "node.h"

#include <iostream>
using namespace std;

class LinkedList
{
    public:
        LinkedList();

        ~LinkedList();

        void insert(int user_num); //inserts user_numb at the end of the linked list

        bool search(int user_num); //checks each node of the linked list for equality with user_num, returns true if present and false if not

        bool deleteElement(int user_num); //deletes element specified by user_num if present

        void print_list();

    private:
        node* head;
        node* tail;
};

#endif