#include "HashTable.h"
#include "node.h"
#include "LinkedListHash.h"

using namespace std;

void interface(HashChain& x, HashLinear& y, int z, char choice)
{
    if(z == 1) //calls insertLinear() or insertChain() base on char choice, with the user's input, int z, as a parameter
    {
        int add_num;
        cout << "What data element do you want to add? ";
        cin >> add_num;

        if((choice == 'l') || (choice == 'L'))
        {
            y.insertLinear(add_num); //adds int add_num to hash table using linear probing
        }

        if((choice == 'c') || (choice == 'C'))
        {
            x.insertChain(add_num); //adds int add_num to hash table using chaining
        }

        cout << endl;
    }

    if(z == 2) //calls search() with the user's input as a parameter
    {
        int searchFor;
        cout << "What data element are you searching for? ";
        cin >> searchFor;

        if((choice == 'l') || (choice == 'L'))
        {
            y.searchLinear(searchFor); //searches for int searchFor in the vector<int> of class HashLinear
        }

        if((choice == 'c') || (choice == 'C'))
        {
            x.searchChain(searchFor); //searches for int searchFor in the vector<LinkedList> of class HashChain
        }

        cout << endl;
    }
    
    if(z == 3) //calls deleteHash() with the user's input as a parameter
    {
        int delete_element;
        cout << "What data element do you want to delete? ";
        cin >> delete_element;

        if((choice == 'l') || (choice == 'L'))
        {
            y.deleteHashLinear(delete_element); //deleted int delete_element, if present, from the vector<int> of class HashLinear
        }

        if((choice == 'c') || (choice == 'C'))
        {
            x.deleteHashChain(delete_element); //deleted int delete_element, if present, from the vector<LinkedList> of class HashChain
        }

        cout << endl;
    }

    if(z == 4) //calls print() with the user's input as a parameter
    {
        if((choice == 'l') || (choice == 'L'))
        {
            y.printLinear(); //prints the contents of class HashlLinear's vector<int>
        }

        if((choice == 'c') || (choice == 'C'))
        {
            x.printChain(); //prints the contents of class HashlChain's vector<LinkedList>
        }

        cout << endl;
    }

    if((z >= 5) || (z <= 0)) //makes sure incorrect user input doesn't cause an error
    {
        cout << "Please enter either a 1, 2, 3, 4, or 5" << endl;

        cout << endl;
    }
}

int main()
{
    HashLinear linear_probe; //stores the data for a hash table using linear probing rules
    HashChain chain; //stores the data for a hash table using chaining rules

    int user_input;
    char user_choice;
    bool l_c = false;

    while(l_c == false)
    {
        cout << "Do you want to use linear probing or chaining? (type \"l\" for linear probing and \"c\" chaining) ";
        cin >> user_choice;

        if((user_choice == 'l') || (user_choice == 'c') || (user_choice == 'L') || (user_choice == 'C'))
        {
            l_c = true;
        }
        else
        {
            cout << "Input must be an \"l\" or \"c\": ";
        }
    }

    cout << "What element do you want to add to the hash table? "; //starts off with adding an element since the other functions have nothing to search/delete/print otherwise

    cin >> user_input;

    cout << endl;
    if((user_choice == 'l') || (user_choice == 'L'))
    {
        linear_probe.insertLinear(user_input);
    }

    if((user_choice == 'c') || (user_choice == 'C'))
    {
        chain.insertChain(user_input);
    }

    int guide; //used for interface() interaction

    cout << "What would you like to do now?" << endl << endl << "1. Add data element" << endl << endl << "2. Search for a data element" << endl << endl << "3. Delete a data element" << endl << endl <<"4. Print all elements in list" << endl << endl << "5. Exit program" << endl << endl;

    cin >> guide;

    while(guide != 5) //loops through interface() until user wants to exit the program
    {
        interface(chain, linear_probe, guide, user_choice);

        cout << "What would you like to do now?" << endl << endl << "1. Add data element" << endl << endl << "2. Search for a data element" << endl << endl << "3. Delete a data element" << endl << endl <<"4. Print all elements in list" << endl << endl << "5. Exit program" << endl << endl;
        cin >> guide;
    }
}