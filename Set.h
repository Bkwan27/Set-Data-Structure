#ifndef SET
#define SET
#include <string>

using ItemType = std::string;

class Set
{
public: //declare public methods
    Set(); //zero constructor
    Set(const Set& src); //copy constructor
    ~Set(); //destructor
    Set& operator=(const Set& src); //assignment operator
    bool empty() const; //check is Set is empty
    int size() const; //return size of Set
    bool insert(const ItemType& value); //insert value into Set at correct position
    bool erase(const ItemType& value); //erase a node with value in Set
    bool contains(const ItemType& value) const; //check if Set contains a Node with the corresponding value
    bool get(int pos, ItemType& value) const; //gets the value at the corresponding pos
    void swap(Set& other); //swaps too Sets
    void dump() const; //prints out a Set

private: //private member variables
    struct Node
    {
        ItemType value;
        Node* next;
        Node* prev;
    };
    Node dummy;
    int m_numNodes;
};

void unite(const Set& s1, const Set& s2, Set& result); //unites too Sets into one
void butNot(const Set& s1, const Set& s2, Set& result); //creates new Sets that have elements only in s1 and not in s2
#endif

