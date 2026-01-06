To compile the program, type g++ hash_main.cpp HashTable.cpp LinkedListHash.cpp node.cpp -o hash_main.exe, and to run it type ./hash_main.exe

The program will ask you enter "l" or "c" for linear probing or chaining, respectively, then ask you for the first element you want to add to the hash table

After this, you will have a menu, press 1 to add an element, 2 to search for an element, 3 to delete an element, 4 to print your hash table, and 5 to exit the program

For options 1, 2 and 3, all you need to do is enter an integer, and that integer, depending on what menu option you chose, will be inserted into your hash table, if possible, searched for, or deleted, if present.