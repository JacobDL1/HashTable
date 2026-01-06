#include "node.h"
#include "LinkedListHash.h"

#include <iostream>
using namespace std;

LinkedList::LinkedList()
{
    head = nullptr;
    tail = nullptr;
}

LinkedList::~LinkedList()
{
    node* x = head;
    while(x != nullptr)
    {
        node* y = x -> next;
        delete x;
        x = y;
    }
}

void LinkedList::insert(int user_num) //inserts user_num to the end of the linked list
{
    node* user_list = new node(user_num);

    if(head == nullptr) //if the linked list is empty, head and tail both point to user_list
    {
        tail = user_list;
        head = tail;
    }
    else //puts user_list before head, then sets head to point to user_list 
    {
        tail -> next = user_list;
        tail = user_list;
    }
}

bool LinkedList::search(int user_num)
{
    node* incrementNode = head;

    while(incrementNode != nullptr) //increments through the linked list and compares each node's num value to see if it's equal to user_num
    {
        if(incrementNode->num == user_num)
        {
            return true;
        }
        else
        {
            incrementNode = incrementNode->next;
        }
    }

    return false;
}

bool LinkedList::deleteElement(int user_num)
{
    if(head == nullptr) //makes sure an empty list ins't being checked
    {
        return false;
    }

    node* incrementNode = head; //nodes used for traversing linked list to check for and delete user_num
    node* deleted = head->next;

    if(incrementNode->num == user_num) //checks if the head is the number being searched for
    {
        head = head->next; //moves the head to the next node
        
        if(incrementNode == tail) //if incrementNode was the head and tail of the list, tail is updated to be nullptr
        {
            tail = nullptr;
        }

        delete incrementNode; //deletes head
        return true;
    }

    while(deleted != nullptr) //increments through the linked list and compares each node's num value to see if it's equal to user_num
    {
        if((deleted->num == user_num))
        {
            if(deleted == tail) //checks if the number to be deleted is the tail, and resets the tail to incrementNode if so
            {
                tail = incrementNode;
                incrementNode->next = nullptr;
                delete deleted;
                return true;
            }
            else //element being deleted is neither the head or tail
            {
                incrementNode->next = deleted->next;
                delete deleted;
                return true;
            }
        }
        else //if user_num isn't found in the linked list, each node moves forward
        {
            incrementNode = incrementNode->next;
            deleted = deleted->next;
        }
    }

    return false;
}

void LinkedList::print_list()
{
    node* x = head;
    node* y = tail;

    if(x == nullptr)
    {
        cout << "Empty";
    }

    while(x != nullptr) //increments through the linked list until a nullptr is reached
    {
        if(x == y) //if the node being printed is the last in the list, then no arrow is print after the node's number, and if not, an arrow is printed after the node's number
        {
            cout << x->num;
        }
        else
        {
            cout << x->num << " -> ";
        }
        
        x = x -> next;
    }
    cout << endl;
}