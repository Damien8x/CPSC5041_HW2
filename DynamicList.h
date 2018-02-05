#include <iostream>
#include <string>

using namespace std;


class DynamicList
{
private:

int list_capacity; //max number of integers that the list can currently store

int size; // number of current items in list

int *list; // used for dynamicly allocating an array of integers

public:

DynamicList(int capactiy); // only constructor. sets intital capactiy 

void add_item(int item); // adds argument to end of list

void remove_item(); // removes the last item on the list

void expand_list(); // doubles capacity of list onece list size > 50%

void shrink_list(); // cuts capacity of list in half once list size is less than 25% of capacity

int get_size(); // returns size of list

void print_list(); // prints contents of list
};
