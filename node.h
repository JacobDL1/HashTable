#ifndef NODE
#define NODE

using namespace std;

class node
{
    public:
        int num; //stores value for the node
        node* next; //pointer for next node's memory address

        node(int x);
};

#endif