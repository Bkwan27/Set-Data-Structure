#include <iostream>
#include <string>
#include "Set.h"
#include <cassert>
using namespace std;

int main() {
	///*
	Set h;
	Set b = h; //check copy constructor if nothing is in Set
	b.dump();
	Set k;
	k.insert("l");
	k = b; //check assignment operator if the src set is empty
	k.dump();
	assert(h.empty() == true); //check empty method
	assert(h.erase("h") == false); //check that erase doesn't work if value is not in Set
	assert(h.insert("honey") == true); //check that insert works
	assert(h.empty() == false); //check empty method when Set isn't empty
	assert(h.insert("hello") == true);
	h.insert("a");
	h.insert("b");
	h.insert("imp");
	assert(h.insert("a") == false); //make sure you can't insert duplicates
	h.dump(); //see Set
	cerr << h.size() << endl; //check size is accurate
	ItemType test = "";
	//check that get gets the right word and returns true
	assert(h.get(2, test) == true && test == "hello");
	assert(h.get(0, test) == true && test == "a");
	assert(h.get(1, test) == true && test == "b");
	assert(h.get(5, test) == false); //check that get returns false if accessing outside Set size
	Set j = h; //checking copy constructor
	j.dump();
	cerr << j.size() << endl;
	j.insert("i love");
	j.insert("you look great");
	j = h; //checking assignment operator
	j.dump();
	cerr << j.size() << endl << endl;
	assert(j.erase("hello") == true); //check erase function
	assert(j.erase("hello") == false);
	assert(j.erase("a") == true); //check if can erase from beginning and end
	assert(j.erase("imp") == true);
	j.dump();
	h.dump();
	j.swap(h); //check swap function
	j.dump();
	h.dump();

	Set x;
	x.insert("abc");
	x.insert("ab");
	x.insert("a");
	Set y;
	y.insert("abc");
	y.insert("k");
	y.insert("h");
	y.insert("p");

	Set z;
	unite(x, y, z); //check unite
	z.dump();

	Set d;
	butNot(x, y, d); //check butNot
	d.dump();

	butNot(x, y, x); //check butNot if s1 is same Set variable as result
	x.dump();

	unite(x, y, x); //check unite if s1 is same Set variable as result
	x.dump();

	Set q;
	Set t;
	t.insert("abc");
	t.insert("ab");
	t.insert("a");
	assert(t.insert("") == true); //check with empty strings
	assert(t.insert("") == false);
	butNot(q, y, d);//check with empty Sets as one input
	d.dump();
	unite(t, q, z);
	z.dump();
	butNot(z, q, d);
	unite(q, t, z);
	d.dump();
	z.dump();
	//*/

	/*
	//check with unsigned long
	Set u;
	assert(u.insert(286) == true); //test insert
	assert(!(u.insert(286)));
	u.insert(800);
	u.insert(465);
	u.insert(0);
	u.insert(435);
	u.dump();
	Set w = u; //test copy constructor
	w.dump();
	w.insert(200);
	w.insert(89);
	w.swap(u); //test swap
	u.dump();
	w.dump();

	assert(!(u.erase(2))); //test erase
	assert(u.erase(286));
	ItemType test;
	assert(u.get(0, test) && test == 0); //test get
	assert(u.contains(800)); //test contains
	assert(!(u.contains(4)));
	*/
}
