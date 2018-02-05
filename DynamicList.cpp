#include "DynamicList.h"
#include <string>
#include <iostream>

using namespace std;

// class variables
int list_capacity;
int size;
int *list;

// only constructor. argument used to set capacity of dynamically allocated
// list, list. initial size of list is zero.
DynamicList::DynamicList(int capacity)
{
this->list_capacity = capacity;
this->size = 0;
this->list = new int[list_capacity];
}

// method adds passed integer to end of list. If list size after addition
// is over  50% of capactiy, expand_list() is called.
void DynamicList::add_item(int item)
{
this->list[size] = item;
this->size++;
	if(size > (list_capacity/2))
		expand_list();
}

// method removes last item from list. If list size after removal
// is less than 25% of capacity, shrink_list() is called
// if size is equal to 0 error  will be displayed
void DynamicList::remove_item()
{
	if(size == 0)
		cout << "error: list size is zero" << endl;
	else
	{
		this->size--;
		this->list[size] = 0;
	}
	if(size < (list_capacity/4))
		shrink_list();
}

// doubles size of list by creating temporary list with twice the capacity
// of current list. all elements of list are copied to the temp list,
// original list is deleted from dynamic memory and class pointer *list
// points to temp array. 
void DynamicList::expand_list()
{
list_capacity*=2;
int *temp;
temp = new int[list_capacity];
	for(int i=0; i< size; i++)
		temp[i] = list[i];
delete[] list;
list = temp;	
}

// cuts capacity of list in half by creating temporary list with half the capacity
// of current list. All elements  of  list are copied tothe temp list,
// original list is deleted from dynamic memory and class pointer *list
// points to temp array.
void DynamicList::shrink_list()
{
list_capacity = list_capacity/2;
int *temp;
temp = new int[list_capacity];
	for(int i=0; i<size; i++)
		temp[i] = list[i];
delete[] list;
list = temp;
}

// formats and prints max capacity of list, current size of list and all
// contents of list.
void DynamicList::print_list()
{
cout << "List max capacity = " << list_capacity << endl;
cout << "List current size = " << size << endl;
cout << "List contents ";
	if(size == 0)
		cout << "\n";
	else
	{
		for(int i=0; i<size; i++)
			if(i != (size -1))
				cout << this->list[i] << ", ";
			else
				cout << this->list[i] << endl;
	}
}

// class Destructor deletes dynamic memory created by this-> object
DynamicList::~DynamicList()
{
delete [] list;
}
