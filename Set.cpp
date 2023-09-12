#include "Set.h"
#include <iostream>
using namespace std;

Set::Set() { //set private member variables to default values
	dummy.next = nullptr;
	dummy.prev = nullptr;
	m_numNodes = 0;
}

Set::~Set() {
	Node* p;
	p = dummy.next; //starts at top of linked list
	while (p != nullptr) //traverses every node in lnked list and deletes it
	{
		Node* n = p->next;
		delete p;
		p = n;
	}
}

Set::Set(const Set& src) {
	Node* p;
	dummy = src.dummy;//starts at dummy
	p = &dummy;
	m_numNodes = src.m_numNodes; //assigns m_numNodes to new Set
	if (p->next == nullptr) { //sets to default value if src is empty Set
		dummy.next = nullptr;
		dummy.prev = nullptr;
	}
	else //creates and assigns same values to same # of Nodes as src Set
	{
		p = p->next;
		Node* temp = &dummy;
		while (p != nullptr) //goes through each Node in Set and creates a corresponding Node
		{
			Node* h = new Node;
			temp->next = h;
			h->prev = temp;
			h->value = p->value;
			p = p->next;
			temp = h;
		}
		temp->next = nullptr;
	}
}

Set& Set::operator=(const Set& src) {
	Node* p; //deletes the Nodes of the original linked list
	p = dummy.next;
	while (p != nullptr)
	{
		Node* n = p->next;
		delete p;
		p = n;
	}

	//creates a new Set by copying number of nodes and values of each node from src Set
	dummy = src.dummy; 
	p = &dummy;
	m_numNodes = src.m_numNodes;
	if (p->next == nullptr) {
		dummy.next = nullptr;
		dummy.prev = nullptr;
		return *this;
	}
	p = p->next;
	Node* temp = &dummy;
	while (p != nullptr) //replicates each Node of src Set
	{
		Node* h = new Node;
		temp->next = h;
		h->prev = temp;
		h->value = p->value;
		p = p->next;
		temp = h;
	}
	temp->next = nullptr;
	return *this;
}

bool Set::empty() const { //checks if Set is empty
	return (dummy.next == nullptr);
}

int Set::size() const { 
	return m_numNodes;
}

bool Set::contains(const ItemType& value) const {
	Node* p = dummy.next;
	while (p != nullptr) { //traverses Set to see if value is in Set
		if (p->value == value)
			return true;
		p = p->next;
	}
	return false;
}

bool Set::insert(const ItemType& value) {
	if (contains(value)) //checks if value is in Set b/c there can't be duplicates
		return false;
	Node* p = &dummy;
	Node* insert = new Node;
	m_numNodes++;
	while (p->next != nullptr) {  //finds proper position to put value so Set is sorted
		if (p->next->value > value)
			break;
		p = p->next;
	}
	if (p->next == nullptr) { //if at rear of Linked List this adds a new Node to the rear
		p->next = insert;
		insert->prev = p;
		insert->next = nullptr;
		insert->value = value;
		return true;
	}
	else //adds a new Node to anywhere else in the Set
	{
		insert->prev = p;
		p->next->prev = insert;
		insert->next = p->next;
		p->next = insert;
		insert->value = value;
		return true;
	}
} 

bool Set::erase(const ItemType& value) {
	Node* p = dummy.next;
	while (p != nullptr) { //finds the value
		if (p->value == value)
			break;
		p = p->next;
	}
	if (p != nullptr && p->next != nullptr) { //erases Node if not at rear of the Set
		p->prev->next = p->next;
		p->next->prev = p->prev;
		delete p;
		m_numNodes--;
		return true;
	}
	else if (p != nullptr && p->next == nullptr) { //erases Node if at the end of the Set
		p->prev->next = nullptr;
		delete p;
		m_numNodes--;
		return true;
	}
	return false;
}

bool Set::get(int pos, ItemType& value) const {
	if (pos < 0 || pos >= m_numNodes) //checks if pos is valid
		return false;

	Node* p = dummy.next;
	while (pos != 0) { //gets to the right Node in the Set given pos
		p = p->next;
		pos--;
	}
	value = p->value; 
	return true;
}

void Set::swap(Set& other) { //swaps Set
	Set temp = other;
	other = *this;
	*this = temp;
}

void unite(const Set& s1, const Set& s2, Set& result) { 
	ItemType i;
	int j = 0;
	Set output;
	while (j < s1.size()) { //adds values to result linked list from s1
		s1.get(j, i);
		output.insert(i);
		j++;
	}
	j = 0;
	while (j < s2.size()) { //adds values to result linked list from s2
		s2.get(j, i);
		output.insert(i);
		j++;
	}
	result = output;
}

void butNot(const Set& s1, const Set& s2, Set& result) {
	ItemType i;
	int j = 0;
	Set output;
	while (j < s1.size()) { //adds values to result Set from s1
		s1.get(j, i);
		output.insert(i);
		j++;
	}
	j = 0;
	while (j < s2.size()) { //erases values in result Set that are in s2
		s2.get(j, i);
		output.erase(i);
		j++;
	}
	result = output;
}

void Set::dump() const{
	Node* p = dummy.next;
	cerr << endl;
	while (p != nullptr) { //prints out each Node in Set
		cerr << p->value << endl;
		p = p->next;
	}
	cerr << size() << endl << endl;
}


